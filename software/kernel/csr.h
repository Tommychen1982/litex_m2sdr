//--------------------------------------------------------------------------------
// Auto-generated by LiteX (14dbdeb0) on 2024-05-21 11:40:35
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// CSR Includes.
//--------------------------------------------------------------------------------

#ifndef __GENERATED_CSR_H
#define __GENERATED_CSR_H

#ifndef CSR_BASE
#define CSR_BASE 0x0L
#endif /* ! CSR_BASE */

//--------------------------------------------------------------------------------
// CSR Registers/Fields Definition.
//--------------------------------------------------------------------------------

/* AD9361 Registers */
#define CSR_AD9361_BASE (CSR_BASE + 0x0L)
#define CSR_AD9361_CONFIG_ADDR (CSR_BASE + 0x0L)
#define CSR_AD9361_CONFIG_SIZE 1
#define CSR_AD9361_CTRL_ADDR (CSR_BASE + 0x4L)
#define CSR_AD9361_CTRL_SIZE 1
#define CSR_AD9361_STAT_ADDR (CSR_BASE + 0x8L)
#define CSR_AD9361_STAT_SIZE 1
#define CSR_AD9361_PHY_CONTROL_ADDR (CSR_BASE + 0xcL)
#define CSR_AD9361_PHY_CONTROL_SIZE 1
#define CSR_AD9361_SPI_CTRL_ADDR (CSR_BASE + 0x10L)
#define CSR_AD9361_SPI_CTRL_SIZE 1
#define CSR_AD9361_SPI_STATUS_ADDR (CSR_BASE + 0x14L)
#define CSR_AD9361_SPI_STATUS_SIZE 1
#define CSR_AD9361_SPI_MOSI_ADDR (CSR_BASE + 0x18L)
#define CSR_AD9361_SPI_MOSI_SIZE 1
#define CSR_AD9361_SPI_MISO_ADDR (CSR_BASE + 0x1cL)
#define CSR_AD9361_SPI_MISO_SIZE 1

/* AD9361 Fields */
#define CSR_AD9361_CONFIG_RST_N_OFFSET 0
#define CSR_AD9361_CONFIG_RST_N_SIZE 1
#define CSR_AD9361_CONFIG_ENABLE_OFFSET 1
#define CSR_AD9361_CONFIG_ENABLE_SIZE 1
#define CSR_AD9361_CONFIG_TXNRX_OFFSET 4
#define CSR_AD9361_CONFIG_TXNRX_SIZE 1
#define CSR_AD9361_CONFIG_EN_AGC_OFFSET 5
#define CSR_AD9361_CONFIG_EN_AGC_SIZE 1
#define CSR_AD9361_PHY_CONTROL_MODE_OFFSET 0
#define CSR_AD9361_PHY_CONTROL_MODE_SIZE 1

/* CTRL Registers */
#define CSR_CTRL_BASE (CSR_BASE + 0x800L)
#define CSR_CTRL_RESET_ADDR (CSR_BASE + 0x800L)
#define CSR_CTRL_RESET_SIZE 1
#define CSR_CTRL_SCRATCH_ADDR (CSR_BASE + 0x804L)
#define CSR_CTRL_SCRATCH_SIZE 1
#define CSR_CTRL_BUS_ERRORS_ADDR (CSR_BASE + 0x808L)
#define CSR_CTRL_BUS_ERRORS_SIZE 1

/* CTRL Fields */
#define CSR_CTRL_RESET_SOC_RST_OFFSET 0
#define CSR_CTRL_RESET_SOC_RST_SIZE 1
#define CSR_CTRL_RESET_CPU_RST_OFFSET 1
#define CSR_CTRL_RESET_CPU_RST_SIZE 1

/* DNA Registers */
#define CSR_DNA_BASE (CSR_BASE + 0x1000L)
#define CSR_DNA_ID_ADDR (CSR_BASE + 0x1000L)
#define CSR_DNA_ID_SIZE 2

