#!/usr/bin/env python3

#
# This file is part of LiteX-M2SDR.
#
# Copyright (c) 2024 Enjoy-Digital <enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

import os
import time
import argparse

from migen import *

from litex.gen import *

from pcie_radio_platform import Platform

from litex.soc.interconnect.csr import *
from litex.soc.interconnect     import stream

from litex.soc.integration.soc_core import *
from litex.soc.integration.builder  import *

from litex.soc.cores.clock     import *
from litex.soc.cores.led       import LedChaser
from litex.soc.cores.icap      import ICAP
from litex.soc.cores.xadc      import XADC
from litex.soc.cores.dna       import DNA
from litex.soc.cores.pwm       import PWM
from litex.soc.cores.bitbang   import I2CMaster
from litex.soc.cores.gpio      import GPIOOut
from litex.soc.cores.spi_flash import S7SPIFlash

from litex.build.generic_platform import IOStandard, Subsignal, Pins

from litepcie.phy.s7pciephy import S7PCIEPHY

from liteeth.phy.a7_gtp       import QPLLSettings, QPLL
from liteeth.phy.a7_1000basex import A7_1000BASEX

from litescope import LiteScopeAnalyzer

from gateware.ad9361.core import AD9361RFIC
from gateware.cdcm6208    import CDCM6208
from gateware.timestamp   import Timestamp
from gateware.header      import TXRXHeader
from gateware.measurement import MultiClkMeasurement

from software import generate_litepcie_software
from software import get_pcie_device_id, remove_pcie_device, rescan_pcie_bus

# CRG ----------------------------------------------------------------------------------------------

class CRG(LiteXModule):
    def __init__(self, platform, sys_clk_freq):
        self.cd_sys    = ClockDomain()
        self.cd_idelay = ClockDomain()

        # # #

        # Clk / Rst.
        clk38p4 = platform.request("clk38p4")

        # PLL.
        self.pll = pll = S7PLL(speedgrade=-2)
        pll.register_clkin(clk38p4, 38.4e6)
        pll.create_clkout(self.cd_sys, sys_clk_freq)
        pll.create_clkout(self.cd_idelay, 200e6)

        # IDelayCtrl.
        self.idelayctrl = S7IDELAYCTRL(self.cd_idelay)

# BaseSoC -----------------------------------------------------------------------------------------

