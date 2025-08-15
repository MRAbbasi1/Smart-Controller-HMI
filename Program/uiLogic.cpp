// uiLogic.cpp

// -----------------------------------
// UI Logic Module
// -----------------------------------

#include "uiLogic.h"

// ============================ Constants and Variables ============================

// Touch timeout management
static uint32_t lastTouchTime = 0;              // Last time the screen was touched
static const uint32_t timeoutDuration = 120000; // Timeout duration in milliseconds

// Main screen update intervals
static const uint32_t updateArcMainScreenInterval = 5000; // Update arc every 5 seconds
static uint32_t lastUpdateMainScreenArc = 0;              // Last arc update time

// Status check intervals
static const uint32_t DEVICE_CHECK_INTERVAL = 5000;    // Device status check every 5 seconds
static const uint32_t HIGH_TEMP_CHECK_INTERVAL = 5000; // High temp alarm check every 5 seconds
static const uint32_t PRESSURE_CHECK_INTERVAL = 5000;  // Pressure alarm check every 5 seconds
static const uint32_t DOOR_CHECK_INTERVAL = 5000;      // Door status check every 5 seconds
static const uint32_t RELAY_CHECK_INTERVAL = 5000;     // Relay status check every 5 seconds
static uint32_t lastDeviceCheckTime = 0;               // Last device status check
static uint32_t lastHighTempCheckTime = 0;             // Last high temp check
static uint32_t lastPressureCheckTime = 0;             // Last pressure check
static uint32_t lastDoorCheckTime = 0;                 // Last door status check
static uint32_t lastRelayCheckTime = 0;                // Last relay status check

// Status screen update intervals
static const uint32_t temperatureLabelsUpdateInterval = 10000; // Update temp labels every 10 seconds
static const uint32_t alarmLabelsUpdateInterval = 10000;       // Update alarm labels every 10 seconds
static const uint32_t relayLabelsUpdateInterval = 10000;       // Update relay labels every 10 seconds
static const uint32_t UPDATE_INTERVAL_Maintenance = 3600000;   // Update maintenance every 1 hour
static const uint32_t UPDATE_INTERVAL_Info = 12 * 3600000;     // Update info every 12 hours
static uint32_t lastUpdateTemperatureLabels = 0;               // Last temp labels update
static uint32_t lastUpdateAlarmLabels = 0;                     // Last alarm labels update
static uint32_t lastUpdateRelayLabels = 0;                     // Last relay labels update
static uint32_t lastMaintenanceUpdateTime = 0;                 // Last maintenance update
static uint32_t lastInfoUpdateTime = 0;                        // Last info update
static bool firstMaintenanceRun = true;                        // First maintenance run flag
static bool firstInfoRun = true;                               // First info run flag

// Device status variables
static bool isDeviceOn = false;                // Device status (true = ON, false = OFF)
static bool isHighTempAlarmActive = false;     // High temperature alarm status
static bool isHighPressureAlarmActive = false; // High pressure alarm status
static bool isDoorClosedStatus = false;        // Door status (true = closed, false = open)
static bool isCompressorRelayActive = false;   // Compressor relay status

// ============================ Touch Timeout Management ============================

uint32_t getLastTouchTime()
{
    return lastTouchTime;
}

uint32_t getTimeoutDuration()
{
    return timeoutDuration;
}

void updateLastTouchTime(uint32_t time)
{
    lastTouchTime = time;
}

/**
 * @brief Checks if any important UI container is visible.
 * @return True if any container is visible, false otherwise.
 */
