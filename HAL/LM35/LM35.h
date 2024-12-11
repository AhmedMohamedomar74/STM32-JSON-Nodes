/*
 * LM35.h
 *
 *  Created on: Dec 6, 2024
 *      Author: ahmed
 */

#ifndef LM35_H_
#define LM35_H_

#include "stm32f1xx.h"
#include "LM35_Private.h"
#include "Node.h"
#include "LM35_Config.h"


#define VREF 5
#define REVERED_10mm 100

extern ADC_HandleTypeDef hadc1;


LM35_status LM35_voidInit(Node_t * Node_temp_prt);
LM35_status LM35_voidGetTemperature(Node_t * Node_temp_prt);
LM35_status LM35_voidDeInit(Node_t * Node_temp_prt);

#endif /* LM35_H_ */
