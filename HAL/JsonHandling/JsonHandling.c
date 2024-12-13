/*
 * JsonHandling.c
 *
 *  Created on: Dec 10, 2024
 *      Author: ahmed
 */


#include "JsonHandling.h"
static void removeSpaces(char *str);

// Function to generate JSON object
cJSON* generateJSONObjectTemp(Node_t *node)
{
    // Create a JSON object
    cJSON *json = cJSON_CreateObject();

    if (json == NULL)
    {
        return NULL; // Return NULL if JSON object creation fails
    }

    // Buffer to hold string representations of NodeID and Data
    char nodeIDStr[12]; // Sufficient size for uint8_t and null terminator
    char dataStr[12];   // Sufficient size for uint8_t and null terminator

    // Convert NodeID and Data to strings
    sprintf(nodeIDStr, "0x%02X", node->NodeID);
    sprintf(dataStr, "%u^C", node->Data);

    if (node->NodeID == TempSensorID) {
    	sprintf(dataStr, "%u^C", node->Data);
	} else {
		sprintf(dataStr, "%u", node->Data);
	}

    // Add elements to the JSON object
    cJSON_AddStringToObject(json, "NodeType", (char *)node->NodeType);
    cJSON_AddStringToObject(json, "NodeID", nodeIDStr);
    cJSON_AddStringToObject(json, "Data", dataStr);

    return json; // Return the JSON object
}

void PrintJson(cJSON *jsonObject)
{
    if (jsonObject != NULL)
    {
        // Convert JSON object to string
        char *jsonString = cJSON_Print(jsonObject);
        if (jsonString != NULL)
        {
            // Reallocate memory for JSON string to add '\n'
            size_t length = strlen(jsonString);
            char *resizedJsonString = (char *)realloc(jsonString, length + 2); // +1 for '\n', +1 for '\0'
            if (resizedJsonString != NULL)
            {
                // Append newline and null terminator
                resizedJsonString[length] = '\r';   // Add newline character
                resizedJsonString[length + 1] = '\0'; // Null-terminate the string

                // Transmit the modified JSON string
                HAL_UART_Transmit(&huart1, (uint8_t *)resizedJsonString, strlen(resizedJsonString), HAL_MAX_DELAY);

                free(resizedJsonString); // Free the allocated memory
            }
            else
            {
                // Handle reallocation failure
                HAL_UART_Transmit(&huart1, (uint8_t *)"Failed to allocate memory\n", 26, HAL_MAX_DELAY);
                free(jsonString); // Free the original JSON string
            }
        }
        cJSON_Delete(jsonObject); // Free the JSON object
    }
    else
    {
        sprintf(buffer, "Failed to generate JSON\r\n");
        HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
    }
}



void parse_json_command(const char *json_string,Command_t * CommandPtr)
{
    removeSpaces(json_string);
    cJSON *json = cJSON_Parse(json_string);
    if (json == NULL) {
        sprintf(buffer, "Error parsing JSON string: %s\r", cJSON_GetErrorPtr());
        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
        return;
    }

    // Extract fields
    cJSON *command = cJSON_GetObjectItem(json, "command");
    cJSON *node_id = cJSON_GetObjectItem(json, "nodeID");
    cJSON *data = cJSON_GetObjectItem(json, "data");

    // Initialize the command_struct members
    memset(CommandPtr, 0, sizeof(CommandPtr));

    if (cJSON_IsString(command) && command->valuestring != NULL) {
    	CommandPtr->command = (uint8_t *)strdup(command->valuestring); // Duplicate string
    }
    if (cJSON_IsString(node_id) && node_id->valuestring != NULL) {
    	CommandPtr->nodeID = (uint8_t)strtol(node_id->valuestring, NULL, 16);
    }
    if (cJSON_IsString(data) && data->valuestring != NULL) {
    	CommandPtr->data = (uint8_t)atoi(data->valuestring); // Convert string to int
    }

//    // Send the values over UART
//    if (CommandPtr->command != NULL) {
//        sprintf(buffer, "Command: %s\r", CommandPtr->command);
//        HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
//    }
//
//    sprintf(buffer, "Node ID: 0x%X\r", CommandPtr->nodeID);
//    HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
//    sprintf(buffer, "Data: %u\r", CommandPtr->data);
//    HAL_UART_Transmit(&huart1, buffer, strlen(buffer), HAL_MAX_DELAY);
//
//    // Free allocated memory for the command string
//    if (CommandPtr->command != NULL) {
//        free(CommandPtr->command);
//    }

    // Free the JSON object
    cJSON_Delete(json);
}

static void removeSpaces(char *str) {
    uint8_t i, j = 0;
    uint8_t len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0'; // Null-terminate the modified string
}


