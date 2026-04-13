#ifndef __LCD_MIPI_H
#define __LCD_MIPI_H

#include <stdint.h>
#include <stdbool.h>
#include "hal_data.h"  // 包含瑞萨 FSP 库生成的底层结构体，例如 g_mipi_dsi0_ctrl 等



/* 声明屏幕初始化函数 */
void ra8_mipi_lcd_init(void);

#endif
