#include <main0_thread.h>
#include "hal_data.h"
#include "ceu/ceu.h"
#include "lcd_mipi/lcd_mipi.h"
#include "core_cm85.h"
/* New Thread entry function */
/* pvParameters contains TaskHandle_t */
extern uint8_t fb_background[2][DISPLAY_BUFFER_STRIDE_BYTES_INPUT0 * DISPLAY_VSIZE_INPUT0];
extern volatile uint8_t g_ceu_write_index ;
extern volatile bool g_frame_captured;
extern volatile bool g_vsync_flag;
void cpu0_ipc1_callback(ipc_callback_args_t * p_args)
{
    // p_args->event 中包含了触发的事件类型
    if (p_args->event & IPC_EVENT_IRQ0)
    {
        // 收到来自 CPU1 的消息/事件！
        // 在这里处理接收逻辑（注意：这是在中断上下文）
    }
}

void main0_thread_entry(void *pvParameters) {
	R_BSP_SecondaryCoreStart();
	FSP_PARAMETER_NOT_USED(pvParameters);

	R_OSPI_B_Open(&g_ospi1_ctrl, &g_ospi1_cfg);
	R_IIC_MASTER_Open(&g_i2c_master1_ctrl, &g_i2c_master1_cfg);
	OV5640_RGB565_Default_Config();
	OV5640_USER_Config();
	OV5640_FOCUS_AD5820_Init();
	OV5640_FOCUS_AD5820_Constant_Focus();

	R_CEU_Open(&g_ceu_qvga_ctrl, &g_ceu_qvga_cfg);
	R_GLCDC_Open(&g_display0_ctrl, &g_display0_cfg);
	R_MIPI_DSI_Open(&g_mipi_dsi0_ctrl, &g_mipi_dsi0_cfg);
	R_MIPI_DSI_Start(&g_mipi_dsi0_ctrl);
	ra8_mipi_lcd_init();
	R_GLCDC_Start(&g_display0_ctrl);
	d2_device *d2_handle = d2_opendevice(0);
	d2_inithw(d2_handle, 0);
	    // 分配一个指令缓存区，存放我们要画的图形指令
	d2_renderbuffer *renderbuffer = d2_newrenderbuffer(d2_handle, 20, 20);
	d2_selectrenderbuffer(d2_handle, renderbuffer);

	    /* 启动第一次摄像头采集 */
	R_CEU_CaptureStart(&g_ceu_qvga_ctrl, (uint8_t *)fb_background[g_ceu_write_index]);
	while (1) {
		if (g_frame_captured) {
		        g_frame_captured = false;

		        /* 1. DAVE2D 画图 */
		        d2_framebuffer(d2_handle, (void *)fb_background[g_ceu_write_index], 800, 800, 480, d2_mode_rgb565);
		        d2_setcolor(d2_handle, 0, 0xFF0000);
		        d2_renderbox_outline(d2_handle, 100, 100, 280, 280);
		        d2_executerenderbuffer(d2_handle, renderbuffer, 0);
		        d2_flushframe(d2_handle);
		        SCB_CleanDCache_by_Addr((uint32_t *)fb_background[g_ceu_write_index], 800 * 480 * 2);
		        /* 2. 等待屏幕刷新信号 (防撕裂) */
		        // 注意：这里必须有一个内部死循环卡住，因为我们要精准卡在 VSYNC 到来的那一瞬间去切换 Buffer
		        while (!g_vsync_flag) {
		            // 如果不加 vTaskDelay(1)，这个死循环会占满 100% CPU，导致其他任务卡死
		            vTaskDelay(1);
		        }
		        g_vsync_flag = false; // 用完马上清零，为下一帧做准备

		        /* 3. 切换 Buffer */
		        R_GLCDC_BufferChange(&g_display0_ctrl, (uint8_t *)fb_background[g_ceu_write_index], DISPLAY_FRAME_LAYER_1);

		        /* 4. 开启下次采集 */
		        g_ceu_write_index = (g_ceu_write_index == 0) ? 1 : 0;
		        R_CEU_CaptureStart(&g_ceu_qvga_ctrl, (uint8_t *)fb_background[g_ceu_write_index]);
		    }

		    // 总的循环底部：如果摄像头没拍完，就在这里 Delay 让出 CPU 给其他任务
		    vTaskDelay(1);
	}
}
