// tempSensor.cpp

#include "tempSensor.h"
#include "setting.h"

#define ONE_WIRE_BUS // sensor GPIO pin - ** REAL GPIO need for DS18B20 frequency speed controling **

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20(&oneWire);

const uint8_t sensorCount = 4; // number of sensor
DS18B20Sensor sensors[sensorCount];

const unsigned long TEMPERATURE_READ_INTERVAL = 10000; // reading new data interval
unsigned long lastTemperatureRequestTime = 0;
bool conversionRequested = false;
const uint16_t CONVERSION_TIME = 750; // connection time

// ================================
// Convert String to Device Address
// Converts a string representation of a DS18B20 sensor address (e.g., "28:FF:12:34:56:78:9A:BC") to a DeviceAddress array
// - Validates each byte as a hexadecimal value (0-255)
// - Returns true on successful conversion, false on invalid format
// ================================
bool convertStringToDeviceAddress(const char *addressStr, DeviceAddress &deviceAddress)
{
    uint32_t currentTime = millis();
    Serial.printf("[Temperature][INFO][%lu] Converting address string: %s\n", currentTime, addressStr);

    char *ptr = (char *)addressStr;
    for (uint8_t i = 0; i < 8; i++)
    {
        if (*ptr == ':')
            ptr++;
        char hex[3] = {ptr[0], ptr[1], '\0'};
        char *end;
        long value = strtol(hex, &end, 16);

        if (end == hex || value < 0 || value > 255)
        {
            Serial.printf("[Temperature][ERROR][%lu] Invalid hex value in address: %s\n", currentTime, hex);
            return false;
        }
        deviceAddress[i] = (uint8_t)value;
        ptr += 2;
    }
    Serial.printf("[Temperature][INFO][%lu] Address conversion successful\n", currentTime);
    return true;
}

// ================================
// Initialize Sensors
// Initializes DS18B20 sensors by reading their addresses from NVS and verifying connections
// - Sets 12-bit resolution and async mode for the DallasTemperature library
// - Reads initial temperature values for each sensor
// - Logs success or failure for each sensor and overall initialization
// ================================
void initializeSensors()
{
    uint32_t currentTime = millis();
    Serial.printf("[Temperature][INFO][%lu] Starting sensor initialization\n", currentTime);

    Serial.printf("[Temperature][INFO][%lu] Beginning Dallas Temperature library\n", currentTime);
    ds18b20.begin();

    Serial.printf("[Temperature][INFO][%lu] Setting resolution to 12 bits\n", currentTime);
    ds18b20.setResolution(12);

    Serial.printf("[Temperature][INFO][%lu] Enabling async mode\n", currentTime);
    ds18b20.setWaitForConversion(false);

    const char *sensorNames[] = {"Inlet", "Outlet", "Antifreeze", "Filter"};
    StringIndex sensorIndexes[] = {INLET_SENSOR_ADDRESS, OUTLET_SENSOR_ADDRESS, ANTIFREEZE_SENSOR_ADDRESS, FILTER_SENSOR_ADDRESS};

    uint8_t successCount = 0;

    for (uint8_t i = 0; i < sensorCount; i++)
    {
        Serial.printf("[Temperature][INFO][%lu] Initializing sensor %d of %d (%s)\n", currentTime, i + 1, sensorCount, sensorNames[i]);

        char addressStr[STRING_MAX_LENGTH];

        Serial.printf("[Temperature][INFO][%lu] Reading address for sensor: %s\n", currentTime, sensorNames[i]);

        if (!getStringSetting(sensorIndexes[i], addressStr, STRING_MAX_LENGTH))
        {
            Serial.printf("[Temperature][ERROR][%lu] Failed to read address from settings for sensor: %s\n", currentTime, sensorNames[i]);
            continue;
        }

        if (!convertStringToDeviceAddress(addressStr, sensors[i].address))
        {
            Serial.printf("[Temperature][ERROR][%lu] Invalid address format for sensor: %s\n", currentTime, sensorNames[i]);
            continue;
        }

        sensors[i].name = sensorNames[i];

        Serial.printf("[Temperature][INFO][%lu] Checking connection for sensor: %s\n", currentTime, sensorNames[i]);

        if (!ds18b20.isConnected(sensors[i].address))
        {
            Serial.printf("[Temperature][ERROR][%lu] Sensor not connected: %s\n", currentTime, sensorNames[i]);
            continue;
        }

        char addressBuffer[24];
        int pos = 0;
        for (uint8_t j = 0; j < 8; j++)
        {
            if (j > 0)
                addressBuffer[pos++] = ':';
            pos += sprintf(&addressBuffer[pos], "%02X", sensors[i].address[j]);
        }
        addressBuffer[pos] = '\0';
        Serial.printf("[Temperature][INFO][%lu] Sensor %s initialized | Address: %s\n", currentTime, sensors[i].name, addressBuffer);

        successCount++;
    }

    Serial.printf("[Temperature][INFO][%lu] Initialization complete: %d/%d sensors initialized\n", currentTime, successCount, sensorCount);

    // get first temp
    Serial.printf("[Temperature][INFO][%lu] Reading initial values for all sensors\n", currentTime);
    ds18b20.requestTemperatures();
    delay(CONVERSION_TIME);

    for (uint8_t i = 0; i < sensorCount; i++)
    {
        float temperature = ds18b20.getTempC(sensors[i].address);

        if (temperature != DEVICE_DISCONNECTED_C && temperature > -55 && temperature < 125)
        {
            sensors[i].lastValidTemperature = temperature;
            sensors[i].lastReadTime = millis();
            Serial.printf("[Temperature][INFO][%lu] Sensor %s: %.2f°C\n", currentTime, sensors[i].name, temperature);
        }
        else
        {
            Serial.printf("[Temperature][ERROR][%lu] Failed to read initial value for sensor: %s\n", currentTime, sensors[i].name);
        }
    }
}

