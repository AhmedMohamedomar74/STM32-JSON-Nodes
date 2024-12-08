/*
 * HelperFunctions.c
 *
 *  Created on: Dec 8, 2024
 *      Author: ahmed
 */

#include "HelperFunctions.h"
//void Test_JSON(void) {
//    // Create a JSON object
//    cJSON *root = cJSON_CreateObject();
//    cJSON_AddStringToObject(root, "device", "STM32");
//    cJSON_AddNumberToObject(root, "temperature", 200);
//
//    // Convert to string and print
//    char *json_str = cJSON_Print(root);
//    sprintf(buffer,"Generated JSON: %s\r", json_str);
//    HAL_UART_Transmit(&huart1, json_str, strlen(json_str), HAL_MAX_DELAY);
//    // Cleanup
//    cJSON_Delete(root);
//    free(json_str);
//}
/* UART RX Complete Callback Function */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        if (rxBuffer[rxIndex] == '\n' || rxBuffer[rxIndex] == '}' || rxBuffer[rxIndex] == '\0' || rxIndex >= RX_BUFFER_SIZE - 1)
        {
            // End of message
            rxBuffer[rxIndex + 1] = '\0'; // Null-terminate the string
            dataReceived = 1;
            rxIndex = 0; // Reset the buffer index
        }
        else
        {
            // Increment buffer index for next character
            rxIndex++;
        }

        // Continue receiving data
        HAL_UART_Receive_IT(&huart1, (uint8_t *)&rxBuffer[rxIndex], 1);
    }
}

/* Process Received Data */
//void processReceivedData(void)
//{
//    // Transmit the received data back
//	// parse_json_command(rxBuffer);
//	strcpy(txBuffer, rxBuffer);
//    // txBuffer[strlen(txBuffer)] = '\0';
//    HAL_UART_Transmit(&huart1, (uint8_t *)txBuffer, strlen(txBuffer), HAL_MAX_DELAY);
//    // parse_json_command(txBuffer);
//}

void parse_json_command(const char *json_string) {
    // Parse the JSON string
    cJSON *json = cJSON_Parse(json_string);
    if (json == NULL) {
    	sprintf(buffer, "Error parsing JSON string: %s\r", cJSON_GetErrorPtr());
    	HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
        return;
    }

    // Extract fields
    cJSON *command = cJSON_GetObjectItem(json, "command");
    cJSON *node_type = cJSON_GetObjectItem(json, "nodeType");
    cJSON *node_id = cJSON_GetObjectItem(json, "nodeID");
    cJSON *data = cJSON_GetObjectItem(json, "data");

    // Determine if it's a "command" or "nodeType" based JSON
    if (cJSON_IsString(command)) {
        sprintf(buffer, "Command: %s\r", command->valuestring);
        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
    } else if (cJSON_IsString(node_type)) {
        sprintf(buffer, "Node Type: %s\r", node_type->valuestring);
        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
    } else {
        sprintf(buffer, "Command/Node Type: Not Found or Invalid\r");
        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
    }

    // Handle nodeID
//    if (node_id != NULL) {
//        sprintf(buffer, "Debug: nodeID type=%d\r", node_id->type);
//        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
//    }

    if (cJSON_IsNumber(node_id)) {
        sprintf(buffer, "Node ID: 0x%s\r", (unsigned int)node_id->valuestring);
        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
    } else if (cJSON_IsString(node_id)) {
        int node_id_value = atoi(node_id->valuestring);
        sprintf(buffer, "Node ID (converted): %d\r", node_id_value);
        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
    } else {
        sprintf(buffer, "Node ID: Not Found or Invalid\r");
        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
    }

    // Handle data
    if (cJSON_IsString(data)) {
        sprintf(buffer, "Data: %s\r", data->valuestring);
        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
    } else if (cJSON_IsNull(data)) {
        sprintf(buffer, "Data: NULL\r");
        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
    } else {
        sprintf(buffer, "Data: Not Found or Invalid\r");
        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
    }

    // Free the JSON object
    cJSON_Delete(json);
}

void removeSpaces(char *str) {
    uint8_t i, j = 0;
    uint8_t len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0'; // Null-terminate the modified string
}
