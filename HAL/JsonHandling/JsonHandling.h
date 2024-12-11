/*
 * JsonHandling.h
 *
 *  Created on: Dec 10, 2024
 *      Author: ahmed
 */

#ifndef JSONHANDLING_H_
#define JSONHANDLING_H_

#include "JsonHandling_Config.h"
#include "cJSON.h"
#include "Node.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"
#include "string.h"

#define BUFFER_SIZE 50

extern char buffer[BUFFER_SIZE];
extern UART_HandleTypeDef huart1;

cJSON* generateJSONObjectTemp(Node_t *node);
void PrintJson(cJSON * jsonObject);
void parse_json_command(const char *json_string,Command_t * CommandPtr);

#endif /* JSONHANDLING_H_ */
