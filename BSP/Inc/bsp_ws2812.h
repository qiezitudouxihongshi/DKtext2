#include "tim.h"

#ifndef DM0_WS2812_H
#define DM0_WS2812_H

//亮度
void ws2812_SetBrightness(uint8_t brightness);
//颜色
void ws2812_SetColor(uint16_t g, uint16_t r, uint16_t b);
//PWM
void ws2812_Update(void);

#endif //DM0_WS2812_H