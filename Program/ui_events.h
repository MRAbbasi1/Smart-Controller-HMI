// ui_events.h


#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void bootScreen(lv_event_t * e);
void settingScreen(lv_event_t * e);
void turnOffCtrl_Checked(lv_event_t * e);
void turnOffCtrl_Unchecked(lv_event_t * e);
void processSettingScreen(lv_event_t * e);
void submit_process_setting(lv_event_t * e);
void addvancedSettingScreen(lv_event_t * e);
void submit_advance_setting(lv_event_t * e);
void TabView1AddvancedSetting(lv_event_t * e);
void restart_device(lv_event_t * e);
void reseting_sensors_address(lv_event_t * e);
void sensors_disconnect_check(lv_event_t * e);
void check_set_Inlet(lv_event_t * e);
void check_set_Outlet(lv_event_t * e);
void check_set_Antifreeze(lv_event_t * e);
void check_set_Filter(lv_event_t * e);
void goToFactoryReseting(lv_event_t * e);
void satusScreen(lv_event_t * e);
void show_QR_code(lv_event_t * e);
void mainScreen(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
