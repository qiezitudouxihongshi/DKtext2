#include "ws2812.h"

static const uint16_t data[25] = {    //改成const能把数组扔到flash让DMA读取
    30, 30, 30, 30, 30, 30, 30, 30,
    30, 30, 30, 30, 30, 30, 60, 30,
    30, 30, 30, 30, 30, 30, 60, 30,
    0
};

void ws2812_Update(void)
{
    HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_2,(uint32_t *)data,sizeof(data) / sizeof(data[0]));
}