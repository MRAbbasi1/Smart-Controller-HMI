// display.h

#ifndef DISPLAY_H
#define DISPLAY_H

// ======================= Include Dependencies =======================
#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <esp_heap_caps.h>
#include "ui.h"
#include "uiLogic.h"

// ======================= Display Configuration =======================

// Screen rotation (0, 1, 2, 3)
#define SCREEN_ROTATION 1

// Screen width and height based on rotation
#if (SCREEN_ROTATION == 1) || (SCREEN_ROTATION == 3)
constexpr uint16_t screenWidth = 320;
constexpr uint16_t screenHeight = 240;
#else
constexpr uint16_t screenWidth = 240;
constexpr uint16_t screenHeight = 320;
#endif

// Display buffer size (optimized for performance)
#define SIZE_SCREEN_BUFFER (screenWidth * screenHeight / 2)

// ======================= Function Declarations =======================

/**
 * @brief Initializes the display, touch, and UI components.
 */
void displaySetup();

/**
 * @brief Handles display-related tasks in the main loop.
 */
void displayLoop();

#endif // DISPLAY_H