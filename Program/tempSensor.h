// tempSensor.h

#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Define DS18B20 sensor structure
struct DS18B20Sensor
{
    const char *name;
    DeviceAddress address;
    float lastValidTemperature;
    unsigned long lastReadTime;
};

// Declare global variables for sensors
extern DS18B20Sensor sensors[];   // Array of DS18B20 sensors
extern const uint8_t sensorCount; // Number of sensors

// Function prototypes
void initializeSensors();                 // Function to initialize all sensors
void handleTemperatureReadings();         // Function to handle continuous temperature readings
float readTemperatureByName(String name); // Function to read temperature from a sensor by name

#ifdef __cplusplus
extern "C"
{
#endif

    int detectDS18B20Sensors(void); // Function to detect and count DS18B20 sensors

    int getFirstDS18B20Address(char *addressStr, int maxLen); // sensor setup function with ui

#ifdef __cplusplus
}
#endif

#endif