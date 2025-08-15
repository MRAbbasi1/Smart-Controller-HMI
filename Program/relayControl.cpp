// relayControl.cpp
#include "relayControl.h"

// ================================
// Relay Status Variables
// Global variables to track the state of each relay (true = ON, false = OFF)
// ================================
bool compressorRelayStatus = false; // Compressor relay state
bool evaporatorRelayStatus = false; // Evaporator relay state
bool condenserRelayStatus = false;  // Condenser relay state
bool fan2RelayStatus = false;       // Fan2 relay state

// ================================
// Cached Settings and Sensor Data
// Static variables to store configuration and sensor readings from NVS and sensors
// ================================
static bool deviceOn = false;            // Device power state
static bool fan2On = false;              // Fan2 enabled state
static int32_t compressorTemp = 0;       // Compressor base temperature threshold
static int32_t compressorRange = 0;      // Compressor temperature range for hysteresis
static int32_t compressorRestTime = 0;   // Compressor rest time (ms) after deactivation (default 0ms, disabled)
static int32_t antiFreezeBase = 0;       // Antifreeze base temperature threshold
static int32_t antiFreezeRange = 0;      // Antifreeze temperature range for hysteresis
static int32_t fan2Temp = 0;             // Fan2 temperature threshold
static bool cachedDoorClosed = true;     // Cached door state (true = closed)
static bool cachedFilterWarning = false; // Cached filter warning state (true = active)
static float inletTemp = 0.0;            // Inlet sensor temperature
static float antiFreezeTemp = 0.0;       // Antifreeze sensor temperature
static float fan2SensorTemp = 0.0;       // Fan2 sensor temperature

// ================================
// Timing Variables
// Control periodic updates for settings and relay control
// ================================
static unsigned long lastCheckTime = 0;           // Last time settings were refreshed
static unsigned long lastRelayUpdateTime = 0;     // Last time relays were updated
static unsigned long lastCompressorOffTime = 0;   // Last time compressor was turned off
const unsigned long CHECK_INTERVAL = 5000;        // Interval for refreshing settings (ms)
const unsigned long RELAY_UPDATE_INTERVAL = 5000; // Interval for relay updates (ms, matched with PCF8574 version)
const unsigned long COMPRESSOR_ON_DELAY = 5000;   // Fixed delay (ms) for compressor activation after condenser

// ================================
// Setup Function
// Initializes relay pins and loads initial configuration data from NVS
// ================================
void setupRelays()
{
    uint32_t currentTime = millis();
    Serial.printf("[Relay][INFO][%lu] Initializing relay pins\n", currentTime);

    // Configure relay pins as outputs
    pinMode(COMPRESSOR_RELAY_PIN, OUTPUT);
    pinMode(EVAPORATOR_RELAY_PIN, OUTPUT);
    pinMode(CONDENSER_RELAY_PIN, OUTPUT);
    pinMode(FAN2_RELAY_PIN, OUTPUT);

    // Set initial relay states to OFF (HIGH = OFF, LOW = ON for active-low relays)
    digitalWrite(COMPRESSOR_RELAY_PIN, HIGH);
    digitalWrite(EVAPORATOR_RELAY_PIN, HIGH);
    digitalWrite(CONDENSER_RELAY_PIN, HIGH);
    digitalWrite(FAN2_RELAY_PIN, HIGH);

    // Load initial settings and sensor data
    reloadCachedData();
}

// ================================
// Control Loop
// Periodically refreshes settings and controls all relays
// ================================
void controlRelays()
{
    uint32_t currentTime = millis();

    // Refresh settings and sensor data every CHECK_INTERVAL
    if (currentTime - lastCheckTime >= CHECK_INTERVAL)
    {
        reloadCachedData();
        lastCheckTime = currentTime;
    }

    // Update relay states every RELAY_UPDATE_INTERVAL
    if (currentTime - lastRelayUpdateTime >= RELAY_UPDATE_INTERVAL)
    {
        controlEvaporatorRelay();
        controlCompressorAndCondenserRelays();
        controlFan2Relay();
        lastRelayUpdateTime = currentTime;
    }
}

