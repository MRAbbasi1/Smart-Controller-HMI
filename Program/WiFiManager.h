#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

// Maximum length for strings (SSID and password)
#define STRING_MAX_LENGTH 64

// Maximum number of networks to store
#define MAX_NETWORKS 7

// Maximum SSID Scan length
#define MAX_SSID_LENGTH 32

/**
 * @brief Structure to store Wi-Fi network details.
 */
struct WiFiNetwork
{
    char ssid[MAX_SSID_LENGTH];
    int rssi; // Signal strength
};

// Global array to store scanned networks
extern WiFiNetwork networks[MAX_NETWORKS];

// Wi-Fi functions
void wifiSetup();                                            // Initialize Wi-Fi connection
void wifiLoop();                                             // Monitor Wi-Fi connection
void wifiDisconnect();                                       // Disconnect from Wi-Fi and clear credentials
bool wifiIsConnected(char *connectedSSID, size_t maxLength); // Check if Wi-Fi is connected and get the connected SSID
void scanWiFiNetworks();                                     // Scan for Wi-Fi networks

#endif // WIFI_H