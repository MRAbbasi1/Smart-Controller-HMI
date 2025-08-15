// alarm.cpp
// ===============================================
// Includes and Global Variables
// ===============================================
#include "alarm.h"
#include "setting.h"    // Provides NVS settings management functions
#include "tempSensor.h" // Provides temperature sensor reading utilities

// Global variables to track alarm states
bool doorClosed = false;   // Tracks door status (true = closed, false = open)
bool tempAlarm = false;    // Tracks high temperature alarm status
bool filterAlarm = false;  // Tracks filter warning status
bool pressureHigh = false; // Tracks high pressure alarm status

// ===============================================
// Initialization Function
// Configures alarm-related pins and initializes settings
// ===============================================
void alarmSetup()
{
    uint32_t currentTime = millis();
    // Configure door and pressure pins with pulldown resistors
    pinMode(DOOR_PIN, INPUT_PULLDOWN);
    pinMode(PRESSURE_PIN, INPUT_PULLDOWN);
    // Initialize NVS settings
    initializeSettings();
    Serial.printf("[Alarm][INFO][%lu] Alarm system initialized\n", currentTime);
}

// ===============================================
// Door Monitoring
// Checks door status based on settings and pin state
// ===============================================
bool isDoorClosed()
{
    uint32_t currentTime = millis();
    // Check if door warning setting has changed
    bool doorSettingTemp = getChangedFlagTemp("boolean", DOOR_WARNING_ON);
    static bool doorWarning = false; // Cached door warning enable state

    if (doorSettingTemp)
    {
        doorWarning = getBooleanSetting(DOOR_WARNING_ON);
        resetChangedFlagTemp("boolean", DOOR_WARNING_ON);
        Serial.printf("[Alarm][INFO][%lu] Door warning setting updated: %s\n", currentTime, doorWarning ? "Enabled" : "Disabled");
    }

    // If door warning is disabled, assume door is closed
    if (!doorWarning)
    {
        doorClosed = true;
        Serial.printf("[Alarm][INFO][%lu] Door is closed (warning disabled)\n", currentTime);
    }
    else
    {
        // Read door pin state (HIGH = closed, LOW = open)
        doorClosed = (digitalRead(DOOR_PIN) == HIGH);
        Serial.printf("[Alarm][INFO][%lu] Door status: %s\n", currentTime, doorClosed ? "Closed" : "Open");
    }

    return doorClosed;
}

// ===============================================
// Filter Monitoring
// Checks filter temperature against threshold to detect warnings
// ===============================================
bool isFilterWarning()
{
    uint32_t currentTime = millis();
    static bool filterWarning = false;         // Cached filter warning enable state
    static bool filterAlarm = false;           // Cached filter alarm state
    static int32_t filterWarningThreshold = 0; // Cached filter temperature threshold
    // Check if filter warning setting has changed
    bool filterSettingTemp = getChangedFlagTemp("boolean", FILTER_WARNING_ON);

    if (filterSettingTemp)
    {
        filterWarning = getBooleanSetting(FILTER_WARNING_ON);
        filterWarningThreshold = getNumericSetting(FILTER_WARNING);
        resetChangedFlagTemp("boolean", FILTER_WARNING_ON);
        Serial.printf("[Alarm][INFO][%lu] Filter warning setting updated: %s, threshold: %d°C\n", currentTime, filterWarning ? "Enabled" : "Disabled", filterWarningThreshold);
    }

    // If filter warning is disabled, clear alarm
    if (!filterWarning)
    {
        if (filterAlarm)
        {
            filterAlarm = false;
            Serial.printf("[Alarm][INFO][%lu] Filter is normal (warning disabled)\n", currentTime);
        }
    }
    else
    {
        // Read filter sensor temperature
        float temperature = readTemperatureByName("Filter");

        // Trigger alarm if temperature is invalid (NaN) or exceeds threshold
        filterAlarm = (isnan(temperature) || temperature > filterWarningThreshold);

        // Log warning for invalid readings or threshold comparison
        if (isnan(temperature))
        {
            Serial.printf("[Alarm][ERROR][%lu] Invalid filter temperature reading (NaN)\n", currentTime);
        }
        else
        {
            Serial.printf("[Alarm][INFO][%lu] Filter temperature: %.2f°C %s threshold of %d°C\n",
                          currentTime, temperature, filterAlarm ? "exceeds" : "is below", filterWarningThreshold);
        }
    }

    return filterAlarm;
}