// ================================
// Reload Cached Data
// Updates cached settings, alarms, and sensor data from NVS and sensors
// Only refreshes changed settings to optimize performance
// ================================
void reloadCachedData()
{
    uint32_t currentTime = millis();
    Serial.printf("[Relay][INFO][%lu] Reloading cached settings and sensor data\n", currentTime);

    // Update boolean settings if changed
    if (getChangedFlagTemp("boolean", DEVICE_ON))
    {
        deviceOn = getBooleanSetting(DEVICE_ON);
        resetChangedFlagTemp("boolean", DEVICE_ON);
        Serial.printf("[Relay][INFO][%lu] Device ON: %s\n", currentTime, deviceOn ? "True" : "False");
    }
    if (getChangedFlagTemp("boolean", FAN2_ON))
    {
        fan2On = getBooleanSetting(FAN2_ON);
        resetChangedFlagTemp("boolean", FAN2_ON);
        Serial.printf("[Relay][INFO][%lu] Fan2 ON: %s\n", currentTime, fan2On ? "True" : "False");
    }

    // Update numeric settings if changed
    if (getChangedFlagTemp("numeric", COMPRESSOR_TEMP))
    {
        compressorTemp = getNumericSetting(COMPRESSOR_TEMP);
        resetChangedFlagTemp("numeric", COMPRESSOR_TEMP);
        Serial.printf("[Relay][INFO][%lu] Compressor Temp: %d°C\n", currentTime, compressorTemp);
    }
    if (getChangedFlagTemp("numeric", COMPRESSOR_RANGE))
    {
        compressorRange = getNumericSetting(COMPRESSOR_RANGE);
        resetChangedFlagTemp("numeric", COMPRESSOR_RANGE);
        Serial.printf("[Relay][INFO][%lu] Compressor Range: %d°C\n", currentTime, compressorRange);
    }
    if (getChangedFlagTemp("numeric", COMPRESSOR_REST_TIME))
    {
        int32_t restTimeMinutes = getNumericSetting(COMPRESSOR_REST_TIME);
        // Validate compressorRestTime (0 to 5 minutes)
        if (restTimeMinutes < 0 || restTimeMinutes > 5)
        {
            restTimeMinutes = 0; // Default to 0 (disabled) if invalid
            Serial.printf("[Relay][WARN][%lu] Invalid compressorRestTime, using default 0 minutes\n", currentTime);
        }
        compressorRestTime = restTimeMinutes * 60000; // Convert minutes to milliseconds
        resetChangedFlagTemp("numeric", COMPRESSOR_REST_TIME);
        Serial.printf("[Relay][INFO][%lu] Compressor Rest Time: %d minutes (%dms)\n", currentTime, restTimeMinutes, compressorRestTime);
    }
    if (getChangedFlagTemp("numeric", ANTI_FREEZE_TEMP))
    {
        antiFreezeBase = getNumericSetting(ANTI_FREEZE_TEMP);
        resetChangedFlagTemp("numeric", ANTI_FREEZE_TEMP);
        Serial.printf("[Relay][INFO][%lu] AntiFreeze Base: %d°C\n", currentTime, antiFreezeBase);
    }
    if (getChangedFlagTemp("numeric", ANTI_FREEZE_RANGE))
    {
        antiFreezeRange = getNumericSetting(ANTI_FREEZE_RANGE);
        resetChangedFlagTemp("numeric", ANTI_FREEZE_RANGE);
        Serial.printf("[Relay][INFO][%lu] AntiFreeze Range: %d°C\n", currentTime, antiFreezeRange);
    }
    if (getChangedFlagTemp("numeric", FAN2_TEMP))
    {
        fan2Temp = getNumericSetting(FAN2_TEMP);
        resetChangedFlagTemp("numeric", FAN2_TEMP);
        Serial.printf("[Relay][INFO][%lu] Fan2 Temp: %d°C\n", currentTime, fan2Temp);
    }

    // Read and cache sensor temperatures
    inletTemp = readTemperatureByName("Inlet");
    antiFreezeTemp = readTemperatureByName("Antifreeze");
    fan2SensorTemp = readTemperatureByName("Filter");
    Serial.printf("[Relay][INFO][%lu] Inlet Temp: %.1f°C\n", currentTime, inletTemp);
    Serial.printf("[Relay][INFO][%lu] AntiFreeze Temp: %.1f°C\n", currentTime, antiFreezeTemp);
    Serial.printf("[Relay][INFO][%lu] Fan2 Sensor Temp: %.1f°C\n", currentTime, fan2SensorTemp);

    // Update cached alarm states
    cachedDoorClosed = isDoorClosed();
    cachedFilterWarning = isFilterWarning();
    Serial.printf("[Relay][INFO][%lu] Door Closed: %s\n", currentTime, cachedDoorClosed ? "True" : "False");
    Serial.printf("[Relay][INFO][%lu] Filter Warning: %s\n", currentTime, cachedFilterWarning ? "True" : "False");
}

