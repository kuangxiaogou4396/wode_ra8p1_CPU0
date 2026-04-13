/* generated HAL source file - do not edit */
#include "hal_data.h"
iic_master_instance_ctrl_t g_i2c_master1_ctrl;
const iic_master_extended_cfg_t g_i2c_master1_extend =
		{ .timeout_mode = IIC_MASTER_TIMEOUT_MODE_SHORT, .timeout_scl_low =
				IIC_MASTER_TIMEOUT_SCL_LOW_ENABLED, .smbus_operation = 0,
				/* Actual calculated bitrate: 393082. Actual calculated duty cycle: 50%. */.clock_settings.brl_value =
						15, .clock_settings.brh_value = 15,
				.clock_settings.cks_value = 2, .clock_settings.sddl_value = 0,
				.clock_settings.dlcs_value = 0, };
const i2c_master_cfg_t g_i2c_master1_cfg = { .channel = 1, .rate =
		I2C_MASTER_RATE_FAST, .slave = 0x00, .addr_mode =
		I2C_MASTER_ADDR_MODE_7BIT,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
		.p_callback = iic1_callback, .p_context = NULL,
#if defined(VECTOR_NUMBER_IIC1_RXI)
    .rxi_irq             = VECTOR_NUMBER_IIC1_RXI,
#else
		.rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_TXI)
    .txi_irq             = VECTOR_NUMBER_IIC1_TXI,
#else
		.txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_TEI)
    .tei_irq             = VECTOR_NUMBER_IIC1_TEI,
#else
		.tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_ERI)
    .eri_irq             = VECTOR_NUMBER_IIC1_ERI,
#else
		.eri_irq = FSP_INVALID_VECTOR,
#endif
		.ipl = (10), .p_extend = &g_i2c_master1_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c_master1 = { .p_ctrl = &g_i2c_master1_ctrl,
		.p_cfg = &g_i2c_master1_cfg, .p_api = &g_i2c_master_on_iic };

dmac_instance_ctrl_t g_transfer0_ctrl;
transfer_info_t g_transfer0_info = { .transfer_settings_word_b.dest_addr_mode =
		TRANSFER_ADDR_MODE_INCREMENTED, .transfer_settings_word_b.repeat_area =
		TRANSFER_REPEAT_AREA_SOURCE, .transfer_settings_word_b.irq =
		TRANSFER_IRQ_END, .transfer_settings_word_b.chain_mode =
		TRANSFER_CHAIN_MODE_DISABLED, .transfer_settings_word_b.src_addr_mode =
		TRANSFER_ADDR_MODE_INCREMENTED, .transfer_settings_word_b.size =
		TRANSFER_SIZE_1_BYTE, .transfer_settings_word_b.mode =
		TRANSFER_MODE_BLOCK, .p_dest = (void*) NULL,
		.p_src = (void const*) NULL, .num_blocks = 1, .length = 64, };
const dmac_extended_cfg_t g_transfer0_extend = { .offset = 0, .src_buffer_size =
		0,
#if defined(VECTOR_NUMBER_DMAC0_INT)
    .irq                 = VECTOR_NUMBER_DMAC0_INT,
#else
		.irq = FSP_INVALID_VECTOR,
#endif
		.ipl = (BSP_IRQ_DISABLED), .channel = 0, .p_callback = NULL,
		.p_context = NULL, .activation_source = ELC_EVENT_NONE, };
const transfer_cfg_t g_transfer0_cfg = { .p_info = &g_transfer0_info,
		.p_extend = &g_transfer0_extend, };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer0 = { .p_ctrl = &g_transfer0_ctrl, .p_cfg =
		&g_transfer0_cfg, .p_api = &g_transfer_on_dmac };

ospi_b_instance_ctrl_t g_ospi1_ctrl;

