/*
 * ceu.h
 *
 *  Created on: 2026年4月11日
 *      Author: 28972
 */

#ifndef __CEU_H
#define __CEU_H
#include "hal_data.h"
#define FRAME_RATE_30FPS	0 //30Ö¡
#define FRAME_RATE_15FPS	1 //15Ö¡

#define DCMI_TIMEOUT_MAX               10000

typedef struct
{
  uint8_t PIDH;
  uint8_t PIDL;
}OV5640_IDTypeDef;

typedef struct
{
	uint8_t frame_rate;	//Êä³öÖ¡ÂÊ

	uint16_t cam_isp_sx; //ÉãÏñÍ·ISP XÆðÊ¼Î»ÖÃ
	uint16_t cam_isp_sy; //ÉãÏñÍ·ISP YÆðÊ¼Î»ÖÃ

	uint16_t cam_isp_width; //ÉãÏñÍ·ISP ¿í
	uint16_t cam_isp_height; //ÉãÏñÍ·ISP ¸ß

	uint8_t scaling;				//ÊÇ·ñÊ¹ÓÃ×Ô¶¯Ëõ·Å£¬ÍÆ¼öÊ¹ÓÃ£¬1:Ê¹ÓÃ£¬0:²»Ê¹ÓÃ

	uint16_t cam_out_sx; //ÉãÏñÍ·Êä³ö´°¿ÚXÆðÊ¼Î»ÖÃ
	uint16_t cam_out_sy; //ÉãÏñÍ·Êä³ö´°¿ÚYÆðÊ¼Î»ÖÃ

	uint16_t cam_out_width;//Êä³öÍ¼Ïñ·Ö±æÂÊ£¬¿í
	uint16_t cam_out_height;//Êä³öÍ¼Ïñ·Ö±æÂÊ£¬¸ß

	uint16_t lcd_sx;//Í¼ÏñÏÔÊ¾ÔÚÒº¾§ÆÁµÄXÆðÊ¼Î»ÖÃ
	uint16_t lcd_sy;//Í¼ÏñÏÔÊ¾ÔÚÒº¾§ÆÁµÄYÆðÊ¼Î»ÖÃ
	uint8_t lcd_scan;//Òº¾§ÆÁµÄÉ¨ÃèÄ£Ê½£¨0-7£©

	uint8_t light_mode;//¹âÕÕÄ£Ê½£¬²ÎÊý·¶Î§[0~4]
	int8_t saturation;//±¥ºÍ¶È,²ÎÊý·¶Î§[-3 ~ +3]
	int8_t brightness;//¹âÕÕ¶È£¬²ÎÊý·¶Î§[-4~+4]
	int8_t contrast;//¶Ô±È¶È£¬²ÎÊý·¶Î§[-3~+3]
	uint8_t effect;	//ÌØÊâÐ§¹û£¬²ÎÊý·¶Î§[0~9]:
	int8_t exposure;//ÆØ¹â²¹³¥£¬²ÎÊý·¶Î§[-3~+3]


	uint8_t auto_focus;//ÊÇ·ñÊ¹ÓÃ×Ô¶¯¶Ô½¹¹¦ÄÜ 1:Ê¹ÓÃ£¬0:²»Ê¹ÓÃ

}OV5640_MODE_PARAM;

extern OV5640_MODE_PARAM cam_mode;

#define OV5640_DEVICE_ADDRESS    0x78
#define OV5640_DSP_R_BYPASS     0x05
#define OV5640_DSP_Qs           0x44
#define OV5640_DSP_CTRL         0x50
#define OV5640_DSP_HSIZE1       0x51
#define OV5640_DSP_VSIZE1       0x52
#define OV5640_DSP_XOFFL        0x53
#define OV5640_DSP_YOFFL        0x54
#define OV5640_DSP_VHYX         0x55
#define OV5640_DSP_DPRP         0x56
#define OV5640_DSP_TEST         0x57
#define OV5640_DSP_ZMOW         0x5A
#define OV5640_DSP_ZMOH         0x5B
#define OV5640_DSP_ZMHH         0x5C
#define OV5640_DSP_BPADDR       0x7C
#define OV5640_DSP_BPDATA       0x7D
#define OV5640_DSP_CTRL2        0x86
#define OV5640_DSP_CTRL3        0x87
#define OV5640_DSP_SIZEL        0x8C
#define OV5640_DSP_HSIZE2       0xC0
#define OV5640_DSP_VSIZE2       0xC1
#define OV5640_DSP_CTRL0        0xC2
#define OV5640_DSP_CTRL1        0xC3
#define OV5640_DSP_R_DVP_SP     0xD3
#define OV5640_DSP_IMAGE_MODE   0xDA
#define OV5640_DSP_RESET        0xE0
#define OV5640_DSP_MS_SP        0xF0
#define OV5640_DSP_SS_ID        0x7F
#define OV5640_DSP_SS_CTRL      0xF8
#define OV5640_DSP_MC_BIST      0xF9
#define OV5640_DSP_MC_AL        0xFA
#define OV5640_DSP_MC_AH        0xFB
#define OV5640_DSP_MC_D         0xFC
#define OV5640_DSP_P_STATUS     0xFE
#define OV5640_DSP_RA_DLMT      0xFF

