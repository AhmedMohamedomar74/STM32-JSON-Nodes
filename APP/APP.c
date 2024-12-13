/*
 * APP.c
 *
 *  Created on: Dec 13, 2024
 *      Author: ahmed
 */

#include "APP.h"

Node_t NodeTemp;
Node_t NodeLDR;
Node_t NodeRELAY;
cJSON * cJSONOPtr;



static void SendDataTemp();
static void SendDataLdr();

void CommandHandling(Command_t *commandPtr)
{
	if (strcmp(commandPtr->command, "ENA") == 0) {
	    if (TempSensorID == commandPtr->nodeID) {
	    	LM35_voidInit(&NodeTemp);
	        cJSONOPtr = generateJSONObjectTemp(&NodeTemp);
	        PrintJson(cJSONOPtr);
	    } else if (LDRSensorID == commandPtr->nodeID) {
	        LDR_voidinit(&NodeLDR);
	        cJSONOPtr = generateJSONObjectTemp(&NodeLDR);
	        PrintJson(cJSONOPtr);
	    }
	    else if (RelayID == commandPtr->nodeID) {
			RELAY_voidInit(&NodeRELAY);
			cJSONOPtr = generateJSONObjectTemp(&NodeRELAY);
			PrintJson(cJSONOPtr);
		}
	}
	else if (strcmp(commandPtr->command, "DIS") == 0) {
	    if (TempSensorID == commandPtr->nodeID) {
	        LM35_voidDeInit(&NodeTemp);
	        Timer_Stop(SendDataTemp);
	    } else if (LDRSensorID == commandPtr->nodeID) {
	        LDR_voidDeInit(&NodeLDR);
	        Timer_Stop(SendDataLdr);
	    }
	    else if (RelayID == commandPtr->nodeID) {
			RELAY_voidDeInit(&NodeRELAY);
	    }
	}

	else if (strcmp(commandPtr->command, "ACT") == 0) {
		 NodeRELAY.Data = commandPtr->data;
		 RELAY_voidSetPin(&NodeRELAY);
		}
	else if (strcmp(commandPtr->command, "DUR") == 0) {
			if (TempSensorID == commandPtr->nodeID) {
				Timer_StartRepeat(SendDataTemp, (commandPtr->data * 1000));
				} else if (LDRSensorID == commandPtr->nodeID) {
				Timer_StartRepeat(SendDataLdr, (commandPtr->data * 1000));
				}
			}
	else if (strcmp(commandPtr->command, "STA") == 0) {
		if (TempSensorID == commandPtr->nodeID) {
			cJSONOPtr = generateJSONObjectTemp(&NodeTemp);
			PrintJson(cJSONOPtr);
				} else if (LDRSensorID == commandPtr->nodeID) {
					cJSONOPtr = generateJSONObjectTemp(&NodeLDR);
					PrintJson(cJSONOPtr);
				}
				else if (RelayID == commandPtr->nodeID) {
					cJSONOPtr = generateJSONObjectTemp(&NodeRELAY);
					PrintJson(cJSONOPtr);
				}
			}
}

static void SendDataTemp()
{
	LM35_voidGetTemperature(&NodeTemp);
	cJSONOPtr = generateJSONObjectTemp(&NodeTemp);
	PrintJson(cJSONOPtr);
}

static void SendDataLdr()
{
	LDR_voidGetLightingIntensity(&NodeLDR);
	cJSONOPtr = generateJSONObjectTemp(&NodeLDR);
	PrintJson(cJSONOPtr);
}

