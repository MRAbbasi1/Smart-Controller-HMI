// relayControl.h
#ifndef RELAY_CONTROL_H
#define RELAY_CONTROL_H

// ================================
// Library Includes
// ================================
#include <Arduino.h>
#include <Wire.h> // I2C communication library
#include "alarm.h"
#include "setting.h"
#include "tempSensor.h"

// ================================
// I2C Address and Pin Definitions
// Defines I2C address for PCF8574 and pin mappings for relays
// ================================
#define PCF8574_ADDRESS 0x21   // Base I2C address for PCF8574 (configurable via jumper)
#define COMPRESSOR_RELAY_PIN 0 // P0 for compressor relay
#define EVAPORATOR_RELAY_PIN 1 // P1 for evaporator relay
#define CONDENSER_RELAY_PIN 2  // P2 for condenser relay
#define FAN2_RELAY_PIN 3       // P3 for fan2 relay

// ================================
// Function Prototypes
// ================================
void setupRelays();                         // Initializes PCF8574 and loads initial settings
void controlRelays();                       // Main control loop for periodic relay updates
void reloadCachedData();                    // Refreshes cached settings and sensor data from NVS
void controlEvaporatorRelay();              // Controls evaporator relay based on general conditions
void controlCompressorAndCondenserRelays(); // Controls compressor and condenser relays with hysteresis
void controlFan2Relay();                    // Controls fan2 relay based on temperature threshold

bool getCompressorRelayStatus(); // Returns current state of compressor relay
bool getEvaporatorRelayStatus(); // Returns current state of evaporator relay
bool getCondenserRelayStatus();  // Returns current state of condenser relay
bool getFan2RelayStatus();       // Returns current state of fan2 relay

#endif // RELAY_CONTROL_H