static ospi_b_timing_setting_t g_ospi1_timing_settings = {
		.command_to_command_interval = OSPI_B_COMMAND_INTERVAL_CLOCKS_2,
		.cs_pullup_lag = OSPI_B_COMMAND_CS_PULLUP_CLOCKS_NO_EXTENSION,
		.cs_pulldown_lead = OSPI_B_COMMAND_CS_PULLDOWN_CLOCKS_NO_EXTENSION,
		.sdr_drive_timing = OSPI_B_SDR_DRIVE_TIMING_BEFORE_CK,
		.sdr_sampling_edge = OSPI_B_CK_EDGE_FALLING, .sdr_sampling_delay =
				OSPI_B_SDR_SAMPLING_DELAY_NONE, .ddr_sampling_extension =
				OSPI_B_DDR_SAMPLING_EXTENSION_1, };
extern ospi_b_xspi_command_set_t g_hyper_ram_commands[];
static const ospi_b_table_t g_ospi1_command_set = { .p_table =
		(void*) g_hyper_ram_commands, .length = 1 };

#if OSPI_B_CFG_DOTF_SUPPORT_ENABLE
extern uint8_t g_ospi_dotf_iv[];
extern uint8_t g_ospi_dotf_key[];

static ospi_b_dotf_cfg_t g_ospi_dotf_cfg=
{
    .key_type       = OSPI_B_DOTF_AES_KEY_TYPE_128,
    .format         = OSPI_B_DOTF_KEY_FORMAT_PLAINTEXT,
    .p_start_addr   = (uint32_t *)0x90000000,
    .p_end_addr     = (uint32_t *)0x90001FFF,
    .p_key          = (uint32_t *)g_ospi_dotf_key,
    .p_iv           = (uint32_t *)g_ospi_dotf_iv,
};
#endif

static const ospi_b_extended_cfg_t g_ospi1_extended_cfg = { .ospi_b_unit = 1,
		.channel = (ospi_b_device_number_t) 0, .p_timing_settings =
				&g_ospi1_timing_settings, .p_xspi_command_set =
				&g_ospi1_command_set, .data_latch_delay_clocks =
				OSPI_B_DS_TIMING_DELAY_8,
		.p_autocalibration_preamble_pattern_addr = (uint8_t*) 0x00,
#if OSPI_B_CFG_DMAC_SUPPORT_ENABLE
    .p_lower_lvl_transfer                    = &g_transfer0,
#endif
#if OSPI_B_CFG_DOTF_SUPPORT_ENABLE
    .p_dotf_cfg                              = &g_ospi_dotf_cfg,
#endif
#if OSPI_B_CFG_ROW_ADDRESSING_SUPPORT_ENABLE
    .row_index_bytes                         = 0xFF,
#endif
		};
const spi_flash_cfg_t g_ospi1_cfg = { .spi_protocol =
		SPI_FLASH_PROTOCOL_8D_8D_8D, .read_mode = SPI_FLASH_READ_MODE_STANDARD, /* Unused by OSPI_B */
.address_bytes = SPI_FLASH_ADDRESS_BYTES_4, .dummy_clocks =
		SPI_FLASH_DUMMY_CLOCKS_DEFAULT, /* Unused by OSPI_B */
.page_program_address_lines = (spi_flash_data_lines_t) 0U, /* Unused by OSPI_B */
.page_size_bytes = 64, .write_status_bit = 1, .write_enable_bit = 1,
		.page_program_command = 0, /* OSPI_B uses command sets. See g_ospi1_command_set. */
		.write_enable_command = 0, /* OSPI_B uses command sets. See g_ospi1_command_set. */
		.status_command = 0, /* OSPI_B uses command sets. See g_ospi1_command_set. */
		.read_command = 0, /* OSPI_B uses command sets. See g_ospi1_command_set. */
#if OSPI_B_CFG_XIP_SUPPORT_ENABLE
    .xip_enter_command           = 0,
    .xip_exit_command            = 0,
#else
		.xip_enter_command = 0U, .xip_exit_command = 0U,
#endif
		.erase_command_list_length = 0U, /* OSPI_B uses command sets. See g_ospi1_command_set. */
		.p_erase_command_list = NULL, /* OSPI_B uses command sets. See g_ospi1_command_set. */
		.p_extend = &g_ospi1_extended_cfg, };

/** This structure encompasses everything that is needed to use an instance of this interface. */
const spi_flash_instance_t g_ospi1 = { .p_ctrl = &g_ospi1_ctrl, .p_cfg =
		&g_ospi1_cfg, .p_api = &g_ospi_b_on_spi_flash, };

