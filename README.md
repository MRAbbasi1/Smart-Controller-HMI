# SmartController

## Overview

SmartController is an advanced IoT temperature control and monitoring system built on the ESP32-S3 platform. The system provides precise temperature control, monitoring, and management capabilities for refrigeration and cooling applications.

### Key Features

- Real-time temperature monitoring via multiple DS18B20 sensors
- Intelligent relay control for compressor, evaporator, condenser and auxiliary fan
- Advanced safety features including door monitoring and pressure sensing
- WiFi connectivity with dynamic network configuration
- Built-in display interface using ILI9341 2.8" screen
- NVS (Non-Volatile Storage) based settings management
- Comprehensive system monitoring and logging

## Hardware Requirements

### Core Components

- ESP32-S3-WROOM-1-N8R2 microcontroller
- ILI9341 V1.2 2.8" TFT Display
- DS18B20 Temperature Sensors (x4)
- Relay Module (x4)
- Door Sensor
- Pressure Sensor
- RGB LED (Builtin)

### Pin Configuration

#### Display (ILI9341_V1.2)

```
VCC     -> 3.3V
LED     -> 3.3V
GND     -> GND
CS      -> GPIO 9
RESET   -> GPIO 8
DC      -> GPIO 3
MOSI    -> GPIO 11
SCLK    -> GPIO 12
MISO    -> GPIO 13
T_CLK   -> GPIO 12
T_CS    -> GPIO 18
T_DIN   -> GPIO 11
T_DO    -> GPIO 13
```

#### Sensors & Controls

```
Temperature Sensors (OneWire Pull UP 4.7K Resistor) -> GPIO 4
Door Sensor                                         -> GPIO 1
Pressure Sensor                                     -> GPIO 2
RGB LED                                             -> GPIO 48
```

#### Relay Pins

```
Compressor Relay  -> GPIO 38
Evaporator Relay  -> GPIO 37
Condenser Relay   -> GPIO 35
Fan2 Relay        -> GPIO 36
```

## Software Architecture

### Core Modules

1. **Program.ino**

   - Main program entry point
   - System initialization and loop management
   - Memory usage monitoring

2. **WiFiManager**

   - WiFi connection handling
   - Network scanning and management
   - Connection state monitoring

3. **RelayControl**

   - Intelligent relay state management
   - Temperature-based control logic
   - Safety interlocks and timing controls

4. **TempSensor**

   - DS18B20 sensor interface
   - Temperature reading and validation
   - Sensor address management

5. **Settings**

   - NVS-based configuration storage
   - Parameter validation
   - Change tracking system

6. **Alarm**
   - Safety monitoring system
   - Door and pressure monitoring
   - Temperature threshold alarms

### Key Features Implementation

#### Temperature Control System

- Compressor control with hysteresis
- Anti-freeze protection
- Filter temperature monitoring
- Multi-sensor temperature tracking

#### Safety Features

- Door state monitoring
- Pressure monitoring
- Filter condition monitoring
- Compressor rest time management

#### Configuration Management

- Persistent settings storage in NVS
- Parameter validation
- Default value management
- Change tracking system

## Building and Flashing

### Prerequisites

1. Arduino IDE with ESP32 support
2. Required Libraries:
   - Adafruit_NeoPixel
   - OneWire
   - DallasTemperature
   - ArduinoJson
   - WiFi
   - HTTPClient

### Build Steps

1. Clone the repository
2. Open `Program.ino` in Arduino IDE
3. Select ESP32-S3 board in board manager
4. Install required libraries
5. Compile and upload

## Configuration

### Initial Setup

1. Power on the device
2. Set temperature thresholds and operating parameters through the UI
3. Configure sensor addresses, if you need add new sensors

### Key Parameters

- Compressor temperature range
- Anti-freeze thresholds
- Fan control temperatures
- Service intervals
- Safety timeout values

## Operation Guide

### Normal Operation

1. Device automatically maintains temperature based on settings
2. Display shows current status and temperatures
3. RGB LED indicates system state
4. Automatic safety monitoring

### Maintenance

1. Regular filter monitoring
2. Temperature sensor validation
3. Door seal verification
4. Pressure system checks

## Troubleshooting

### Common Issues

1. Temperature Sensor Errors

   - Check sensor connections
   - Verify sensor addresses
   - Monitor serial logs

2. Relay Control Issues

   - Check relay connections
   - Verify temperature thresholds
   - Check safety interlocks

3. WiFi Connection Problems
   - Verify credentials
   - Check signal strength
   - Monitor connection logs

### Debug Information

- Serial monitoring at 115200 baud
- Detailed logging of system states
- Memory usage monitoring
- Temperature and relay state logging
