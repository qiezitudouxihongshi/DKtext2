#include "bsp_buzzer.h"

#define buzzer_TIM &htim12
#define buzzer_channel TIM_CHANNEL_2

//蜂鸣器初始化
void buzzer_init(void)
{
    HAL_TIM_PWM_Start(buzzer_TIM,buzzer_channel);
    __HAL_TIM_SET_COMPARE(buzzer_TIM,buzzer_channel,0);
}

//设置频率转化为周期
void buzzer_Set_freq(uint16_t freq)
{
    if(freq==0)
    {
        __HAL_TIM_SET_COMPARE(buzzer_TIM,buzzer_channel,0);
    }
    uint32_t period = 1000000/freq;    //周期
    __HAL_TIM_SET_AUTORELOAD(buzzer_TIM,period);
    __HAL_TIM_SET_COMPARE(buzzer_TIM,buzzer_channel,period/2);
}

//关闭蜂鸣器
void buzzer_off(void)
{
    __HAL_TIM_SET_COMPARE(buzzer_TIM,buzzer_channel,0);
}

//小星星
void Little_Star(void)
{
    buzzer_Set_freq(Do);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Do);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(So);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(So);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(La);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(La);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(So);
    HAL_Delay(500);
    buzzer_Set_freq(0);
    HAL_Delay(500);

    buzzer_Set_freq(Fa);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Fa);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Mi);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Mi);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Re);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Re);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Do);
    HAL_Delay(500);
    buzzer_Set_freq(0);
    HAL_Delay(500);

    buzzer_Set_freq(So);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(So);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Fa);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Fa);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Mi);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Mi);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Re);
    HAL_Delay(500);
    buzzer_Set_freq(0);
    HAL_Delay(500);

    buzzer_Set_freq(So);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(So);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Fa);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Fa);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Mi);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Mi);
    HAL_Delay(250);
    buzzer_Set_freq(0);
    HAL_Delay(250);
    buzzer_Set_freq(Re);
    HAL_Delay(500);
    buzzer_Set_freq(0);
    HAL_Delay(500);
}