bool isAnyContainerVisible()
{
    return !lv_obj_has_flag(ui_sensors_setup_container, LV_OBJ_FLAG_HIDDEN) ||
           !lv_obj_has_flag(ui_Sensor_Setup_main_Container_1, LV_OBJ_FLAG_HIDDEN) ||
           !lv_obj_has_flag(ui_Sensor_Setup_main_Container_2, LV_OBJ_FLAG_HIDDEN) ||
           !lv_obj_has_flag(ui_Sensor_Setup_main_Container_3, LV_OBJ_FLAG_HIDDEN) ||
           !lv_obj_has_flag(ui_Sensor_Setup_main_Container_4, LV_OBJ_FLAG_HIDDEN) ||
           !lv_obj_has_flag(ui_Sensor_Setup_main_Container_5, LV_OBJ_FLAG_HIDDEN) ||
           !lv_obj_has_flag(ui_Sensor_Setup_main_Container_6, LV_OBJ_FLAG_HIDDEN) ||
           !lv_obj_has_flag(ui_factory_reset_container, LV_OBJ_FLAG_HIDDEN);
}

/**
 * @brief Switches to the main screen and resets UI elements.
 */
void switchToMainScreen()
{
    lv_obj_t *currentScreen = lv_scr_act();
    if (currentScreen != ui_mainScreen && currentScreen != NULL)
    {
        lv_obj_t *screenToDelete = currentScreen;
        _ui_screen_delete(&screenToDelete);
    }

    _ui_screen_change(&ui_mainScreen, LV_SCR_LOAD_ANIM_NONE, 0, 0, NULL);

    // Reset UI elements
    lv_obj_add_flag(ui_tempStatusPanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_tempStatusButton, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_alarmStatusPanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_alarmStatusButton, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_relayStatusPanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_relayStatusButton, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_networkStatusPanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_networkStatusButton, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_deviceInfoPanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_serviceInfoButton, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_serviceInfoPanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_deviceInfoButton, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_sensors_setup_container, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_factory_reset_container, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_QRcode_Tab, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Hide_QR_Code_Button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_show_QR_Code_Button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_returnButton14, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_Advanced_Setting_Label, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_Setting_Save_btn_in_advanced_Screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_Setting_Save_btn_label_advanced_Screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_TabView1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_Sensor_Setup_Button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_Sensor_Setup_Button_Label, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_open_factory_reset_panel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_factory_reset_btn_Label, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_DEVICE_RESTART_Button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_DEVICE_RESTART_Button_Label, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_sensors_setup_container, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_Sensor_Setup_Notice_Container, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Sensor_Setup_main_Container_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Sensor_Setup_main_Container_2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Sensor_Setup_main_Container_3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Sensor_Setup_main_Container_4, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Sensor_Setup_main_Container_5, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Sensor_Setup_main_Container_6, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_factory_reset_container, LV_OBJ_FLAG_HIDDEN);

    Serial.println("[UI][INFO] Switched to main screen.");
}

// ============================ Main Screen Updates ============================

/**
 * @brief Updates temperature arcs on the main screen.
 */
static void updateArcMainScreen()
{
    if (lv_scr_act() != ui_mainScreen)
        return;

    uint32_t currentTime = millis();
    if (currentTime - lastUpdateMainScreenArc < updateArcMainScreenInterval)
        return;

    lastUpdateMainScreenArc = currentTime;

    float inletTemp = readTemperatureByName("Inlet");
    float outletTemp = readTemperatureByName("Outlet");
    char inletLabelText[32];
    char outletLabelText[32];

    // Update inlet arc and label
    if (!isnan(inletTemp) && inletTemp != DEVICE_DISCONNECTED_C && inletTemp > -55 && inletTemp < 125)
    {
        lv_arc_set_value(ui_inlet_Arc, static_cast<int>(inletTemp));
        snprintf(inletLabelText, sizeof(inletLabelText), "%.1f C°\n\nINLET", inletTemp);
        lv_obj_add_flag(ui_arc_danger_inlet, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][INFO][%lu] Inlet Temp: %.1f°C\n", currentTime, inletTemp);
    }
    else
    {
        lv_arc_set_value(ui_inlet_Arc, 0);
        snprintf(inletLabelText, sizeof(inletLabelText), "Error\n\nINLET");
        lv_obj_clear_flag(ui_arc_danger_inlet, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][ERROR][%lu] Inlet Temp: Invalid data\n", currentTime);
    }

    // Update outlet arc and label
    if (!isnan(outletTemp) && outletTemp != DEVICE_DISCONNECTED_C && outletTemp > -55 && outletTemp < 125)
    {
        lv_arc_set_value(ui_outlet_Arc, static_cast<int>(outletTemp));
        snprintf(outletLabelText, sizeof(outletLabelText), "%.1f C°\n\nOUTLET", outletTemp);
        lv_obj_add_flag(ui_arc_danger_outlet_, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][INFO][%lu] Outlet Temp: %.1f°C\n", currentTime, outletTemp);
    }
    else
    {
        lv_arc_set_value(ui_outlet_Arc, 0);
        snprintf(outletLabelText, sizeof(outletLabelText), "Error\n\nOUTLET");
        lv_obj_clear_flag(ui_arc_danger_outlet_, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][ERROR][%lu] Outlet Temp: Invalid data\n", currentTime);
    }

    lv_label_set_text(ui_inletMainsScreen, inletLabelText);
    lv_label_set_text(ui_outletMainsScreen, outletLabelText);
}

