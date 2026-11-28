#ifndef DM0_BSP_UART_H
#define DM0_BSP_UART_H

#include "usart.h"

typedef struct
{
    UART_HandleTypeDef *huart;
    uint8_t tx_flag;           //发送完成标志位
    uint8_t rx_buffer[100];    //接收数据的缓冲区
    uint16_t rx_index;         //记录当前字节数
    uint8_t rx_flag;           //接收完成标志位 1-完成
}Uart_t;

extern Uart_t usart1;
extern Uart_t uart5;

void uart_init(UART_HandleTypeDef *huart,Uart_t *manage);
void uart_send(UART_HandleTypeDef *huart, uint8_t*s_data,uint16_t s_len);
uint8_t uart_is_tx_complete(UART_HandleTypeDef *huart);
uint8_t uart_getdata(UART_HandleTypeDef *huart,uint8_t *out_buffer,uint16_t *out_len);

#endif //DM0_BSP_UART_H