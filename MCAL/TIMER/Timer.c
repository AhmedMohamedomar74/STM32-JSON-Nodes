/*
 * Timer.c
 *
 *  Created on: Dec 13, 2024
 *      Author: ahmed
 */


#include "timer.h"

// Array of timers
static Timer timers[MAX_TIMERS];

// Global system time variable
volatile uint32_t systemTime = 0; // Increment this in SysTick handler or equivalent

// Initialize all timers
void Timer_Init(void)
{
    for (int i = 0; i < MAX_TIMERS; i++) {
        timers[i].active = 0;
        timers[i].callback = NULL;
        timers[i].repeat = 0;
    }
}

// Start a one-shot timer
void Timer_StartOnce(CallbackFunction callback, uint32_t delayMs)
{
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (!timers[i].active) {
            timers[i].callback = callback;
            timers[i].delay = delayMs;
            timers[i].startTime = systemTime;
            timers[i].active = 1;
            timers[i].repeat = 0; // One-shot
            break;
        }
    }
}

// Start a repeating timer
void Timer_StartRepeat(CallbackFunction callback, uint32_t delayMs)
{
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (!timers[i].active) {
            timers[i].callback = callback;
            timers[i].delay = delayMs;
            timers[i].startTime = systemTime;
            timers[i].active = 1;
            timers[i].repeat = 1; // Repeating
            break;
        }
    }
}

// Stop a specific timer
void Timer_Stop(CallbackFunction callback)
{
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (timers[i].active && timers[i].callback == callback) {
            timers[i].active = 0; // Deactivate the timer
            timers[i].callback = NULL;
            break;
        }
    }
}

// Check and execute timers
void Timer_Check(void)
{
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (timers[i].active && (systemTime - timers[i].startTime >= timers[i].delay)) {
            if (timers[i].callback) {
                timers[i].callback(); // Execute the callback
            }

            if (timers[i].repeat) {
                timers[i].startTime = systemTime; // Restart repeating timer
            } else {
                timers[i].active = 0; // Disable one-shot timer
            }
        }
    }
}