#if defined OSPI_B_CFG_DOTF_PROTECTED_MODE_SUPPORT_ENABLE
rsip_instance_t const * const gp_rsip_instance = &RA_NOT_DEFINED;
#endif
ceu_instance_ctrl_t g_ceu_qvga_ctrl;
const ceu_extended_cfg_t g_ceu_qvga_extended_cfg = { .capture_format =
		CEU_CAPTURE_FORMAT_DATA_SYNCHRONOUS, .data_bus_width =
		CEU_DATA_BUS_SIZE_8_BIT, .edge_info.dsel = 0, .edge_info.hdsel = 0,
		.edge_info.vdsel = 0, .hsync_polarity = CEU_HSYNC_POLARITY_HIGH,
		.vsync_polarity = CEU_VSYNC_POLARITY_HIGH, .byte_swapping = {
				.swap_8bit_units = (0x1 | 0x2 | 0x4 | 0x0) >> 0x00 & 0x01,
				.swap_16bit_units = (0x1 | 0x2 | 0x4 | 0x0) >> 0x01 & 0x01,
				.swap_32bit_units = (0x1 | 0x2 | 0x4 | 0x0) >> 0x02 & 0x01, },
		.burst_mode = CEU_BURST_TRANSFER_MODE_X8, .image_area_size = 800 * 480
				* 2, .interrupts_enabled = 0 | R_CEU_CEIER_CPEIE_Msk | 0
				| R_CEU_CEIER_VDIE_Msk | R_CEU_CEIER_CDTOFIE_Msk | 0 | 0
				| R_CEU_CEIER_VBPIE_Msk | R_CEU_CEIER_NHDIE_Msk
				| R_CEU_CEIER_NVDIE_Msk, .ceu_ipl = (10), .ceu_irq =
				VECTOR_NUMBER_CEU_CEUI, };

const capture_cfg_t g_ceu_qvga_cfg = { .x_capture_pixels = 800,
		.y_capture_pixels = 480, .x_capture_start_pixel = 0,
		.y_capture_start_pixel = 0, .bytes_per_pixel = 2, .p_callback =
				g_ceu_callback, .p_context = (void*) NULL, .p_extend =
				&g_ceu_qvga_extended_cfg, };

const capture_instance_t g_ceu_qvga = { .p_ctrl = &g_ceu_qvga_ctrl, .p_cfg =
		&g_ceu_qvga_cfg, .p_api = &g_ceu_on_capture, };
ipc_instance_ctrl_t g_ipc1_ctrl;

/** IPC configuration */
const ipc_cfg_t g_ipc1_cfg = { .channel = 1, .p_callback = cpu0_ipc1_callback,
#if defined(NULL)
                .p_context = NULL,
#else
		.p_context = (void*) &NULL,
#endif
		.ipl = (5),
#if defined(VECTOR_NUMBER_IPC_IRQ1)
                .irq = VECTOR_NUMBER_IPC_IRQ1,
#else
		.irq = FSP_INVALID_VECTOR,
#endif
		};

/* Instance structure to use this module. */
const ipc_instance_t g_ipc1 = { .p_ctrl = &g_ipc1_ctrl, .p_cfg = &g_ipc1_cfg,
		.p_api = &g_ipc_on_ipc };
ipc_instance_ctrl_t g_ipc0_ctrl;

/** IPC configuration */
const ipc_cfg_t g_ipc0_cfg = { .channel = 0, .p_callback = NULL,
#if defined(NULL)
                .p_context = NULL,
#else
		.p_context = (void*) &NULL,
#endif
		.ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_IPC_IRQ0)
                .irq = VECTOR_NUMBER_IPC_IRQ0,
#else
		.irq = FSP_INVALID_VECTOR,
#endif
		};

/* Instance structure to use this module. */
const ipc_instance_t g_ipc0 = { .p_ctrl = &g_ipc0_ctrl, .p_cfg = &g_ipc0_cfg,
		.p_api = &g_ipc_on_ipc };
void g_hal_init(void) {
	g_common_init();
}
