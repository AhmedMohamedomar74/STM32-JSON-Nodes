/*
 * UART.c
 *
 *  Created on: Dec 13, 2024
 *      Author: ahmed
 */


#include "UART.h"

char buffer[BUFFER_SIZE];
char rxBuffer[RX_BUFFER_SIZE]; // Circular buffer for receiving data
volatile uint8_t rxIndex; // Current index in the RX buffer
volatile uint8_t dataReceived; // Flag indicating data reception


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        if (rxBuffer[rxIndex] == '\n' || rxBuffer[rxIndex] == '}' || rxBuffer[rxIndex] == '\0' || rxIndex >= RX_BUFFER_SIZE - 1)
        {
            // End of message
            rxBuffer[rxIndex + 1] = '\0'; // Null-terminate the string
            dataReceived = 1;
            rxIndex = 0; // Reset the buffer index
        }
        else
        {
            // Increment buffer index for next character
            rxIndex++;
        }

        // Continue receiving data
        HAL_UART_Receive_IT(&huart1, (uint8_t *)&rxBuffer[rxIndex], 1);
    }
}
