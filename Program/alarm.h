// alarm.h
#ifndef ALARM_H
#define ALARM_H

#include "setting.h"    // Provides NVS settings management functions
#include "tempSensor.h" // Provides temperature sensor reading utilities

// ================================
// Pin Definitions
// Defines GPIO pins for monitoring door and pressure states
// ================================
#define DOOR_PIN 1     // GPIO pin for door status sensor
#define PRESSURE_PIN 2 // GPIO pin for pressure sensor

// ================================
// Global Alarm State Variables
// Tracks current alarm conditions
// ================================
extern bool doorClosed;   // True if door is closed, false if open
extern bool tempAlarm;    // True if temperature exceeds defined threshold
extern bool filterAlarm;  // True if filter warning is active
extern bool pressureHigh; // True if pressure exceeds defined threshold

// ================================
// Function Prototypes
// Declares functions for alarm initialization and status checks
// ================================
void alarmSetup();      // Initializes alarm pins and settings
bool isDoorClosed();    // Returns true if door is closed
bool isPressureHigh();  // Returns true if pressure is above threshold
bool isFilterWarning(); // Returns true if filter warning is active
bool isHighTempAlarm(); // Returns true if temperature exceeds threshold

#endif // ALARM_H