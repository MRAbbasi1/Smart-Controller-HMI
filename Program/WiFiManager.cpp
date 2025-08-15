// WiFiManager.cpp
// -----------------------------------
// Wi-Fi Management Module
// -----------------------------------

#include "WiFiManager.h"
#include "setting.h" // For NVS settings
#include <WiFi.h>

// =====================================================================
// Internal Variables
// =====================================================================
static unsigned long lastReconnectAttempt = 0; // Stores the timestamp of the last reconnect attempt
static bool wasConnected = false;              // Tracks the previous connection state to detect changes
static bool skipMonitoringLogged = false;      // Tracks if a log has been printed when monitoring is skipped

// =====================================================================
// Helper Function: Check if a string is "0"
// =====================================================================
/**
 * Checks whether the provided string is set to "0".
 *
 * This is primarily used to verify if stored credentials (e.g., SSID or password)
 * have been cleared or are invalid.
 *
 * @param str Pointer to the string to check.
 * @return `true` if the string is "0", otherwise `false`.
 */
bool isZeroString(const char *str)
{
    return (strcmp(str, "0") == 0);
}

// =====================================================================
// Wi-Fi Setup Function
// =====================================================================
/**
 * Initializes and connects the ESP32 to a Wi-Fi network based on stored credentials.
 *
 * Steps:
 * 1. Retrieve stored SSID and password from NVS.
 * 2. Validate the credentials (ensure they are not set to "0").
 * 3. Scan for available networks to confirm that the target SSID is within range.
 * 4. Attempt to connect to the specified Wi-Fi network.
 *
 * Notes:
 * - Adds a small delay to ensure NVS and Wi-Fi modules are initialized properly.
 * - Skips connection attempts if credentials are invalid or the target SSID is not found.
 */
void wifiSetup()
{
    uint32_t currentTime = millis();
    Serial.printf("[WiFi][INFO][%lu] Starting Wi-Fi setup\n", currentTime);

    // Step 1: Retrieve SSID and Password from NVS
    char ssid[STRING_MAX_LENGTH];
    char password[STRING_MAX_LENGTH];

    if (!getStringSetting(WIFI_SSID, ssid, STRING_MAX_LENGTH) ||
        !getStringSetting(WIFI_PASSWORD, password, STRING_MAX_LENGTH))
    {
        Serial.printf("[WiFi][ERROR][%lu] Failed to retrieve credentials from NVS\n", currentTime);
        return;
    }

    // Step 2: Validate credentials
    if (isZeroString(ssid) || isZeroString(password))
    {
        Serial.printf("[WiFi][WARN][%lu] Credentials set to '0'. Skipping Wi-Fi setup\n", currentTime);
        return;
    }

    // Step 3: Initialize Wi-Fi
    WiFi.disconnect(true); // Reset any previous Wi-Fi configuration
    WiFi.mode(WIFI_STA);   // Set Wi-Fi to station mode

    Serial.printf("[WiFi][INFO][%lu] Scanning for available networks\n", currentTime);

    delay(500); // Allow some time before scanning

    // Step 4: Scan for target SSID
    int networksFound = WiFi.scanNetworks();
    bool ssidFound = false;
    for (int i = 0; i < networksFound; i++)
    {
        if (WiFi.SSID(i).equals(ssid))
        {
            ssidFound = true;
            break;
        }
    }

    if (!ssidFound)
    {
        Serial.printf("[WiFi][WARN][%lu] Target SSID not found. Skipping connection attempt\n", currentTime);
        return;
    }

    // Step 5: Attempt connection to Wi-Fi
    Serial.printf("[WiFi][INFO][%lu] Connecting to SSID: %s\n", currentTime, ssid);

    WiFi.begin(ssid, password);

    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 15000)
    {
        delay(500);
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.printf("\n[WiFi][INFO][%lu] Connected successfully, IP Address: %s\n", millis(), WiFi.localIP().toString().c_str());
    }
    else
    {
        Serial.printf("\n[WiFi][ERROR][%lu] Failed to connect to SSID: %s\n", millis(), ssid);
    }

    Serial.printf("[WiFi][INFO][%lu] Wi-Fi setup complete\n", millis());
}

// =====================================================================
// Wi-Fi Loop Function with Proper Temp Flag Handling
// =====================================================================
/**
 * Periodically checks the Wi-Fi connection status and attempts to reconnect if disconnected.
 * Uses Temporary flags to control NVS reads.
 */
