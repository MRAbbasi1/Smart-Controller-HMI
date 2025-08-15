// setting.cpp

#include "setting.h"
#include <nvs_flash.h>
#include <nvs.h>
#include <string.h>

// ================================
// Default Values
// Defines default values for numeric, boolean, and string settings
// - Numeric: Temperature thresholds, device IDs, counters (e.g., COMPRESSOR_TEMP = 20)
// - Boolean: Feature toggles (e.g., DEVICE_ON = false)
// - String: Wi-Fi credentials, server URLs, sensor addresses (e.g., SERVER_URL = "http://server.com")
// ================================
const int32_t defaultNumericValues[] = {
    20,        // COMPRESSOR_TEMP
    5,         // COMPRESSOR_RANGE
    40,        // HIGH_TEMP_WARNING
    -5,        // ANTI_FREEZE_TEMP
    10,        // ANTI_FREEZE_RANGE
    1,         // COMPRESSOR_REST_TIME
    80,        // FILTER_WARNING
    55,        // FAN2_TEMP
    100001,    // DEVICE_SERIAL_ID
    123456789, // CUSTOMER_ID
    20241104,  // ACTIVATION_DATE
    365,       // SERVICE_INTERVAL
    0          // HOURS_ELAPSED
};

const bool defaultBooleanValues[] = {
    false, // DEVICE_ON
    false, // PRESSURE_WARNING_ON
    false, // TEMP_WARNING_ON
    false, // FILTER_WARNING_ON
    false, // DOOR_WARNING_ON
    false, // FAN2_ON
    false, // ADVANCED_SETTINGS_ON
    false, // CLOUD_ON
    false, // SERIAL_LOG_ON
    false  // CLOUD_LOG_ON
};

const char *defaultStringValues[] = {
    "0",                       // WIFI_SSID
    "0",                       // WIFI_PASSWORD
    "0",                       // AP_NAME
    "0",                       // AP_PASSWORD
    "http://bently.cool",      // SERVER_URL
    "192.168.4.1",             // SERVER_IP
    "28:2D:11:58:D4:E1:3C:BC", // INLET_SENSOR_ADDRESS
    "28:AB:CC:43:D4:E1:3C:FA", // OUTLET_SENSOR_ADDRESS
    "28:FF:64:1F:7F:86:98:02", // ANTIFREEZE_SENSOR_ADDRESS
    "28:FF:64:1F:7F:CA:EF:AF"  // FILTER_SENSOR_ADDRESS
};

// ================================
// Validation Ranges
// Defines minimum and maximum values for numeric settings and maximum lengths for strings
// - Numeric: Ensures values stay within valid ranges (e.g., COMPRESSOR_TEMP: 20 to 50)
// - String: Limits lengths (e.g., WIFI_SSID: 32, SERVER_IP: 15)
// ================================
const int32_t numericMinValues[] = {
    20,       // COMPRESSOR_TEMP_MIN
    0,        // COMPRESSOR_RANGE
    20,       // HIGH_TEMP_WARNING
    -15,      // ANTI_FREEZE_TEMP
    0,        // ANTI_FREEZE_RANGE
    0,        // COMPRESSOR_REST_TIME
    60,       // FILTER_WARNING
    30,       // FAN2_TEMP
    0,        // DEVICE_SERIAL_ID
    0,        // CUSTOMER_ID
    20010903, // ACTIVATION_DATE
    0,        // SERVICE_INTERVAL
    0         // HOURS_ELAPSED
};

const int32_t numericMaxValues[] = {
    50,        // COMPRESSOR_TEMP_MAX
    15,        // COMPRESSOR_RANGE
    50,        // HIGH_TEMP_WARNING
    15,        // ANTI_FREEZE_TEMP
    15,        // ANTI_FREEZE_RANGE
    5,         // COMPRESSOR_REST_TIME
    100,       // FILTER_WARNING
    85,        // FAN2_TEMP
    999999999, // DEVICE_SERIAL_ID
    999999999, // CUSTOMER_ID
    999999999, // ACTIVATION_DATE
    3650,      // SERVICE_INTERVAL
    87600      // HOURS_ELAPSED
};