// ================================
// Evaporator Relay Control
// Activates evaporator relay based on general conditions
// ================================
void controlEvaporatorRelay()
{
    uint32_t currentTime = millis();
    // Enable relay if device is on, door is closed, no filter warning, and inlet temp is valid
    bool newStatus = (deviceOn && cachedDoorClosed && !cachedFilterWarning && !isnan(inletTemp));

    if (newStatus != evaporatorRelayStatus)
    {
        evaporatorRelayStatus = newStatus;
        digitalWrite(EVAPORATOR_RELAY_PIN, newStatus ? LOW : HIGH);

        Serial.printf("[Relay][INFO][%lu] Evaporator: %s | Reason: ", currentTime, newStatus ? "ON" : "OFF");
        if (!deviceOn)
            Serial.printf("Device is OFF\n");
        else if (!cachedDoorClosed)
            Serial.printf("Door is OPEN\n");
        else if (cachedFilterWarning)
            Serial.printf("Filter warning active\n");
        else if (isnan(inletTemp))
            Serial.printf("Invalid inlet temperature (NaN)\n");
        else
            Serial.printf("All conditions met\n");
    }
}

// ================================
// Compressor and Condenser Relay Control
// Implements hysteresis for inletTemp and antiFreezeTemp to prevent rapid relay switching
// - inletTemp: ON at >= compressorTemp + compressorRange, OFF at < compressorTemp
// - antiFreezeTemp: ON at > antiFreezeBase + antiFreezeRange, OFF at <= antiFreezeBase
// Maintains state in hysteresis ranges, enforces 5s delay for compressor activation, and ensures rest time after deactivation
// ================================
void controlCompressorAndCondenserRelays()
{
    uint32_t currentTime = millis();
    static unsigned long condenserOnTime = 0;         // Tracks condenser activation time for delay
    static bool lastCondenserStatus = false;          // Stores previous condenser state for hysteresis
    bool newCondenserStatus = lastCondenserStatus;    // Default: maintain current state
    bool newCompressorStatus = compressorRelayStatus; // Default: maintain previous compressor state

    // Validate general conditions for operation
    if (deviceOn && cachedDoorClosed && !cachedFilterWarning && !isnan(antiFreezeTemp) && !isnan(inletTemp))
    {
        // Hysteresis for antiFreezeTemp: ON when temp > antiFreezeBase + antiFreezeRange, OFF when <= antiFreezeBase
        if (antiFreezeTemp > antiFreezeBase + antiFreezeRange)
        {
            // Hysteresis for inletTemp: ON when temp >= compressorTemp + compressorRange, OFF when < compressorTemp
            if (inletTemp >= compressorTemp + compressorRange)
            {
                newCondenserStatus = true;
                if (newCondenserStatus != lastCondenserStatus)
                {
                    condenserOnTime = millis(); // Record condenser activation time
                }
                // Check if compressor rest time has elapsed since last deactivation (if rest time is enabled)
                if (compressorRestTime == 0 || lastCompressorOffTime == 0 ||
                    (millis() - lastCompressorOffTime >= (unsigned long)compressorRestTime))
                {
                    newCompressorStatus = (millis() - condenserOnTime >= COMPRESSOR_ON_DELAY); // Compressor ON after 5s delay
                }
                else
                {
                    Serial.printf("[Relay][INFO][%lu] Compressor rest time not elapsed: %lu/%dms\n",
                                  currentTime, millis() - lastCompressorOffTime, compressorRestTime);
                }
            }
            else if (inletTemp < compressorTemp)
            {
                newCondenserStatus = false;
                newCompressorStatus = false;
                condenserOnTime = 0; // Reset condenser timer
            }
            else
            {
                newCondenserStatus = compressorRelayStatus; // Maintain previous state in hysteresis range
                Serial.printf("[Relay][INFO][%lu] Inlet Temp in hysteresis range: %.1f°C (%.1f to %.1f)\n",
                              currentTime, inletTemp, (float)compressorTemp, (float)(compressorTemp + compressorRange));
            }
        }
        else if (antiFreezeTemp <= antiFreezeBase)
        {
            newCondenserStatus = false;
            newCompressorStatus = false;
            condenserOnTime = 0; // Reset condenser timer
            Serial.printf("[Relay][INFO][%lu] AntiFreeze Temp at or below base: %.1f°C <= %d°C\n",
                          currentTime, antiFreezeTemp, antiFreezeBase);
        }
        else
        {
            newCondenserStatus = compressorRelayStatus;  // Maintain previous state in hysteresis range
            newCompressorStatus = compressorRelayStatus; // Maintain previous compressor state
            Serial.printf("[Relay][INFO][%lu] AntiFreeze Temp in hysteresis range: %.1f°C (%.1f to %.1f)\n",
                          currentTime, antiFreezeTemp, (float)antiFreezeBase, (float)(antiFreezeBase + antiFreezeRange));
        }
    }
    else
    {
        newCondenserStatus = false;
        newCompressorStatus = false;
        condenserOnTime = 0; // Reset condenser timer
        Serial.printf("[Relay][INFO][%lu] Relays OFF | Reason: ", currentTime);
        if (!deviceOn)
            Serial.printf("Device is OFF\n");
        else if (!cachedDoorClosed)
            Serial.printf("Door is OPEN\n");
        else if (cachedFilterWarning)
            Serial.printf("Filter warning active\n");
        else if (isnan(antiFreezeTemp))
            Serial.printf("Invalid antifreeze temperature (NaN)\n");
        else if (isnan(inletTemp))
            Serial.printf("Invalid inlet temperature (NaN)\n");
    }

    // Apply condenser relay state if changed
    if (newCondenserStatus != condenserRelayStatus)
    {
        condenserRelayStatus = newCondenserStatus;
        lastCondenserStatus = newCondenserStatus; // Update hysteresis state
        digitalWrite(CONDENSER_RELAY_PIN, newCondenserStatus ? LOW : HIGH);

        Serial.printf("[Relay][INFO][%lu] Condenser: %s | Reason: ", currentTime, newCondenserStatus ? "ON" : "OFF");
        if (!deviceOn)
            Serial.printf("Device is OFF\n");
        else if (!cachedDoorClosed)
            Serial.printf("Door is OPEN\n");
        else if (cachedFilterWarning)
            Serial.printf("Filter warning active\n");
        else if (isnan(antiFreezeTemp))
            Serial.printf("Invalid antifreeze temperature (NaN)\n");
        else if (isnan(inletTemp))
            Serial.printf("Invalid inlet temperature (NaN)\n");
        else if (antiFreezeTemp < antiFreezeBase)
            Serial.printf("Antifreeze temperature below base: %.1f°C < %d°C\n", antiFreezeTemp, antiFreezeBase);
        else if (antiFreezeTemp <= antiFreezeBase + antiFreezeRange)
            Serial.printf("Antifreeze temperature in hysteresis range: %.1f°C (%.1f to %.1f)\n",
                          antiFreezeTemp, (float)antiFreezeBase, (float)(antiFreezeBase + antiFreezeRange));
        else if (inletTemp < compressorTemp)
            Serial.printf("Inlet temperature below base: %.1f°C < %d°C\n", inletTemp, compressorTemp);
        else if (inletTemp >= compressorTemp + compressorRange)
            Serial.printf("Inlet temperature at or above range: %.1f°C >= %.1f°C\n",
                          inletTemp, (float)(compressorTemp + compressorRange));
        else
            Serial.printf("Following compressor in hysteresis range\n");
    }

    // Apply compressor relay state if changed
    if (newCompressorStatus != compressorRelayStatus)
    {
        compressorRelayStatus = newCompressorStatus;
        digitalWrite(COMPRESSOR_RELAY_PIN, newCompressorStatus ? LOW : HIGH);
        if (!newCompressorStatus)
        {
            lastCompressorOffTime = millis(); // Record time when compressor turns off
            condenserOnTime = 0;              // Reset condenser timer when compressor turns OFF
        }

        Serial.printf("[Relay][INFO][%lu] Compressor: %s | Reason: ", currentTime, newCompressorStatus ? "ON" : "OFF");
        if (!deviceOn)
            Serial.printf("Device is OFF\n");
        else if (!cachedDoorClosed)
            Serial.printf("Door is OPEN\n");
        else if (cachedFilterWarning)
            Serial.printf("Filter warning active\n");
        else if (isnan(antiFreezeTemp))
            Serial.printf("Invalid antifreeze temperature (NaN)\n");
        else if (isnan(inletTemp))
            Serial.printf("Invalid inlet temperature (NaN)\n");
        else if (antiFreezeTemp < antiFreezeBase)
            Serial.printf("Antifreeze temperature below base: %.1f°C < %d°C\n", antiFreezeTemp, antiFreezeBase);
        else if (antiFreezeTemp <= antiFreezeBase + antiFreezeRange)
            Serial.printf("Antifreeze temperature in hysteresis range: %.1f°C (%.1f to %.1f)\n",
                          antiFreezeTemp, (float)antiFreezeBase, (float)(antiFreezeBase + antiFreezeRange));
        else if (inletTemp < compressorTemp)
            Serial.printf("Inlet temperature below base: %.1f°C < %d°C\n", inletTemp, compressorTemp);
        else if (compressorRestTime != 0 && lastCompressorOffTime != 0 &&
                 (millis() - lastCompressorOffTime < (unsigned long)compressorRestTime))
            Serial.printf("Waiting for rest time: %lu/%dms\n",
                          millis() - lastCompressorOffTime, compressorRestTime);
        else if (millis() - condenserOnTime < COMPRESSOR_ON_DELAY)
            Serial.printf("Waiting for condenser delay (5s)\n");
        else
            Serial.printf("All conditions met\n");
    }
}

