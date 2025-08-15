# LVGL Display Optimization Guide

## Overview

This guide addresses display smoothness issues in modular LVGL code by optimizing three critical areas: UI update logic, display buffer settings, and LVGL configuration.

## 1. UI Update Logic Optimization (Most Critical)

### Problem

Heavy UI update functions (`updateMainScreenUI` and `updateStatusScreenUI`) are called in every iteration of `displayLoop`, causing irregular delays (jitter) in rendering.

### Solution

Move heavy UI logic from the main render loop to LVGL's own timer system.

### Implementation Steps

#### A. Modify uiLogic.cpp

1. **Remove internal millis() checks**: Remove all time-conditional statements `if (currentTime - last...Time < ..._INTERVAL)` from these functions:

   - `updateArcMainScreen`
   - `checkDeviceStatus`, `checkHighTempAlarmStatus`, `checkPressureAlarmStatus`, `checkDoorStatus`, `checkRelayStatus`
   - `updateTemperatureLabels`, `updateAlarmLabels`, `updateRelayLabels`, `updateMaintenanceLabels`, `updateInfoLabels`

2. **Add timer setup function** at the end of `uiLogic.cpp`:

```cpp
void setupUiTimers() {
    // Timer for main screen arcs and icons (every 5 seconds)
    lv_timer_create(updateMainScreenUI, 5000, NULL);

    // Timer for status screen labels (every 10 seconds)
    lv_timer_create(updateStatusScreenUI, 10000, NULL);
}
```

#### B. Update uiLogic.h

Add function declaration:

```c
void setupUiTimers();
```

#### C. Modify display.cpp

1. **Remove these calls from displayLoop**:

```cpp
// DELETE these lines
updateMainScreenUI();
updateStatusScreenUI();
```

2. **Simplified displayLoop should be**:

```cpp
void displayLoop() {
    uint32_t currentTime = millis();
    lv_timer_handler(); // Process LVGL tasks

    // Touch timeout check (keep this part)
    if (millis() - getLastTouchTime() > getTimeoutDuration() &&
        lv_scr_act() != ui_mainScreen && !isAnyContainerVisible()) {
        switchToMainScreen();
    }
    delay(5);
}
```

#### D. Update Program.ino.cpp

Add timer initialization in `setup()` after `displaySetup()`:

```cpp
#include "uiLogic.h" // Add if not already included

// In setup() function after displaySetup()
displaySetup();
Serial.printf("[System][INFO][%lu] Display initialized\n", currentTime);

// Initialize UI timers
setupUiTimers();
Serial.printf("[System][INFO][%lu] UI timers initialized\n", currentTime);
```

## 2. Display Buffer Optimization

### Problem

Large buffers don't always mean better performance. Smaller buffers can flush faster to the display.

### Solution

#### A. Modify display.h

Reduce buffer size:

```c
#define SIZE_SCREEN_BUFFER (screenWidth * screenHeight / 8) // or /10
```

## 3. LVGL Configuration Optimization

### Modify lv_conf.h

#### A. Refresh Rate

Set a stable refresh rate:

```c
#define LV_DISP_DEF_REFR_PERIOD 16 // or 20 or 30
```

#### B. Performance Monitoring (for testing)

Enable temporary monitoring to see improvement:

```c
#define LV_USE_PERF_MONITOR 1
#define LV_USE_MEM_MONITOR 1
```

(Disable after optimization is complete)

## Root Cause Analysis

### 1. Timing Mechanism (Most Critical Issue)

- **Sample Code (Smooth)**: Uses hardware timer (`esp_timer`) with high precision, creating interrupts every 2ms for `lv_tick_inc()`. This ensures LVGL's "heartbeat" is extremely precise and stable.
- **Your Code (Prone to Jitter)**: Uses `LV_TICK_CUSTOM = 1` with `millis()`. If the main loop is blocked even briefly by other tasks, LVGL timing gets disrupted, causing display tearing.

### 2. UI Update Logic

- **Sample Code**: Only runs `lv_demo_widgets()` with lightweight loop calling only `lv_timer_handler()`
- **Your Code**: Calls heavy functions in `displayLoop` that read sensors, format strings, and update many UI elements, causing irregular delays

### 3. Buffer Configuration

- **Buffer Size**: Your large buffer (/ 2) vs sample's smaller buffer (/ 4) - sometimes smaller is smoother
- **Memory Type**: Your `MALLOC_CAP_SPIRAM` vs sample's `MALLOC_CAP_DMA` - DMA ensures fastest display driver data transfer

## I2C Optimization Note

Due to I2C instability in this model, use optimized frequency and integrated pin setup for I2C devices (relays and display) to ensure stable communication.

## Expected Results

After implementing these optimizations:

- Significantly reduced processing load on main render loop
- Stable, jitter-free display updates
- Better overall system responsiveness
- Smoother animations and transitions