// ===============================================
// Pressure Monitoring
// Checks pressure status based on settings and pin state
// ===============================================
bool isPressureHigh()
{
    uint32_t currentTime = millis();
    // Check if pressure warning setting has changed
    bool pressureSettingTemp = getChangedFlagTemp("boolean", PRESSURE_WARNING_ON);
    static bool pressureWarning = false; // Cached pressure warning enable state

    if (pressureSettingTemp)
    {
        pressureWarning = getBooleanSetting(PRESSURE_WARNING_ON);
        resetChangedFlagTemp("boolean", PRESSURE_WARNING_ON);
        Serial.printf("[Alarm][INFO][%lu] Pressure warning setting updated: %s\n", currentTime, pressureWarning ? "Enabled" : "Disabled");
    }

    // If pressure warning is disabled, assume pressure is normal
    if (!pressureWarning)
    {
        pressureHigh = false;
        Serial.printf("[Alarm][INFO][%lu] Pressure is normal (warning disabled)\n", currentTime);
    }
    else
    {
        // Read pressure pin state (HIGH = high pressure, LOW = normal)
        pressureHigh = (digitalRead(PRESSURE_PIN) == HIGH);
        Serial.printf("[Alarm][INFO][%lu] Pressure status: %s\n", currentTime, pressureHigh ? "High" : "Normal");
    }

    return pressureHigh;
}

// ===============================================
// Temperature Monitoring
// Checks inlet temperature against threshold to detect high temperature alarms
// ===============================================
bool isHighTempAlarm()
{
    uint32_t currentTime = millis();
    static bool tempWarning = false;             // Cached temperature warning enable state
    static bool tempAlarm = false;               // Cached temperature alarm state
    static int32_t highTempWarningThreshold = 0; // Cached high temperature threshold
    // Check if temperature warning setting has changed
    bool tempSettingTemp = getChangedFlagTemp("boolean", TEMP_WARNING_ON);

    if (tempSettingTemp)
    {
        tempWarning = getBooleanSetting(TEMP_WARNING_ON);
        highTempWarningThreshold = getNumericSetting(HIGH_TEMP_WARNING);
        resetChangedFlagTemp("boolean", TEMP_WARNING_ON);
        Serial.printf("[Alarm][INFO][%lu] Temperature warning setting updated: %s, threshold: %d°C\n", currentTime, tempWarning ? "Enabled" : "Disabled", highTempWarningThreshold);
    }

    // If temperature warning is disabled, clear alarm
    if (!tempWarning)
    {
        if (tempAlarm)
        {
            tempAlarm = false;
            Serial.printf("[Alarm][INFO][%lu] Temperature is normal (warning disabled)\n", currentTime);
        }
    }
    else
    {
        // Read inlet sensor temperature
        float temperature = readTemperatureByName("Inlet");

        // Trigger alarm if temperature is invalid (NaN) or exceeds threshold
        tempAlarm = (isnan(temperature) || temperature > highTempWarningThreshold);

        // Log warning for invalid readings or threshold comparison
        if (isnan(temperature))
        {
            Serial.printf("[Alarm][ERROR][%lu] Invalid inlet temperature reading (NaN)\n", currentTime);
        }
        else
        {
            Serial.printf("[Alarm][INFO][%lu] Inlet temperature: %.2f°C %s threshold of %d°C\n",
                          currentTime, temperature, tempAlarm ? "exceeds" : "is below", highTempWarningThreshold);
        }
    }

    return tempAlarm;
}