// ================================
// Fan2 Relay Control
// Activates Fan2 relay based on general conditions and fan2SensorTemp threshold
// ================================
void controlFan2Relay()
{
    uint32_t currentTime = millis();
    // Enable relay if device is on, door is closed, no filter warning, valid temp, and fan2SensorTemp exceeds threshold
    bool newStatus = (deviceOn && fan2On && cachedDoorClosed && !cachedFilterWarning &&
                      !isnan(fan2SensorTemp) && fan2SensorTemp > fan2Temp);

    if (newStatus != fan2RelayStatus)
    {
        fan2RelayStatus = newStatus;
        digitalWrite(FAN2_RELAY_PIN, newStatus ? LOW : HIGH);

        Serial.printf("[Relay][INFO][%lu] Fan2: %s | Reason: ", currentTime, newStatus ? "ON" : "OFF");
        if (!deviceOn)
            Serial.printf("Device is OFF\n");
        else if (!fan2On)
            Serial.printf("Fan2 is disabled in settings\n");
        else if (!cachedDoorClosed)
            Serial.printf("Door is OPEN\n");
        else if (cachedFilterWarning)
            Serial.printf("Filter warning active\n");
        else if (isnan(fan2SensorTemp))
            Serial.printf("Invalid sensor temperature (NaN)\n");
        else if (fan2SensorTemp <= fan2Temp)
            Serial.printf("Sensor temperature at or below threshold: %.1f°C <= %d°C\n",
                          fan2SensorTemp, fan2Temp);
        else
            Serial.printf("Sensor temperature above threshold: %.1f°C > %d°C\n",
                          fan2SensorTemp, fan2Temp);
    }
}

// ================================
// Relay Status Accessors
// Return current state of each relay with debug logging
// ================================
bool getCompressorRelayStatus()
{
    uint32_t currentTime = millis();
    Serial.printf("[Relay][INFO][%lu] Compressor Relay Status: %s\n", currentTime, compressorRelayStatus ? "True" : "False");
    return compressorRelayStatus;
}

bool getEvaporatorRelayStatus()
{
    uint32_t currentTime = millis();
    Serial.printf("[Relay][INFO][%lu] Evaporator Relay Status: %s\n", currentTime, evaporatorRelayStatus ? "True" : "False");
    return evaporatorRelayStatus;
}

bool getCondenserRelayStatus()
{
    uint32_t currentTime = millis();
    Serial.printf("[Relay][INFO][%lu] Condenser Relay Status: %s\n", currentTime, condenserRelayStatus ? "True" : "False");
    return condenserRelayStatus;
}

bool getFan2RelayStatus()
{
    uint32_t currentTime = millis();
    Serial.printf("[Relay][INFO][%lu] Fan2 Relay Status: %s\n", currentTime, fan2RelayStatus ? "True" : "False");
    return fan2RelayStatus;
}