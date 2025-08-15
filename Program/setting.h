// setting.h
#ifndef SETTING_H
#define SETTING_H

#include <nvs_flash.h>
#include <nvs.h>
#include <Arduino.h>
#include <stdint.h> // int32_t & size_t

#ifdef __cplusplus
extern "C"
{
#endif

// ================================
// Constants and Definitions
// Defines counts and maximum length for settings stored in NVS
// - Numeric settings: 13 (e.g., temperature thresholds, device IDs)
// - Boolean settings: 10 (e.g., feature toggles)
// - String settings: 10 (e.g., Wi-Fi credentials, sensor addresses)
// - Maximum string length: 64 characters
// ================================
#define NUMERIC_SETTING_COUNT 13
#define BOOLEAN_SETTING_COUNT 10
#define STRING_SETTING_COUNT 10
#define STRING_MAX_LENGTH 64

    // ================================
    // Use Enumerations instead of indices for access to arrays
    // Defines indices for numeric, boolean, and string settings
    // - NumericIndex: For thresholds and counters (e.g., COMPRESSOR_TEMP, HOURS_ELAPSED)
    // - BooleanIndex: For toggles (e.g., DEVICE_ON, CLOUD_ON)
    // - StringIndex: For text-based settings (e.g., WIFI_SSID, SERVER_IP)
    // ================================
    typedef enum
    {
        COMPRESSOR_TEMP,
        COMPRESSOR_RANGE,
        HIGH_TEMP_WARNING,
        ANTI_FREEZE_TEMP,
        ANTI_FREEZE_RANGE,
        COMPRESSOR_REST_TIME,
        FILTER_WARNING,
        FAN2_TEMP,
        DEVICE_SERIAL_ID,
        CUSTOMER_ID,
        ACTIVATION_DATE,
        SERVICE_INTERVAL,
        HOURS_ELAPSED
    } NumericIndex;

    typedef enum
    {
        DEVICE_ON,
        PRESSURE_WARNING_ON,
        TEMP_WARNING_ON,
        FILTER_WARNING_ON,
        DOOR_WARNING_ON,
        FAN2_ON,
        ADVANCED_SETTINGS_ON,
        CLOUD_ON,
        SERIAL_LOG_ON,
        CLOUD_LOG_ON
    } BooleanIndex;

    typedef enum
    {
        WIFI_SSID,
        WIFI_PASSWORD,
        AP_NAME,
        AP_PASSWORD,
        SERVER_URL,
        SERVER_IP,
        INLET_SENSOR_ADDRESS,
        OUTLET_SENSOR_ADDRESS,
        ANTIFREEZE_SENSOR_ADDRESS,
        FILTER_SENSOR_ADDRESS
    } StringIndex;

    // ================================
    // Default Values
    // Declares default values for numeric, boolean, and string settings
    // - Used when settings are missing in NVS during initialization
    // ================================
    extern const int32_t defaultNumericValues[NUMERIC_SETTING_COUNT];
    extern const bool defaultBooleanValues[BOOLEAN_SETTING_COUNT];
    extern const char *defaultStringValues[STRING_SETTING_COUNT];

    // ================================
    // Validation Ranges
    // Defines minimum and maximum values for numeric settings and maximum lengths for strings
    // - Ensures settings stay within valid ranges (e.g., COMPRESSOR_TEMP: 20 to 50)
    // - String lengths vary (e.g., 32 for Wi-Fi credentials, 15 for SERVER_IP)
    // ================================
    extern const int32_t numericMinValues[NUMERIC_SETTING_COUNT];
    extern const int32_t numericMaxValues[NUMERIC_SETTING_COUNT];
    extern const size_t stringMaxLengths[STRING_SETTING_COUNT];

    // ================================
    // Temporary Change Flags
    // Tracks whether settings have been changed since last reset
    // - Separate arrays for numeric, boolean, and string settings
    // ================================
    extern bool numericTempSettingsChanged[NUMERIC_SETTING_COUNT];
    extern bool booleanTempSettingsChanged[BOOLEAN_SETTING_COUNT];
    extern bool stringTempSettingsChanged[STRING_SETTING_COUNT];

    // ================================
    // Track Last Set Time
    // Records the time (in milliseconds) when each setting was last updated
    // - Used to manage temporary change flags
    // ================================
    extern unsigned long numericLastSetTime[NUMERIC_SETTING_COUNT];
    extern unsigned long booleanLastSetTime[BOOLEAN_SETTING_COUNT];
    extern unsigned long stringLastSetTime[STRING_SETTING_COUNT];

    // ================================
    // Function Prototypes
    // Declares functions for managing NVS settings and change flags
    // - Initialization, reset, set, get, and flag management
    // ================================
    void initializeSettings();
    void resetSettings();

    bool setNumericSetting(NumericIndex index, int32_t value);   // Set numeric setting
    bool setBooleanSetting(BooleanIndex index, bool value);      // Set boolean setting
    bool setStringSetting(StringIndex index, const char *value); // Set string setting

    int32_t getNumericSetting(NumericIndex index);                             // Get numeric setting
    bool getBooleanSetting(BooleanIndex index);                                // Get boolean setting
    bool getStringSetting(StringIndex index, char *buffer, size_t bufferSize); // Get string setting

    void resetAllChangedFlagsToFalse(); // Reset all change flags to false
    void resetAllChangedFlagsToTrue();  // Reset all change flags to true

    bool resetChangedFlagTemp(const char *type, int index);      // Reset a specific change flag to false
    bool getChangedFlagTemp(const char *settingType, int index); // Check a specific change flag

#ifdef __cplusplus
}
#endif

#endif // SETTING_H