// ================================
// Handle Temperature Readings
// Manages periodic temperature readings for all DS18B20 sensors using async mode
// - Requests conversions every 15 seconds (TEMPERATURE_READ_INTERVAL)
// - Reads temperatures after 750ms (CONVERSION_TIME) and updates cache
// - Validates readings (not DEVICE_DISCONNECTED_C, within -55°C to 125°C, not NaN)
// - Logs valid and invalid readings, and tracks number of valid readings
// ================================
void handleTemperatureReadings()
{
    uint32_t currentTime = millis();

    // Request temperature conversion if it's time to do so
    if (!conversionRequested && (currentTime - lastTemperatureRequestTime >= TEMPERATURE_READ_INTERVAL))
    {
        Serial.printf("[Temperature][INFO][%lu] Requesting temperature conversion\n", currentTime);
        ds18b20.requestTemperatures();
        conversionRequested = true;
        lastTemperatureRequestTime = currentTime;
        return;
    }

    // Read the temperature values after conversion is complete
    if (conversionRequested && (currentTime - lastTemperatureRequestTime >= CONVERSION_TIME))
    {
        Serial.printf("[Temperature][INFO][%lu] Reading all sensors\n", currentTime);
        uint8_t validReadings = 0;

        // Loop through all sensors
        for (uint8_t i = 0; i < sensorCount; i++)
        {
            // Get the temperature reading from the sensor
            float temperature = ds18b20.getTempC(sensors[i].address);

            // Check if the reading is valid
            if (temperature != DEVICE_DISCONNECTED_C && temperature > -55 && temperature < 125 && !isnan(temperature))
            {
                Serial.printf("[Temperature][INFO][%lu] Sensor %s: %.2f°C\n", currentTime, sensors[i].name, temperature);
                sensors[i].lastValidTemperature = temperature;
                sensors[i].lastReadTime = currentTime;
                validReadings++;
            }
            else
            {
                Serial.printf("[Temperature][ERROR][%lu] Invalid reading for sensor %s: %.2f°C\n", currentTime, sensors[i].name, temperature);
                temperature = NAN;
                sensors[i].lastValidTemperature = temperature;
                sensors[i].lastReadTime = currentTime;
            }
        }

        Serial.printf("[Temperature][INFO][%lu] Valid readings: %d/%d\n", currentTime, validReadings, sensorCount);
        conversionRequested = false;
    }
}

