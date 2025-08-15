// Program.ino
#include <Arduino.h>
#include "setting.h"
#include "display.h"
#include "WiFiManager.h"
#include "relayControl.h"
#include "tempSensor.h"
#include "alarm.h"
#include "general.h"
#include <esp_heap_caps.h>

// ================================
// System Monitoring Variables
// Tracks timing for periodic memory usage updates
// ================================
unsigned long lastMemoryUsageUpdateTime = 0;
const long MEMORY_USAGE_UPDATE_INTERVAL = 5000; // Interval for memory usage updates (ms)

// ================================
// Show Memory Usage
// Displays heap and PSRAM usage in KB
// - Logs free, total, and used memory for both heap and PSRAM
// - Warns if free heap falls below 10% of total
// ================================
void showMemoryUsage()
{
  uint32_t currentTime = millis();
  Serial.printf("[System][INFO][%lu] Memory Usage Report\n", currentTime);

  size_t freeHeap = ESP.getFreeHeap();
  size_t totalHeap = ESP.getHeapSize();
  size_t usedHeap = totalHeap - freeHeap;

  Serial.printf("[System][INFO][%lu] Free Heap: %.2f KB\n", currentTime, freeHeap / 1024.0);
  Serial.printf("[System][INFO][%lu] Total Heap: %.2f KB\n", currentTime, totalHeap / 1024.0);
  Serial.printf("[System][INFO][%lu] Used Heap: %.2f KB\n", currentTime, usedHeap / 1024.0);

  // Warn if free heap is less than 10% of total
  if (freeHeap < totalHeap * 0.1)
  {
    Serial.printf("[System][WARN][%lu] Low free heap: %.2f KB (<10%% of total)\n", currentTime, freeHeap / 1024.0);
  }

  size_t freePSRAM = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);
  size_t totalPSRAM = heap_caps_get_total_size(MALLOC_CAP_SPIRAM);
  size_t usedPSRAM = totalPSRAM - freePSRAM;

  Serial.printf("[System][INFO][%lu] Free PSRAM: %.2f KB\n", currentTime, freePSRAM / 1024.0);
  Serial.printf("[System][INFO][%lu] Total PSRAM: %.2f KB\n", currentTime, totalPSRAM / 1024.0);
  Serial.printf("[System][INFO][%lu] Used PSRAM: %.2f KB\n", currentTime, usedPSRAM / 1024.0);

  // Warn if free PSRAM is less than 10% of total (if PSRAM is available)
  if (totalPSRAM > 0 && freePSRAM < totalPSRAM * 0.1)
  {
    Serial.printf("[System][WARN][%lu] Low free PSRAM: %.2f KB (<10%% of total)\n", currentTime, freePSRAM / 1024.0);
  }
}

// ================================
// Setup Function
// Initializes all system components and modules
// - Configures serial, relays, display, settings, sensors, WiFi, alarms, time, and maintenance counter
// - Logs progress and errors for each initialization step
// ================================
void setup()
{
  uint32_t currentTime = millis();
  Serial.begin(115200);
  Serial.printf("[System][INFO][%lu] Starting system setup\n", currentTime);

  // Show initial memory usage
  showMemoryUsage();

  // Initialize settings (NVS)
  initializeSettings();
  Serial.printf("[System][INFO][%lu] NVS settings initialized\n", currentTime);

  // Initialize display
  displaySetup();
  Serial.printf("[System][INFO][%lu] Display initialized\n", currentTime);

  // Initialize sensors
  initializeSensors();
  Serial.printf("[System][INFO][%lu] Sensors initialized\n", currentTime);

  // Initialize alarm system
  alarmSetup();
  Serial.printf("[System][INFO][%lu] Alarm system initialized\n", currentTime);

  // Initialize relays
  setupRelays();
  Serial.printf("[System][INFO][%lu] Relays initialized\n", currentTime);

  // Initialize WiFi
  wifiSetup();
  Serial.printf("[System][INFO][%lu] WiFi initialized\n", currentTime);

  // Update system time
  setupAndUpdateTime();
  Serial.printf("[System][INFO][%lu] System time updated\n", currentTime);

  // Initialize maintenance counter
  initializeHoursElapsedTracking();
  Serial.printf("[System][INFO][%lu] Maintenance counter initialized\n", currentTime);

  Serial.printf("[System][INFO][%lu] Setup completed :) \n", currentTime);
}

// ================================
// Loop Function
// Main system loop to handle continuous operations
// - Updates display, WiFi, sensors, relays, maintenance counter, and memory usage
// - Periodic memory usage check every 5 seconds
// ================================
void loop()
{
  uint32_t currentTime = millis();

  displayLoop();               // Update display
  wifiLoop();                  // Handle WiFi connection
  handleTemperatureReadings(); // Read temperature sensors
  controlRelays();             // Control relays
  updateHoursElapsedCounter(); // Update maintenance counter

  // Periodic memory usage check
  if (currentTime - lastMemoryUsageUpdateTime >= MEMORY_USAGE_UPDATE_INTERVAL)
  {
    lastMemoryUsageUpdateTime = currentTime;
    showMemoryUsage();
  }
}