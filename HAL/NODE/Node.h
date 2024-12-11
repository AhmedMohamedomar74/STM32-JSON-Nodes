/*
 * Node.h
 *
 *  Created on: Dec 10, 2024
 *      Author: ahmed
 */

#ifndef NODE_H_
#define NODE_H_

#include "stdint.h"

typedef struct
{
	uint8_t * NodeType;
	uint8_t  NodeID;
	uint16_t  Data;
}Node_t;

typedef struct
{
	uint8_t * command;
	uint8_t  nodeID;
	uint8_t  data;
}Command_t;

#endif /* NODE_H_ */
