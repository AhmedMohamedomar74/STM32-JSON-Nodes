/*
 * RELAY.h
 *
 *  Created on: Dec 11, 2024
 *      Author: ahmed
 */

#ifndef RELAY_H_
#define RELAY_H_

#include "stm32f1xx.h"
#include "Node.h"
#include "RELAY_Private.h"

RELAY_status RELAY_voidInit(Node_t * Node_relay_prt);
RELAY_status RELAY_voidSetPin(Node_t * Node_relay_prt);
RELAY_status RELAY_voidDeInit(Node_t * Node_relay_prt);


#endif /* RELAY_H_ */
