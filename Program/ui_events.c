// ui_events.c

// Include system and standard libraries
#include <stdio.h>
#include "esp_system.h"
#include <Arduino.h>

// Include project and module-specific libraries
#include "ui.h"
#include "setting.h"

void mainScreen(lv_event_t *e)
{
	// Attach event handlers for value updates
	lv_obj_add_event_cb(ui_inlet_Arc, ui_event_inlet_Arc, LV_EVENT_VALUE_CHANGED, NULL);
	lv_obj_add_event_cb(ui_outlet_Arc, ui_event_outlet_Arc, LV_EVENT_VALUE_CHANGED, NULL);
}

void settingScreen(lv_event_t *e)
{
	// turnOffCtrl btn
	bool deviceOnStateForBtn;
	deviceOnStateForBtn = getBooleanSetting(DEVICE_ON);

	if (deviceOnStateForBtn)
	{
		lv_obj_add_state(ui_TurnOffCTRL, LV_STATE_CHECKED); // btn checked

		lv_obj_clear_flag(ui_COOLER_IS__ON, LV_OBJ_FLAG_HIDDEN); // unhide COOLER_IS__ON
		lv_obj_add_flag(ui_COOLER_IS__OFF, LV_OBJ_FLAG_HIDDEN);	 // hide COOLER_IS__OFF
	}
	else
	{
		lv_obj_clear_state(ui_TurnOffCTRL, LV_STATE_CHECKED); // btn unchecked

		lv_obj_clear_flag(ui_COOLER_IS__OFF, LV_OBJ_FLAG_HIDDEN); // unhide COOLER_IS__OFF
	}
}

lv_timer_t *coolerStatusTimer = NULL;

void showCoolerStatusOn(lv_timer_t *timer)
{
	// Hide the "COOLER IS : OFF" label
	lv_obj_add_flag(ui_COOLER_IS__OFF, LV_OBJ_FLAG_HIDDEN);

	// Update text and show the "COOLER IS : ON" label
	lv_label_set_text(ui_COOLER_IS__ON, "COOLER IS : ON");
	lv_obj_clear_flag(ui_COOLER_IS__ON, LV_OBJ_FLAG_HIDDEN);

	// Delete the timer
	lv_timer_del(timer);
	coolerStatusTimer = NULL;
}

void showCoolerStatusOff(lv_timer_t *timer)
{
	// Hide the "COOLER IS : ON" label
	lv_obj_add_flag(ui_COOLER_IS__ON, LV_OBJ_FLAG_HIDDEN);

	// Update text and show the "COOLER IS : OFF" label
	lv_label_set_text(ui_COOLER_IS__OFF, "COOLER IS : OFF");
	lv_obj_clear_flag(ui_COOLER_IS__OFF, LV_OBJ_FLAG_HIDDEN);

	// Delete the timer
	lv_timer_del(timer);
	coolerStatusTimer = NULL;
}

void turnOffCtrl_Checked(lv_event_t *e)
{
	// Store device state as ON
	setBooleanSetting(DEVICE_ON, true);

	// Hide the "COOLER IS : OFF" label
	lv_obj_add_flag(ui_COOLER_IS__OFF, LV_OBJ_FLAG_HIDDEN);

	// Set New label: "TURNING ON..."
	lv_label_set_text(ui_COOLER_IS__ON, "TURNING ON...");
	lv_obj_clear_flag(ui_COOLER_IS__ON, LV_OBJ_FLAG_HIDDEN);

	// If a previous timer exists, delete it before creating a new one
	if (coolerStatusTimer != NULL)
	{
		lv_timer_del(coolerStatusTimer);
		coolerStatusTimer = NULL;
	}

	// Create a new timer to update the final status after 7 seconds
	coolerStatusTimer = lv_timer_create(showCoolerStatusOn, 5000, NULL);
}

void turnOffCtrl_Unchecked(lv_event_t *e)
{
	// Store device state as OFF
	setBooleanSetting(DEVICE_ON, false);

	// Hide the "COOLER IS : ON" label
	lv_obj_add_flag(ui_COOLER_IS__ON, LV_OBJ_FLAG_HIDDEN);

	// Set new label: "TURNING OFF..." label
	lv_label_set_text(ui_COOLER_IS__OFF, "TURNING OFF...");
	lv_obj_clear_flag(ui_COOLER_IS__OFF, LV_OBJ_FLAG_HIDDEN);

	// If a previous timer exists, delete it before creating a new one
	if (coolerStatusTimer != NULL)
	{
		lv_timer_del(coolerStatusTimer);
		coolerStatusTimer = NULL;
	}

	// Create a new timer to update the final status after 7 seconds
	coolerStatusTimer = lv_timer_create(showCoolerStatusOff, 5000, NULL);
}