/* DNA Fields */

/* ICAP Registers */
#define CSR_ICAP_BASE (CSR_BASE + 0x1800L)
#define CSR_ICAP_ADDR_ADDR (CSR_BASE + 0x1800L)
#define CSR_ICAP_ADDR_SIZE 1
#define CSR_ICAP_DATA_ADDR (CSR_BASE + 0x1804L)
#define CSR_ICAP_DATA_SIZE 1
#define CSR_ICAP_WRITE_ADDR (CSR_BASE + 0x1808L)
#define CSR_ICAP_WRITE_SIZE 1
#define CSR_ICAP_DONE_ADDR (CSR_BASE + 0x180cL)
#define CSR_ICAP_DONE_SIZE 1
#define CSR_ICAP_READ_ADDR (CSR_BASE + 0x1810L)
#define CSR_ICAP_READ_SIZE 1

/* ICAP Fields */

/* IDENTIFIER_MEM Registers */
#define CSR_IDENTIFIER_MEM_BASE (CSR_BASE + 0x2000L)

/* IDENTIFIER_MEM Fields */

/* LEDS Registers */
#define CSR_LEDS_BASE (CSR_BASE + 0x2800L)
#define CSR_LEDS_OUT_ADDR (CSR_BASE + 0x2800L)
#define CSR_LEDS_OUT_SIZE 1

/* LEDS Fields */

/* PCIE_DMA0 Registers */
#define CSR_PCIE_DMA0_BASE (CSR_BASE + 0x3000L)
#define CSR_PCIE_DMA0_WRITER_ENABLE_ADDR (CSR_BASE + 0x3000L)
#define CSR_PCIE_DMA0_WRITER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDR (CSR_BASE + 0x3004L)
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_SIZE 2
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_ADDR (CSR_BASE + 0x300cL)
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_PROG_N_ADDR (CSR_BASE + 0x3010L)
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_PROG_N_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_ADDR (CSR_BASE + 0x3014L)
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LEVEL_ADDR (CSR_BASE + 0x3018L)
#define CSR_PCIE_DMA0_WRITER_TABLE_LEVEL_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_RESET_ADDR (CSR_BASE + 0x301cL)
#define CSR_PCIE_DMA0_WRITER_TABLE_RESET_SIZE 1
#define CSR_PCIE_DMA0_READER_ENABLE_ADDR (CSR_BASE + 0x3020L)
#define CSR_PCIE_DMA0_READER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDR (CSR_BASE + 0x3024L)
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_SIZE 2
#define CSR_PCIE_DMA0_READER_TABLE_WE_ADDR (CSR_BASE + 0x302cL)
#define CSR_PCIE_DMA0_READER_TABLE_WE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_PROG_N_ADDR (CSR_BASE + 0x3030L)
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_PROG_N_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_ADDR (CSR_BASE + 0x3034L)
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LEVEL_ADDR (CSR_BASE + 0x3038L)
#define CSR_PCIE_DMA0_READER_TABLE_LEVEL_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_RESET_ADDR (CSR_BASE + 0x303cL)
#define CSR_PCIE_DMA0_READER_TABLE_RESET_SIZE 1
#define CSR_PCIE_DMA0_LOOPBACK_ENABLE_ADDR (CSR_BASE + 0x3040L)
#define CSR_PCIE_DMA0_LOOPBACK_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_SYNCHRONIZER_BYPASS_ADDR (CSR_BASE + 0x3044L)
#define CSR_PCIE_DMA0_SYNCHRONIZER_BYPASS_SIZE 1
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_ADDR (CSR_BASE + 0x3048L)
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_ADDR (CSR_BASE + 0x304cL)
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_ADDR (CSR_BASE + 0x3050L)
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_ADDR (CSR_BASE + 0x3054L)
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_ADDR (CSR_BASE + 0x3058L)
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_SIZE 1