class BaseSoC(SoCMini):
    SoCCore.csr_map = {
        # SoC.
        "ctrl"        : 0,
        "uart"        : 1,
        "icap"        : 2,
        "flash"       : 3,
        "xadc"        : 4,
        "dna"         : 5,
        "flash"       : 6,
        "leds"        : 7,

        # PCIe.
        "pcie_phy"    : 10,
        "pcie_msi"    : 11,
        "pcie_dma0"   : 12,

        # Eth.
        "eth_phy"     : 14,

        # SATA.
        "sata_phy"    : 15,
        "sata_core"   : 16,

        # SDR.
        "si5351_i2c"  : 20,
        "si5351_pwm"  : 21,
        "timestamp"   : 22,
        "header"      : 23,
        "ad9361"      : 24,

        # Measurements/Analyzer.
        "clk_measurement" : 30,
        "analyzer"        : 31,
    }

    def __init__(self, sys_clk_freq=int(125e6),
        with_pcie     = True,  pcie_lanes=1,
        with_jtagbone = True
    ):
        # Platform ---------------------------------------------------------------------------------
        platform = Platform(build_multiboot=True)

        # SoCMini ----------------------------------------------------------------------------------

        SoCMini.__init__(self, platform, sys_clk_freq,
            ident         = f"LiteX SoC on PCIe-Radio",
            ident_version = True,
        )

        # Clocking ---------------------------------------------------------------------------------

        self.crg = CRG(platform, sys_clk_freq)
        platform.add_platform_command("set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets {{*crg_clkin}}]")

        # SI5351 Clock Generator -------------------------------------------------------------------
        class SI5351FakePads:
            def __init__(self):
                self.scl = Signal()
                self.sda = Signal()
                self.pwm = Signal()
        si5351_fake_pads = SI5351FakePads()

        self.si5351_i2c = I2CMaster(pads=si5351_fake_pads)
        self.si5351_pwm = PWM(si5351_fake_pads.pwm,
            default_enable = 1,
            default_width  = 1024,
            default_period = 2048,
        )

        # CDCM6208 Clock Generator -----------------------------------------------------------------

        self.cdcm6208 = CDCM6208(pads=platform.request("cdcm6208"), sys_clk_freq=sys_clk_freq)

        # JTAGBone ---------------------------------------------------------------------------------

        if with_jtagbone:
            self.add_jtagbone()
            platform.add_period_constraint(self.jtagbone_phy.cd_jtag.clk, 1e9/20e6)
            platform.add_false_path_constraints(self.jtagbone_phy.cd_jtag.clk, self.crg.cd_sys.clk)

        # Leds -------------------------------------------------------------------------------------

        self.leds = LedChaser(
            pads         = platform.request_all("user_led"),
            sys_clk_freq = sys_clk_freq
        )

        # ICAP -------------------------------------------------------------------------------------

        self.icap = ICAP()
        self.icap.add_reload()
        self.icap.add_timing_constraints(platform, sys_clk_freq, self.crg.cd_sys.clk)

        # XADC -------------------------------------------------------------------------------------

        self.xadc = XADC()

        # DNA --------------------------------------------------------------------------------------

        self.dna = DNA()
        self.dna.add_timing_constraints(platform, sys_clk_freq, self.crg.cd_sys.clk)

        # SPI Flash --------------------------------------------------------------------------------
        self.flash_cs_n = GPIOOut(platform.request("flash_cs_n"))
        self.flash      = S7SPIFlash(platform.request("flash"), sys_clk_freq, 25e6)

        # PCIe -------------------------------------------------------------------------------------

        if with_pcie:
            self.pcie_phy = S7PCIEPHY(platform, platform.request(f"pcie_x{pcie_lanes}"),
                data_width  = {1: 64, 4: 128}[pcie_lanes],
                bar0_size   = 0x20000,
                cd          = "sys",
            )
            if pcie_lanes == 1:
                platform.toolchain.pre_placement_commands.append("reset_property LOC [get_cells -hierarchical -filter {{NAME=~pcie_s7/*gtp_channel.gtpe2_channel_i}}]")
                platform.toolchain.pre_placement_commands.append("set_property LOC GTPE2_CHANNEL_X0Y2 [get_cells -hierarchical -filter {{NAME=~pcie_s7/*gtp_channel.gtpe2_channel_i}}]")
            self.pcie_phy.update_config({
                "Base_Class_Menu"          : "Wireless_controller",
                "Sub_Class_Interface_Menu" : "RF_controller",
                "Class_Code_Base"          : "0D",
                "Class_Code_Sub"           : "10",
                }
            )
            self.add_pcie(phy=self.pcie_phy, address_width=32, ndmas=1, data_width=64,
                with_dma_buffering    = True, dma_buffering_depth=8192,
                with_dma_loopback     = True,
                with_dma_synchronizer = True,
                with_msi              = True
            )
            self.comb += self.pcie_dma0.synchronizer.pps.eq(1)

            # Timing Constraints/False Paths -------------------------------------------------------
            for i in range(4):
                platform.toolchain.pre_placement_commands.append(f"set_clock_groups -group [get_clocks {{{{*s7pciephy_clkout{i}}}}}] -group [get_clocks        dna_clk] -asynchronous")
                platform.toolchain.pre_placement_commands.append(f"set_clock_groups -group [get_clocks {{{{*s7pciephy_clkout{i}}}}}] -group [get_clocks       jtag_clk] -asynchronous")
                platform.toolchain.pre_placement_commands.append(f"set_clock_groups -group [get_clocks {{{{*s7pciephy_clkout{i}}}}}] -group [get_clocks       icap_clk] -asynchronous")


        # Timestamp --------------------------------------------------------------------------------

        self.timestamp = Timestamp(clk_domain="rfic")

        # TX/RX Header Extracter/Inserter ----------------------------------------------------------

        self.header = TXRXHeader(data_width=64)
        self.comb += [
            self.header.rx.header.eq(0x5aa5_5aa5_5aa5_5aa5), # Unused for now, arbitrary.
            self.header.rx.timestamp.eq(self.timestamp.time),
        ]
        if with_pcie:
            # PCIe TX -> Header TX.
            self.comb += [
                self.header.tx.reset.eq(~self.pcie_dma0.reader.enable),
                self.pcie_dma0.source.connect(self.header.tx.sink),
            ]

            # Header RX -> PCIe RX.
            self.comb += [
                self.header.rx.reset.eq(~self.pcie_dma0.writer.enable),
                self.header.rx.source.connect(self.pcie_dma0.sink),
            ]

        # AD9361 RFIC ------------------------------------------------------------------------------

        self.ad9361 = AD9361RFIC(
            rfic_pads    = platform.request("ad9361_rfic"),
            spi_pads     = platform.request("ad9361_spi"),
            sys_clk_freq = sys_clk_freq,
        )
        self.ad9361.add_prbs()
        if with_pcie:
            self.comb += [
                # Header TX -> AD9361 TX.
                self.header.tx.source.connect(self.ad9361.sink),
                # AD9361 RX -> Header RX.
                self.ad9361.source.connect(self.header.rx.sink),
        ]
        #self.platform.add_period_constraint(self.ad9361.cd_rfic.clk, 1e9/245.76e6)
        self.platform.add_period_constraint(self.ad9361.cd_rfic.clk, 1e9/491.52e6)
        self.platform.add_false_path_constraints(self.crg.cd_sys.clk, self.ad9361.cd_rfic.clk)

        # Debug.
        with_spi_analyzer  = False
        with_rfic_analyzer = False
        with_dma_analyzer  = False
        if with_spi_analyzer:
            analyzer_signals = [platform.lookup_request("ad9361_spi")]
            self.analyzer = LiteScopeAnalyzer(analyzer_signals,
                depth        = 4096,
                clock_domain = "sys",
                register     = True,
                csr_csv      = "analyzer.csv"
            )
        if with_rfic_analyzer:
            analyzer_signals = [
                self.ad9361.phy.sink,   # TX.
                self.ad9361.phy.source, # RX.
                self.ad9361.prbs_rx.fields.synced,
            ]
            self.analyzer = LiteScopeAnalyzer(analyzer_signals,
                depth        = 4096,
                clock_domain = "rfic",
                register     = True,
                csr_csv      = "analyzer.csv"
            )
        if with_dma_analyzer:
            assert with_pcie
            analyzer_signals = [
                self.pcie_dma0.sink,   # RX.
                self.pcie_dma0.source, # TX.
                self.pcie_dma0.synchronizer.synced,
            ]
            self.analyzer = LiteScopeAnalyzer(analyzer_signals,
                depth        = 1024,
                clock_domain = "sys",
                register     = True,
                csr_csv      = "analyzer.csv"
            )

        # Clk Measurements -------------------------------------------------------------------------

        self.clk_measurement = MultiClkMeasurement(clks={
            "clk0" : 0,
            "clk1" : ClockSignal("rfic"),
            "clk2" : 0,
            "clk3" : 0,
        })

