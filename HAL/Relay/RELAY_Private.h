/*
 * RELAY_Private.h
 *
 *  Created on: Dec 11, 2024
 *      Author: ahmed
 */

#ifndef RELAY_PRIVATE_H_
#define RELAY_PRIVATE_H_

#include "stm32f1xx.h"

typedef enum
{
	RELAY_OK =  HAL_OK,
	RELAY_ERROR,
}RELAY_status;

#define RELAY_SET GPIO_PIN_SET
#define RELAY_RESET GPIO_PIN_RESET
#define RELAY_UNKNOW 2

#endif /* RELAY_PRIVATE_H_ */
