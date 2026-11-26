#include "bsp_uart.h"

//发送数据
void uart_send(UART_HandleTypeDef *huart, uint8_t*s_data,uint16_t s_len)
{
    HAL_UART_Transmit(huart, (uint8_t *)s_data, s_len, 0xFFFF);
}

//接收数据
uint16_t uart_Receive(UART_HandleTypeDef *huart,uint8_t *r_buffer,uint16_t r_len)
{
    uint16_t rx_len = 0;
    HAL_UART_Receive(huart, &r_buffer[0], 1, 0XFFFF);

    while (r_buffer[rx_len] !='\n' && r_buffer[rx_len] != '\r' && rx_len < r_len-1)
    {
        rx_len++;
        HAL_UART_Receive(huart, &r_buffer[rx_len], 1, 0XFFFF);
    }
    r_buffer[rx_len] = '\0';
    return rx_len;
}

