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
// Stores settings and sensor data retrieved from NVS and sensors
// ================================
static bool deviceOn = false;            // Device power state
static bool fan2On = false;              // Fan2 enable state
static int32_t compressorTemp = 0;       // Compressor temperature threshold (°C)
static int32_t compressorRange = 0;      // Compressor hysteresis range (°C)
static int32_t compressorRestTime = 0;   // Compressor rest time (ms)
static int32_t antiFreezeBase = 0;       // Anti-freeze temperature base (°C)
static int32_t antiFreezeRange = 0;      // Anti-freeze hysteresis range (°C)
static int32_t fan2Temp = 0;             // Fan2 temperature threshold (°C)
static bool cachedDoorClosed = true;     // Cached door state (true = closed)
static bool cachedFilterWarning = false; // Cached filter warning state
static float inletTemp = 0.0;            // Inlet sensor temperature (°C)
static float antiFreezeTemp = 0.0;       // Anti-freeze sensor temperature (°C)
static float fan2SensorTemp = 0.0;       // Fan2 sensor temperature (°C)

// ================================
// Timing Variables
// Controls timing for relay updates and sensor checks
// ================================
static unsigned long lastCheckTime = 0;           // Last time settings/sensors were checked
static unsigned long lastRelayUpdateTime = 0;     // Last time relays were updated
static unsigned long lastCompressorOffTime = 0;   // Last time compressor was turned off
const unsigned long CHECK_INTERVAL = 5000;        // Interval for checking settings/sensors (ms)
const unsigned long RELAY_UPDATE_INTERVAL = 5000; // Interval for updating relays (ms)
const unsigned long COMPRESSOR_ON_DELAY = 5000;   // Delay before compressor turns on (ms)

// PCF8574 output state (all pins HIGH by default, relays OFF)
static uint8_t pcf8574_output_state = 0xFF;

// ================================
// Helper Function to Write to PCF8574
// Writes the current output state to PCF8574 via I2C
// ================================
void writeToPCF8574()
{
    uint32_t currentTime = millis();
    Wire.beginTransmission(PCF8574_ADDRESS);
    Wire.write(pcf8574_output_state);
    if (Wire.endTransmission() != 0)
    {
        Serial.printf("[Relay][ERROR][%lu] Failed to write to PCF8574 at address 0x%02X\n", currentTime, PCF8574_ADDRESS);
    }
}

// ================================
// Helper Function to Set Pin State
// Updates the specific bit in pcf8574_output_state and writes to PCF8574
// pin: 0 to 7 (P0 to P7), value: HIGH (relay OFF) or LOW (relay ON)
// ================================
void setPCF8574Pin(uint8_t pin, uint8_t value)
{
    uint32_t currentTime = millis();
    if (value == HIGH)
        pcf8574_output_state |= (1 << pin); // Set bit to 1 (HIGH, relay OFF)
    else
        pcf8574_output_state &= ~(1 << pin); // Clear bit to 0 (LOW, relay ON)
    writeToPCF8574();
    Serial.printf("[Relay][INFO][%lu] PCF8574 pin P%d set to %s\n", currentTime, pin, value == HIGH ? "HIGH" : "LOW");
}

// ================================
// Setup Function
// Initializes PCF8574 via I2C and loads initial configuration data from NVS
// ================================
void setupRelays()
{
    uint32_t currentTime = millis();
    Serial.printf("[Relay][INFO][%lu] Initializing PCF8574 for relay control\n", currentTime);

    // Initialize I2C bus with SDA: GPIO15, SCL: GPIO7
    Wire.begin(15, 7);

    Wire.setClock(400000); // Set I2C frequency to 400kHz

    // Set all PCF8574 pins to HIGH (relays OFF)
    pcf8574_output_state = 0xFF;
    writeToPCF8574();

    // Verify PCF8574 connection
    Wire.beginTransmission(PCF8574_ADDRESS);
    if (Wire.endTransmission() == 0)
    {
        Serial.printf("[Relay][INFO][%lu] PCF8574 initialized at address 0x%02X\n", currentTime, PCF8574_ADDRESS);
    }
    else
    {
        Serial.printf("[Relay][ERROR][%lu] Failed to initialize PCF8574 at address 0x%02X. Continuing without relays...\n", currentTime, PCF8574_ADDRESS);
    }

    // Load initial settings and sensor data
    reloadCachedData();
}

