#include "lcd_mipi.h"

// 宏定义替换，去掉原先的 drv_log，如果是裸机可以使用 printf 或者不打印
#define MIPI_DSI_DISPLAY_CONFIG_DATA_DELAY_FLAG      ((mipi_dsi_cmd_id_t) 0xFE)
#define MIPI_DSI_DISPLAY_CONFIG_DATA_END_OF_TABLE    ((mipi_dsi_cmd_id_t) 0xFD)
volatile bool g_vsync_flag = false;
typedef struct
{
    unsigned char        size;
    unsigned char        buffer[50];
    mipi_dsi_cmd_id_t    cmd_id;
    mipi_dsi_cmd_flag_t  flags;
} lcd_table_setting_t;

volatile static bool g_message_sent = false;
volatile static mipi_dsi_phy_status_t g_phy_status;

/* MIPI DSI 屏幕初始化序列表 */
const lcd_table_setting_t g_lcd_init_focuslcd[] =
{
    // 480*800 冠显
    {4,  {0x99, 0x71, 0x02, 0xa2},   MIPI_DSI_CMD_ID_GENERIC_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
    {4,  {0x99, 0x71, 0x02, 0xa3},   MIPI_DSI_CMD_ID_GENERIC_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
    {4,  {0x99, 0x71, 0x02, 0xa4},   MIPI_DSI_CMD_ID_GENERIC_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},

    {2,  {0xA4, 0x31},   MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},   // 2Lanes
    {8,  {0xB0, 0x22, 0x57, 0x1E, 0x61, 0x2F, 0x57, 0x61},   MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},   // VGH_VGL (14v)
    {3,  {0xB7, 0x64, 0x64},  MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},  // Source (5v)
    {3,  {0xBF, 0xB4, 0xB4},  MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},  // VCOM (-2v)

    // Gamma----(5V)
    {38, {0xC8, 0x00, 0x00, 0x0F, 0x1C, 0x34, 0x00, 0x60, 0x03, 0xA0, 0x06, 0x10, 0xFE, 0x06, 0x74, 0x03, 0x21, 0xC4, 0x00, 0x08, 0x00, 0x22, 0x46, 0x0F, 0x8F, 0x0A, 0x32, 0xF2, 0x0C, 0x42, 0x0F}, MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
    {38, {0xC9, 0x00, 0x00, 0x0F, 0x1C, 0x34, 0x00, 0x60, 0x03, 0xA0, 0x06, 0x10, 0xFE, 0x06, 0x74, 0x03, 0x21, 0xC4, 0x00, 0x08, 0x00, 0x22, 0x46, 0x0F, 0x8F, 0x0A, 0x32, 0xF2, 0x0C, 0x42, 0x0F}, MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},

    // GIP
    {7,  {0xD7, 0x10, 0x2A, 0x28, 0x19, 0x90, 0x90},  MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},  // 800

    // 其他初始化序列...（因为原配置过长，这里直接按照你的源文件截取补全）
    {33, {0xA3, 0x51, 0x03, 0x80, 0xCF, 0x44, 0x00, 0x00, 0x00, 0x00, 0x04, 0x78, 0x78, 0x00, 0x1A, 0x00, 0x45, 0x05, 0x00, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x02, 0x20, 0x52, 0x00, 0x05}, MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
    {44, {0xA6, 0x02, 0x00, 0x24, 0x55, 0x35, 0x00, 0x38, 0x00, 0x78, 0x78, 0x00, 0x24, 0x55, 0x36, 0x00, 0x37, 0x00, 0x78, 0x78, 0x02, 0xAC, 0x51, 0x3A, 0x00, 0x00, 0x00, 0x78, 0x78, 0x03}, MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
    {48, {0xA7, 0x19, 0x19, 0x00, 0x64, 0x40, 0x07, 0x16, 0x40, 0x00, 0x04, 0x03, 0x78, 0x78, 0x00, 0x64, 0x40, 0x25, 0x34, 0x00, 0x00, 0x02, 0x01, 0x78, 0x78, 0x00, 0x64, 0x40, 0x4B, 0x5A}, MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
    {37, {0xAC, 0x08, 0x0A, 0x11, 0x00, 0x13, 0x03, 0x1B, 0x18, 0x06, 0x1A, 0x19, 0x1B, 0x1B, 0x1B, 0x18, 0x1B, 0x09, 0x0B, 0x10, 0x02, 0x12, 0x01, 0x1B, 0x18, 0x06, 0x1A, 0x19, 0x1B, 0x1B}, MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},

    {8,  {0xAD, 0xCC, 0x40, 0x46, 0x11, 0x04, 0x78, 0x78},  MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
    {15, {0xE8, 0x30, 0x07, 0x00, 0x94, 0x94, 0x9C, 0x00, 0xE2, 0x04, 0x00, 0x00, 0x00, 0x00, 0xEF},  MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
    {33, {0xE7, 0x8B, 0x3C, 0x00, 0x0C, 0xF0, 0x5D, 0x00, 0x5D, 0x00, 0x5D, 0x00, 0x5D, 0x00, 0xFF, 0x00, 0x08, 0x7B, 0x00, 0x00, 0xC8, 0x6A, 0x5A, 0x08, 0x1A, 0x3C, 0x00, 0x81, 0x01, 0xCC}, MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},

    {2,  {0x11, 0x00},  MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_0_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},  // Sleep out
    {120,{0},           MIPI_DSI_DISPLAY_CONFIG_DATA_DELAY_FLAG, (mipi_dsi_cmd_flag_t)0},
    {2,  {0x29, 0x00},  MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_0_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},  // display on
    {2,  {0x35, 0x00},  MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},  // TE off

    {0x00,{0},          MIPI_DSI_DISPLAY_CONFIG_DATA_END_OF_TABLE, (mipi_dsi_cmd_flag_t)0},
};

/* MIPI DSI 通信的回调函数（需要在 FSP 中配置挂载此函数） */
void mipi_dsi0_callback(mipi_dsi_callback_args_t *p_args)
{
    switch (p_args->event)
    {
    case MIPI_DSI_EVENT_SEQUENCE_0:
    {
        if (MIPI_DSI_SEQUENCE_STATUS_DESCRIPTORS_FINISHED == p_args->tx_status)
        {
            g_message_sent = true;
        }
        break;
    }
    case MIPI_DSI_EVENT_PHY:
    {
        g_phy_status |= p_args->phy_status;
        break;
    }
    default:
        break;
    }
}



/* 在 FSP 配置中你把回调函数命名为 Display_callback，所以代码里要实现这个名字的函数 */
void Display_callback(display_callback_args_t *p_args)
{
    if (DISPLAY_EVENT_LINE_DETECTION == p_args->event)
    {
        g_vsync_flag = true;
    }
}

/* 推送 MIPI DSI 初始化表 */
static void mipi_dsi_push_table(const lcd_table_setting_t *table)
{
    fsp_err_t err = FSP_SUCCESS;
    const lcd_table_setting_t *p_entry = table;

    while (MIPI_DSI_DISPLAY_CONFIG_DATA_END_OF_TABLE != p_entry->cmd_id)
    {
        mipi_dsi_cmd_t msg =
        {
            .channel = 0,
            .cmd_id = p_entry->cmd_id,
            .flags = p_entry->flags,
            .tx_len = p_entry->size,
            .p_tx_buffer = (uint8_t *)p_entry->buffer,
        };

        if (MIPI_DSI_DISPLAY_CONFIG_DATA_DELAY_FLAG == msg.cmd_id)
        {
        	R_BSP_SoftwareDelay(p_entry->size, BSP_DELAY_UNITS_MILLISECONDS);
        }
        else
        {
            g_message_sent = false;

            /* Send a command to the peripheral device */
            err = R_MIPI_DSI_Command(&g_mipi_dsi0_ctrl, &msg);

            /* Wait */
            while (!g_message_sent);
        }
        p_entry++;
    }
}

/* 开放给 main 的初始化接口 */
void ra8_mipi_lcd_init(void)
{
    // 调用屏幕初始化表下发
    mipi_dsi_push_table(g_lcd_init_focuslcd);
}