# Build --------------------------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(description="LiteX SoC on PCIe-Radio.")
    parser.add_argument("--build",  action="store_true", help="Build bitstream.")
    parser.add_argument("--load",   action="store_true", help="Load bitstream.")
    parser.add_argument("--flash",  action="store_true", help="Flash bitstream.")
    parser.add_argument("--rescan", action="store_true", help="Execute PCIe Rescan while Loading/Flashing.")
    parser.add_argument("--driver", action="store_true", help="Generate PCIe driver from LitePCIe (override local version).")
    comopts = parser.add_mutually_exclusive_group()
    comopts.add_argument("--with-pcie",      action="store_true", help="Enable PCIe Communication.")
    args = parser.parse_args()

    # Build SoC.
    soc = BaseSoC(
        with_pcie     = args.with_pcie,
    )
    builder = Builder(soc, csr_csv="csr.csv")
    builder.build(run=args.build)

    # Generate LitePCIe Driver.
    generate_litepcie_software(soc, "software", use_litepcie_software=args.driver)

    # Remove PCIe Driver/Device.
    if (args.load or args.flash) and args.rescan:
        device_id = get_pcie_device_id(vendor="10ee", device="7021") # FIXME: Handle X4  case.
        if device_id:
            remove_pcie_device(device_id, driver="litepcie")

    # Load Bistream.
    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(os.path.join(builder.gateware_dir, soc.build_name + ".bit"))

    # Flash Bitstream.
    if args.flash:
        prog = soc.platform.create_programmer()
        prog.flash(0, os.path.join(builder.gateware_dir, soc.build_name + ".bin"))

    # Rescan PCIe Bus.
    if args.rescan:
        time.sleep(2)
        rescan_pcie_bus()

if __name__ == "__main__":
    main()