const size_t stringMaxLengths[] = {
    32, // WIFI_SSID
    32, // WIFI_PASSWORD
    16, // AP_NAME
    16, // AP_PASSWORD
    64, // SERVER_URL
    15, // SERVER_IP
    32, // INLET_SENSOR_ADDRESS
    32, // OUTLET_SENSOR_ADDRESS
    32, // ANTIFREEZE_SENSOR_ADDRESS
    32  // FILTER_SENSOR_ADDRESS
};

// ================================
// Temporary Change Flags
// Tracks changes to settings with temporary flags
// - Arrays for numeric, boolean, and string settings
// ================================
bool numericTempSettingsChanged[NUMERIC_SETTING_COUNT] = {false};
bool booleanTempSettingsChanged[BOOLEAN_SETTING_COUNT] = {false};
bool stringTempSettingsChanged[STRING_SETTING_COUNT] = {false};

// ================================
// Track Last Set Time
// Records the time (in milliseconds) when each setting was last updated
// - Used to reset temporary change flags after 60 seconds
// ================================
unsigned long numericLastSetTime[NUMERIC_SETTING_COUNT] = {0};
unsigned long booleanLastSetTime[BOOLEAN_SETTING_COUNT] = {0};
unsigned long stringLastSetTime[STRING_SETTING_COUNT] = {0};

// ================================
// Reset All Changed Flags to False
// Resets all temporary change flags for numeric, boolean, and string settings to false
// - Used to clear change tracking after processing
// ================================
void resetAllChangedFlagsToFalse()
{
    uint32_t currentTime = millis();
    for (int i = 0; i < NUMERIC_SETTING_COUNT; i++)
    {
        numericTempSettingsChanged[i] = false;
    }
    for (int i = 0; i < BOOLEAN_SETTING_COUNT; i++)
    {
        booleanTempSettingsChanged[i] = false;
    }
    for (int i = 0; i < STRING_SETTING_COUNT; i++)
    {
        stringTempSettingsChanged[i] = false;
    }
    Serial.printf("[Setting][INFO][%lu] All changed flags reset to false\n", currentTime);
}

// ================================
// Reset All Changed Flags to True
// Sets all temporary change flags for numeric, boolean, and string settings to true
// - Used during initialization or reset to mark all settings as changed
// ================================
void resetAllChangedFlagsToTrue()
{
    uint32_t currentTime = millis();
    for (int i = 0; i < NUMERIC_SETTING_COUNT; i++)
    {
        numericTempSettingsChanged[i] = true;
    }
    for (int i = 0; i < BOOLEAN_SETTING_COUNT; i++)
    {
        booleanTempSettingsChanged[i] = true;
    }
    for (int i = 0; i < STRING_SETTING_COUNT; i++)
    {
        stringTempSettingsChanged[i] = true;
    }
    Serial.printf("[Setting][INFO][%lu] All changed flags reset to true\n", currentTime);
}

