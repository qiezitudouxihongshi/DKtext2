#ifndef DM0_BSP_UART_C_H
#define DM0_BSP_UART_C_H

#include "usart.h"

void uart_send(UART_HandleTypeDef *huart, uint8_t*s_data,uint16_t s_len);
uint16_t uart_Receive(UART_HandleTypeDef *huart,uint8_t *r_buffer,uint16_t r_len);

#endif //DM0_BSP_UART_C_H