/* OV5640 Registers definition when sensor bank selected (0xFF = 0x01) */
#define OV5640_SENSOR_GAIN       0x00
#define OV5640_SENSOR_COM1       0x03
#define OV5640_SENSOR_REG04      0x04
#define OV5640_SENSOR_REG08      0x08
#define OV5640_SENSOR_COM2       0x09

#define OV5640_SENSOR_PIDH       0x300A
#define OV5640_SENSOR_PIDL       0x300B

#define OV5640_SENSOR_COM3       0x0C
#define OV5640_SENSOR_COM4       0x0D
#define OV5640_SENSOR_AEC        0x10
#define OV5640_SENSOR_CLKRC      0x11
#define OV5640_SENSOR_COM7       0x12
#define OV5640_SENSOR_COM8       0x13
#define OV5640_SENSOR_COM9       0x14
#define OV5640_SENSOR_COM10      0x15
#define OV5640_SENSOR_HREFST     0x17
#define OV5640_SENSOR_HREFEND    0x18
#define OV5640_SENSOR_VSTART     0x19
#define OV5640_SENSOR_VEND       0x1A


#define OV5640_SENSOR_MIDH       0x1C
#define OV5640_SENSOR_MIDL       0x1D

#define OV5640_SENSOR_AEW        0x24
#define OV5640_SENSOR_AEB        0x25
#define OV5640_SENSOR_W          0x26
#define OV5640_SENSOR_REG2A      0x2A
#define OV5640_SENSOR_FRARL      0x2B
#define OV5640_SENSOR_ADDVSL     0x2D
#define OV5640_SENSOR_ADDVHS     0x2E
#define OV5640_SENSOR_YAVG       0x2F
#define OV5640_SENSOR_REG32      0x32
#define OV5640_SENSOR_ARCOM2     0x34
#define OV5640_SENSOR_REG45      0x45
#define OV5640_SENSOR_FLL        0x46
#define OV5640_SENSOR_FLH        0x47
#define OV5640_SENSOR_COM19      0x48
#define OV5640_SENSOR_ZOOMS      0x49
#define OV5640_SENSOR_COM22      0x4B
#define OV5640_SENSOR_COM25      0x4E
#define OV5640_SENSOR_BD50       0x4F
#define OV5640_SENSOR_BD60       0x50
#define OV5640_SENSOR_REG5D      0x5D
#define OV5640_SENSOR_REG5E      0x5E
#define OV5640_SENSOR_REG5F      0x5F
#define OV5640_SENSOR_REG60      0x60
#define OV5640_SENSOR_HISTO_LOW  0x61
#define OV5640_SENSOR_HISTO_HIGH 0x62

void i2c_write( uint16_t reg_addr, uint8_t *data, uint8_t len);
uint8_t i2c_read( uint16_t reg_addr, uint8_t *data, uint32_t len);
void OV5640_WriteReg(uint16_t reg, uint8_t data);
uint8_t OV5640_FOCUS_AD5820_Init(void);
void hyperram_init(void);
uint16_t swap16(uint16_t value);
void OV5640_USER_Config(void);
void OV5640_ReadID(OV5640_IDTypeDef *OV5640ID);
uint8_t OV5640_ReadReg(uint16_t reg);
void OV5640_Reset(void);
void OV5640_RGB565_Default_Config(void);
uint8_t OV5640_FOCUS_AD5820_Constant_Focus(void);
uint8_t OV5640_WriteFW_FSP(uint8_t *pBuffer, uint16_t BufferSize);
void OV5640_FrameRate_Set(uint8_t frame_rate);
void OV5640_BrightnessConfig(int8_t Brightness);
void OV5640_ContrastConfig(int8_t cnst);
void OV5640_Color_Saturation(int8_t sat);
void OV5640_ColorEffectsConfig(uint8_t value1, uint8_t value2);
void OV5640_LightMode(uint8_t mode);
void OV5640_SpecialEffects(uint8_t mode);
void OV5640_Exposure(int8_t ev);
uint8_t OV5640_WriteFW_FSP(uint8_t *pBuffer ,uint16_t BufferSize);
void OV5640_ISPSize_Set(uint16_t x_st,uint16_t y_st,uint16_t width,uint16_t height);
void OV5640_OutSize_Set(uint8_t scaling,uint16_t x_off,uint16_t y_off,uint16_t width,uint16_t height);
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#endif /* CEU_CEU_H_ */
