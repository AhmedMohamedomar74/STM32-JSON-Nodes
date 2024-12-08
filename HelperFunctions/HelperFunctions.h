/*
 * HelperFunctions.h
 *
 *  Created on: Dec 8, 2024
 *      Author: ahmed
 */

#ifndef HELPERFUNCTIONS_H_
#define HELPERFUNCTIONS_H_

#include "stm32f1xx.h"
#include "cJSON.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

extern uint8_t buffer[50];
extern UART_HandleTypeDef huart1;
#define RX_BUFFER_SIZE 50
extern char rxBuffer[RX_BUFFER_SIZE]; // Circular buffer for receiving data
extern volatile uint8_t rxIndex; // Current index in the RX buffer
extern volatile uint8_t dataReceived; // Flag indicating data reception

void Test_JSON(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void processReceivedData(void);
void parse_json_command(const char *json_string);
void removeSpaces(char *str);

#endif /* HELPERFUNCTIONS_H_ */