/**
 * @brief Updates compressor relay icons.
 */
static void updateCompressorIcons()
{
    if (isCompressorRelayActive)
    {
        lv_obj_clear_flag(ui_Compressor_ON_Icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Compressor_OFF_Icon, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_clear_flag(ui_Compressor_OFF_Icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Compressor_ON_Icon, LV_OBJ_FLAG_HIDDEN);
    }
}

/**
 * @brief Updates device status icons.
 */
static void updateDeviceIcons()
{
    if (isDeviceOn)
    {
        lv_obj_clear_flag(ui_Cooler_ON_Icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Cooler_OFF_Icon, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_clear_flag(ui_Cooler_OFF_Icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Cooler_ON_Icon, LV_OBJ_FLAG_HIDDEN);
    }
}

/**
 * @brief Updates temperature alarm icons.
 */
static void updateTempAlarmIcons()
{
    if (isHighTempAlarmActive)
    {
        lv_obj_clear_flag(ui_High_Temp_Icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Low_Temp_Icon, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_clear_flag(ui_Low_Temp_Icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_High_Temp_Icon, LV_OBJ_FLAG_HIDDEN);
    }
}

/**
 * @brief Updates pressure alarm icons.
 */
static void updatePressureAlarmIcons()
{
    if (isHighPressureAlarmActive)
    {
        lv_obj_clear_flag(ui_High_Pressure_Icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Low_Pressure_Icon, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_clear_flag(ui_Low_Pressure_Icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_High_Pressure_Icon, LV_OBJ_FLAG_HIDDEN);
    }
}

/**
 * @brief Updates door status icons.
 */
static void updateDoorIcons()
{
    if (isDoorClosedStatus)
    {
        lv_obj_clear_flag(ui_Door_Close_Icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Door_Open_Icon, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_clear_flag(ui_Door_Open_Icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Door_Close_Icon, LV_OBJ_FLAG_HIDDEN);
    }
}

/**
 * @brief Periodically checks device status.
 */
static void checkDeviceStatus()
{
    uint32_t currentTime = millis();
    if (currentTime - lastDeviceCheckTime < DEVICE_CHECK_INTERVAL)
        return;

    lastDeviceCheckTime = currentTime;
    isDeviceOn = getEvaporatorRelayStatus();
    updateDeviceIcons();
    Serial.printf("[UI][INFO][%lu] Device Status: %s\n", currentTime, isDeviceOn ? "ON" : "OFF");
}

/**
 * @brief Periodically checks high temperature alarm status.
 */
static void checkHighTempAlarmStatus()
{
    uint32_t currentTime = millis();
    if (currentTime - lastHighTempCheckTime < HIGH_TEMP_CHECK_INTERVAL)
        return;

    lastHighTempCheckTime = currentTime;
    isHighTempAlarmActive = isHighTempAlarm();
    updateTempAlarmIcons();
    Serial.printf("[UI][INFO][%lu] High Temp Alarm: %s\n", currentTime, isHighTempAlarmActive ? "Active" : "Inactive");
}

/**
 * @brief Periodically checks high pressure alarm status.
 */
static void checkPressureAlarmStatus()
{
    uint32_t currentTime = millis();
    if (currentTime - lastPressureCheckTime < PRESSURE_CHECK_INTERVAL)
        return;

    lastPressureCheckTime = currentTime;
    isHighPressureAlarmActive = isPressureHigh();
    updatePressureAlarmIcons();
    Serial.printf("[UI][INFO][%lu] High Pressure Alarm: %s\n", currentTime, isHighPressureAlarmActive ? "Active" : "Inactive");
}

/**
 * @brief Periodically checks door status.
 */
static void checkDoorStatus()
{
    uint32_t currentTime = millis();
    if (currentTime - lastDoorCheckTime < DOOR_CHECK_INTERVAL)
        return;

    lastDoorCheckTime = currentTime;
    isDoorClosedStatus = isDoorClosed();
    updateDoorIcons();
    Serial.printf("[UI][INFO][%lu] Door Status: %s\n", currentTime, isDoorClosedStatus ? "Closed" : "Open");
}

/**
 * @brief Periodically checks compressor relay status.
 */
static void checkRelayStatus()
{
    uint32_t currentTime = millis();
    if (currentTime - lastRelayCheckTime < RELAY_CHECK_INTERVAL)
        return;

    lastRelayCheckTime = currentTime;
    isCompressorRelayActive = getCompressorRelayStatus();
    updateCompressorIcons();
    Serial.printf("[UI][INFO][%lu] Compressor Relay: %s\n", currentTime, isCompressorRelayActive ? "ON" : "OFF");
}

/**
 * @brief Updates all UI elements on the main screen.
 */
void updateMainScreenUI()
{
    if (lv_scr_act() != ui_mainScreen)
        return;

    updateArcMainScreen();
    checkDeviceStatus();
    checkHighTempAlarmStatus();
    checkPressureAlarmStatus();
    checkDoorStatus();
    checkRelayStatus();
}

// ============================ Status Screen Updates ============================

/**
 * @brief Updates temperature labels on the status screen.
 */
static void updateTemperatureLabels()
{
    if (lv_scr_act() != ui_statusScreen || lv_obj_has_flag(ui_tempStatusPanel, LV_OBJ_FLAG_HIDDEN))
        return;

    uint32_t currentTime = millis();
    if (currentTime - lastUpdateTemperatureLabels < temperatureLabelsUpdateInterval)
        return;

    lastUpdateTemperatureLabels = currentTime;

    float inletTemp = readTemperatureByName("Inlet");
    float outletTemp = readTemperatureByName("Outlet");
    float antifreezeTemp = readTemperatureByName("Antifreeze");
    float filterTemp = readTemperatureByName("Filter");

    char buffer[32];
    // Inlet Temperature
    if (!isnan(inletTemp) && inletTemp != DEVICE_DISCONNECTED_C && inletTemp > -55 && inletTemp < 125)
    {
        snprintf(buffer, sizeof(buffer), "INLET: %.1f °C", inletTemp);
        lv_obj_add_flag(ui_inlet_temp_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][INFO][%lu] Status - Inlet Temp: %.1f°C\n", currentTime, inletTemp);
    }
    else
    {
        snprintf(buffer, sizeof(buffer), "INLET: NaN - Sensor Error!");
        lv_obj_clear_flag(ui_inlet_temp_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][ERROR][%lu] Status - Inlet Temp: Invalid data\n", currentTime);
    }
    lv_label_set_text(ui_Inlet_Temp_status, buffer);

    // Outlet Temperature
    if (!isnan(outletTemp) && outletTemp != DEVICE_DISCONNECTED_C && outletTemp > -55 && outletTemp < 125)
    {
        snprintf(buffer, sizeof(buffer), "OUTLET: %.1f °C", outletTemp);
        lv_obj_add_flag(ui_outlet_temp_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][INFO][%lu] Status - Outlet Temp: %.1f°C\n", currentTime, outletTemp);
    }
    else
    {
        snprintf(buffer, sizeof(buffer), "OUTLET: NaN - Sensor Error!");
        lv_obj_clear_flag(ui_outlet_temp_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][ERROR][%lu] Status - Outlet Temp: Invalid data\n", currentTime);
    }
    lv_label_set_text(ui_Outlet_Temp_status, buffer);

    // Antifreeze Temperature
    if (!isnan(antifreezeTemp) && antifreezeTemp != DEVICE_DISCONNECTED_C && antifreezeTemp > -55 && antifreezeTemp < 125)
    {
        snprintf(buffer, sizeof(buffer), "ANTIFREEZE: %.1f °C", antifreezeTemp);
        lv_obj_add_flag(ui_antifreeze_temp_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][INFO][%lu] Status - Antifreeze Temp: %.1f°C\n", currentTime, antifreezeTemp);
    }
    else
    {
        snprintf(buffer, sizeof(buffer), "ANTIFREEZE: NaN - Sensor Error!");
        lv_obj_clear_flag(ui_antifreeze_temp_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][ERROR][%lu] Status - Antifreeze Temp: Invalid data\n", currentTime);
    }
    lv_label_set_text(ui_antifreeze_temp_status, buffer);

    // Filter Temperature
    if (!isnan(filterTemp) && filterTemp != DEVICE_DISCONNECTED_C && filterTemp > -55 && filterTemp < 125)
    {
        snprintf(buffer, sizeof(buffer), "FILTER: %.1f °C", filterTemp);
        lv_obj_add_flag(ui_filter_temp_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][INFO][%lu] Status - Filter Temp: %.1f°C\n", currentTime, filterTemp);
    }
    else
    {
        snprintf(buffer, sizeof(buffer), "FILTER: NaN - Sensor Error!");
        lv_obj_clear_flag(ui_filter_temp_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][ERROR][%lu] Status - Filter Temp: Invalid data\n", currentTime);
    }
    lv_label_set_text(ui_fan_2_filter_alarm_status, buffer);
}

/**
 * @brief Updates alarm labels on the status screen.
 */
static void updateAlarmLabels()
{
    if (lv_scr_act() != ui_statusScreen || lv_obj_has_flag(ui_alarmStatusPanel, LV_OBJ_FLAG_HIDDEN))
        return;

    uint32_t currentTime = millis();
    if (currentTime - lastUpdateAlarmLabels < alarmLabelsUpdateInterval)
        return;

    lastUpdateAlarmLabels = currentTime;

    char buffer_temp[64];
    char buffer_filter[64];
    char buffer_door[64];
    char buffer_pressure[64];

    // High Temperature Alarm
    if (isHighTempAlarm())
    {
        float highTempAlarmInlet = readTemperatureByName("Inlet");
        if (!isnan(highTempAlarmInlet) && highTempAlarmInlet != DEVICE_DISCONNECTED_C && highTempAlarmInlet > -55 && highTempAlarmInlet < 125)
        {
            snprintf(buffer_temp, sizeof(buffer_temp), "TEMP: %.1f °C - High Temp!", highTempAlarmInlet);
            lv_obj_clear_flag(ui_high_temp_danger, LV_OBJ_FLAG_HIDDEN);
            Serial.printf("[UI][WARN][%lu] Status - High Temp Alarm: %.1f°C\n", currentTime, highTempAlarmInlet);
        }
        else
        {
            snprintf(buffer_temp, sizeof(buffer_temp), "TEMP: NaN - Sensor Error!");
            lv_obj_clear_flag(ui_high_temp_danger, LV_OBJ_FLAG_HIDDEN);
            Serial.printf("[UI][ERROR][%lu] Status - High Temp Alarm: Invalid data\n", currentTime);
        }
        lv_obj_set_style_text_color(ui_high_Temp_Alarm, lv_color_hex(0xFF0000), LV_PART_MAIN);
    }
    else
    {
        snprintf(buffer_temp, sizeof(buffer_temp), "TEMP: Within Safe Limits - OK!");
        lv_obj_set_style_text_color(ui_high_Temp_Alarm, lv_color_hex(0x00BE10), LV_PART_MAIN);
        lv_obj_add_flag(ui_high_temp_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][INFO][%lu] Status - High Temp Alarm: Within safe limits\n", currentTime);
    }
    lv_label_set_text(ui_high_Temp_Alarm, buffer_temp);

    // Filter Alarm
    if (isFilterWarning())
    {
        float highTempAlarmFilter = readTemperatureByName("Filter");
        if (!isnan(highTempAlarmFilter) && highTempAlarmFilter != DEVICE_DISCONNECTED_C && highTempAlarmFilter > -55 && highTempAlarmFilter < 125)
        {
            snprintf(buffer_filter, sizeof(buffer_filter), "FILTER: %.1f °C - Filter Warning!", highTempAlarmFilter);
            lv_obj_clear_flag(ui_filter_danger, LV_OBJ_FLAG_HIDDEN);
            Serial.printf("[UI][WARN][%lu] Status - Filter Alarm: %.1f°C\n", currentTime, highTempAlarmFilter);
        }
        else
        {
            snprintf(buffer_filter, sizeof(buffer_filter), "FILTER: NaN - Sensor Error!");
            lv_obj_clear_flag(ui_filter_danger, LV_OBJ_FLAG_HIDDEN);
            Serial.printf("[UI][ERROR][%lu] Status - Filter Alarm: Invalid data\n", currentTime);
        }
        lv_obj_set_style_text_color(ui_Filter_Alarm, lv_color_hex(0xFF0000), LV_PART_MAIN);
    }
    else
    {
        snprintf(buffer_filter, sizeof(buffer_filter), "FILTER: Operating Normally - Stable!");
        lv_obj_set_style_text_color(ui_Filter_Alarm, lv_color_hex(0x00BE10), LV_PART_MAIN);
        lv_obj_add_flag(ui_filter_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][INFO][%lu] Status - Filter Alarm: Normal\n", currentTime);
    }
    lv_label_set_text(ui_Filter_Alarm, buffer_filter);

    // Door Alarm
    if (!isDoorClosed())
    {
        snprintf(buffer_door, sizeof(buffer_door), "DOOR: Critical Warning - Open!");
        lv_obj_set_style_text_color(ui_Door_Alarm, lv_color_hex(0xFF0000), LV_PART_MAIN);
        lv_obj_clear_flag(ui_door_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][WARN][%lu] Status - Door Alarm: Open\n", currentTime);
    }
    else
    {
        snprintf(buffer_door, sizeof(buffer_door), "DOOR: Closed - OK!");
        lv_obj_set_style_text_color(ui_Door_Alarm, lv_color_hex(0x00BE10), LV_PART_MAIN);
        lv_obj_add_flag(ui_door_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][INFO][%lu] Status - Door Alarm: Closed\n", currentTime);
    }
    lv_label_set_text(ui_Door_Alarm, buffer_door);

    // Pressure Alarm
    if (isPressureHigh())
    {
        snprintf(buffer_pressure, sizeof(buffer_pressure), "PRESSURE: High - Warning!");
        lv_obj_set_style_text_color(ui_high_Pressure_Alarm, lv_color_hex(0xFF0000), LV_PART_MAIN);
        lv_obj_clear_flag(ui_high_pressure_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][WARN][%lu] Status - Pressure Alarm: High\n", currentTime);
    }
    else
    {
        snprintf(buffer_pressure, sizeof(buffer_pressure), "PRESSURE: Normal - Stable!");
        lv_obj_set_style_text_color(ui_high_Pressure_Alarm, lv_color_hex(0x00BE10), LV_PART_MAIN);
        lv_obj_add_flag(ui_high_pressure_danger, LV_OBJ_FLAG_HIDDEN);
        Serial.printf("[UI][INFO][%lu] Status - Pressure Alarm: Normal\n", currentTime);
    }
    lv_label_set_text(ui_high_Pressure_Alarm, buffer_pressure);
}

/**
 * @brief Updates relay status labels on the status screen.
 */
static void updateRelayLabels()
{
    if (lv_scr_act() != ui_statusScreen || lv_obj_has_flag(ui_relayStatusPanel, LV_OBJ_FLAG_HIDDEN))
        return;

    uint32_t currentTime = millis();
    if (currentTime - lastUpdateRelayLabels < relayLabelsUpdateInterval)
        return;

    lastUpdateRelayLabels = currentTime;

    char buffer_evaprator[32];
    char buffer_compressor[32];
    char buffer_condensor[32];
    char buffer_fan2[32];

    // Evaporator Status
    if (getEvaporatorRelayStatus())
    {
        snprintf(buffer_evaprator, sizeof(buffer_evaprator), "EVAPORATOR: ON - Working!");
        lv_obj_set_style_text_color(ui_evaprartor_Fan_Status, lv_color_hex(0x00BE10), LV_PART_MAIN);
        Serial.printf("[UI][INFO][%lu] Status - Evaporator: ON\n", currentTime);
    }
    else
    {
        snprintf(buffer_evaprator, sizeof(buffer_evaprator), "EVAPORATOR: OFF - Not Working!");
        lv_obj_set_style_text_color(ui_evaprartor_Fan_Status, lv_color_hex(0xFF0000), LV_PART_MAIN);
        Serial.printf("[UI][INFO][%lu] Status - Evaporator: OFF\n", currentTime);
    }
    lv_label_set_text(ui_evaprartor_Fan_Status, buffer_evaprator);

    // Compressor Status
    if (getCompressorRelayStatus())
    {
        snprintf(buffer_compressor, sizeof(buffer_compressor), "COMPRESSOR: ON - Working!");
        lv_obj_set_style_text_color(ui_Compressor_Status, lv_color_hex(0x00BE10), LV_PART_MAIN);
        Serial.printf("[UI][INFO][%lu] Status - Compressor: ON\n", currentTime);
    }
    else
    {
        snprintf(buffer_compressor, sizeof(buffer_compressor), "COMPRESSOR: OFF - Not Working!");
        lv_obj_set_style_text_color(ui_Compressor_Status, lv_color_hex(0xFF0000), LV_PART_MAIN);
        Serial.printf("[UI][INFO][%lu] Status - Compressor: OFF\n", currentTime);
    }
    lv_label_set_text(ui_Compressor_Status, buffer_compressor);

    // Condenser Status
    if (getCondenserRelayStatus())
    {
        snprintf(buffer_condensor, sizeof(buffer_condensor), "CONDENSER: ON - Working!");
        lv_obj_set_style_text_color(ui_condensor_Fan_1_Status, lv_color_hex(0x00BE10), LV_PART_MAIN);
        Serial.printf("[UI][INFO][%lu] Status - Condenser: ON\n", currentTime);
    }
    else
    {
        snprintf(buffer_condensor, sizeof(buffer_condensor), "CONDENSER: OFF - Not Working!");
        lv_obj_set_style_text_color(ui_condensor_Fan_1_Status, lv_color_hex(0xFF0000), LV_PART_MAIN);
        Serial.printf("[UI][INFO][%lu] Status - Condenser: OFF\n", currentTime);
    }
    lv_label_set_text(ui_condensor_Fan_1_Status, buffer_condensor);

    // Fan-2 Status
    if (getFan2RelayStatus())
    {
        snprintf(buffer_fan2, sizeof(buffer_fan2), "FAN-2: ON - Working!");
        lv_obj_set_style_text_color(ui_condensor_Fan_2_Status, lv_color_hex(0x00BE10), LV_PART_MAIN);
        Serial.printf("[UI][INFO][%lu] Status - Fan-2: ON\n", currentTime);
    }
    else
    {
        snprintf(buffer_fan2, sizeof(buffer_fan2), "FAN-2: OFF - Not Working!");
        lv_obj_set_style_text_color(ui_condensor_Fan_2_Status, lv_color_hex(0xFF0000), LV_PART_MAIN);
        Serial.printf("[UI][INFO][%lu] Status - Fan-2: OFF\n", currentTime);
    }
    lv_label_set_text(ui_condensor_Fan_2_Status, buffer_fan2);
}

/**
 * @brief Updates maintenance labels on the status screen.
 */
static void updateMaintenanceLabels()
{
    uint32_t currentTime = millis();
    if (!firstMaintenanceRun && (currentTime - lastMaintenanceUpdateTime < UPDATE_INTERVAL_Maintenance))
        return;

    firstMaintenanceRun = false;
    lastMaintenanceUpdateTime = currentTime;

    int serviceInterval = getNumericSetting(SERVICE_INTERVAL);
    int hoursElapsed = getNumericSetting(HOURS_ELAPSED);

    serviceInterval = (serviceInterval <= 0) ? 365 : serviceInterval;
    hoursElapsed = (hoursElapsed < 0 || hoursElapsed > 87600) ? 0 : hoursElapsed;

    int daysElapsed = hoursElapsed / 24;
    int remainingHours = hoursElapsed % 24;
    int daysRemaining = max(0, serviceInterval - daysElapsed);
    bool isServiceOverdue = daysRemaining <= 0;

    char buffer[128];
    if (!isServiceOverdue)
    {
        snprintf(buffer, sizeof(buffer), "SERVICES INTERVALS:\n %d Days %d Hours Elapsed - OK!", daysElapsed, remainingHours);
        Serial.printf("[UI][INFO][%lu] Maintenance: %d days elapsed, %d days remaining\n", currentTime, daysElapsed, daysRemaining);
    }
    else
    {
        snprintf(buffer, sizeof(buffer), "MAINTENANCE ALERT: %d Hours Overdue!\n                 Service Required!", hoursElapsed - (serviceInterval * 24));
        Serial.printf("[UI][WARN][%lu] Maintenance: Overdue by %d hours\n", currentTime, hoursElapsed - (serviceInterval * 24));
    }

    if (ui_servicesintervals != NULL)
    {
        lv_label_set_text(ui_servicesintervals, buffer);
        lv_obj_set_style_text_color(ui_servicesintervals, isServiceOverdue ? lv_color_hex(0xFF0000) : lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    }
}

/**
 * @brief Updates info labels on the status screen.
 */
static void updateInfoLabels()
{
    uint32_t currentTime = millis();
    if (!firstInfoRun && (currentTime - lastInfoUpdateTime < UPDATE_INTERVAL_Info))
        return;

    firstInfoRun = false;
    lastInfoUpdateTime = currentTime;

    int serialNumber = getNumericSetting(DEVICE_SERIAL_ID);
    int customerId = getNumericSetting(CUSTOMER_ID);
    int activationDate = getNumericSetting(ACTIVATION_DATE);

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "Serial Number: %d", serialNumber);
    lv_label_set_text(ui_serial_number, buffer);

    snprintf(buffer, sizeof(buffer), "Customer ID: %d", customerId);
    lv_label_set_text(ui_customerID, buffer);

    snprintf(buffer, sizeof(buffer), "Activation Date: %04d-%02d-%02d",
             activationDate / 10000, (activationDate % 10000) / 100, activationDate % 100);
    lv_label_set_text(ui_activationDate, buffer);

    Serial.printf("[UI][INFO][%lu] Info Updated - Serial: %d, Customer ID: %d, Activation: %04d-%02d-%02d\n",
                  currentTime, serialNumber, customerId,
                  activationDate / 10000, (activationDate % 10000) / 100, activationDate % 100);
}

/**
 * @brief Updates all UI elements on the status screen.
 */
void updateStatusScreenUI()
{
    updateTemperatureLabels();
    updateAlarmLabels();
    updateRelayLabels();
    updateMaintenanceLabels();
    updateInfoLabels();
}