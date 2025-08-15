// uiLogic.h

#ifndef UI_LOGIC_H
#define UI_LOGIC_H

// ======================= Include Dependencies =======================
#include <Arduino.h>
#include <lvgl.h>
#include "tempSensor.h"
#include "setting.h"
#include "alarm.h"
#include "relayControl.h"
#include "ui.h"

// ======================= Function Declarations =======================

/**
 * @brief Updates UI elements on the main screen (e.g., arcs, icons).
 */
void updateMainScreenUI();

/**
 * @brief Updates UI elements on the status screen (e.g., temperature, alarm, relay, maintenance, info labels).
 */
void updateStatusScreenUI();

/**
 * @brief Switches to the main screen and resets UI elements.
 */
void switchToMainScreen();

/**
 * @brief Checks if any important UI container is visible.
 * @return True if any container is visible, false otherwise.
 */
bool isAnyContainerVisible();

/**
 * @brief Gets the last touch time for timeout management.
 * @return Last touch time in milliseconds.
 */
uint32_t getLastTouchTime();

/**
 * @brief Gets the touch timeout duration.
 * @return Timeout duration in milliseconds.
 */
uint32_t getTimeoutDuration();

/**
 * @brief Updates the last touch time.
 * @param time Current time in milliseconds.
 */
void updateLastTouchTime(uint32_t time);

#endif // UI_LOGIC_H