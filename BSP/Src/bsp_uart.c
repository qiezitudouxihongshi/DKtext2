#include "bsp_uart.h"

uint8_t tx_flag = 0;
uint8_t rx_byte;         //暂存接收到的单个字节
uint8_t rx_buffer[100];  //接收数据的缓冲区
uint16_t rx_index = 0;    //记录当前字节数
uint8_t rx_flag = 0;     //接收完成标志位 1-完成

//发送数据
void uart_send(UART_HandleTypeDef *huart, uint8_t *s_data,uint16_t s_len)//s_data需要全局变量
{
    HAL_UART_Transmit_IT(huart, s_data, s_len);
}

//接受回调
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        tx_flag = 1;
    }
}
//告诉主程序是否发送完成+重置
uint8_t uart_is_tx_complete()
{
    if (rx_flag == 1)
    {
        tx_flag = 0;
        return 1;       //1-成功发送数据  0-失败
    }
    return 0;
}


//接收函数
void uart_receive(UART_HandleTypeDef *huart)
{
    HAL_UART_Receive_IT(huart, &rx_byte, 1);  //开启中断接收
}

//中断回调
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        if (rx_index < 99)
        {
            rx_buffer[rx_index] = rx_byte;   //把收到的字节存到缓冲区里
            rx_index++;
        }
        if (rx_byte == '\n')
        {
            rx_flag = 1;
            rx_buffer[rx_index] = '\0';
        }
        HAL_UART_Receive_IT(huart, &rx_byte, 1);
    }
}

//复制数据+重置
uint8_t uart_getdata(uint8_t *out_buffer,uint16_t *out_len)
{
    if (rx_flag == 1)
    {
        for (uint16_t i = 0; i <= rx_index; i++)
        {
            out_buffer[i] = rx_buffer[i];
        }
        *out_len = rx_index;
        rx_flag = 0;
        rx_index = 0;
        return 1;       //1-成功取到数据  0-失败
    }
    return 0;
}
