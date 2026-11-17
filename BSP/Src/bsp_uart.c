#include "bsp_uart.h"

int _write(int file, char *ptr, int len)    //重定向
{
    HAL_UART_Transmit(&huart1, (uint8_t *)ptr, len, HAL_MAX_DELAY);
    return len;
}