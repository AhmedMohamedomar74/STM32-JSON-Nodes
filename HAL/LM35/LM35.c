/*
 * LM35.c
 *
 *  Created on: Dec 6, 2024
 *      Author: ahmed
 */
#include "LM35.h"
LM35_status LM35_voidGetTemperature(Node_t * Node_temp_prt)
{
	LM35_status ret = LM35_ERROR;
	if (Node_temp_prt != NULL) {
		ADC_ChannelConfTypeDef sConfig = {0};
		sConfig.Channel = LM35DataPin;
		sConfig.Rank = ADC_REGULAR_RANK_1;
		sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
		HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	if (HAL_ADC_Start(&hadc1) == HAL_OK){
		ret = LM35_OK;
		uint32_t ADC_val = HAL_ADC_GetValue(&hadc1);
		uint32_t temp_val = (ADC_val * VREF * REVERED_10mm) / 4059;
		Node_temp_prt->Data= temp_val;
		}
	}
	return ret;
}

LM35_status LM35_voidInit(Node_t * Node_temp_prt)
{
	LM35_status ret = LM35_ERROR;
	if (Node_temp_prt != NULL) {
		Node_temp_prt->NodeType = "NS";
		Node_temp_prt->NodeID = 0x80;
		Node_temp_prt->Data = NULL;
		ret = LM35_OK;
	}
	return ret;
}

LM35_status LM35_voidDeInit(Node_t * Node_temp_prt)
{
	LM35_status ret = LM35_ERROR;
	if (Node_temp_prt != NULL) {
		Node_temp_prt->NodeType = NULL;
		Node_temp_prt->NodeID = 0x80;
		Node_temp_prt->Data = NULL;
		ret = LM35_OK;
	}
	return ret;
}


