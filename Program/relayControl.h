// relayControl.h
#ifndef RELAY_CONTROL_H
#define RELAY_CONTROL_H

#include <Arduino.h>
#include "alarm.h"
#include "setting.h"
#include "tempSensor.h"

// ================================
// Pin Definitions
// Defines GPIO pins for relay control (active-low configuration)
// ================================
#define COMPRESSOR_RELAY_PIN 38 // GPIO pin for compressor relay
#define EVAPORATOR_RELAY_PIN 37 // GPIO pin for evaporator relay
#define CONDENSER_RELAY_PIN 35  // GPIO pin for condenser relay
#define FAN2_RELAY_PIN 36       // GPIO pin for fan2 relay

// ================================
// Function Prototypes
// Declares functions for relay initialization, control, and status retrieval
// ================================
void setupRelays();                         // Initializes relay pins and loads initial settings
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