// ================================
// Initialize Settings
// Initializes NVS and loads default values for missing settings
// - Opens NVS storage in read/write mode
// - Sets default numeric, boolean, and string values if not found
// - Commits changes and sets all change flags to true
// ================================
void initializeSettings()
{
    uint32_t currentTime = millis();
    Serial.printf("[Setting][INFO][%lu] Initializing settings\n", currentTime);

    if (nvs_flash_init() != ESP_OK)
    {
        Serial.printf("[Setting][ERROR][%lu] NVS initialization failed\n", currentTime);
        return;
    }

    nvs_handle_t handle;
    if (nvs_open("storage", NVS_READWRITE, &handle) != ESP_OK)
    {
        Serial.printf("[Setting][ERROR][%lu] Failed to open NVS\n", currentTime);
        return;
    }

    Serial.printf("[Setting][INFO][%lu] NVS opened successfully\n", currentTime);

    // Load numeric defaults if missing
    for (int i = 0; i < NUMERIC_SETTING_COUNT; i++)
    {
        char key[16];
        sprintf(key, "num_%d", i);
        int32_t value;
        if (nvs_get_i32(handle, key, &value) != ESP_OK)
        {
            nvs_set_i32(handle, key, defaultNumericValues[i]);
            Serial.printf("[Setting][INFO][%lu] Numeric key '%s' initialized with default value: %d\n", currentTime, key, defaultNumericValues[i]);
        }
    }

    // Load boolean defaults if missing
    for (int i = 0; i < BOOLEAN_SETTING_COUNT; i++)
    {
        char key[16];
        sprintf(key, "bool_%d", i);
        uint8_t value;
        if (nvs_get_u8(handle, key, &value) != ESP_OK)
        {
            nvs_set_u8(handle, key, defaultBooleanValues[i]);
            Serial.printf("[Setting][INFO][%lu] Boolean key '%s' initialized with default value: %d\n", currentTime, key, defaultBooleanValues[i]);
        }
    }

    // Load string defaults if missing
    for (int i = 0; i < STRING_SETTING_COUNT; i++)
    {
        char key[16];
        sprintf(key, "str_%d", i);
        size_t length = STRING_MAX_LENGTH;
        char buffer[STRING_MAX_LENGTH];
        if (nvs_get_str(handle, key, buffer, &length) != ESP_OK)
        {
            nvs_set_str(handle, key, defaultStringValues[i]);
            Serial.printf("[Setting][INFO][%lu] String key '%s' initialized with default value: %s\n", currentTime, key, defaultStringValues[i]);
        }
    }

    nvs_commit(handle);
    nvs_close(handle);
    resetAllChangedFlagsToTrue();
    Serial.printf("[Setting][INFO][%lu] Settings initialization completed\n", currentTime);
}

// ================================
// Reset Settings
// Erases all NVS data and reinitializes with default values
// - Clears NVS, reinitializes, and sets all change flags to true
// ================================
void resetSettings()
{
    uint32_t currentTime = millis();
    Serial.printf("[Setting][INFO][%lu] Resetting settings to default values\n", currentTime);

    nvs_flash_erase();
    nvs_flash_init();
    initializeSettings();
    resetAllChangedFlagsToTrue();
    Serial.printf("[Setting][INFO][%lu] Settings reset completed\n", currentTime);
}

// ================================
// Set Numeric Setting
// Stores a numeric setting in NVS with validation
// - Validates index and value range
// - Updates change flag and records set time
// - Returns true on success, false on failure
// ================================
bool setNumericSetting(NumericIndex index, int32_t value)
{
    uint32_t currentTime = millis();
    if (index < 0 || index >= NUMERIC_SETTING_COUNT)
    {
        Serial.printf("[Setting][ERROR][%lu] Invalid numeric index: %d\n", currentTime, index);
        return false;
    }

    if (value < numericMinValues[index] || value > numericMaxValues[index])
    {
        Serial.printf("[Setting][ERROR][%lu] Value %d for 'num_%d' out of range: %d to %d\n", currentTime, value, index, numericMinValues[index], numericMaxValues[index]);
        return false;
    }

    nvs_handle_t handle;
    if (nvs_open("storage", NVS_READWRITE, &handle) != ESP_OK)
    {
        Serial.printf("[Setting][ERROR][%lu] Failed to open NVS\n", currentTime);
        return false;
    }

    char key[16];
    sprintf(key, "num_%d", index);
    nvs_set_i32(handle, key, value);
    nvs_commit(handle);
    nvs_close(handle);

    numericTempSettingsChanged[index] = true;
    numericLastSetTime[index] = currentTime;
    Serial.printf("[Setting][INFO][%lu] Numeric key '%s' updated to value: %d\n", currentTime, key, value);
    return true;
}