/* PCIE_DMA0 Fields */
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDRESS_LSB_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDRESS_LSB_SIZE 32
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LENGTH_OFFSET 32
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LENGTH_SIZE 24
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_IRQ_DISABLE_OFFSET 56
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_IRQ_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LAST_DISABLE_OFFSET 57
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LAST_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_ADDRESS_MSB_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_ADDRESS_MSB_SIZE 32
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_INDEX_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_INDEX_SIZE 16
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_COUNT_OFFSET 16
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_COUNT_SIZE 16
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDRESS_LSB_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDRESS_LSB_SIZE 32
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LENGTH_OFFSET 32
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LENGTH_SIZE 24
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_IRQ_DISABLE_OFFSET 56
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_IRQ_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LAST_DISABLE_OFFSET 57
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LAST_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_WE_ADDRESS_MSB_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_WE_ADDRESS_MSB_SIZE 32
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_INDEX_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_INDEX_SIZE 16
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_COUNT_OFFSET 16
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_COUNT_SIZE 16
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_MODE_OFFSET 0
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_MODE_SIZE 2
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_DEPTH_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_DEPTH_SIZE 24
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_SCRATCH_OFFSET 24
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_SCRATCH_SIZE 4
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_LEVEL_MODE_OFFSET 31
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_LEVEL_MODE_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_LEVEL_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_LEVEL_SIZE 24
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_DEPTH_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_DEPTH_SIZE 24
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_SCRATCH_OFFSET 24
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_SCRATCH_SIZE 4
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_LEVEL_MODE_OFFSET 31
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_LEVEL_MODE_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_LEVEL_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_LEVEL_SIZE 24

/* PCIE_ENDPOINT Registers */
#define CSR_PCIE_ENDPOINT_BASE (CSR_BASE + 0x3800L)
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_ADDR (CSR_BASE + 0x3800L)
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MSI_ENABLE_ADDR (CSR_BASE + 0x3804L)
#define CSR_PCIE_ENDPOINT_PHY_MSI_ENABLE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MSIX_ENABLE_ADDR (CSR_BASE + 0x3808L)
#define CSR_PCIE_ENDPOINT_PHY_MSIX_ENABLE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_BUS_MASTER_ENABLE_ADDR (CSR_BASE + 0x380cL)
#define CSR_PCIE_ENDPOINT_PHY_BUS_MASTER_ENABLE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MAX_REQUEST_SIZE_ADDR (CSR_BASE + 0x3810L)
#define CSR_PCIE_ENDPOINT_PHY_MAX_REQUEST_SIZE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MAX_PAYLOAD_SIZE_ADDR (CSR_BASE + 0x3814L)
#define CSR_PCIE_ENDPOINT_PHY_MAX_PAYLOAD_SIZE_SIZE 1

/* PCIE_ENDPOINT Fields */
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_STATUS_OFFSET 0
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_STATUS_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_RATE_OFFSET 1
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_RATE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_WIDTH_OFFSET 2
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_WIDTH_SIZE 2
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_LTSSM_OFFSET 4
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_LTSSM_SIZE 6

/* PCIE_MSI Registers */
#define CSR_PCIE_MSI_BASE (CSR_BASE + 0x4000L)
#define CSR_PCIE_MSI_ENABLE_ADDR (CSR_BASE + 0x4000L)
#define CSR_PCIE_MSI_ENABLE_SIZE 1
#define CSR_PCIE_MSI_CLEAR_ADDR (CSR_BASE + 0x4004L)
#define CSR_PCIE_MSI_CLEAR_SIZE 1
#define CSR_PCIE_MSI_VECTOR_ADDR (CSR_BASE + 0x4008L)
#define CSR_PCIE_MSI_VECTOR_SIZE 1

/* PCIE_MSI Fields */

