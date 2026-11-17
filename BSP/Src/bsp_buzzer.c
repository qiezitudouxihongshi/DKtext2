#include "bsp_buzzer.h"

// #define Do
// #define Re
// #define Mi
// #define Fa
// #define So
// #define La
// #define Xi

void buzzer_init(void)
{
    HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_2);
}
void buzzer_action(void)
{
    __HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,250);
    HAL_Delay(300);
    __HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,0);
    HAL_Delay(300);
    __HAL_TIM_SET_AUTORELOAD(&htim12,1000);
    __HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,500);
    HAL_Delay(300);
    __HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,0);

}