// ================================
// Set Boolean Setting
// Stores a boolean setting in NVS
// - Validates index
// - Updates change flag and records set time
// - Returns true on success, false on failure
// ================================
bool setBooleanSetting(BooleanIndex index, bool value)
{
    uint32_t currentTime = millis();
    if (index < 0 || index >= BOOLEAN_SETTING_COUNT)
    {
        Serial.printf("[Setting][ERROR][%lu] Invalid boolean index: %d\n", currentTime, index);
        return false;
    }

    nvs_handle_t handle;
    if (nvs_open("storage", NVS_READWRITE, &handle) != ESP_OK)
    {
        Serial.printf("[Setting][ERROR][%lu] Failed to open NVS\n", currentTime);
        return false;
    }

    char key[16];
    sprintf(key, "bool_%d", index);
    nvs_set_u8(handle, key, value);
    nvs_commit(handle);
    nvs_close(handle);

    booleanTempSettingsChanged[index] = true;
    booleanLastSetTime[index] = currentTime;
    Serial.printf("[Setting][INFO][%lu] Boolean key '%s' updated to value: %d\n", currentTime, key, value);
    return true;
}

// ================================
// Set String Setting
// Stores a string setting in NVS with validation
// - Validates index, string length, and SERVER_IP format (if applicable)
// - Updates change flag and records set time
// - Returns true on success, false on failure
// ================================
bool setStringSetting(StringIndex index, const char *value)
{
    uint32_t currentTime = millis();
    if (index < 0 || index >= STRING_SETTING_COUNT)
    {
        Serial.printf("[Setting][ERROR][%lu] Invalid string index: %d\n", currentTime, index);
        return false;
    }

    if (index == SERVER_IP)
    {
        Serial.printf("[Setting][INFO][%lu] Validating IP address: %s\n", currentTime, value);
        int parts[4];
        int count = 0;
        char ipCopy[16];
        strncpy(ipCopy, value, sizeof(ipCopy));
        ipCopy[sizeof(ipCopy) - 1] = '\0';
        char *token = strtok(ipCopy, ".");

        while (token != NULL)
        {
            if (count >= 4)
            {
                Serial.printf("[Setting][ERROR][%lu] Invalid IP address: too many parts\n", currentTime);
                return false;
            }
            parts[count++] = atoi(token);
            token = strtok(NULL, ".");
        }

        if (count != 4)
        {
            Serial.printf("[Setting][ERROR][%lu] Invalid IP address: must have 4 parts\n", currentTime);
            return false;
        }

        for (int i = 0; i < 4; i++)
        {
            if (parts[i] < 0 || parts[i] > 255)
            {
                Serial.printf("[Setting][ERROR][%lu] Invalid IP address: part %d out of range\n", currentTime, i);
                return false;
            }
        }
    }

    if (strlen(value) > stringMaxLengths[index])
    {
        Serial.printf("[Setting][ERROR][%lu] String value for 'str_%d' too long: %d, max: %d\n", currentTime, index, strlen(value), stringMaxLengths[index]);
        return false;
    }

    nvs_handle_t handle;
    if (nvs_open("storage", NVS_READWRITE, &handle) != ESP_OK)
    {
        Serial.printf("[Setting][ERROR][%lu] Failed to open NVS\n", currentTime);
        return false;
    }

    char key[16];
    sprintf(key, "str_%d", index);
    nvs_set_str(handle, key, value);
    nvs_commit(handle);
    nvs_close(handle);

    stringTempSettingsChanged[index] = true;
    stringLastSetTime[index] = currentTime;
    Serial.printf("[Setting][INFO][%lu] String key '%s' updated to value: %s\n", currentTime, key, value);
    return true;
}

