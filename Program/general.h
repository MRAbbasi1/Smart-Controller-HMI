// general.h

#ifndef GENERAL_H
#define GENERAL_H

#include <Arduino.h>
#include <time.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Setup and update time
void setupAndUpdateTime();

// Get the current time
String getTime();

void initializeHoursElapsedTracking();
void updateHoursElapsedCounter();

#endif // GENERAL_H