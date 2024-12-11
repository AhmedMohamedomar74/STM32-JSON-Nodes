/*
 * LDR.c
 *
 *  Created on: Dec 10, 2024
 *      Author: ahmed
 */

#include "LDR.h"

LDR_status LDR_voidinit(Node_t * Node_LDR)
{
	LDR_status ret = LDR_ERROR;
	if (Node_LDR != NULL) {
		Node_LDR->NodeType = "NS";
		Node_LDR->NodeID = 0x81;
		Node_LDR->Data = NULL;
		ret = LDR_OK;
	}
	return ret;
}

LDR_status LDR_voidDeInit(Node_t * Node_LDR)
{
	LDR_status ret = LDR_ERROR;
	if (Node_LDR != NULL) {
		Node_LDR->NodeType = NULL;
		Node_LDR->NodeID = 0x81;
		Node_LDR->Data = NULL;
		ret = LDR_OK;
	}
	return ret;
}

LDR_status LDR_voidGetLightingIntensity(Node_t * Node_LDR_prt)
{
	LDR_status ret = LDR_ERROR;
	if (Node_LDR_prt != NULL) {
		ADC_ChannelConfTypeDef sConfig = {0};
		sConfig.Channel = LDRDataPin;
		sConfig.Rank = ADC_REGULAR_RANK_1;
		sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
		HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	if (HAL_ADC_Start(&hadc1) == HAL_OK){
		ret = LDR_OK;
		uint32_t ADC_val = HAL_ADC_GetValue(&hadc1);
		Node_LDR_prt->Data= ADC_val;
		}
	}
	return ret;
}


