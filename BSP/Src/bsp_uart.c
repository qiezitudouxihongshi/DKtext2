#include "bsp_uart.h"

Uart_t usart1 __attribute__((section(".dma_buffer"), aligned(32)));
Uart_t uart5  __attribute__((section(".dma_buffer"), aligned(32)));

//反查函数
static Uart_t *uart_manage(UART_HandleTypeDef *huart)
{
    if (huart == NULL) return NULL;
    if (huart->Instance == USART1) return &usart1;
    if (huart->Instance == UART5)  return &uart5;
    return NULL;
}

//初始化函数
void uart_init(UART_HandleTypeDef *huart,Uart_t *manage)
{
    manage->huart    = huart;
    manage->rx_index = 0;
    manage->rx_flag  = 0;
    manage->tx_flag  = 0;
    HAL_UARTEx_ReceiveToIdle_DMA(huart, manage->rx_buffer, sizeof(manage->rx_buffer) - 1);  //开启第一次中断接收

}

//发送数据
void uart_send(UART_HandleTypeDef *huart, uint8_t *s_data,uint16_t s_len)//s_data需要全局变量
{
    Uart_t *manage = uart_manage(huart);
    if (manage != NULL)
    {
        HAL_UART_Transmit_IT(huart, s_data, s_len);
    }
}

//发送回调
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    Uart_t *manage = uart_manage(huart);
    if (manage != NULL)
    {
        manage->tx_flag = 1;
    }
}
//告诉主程序是否发送完成+重置
uint8_t uart_is_tx_complete(UART_HandleTypeDef *huart)
{
    Uart_t *manage = uart_manage(huart);
    if (manage != NULL && manage->tx_flag == 1)
    {
        manage->tx_flag = 0;
        return 1;       //1-成功发送数据  0-失败
    }
    return 0;
}

//接受回调
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart,uint16_t Size)
{
    Uart_t *manage = uart_manage(huart);
    if (manage != NULL)
    {

        manage->rx_index=Size;
        manage->rx_buffer[Size] = '\0';
        manage->rx_flag = 1;
    }
}

//复制数据+重置
uint8_t uart_getdata(UART_HandleTypeDef *huart,uint8_t *out_buffer,uint16_t *out_len)
{
    Uart_t *manage = uart_manage(huart);
    if (manage != NULL && manage->rx_flag == 1)
    {
        for (uint16_t i = 0; i <= manage->rx_index; i++)
        {
            out_buffer[i] = manage->rx_buffer[i];
        }
        *out_len = manage->rx_index;
        manage->rx_flag = 0;
        manage->rx_index = 0;
        HAL_UARTEx_ReceiveToIdle_DMA(huart, manage->rx_buffer, sizeof(manage->rx_buffer) - 1);
        return 1;       //1-成功取到数据  0-失败
    }
    return 0;
}