// ================================
// Get Numeric Setting
// Retrieves a numeric setting from NVS
// - Validates index
// - Returns default value if key not found
// - Returns -1 on invalid index or NVS failure
// ================================
int32_t getNumericSetting(NumericIndex index)
{
    uint32_t currentTime = millis();
    if (index < 0 || index >= NUMERIC_SETTING_COUNT)
    {
        Serial.printf("[Setting][ERROR][%lu] Invalid numeric index: %d\n", currentTime, index);
        return -1;
    }

    nvs_handle_t handle;
    if (nvs_open("storage", NVS_READONLY, &handle) != ESP_OK)
    {
        Serial.printf("[Setting][ERROR][%lu] Failed to open NVS\n", currentTime);
        return -1;
    }

    char key[16];
    sprintf(key, "num_%d", index);
    int32_t value;
    if (nvs_get_i32(handle, key, &value) != ESP_OK)
    {
        Serial.printf("[Setting][WARN][%lu] Numeric key '%s' not found, using default value: %d\n", currentTime, key, defaultNumericValues[index]);
        value = defaultNumericValues[index];
    }
    nvs_close(handle);

    Serial.printf("[Setting][INFO][%lu] Numeric key '%s' retrieved with value: %d\n", currentTime, key, value);
    return value;
}

// ================================
// Get Boolean Setting
// Retrieves a boolean setting from NVS
// - Validates index
// - Returns default value if key not found
// - Returns false on invalid index or NVS failure
// ================================
bool getBooleanSetting(BooleanIndex index)
{
    uint32_t currentTime = millis();
    if (index < 0 || index >= BOOLEAN_SETTING_COUNT)
    {
        Serial.printf("[Setting][ERROR][%lu] Invalid boolean index: %d\n", currentTime, index);
        return false;
    }

    nvs_handle_t handle;
    if (nvs_open("storage", NVS_READONLY, &handle) != ESP_OK)
    {
        Serial.printf("[Setting][ERROR][%lu] Failed to open NVS\n", currentTime);
        return false;
    }

    char key[16];
    sprintf(key, "bool_%d", index);
    uint8_t value;
    if (nvs_get_u8(handle, key, &value) != ESP_OK)
    {
        Serial.printf("[Setting][WARN][%lu] Boolean key '%s' not found, using default value: %d\n", currentTime, key, defaultBooleanValues[index]);
        value = defaultBooleanValues[index];
    }
    nvs_close(handle);

    Serial.printf("[Setting][INFO][%lu] Boolean key '%s' retrieved with value: %d\n", currentTime, key, value);
    return value;
}

// ================================
// Get String Setting
// Retrieves a string setting from NVS
// - Validates index and buffer size
// - Copies default value to buffer if key not found
// - Returns true on success, false on failure
// ================================
bool getStringSetting(StringIndex index, char *buffer, size_t bufferSize)
{
    uint32_t currentTime = millis();
    if (index < 0 || index >= STRING_SETTING_COUNT)
    {
        Serial.printf("[Setting][ERROR][%lu] Invalid string index: %d\n", currentTime, index);
        return false;
    }

    nvs_handle_t handle;
    if (nvs_open("storage", NVS_READONLY, &handle) != ESP_OK)
    {
        Serial.printf("[Setting][ERROR][%lu] Failed to open NVS\n", currentTime);
        return false;
    }

    char key[16];
    sprintf(key, "str_%d", index);
    size_t length = bufferSize;
    if (nvs_get_str(handle, key, buffer, &length) != ESP_OK)
    {
        Serial.printf("[Setting][WARN][%lu] String key '%s' not found, using default value: %s\n", currentTime, key, defaultStringValues[index]);
        strncpy(buffer, defaultStringValues[index], bufferSize);
    }
    nvs_close(handle);

    Serial.printf("[Setting][INFO][%lu] String key '%s' retrieved with value: %s\n", currentTime, key, buffer);
    return true;
}