void wifiLoop()
{
    static unsigned long lastCheckTime = 0;        // Tracks the last time the loop was executed
    const unsigned long CHECK_INTERVAL = 120000;   // Interval for checking (in seconds)
    static char ssid[STRING_MAX_LENGTH] = {0};     // Cached SSID
    static char password[STRING_MAX_LENGTH] = {0}; // Cached Password

    // Ensure the loop runs only every CHECK_INTERVAL
    if (millis() - lastCheckTime < CHECK_INTERVAL)
        return;

    lastCheckTime = millis();
    uint32_t currentTime = lastCheckTime;

    // ---------------------------------------------------
    // Step 1: Check Wi-Fi Connection Status
    // ---------------------------------------------------
    if (WiFi.status() == WL_CONNECTED)
    {
        if (!wasConnected) // Detect a new connection
        {
            Serial.printf("[WiFi][INFO][%lu] Connected to SSID: %s, IP Address: %s\n",
                          currentTime, WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
            wasConnected = true; // Update connection state
        }
        return; // Exit if already connected
    }

    // ---------------------------------------------------
    // Step 2: If Disconnected, Check Temporary Flags
    // ---------------------------------------------------
    wasConnected = false;

    Serial.printf("[WiFi][WARN][%lu] Disconnected. Checking NVS and attempting reconnection\n", currentTime);

    // Check Temporary Flags to Decide NVS Access
    bool ssidFlagTemp = getChangedFlagTemp("string", WIFI_SSID);
    bool passwordFlagTemp = getChangedFlagTemp("string", WIFI_PASSWORD);

    // Reload credentials from NVS only if Temp flags are true
    if (ssidFlagTemp || passwordFlagTemp)
    {
        getStringSetting(WIFI_SSID, ssid, STRING_MAX_LENGTH);
        getStringSetting(WIFI_PASSWORD, password, STRING_MAX_LENGTH);

        // Reset Temporary Flags after reading NVS
        if (resetChangedFlagTemp("string", WIFI_SSID))
        {
            Serial.printf("[WiFi][INFO][%lu] Temporary flag for SSID reset\n", currentTime);
        }
        if (resetChangedFlagTemp("string", WIFI_PASSWORD))
        {
            Serial.printf("[WiFi][INFO][%lu] Temporary flag for Password reset\n", currentTime);
        }
        Serial.printf("[WiFi][INFO][%lu] Credentials reloaded from NVS\n", currentTime);
    }

    // Validate credentials
    if (isZeroString(ssid) || isZeroString(password))
    {
        Serial.printf("[WiFi][WARN][%lu] Invalid credentials in NVS. Skipping reconnection\n", currentTime);
        return; // Skip the process if credentials are invalid
    }

    // ---------------------------------------------------
    // Step 3: Scan Available Networks (Non-blocking)
    // ---------------------------------------------------
    Serial.printf("[WiFi][INFO][%lu] Initiating non-blocking scan for available networks\n", currentTime);

    // Start asynchronous scan
    if (WiFi.scanComplete() == -2)
    {
        WiFi.scanNetworks(true); // Start scan in non-blocking mode
        return;                  // Exit until the scan is complete
    }

    int networksFound = WiFi.scanComplete();
    if (networksFound == -1)
    {
        Serial.printf("[WiFi][INFO][%lu] Scan in progress\n", currentTime);
        return; // Exit if scan is still running
    }

    bool ssidFound = false;
    for (int i = 0; i < networksFound; i++)
    {
        if (WiFi.SSID(i).equals(ssid))
        {
            ssidFound = true; // SSID found
            break;
        }
    }

    // Free memory used by the scan results
    WiFi.scanDelete();

    if (!ssidFound)
    {
        Serial.printf("[WiFi][WARN][%lu] Target SSID not found. Retrying in next cycle\n", currentTime);
        return; // Skip connection attempt if SSID is not found
    }

    // ---------------------------------------------------
    // Step 4: Attempt to Connect to Wi-Fi
    // ---------------------------------------------------
    Serial.printf("[WiFi][INFO][%lu] Attempting to connect to SSID: %s\n", currentTime, ssid);

    WiFi.begin(ssid, password);

    // Wait for up to 5 seconds to establish a connection
    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 5000)
    {
        delay(500); // Short delay to avoid excessive looping
        Serial.print(".");
    }

    // ---------------------------------------------------
    // Step 5: Log Connection Status
    // ---------------------------------------------------
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.printf("\n[WiFi][INFO][%lu] Connected successfully, IP Address: %s\n", millis(), WiFi.localIP().toString().c_str());
    }
    else
    {
        Serial.printf("\n[WiFi][ERROR][%lu] Failed to connect to SSID: %s\n", millis(), ssid);
    }
}

// =====================================================================
// Wi-Fi Disconnect Function
// =====================================================================
/**
 * Disconnects from the current Wi-Fi network and clears stored credentials.
 *
 * This function:
 * 1. Disconnects the ESP32 from the currently connected Wi-Fi network.
 * 2. Erases Wi-Fi credentials from the chip memory.
 * 3. Updates the settings storage (e.g., NVS or JSON) to reflect cleared credentials.
 */
