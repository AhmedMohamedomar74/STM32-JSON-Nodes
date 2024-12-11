/*
 * LDR.h
 *
 *  Created on: Dec 10, 2024
 *      Author: ahmed
 */

#ifndef LDR_H_
#define LDR_H_

#include "stm32f1xx.h"
#include "LDR_Private.h"
#include "stm32f1xx_hal.h"
#include "LDR_Config.h"
#include "Node.h"

#define BUFFER_SIZE 50
extern char buffer[BUFFER_SIZE];
extern UART_HandleTypeDef huart1;
extern ADC_HandleTypeDef hadc1;



LDR_status LDR_voidinit(Node_t * Node_LDR);
LDR_status LDR_voidGetLightingIntensity(Node_t * Node_LDR_prt);
LDR_status LDR_voidDeInit(Node_t * Node_LDR);


#endif /* LDR_H_ */