// ================================
// Read Temperature by Name
// Retrieves temperature for a specific DS18B20 sensor by name
// - Returns cached value if recent (within 2x TEMPERATURE_READ_INTERVAL)
// - Requests new reading if cache is stale, waits 750ms for conversion
// - Validates reading (not DEVICE_DISCONNECTED_C, within -55°C to 125°C)
// - Returns NAN for invalid readings or if sensor not found
// ================================
float readTemperatureByName(String name)
{
    uint32_t currentTime = millis();
    Serial.printf("[Temperature][INFO][%lu] Reading temperature for sensor: %s\n", currentTime, name.c_str());

    for (uint8_t i = 0; i < sensorCount; i++)
    {
        if (String(sensors[i].name) == name)
        {
            if (currentTime - sensors[i].lastReadTime < TEMPERATURE_READ_INTERVAL * 2)
            {
                Serial.printf("[Temperature][INFO][%lu] Using cached value for sensor %s: %.2f°C\n", currentTime, name.c_str(), sensors[i].lastValidTemperature);
                return sensors[i].lastValidTemperature;
            }

            Serial.printf("[Temperature][INFO][%lu] Requesting new reading for sensor: %s\n", currentTime, name.c_str());
            ds18b20.requestTemperatures();
            delay(CONVERSION_TIME);

            float temperature = ds18b20.getTempC(sensors[i].address);

            if (temperature != DEVICE_DISCONNECTED_C && temperature > -55 && temperature < 125)
            {
                Serial.printf("[Temperature][INFO][%lu] Sensor %s: %.2f°C\n", currentTime, name.c_str(), temperature);
                sensors[i].lastValidTemperature = temperature;
                sensors[i].lastReadTime = currentTime;
                return temperature;
            }

            Serial.printf("[Temperature][ERROR][%lu] Invalid reading for sensor %s\n", currentTime, name.c_str());
            return NAN;
        }
    }

    Serial.printf("[Temperature][ERROR][%lu] Sensor not found: %s\n", currentTime, name.c_str());
    return NAN;
}

// ================================
// Detect DS18B20 Sensors
// Scans the OneWire bus to detect and count DS18B20 sensors
// - Validates each sensor with CRC check and device type (0x28 for DS18B20)
// - Logs detected sensors with their addresses
// - Returns the total number of valid DS18B20 sensors found
// ================================
int detectDS18B20Sensors(void)
{
    uint32_t currentTime = millis();
    OneWire oneWire(ONE_WIRE_BUS);
    int sensorCount = 0;
    byte addr[8];

    Serial.printf("[Temperature][INFO][%lu] Scanning for DS18B20 sensors\n", currentTime);

    // Reset the OneWire bus first
    oneWire.reset_search();
    delay(250);

    // Search for devices on the bus
    while (oneWire.search(addr))
    {
        // Check if address is valid
        if (OneWire::crc8(addr, 7) != addr[7])
        {
            Serial.printf("[Temperature][ERROR][%lu] Invalid CRC for sensor\n", currentTime);
            continue;
        }

        // Check if device is a DS18B20
        if (addr[0] != 0x28)
        {
            Serial.printf("[Temperature][ERROR][%lu] Device is not a DS18B20\n", currentTime);
            continue;
        }

        // Print device address
        char addressBuffer[24];
        int pos = 0;
        for (int i = 0; i < 8; i++)
        {
            if (i > 0)
                addressBuffer[pos++] = ':';
            pos += sprintf(&addressBuffer[pos], "%02X", addr[i]);
        }
        addressBuffer[pos] = '\0';
        Serial.printf("[Temperature][INFO][%lu] Sensor %d found | Address: %s\n", currentTime, sensorCount + 1, addressBuffer);

        sensorCount++;
    }

    Serial.printf("[Temperature][INFO][%lu] Total sensors found: %d\n", currentTime, sensorCount);
    return sensorCount;
}

