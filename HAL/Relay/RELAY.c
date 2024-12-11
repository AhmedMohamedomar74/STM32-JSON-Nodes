/*
 * RELAY.c
 *
 *  Created on: Dec 11, 2024
 *      Author: ahmed
 */

#include "RELAY.h"


RELAY_status RELAY_voidInit(Node_t * Node_relay_prt)
{
	RELAY_status ret = RELAY_ERROR;
		if (Node_relay_prt != NULL) {
			Node_relay_prt->NodeType = "NA";
			Node_relay_prt->NodeID = 0x50;
			Node_relay_prt->Data = NULL;
			ret = RELAY_OK;
		}
		return ret;
}

RELAY_status RELAY_voidSetPin(Node_t * Node_relay_prt)
{
	RELAY_status ret = RELAY_ERROR;
			if (Node_relay_prt != NULL) {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, Node_relay_prt->Data);
				ret = RELAY_OK;
			}
			return ret;
}

RELAY_status RELAY_voidDeInit(Node_t * Node_relay_prt)
{
	RELAY_status ret = RELAY_ERROR;
		if (Node_relay_prt != NULL) {
			Node_relay_prt->NodeType = NULL;
			Node_relay_prt->NodeID = 0x50;
			Node_relay_prt->Data = NULL;
			ret = RELAY_OK;
		}
		return ret;
}