// ================================
// Main Control Loop
// Periodically refreshes settings and updates relay states
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
// Refreshes cached settings and sensor data from NVS and sensors
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
        if (restTimeMinutes < 0 || restTimeMinutes > 5)
        {
            restTimeMinutes = 0;
            Serial.printf("[Relay][WARN][%lu] Invalid compressorRestTime, using default 0 minutes\n", currentTime);
        }
        compressorRestTime = restTimeMinutes * 60000;
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
// Controls evaporator relay based on device state, door, filter, and inlet temperature
// ================================
void controlEvaporatorRelay()
{
    uint32_t currentTime = millis();
    bool newStatus = (deviceOn && cachedDoorClosed && !cachedFilterWarning && !isnan(inletTemp));

    if (newStatus != evaporatorRelayStatus)
    {
        evaporatorRelayStatus = newStatus;
        setPCF8574Pin(EVAPORATOR_RELAY_PIN, newStatus ? LOW : HIGH);
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
// Controls compressor and condenser relays with hysteresis and delay
// ================================
void controlCompressorAndCondenserRelays()
{
    uint32_t currentTime = millis();
    static unsigned long condenserOnTime = 0;         // Time when condenser was last turned on
    bool newCompressorStatus = compressorRelayStatus; // Maintain previous compressor state by default
    bool newCondenserStatus = compressorRelayStatus;  // Condenser follows compressor state by default

    // Check if device is on and no errors exist
    if (deviceOn && cachedDoorClosed && !cachedFilterWarning && !isnan(antiFreezeTemp) && !isnan(inletTemp))
    {
        // Check anti-freeze temperature condition
        if (antiFreezeTemp > antiFreezeBase + antiFreezeRange)
        {
            // Hysteresis logic for compressor
            if (inletTemp >= compressorTemp + compressorRange)
            {
                newCondenserStatus = true; // Condenser should be ON
                // Check if compressor rest time has elapsed
                if (compressorRestTime == 0 || lastCompressorOffTime == 0 ||
                    (millis() - lastCompressorOffTime >= (unsigned long)compressorRestTime))
                {
                    // Apply delay for compressor activation
                    if (!condenserOnTime) // Start timer when condenser turns ON
                    {
                        condenserOnTime = millis();
                    }
                    newCompressorStatus = (millis() - condenserOnTime >= COMPRESSOR_ON_DELAY);
                }
                else
                {
                    Serial.printf("[Relay][INFO][%lu] Compressor rest time not elapsed: %lu/%dms\n",
                                  currentTime, millis() - lastCompressorOffTime, compressorRestTime);
                }
            }
            else if (inletTemp < compressorTemp)
            {
                newCondenserStatus = false;  // Condenser should be OFF
                newCompressorStatus = false; // Compressor should be OFF
                condenserOnTime = 0;         // Reset condenser timer
            }
            else
            {
                // Hysteresis range for inlet temp: maintain previous compressor state
                newCondenserStatus = compressorRelayStatus; // Condenser follows compressor
                Serial.printf("[Relay][INFO][%lu] Inlet Temp in hysteresis range: %.1f°C (%.1f to %.1f)\n",
                              currentTime, inletTemp, (float)compressorTemp, (float)(compressorTemp + compressorRange));
            }
        }
        else if (antiFreezeTemp < antiFreezeBase)
        {
            // Anti-freeze temperature too low
            newCondenserStatus = false;  // Condenser should be OFF
            newCompressorStatus = false; // Compressor should be OFF
            condenserOnTime = 0;         // Reset condenser timer
            Serial.printf("[Relay][INFO][%lu] AntiFreeze Temp at or below base: %.1f°C <= %d°C\n",
                          currentTime, antiFreezeTemp, antiFreezeBase);
        }
        else
        {
            // Hysteresis range for anti-freeze temp: maintain previous compressor state
            newCondenserStatus = compressorRelayStatus;  // Condenser follows compressor
            newCompressorStatus = compressorRelayStatus; // Maintain previous compressor state
            Serial.printf("[Relay][INFO][%lu] AntiFreeze Temp in hysteresis range: %.1f°C (%.1f to %.1f)\n",
                          currentTime, antiFreezeTemp, (float)antiFreezeBase, (float)(antiFreezeBase + antiFreezeRange));
        }
    }
    else
    {
        // Device is OFF or error condition exists
        newCondenserStatus = false;  // Condenser should be OFF
        newCompressorStatus = false; // Compressor should be OFF
        condenserOnTime = 0;         // Reset condenser timer
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

    // Update condenser relay if state changed
    if (newCondenserStatus != condenserRelayStatus)
    {
        condenserRelayStatus = newCondenserStatus;
        setPCF8574Pin(CONDENSER_RELAY_PIN, newCondenserStatus ? LOW : HIGH);
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
            Serial.printf("Inlet temperature at or above range: %.1f°C >= %.1f°C\n", inletTemp, (float)(compressorTemp + compressorRange));
        else
            Serial.printf("Following compressor in hysteresis range\n");
    }

    // Update compressor relay if state changed
    if (newCompressorStatus != compressorRelayStatus)
    {
        compressorRelayStatus = newCompressorStatus;
        setPCF8574Pin(COMPRESSOR_RELAY_PIN, newCompressorStatus ? LOW : HIGH);
        if (!newCompressorStatus)
        {
            lastCompressorOffTime = millis();
            condenserOnTime = 0; // Reset condenser timer when compressor turns OFF
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
        else if (compressorRestTime != 0 && lastCompressorOffTime != 0 && (millis() - lastCompressorOffTime < (unsigned long)compressorRestTime))
            Serial.printf("Waiting for rest time: %lu/%dms\n", millis() - lastCompressorOffTime, compressorRestTime);
        else if (millis() - condenserOnTime < COMPRESSOR_ON_DELAY)
            Serial.printf("Waiting for condenser delay (5s)\n");
        else
            Serial.printf("All conditions met\n");
    }
}

// ================================
// Fan2 Relay Control
// Controls fan2 relay based on device state, settings, and sensor temperature
// ================================
void controlFan2Relay()
{
    uint32_t currentTime = millis();
    bool newStatus = (deviceOn && fan2On && cachedDoorClosed && !cachedFilterWarning &&
                      !isnan(fan2SensorTemp) && fan2SensorTemp > fan2Temp);

    if (newStatus != fan2RelayStatus)
    {
        fan2RelayStatus = newStatus;
        setPCF8574Pin(FAN2_RELAY_PIN, newStatus ? LOW : HIGH);
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
            Serial.printf("Sensor temperature at or below threshold: %.1f°C <= %d°C\n", fan2SensorTemp, fan2Temp);
        else
            Serial.printf("Sensor temperature above threshold: %.1f°C > %d°C\n", fan2SensorTemp, fan2Temp);
    }
}

// ================================
// Relay Status Accessors
// Returns current state of each relay with logging
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