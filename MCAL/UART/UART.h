/*
 * UART.h
 *
 *  Created on: Dec 13, 2024
 *      Author: ahmed
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f1xx.h"

#define RX_BUFFER_SIZE 50
#define BUFFER_SIZE 50

extern UART_HandleTypeDef huart1;
extern char buffer[BUFFER_SIZE];
extern char rxBuffer[RX_BUFFER_SIZE]; // Circular buffer for receiving data
extern volatile uint8_t rxIndex; // Current index in the RX buffer
extern volatile uint8_t dataReceived; // Flag indicating data reception


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif /* UART_H_ */