void processSettingScreen(lv_event_t *e)
{
	int compressorTempSpinbox;
	compressorTempSpinbox = getNumericSetting(COMPRESSOR_TEMP);
	lv_spinbox_set_value(ui_Compressor_Range_Spinbox, compressorTempSpinbox);

	int compressorOffsetSpinbox;
	compressorOffsetSpinbox = getNumericSetting(COMPRESSOR_RANGE);
	lv_spinbox_set_value(ui_Compressor_Offste_Spinbox, compressorOffsetSpinbox);

	int highTempAlarmSpinbox;
	highTempAlarmSpinbox = getNumericSetting(HIGH_TEMP_WARNING);
	lv_spinbox_set_value(ui_High_Temp_Alarm_Spinbox, highTempAlarmSpinbox);

	bool pressureAlarmSwitch;
	pressureAlarmSwitch = getBooleanSetting(PRESSURE_WARNING_ON);
	if (pressureAlarmSwitch)
	{
		// true - checked
		lv_obj_add_state(ui_PressureAlarmSwitch, LV_STATE_CHECKED);
		lv_obj_clear_flag(ui_PressureAlarmSwitch_ONlabel, LV_OBJ_FLAG_HIDDEN); // "ON" Flag
		lv_obj_add_flag(ui_PressureAlarmSwitch_OFFlabel, LV_OBJ_FLAG_HIDDEN);  // "OFF" Flag
	}
	else
	{
		// false - unchecked
		lv_obj_clear_state(ui_PressureAlarmSwitch, LV_STATE_CHECKED);
		lv_obj_add_flag(ui_PressureAlarmSwitch_ONlabel, LV_OBJ_FLAG_HIDDEN);	// "ON" Flag
		lv_obj_clear_flag(ui_PressureAlarmSwitch_OFFlabel, LV_OBJ_FLAG_HIDDEN); // "OFF" Flag
	}

	bool tempAlarmSwitch;
	tempAlarmSwitch = getBooleanSetting(TEMP_WARNING_ON);
	if (tempAlarmSwitch)
	{
		// true - checked
		lv_obj_add_state(ui_TempAlarmSwitch, LV_STATE_CHECKED);
		lv_obj_clear_flag(ui_TempAlarmSwitch_ONlabel, LV_OBJ_FLAG_HIDDEN); // "ON" Flag
		lv_obj_add_flag(ui_TempAlarmSwitch_OFFlabel, LV_OBJ_FLAG_HIDDEN);  // "OFF" Flag

		_ui_state_modify(ui_High_Temp_Alarm_Plus_Button, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
		_ui_state_modify(ui_High_Temp_Alarm_Minus_Button, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
		_ui_state_modify(ui_High_Temp_Alarm_Spinbox, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
	}
	else
	{
		// false - unchecked
		lv_obj_clear_state(ui_TempAlarmSwitch, LV_STATE_CHECKED);
		lv_obj_add_flag(ui_TempAlarmSwitch_ONlabel, LV_OBJ_FLAG_HIDDEN);	// "ON" Flag
		lv_obj_clear_flag(ui_TempAlarmSwitch_OFFlabel, LV_OBJ_FLAG_HIDDEN); // "OFF" Flag

		_ui_state_modify(ui_High_Temp_Alarm_Spinbox, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
		_ui_state_modify(ui_High_Temp_Alarm_Plus_Button, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
		_ui_state_modify(ui_High_Temp_Alarm_Minus_Button, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
	}
}

static void update_save_label(lv_timer_t *timer)
{
	static int step = 0;
	const char *texts[] = {"Saving", "Saved", "Save"};

	if (lv_scr_act() == ui_processSettingScreen)
	{
		lv_label_set_text(ui_Setting_Save_btn_label, texts[step]);
	}
	else if (lv_scr_act() == ui_addvansedSettingScreen)
	{
		lv_label_set_text(ui_Setting_Save_btn_label_advanced_Screen, texts[step]);
	}

	step++;
	if (step >= 3)
	{
		step = 0;
		lv_timer_del(timer);
	}
}

void animate_save_label()
{
	if (lv_scr_act() == ui_processSettingScreen)
	{
		lv_label_set_text(ui_Setting_Save_btn_label, "Save");
	}
	else if (lv_scr_act() == ui_addvansedSettingScreen)
	{
		lv_label_set_text(ui_Setting_Save_btn_label_advanced_Screen, "Save");
	}

	lv_timer_create(update_save_label, 1000, NULL);
}

void submit_process_setting(lv_event_t *e)
{
	animate_save_label();

	int compressorTempValue = lv_spinbox_get_value(ui_Compressor_Range_Spinbox);
	int compressorOffsetValue = lv_spinbox_get_value(ui_Compressor_Offste_Spinbox);
	int highTempAlarmValue = lv_spinbox_get_value(ui_High_Temp_Alarm_Spinbox);

	bool pressureAlarmState = lv_obj_has_state(ui_PressureAlarmSwitch, LV_STATE_CHECKED);
	bool tempAlarmState = lv_obj_has_state(ui_TempAlarmSwitch, LV_STATE_CHECKED);

	setNumericSetting(COMPRESSOR_TEMP, compressorTempValue);
	setNumericSetting(COMPRESSOR_RANGE, compressorOffsetValue);
	setNumericSetting(HIGH_TEMP_WARNING, highTempAlarmValue);

	setBooleanSetting(PRESSURE_WARNING_ON, pressureAlarmState);
	setBooleanSetting(TEMP_WARNING_ON, tempAlarmState);
}

void addvancedSettingScreen(lv_event_t *e)
{
	int antiFreezeTempSpinbox;
	antiFreezeTempSpinbox = getNumericSetting(ANTI_FREEZE_TEMP);
	lv_spinbox_set_value(ui_AntiFreeze_Temp_Range_Spinbox, antiFreezeTempSpinbox);

	int antiFreezeOffsetTempSpinbox;
	antiFreezeOffsetTempSpinbox = getNumericSetting(ANTI_FREEZE_RANGE);
	lv_spinbox_set_value(ui_AntiFreeze_Temp_Offset_Spinbox, antiFreezeOffsetTempSpinbox);

	int compressorRestTimeSpinbox;
	compressorRestTimeSpinbox = getNumericSetting(COMPRESSOR_REST_TIME);
	lv_spinbox_set_value(ui_Compressor_Rest_Time_Spinbox, compressorRestTimeSpinbox);

	int filterAlarmSpinbox;
	filterAlarmSpinbox = getNumericSetting(FILTER_WARNING);
	lv_spinbox_set_value(ui_Filter_Alarm_Spinbox, filterAlarmSpinbox);

	int fan2RangeSpinbox;
	fan2RangeSpinbox = getNumericSetting(FAN2_TEMP);
	lv_spinbox_set_value(ui_fan_2_range_Spinbox, fan2RangeSpinbox);

	bool fan2Switch;
	fan2Switch = getBooleanSetting(FAN2_ON);
	if (fan2Switch)
	{
		// true - checked
		lv_obj_add_state(ui_fan_2_Switch, LV_STATE_CHECKED);
		lv_obj_clear_flag(ui_enable_fan_2_Label, LV_OBJ_FLAG_HIDDEN); // "ON" Flag
		lv_obj_add_flag(ui_disable_fan_2_Label, LV_OBJ_FLAG_HIDDEN);  // "OFF" Flag

		_ui_state_modify(ui_fan_2_range_Minus_Button, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
		_ui_state_modify(ui_fan_2_range_Plus_Button, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
		_ui_state_modify(ui_fan_2_range_Spinbox, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
	}
	else
	{
		// false - unchecked
		lv_obj_clear_state(ui_fan_2_Switch, LV_STATE_CHECKED);
		lv_obj_add_flag(ui_enable_fan_2_Label, LV_OBJ_FLAG_HIDDEN);	   // "ON" Flag
		lv_obj_clear_flag(ui_disable_fan_2_Label, LV_OBJ_FLAG_HIDDEN); // "OFF" Flag

		_ui_state_modify(ui_fan_2_range_Plus_Button, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
		_ui_state_modify(ui_fan_2_range_Spinbox, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
		_ui_state_modify(ui_fan_2_range_Minus_Button, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
	}

	bool doorAlarmStatusSwitch;
	doorAlarmStatusSwitch = getBooleanSetting(DOOR_WARNING_ON);
	if (doorAlarmStatusSwitch)
	{
		// true - checked
		lv_obj_add_state(ui_door_alarm_status_Switch, LV_STATE_CHECKED);
		lv_obj_clear_flag(ui_enable_door_alarm_status_Label, LV_OBJ_FLAG_HIDDEN); // "ON" Flag
		lv_obj_add_flag(ui_disable_door_alarm_status_Label, LV_OBJ_FLAG_HIDDEN);  // "OFF" Flag
	}
	else
	{
		// false - unchecked
		lv_obj_clear_state(ui_door_alarm_status_Switch, LV_STATE_CHECKED);
		lv_obj_add_flag(ui_enable_door_alarm_status_Label, LV_OBJ_FLAG_HIDDEN);	   // "ON" Flag
		lv_obj_clear_flag(ui_disable_door_alarm_status_Label, LV_OBJ_FLAG_HIDDEN); // "OFF" Flag
	}

	bool filterAlarmStatusSwitch;
	filterAlarmStatusSwitch = getBooleanSetting(FILTER_WARNING_ON);
	if (filterAlarmStatusSwitch)
	{
		// true - checked
		lv_obj_add_state(ui_filter_alarm_status_Switch, LV_STATE_CHECKED);
		lv_obj_clear_flag(ui_enable_filter_alarm_status_Label, LV_OBJ_FLAG_HIDDEN); // "ON" Flag
		lv_obj_add_flag(ui_disable_filter_alarm_status_Label, LV_OBJ_FLAG_HIDDEN);	// "OFF" Flag
	}
	else
	{
		// false - unchecked
		lv_obj_clear_state(ui_filter_alarm_status_Switch, LV_STATE_CHECKED);
		lv_obj_add_flag(ui_enable_filter_alarm_status_Label, LV_OBJ_FLAG_HIDDEN);	 // "ON" Flag
		lv_obj_clear_flag(ui_disable_filter_alarm_status_Label, LV_OBJ_FLAG_HIDDEN); // "OFF" Flag
	}
}

void submit_advance_setting(lv_event_t *e)
{
	animate_save_label();

	int antiFreeze_Temp_Range_SpinboxValue = lv_spinbox_get_value(ui_AntiFreeze_Temp_Range_Spinbox);
	int antiFreeze_Temp_Offset_SpinboxValue = lv_spinbox_get_value(ui_AntiFreeze_Temp_Offset_Spinbox);
	int compressor_Rest_Time_SpinboxValue = lv_spinbox_get_value(ui_Compressor_Rest_Time_Spinbox);
	int filter_Alarm_SpinboxValue = lv_spinbox_get_value(ui_Filter_Alarm_Spinbox);
	int fan_2_range_SpinboxValue = lv_spinbox_get_value(ui_fan_2_range_Spinbox);

	bool fan_2_SwitchState = lv_obj_has_state(ui_fan_2_Switch, LV_STATE_CHECKED);
	bool door_alarm_status_SwitchState = lv_obj_has_state(ui_door_alarm_status_Switch, LV_STATE_CHECKED);
	bool filter_alarm_status_SwitchState = lv_obj_has_state(ui_filter_alarm_status_Switch, LV_STATE_CHECKED);

	setNumericSetting(ANTI_FREEZE_TEMP, antiFreeze_Temp_Range_SpinboxValue);
	setNumericSetting(ANTI_FREEZE_RANGE, antiFreeze_Temp_Offset_SpinboxValue);
	setNumericSetting(COMPRESSOR_REST_TIME, compressor_Rest_Time_SpinboxValue);
	setNumericSetting(FILTER_WARNING, filter_Alarm_SpinboxValue);
	setNumericSetting(FAN2_TEMP, fan_2_range_SpinboxValue);

	setBooleanSetting(FAN2_ON, fan_2_SwitchState);
	setBooleanSetting(DOOR_WARNING_ON, door_alarm_status_SwitchState);
	setBooleanSetting(FILTER_WARNING_ON, filter_alarm_status_SwitchState);
}

void TabView1AddvancedSetting(lv_event_t *e)
{
	lv_obj_t *tabview = lv_event_get_target(e);
	uint16_t active_tab = lv_tabview_get_tab_act(tabview);

	if (active_tab == 0 || active_tab == 1)
	{
		lv_obj_clear_flag(ui_Setting_Save_btn_in_advanced_Screen, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_Setting_Save_btn_label_advanced_Screen, LV_OBJ_FLAG_HIDDEN);
	}
	else if (active_tab == 2)
	{
		lv_obj_add_flag(ui_Setting_Save_btn_in_advanced_Screen, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_Setting_Save_btn_label_advanced_Screen, LV_OBJ_FLAG_HIDDEN);
	}
}

static lv_obj_t *label_countdown;
static int countdown_value = 10;

void update_countdown(lv_timer_t *timer)
{
	// Update countdown value
	countdown_value--;
	lv_label_set_text_fmt(label_countdown, "%d", countdown_value);

	// Check if countdown reached zero
	if (countdown_value <= 0)
	{
		// Stop the timer
		lv_timer_del(timer);

		// Restart device
		esp_restart();
	}
}

void restart_device(lv_event_t *e)
{
	lv_obj_t *new_screen = lv_obj_create(NULL);
	lv_scr_load(new_screen);

	lv_obj_set_size(new_screen, LV_HOR_RES, LV_VER_RES);

	// Set black background
	lv_obj_set_style_bg_color(new_screen, lv_color_hex(0x000000), LV_PART_MAIN);
	lv_obj_set_style_bg_opa(new_screen, LV_OPA_COVER, LV_PART_MAIN);

	// Display restarting message
	lv_obj_t *label_message = lv_label_create(lv_scr_act());
	lv_label_set_text(label_message, "Restarting Device...");
	lv_obj_set_style_text_font(label_message, &lv_font_montserrat_20, LV_PART_MAIN);
	lv_obj_set_style_text_color(label_message, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
	lv_obj_align(label_message, LV_ALIGN_CENTER, 0, -20);

	// Create countdown label
	label_countdown = lv_label_create(lv_scr_act());
	lv_label_set_text_fmt(label_countdown, "%d", countdown_value);
	lv_obj_set_style_text_font(label_countdown, &lv_font_montserrat_20, LV_PART_MAIN);
	lv_obj_set_style_text_color(label_countdown, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
	lv_obj_align(label_countdown, LV_ALIGN_CENTER, 0, 20);

	// Create timer for countdown
	lv_timer_t *timer = lv_timer_create(update_countdown, 1000, NULL); // Update every 1 second

	// Update display to ensure UI is rendered immediately
	lv_timer_handler();
}

void reseting_sensors_address(lv_event_t *e)
{
	setStringSetting(INLET_SENSOR_ADDRESS, "00:00:00:00:00:00:00:00");
	setStringSetting(OUTLET_SENSOR_ADDRESS, "00:00:00:00:00:00:00:00");
	setStringSetting(ANTIFREEZE_SENSOR_ADDRESS, "00:00:00:00:00:00:00:00");
	setStringSetting(FILTER_SENSOR_ADDRESS, "00:00:00:00:00:00:00:00");
}

extern int detectDS18B20Sensors(void);

void hideSensorSetupContainers_1(lv_timer_t *timer)
{
	lv_obj_add_flag(ui_Sensor_Setup_main_Container_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui_Sensor_Setup_main_Container_2, LV_OBJ_FLAG_HIDDEN);

	lv_timer_del(timer);
}

void sensors_disconnect_check(lv_event_t *e)
{
	int numSensors = detectDS18B20Sensors();

	if (numSensors == 0)
	{
		lv_obj_add_flag(ui_Detail_Success_Status_message_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_disconnect_error_icon, LV_OBJ_FLAG_HIDDEN);

		lv_obj_clear_flag(ui_Detail_Success_Status_message_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_success_disconnect_icon, LV_OBJ_FLAG_HIDDEN);

		lv_timer_create(hideSensorSetupContainers_1, 3000, NULL);
	}
	else
	{
		char statusMessage[100];

		snprintf(statusMessage, sizeof(statusMessage), "Error: %d Sensors Connected!\nDisconnect All sensors, Try Again.", numSensors);
		lv_label_set_text(ui_Detail_Success_Status_message_1, statusMessage);

		lv_obj_clear_flag(ui_Detail_Success_Status_message_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_disconnect_error_icon, LV_OBJ_FLAG_HIDDEN);

		lv_obj_add_flag(ui_Detail_Success_Status_message_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_success_disconnect_icon, LV_OBJ_FLAG_HIDDEN);
	}
}

extern int getFirstDS18B20Address(char *addressStr, int maxLen);

void hideSensorSetupContainers_2(lv_timer_t *timer)
{
	lv_obj_clear_flag(ui_Sensor_Setup_main_Container_3, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui_Sensor_Setup_main_Container_2, LV_OBJ_FLAG_HIDDEN);

	lv_timer_del(timer);
}

void check_set_Inlet(lv_event_t *e)
{
	int numSensors = detectDS18B20Sensors();

	if (numSensors != 1) // if not 1 detected
	{
		char statusMessage[100];

		if (numSensors == 0)
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: No sensor connected!\nPlease connect the INLET sensor.");
		}
		else
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: %d sensors connected!\nConnect only the INLET sensor.", numSensors);
		}

		lv_label_set_text(ui_Detail_Success_Status_message_3, statusMessage);

		lv_obj_clear_flag(ui_Detail_Success_Status_message_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_inlet_setup_error_icon, LV_OBJ_FLAG_HIDDEN);

		lv_obj_add_flag(ui_Detail_Success_Status_message_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_inlet_setup_success_icon, LV_OBJ_FLAG_HIDDEN);
	}
	else
	{
		char newAddress[24];

		if (getFirstDS18B20Address(newAddress, sizeof(newAddress)))
		{
			setStringSetting(INLET_SENSOR_ADDRESS, newAddress);

			lv_obj_clear_flag(ui_Detail_Success_Status_message_4, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(ui_inlet_setup_success_icon, LV_OBJ_FLAG_HIDDEN);

			lv_obj_add_flag(ui_Detail_Success_Status_message_3, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(ui_inlet_setup_error_icon, LV_OBJ_FLAG_HIDDEN);

			lv_timer_create(hideSensorSetupContainers_2, 3000, NULL);
		}
	}
}

void hideSensorSetupContainers_3(lv_timer_t *timer)
{
	lv_obj_clear_flag(ui_Sensor_Setup_main_Container_4, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui_Sensor_Setup_main_Container_3, LV_OBJ_FLAG_HIDDEN);

	lv_timer_del(timer);
}

void check_set_Outlet(lv_event_t *e)
{
	int numSensors = detectDS18B20Sensors();

	if (numSensors != 2) // if not 2 detected
	{
		char statusMessage[100];

		if (numSensors == 0)
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: No sensor connected!\nConnect INLET & OUTLET.");
		}
		else if (numSensors == 1)
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: Only one sensor connected!\nBoth INLET & OUTLET required.");
		}
		else
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: %d sensors connected!\nOnly INLET & OUTLET allowed.", numSensors);
		}

		lv_label_set_text(ui_Detail_Success_Status_message_5, statusMessage);

		lv_obj_clear_flag(ui_Detail_Success_Status_message_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_Outlet_setup_error_icon, LV_OBJ_FLAG_HIDDEN);

		lv_obj_add_flag(ui_Detail_Success_Status_message_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_Outlet_setup_success_icon, LV_OBJ_FLAG_HIDDEN);
	}
	else
	{
		char newAddress[24];

		if (getFirstDS18B20Address(newAddress, sizeof(newAddress)))
		{
			setStringSetting(OUTLET_SENSOR_ADDRESS, newAddress);

			lv_obj_clear_flag(ui_Detail_Success_Status_message_6, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(ui_Outlet_setup_success_icon, LV_OBJ_FLAG_HIDDEN);

			lv_obj_add_flag(ui_Detail_Success_Status_message_5, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(ui_Outlet_setup_error_icon, LV_OBJ_FLAG_HIDDEN);

			lv_timer_create(hideSensorSetupContainers_3, 3000, NULL);
		}
	}
}

void hideSensorSetupContainers_4(lv_timer_t *timer)
{
	lv_obj_clear_flag(ui_Sensor_Setup_main_Container_5, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui_Sensor_Setup_main_Container_4, LV_OBJ_FLAG_HIDDEN);

	lv_timer_del(timer);
}

void check_set_Antifreeze(lv_event_t *e)
{
	int numSensors = detectDS18B20Sensors();

	if (numSensors != 3) // if not 3 detected
	{
		char statusMessage[100];

		if (numSensors == 0)
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: No sensor connected!\nConnect INLET, OUTLET & ANTIFREEZE.");
		}
		else if (numSensors == 1)
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: Only one sensor connected!\nINLET, OUTLET & ANTIFREEZE required.");
		}
		else if (numSensors == 2)
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: 2 sensors connected!\nINLET, OUTLET & ANTIFREEZE required.");
		}
		else
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: %d sensors connected!\nOnly INLET, OUTLET & ANTIFREEZE allowed.", numSensors);
		}

		lv_label_set_text(ui_Detail_Success_Status_message_7, statusMessage);

		lv_obj_clear_flag(ui_Detail_Success_Status_message_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_Antifreeze_setup_error_icon, LV_OBJ_FLAG_HIDDEN);

		lv_obj_add_flag(ui_Detail_Success_Status_message_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_Antifreeze_setup_success_icon, LV_OBJ_FLAG_HIDDEN);
	}
	else
	{
		char newAddress[24];

		if (getFirstDS18B20Address(newAddress, sizeof(newAddress)))
		{
			setStringSetting(ANTIFREEZE_SENSOR_ADDRESS, newAddress);

			lv_obj_clear_flag(ui_Detail_Success_Status_message_8, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(ui_Antifreeze_setup_success_icon, LV_OBJ_FLAG_HIDDEN);

			lv_obj_add_flag(ui_Detail_Success_Status_message_7, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(ui_Antifreeze_setup_error_icon, LV_OBJ_FLAG_HIDDEN);

			lv_timer_create(hideSensorSetupContainers_4, 3000, NULL);
		}
	}
}

void hideSensorSetupContainers_5(lv_timer_t *timer)
{
	lv_obj_clear_flag(ui_Sensor_Setup_main_Container_6, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui_Sensor_Setup_main_Container_5, LV_OBJ_FLAG_HIDDEN);

	lv_timer_del(timer);

	label_countdown = lv_label_create(ui_Sensor_Setup_main_Container_6);
	lv_label_set_text_fmt(label_countdown, "%d", countdown_value);
	lv_obj_set_style_text_font(label_countdown, &lv_font_montserrat_20, LV_PART_MAIN);
	lv_obj_set_style_text_color(label_countdown, lv_color_hex(0x0D0246), LV_PART_MAIN);
	lv_obj_align(label_countdown, LV_ALIGN_BOTTOM_MID, 0, -20);

	lv_timer_create(update_countdown, 1000, NULL);
}

void check_set_Filter(lv_event_t *e)
{
	int numSensors = detectDS18B20Sensors();

	if (numSensors != 4) // if not 4 detected
	{
		char statusMessage[100];

		if (numSensors == 0)
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: No sensor connected!\nConnect INLET, OUTLET, ANTIFREEZE &\nFILTER Sensor.");
		}
		else if (numSensors == 1)
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: Only one sensor connected!\nINLET, OUTLET, ANTIFREEZE &\nFILTER Sensor required.");
		}
		else if (numSensors == 2)
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: 2 sensors connected!\nINLET, OUTLET, ANTIFREEZE &\nFILTER Sensor required.");
		}
		else if (numSensors == 3)
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: 3 sensors connected!\nINLET, OUTLET, ANTIFREEZE &\nFILTER Sensor required.");
		}
		else
		{
			snprintf(statusMessage, sizeof(statusMessage), "Error: %d sensors connected!\nOnly INLET, OUTLET, ANTIFREEZE &\nFILTER Sensor allowed.", numSensors);
		}

		lv_label_set_text(ui_Detail_Success_Status_message_9, statusMessage);

		lv_obj_clear_flag(ui_Detail_Success_Status_message_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_Filter_setup_error_icon, LV_OBJ_FLAG_HIDDEN);

		lv_obj_add_flag(ui_Detail_Success_Status_message_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_Filter_setup_success_icon, LV_OBJ_FLAG_HIDDEN);
	}
	else
	{
		char newAddress[24];

		if (getFirstDS18B20Address(newAddress, sizeof(newAddress)))
		{
			setStringSetting(FILTER_SENSOR_ADDRESS, newAddress);

			lv_obj_clear_flag(ui_Detail_Success_Status_message_10, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(ui_Filter_setup_success_icon, LV_OBJ_FLAG_HIDDEN);

			lv_obj_add_flag(ui_Detail_Success_Status_message_9, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(ui_Filter_setup_error_icon, LV_OBJ_FLAG_HIDDEN);

			lv_timer_create(hideSensorSetupContainers_5, 3000, NULL);
		}
	}
}

// ================================
// Reset Device Settings
// Resets all settings to default values and reboots the system
// - Sets DEVICE_ON to false first, then resets numeric, boolean, and string settings
// - Includes a delay to ensure settings are applied before reboot
// ================================
void resetDeviceSettings()
{
    uint32_t currentTime = millis();
    printf("[UI][INFO][%lu] Starting factory reset\n", currentTime);

    // Reset Numeric Settings to Default
    setNumericSetting(COMPRESSOR_TEMP, 20);
    setNumericSetting(COMPRESSOR_RANGE, 5);
    setNumericSetting(HIGH_TEMP_WARNING, 40);
    setNumericSetting(ANTI_FREEZE_TEMP, 0);
    setNumericSetting(ANTI_FREEZE_RANGE, 5);
    setNumericSetting(COMPRESSOR_REST_TIME, 3);
    setNumericSetting(FILTER_WARNING, 80);
    setNumericSetting(FAN2_TEMP, 55);
    setNumericSetting(DEVICE_SERIAL_ID, 100001);
    setNumericSetting(CUSTOMER_ID, 123456789);
    setNumericSetting(ACTIVATION_DATE, 20241104);
    setNumericSetting(SERVICE_INTERVAL, 365);
    setNumericSetting(HOURS_ELAPSED, 0);
    printf("[UI][INFO][%lu] Numeric settings reset to default\n", millis());

    // Reset Boolean Settings to Default
    setBooleanSetting(DEVICE_ON, false);
    setBooleanSetting(PRESSURE_WARNING_ON, false);
    setBooleanSetting(TEMP_WARNING_ON, false);
    setBooleanSetting(FILTER_WARNING_ON, false);
    setBooleanSetting(DOOR_WARNING_ON, false);
    setBooleanSetting(FAN2_ON, false);
    setBooleanSetting(ADVANCED_SETTINGS_ON, false);
    setBooleanSetting(CLOUD_ON, false);
    setBooleanSetting(SERIAL_LOG_ON, false);
    setBooleanSetting(CLOUD_LOG_ON, false);
    printf("[UI][INFO][%lu] Boolean settings reset to default\n", millis());

    // Reset String Settings to Default
    setStringSetting(WIFI_SSID, "0");
    setStringSetting(WIFI_PASSWORD, "0");
    setStringSetting(AP_NAME, "0");
    setStringSetting(AP_PASSWORD, "0");
    setStringSetting(SERVER_URL, "https://bently.cool/");
    setStringSetting(SERVER_IP, "192.168.4.1");
	setStringSetting(INLET_SENSOR_ADDRESS, "28:2D:11:58:D4:E1:3C:BC");
	setStringSetting(OUTLET_SENSOR_ADDRESS, "28:BD:AD:43:D4:E1:3C:CF");
	setStringSetting(ANTIFREEZE_SENSOR_ADDRESS, "28:AB:CC:43:D4:E1:3C:FA");
	setStringSetting(FILTER_SENSOR_ADDRESS, "28:FF:64:1F:70:68:7C:7C");
    printf("[UI][INFO][%lu] String settings reset to default\n", millis());

    resetAllChangedFlagsToFalse(); // Reset all flags to false
    printf("[UI][INFO][%lu] All changed flags reset\n", millis());
    
    printf("[UI][INFO][%lu] Factory reset complete, rebooting\n", millis());
	delay(5000); // Reduced delay to 5 seconds to ensure settings are applied

    esp_restart(); // Reboot after the reset
}

// ================================
// Reset Device Callback
// Timer callback to execute resetDeviceSettings after UI rendering
// ================================
void resetDeviceCallback(lv_timer_t *t)
{
    resetDeviceSettings();
    lv_timer_del(t); // Delete timer after execution
}

// ================================
// Display and Reset Task
// Displays factory reset screen and schedules reset
// - Shows warning message and schedules reset after a short delay
// ================================
void displayAndResetTask(lv_event_t *e)
{
    uint32_t currentTime = millis();
    printf("[UI][INFO][%lu] Displaying factory reset screen\n", currentTime);

    lv_obj_t *new_screen = lv_obj_create(NULL);
    lv_scr_load(new_screen);
    lv_obj_set_size(new_screen, LV_HOR_RES, LV_VER_RES);

    // Set black background
    lv_obj_set_style_bg_color(new_screen, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(new_screen, LV_OPA_COVER, LV_PART_MAIN);

    // Create styles
    static lv_style_t style_title, style_warning, style_symbol;
    lv_style_init(&style_title);
    lv_style_set_text_font(&style_title, &lv_font_montserrat_18);
    lv_style_set_text_color(&style_title, lv_color_hex(0xFFFFFF));

    lv_style_init(&style_warning);
    lv_style_set_text_font(&style_warning, &lv_font_montserrat_16);
    lv_style_set_text_color(&style_warning, lv_color_hex(0xFFFFFF));

    lv_style_init(&style_symbol);
    lv_style_set_text_font(&style_symbol, &lv_font_montserrat_22);
    lv_style_set_text_color(&style_symbol, lv_color_hex(0xFF0000));

    // Title Label
    lv_obj_t *titleLabel = lv_label_create(lv_scr_act());
    lv_label_set_text(titleLabel, "Factory Reset In Progress...");
    lv_obj_align(titleLabel, LV_ALIGN_CENTER, 0, -30);
    lv_obj_set_width(titleLabel, LV_HOR_RES);
    lv_obj_set_style_text_align(titleLabel, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_style(titleLabel, &style_title, LV_PART_MAIN);

    // Symbol Label (Warning)
    lv_obj_t *symbolLabel = lv_label_create(lv_scr_act());
    lv_label_set_text(symbolLabel, LV_SYMBOL_WARNING);
    lv_obj_align(symbolLabel, LV_ALIGN_CENTER, 0, 10);
    lv_obj_add_style(symbolLabel, &style_symbol, LV_PART_MAIN);

    // Warning Label
    lv_obj_t *warningLabel = lv_label_create(lv_scr_act());
    lv_label_set_text(warningLabel, "Do not turn off or unplug the device!");
    lv_obj_align(warningLabel, LV_ALIGN_CENTER, 0, 50);
    lv_obj_set_width(warningLabel, LV_HOR_RES);
    lv_obj_set_style_text_align(warningLabel, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_style(warningLabel, &style_warning, LV_PART_MAIN);

    // Update display to ensure UI is rendered immediately
    lv_timer_handler();

    // Schedule reset after a short delay to allow UI rendering
    lv_timer_create(resetDeviceCallback, 500, NULL);
}

// ================================
// Go To Factory Reset
// Initiates factory reset process by turning off the device first
// - Sets DEVICE_ON to false and waits for system to process
// - Then displays reset screen and proceeds with reset
// ================================
void goToFactoryReseting(lv_event_t *e)
{
    uint32_t currentTime = millis();
    printf("[UI][INFO][%lu] Factory reset initiated, turning off device\n", currentTime);

    // Turn off the device first
    setBooleanSetting(DEVICE_ON, false);
    printf("[UI][INFO][%lu] DEVICE_ON set to false\n", millis());

    // Wait for system to process the OFF state (e.g., relays turning off)
    delay(2000); // 2-second delay to ensure system processes the change
    printf("[UI][INFO][%lu] Device turned off, proceeding with reset\n", millis());

    // Start display and reset task
    displayAndResetTask(e);
}

void satusScreen(lv_event_t *e)
{
	// code...
}

void show_QR_code(lv_event_t *e)
{
	// code...
}

void switchToMainScreen(lv_timer_t *timer)
{
	// Get the currently active screen
	lv_obj_t *currentScreen = lv_scr_act();

	// Change to the main screen with a fade-in animation
	_ui_screen_change(&ui_mainScreen, LV_SCR_LOAD_ANIM_FADE_IN, 100, 0, NULL);

	// Delete the boot screen if it is still active
	if (currentScreen == ui_Boot_Screen)
	{
		lv_obj_t *screenToDelete = currentScreen; // Create a temporary pointer
		_ui_screen_delete(&screenToDelete);		  // Delete the boot screen
	}

	// Delete the timer to prevent further execution
	lv_timer_del(timer);
}

void bootScreen(lv_event_t *e)
{
	printf("[UI] Boot Screen Started...\n");

	// Create a timer to switch to the main screen after 30,000ms (30 seconds)
	lv_timer_create(switchToMainScreen, 15000, NULL);

	// Handle LVGL tasks
	lv_timer_handler();
}