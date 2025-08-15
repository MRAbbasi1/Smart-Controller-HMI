// display.h
#ifndef DISPLAY_H
#define DISPLAY_H

// ================================
// Library Includes
// ================================
#include <Arduino.h>
#include <lvgl.h>
#include <Arduino_GFX_Library.h>
#include <TouchDrvGT911.hpp>
#include "ui.h"
#include "uiLogic.h"

// ================================
// Display Configuration
// Defines screen rotation and dimensions
// ================================
#define SCREEN_ROTATION 2                                   // Screen rotation (0, 1, 2, or 3)
constexpr uint16_t screenWidth = 480;                       // Screen width in pixels
constexpr uint16_t screenHeight = 480;                      // Screen height in pixels
#define SIZE_SCREEN_BUFFER (screenWidth * screenHeight / 4) // Screen buffer size for LVGL - 1/2,4,8

// ================================
// Function Prototypes
// ================================
void displaySetup(); // Initialize display and touch
void displayLoop();  // Main display loop for LVGL and UI updates

#endif // DISPLAY_H