// ================================
// Reset Changed Flag (Temporary)
// Resets a specific temporary change flag to false after 60 seconds
// - Supports numeric, boolean, and string settings
// - Returns true if flag was reset, false otherwise
// ================================
bool resetChangedFlagTemp(const char *type, int index)
{
    uint32_t currentTime = millis();
    if (strcmp(type, "numeric") == 0 && index >= 0 && index < NUMERIC_SETTING_COUNT)
    {
        if (numericTempSettingsChanged[index] && (currentTime - numericLastSetTime[index] >= 60000))
        {
            numericTempSettingsChanged[index] = false;
            Serial.printf("[Setting][INFO][%lu] Numeric setting flag for index %d reset after 60 seconds\n", currentTime, index);
            return true;
        }
    }
    else if (strcmp(type, "boolean") == 0 && index >= 0 && index < BOOLEAN_SETTING_COUNT)
    {
        if (booleanTempSettingsChanged[index] && (currentTime - booleanLastSetTime[index] >= 60000))
        {
            booleanTempSettingsChanged[index] = false;
            Serial.printf("[Setting][INFO][%lu] Boolean setting flag for index %d reset after 60 seconds\n", currentTime, index);
            return true;
        }
    }
    else if (strcmp(type, "string") == 0 && index >= 0 && index < STRING_SETTING_COUNT)
    {
        if (stringTempSettingsChanged[index] && (currentTime - stringLastSetTime[index] >= 60000))
        {
            stringTempSettingsChanged[index] = false;
            Serial.printf("[Setting][INFO][%lu] String setting flag for index %d reset after 60 seconds\n", currentTime, index);
            return true;
        }
    }
    return false;
}

// ================================
// Get Changed Flag (Temporary)
// Checks the temporary change flag for a specific setting
// - Supports numeric, boolean, and string settings
// - Returns true if changed, false if unchanged or invalid
// ================================
bool getChangedFlagTemp(const char *settingType, int index)
{
    uint32_t currentTime = millis();
    if (index < 0)
    {
        Serial.printf("[Setting][ERROR][%lu] Invalid index for reading flag: %d\n", currentTime, index);
        return false;
    }

    if (strcmp(settingType, "numeric") == 0)
    {
        if (index >= NUMERIC_SETTING_COUNT)
        {
            Serial.printf("[Setting][ERROR][%lu] Invalid numeric index for reading: %d\n", currentTime, index);
            return false;
        }
        Serial.printf("[Setting][INFO][%lu] Numeric setting flag for index %d is: %s\n", currentTime, index, numericTempSettingsChanged[index] ? "true" : "false");
        return numericTempSettingsChanged[index];
    }
    else if (strcmp(settingType, "boolean") == 0)
    {
        if (index >= BOOLEAN_SETTING_COUNT)
        {
            Serial.printf("[Setting][ERROR][%lu] Invalid boolean index for reading: %d\n", currentTime, index);
            return false;
        }
        Serial.printf("[Setting][INFO][%lu] Boolean setting flag for index %d is: %s\n", currentTime, index, booleanTempSettingsChanged[index] ? "true" : "false");
        return booleanTempSettingsChanged[index];
    }
    else if (strcmp(settingType, "string") == 0)
    {
        if (index >= STRING_SETTING_COUNT)
        {
            Serial.printf("[Setting][ERROR][%lu] Invalid string index for reading: %d\n", currentTime, index);
            return false;
        }
        Serial.printf("[Setting][INFO][%lu] String setting flag for index %d is: %s\n", currentTime, index, stringTempSettingsChanged[index] ? "true" : "false");
        return stringTempSettingsChanged[index];
    }
    else
    {
        Serial.printf("[Setting][ERROR][%lu] Invalid type for reading flag: %s\n", currentTime, settingType);
        return false;
    }
}