/* PCIE_PHY Registers */
#define CSR_PCIE_PHY_BASE (CSR_BASE + 0x4800L)
#define CSR_PCIE_PHY_PHY_LINK_STATUS_ADDR (CSR_BASE + 0x4800L)
#define CSR_PCIE_PHY_PHY_LINK_STATUS_SIZE 1
#define CSR_PCIE_PHY_PHY_MSI_ENABLE_ADDR (CSR_BASE + 0x4804L)
#define CSR_PCIE_PHY_PHY_MSI_ENABLE_SIZE 1
#define CSR_PCIE_PHY_PHY_MSIX_ENABLE_ADDR (CSR_BASE + 0x4808L)
#define CSR_PCIE_PHY_PHY_MSIX_ENABLE_SIZE 1
#define CSR_PCIE_PHY_PHY_BUS_MASTER_ENABLE_ADDR (CSR_BASE + 0x480cL)
#define CSR_PCIE_PHY_PHY_BUS_MASTER_ENABLE_SIZE 1
#define CSR_PCIE_PHY_PHY_MAX_REQUEST_SIZE_ADDR (CSR_BASE + 0x4810L)
#define CSR_PCIE_PHY_PHY_MAX_REQUEST_SIZE_SIZE 1
#define CSR_PCIE_PHY_PHY_MAX_PAYLOAD_SIZE_ADDR (CSR_BASE + 0x4814L)
#define CSR_PCIE_PHY_PHY_MAX_PAYLOAD_SIZE_SIZE 1

/* PCIE_PHY Fields */
#define CSR_PCIE_PHY_PHY_LINK_STATUS_STATUS_OFFSET 0
#define CSR_PCIE_PHY_PHY_LINK_STATUS_STATUS_SIZE 1
#define CSR_PCIE_PHY_PHY_LINK_STATUS_RATE_OFFSET 1
#define CSR_PCIE_PHY_PHY_LINK_STATUS_RATE_SIZE 1
#define CSR_PCIE_PHY_PHY_LINK_STATUS_WIDTH_OFFSET 2
#define CSR_PCIE_PHY_PHY_LINK_STATUS_WIDTH_SIZE 2
#define CSR_PCIE_PHY_PHY_LINK_STATUS_LTSSM_OFFSET 4
#define CSR_PCIE_PHY_PHY_LINK_STATUS_LTSSM_SIZE 6

/* SI5351_CLK0_MEASUREMENT Registers */
#define CSR_SI5351_CLK0_MEASUREMENT_BASE (CSR_BASE + 0x5000L)
#define CSR_SI5351_CLK0_MEASUREMENT_LATCH_ADDR (CSR_BASE + 0x5000L)
#define CSR_SI5351_CLK0_MEASUREMENT_LATCH_SIZE 1
#define CSR_SI5351_CLK0_MEASUREMENT_VALUE_ADDR (CSR_BASE + 0x5004L)
#define CSR_SI5351_CLK0_MEASUREMENT_VALUE_SIZE 2

/* SI5351_CLK0_MEASUREMENT Fields */

/* SI5351_CLK1_MEASUREMENT Registers */
#define CSR_SI5351_CLK1_MEASUREMENT_BASE (CSR_BASE + 0x5800L)
#define CSR_SI5351_CLK1_MEASUREMENT_LATCH_ADDR (CSR_BASE + 0x5800L)
#define CSR_SI5351_CLK1_MEASUREMENT_LATCH_SIZE 1
#define CSR_SI5351_CLK1_MEASUREMENT_VALUE_ADDR (CSR_BASE + 0x5804L)
#define CSR_SI5351_CLK1_MEASUREMENT_VALUE_SIZE 2

/* SI5351_CLK1_MEASUREMENT Fields */

