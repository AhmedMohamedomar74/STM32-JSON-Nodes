/*
 * Timer.h
 *
 *  Created on: Dec 13, 2024
 *      Author: ahmed
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>
#include <stdio.h>

#define MAX_TIMERS 10  // Adjust based on your requirements

typedef void (*CallbackFunction)(void); // Function pointer type for callback

// Timer structure
typedef struct {
    CallbackFunction callback;
    uint32_t delay;
    uint32_t startTime;
    uint8_t active;
    uint8_t repeat;
} Timer;

// Global system time variable (should be incremented by SysTick or similar)
extern volatile uint32_t systemTime;

// Function declarations
void Timer_Init(void);
void Timer_Check(void);
void Timer_StartOnce(CallbackFunction callback, uint32_t delayMs);
void Timer_StartRepeat(CallbackFunction callback, uint32_t delayMs);
void Timer_Stop(CallbackFunction callback);

#endif /* TIMER_H_ */
