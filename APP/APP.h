/*
 * APP.h
 *
 *  Created on: Dec 13, 2024
 *      Author: ahmed
 */

#ifndef APP_H_
#define APP_H_

#include "LM35.h"
#include "LDR.h"
#include "JsonHandling.h"
#include "Timer.h"
#include "UART.h"

extern Node_t NodeTemp;
extern Node_t NodeLDR;
extern Node_t NodeRELAY;
extern cJSON * cJSONOPtr;
extern UART_HandleTypeDef huart1;

void CommandHandling(Command_t *commandPtr);

#endif /* APP_H_ */
