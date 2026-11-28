#ifndef DM0_BSP_UART_C_H
#define DM0_BSP_UART_C_H

#include "usart.h"

void uart_send(UART_HandleTypeDef *huart, uint8_t*s_data,uint16_t s_len);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
uint8_t uart_is_tx_complete();
void uart_receive(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
uint8_t uart_getdata(uint8_t *out_buffer,uint16_t *out_len);

#endif //DM0_BSP_UART_C_H