// ================================
// Get First DS18B20 Address
// Scans the OneWire bus to find a new DS18B20 sensor not already stored in NVS
// - Validates sensor with CRC check and device type (0x28 for DS18B20)
// - Checks against existing addresses in NVS (Inlet, Outlet, Antifreeze, Filter)
// - Returns the first new sensor address as a string, or 0 if no new sensor is found
// - Requires buffer size of at least 24 characters for address string
// ================================
int getFirstDS18B20Address(char *addressStr, int maxLen)
{
    uint32_t currentTime = millis();
    if (maxLen < 24)
    { // Need at least 23 chars + null terminator
        Serial.printf("[Temperature][ERROR][%lu] Insufficient buffer size for address: %d\n", currentTime, maxLen);
        return 0;
    }

    OneWire oneWire(ONE_WIRE_BUS);
    byte addr[8];
    char existingAddr[24];
    bool found = false;

    Serial.printf("[Temperature][INFO][%lu] Scanning for DS18B20 sensors\n", currentTime);

    // Reset the OneWire bus first
    oneWire.reset_search();
    delay(250);

    // Get existing addresses from NVS
    bool hasInlet = getStringSetting(INLET_SENSOR_ADDRESS, existingAddr, sizeof(existingAddr));
    bool hasOutlet = getStringSetting(OUTLET_SENSOR_ADDRESS, existingAddr, sizeof(existingAddr));
    bool hasAntifreeze = getStringSetting(ANTIFREEZE_SENSOR_ADDRESS, existingAddr, sizeof(existingAddr));
    bool hasFilter = getStringSetting(FILTER_SENSOR_ADDRESS, existingAddr, sizeof(existingAddr));

    // Search for devices
    while (oneWire.search(addr))
    {
        // Check if address is valid
        if (OneWire::crc8(addr, 7) != addr[7])
        {
            Serial.printf("[Temperature][ERROR][%lu] Invalid CRC for sensor\n", currentTime);
            continue;
        }

        // Check if device is a DS18B20
        if (addr[0] != 0x28)
        {
            Serial.printf("[Temperature][ERROR][%lu] Device is not a DS18B20\n", currentTime);
            continue;
        }

        // Convert current address to string format
        char currentAddr[24];
        int pos = 0;
        for (int i = 0; i < 8; i++)
        {
            if (i > 0)
            {
                currentAddr[pos++] = ':';
            }
            pos += sprintf(&currentAddr[pos], "%02X", addr[i]);
        }
        currentAddr[pos] = '\0';

        // Check if this address is already stored in NVS
        bool isNewAddress = true;
        if (hasInlet)
        {
            getStringSetting(INLET_SENSOR_ADDRESS, existingAddr, sizeof(existingAddr));
            if (strcmp(currentAddr, existingAddr) == 0)
            {
                isNewAddress = false;
            }
        }
        if (hasOutlet)
        {
            getStringSetting(OUTLET_SENSOR_ADDRESS, existingAddr, sizeof(existingAddr));
            if (strcmp(currentAddr, existingAddr) == 0)
            {
                isNewAddress = false;
            }
        }
        if (hasAntifreeze)
        {
            getStringSetting(ANTIFREEZE_SENSOR_ADDRESS, existingAddr, sizeof(existingAddr));
            if (strcmp(currentAddr, existingAddr) == 0)
            {
                isNewAddress = false;
            }
        }
        if (hasFilter)
        {
            getStringSetting(FILTER_SENSOR_ADDRESS, existingAddr, sizeof(existingAddr));
            if (strcmp(currentAddr, existingAddr) == 0)
            {
                isNewAddress = false;
            }
        }

        // If this is a new address, return it
        if (isNewAddress)
        {
            strcpy(addressStr, currentAddr);
            Serial.printf("[Temperature][INFO][%lu] New sensor found | Address: %s\n", currentTime, addressStr);
            return 1;
        }
    }

    Serial.printf("[Temperature][WARN][%lu] No new sensors found\n", currentTime);
    return 0;
}