void wifiDisconnect()
{
    uint32_t currentTime = millis();
    Serial.printf("[WiFi][INFO][%lu] Disconnecting from Wi-Fi\n", currentTime);

    WiFi.disconnect(true);                // Disconnect from Wi-Fi and erase credentials from flash memory
    setStringSetting(WIFI_SSID, "0");     // Clear the stored SSID
    setStringSetting(WIFI_PASSWORD, "0"); // Clear the stored password

    Serial.printf("[WiFi][INFO][%lu] Disconnected and credentials cleared\n", currentTime);
}

// =====================================================================
// Helper Function: Check Wi-Fi Connection
// =====================================================================
/**
 * Checks if the device is connected to a Wi-Fi network.
 *
 * This function:
 * 1. Verifies the Wi-Fi connection status using `WiFi.status()`.
 * 2. If connected:
 *    - Optionally copies the connected SSID to the provided buffer (`connectedSSID`).
 * 3. If not connected:
 *    - Clears the `connectedSSID` buffer (if provided) and returns `false`.
 *
 * @param connectedSSID (Optional) Pointer to a buffer for storing the SSID of the connected network.
 * @param maxLength Maximum length of the buffer provided for the SSID (including null-terminator).
 * @return `true` if connected to a Wi-Fi network, otherwise `false`.
 */
bool wifiIsConnected(char *connectedSSID = nullptr, size_t maxLength = 0)
{
    uint32_t currentTime = millis();
    wl_status_t status = WiFi.status(); // Check Wi-Fi connection status
    if (status == WL_CONNECTED)
    {
        // If a buffer is provided, copy the SSID into it
        if (connectedSSID != nullptr && maxLength > 0)
        {
            strncpy(connectedSSID, WiFi.SSID().c_str(), maxLength - 1);
            connectedSSID[maxLength - 1] = '\0'; // Ensure null-termination
        }
        Serial.printf("[WiFi][INFO][%lu] Connected to SSID: %s\n", currentTime, WiFi.SSID().c_str());
        return true;
    }

    // Clear the buffer if provided, since the connection is not active
    if (connectedSSID != nullptr && maxLength > 0)
    {
        connectedSSID[0] = '\0';
    }
    Serial.printf("[WiFi][WARN][%lu] Not connected to any network\n", currentTime);
    return false;
}

// =====================================================================
// Test Available Wi-Fi Networks
// =====================================================================
/**
 * Scans available Wi-Fi networks and sorts them by signal strength (RSSI).
 *
 * This function:
 * 1. Performs a scan of available Wi-Fi networks using `WiFi.scanNetworks()`.
 * 2. Retrieves the SSID and RSSI of each network.
 * 3. Sorts the networks in descending order based on RSSI (strongest signals first).
 * 4. Prints the top networks (up to `MAX_NETWORKS`) to the Serial Monitor.
 */
void scanWiFiNetworks()
{
    uint32_t currentTime = millis();
    Serial.printf("[WiFi][INFO][%lu] Starting Wi-Fi network scan\n", currentTime);

    // Scan for available networks
    int numNetworks = WiFi.scanNetworks();
    if (numNetworks <= 0)
    {
        Serial.printf("[WiFi][WARN][%lu] No networks found\n", currentTime);
        return;
    }

    Serial.printf("[WiFi][INFO][%lu] Found %d networks\n", currentTime, numNetworks);

    // Create arrays to store SSID and RSSI
    String ssidList[numNetworks];
    int rssiList[numNetworks];

    // Collect SSID and RSSI values
    for (int i = 0; i < numNetworks; i++)
    {
        ssidList[i] = WiFi.SSID(i);
        rssiList[i] = WiFi.RSSI(i);
    }

    // Sort networks in-place by RSSI (descending order) using Bubble Sort
    for (int i = 0; i < numNetworks - 1; i++)
    {
        for (int j = 0; j < numNetworks - i - 1; j++)
        {
            if (rssiList[j] < rssiList[j + 1])
            {
                // Swap RSSI
                int tempRssi = rssiList[j];
                rssiList[j] = rssiList[j + 1];
                rssiList[j + 1] = tempRssi;

                // Swap SSID
                String tempSsid = ssidList[j];
                ssidList[j] = ssidList[j + 1];
                ssidList[j + 1] = tempSsid;
            }
        }
    }

    // Print the top networks (up to MAX_NETWORKS)
    for (int i = 0; i < min(numNetworks, MAX_NETWORKS); i++)
    {
        Serial.printf("[WiFi][INFO][%lu] SSID: %s, RSSI: %d\n", currentTime, ssidList[i].c_str(), rssiList[i]);
    }

    Serial.printf("[WiFi][INFO][%lu] Network scan complete\n", currentTime);
}