/* SI5351_CLK2_MEASUREMENT Registers */
#define CSR_SI5351_CLK2_MEASUREMENT_BASE (CSR_BASE + 0x6000L)
#define CSR_SI5351_CLK2_MEASUREMENT_LATCH_ADDR (CSR_BASE + 0x6000L)
#define CSR_SI5351_CLK2_MEASUREMENT_LATCH_SIZE 1
#define CSR_SI5351_CLK2_MEASUREMENT_VALUE_ADDR (CSR_BASE + 0x6004L)
#define CSR_SI5351_CLK2_MEASUREMENT_VALUE_SIZE 2

/* SI5351_CLK2_MEASUREMENT Fields */

/* SI5351_CLK3_MEASUREMENT Registers */
#define CSR_SI5351_CLK3_MEASUREMENT_BASE (CSR_BASE + 0x6800L)
#define CSR_SI5351_CLK3_MEASUREMENT_LATCH_ADDR (CSR_BASE + 0x6800L)
#define CSR_SI5351_CLK3_MEASUREMENT_LATCH_SIZE 1
#define CSR_SI5351_CLK3_MEASUREMENT_VALUE_ADDR (CSR_BASE + 0x6804L)
#define CSR_SI5351_CLK3_MEASUREMENT_VALUE_SIZE 2

/* SI5351_CLK3_MEASUREMENT Fields */

/* SI5351_I2C Registers */
#define CSR_SI5351_I2C_BASE (CSR_BASE + 0x7000L)
#define CSR_SI5351_I2C_W_ADDR (CSR_BASE + 0x7000L)
#define CSR_SI5351_I2C_W_SIZE 1
#define CSR_SI5351_I2C_R_ADDR (CSR_BASE + 0x7004L)
#define CSR_SI5351_I2C_R_SIZE 1

/* SI5351_I2C Fields */
#define CSR_SI5351_I2C_W_SCL_OFFSET 0
#define CSR_SI5351_I2C_W_SCL_SIZE 1
#define CSR_SI5351_I2C_W_OE_OFFSET 1
#define CSR_SI5351_I2C_W_OE_SIZE 1
#define CSR_SI5351_I2C_W_SDA_OFFSET 2
#define CSR_SI5351_I2C_W_SDA_SIZE 1
#define CSR_SI5351_I2C_R_SDA_OFFSET 0
#define CSR_SI5351_I2C_R_SDA_SIZE 1

/* SI5351_PWM Registers */
#define CSR_SI5351_PWM_BASE (CSR_BASE + 0x7800L)
#define CSR_SI5351_PWM_ENABLE_ADDR (CSR_BASE + 0x7800L)
#define CSR_SI5351_PWM_ENABLE_SIZE 1
#define CSR_SI5351_PWM_WIDTH_ADDR (CSR_BASE + 0x7804L)
#define CSR_SI5351_PWM_WIDTH_SIZE 1
#define CSR_SI5351_PWM_PERIOD_ADDR (CSR_BASE + 0x7808L)
#define CSR_SI5351_PWM_PERIOD_SIZE 1

/* SI5351_PWM Fields */

/* XADC Registers */
#define CSR_XADC_BASE (CSR_BASE + 0x8000L)
#define CSR_XADC_TEMPERATURE_ADDR (CSR_BASE + 0x8000L)
#define CSR_XADC_TEMPERATURE_SIZE 1
#define CSR_XADC_VCCINT_ADDR (CSR_BASE + 0x8004L)
#define CSR_XADC_VCCINT_SIZE 1
#define CSR_XADC_VCCAUX_ADDR (CSR_BASE + 0x8008L)
#define CSR_XADC_VCCAUX_SIZE 1
#define CSR_XADC_VCCBRAM_ADDR (CSR_BASE + 0x800cL)
#define CSR_XADC_VCCBRAM_SIZE 1
#define CSR_XADC_EOC_ADDR (CSR_BASE + 0x8010L)
#define CSR_XADC_EOC_SIZE 1
#define CSR_XADC_EOS_ADDR (CSR_BASE + 0x8014L)
#define CSR_XADC_EOS_SIZE 1

/* XADC Fields */

#endif /* ! __GENERATED_CSR_H */
