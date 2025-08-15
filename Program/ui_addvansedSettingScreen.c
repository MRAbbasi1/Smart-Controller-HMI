// ui_addvansedSettingScreen.c


#include "ui.h"

void ui_addvansedSettingScreen_screen_init(void)
{
ui_addvansedSettingScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_addvansedSettingScreen, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM );    /// Flags
lv_obj_set_style_bg_color(ui_addvansedSettingScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_addvansedSettingScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_addvansedSettingScreen, &ui_img_1234_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_returnButton14 = lv_btn_create(ui_addvansedSettingScreen);
lv_obj_set_width( ui_returnButton14, 60);
lv_obj_set_height( ui_returnButton14, 30);
lv_obj_set_x( ui_returnButton14, -125 );
lv_obj_set_y( ui_returnButton14, -100 );
lv_obj_set_align( ui_returnButton14, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_returnButton14, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_returnButton14, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_returnButton14, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_returnButton14, lv_color_hex(0x0D0246), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_returnButton14, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_returnButton14, &ui_img_return_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_color(ui_returnButton14, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_returnButton14, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_returnButton14, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_returnButton14, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_returnButton14, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_returnButton14, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Advanced_Setting_Label = lv_label_create(ui_addvansedSettingScreen);
lv_obj_set_width( ui_Advanced_Setting_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Advanced_Setting_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Advanced_Setting_Label, 0 );
lv_obj_set_y( ui_Advanced_Setting_Label, -100 );
lv_obj_set_align( ui_Advanced_Setting_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Advanced_Setting_Label,"EXPERT SETTING");
lv_obj_set_style_text_color(ui_Advanced_Setting_Label, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Advanced_Setting_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Advanced_Setting_Label, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Setting_Save_btn_in_advanced_Screen = lv_btn_create(ui_addvansedSettingScreen);
lv_obj_set_width( ui_Setting_Save_btn_in_advanced_Screen, 60);
lv_obj_set_height( ui_Setting_Save_btn_in_advanced_Screen, 30);
lv_obj_set_x( ui_Setting_Save_btn_in_advanced_Screen, 125 );
lv_obj_set_y( ui_Setting_Save_btn_in_advanced_Screen, -100 );
lv_obj_set_align( ui_Setting_Save_btn_in_advanced_Screen, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Setting_Save_btn_in_advanced_Screen, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Setting_Save_btn_in_advanced_Screen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Setting_Save_btn_in_advanced_Screen, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Setting_Save_btn_in_advanced_Screen, lv_color_hex(0x00BE10), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Setting_Save_btn_in_advanced_Screen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Setting_Save_btn_in_advanced_Screen, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Setting_Save_btn_in_advanced_Screen, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Setting_Save_btn_in_advanced_Screen, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Setting_Save_btn_in_advanced_Screen, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Setting_Save_btn_label_advanced_Screen = lv_label_create(ui_addvansedSettingScreen);
lv_obj_set_width( ui_Setting_Save_btn_label_advanced_Screen, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Setting_Save_btn_label_advanced_Screen, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Setting_Save_btn_label_advanced_Screen, 125 );
lv_obj_set_y( ui_Setting_Save_btn_label_advanced_Screen, -101 );
lv_obj_set_align( ui_Setting_Save_btn_label_advanced_Screen, LV_ALIGN_CENTER );
lv_label_set_text(ui_Setting_Save_btn_label_advanced_Screen,"Save");
lv_obj_set_style_text_color(ui_Setting_Save_btn_label_advanced_Screen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Setting_Save_btn_label_advanced_Screen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Setting_Save_btn_label_advanced_Screen, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TabView1 = lv_tabview_create(ui_addvansedSettingScreen, LV_DIR_BOTTOM, 35);
lv_obj_set_width( ui_TabView1, 315);
lv_obj_set_height( ui_TabView1, 200);
lv_obj_set_x( ui_TabView1, 0 );
lv_obj_set_y( ui_TabView1, 18 );
lv_obj_set_align( ui_TabView1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_TabView1, LV_OBJ_FLAG_CHECKABLE );   /// Flags
lv_obj_clear_flag( ui_TabView1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_style_bg_color(ui_TabView1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TabView1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_TabView1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_TabView1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_TabView1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_TabView1, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_outline_color(ui_TabView1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_outline_opa(ui_TabView1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_outline_width(ui_TabView1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_outline_pad(ui_TabView1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_TabView1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TabView1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_TabView1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_border_opa(ui_TabView1, 255, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_width(ui_TabView1, 0, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_text_color(ui_TabView1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_text_opa(ui_TabView1, 255, LV_PART_MAIN| LV_STATE_CHECKED);

lv_obj_set_style_text_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0xFFFFFF),  LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(lv_tabview_get_tab_btns(ui_TabView1), &lv_font_montserrat_16,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0x00BE10),  LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_outline_width(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_outline_pad(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0xFFFFFF),  LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_text_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_width(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_side(lv_tabview_get_tab_btns(ui_TabView1), LV_BORDER_SIDE_FULL,  LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_outline_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0xFFFFFF),  LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_outline_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_outline_width(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_outline_pad(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_shadow_width(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_shadow_spread(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_shadow_ofs_x(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_shadow_ofs_y(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_width(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_MAIN| LV_STATE_FOCUSED);
lv_obj_set_style_border_side(lv_tabview_get_tab_btns(ui_TabView1), LV_BORDER_SIDE_FULL,  LV_PART_MAIN| LV_STATE_FOCUSED);

lv_obj_set_style_text_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0xFFFFFF),  LV_PART_ITEMS | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(lv_tabview_get_tab_btns(ui_TabView1), &lv_font_montserrat_16,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_radius(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0x080041),  LV_PART_ITEMS | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0xFFFFFF),  LV_PART_ITEMS | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(lv_tabview_get_tab_btns(ui_TabView1), 1,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(lv_tabview_get_tab_btns(ui_TabView1), LV_BORDER_SIDE_FULL,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_outline_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0xFFFFFF),  LV_PART_ITEMS | LV_STATE_DEFAULT );
lv_obj_set_style_outline_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_outline_width(lv_tabview_get_tab_btns(ui_TabView1), 1,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_outline_pad(lv_tabview_get_tab_btns(ui_TabView1), 1,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0xFFFFFF),  LV_PART_ITEMS | LV_STATE_CHECKED );
lv_obj_set_style_text_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_radius(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_bg_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0x00BE10),  LV_PART_ITEMS | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_border_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0xFFFFFF),  LV_PART_ITEMS | LV_STATE_CHECKED );
lv_obj_set_style_border_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_border_width(lv_tabview_get_tab_btns(ui_TabView1), 1,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_border_side(lv_tabview_get_tab_btns(ui_TabView1), LV_BORDER_SIDE_FULL,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_outline_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0xFFFFFF),  LV_PART_ITEMS | LV_STATE_CHECKED );
lv_obj_set_style_outline_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_outline_width(lv_tabview_get_tab_btns(ui_TabView1), 1,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_outline_pad(lv_tabview_get_tab_btns(ui_TabView1), 1,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_shadow_width(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_shadow_spread(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_shadow_ofs_x(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_shadow_ofs_y(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_CHECKED);
lv_obj_set_style_text_color(lv_tabview_get_tab_btns(ui_TabView1), lv_color_hex(0x000000),  LV_PART_ITEMS | LV_STATE_FOCUSED );
lv_obj_set_style_text_opa(lv_tabview_get_tab_btns(ui_TabView1), 255,  LV_PART_ITEMS| LV_STATE_FOCUSED);
lv_obj_set_style_border_width(lv_tabview_get_tab_btns(ui_TabView1), 0,  LV_PART_ITEMS| LV_STATE_FOCUSED);
lv_obj_set_style_border_side(lv_tabview_get_tab_btns(ui_TabView1), LV_BORDER_SIDE_FULL,  LV_PART_ITEMS| LV_STATE_FOCUSED);

ui_tab1 = lv_tabview_add_tab(ui_TabView1, "1");
lv_obj_add_flag( ui_tab1, LV_OBJ_FLAG_CHECKABLE );   /// Flags
lv_obj_clear_flag( ui_tab1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_style_bg_color(ui_tab1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_tab1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AdvancedScreenContainer1 = lv_obj_create(ui_tab1);
lv_obj_remove_style_all(ui_AdvancedScreenContainer1);
lv_obj_set_width( ui_AdvancedScreenContainer1, 150);
lv_obj_set_height( ui_AdvancedScreenContainer1, 70);
lv_obj_set_x( ui_AdvancedScreenContainer1, -80 );
lv_obj_set_y( ui_AdvancedScreenContainer1, -35 );
lv_obj_set_align( ui_AdvancedScreenContainer1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_AdvancedScreenContainer1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_AdvancedScreenContainer1, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_AdvancedScreenContainer1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AdvancedScreenContainer1, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_AdvancedScreenContainer1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AdvancedScreenContainer1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AdvancedScreenContainer1, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_AdvancedScreenContainer1, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AntiFreeze_Temp_Range_Spinbox = lv_spinbox_create(ui_AdvancedScreenContainer1);
lv_obj_set_width( ui_AntiFreeze_Temp_Range_Spinbox, 45);
lv_obj_set_height( ui_AntiFreeze_Temp_Range_Spinbox, 35);
lv_obj_set_align( ui_AntiFreeze_Temp_Range_Spinbox, LV_ALIGN_CENTER );
lv_spinbox_set_digit_format( ui_AntiFreeze_Temp_Range_Spinbox, 2, 0);
lv_spinbox_set_range( ui_AntiFreeze_Temp_Range_Spinbox, -15,15 );
lv_spinbox_set_cursor_pos(ui_AntiFreeze_Temp_Range_Spinbox, 1 - 1);
lv_spinbox_set_value( ui_AntiFreeze_Temp_Range_Spinbox, 10 );
lv_obj_set_style_border_color(ui_AntiFreeze_Temp_Range_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AntiFreeze_Temp_Range_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AntiFreeze_Temp_Range_Spinbox, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_AntiFreeze_Temp_Range_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_AntiFreeze_Temp_Range_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_AntiFreeze_Temp_Range_Spinbox, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_blend_mode(ui_AntiFreeze_Temp_Range_Spinbox, LV_BLEND_MODE_ADDITIVE, LV_PART_CURSOR| LV_STATE_DEFAULT);
lv_obj_set_style_opa(ui_AntiFreeze_Temp_Range_Spinbox, 0, LV_PART_CURSOR| LV_STATE_DEFAULT);

ui_AntiFreeze_Temp_Range_Plus_Button = lv_btn_create(ui_AdvancedScreenContainer1);
lv_obj_set_width( ui_AntiFreeze_Temp_Range_Plus_Button, 45);
lv_obj_set_height( ui_AntiFreeze_Temp_Range_Plus_Button, 45);
lv_obj_set_x( ui_AntiFreeze_Temp_Range_Plus_Button, 48 );
lv_obj_set_y( ui_AntiFreeze_Temp_Range_Plus_Button, 0 );
lv_obj_set_align( ui_AntiFreeze_Temp_Range_Plus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_AntiFreeze_Temp_Range_Plus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_AntiFreeze_Temp_Range_Plus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_AntiFreeze_Temp_Range_Plus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AntiFreeze_Temp_Range_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_AntiFreeze_Temp_Range_Plus_Button, &ui_img_plus_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_AntiFreeze_Temp_Range_Plus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AntiFreeze_Temp_Range_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AntiFreeze_Temp_Range_Plus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_AntiFreeze_Temp_Range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_AntiFreeze_Temp_Range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_AntiFreeze_Temp_Range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_AntiFreeze_Temp_Range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AntiFreeze_Temp_Range_Minus_Button = lv_btn_create(ui_AdvancedScreenContainer1);
lv_obj_set_width( ui_AntiFreeze_Temp_Range_Minus_Button, 45);
lv_obj_set_height( ui_AntiFreeze_Temp_Range_Minus_Button, 45);
lv_obj_set_x( ui_AntiFreeze_Temp_Range_Minus_Button, -48 );
lv_obj_set_y( ui_AntiFreeze_Temp_Range_Minus_Button, 0 );
lv_obj_set_align( ui_AntiFreeze_Temp_Range_Minus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_AntiFreeze_Temp_Range_Minus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_AntiFreeze_Temp_Range_Minus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_AntiFreeze_Temp_Range_Minus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AntiFreeze_Temp_Range_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_AntiFreeze_Temp_Range_Minus_Button, &ui_img_1731839073, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_AntiFreeze_Temp_Range_Minus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AntiFreeze_Temp_Range_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AntiFreeze_Temp_Range_Minus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_AntiFreeze_Temp_Range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_AntiFreeze_Temp_Range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_AntiFreeze_Temp_Range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_AntiFreeze_Temp_Range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lable25646 = lv_label_create(ui_AdvancedScreenContainer1);
lv_obj_set_width( ui_lable25646, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lable25646, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lable25646, 1 );
lv_obj_set_y( ui_lable25646, 20 );
lv_obj_set_align( ui_lable25646, LV_ALIGN_CENTER );
lv_label_set_text(ui_lable25646," C° ");
lv_obj_set_style_text_color(ui_lable25646, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_lable25646, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lable25646, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_lable25646, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_lable25646, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_lable25646, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AdvancedScreenContainer2 = lv_obj_create(ui_tab1);
lv_obj_remove_style_all(ui_AdvancedScreenContainer2);
lv_obj_set_width( ui_AdvancedScreenContainer2, 150);
lv_obj_set_height( ui_AdvancedScreenContainer2, 70);
lv_obj_set_x( ui_AdvancedScreenContainer2, 80 );
lv_obj_set_y( ui_AdvancedScreenContainer2, -35 );
lv_obj_set_align( ui_AdvancedScreenContainer2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_AdvancedScreenContainer2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_AdvancedScreenContainer2, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_AdvancedScreenContainer2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AdvancedScreenContainer2, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_AdvancedScreenContainer2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AdvancedScreenContainer2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AdvancedScreenContainer2, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_AdvancedScreenContainer2, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AntiFreeze_Temp_Offset_Spinbox = lv_spinbox_create(ui_AdvancedScreenContainer2);
lv_obj_set_width( ui_AntiFreeze_Temp_Offset_Spinbox, 45);
lv_obj_set_height( ui_AntiFreeze_Temp_Offset_Spinbox, 35);
lv_obj_set_align( ui_AntiFreeze_Temp_Offset_Spinbox, LV_ALIGN_CENTER );
lv_spinbox_set_digit_format( ui_AntiFreeze_Temp_Offset_Spinbox, 2, 0);
lv_spinbox_set_range( ui_AntiFreeze_Temp_Offset_Spinbox, 0,15 );
lv_spinbox_set_cursor_pos(ui_AntiFreeze_Temp_Offset_Spinbox, 1 - 1);
lv_spinbox_set_value( ui_AntiFreeze_Temp_Offset_Spinbox, 5 );
lv_obj_set_style_border_color(ui_AntiFreeze_Temp_Offset_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AntiFreeze_Temp_Offset_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AntiFreeze_Temp_Offset_Spinbox, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_AntiFreeze_Temp_Offset_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_AntiFreeze_Temp_Offset_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_AntiFreeze_Temp_Offset_Spinbox, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_blend_mode(ui_AntiFreeze_Temp_Offset_Spinbox, LV_BLEND_MODE_ADDITIVE, LV_PART_CURSOR| LV_STATE_DEFAULT);
lv_obj_set_style_opa(ui_AntiFreeze_Temp_Offset_Spinbox, 0, LV_PART_CURSOR| LV_STATE_DEFAULT);

ui_AntiFreeze_Temp_Offset_Plus_Button = lv_btn_create(ui_AdvancedScreenContainer2);
lv_obj_set_width( ui_AntiFreeze_Temp_Offset_Plus_Button, 45);
lv_obj_set_height( ui_AntiFreeze_Temp_Offset_Plus_Button, 45);
lv_obj_set_x( ui_AntiFreeze_Temp_Offset_Plus_Button, 48 );
lv_obj_set_y( ui_AntiFreeze_Temp_Offset_Plus_Button, 0 );
lv_obj_set_align( ui_AntiFreeze_Temp_Offset_Plus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_AntiFreeze_Temp_Offset_Plus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_AntiFreeze_Temp_Offset_Plus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_AntiFreeze_Temp_Offset_Plus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AntiFreeze_Temp_Offset_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_AntiFreeze_Temp_Offset_Plus_Button, &ui_img_plus_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_AntiFreeze_Temp_Offset_Plus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AntiFreeze_Temp_Offset_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AntiFreeze_Temp_Offset_Plus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_AntiFreeze_Temp_Offset_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_AntiFreeze_Temp_Offset_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_AntiFreeze_Temp_Offset_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_AntiFreeze_Temp_Offset_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AntiFreeze_Temp_Offset_Minus_Button = lv_btn_create(ui_AdvancedScreenContainer2);
lv_obj_set_width( ui_AntiFreeze_Temp_Offset_Minus_Button, 45);
lv_obj_set_height( ui_AntiFreeze_Temp_Offset_Minus_Button, 45);
lv_obj_set_x( ui_AntiFreeze_Temp_Offset_Minus_Button, -48 );
lv_obj_set_y( ui_AntiFreeze_Temp_Offset_Minus_Button, 0 );
lv_obj_set_align( ui_AntiFreeze_Temp_Offset_Minus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_AntiFreeze_Temp_Offset_Minus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_AntiFreeze_Temp_Offset_Minus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_AntiFreeze_Temp_Offset_Minus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AntiFreeze_Temp_Offset_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_AntiFreeze_Temp_Offset_Minus_Button, &ui_img_1731839073, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_AntiFreeze_Temp_Offset_Minus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AntiFreeze_Temp_Offset_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AntiFreeze_Temp_Offset_Minus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_AntiFreeze_Temp_Offset_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_AntiFreeze_Temp_Offset_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_AntiFreeze_Temp_Offset_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_AntiFreeze_Temp_Offset_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lable2235474 = lv_label_create(ui_AdvancedScreenContainer2);
lv_obj_set_width( ui_lable2235474, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lable2235474, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lable2235474, 1 );
lv_obj_set_y( ui_lable2235474, 20 );
lv_obj_set_align( ui_lable2235474, LV_ALIGN_CENTER );
lv_label_set_text(ui_lable2235474," C° ");
lv_obj_set_style_text_color(ui_lable2235474, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_lable2235474, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lable2235474, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_lable2235474, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_lable2235474, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_lable2235474, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AdvancedScreenContainer3 = lv_obj_create(ui_tab1);
lv_obj_remove_style_all(ui_AdvancedScreenContainer3);
lv_obj_set_width( ui_AdvancedScreenContainer3, 150);
lv_obj_set_height( ui_AdvancedScreenContainer3, 70);
lv_obj_set_x( ui_AdvancedScreenContainer3, -80 );
lv_obj_set_y( ui_AdvancedScreenContainer3, 45 );
lv_obj_set_align( ui_AdvancedScreenContainer3, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_AdvancedScreenContainer3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_AdvancedScreenContainer3, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_AdvancedScreenContainer3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AdvancedScreenContainer3, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_AdvancedScreenContainer3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AdvancedScreenContainer3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AdvancedScreenContainer3, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_AdvancedScreenContainer3, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Compressor_Rest_Time_Spinbox = lv_spinbox_create(ui_AdvancedScreenContainer3);
lv_obj_set_width( ui_Compressor_Rest_Time_Spinbox, 45);
lv_obj_set_height( ui_Compressor_Rest_Time_Spinbox, 35);
lv_obj_set_align( ui_Compressor_Rest_Time_Spinbox, LV_ALIGN_CENTER );
lv_spinbox_set_digit_format( ui_Compressor_Rest_Time_Spinbox, 2, 0);
lv_spinbox_set_range( ui_Compressor_Rest_Time_Spinbox, 0,5 );
lv_spinbox_set_cursor_pos(ui_Compressor_Rest_Time_Spinbox, 1 - 1);
lv_spinbox_set_value( ui_Compressor_Rest_Time_Spinbox, 1 );
lv_obj_set_style_border_color(ui_Compressor_Rest_Time_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Compressor_Rest_Time_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Compressor_Rest_Time_Spinbox, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_Compressor_Rest_Time_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Compressor_Rest_Time_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Compressor_Rest_Time_Spinbox, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_blend_mode(ui_Compressor_Rest_Time_Spinbox, LV_BLEND_MODE_ADDITIVE, LV_PART_CURSOR| LV_STATE_DEFAULT);
lv_obj_set_style_opa(ui_Compressor_Rest_Time_Spinbox, 0, LV_PART_CURSOR| LV_STATE_DEFAULT);

ui_Compressor_Rest_Time_Plus_Button = lv_btn_create(ui_AdvancedScreenContainer3);
lv_obj_set_width( ui_Compressor_Rest_Time_Plus_Button, 45);
lv_obj_set_height( ui_Compressor_Rest_Time_Plus_Button, 45);
lv_obj_set_x( ui_Compressor_Rest_Time_Plus_Button, 48 );
lv_obj_set_y( ui_Compressor_Rest_Time_Plus_Button, 0 );
lv_obj_set_align( ui_Compressor_Rest_Time_Plus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Compressor_Rest_Time_Plus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Compressor_Rest_Time_Plus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Compressor_Rest_Time_Plus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Compressor_Rest_Time_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Compressor_Rest_Time_Plus_Button, &ui_img_plus_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_Compressor_Rest_Time_Plus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Compressor_Rest_Time_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Compressor_Rest_Time_Plus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Compressor_Rest_Time_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Compressor_Rest_Time_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Compressor_Rest_Time_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Compressor_Rest_Time_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Compressor_Rest_Time_Minus_Button = lv_btn_create(ui_AdvancedScreenContainer3);
lv_obj_set_width( ui_Compressor_Rest_Time_Minus_Button, 45);
lv_obj_set_height( ui_Compressor_Rest_Time_Minus_Button, 45);
lv_obj_set_x( ui_Compressor_Rest_Time_Minus_Button, -48 );
lv_obj_set_y( ui_Compressor_Rest_Time_Minus_Button, 0 );
lv_obj_set_align( ui_Compressor_Rest_Time_Minus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Compressor_Rest_Time_Minus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Compressor_Rest_Time_Minus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Compressor_Rest_Time_Minus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Compressor_Rest_Time_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Compressor_Rest_Time_Minus_Button, &ui_img_1731839073, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_Compressor_Rest_Time_Minus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Compressor_Rest_Time_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Compressor_Rest_Time_Minus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Compressor_Rest_Time_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Compressor_Rest_Time_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Compressor_Rest_Time_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Compressor_Rest_Time_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_minutelable11 = lv_label_create(ui_AdvancedScreenContainer3);
lv_obj_set_width( ui_minutelable11, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_minutelable11, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_minutelable11, 1 );
lv_obj_set_y( ui_minutelable11, 20 );
lv_obj_set_align( ui_minutelable11, LV_ALIGN_CENTER );
lv_label_set_text(ui_minutelable11," Min ");
lv_obj_set_style_text_color(ui_minutelable11, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_minutelable11, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_minutelable11, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_minutelable11, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_minutelable11, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_minutelable11, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AdvancedScreenContainer4 = lv_obj_create(ui_tab1);
lv_obj_remove_style_all(ui_AdvancedScreenContainer4);
lv_obj_set_width( ui_AdvancedScreenContainer4, 150);
lv_obj_set_height( ui_AdvancedScreenContainer4, 70);
lv_obj_set_x( ui_AdvancedScreenContainer4, 80 );
lv_obj_set_y( ui_AdvancedScreenContainer4, 45 );
lv_obj_set_align( ui_AdvancedScreenContainer4, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_AdvancedScreenContainer4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_AdvancedScreenContainer4, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_AdvancedScreenContainer4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AdvancedScreenContainer4, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_AdvancedScreenContainer4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AdvancedScreenContainer4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AdvancedScreenContainer4, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_AdvancedScreenContainer4, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Filter_Alarm_Spinbox = lv_spinbox_create(ui_AdvancedScreenContainer4);
lv_obj_set_width( ui_Filter_Alarm_Spinbox, 45);
lv_obj_set_height( ui_Filter_Alarm_Spinbox, 35);
lv_obj_set_align( ui_Filter_Alarm_Spinbox, LV_ALIGN_CENTER );
lv_spinbox_set_digit_format( ui_Filter_Alarm_Spinbox, 3, 0);
lv_spinbox_set_range( ui_Filter_Alarm_Spinbox, 60,100 );
lv_spinbox_set_cursor_pos(ui_Filter_Alarm_Spinbox, 1 - 1);
lv_spinbox_set_value( ui_Filter_Alarm_Spinbox, 85 );
lv_obj_set_style_border_color(ui_Filter_Alarm_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Filter_Alarm_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Filter_Alarm_Spinbox, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_Filter_Alarm_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Filter_Alarm_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Filter_Alarm_Spinbox, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_blend_mode(ui_Filter_Alarm_Spinbox, LV_BLEND_MODE_ADDITIVE, LV_PART_CURSOR| LV_STATE_DEFAULT);
lv_obj_set_style_opa(ui_Filter_Alarm_Spinbox, 0, LV_PART_CURSOR| LV_STATE_DEFAULT);

ui_Filter_Alarm_Plus_Button = lv_btn_create(ui_AdvancedScreenContainer4);
lv_obj_set_width( ui_Filter_Alarm_Plus_Button, 45);
lv_obj_set_height( ui_Filter_Alarm_Plus_Button, 45);
lv_obj_set_x( ui_Filter_Alarm_Plus_Button, 48 );
lv_obj_set_y( ui_Filter_Alarm_Plus_Button, 0 );
lv_obj_set_align( ui_Filter_Alarm_Plus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Filter_Alarm_Plus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Filter_Alarm_Plus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Filter_Alarm_Plus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Filter_Alarm_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Filter_Alarm_Plus_Button, &ui_img_plus_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_Filter_Alarm_Plus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Filter_Alarm_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Filter_Alarm_Plus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Filter_Alarm_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Filter_Alarm_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Filter_Alarm_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Filter_Alarm_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Filter_Alarm_Minus_Button = lv_btn_create(ui_AdvancedScreenContainer4);
lv_obj_set_width( ui_Filter_Alarm_Minus_Button, 45);
lv_obj_set_height( ui_Filter_Alarm_Minus_Button, 45);
lv_obj_set_x( ui_Filter_Alarm_Minus_Button, -48 );
lv_obj_set_y( ui_Filter_Alarm_Minus_Button, 0 );
lv_obj_set_align( ui_Filter_Alarm_Minus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Filter_Alarm_Minus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Filter_Alarm_Minus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Filter_Alarm_Minus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Filter_Alarm_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Filter_Alarm_Minus_Button, &ui_img_1731839073, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_Filter_Alarm_Minus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Filter_Alarm_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Filter_Alarm_Minus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Filter_Alarm_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Filter_Alarm_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Filter_Alarm_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Filter_Alarm_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lable29854 = lv_label_create(ui_AdvancedScreenContainer4);
lv_obj_set_width( ui_lable29854, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lable29854, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lable29854, 1 );
lv_obj_set_y( ui_lable29854, 20 );
lv_obj_set_align( ui_lable29854, LV_ALIGN_CENTER );
lv_label_set_text(ui_lable29854," C° ");
lv_obj_set_style_text_color(ui_lable29854, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_lable29854, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lable29854, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_lable29854, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_lable29854, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_lable29854, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Compressor_Rest_Time_Label = lv_label_create(ui_tab1);
lv_obj_set_width( ui_Compressor_Rest_Time_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Compressor_Rest_Time_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Compressor_Rest_Time_Label, -80 );
lv_obj_set_y( ui_Compressor_Rest_Time_Label, 10 );
lv_obj_set_align( ui_Compressor_Rest_Time_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Compressor_Rest_Time_Label," Comp Rest Time ");
lv_obj_set_style_text_color(ui_Compressor_Rest_Time_Label, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Compressor_Rest_Time_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Compressor_Rest_Time_Label, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_Compressor_Rest_Time_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Compressor_Rest_Time_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Compressor_Rest_Time_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AntiFreeze_Temp_Offset_Label = lv_label_create(ui_tab1);
lv_obj_set_width( ui_AntiFreeze_Temp_Offset_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_AntiFreeze_Temp_Offset_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_AntiFreeze_Temp_Offset_Label, 80 );
lv_obj_set_y( ui_AntiFreeze_Temp_Offset_Label, -70 );
lv_obj_set_align( ui_AntiFreeze_Temp_Offset_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_AntiFreeze_Temp_Offset_Label," AntiFreeze Range ");
lv_obj_set_style_text_color(ui_AntiFreeze_Temp_Offset_Label, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_AntiFreeze_Temp_Offset_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_AntiFreeze_Temp_Offset_Label, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_AntiFreeze_Temp_Offset_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_AntiFreeze_Temp_Offset_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AntiFreeze_Temp_Offset_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AntiFreeze_Temp_Range_Label = lv_label_create(ui_tab1);
lv_obj_set_width( ui_AntiFreeze_Temp_Range_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_AntiFreeze_Temp_Range_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_AntiFreeze_Temp_Range_Label, -80 );
lv_obj_set_y( ui_AntiFreeze_Temp_Range_Label, -70 );
lv_obj_set_align( ui_AntiFreeze_Temp_Range_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_AntiFreeze_Temp_Range_Label," AntiFreeze ");
lv_obj_set_style_text_color(ui_AntiFreeze_Temp_Range_Label, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_AntiFreeze_Temp_Range_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_AntiFreeze_Temp_Range_Label, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_AntiFreeze_Temp_Range_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_AntiFreeze_Temp_Range_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AntiFreeze_Temp_Range_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Filter_Alarm__Range_Label = lv_label_create(ui_tab1);
lv_obj_set_width( ui_Filter_Alarm__Range_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Filter_Alarm__Range_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Filter_Alarm__Range_Label, 80 );
lv_obj_set_y( ui_Filter_Alarm__Range_Label, 10 );
lv_obj_set_align( ui_Filter_Alarm__Range_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Filter_Alarm__Range_Label," Filter Alarm ");
lv_obj_set_style_text_color(ui_Filter_Alarm__Range_Label, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Filter_Alarm__Range_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Filter_Alarm__Range_Label, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_Filter_Alarm__Range_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Filter_Alarm__Range_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Filter_Alarm__Range_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_tab2 = lv_tabview_add_tab(ui_TabView1, "2");
lv_obj_add_flag( ui_tab2, LV_OBJ_FLAG_CHECKABLE );   /// Flags
lv_obj_clear_flag( ui_tab2, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_style_bg_color(ui_tab2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_tab2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AdvancedScreenContainer5 = lv_obj_create(ui_tab2);
lv_obj_remove_style_all(ui_AdvancedScreenContainer5);
lv_obj_set_width( ui_AdvancedScreenContainer5, 300);
lv_obj_set_height( ui_AdvancedScreenContainer5, 75);
lv_obj_set_x( ui_AdvancedScreenContainer5, 0 );
lv_obj_set_y( ui_AdvancedScreenContainer5, -35 );
lv_obj_set_align( ui_AdvancedScreenContainer5, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_AdvancedScreenContainer5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_AdvancedScreenContainer5, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_AdvancedScreenContainer5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AdvancedScreenContainer5, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_AdvancedScreenContainer5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AdvancedScreenContainer5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AdvancedScreenContainer5, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_AdvancedScreenContainer5, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_fan_2_range_Spinbox = lv_spinbox_create(ui_AdvancedScreenContainer5);
lv_obj_set_width( ui_fan_2_range_Spinbox, 45);
lv_obj_set_height( ui_fan_2_range_Spinbox, 35);
lv_obj_set_x( ui_fan_2_range_Spinbox, 70 );
lv_obj_set_y( ui_fan_2_range_Spinbox, 5 );
lv_obj_set_align( ui_fan_2_range_Spinbox, LV_ALIGN_CENTER );
lv_obj_add_state( ui_fan_2_range_Spinbox, LV_STATE_DISABLED );     /// States
lv_spinbox_set_digit_format( ui_fan_2_range_Spinbox, 2, 0);
lv_spinbox_set_range( ui_fan_2_range_Spinbox, 30,85 );
lv_spinbox_set_cursor_pos(ui_fan_2_range_Spinbox, 1 - 1);
lv_spinbox_set_value( ui_fan_2_range_Spinbox, 44 );
lv_obj_set_style_border_color(ui_fan_2_range_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_fan_2_range_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_fan_2_range_Spinbox, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_fan_2_range_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_fan_2_range_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_fan_2_range_Spinbox, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_blend_mode(ui_fan_2_range_Spinbox, LV_BLEND_MODE_ADDITIVE, LV_PART_CURSOR| LV_STATE_DEFAULT);
lv_obj_set_style_opa(ui_fan_2_range_Spinbox, 0, LV_PART_CURSOR| LV_STATE_DEFAULT);

ui_fan_2_range_Plus_Button = lv_btn_create(ui_AdvancedScreenContainer5);
lv_obj_set_width( ui_fan_2_range_Plus_Button, 45);
lv_obj_set_height( ui_fan_2_range_Plus_Button, 45);
lv_obj_set_x( ui_fan_2_range_Plus_Button, 120 );
lv_obj_set_y( ui_fan_2_range_Plus_Button, 5 );
lv_obj_set_align( ui_fan_2_range_Plus_Button, LV_ALIGN_CENTER );
lv_obj_add_state( ui_fan_2_range_Plus_Button, LV_STATE_DISABLED );     /// States
lv_obj_add_flag( ui_fan_2_range_Plus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_fan_2_range_Plus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_fan_2_range_Plus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_fan_2_range_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_fan_2_range_Plus_Button, &ui_img_plus_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_fan_2_range_Plus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_fan_2_range_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_fan_2_range_Plus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_fan_2_range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_fan_2_range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_fan_2_range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_fan_2_range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_fan_2_range_Minus_Button = lv_btn_create(ui_AdvancedScreenContainer5);
lv_obj_set_width( ui_fan_2_range_Minus_Button, 45);
lv_obj_set_height( ui_fan_2_range_Minus_Button, 45);
lv_obj_set_x( ui_fan_2_range_Minus_Button, 20 );
lv_obj_set_y( ui_fan_2_range_Minus_Button, 5 );
lv_obj_set_align( ui_fan_2_range_Minus_Button, LV_ALIGN_CENTER );
lv_obj_add_state( ui_fan_2_range_Minus_Button, LV_STATE_DISABLED );     /// States
lv_obj_add_flag( ui_fan_2_range_Minus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_fan_2_range_Minus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_fan_2_range_Minus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_fan_2_range_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_fan_2_range_Minus_Button, &ui_img_1731839073, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_fan_2_range_Minus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_fan_2_range_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_fan_2_range_Minus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_fan_2_range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_fan_2_range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_fan_2_range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_fan_2_range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_fan_2_Switch = lv_switch_create(ui_AdvancedScreenContainer5);
lv_obj_set_width( ui_fan_2_Switch, 50);
lv_obj_set_height( ui_fan_2_Switch, 25);
lv_obj_set_x( ui_fan_2_Switch, -45 );
lv_obj_set_y( ui_fan_2_Switch, 5 );
lv_obj_set_align( ui_fan_2_Switch, LV_ALIGN_CENTER );
lv_obj_set_style_bg_color(ui_fan_2_Switch, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_fan_2_Switch, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_fan_2_Switch, lv_color_hex(0x00B639), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_fan_2_Switch, 255, LV_PART_MAIN| LV_STATE_CHECKED);

lv_obj_set_style_bg_color(ui_fan_2_Switch, lv_color_hex(0x00B639), LV_PART_INDICATOR | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_fan_2_Switch, 255, LV_PART_INDICATOR| LV_STATE_CHECKED);

ui_enable_fan_2_Label = lv_label_create(ui_AdvancedScreenContainer5);
lv_obj_set_width( ui_enable_fan_2_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_enable_fan_2_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_enable_fan_2_Label, -110 );
lv_obj_set_y( ui_enable_fan_2_Label, 5 );
lv_obj_set_align( ui_enable_fan_2_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_enable_fan_2_Label,"Enabled");
lv_obj_add_flag( ui_enable_fan_2_Label, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_enable_fan_2_Label, lv_color_hex(0x00BE10), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_enable_fan_2_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_enable_fan_2_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_disable_fan_2_Label = lv_label_create(ui_AdvancedScreenContainer5);
lv_obj_set_width( ui_disable_fan_2_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_disable_fan_2_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_disable_fan_2_Label, -110 );
lv_obj_set_y( ui_disable_fan_2_Label, 4 );
lv_obj_set_align( ui_disable_fan_2_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_disable_fan_2_Label,"Disabled");
lv_obj_add_flag( ui_disable_fan_2_Label, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_disable_fan_2_Label, lv_color_hex(0xFF0400), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_disable_fan_2_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_disable_fan_2_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lable29988 = lv_label_create(ui_AdvancedScreenContainer5);
lv_obj_set_width( ui_lable29988, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lable29988, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lable29988, 70 );
lv_obj_set_y( ui_lable29988, 23 );
lv_obj_set_align( ui_lable29988, LV_ALIGN_CENTER );
lv_label_set_text(ui_lable29988," C° ");
lv_obj_set_style_text_color(ui_lable29988, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_lable29988, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_lable29988, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_lable29988, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_lable29988, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_lable29988, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_fan_2_range_Label = lv_label_create(ui_tab2);
lv_obj_set_width( ui_fan_2_range_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_fan_2_range_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_fan_2_range_Label, 0 );
lv_obj_set_y( ui_fan_2_range_Label, -72 );
lv_obj_set_align( ui_fan_2_range_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_fan_2_range_Label,"  Fan 2  ");
lv_obj_set_style_text_color(ui_fan_2_range_Label, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_fan_2_range_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_fan_2_range_Label, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_fan_2_range_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_fan_2_range_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_fan_2_range_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AdvancedScreenContainer6 = lv_obj_create(ui_tab2);
lv_obj_remove_style_all(ui_AdvancedScreenContainer6);
lv_obj_set_width( ui_AdvancedScreenContainer6, 150);
lv_obj_set_height( ui_AdvancedScreenContainer6, 60);
lv_obj_set_x( ui_AdvancedScreenContainer6, -75 );
lv_obj_set_y( ui_AdvancedScreenContainer6, 50 );
lv_obj_set_align( ui_AdvancedScreenContainer6, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_AdvancedScreenContainer6, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_AdvancedScreenContainer6, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_AdvancedScreenContainer6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AdvancedScreenContainer6, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_AdvancedScreenContainer6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AdvancedScreenContainer6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AdvancedScreenContainer6, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_AdvancedScreenContainer6, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_door_alarm_status_Switch = lv_switch_create(ui_AdvancedScreenContainer6);
lv_obj_set_width( ui_door_alarm_status_Switch, 50);
lv_obj_set_height( ui_door_alarm_status_Switch, 25);
lv_obj_set_x( ui_door_alarm_status_Switch, 40 );
lv_obj_set_y( ui_door_alarm_status_Switch, 0 );
lv_obj_set_align( ui_door_alarm_status_Switch, LV_ALIGN_CENTER );
lv_obj_add_state( ui_door_alarm_status_Switch, LV_STATE_CHECKED );     /// States
lv_obj_set_style_bg_color(ui_door_alarm_status_Switch, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_door_alarm_status_Switch, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_door_alarm_status_Switch, lv_color_hex(0x00B639), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_door_alarm_status_Switch, 255, LV_PART_MAIN| LV_STATE_CHECKED);

lv_obj_set_style_bg_color(ui_door_alarm_status_Switch, lv_color_hex(0x00B639), LV_PART_INDICATOR | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_door_alarm_status_Switch, 255, LV_PART_INDICATOR| LV_STATE_CHECKED);

ui_enable_door_alarm_status_Label = lv_label_create(ui_AdvancedScreenContainer6);
lv_obj_set_width( ui_enable_door_alarm_status_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_enable_door_alarm_status_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_enable_door_alarm_status_Label, -30 );
lv_obj_set_y( ui_enable_door_alarm_status_Label, 0 );
lv_obj_set_align( ui_enable_door_alarm_status_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_enable_door_alarm_status_Label,"Enabled");
lv_obj_add_flag( ui_enable_door_alarm_status_Label, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_enable_door_alarm_status_Label, lv_color_hex(0x00BE10), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_enable_door_alarm_status_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_enable_door_alarm_status_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_disable_door_alarm_status_Label = lv_label_create(ui_AdvancedScreenContainer6);
lv_obj_set_width( ui_disable_door_alarm_status_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_disable_door_alarm_status_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_disable_door_alarm_status_Label, -30 );
lv_obj_set_y( ui_disable_door_alarm_status_Label, 0 );
lv_obj_set_align( ui_disable_door_alarm_status_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_disable_door_alarm_status_Label,"Disabled");
lv_obj_add_flag( ui_disable_door_alarm_status_Label, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_disable_door_alarm_status_Label, lv_color_hex(0xFF0400), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_disable_door_alarm_status_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_disable_door_alarm_status_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_door_function_and_alarm_Label = lv_label_create(ui_tab2);
lv_obj_set_width( ui_door_function_and_alarm_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_door_function_and_alarm_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_door_function_and_alarm_Label, -75 );
lv_obj_set_y( ui_door_function_and_alarm_Label, 20 );
lv_obj_set_align( ui_door_function_and_alarm_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_door_function_and_alarm_Label,"  Door Alarm & State  ");
lv_obj_set_style_text_color(ui_door_function_and_alarm_Label, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_door_function_and_alarm_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_door_function_and_alarm_Label, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_door_function_and_alarm_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_door_function_and_alarm_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_door_function_and_alarm_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AdvancedScreenContainer7 = lv_obj_create(ui_tab2);
lv_obj_remove_style_all(ui_AdvancedScreenContainer7);
lv_obj_set_width( ui_AdvancedScreenContainer7, 150);
lv_obj_set_height( ui_AdvancedScreenContainer7, 60);
lv_obj_set_x( ui_AdvancedScreenContainer7, 80 );
lv_obj_set_y( ui_AdvancedScreenContainer7, 50 );
lv_obj_set_align( ui_AdvancedScreenContainer7, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_AdvancedScreenContainer7, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_AdvancedScreenContainer7, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_AdvancedScreenContainer7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_AdvancedScreenContainer7, 127, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_AdvancedScreenContainer7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_AdvancedScreenContainer7, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_AdvancedScreenContainer7, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_AdvancedScreenContainer7, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_filter_alarm_status_Switch = lv_switch_create(ui_AdvancedScreenContainer7);
lv_obj_set_width( ui_filter_alarm_status_Switch, 50);
lv_obj_set_height( ui_filter_alarm_status_Switch, 25);
lv_obj_set_x( ui_filter_alarm_status_Switch, 40 );
lv_obj_set_y( ui_filter_alarm_status_Switch, 0 );
lv_obj_set_align( ui_filter_alarm_status_Switch, LV_ALIGN_CENTER );
lv_obj_add_state( ui_filter_alarm_status_Switch, LV_STATE_CHECKED );     /// States
lv_obj_set_style_bg_color(ui_filter_alarm_status_Switch, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_filter_alarm_status_Switch, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_filter_alarm_status_Switch, lv_color_hex(0x00B639), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_filter_alarm_status_Switch, 255, LV_PART_MAIN| LV_STATE_CHECKED);

lv_obj_set_style_bg_color(ui_filter_alarm_status_Switch, lv_color_hex(0x00B639), LV_PART_INDICATOR | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_filter_alarm_status_Switch, 255, LV_PART_INDICATOR| LV_STATE_CHECKED);

ui_enable_filter_alarm_status_Label = lv_label_create(ui_AdvancedScreenContainer7);
lv_obj_set_width( ui_enable_filter_alarm_status_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_enable_filter_alarm_status_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_enable_filter_alarm_status_Label, -30 );
lv_obj_set_y( ui_enable_filter_alarm_status_Label, 0 );
lv_obj_set_align( ui_enable_filter_alarm_status_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_enable_filter_alarm_status_Label,"Enabled");
lv_obj_add_flag( ui_enable_filter_alarm_status_Label, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_enable_filter_alarm_status_Label, lv_color_hex(0x00BE10), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_enable_filter_alarm_status_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_enable_filter_alarm_status_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_disable_filter_alarm_status_Label = lv_label_create(ui_AdvancedScreenContainer7);
lv_obj_set_width( ui_disable_filter_alarm_status_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_disable_filter_alarm_status_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_disable_filter_alarm_status_Label, -30 );
lv_obj_set_y( ui_disable_filter_alarm_status_Label, 0 );
lv_obj_set_align( ui_disable_filter_alarm_status_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_disable_filter_alarm_status_Label,"Disabled");
lv_obj_add_flag( ui_disable_filter_alarm_status_Label, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_disable_filter_alarm_status_Label, lv_color_hex(0xFF0400), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_disable_filter_alarm_status_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_disable_filter_alarm_status_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Filter_alarm_switch_Label = lv_label_create(ui_tab2);
lv_obj_set_width( ui_Filter_alarm_switch_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Filter_alarm_switch_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Filter_alarm_switch_Label, 75 );
lv_obj_set_y( ui_Filter_alarm_switch_Label, 20 );
lv_obj_set_align( ui_Filter_alarm_switch_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Filter_alarm_switch_Label,"  Filter Alarm  ");
lv_obj_set_style_text_color(ui_Filter_alarm_switch_Label, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Filter_alarm_switch_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Filter_alarm_switch_Label, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_Filter_alarm_switch_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Filter_alarm_switch_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Filter_alarm_switch_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_tab3 = lv_tabview_add_tab(ui_TabView1, "3");
lv_obj_add_flag( ui_tab3, LV_OBJ_FLAG_CHECKABLE );   /// Flags
lv_obj_clear_flag( ui_tab3, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_style_bg_color(ui_tab3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_tab3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label456 = lv_label_create(ui_tab3);
lv_obj_set_width( ui_Label456, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label456, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label456, 0 );
lv_obj_set_y( ui_Label456, -75 );
lv_obj_set_align( ui_Label456, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label456,"------------------------");
lv_obj_set_style_text_color(ui_Label456, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label456, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label456, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Sensor_Setup_Button = lv_btn_create(ui_tab3);
lv_obj_set_width( ui_Sensor_Setup_Button, 150);
lv_obj_set_height( ui_Sensor_Setup_Button, 45);
lv_obj_set_x( ui_Sensor_Setup_Button, -80 );
lv_obj_set_y( ui_Sensor_Setup_Button, -30 );
lv_obj_set_align( ui_Sensor_Setup_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Sensor_Setup_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Sensor_Setup_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Sensor_Setup_Button, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Sensor_Setup_Button, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Sensor_Setup_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Sensor_Setup_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Sensor_Setup_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Sensor_Setup_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Sensor_Setup_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Sensor_Setup_Button_Label = lv_label_create(ui_tab3);
lv_obj_set_width( ui_Sensor_Setup_Button_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Sensor_Setup_Button_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Sensor_Setup_Button_Label, -80 );
lv_obj_set_y( ui_Sensor_Setup_Button_Label, -30 );
lv_obj_set_align( ui_Sensor_Setup_Button_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Sensor_Setup_Button_Label,"SETUP SENSORS");
lv_obj_set_style_text_color(ui_Sensor_Setup_Button_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Sensor_Setup_Button_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Sensor_Setup_Button_Label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label123 = lv_label_create(ui_tab3);
lv_obj_set_width( ui_Label123, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label123, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label123, 0 );
lv_obj_set_y( ui_Label123, 10 );
lv_obj_set_align( ui_Label123, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label123,"-----------");
lv_obj_set_style_text_color(ui_Label123, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label123, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label123, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_open_factory_reset_panel = lv_btn_create(ui_tab3);
lv_obj_set_width( ui_open_factory_reset_panel, 150);
lv_obj_set_height( ui_open_factory_reset_panel, 45);
lv_obj_set_x( ui_open_factory_reset_panel, 80 );
lv_obj_set_y( ui_open_factory_reset_panel, -30 );
lv_obj_set_align( ui_open_factory_reset_panel, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_open_factory_reset_panel, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_open_factory_reset_panel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_open_factory_reset_panel, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_open_factory_reset_panel, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_open_factory_reset_panel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_open_factory_reset_panel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_open_factory_reset_panel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_open_factory_reset_panel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_open_factory_reset_panel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_factory_reset_btn_Label = lv_label_create(ui_tab3);
lv_obj_set_width( ui_factory_reset_btn_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_factory_reset_btn_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_factory_reset_btn_Label, 80 );
lv_obj_set_y( ui_factory_reset_btn_Label, -30 );
lv_obj_set_align( ui_factory_reset_btn_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_factory_reset_btn_Label,"FACTORY RESET");
lv_obj_set_style_text_color(ui_factory_reset_btn_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_factory_reset_btn_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_factory_reset_btn_Label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_DEVICE_RESTART_Button = lv_btn_create(ui_tab3);
lv_obj_set_width( ui_DEVICE_RESTART_Button, 150);
lv_obj_set_height( ui_DEVICE_RESTART_Button, 45);
lv_obj_set_x( ui_DEVICE_RESTART_Button, -80 );
lv_obj_set_y( ui_DEVICE_RESTART_Button, 50 );
lv_obj_set_align( ui_DEVICE_RESTART_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_DEVICE_RESTART_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_DEVICE_RESTART_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_DEVICE_RESTART_Button, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_DEVICE_RESTART_Button, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_DEVICE_RESTART_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_DEVICE_RESTART_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_DEVICE_RESTART_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_DEVICE_RESTART_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_DEVICE_RESTART_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_DEVICE_RESTART_Button_Label = lv_label_create(ui_tab3);
lv_obj_set_width( ui_DEVICE_RESTART_Button_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_DEVICE_RESTART_Button_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_DEVICE_RESTART_Button_Label, -80 );
lv_obj_set_y( ui_DEVICE_RESTART_Button_Label, 50 );
lv_obj_set_align( ui_DEVICE_RESTART_Button_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_DEVICE_RESTART_Button_Label,"RESTART DEVICE");
lv_obj_set_style_text_color(ui_DEVICE_RESTART_Button_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_DEVICE_RESTART_Button_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_DEVICE_RESTART_Button_Label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_sensors_setup_container = lv_obj_create(ui_addvansedSettingScreen);
lv_obj_remove_style_all(ui_sensors_setup_container);
lv_obj_set_width( ui_sensors_setup_container, 320);
lv_obj_set_height( ui_sensors_setup_container, 240);
lv_obj_set_align( ui_sensors_setup_container, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_sensors_setup_container, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_sensors_setup_container, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_sensors_setup_container, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_sensors_setup_container, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_sensors_setup_container, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Sensor_Setup_Notice_Container = lv_obj_create(ui_sensors_setup_container);
lv_obj_remove_style_all(ui_Sensor_Setup_Notice_Container);
lv_obj_set_width( ui_Sensor_Setup_Notice_Container, 320);
lv_obj_set_height( ui_Sensor_Setup_Notice_Container, 240);
lv_obj_set_align( ui_Sensor_Setup_Notice_Container, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Sensor_Setup_Notice_Container, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Sensor_Setup_Notice_Container, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Sensor_Setup_Notice_Container, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Sensor_Setup_Notice_Container, &ui_img_1234_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_Reset_Notice_Label = lv_label_create(ui_Sensor_Setup_Notice_Container);
lv_obj_set_width( ui_Reset_Notice_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Reset_Notice_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Reset_Notice_Label, 0 );
lv_obj_set_y( ui_Reset_Notice_Label, -100 );
lv_obj_set_align( ui_Reset_Notice_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Reset_Notice_Label,"Starting Setup Temp Sensors?");
lv_obj_set_style_text_color(ui_Reset_Notice_Label, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Reset_Notice_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Reset_Notice_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Reset_Notice_Label, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_submitResetbtn = lv_btn_create(ui_Sensor_Setup_Notice_Container);
lv_obj_set_width( ui_submitResetbtn, 80);
lv_obj_set_height( ui_submitResetbtn, 35);
lv_obj_set_x( ui_submitResetbtn, 50 );
lv_obj_set_y( ui_submitResetbtn, 85 );
lv_obj_set_align( ui_submitResetbtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_submitResetbtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_submitResetbtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_submitResetbtn, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_submitResetbtn, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_submitResetbtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_submitResetbtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_submitResetbtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_submitResetbtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_submitResetbtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CancelResetbtn = lv_btn_create(ui_Sensor_Setup_Notice_Container);
lv_obj_set_width( ui_CancelResetbtn, 80);
lv_obj_set_height( ui_CancelResetbtn, 35);
lv_obj_set_x( ui_CancelResetbtn, -50 );
lv_obj_set_y( ui_CancelResetbtn, 85 );
lv_obj_set_align( ui_CancelResetbtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_CancelResetbtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_CancelResetbtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_CancelResetbtn, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_CancelResetbtn, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_CancelResetbtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_CancelResetbtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_CancelResetbtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_CancelResetbtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_CancelResetbtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_submitResetbtn_Label = lv_label_create(ui_Sensor_Setup_Notice_Container);
lv_obj_set_width( ui_submitResetbtn_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_submitResetbtn_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_submitResetbtn_Label, 50 );
lv_obj_set_y( ui_submitResetbtn_Label, 85 );
lv_obj_set_align( ui_submitResetbtn_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_submitResetbtn_Label,"YES");
lv_obj_set_style_text_color(ui_submitResetbtn_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_submitResetbtn_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_submitResetbtn_Label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CancelResetbtn_Label = lv_label_create(ui_Sensor_Setup_Notice_Container);
lv_obj_set_width( ui_CancelResetbtn_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_CancelResetbtn_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_CancelResetbtn_Label, -50 );
lv_obj_set_y( ui_CancelResetbtn_Label, 85 );
lv_obj_set_align( ui_CancelResetbtn_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_CancelResetbtn_Label,"CANCEL");
lv_obj_set_style_text_color(ui_CancelResetbtn_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_CancelResetbtn_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_CancelResetbtn_Label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SensorSetupDangerIcon = lv_img_create(ui_Sensor_Setup_Notice_Container);
lv_img_set_src(ui_SensorSetupDangerIcon, &ui_img_1019942150);
lv_obj_set_width( ui_SensorSetupDangerIcon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SensorSetupDangerIcon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SensorSetupDangerIcon, 0 );
lv_obj_set_y( ui_SensorSetupDangerIcon, -60 );
lv_obj_set_align( ui_SensorSetupDangerIcon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_SensorSetupDangerIcon, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_SensorSetupDangerIcon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_shadow_width(ui_SensorSetupDangerIcon, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_SensorSetupDangerIcon, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_SensorSetupDangerIcon, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_SensorSetupDangerIcon, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Reseting_Sensors_Notice_2 = lv_label_create(ui_Sensor_Setup_Notice_Container);
lv_obj_set_width( ui_Reseting_Sensors_Notice_2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Reseting_Sensors_Notice_2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Reseting_Sensors_Notice_2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Reseting_Sensors_Notice_2,"Warning\nThis action will affect the technical\nsettings of the device and if it fails,\nuntil resetup the system will not work!");
lv_obj_set_style_text_color(ui_Reseting_Sensors_Notice_2, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Reseting_Sensors_Notice_2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Reseting_Sensors_Notice_2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Reseting_Sensors_Notice_2, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Reseting_Sensors_Notice_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Reseting_Sensors_Notice_2, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Sensor_Setup_main_Container_1 = lv_obj_create(ui_sensors_setup_container);
lv_obj_remove_style_all(ui_Sensor_Setup_main_Container_1);
lv_obj_set_width( ui_Sensor_Setup_main_Container_1, 320);
lv_obj_set_height( ui_Sensor_Setup_main_Container_1, 240);
lv_obj_set_align( ui_Sensor_Setup_main_Container_1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Sensor_Setup_main_Container_1, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_Sensor_Setup_main_Container_1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Sensor_Setup_main_Container_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Sensor_Setup_main_Container_1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Sensor_Setup_main_Container_1, &ui_img_1234_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_returnButton668 = lv_btn_create(ui_Sensor_Setup_main_Container_1);
lv_obj_set_width( ui_returnButton668, 60);
lv_obj_set_height( ui_returnButton668, 30);
lv_obj_set_x( ui_returnButton668, -125 );
lv_obj_set_y( ui_returnButton668, -100 );
lv_obj_set_align( ui_returnButton668, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_returnButton668, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_returnButton668, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_returnButton668, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_returnButton668, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_returnButton668, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_returnButton668, &ui_img_return_66_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_width(ui_returnButton668, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_returnButton668, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_returnButton668, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_returnButton668, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_disconnect_sensors_Label = lv_label_create(ui_Sensor_Setup_main_Container_1);
lv_obj_set_width( ui_disconnect_sensors_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_disconnect_sensors_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_disconnect_sensors_Label, 0 );
lv_obj_set_y( ui_disconnect_sensors_Label, -65 );
lv_obj_set_align( ui_disconnect_sensors_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_disconnect_sensors_Label,"Please Disconnect All Sensors");
lv_obj_set_style_text_color(ui_disconnect_sensors_Label, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_disconnect_sensors_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_disconnect_sensors_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_disconnect_sensors_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Detail_Success_Status_message_1 = lv_label_create(ui_Sensor_Setup_main_Container_1);
lv_obj_set_width( ui_Detail_Success_Status_message_1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Detail_Success_Status_message_1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Detail_Success_Status_message_1, 0 );
lv_obj_set_y( ui_Detail_Success_Status_message_1, 20 );
lv_obj_set_align( ui_Detail_Success_Status_message_1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Detail_Success_Status_message_1,"Error 4 Sensor Conected");
lv_obj_add_flag( ui_Detail_Success_Status_message_1, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_Detail_Success_Status_message_1, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Detail_Success_Status_message_1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Detail_Success_Status_message_1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Detail_Success_Status_message_1, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Detail_Success_Status_message_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Detail_Success_Status_message_1, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Detail_Success_Status_message_2 = lv_label_create(ui_Sensor_Setup_main_Container_1);
lv_obj_set_width( ui_Detail_Success_Status_message_2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Detail_Success_Status_message_2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Detail_Success_Status_message_2, 0 );
lv_obj_set_y( ui_Detail_Success_Status_message_2, 15 );
lv_obj_set_align( ui_Detail_Success_Status_message_2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Detail_Success_Status_message_2,"OK, All Sensor Disconnected...");
lv_obj_add_flag( ui_Detail_Success_Status_message_2, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_Detail_Success_Status_message_2, lv_color_hex(0x006A09), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Detail_Success_Status_message_2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Detail_Success_Status_message_2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Detail_Success_Status_message_2, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Detail_Success_Status_message_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Detail_Success_Status_message_2, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_disconnect_error_icon = lv_img_create(ui_Sensor_Setup_main_Container_1);
lv_img_set_src(ui_disconnect_error_icon, &ui_img_1019942150);
lv_obj_set_width( ui_disconnect_error_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_disconnect_error_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_disconnect_error_icon, 0 );
lv_obj_set_y( ui_disconnect_error_icon, -25 );
lv_obj_set_align( ui_disconnect_error_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_disconnect_error_icon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_disconnect_error_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_success_disconnect_icon = lv_img_create(ui_Sensor_Setup_main_Container_1);
lv_img_set_src(ui_success_disconnect_icon, &ui_img_unread_png);
lv_obj_set_width( ui_success_disconnect_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_success_disconnect_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_success_disconnect_icon, 0 );
lv_obj_set_y( ui_success_disconnect_icon, -25 );
lv_obj_set_align( ui_success_disconnect_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_success_disconnect_icon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_success_disconnect_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_check_and_next_btn_1 = lv_btn_create(ui_Sensor_Setup_main_Container_1);
lv_obj_set_width( ui_check_and_next_btn_1, 80);
lv_obj_set_height( ui_check_and_next_btn_1, 35);
lv_obj_set_x( ui_check_and_next_btn_1, 0 );
lv_obj_set_y( ui_check_and_next_btn_1, 85 );
lv_obj_set_align( ui_check_and_next_btn_1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_check_and_next_btn_1, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_check_and_next_btn_1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_check_and_next_btn_1, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_check_and_next_btn_1, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_check_and_next_btn_1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_check_and_next_btn_1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_check_and_next_btn_1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_check_and_next_btn_1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_check_and_next_btn_1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_check_and_next_btn_1_label = lv_label_create(ui_Sensor_Setup_main_Container_1);
lv_obj_set_width( ui_check_and_next_btn_1_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_check_and_next_btn_1_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_check_and_next_btn_1_label, 0 );
lv_obj_set_y( ui_check_and_next_btn_1_label, 85 );
lv_obj_set_align( ui_check_and_next_btn_1_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_check_and_next_btn_1_label,"NEXT");
lv_obj_set_style_text_color(ui_check_and_next_btn_1_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_check_and_next_btn_1_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_check_and_next_btn_1_label, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_check_and_next_btn_1_label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_check_and_next_btn_1_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_check_and_next_btn_1_label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Sensor_Setup_main_Container_2 = lv_obj_create(ui_sensors_setup_container);
lv_obj_remove_style_all(ui_Sensor_Setup_main_Container_2);
lv_obj_set_width( ui_Sensor_Setup_main_Container_2, 320);
lv_obj_set_height( ui_Sensor_Setup_main_Container_2, 240);
lv_obj_set_align( ui_Sensor_Setup_main_Container_2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Sensor_Setup_main_Container_2, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_Sensor_Setup_main_Container_2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Sensor_Setup_main_Container_2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Sensor_Setup_main_Container_2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Sensor_Setup_main_Container_2, &ui_img_1234_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_returnButton6987 = lv_btn_create(ui_Sensor_Setup_main_Container_2);
lv_obj_set_width( ui_returnButton6987, 60);
lv_obj_set_height( ui_returnButton6987, 30);
lv_obj_set_x( ui_returnButton6987, -125 );
lv_obj_set_y( ui_returnButton6987, -100 );
lv_obj_set_align( ui_returnButton6987, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_returnButton6987, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_returnButton6987, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_returnButton6987, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_returnButton6987, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_returnButton6987, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_returnButton6987, &ui_img_return_66_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_width(ui_returnButton6987, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_returnButton6987, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_returnButton6987, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_returnButton6987, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Connect_Inlet_Label = lv_label_create(ui_Sensor_Setup_main_Container_2);
lv_obj_set_width( ui_Connect_Inlet_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Connect_Inlet_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Connect_Inlet_Label, 0 );
lv_obj_set_y( ui_Connect_Inlet_Label, -65 );
lv_obj_set_align( ui_Connect_Inlet_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Connect_Inlet_Label,"Please Connect INLET Sensor");
lv_obj_set_style_text_color(ui_Connect_Inlet_Label, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Connect_Inlet_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Connect_Inlet_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Connect_Inlet_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Detail_Success_Status_message_3 = lv_label_create(ui_Sensor_Setup_main_Container_2);
lv_obj_set_width( ui_Detail_Success_Status_message_3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Detail_Success_Status_message_3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Detail_Success_Status_message_3, 0 );
lv_obj_set_y( ui_Detail_Success_Status_message_3, 20 );
lv_obj_set_align( ui_Detail_Success_Status_message_3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Detail_Success_Status_message_3,"Error in Setup, Try Again");
lv_obj_add_flag( ui_Detail_Success_Status_message_3, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_Detail_Success_Status_message_3, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Detail_Success_Status_message_3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Detail_Success_Status_message_3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Detail_Success_Status_message_3, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Detail_Success_Status_message_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Detail_Success_Status_message_3, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Detail_Success_Status_message_4 = lv_label_create(ui_Sensor_Setup_main_Container_2);
lv_obj_set_width( ui_Detail_Success_Status_message_4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Detail_Success_Status_message_4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Detail_Success_Status_message_4, 0 );
lv_obj_set_y( ui_Detail_Success_Status_message_4, 15 );
lv_obj_set_align( ui_Detail_Success_Status_message_4, LV_ALIGN_CENTER );
lv_label_set_text(ui_Detail_Success_Status_message_4,"OK, Inlet Sensor Connected...");
lv_obj_add_flag( ui_Detail_Success_Status_message_4, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_Detail_Success_Status_message_4, lv_color_hex(0x006A09), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Detail_Success_Status_message_4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Detail_Success_Status_message_4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Detail_Success_Status_message_4, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Detail_Success_Status_message_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Detail_Success_Status_message_4, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_inlet_setup_error_icon = lv_img_create(ui_Sensor_Setup_main_Container_2);
lv_img_set_src(ui_inlet_setup_error_icon, &ui_img_1019942150);
lv_obj_set_width( ui_inlet_setup_error_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_inlet_setup_error_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_inlet_setup_error_icon, 0 );
lv_obj_set_y( ui_inlet_setup_error_icon, -25 );
lv_obj_set_align( ui_inlet_setup_error_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_inlet_setup_error_icon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_inlet_setup_error_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_inlet_setup_success_icon = lv_img_create(ui_Sensor_Setup_main_Container_2);
lv_img_set_src(ui_inlet_setup_success_icon, &ui_img_unread_png);
lv_obj_set_width( ui_inlet_setup_success_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_inlet_setup_success_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_inlet_setup_success_icon, 0 );
lv_obj_set_y( ui_inlet_setup_success_icon, -25 );
lv_obj_set_align( ui_inlet_setup_success_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_inlet_setup_success_icon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_inlet_setup_success_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_check_and_next_inlet_btn = lv_btn_create(ui_Sensor_Setup_main_Container_2);
lv_obj_set_width( ui_check_and_next_inlet_btn, 80);
lv_obj_set_height( ui_check_and_next_inlet_btn, 35);
lv_obj_set_x( ui_check_and_next_inlet_btn, 0 );
lv_obj_set_y( ui_check_and_next_inlet_btn, 85 );
lv_obj_set_align( ui_check_and_next_inlet_btn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_check_and_next_inlet_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_check_and_next_inlet_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_check_and_next_inlet_btn, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_check_and_next_inlet_btn, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_check_and_next_inlet_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_check_and_next_inlet_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_check_and_next_inlet_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_check_and_next_inlet_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_check_and_next_inlet_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_check_and_next_inlet_btn_label = lv_label_create(ui_Sensor_Setup_main_Container_2);
lv_obj_set_width( ui_check_and_next_inlet_btn_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_check_and_next_inlet_btn_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_check_and_next_inlet_btn_label, 0 );
lv_obj_set_y( ui_check_and_next_inlet_btn_label, 85 );
lv_obj_set_align( ui_check_and_next_inlet_btn_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_check_and_next_inlet_btn_label,"NEXT");
lv_obj_set_style_text_color(ui_check_and_next_inlet_btn_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_check_and_next_inlet_btn_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_check_and_next_inlet_btn_label, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_check_and_next_inlet_btn_label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_check_and_next_inlet_btn_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_check_and_next_inlet_btn_label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Sensor_Setup_main_Container_3 = lv_obj_create(ui_sensors_setup_container);
lv_obj_remove_style_all(ui_Sensor_Setup_main_Container_3);
lv_obj_set_width( ui_Sensor_Setup_main_Container_3, 320);
lv_obj_set_height( ui_Sensor_Setup_main_Container_3, 240);
lv_obj_set_align( ui_Sensor_Setup_main_Container_3, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Sensor_Setup_main_Container_3, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_Sensor_Setup_main_Container_3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Sensor_Setup_main_Container_3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Sensor_Setup_main_Container_3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Sensor_Setup_main_Container_3, &ui_img_1234_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_returnButton64 = lv_btn_create(ui_Sensor_Setup_main_Container_3);
lv_obj_set_width( ui_returnButton64, 60);
lv_obj_set_height( ui_returnButton64, 30);
lv_obj_set_x( ui_returnButton64, -125 );
lv_obj_set_y( ui_returnButton64, -100 );
lv_obj_set_align( ui_returnButton64, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_returnButton64, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_returnButton64, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_returnButton64, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_returnButton64, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_returnButton64, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_returnButton64, &ui_img_return_66_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_width(ui_returnButton64, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_returnButton64, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_returnButton64, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_returnButton64, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Connect_Outlet_Label = lv_label_create(ui_Sensor_Setup_main_Container_3);
lv_obj_set_width( ui_Connect_Outlet_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Connect_Outlet_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Connect_Outlet_Label, 0 );
lv_obj_set_y( ui_Connect_Outlet_Label, -65 );
lv_obj_set_align( ui_Connect_Outlet_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Connect_Outlet_Label,"Please Connect OUTLET Sensor");
lv_obj_set_style_text_color(ui_Connect_Outlet_Label, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Connect_Outlet_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Connect_Outlet_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Connect_Outlet_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Detail_Success_Status_message_5 = lv_label_create(ui_Sensor_Setup_main_Container_3);
lv_obj_set_width( ui_Detail_Success_Status_message_5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Detail_Success_Status_message_5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Detail_Success_Status_message_5, 0 );
lv_obj_set_y( ui_Detail_Success_Status_message_5, 20 );
lv_obj_set_align( ui_Detail_Success_Status_message_5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Detail_Success_Status_message_5,"Error in Setup, Try Again");
lv_obj_add_flag( ui_Detail_Success_Status_message_5, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_Detail_Success_Status_message_5, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Detail_Success_Status_message_5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Detail_Success_Status_message_5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Detail_Success_Status_message_5, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Detail_Success_Status_message_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Detail_Success_Status_message_5, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Detail_Success_Status_message_6 = lv_label_create(ui_Sensor_Setup_main_Container_3);
lv_obj_set_width( ui_Detail_Success_Status_message_6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Detail_Success_Status_message_6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Detail_Success_Status_message_6, 0 );
lv_obj_set_y( ui_Detail_Success_Status_message_6, 15 );
lv_obj_set_align( ui_Detail_Success_Status_message_6, LV_ALIGN_CENTER );
lv_label_set_text(ui_Detail_Success_Status_message_6,"OK, Outlet Sensor Connected...");
lv_obj_add_flag( ui_Detail_Success_Status_message_6, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_Detail_Success_Status_message_6, lv_color_hex(0x006A09), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Detail_Success_Status_message_6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Detail_Success_Status_message_6, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Detail_Success_Status_message_6, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Detail_Success_Status_message_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Detail_Success_Status_message_6, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Outlet_setup_error_icon = lv_img_create(ui_Sensor_Setup_main_Container_3);
lv_img_set_src(ui_Outlet_setup_error_icon, &ui_img_1019942150);
lv_obj_set_width( ui_Outlet_setup_error_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Outlet_setup_error_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Outlet_setup_error_icon, 0 );
lv_obj_set_y( ui_Outlet_setup_error_icon, -25 );
lv_obj_set_align( ui_Outlet_setup_error_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Outlet_setup_error_icon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Outlet_setup_error_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Outlet_setup_success_icon = lv_img_create(ui_Sensor_Setup_main_Container_3);
lv_img_set_src(ui_Outlet_setup_success_icon, &ui_img_unread_png);
lv_obj_set_width( ui_Outlet_setup_success_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Outlet_setup_success_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Outlet_setup_success_icon, 0 );
lv_obj_set_y( ui_Outlet_setup_success_icon, -25 );
lv_obj_set_align( ui_Outlet_setup_success_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Outlet_setup_success_icon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Outlet_setup_success_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_check_and_next_Outlet_btn = lv_btn_create(ui_Sensor_Setup_main_Container_3);
lv_obj_set_width( ui_check_and_next_Outlet_btn, 80);
lv_obj_set_height( ui_check_and_next_Outlet_btn, 35);
lv_obj_set_x( ui_check_and_next_Outlet_btn, 0 );
lv_obj_set_y( ui_check_and_next_Outlet_btn, 85 );
lv_obj_set_align( ui_check_and_next_Outlet_btn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_check_and_next_Outlet_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_check_and_next_Outlet_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_check_and_next_Outlet_btn, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_check_and_next_Outlet_btn, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_check_and_next_Outlet_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_check_and_next_Outlet_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_check_and_next_Outlet_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_check_and_next_Outlet_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_check_and_next_Outlet_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_check_and_next_Outlet_btn_label = lv_label_create(ui_Sensor_Setup_main_Container_3);
lv_obj_set_width( ui_check_and_next_Outlet_btn_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_check_and_next_Outlet_btn_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_check_and_next_Outlet_btn_label, 0 );
lv_obj_set_y( ui_check_and_next_Outlet_btn_label, 85 );
lv_obj_set_align( ui_check_and_next_Outlet_btn_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_check_and_next_Outlet_btn_label,"NEXT");
lv_obj_set_style_text_color(ui_check_and_next_Outlet_btn_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_check_and_next_Outlet_btn_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_check_and_next_Outlet_btn_label, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_check_and_next_Outlet_btn_label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_check_and_next_Outlet_btn_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_check_and_next_Outlet_btn_label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Sensor_Setup_main_Container_4 = lv_obj_create(ui_sensors_setup_container);
lv_obj_remove_style_all(ui_Sensor_Setup_main_Container_4);
lv_obj_set_width( ui_Sensor_Setup_main_Container_4, 320);
lv_obj_set_height( ui_Sensor_Setup_main_Container_4, 240);
lv_obj_set_align( ui_Sensor_Setup_main_Container_4, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Sensor_Setup_main_Container_4, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_Sensor_Setup_main_Container_4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Sensor_Setup_main_Container_4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Sensor_Setup_main_Container_4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Sensor_Setup_main_Container_4, &ui_img_1234_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_returnButton625 = lv_btn_create(ui_Sensor_Setup_main_Container_4);
lv_obj_set_width( ui_returnButton625, 60);
lv_obj_set_height( ui_returnButton625, 30);
lv_obj_set_x( ui_returnButton625, -125 );
lv_obj_set_y( ui_returnButton625, -100 );
lv_obj_set_align( ui_returnButton625, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_returnButton625, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_returnButton625, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_returnButton625, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_returnButton625, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_returnButton625, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_returnButton625, &ui_img_return_66_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_width(ui_returnButton625, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_returnButton625, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_returnButton625, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_returnButton625, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Connect_Antifreeze_Label = lv_label_create(ui_Sensor_Setup_main_Container_4);
lv_obj_set_width( ui_Connect_Antifreeze_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Connect_Antifreeze_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Connect_Antifreeze_Label, 0 );
lv_obj_set_y( ui_Connect_Antifreeze_Label, -65 );
lv_obj_set_align( ui_Connect_Antifreeze_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Connect_Antifreeze_Label,"Please Connect ANTIFREEZE Sensor");
lv_obj_set_style_text_color(ui_Connect_Antifreeze_Label, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Connect_Antifreeze_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Connect_Antifreeze_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Connect_Antifreeze_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Detail_Success_Status_message_7 = lv_label_create(ui_Sensor_Setup_main_Container_4);
lv_obj_set_width( ui_Detail_Success_Status_message_7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Detail_Success_Status_message_7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Detail_Success_Status_message_7, 0 );
lv_obj_set_y( ui_Detail_Success_Status_message_7, 20 );
lv_obj_set_align( ui_Detail_Success_Status_message_7, LV_ALIGN_CENTER );
lv_label_set_text(ui_Detail_Success_Status_message_7,"Error in Setup, Try Again");
lv_obj_add_flag( ui_Detail_Success_Status_message_7, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_Detail_Success_Status_message_7, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Detail_Success_Status_message_7, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Detail_Success_Status_message_7, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Detail_Success_Status_message_7, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Detail_Success_Status_message_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Detail_Success_Status_message_7, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Detail_Success_Status_message_8 = lv_label_create(ui_Sensor_Setup_main_Container_4);
lv_obj_set_width( ui_Detail_Success_Status_message_8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Detail_Success_Status_message_8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Detail_Success_Status_message_8, 0 );
lv_obj_set_y( ui_Detail_Success_Status_message_8, 15 );
lv_obj_set_align( ui_Detail_Success_Status_message_8, LV_ALIGN_CENTER );
lv_label_set_text(ui_Detail_Success_Status_message_8,"OK, Antifreeze Sensor Connected...");
lv_obj_add_flag( ui_Detail_Success_Status_message_8, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_Detail_Success_Status_message_8, lv_color_hex(0x006A09), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Detail_Success_Status_message_8, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Detail_Success_Status_message_8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Detail_Success_Status_message_8, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Detail_Success_Status_message_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Detail_Success_Status_message_8, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Antifreeze_setup_error_icon = lv_img_create(ui_Sensor_Setup_main_Container_4);
lv_img_set_src(ui_Antifreeze_setup_error_icon, &ui_img_1019942150);
lv_obj_set_width( ui_Antifreeze_setup_error_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Antifreeze_setup_error_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Antifreeze_setup_error_icon, 0 );
lv_obj_set_y( ui_Antifreeze_setup_error_icon, -25 );
lv_obj_set_align( ui_Antifreeze_setup_error_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Antifreeze_setup_error_icon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Antifreeze_setup_error_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Antifreeze_setup_success_icon = lv_img_create(ui_Sensor_Setup_main_Container_4);
lv_img_set_src(ui_Antifreeze_setup_success_icon, &ui_img_unread_png);
lv_obj_set_width( ui_Antifreeze_setup_success_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Antifreeze_setup_success_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Antifreeze_setup_success_icon, 0 );
lv_obj_set_y( ui_Antifreeze_setup_success_icon, -25 );
lv_obj_set_align( ui_Antifreeze_setup_success_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Antifreeze_setup_success_icon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Antifreeze_setup_success_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_check_and_next_Antifreeze_btn = lv_btn_create(ui_Sensor_Setup_main_Container_4);
lv_obj_set_width( ui_check_and_next_Antifreeze_btn, 80);
lv_obj_set_height( ui_check_and_next_Antifreeze_btn, 35);
lv_obj_set_x( ui_check_and_next_Antifreeze_btn, 0 );
lv_obj_set_y( ui_check_and_next_Antifreeze_btn, 85 );
lv_obj_set_align( ui_check_and_next_Antifreeze_btn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_check_and_next_Antifreeze_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_check_and_next_Antifreeze_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_check_and_next_Antifreeze_btn, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_check_and_next_Antifreeze_btn, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_check_and_next_Antifreeze_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_check_and_next_Antifreeze_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_check_and_next_Antifreeze_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_check_and_next_Antifreeze_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_check_and_next_Antifreeze_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_check_and_next_Antifreeze_btn_label = lv_label_create(ui_Sensor_Setup_main_Container_4);
lv_obj_set_width( ui_check_and_next_Antifreeze_btn_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_check_and_next_Antifreeze_btn_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_check_and_next_Antifreeze_btn_label, 0 );
lv_obj_set_y( ui_check_and_next_Antifreeze_btn_label, 85 );
lv_obj_set_align( ui_check_and_next_Antifreeze_btn_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_check_and_next_Antifreeze_btn_label,"NEXT");
lv_obj_set_style_text_color(ui_check_and_next_Antifreeze_btn_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_check_and_next_Antifreeze_btn_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_check_and_next_Antifreeze_btn_label, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_check_and_next_Antifreeze_btn_label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_check_and_next_Antifreeze_btn_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_check_and_next_Antifreeze_btn_label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Sensor_Setup_main_Container_5 = lv_obj_create(ui_sensors_setup_container);
lv_obj_remove_style_all(ui_Sensor_Setup_main_Container_5);
lv_obj_set_width( ui_Sensor_Setup_main_Container_5, 320);
lv_obj_set_height( ui_Sensor_Setup_main_Container_5, 240);
lv_obj_set_align( ui_Sensor_Setup_main_Container_5, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Sensor_Setup_main_Container_5, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_Sensor_Setup_main_Container_5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Sensor_Setup_main_Container_5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Sensor_Setup_main_Container_5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Sensor_Setup_main_Container_5, &ui_img_1234_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_returnButton614987 = lv_btn_create(ui_Sensor_Setup_main_Container_5);
lv_obj_set_width( ui_returnButton614987, 60);
lv_obj_set_height( ui_returnButton614987, 30);
lv_obj_set_x( ui_returnButton614987, -125 );
lv_obj_set_y( ui_returnButton614987, -100 );
lv_obj_set_align( ui_returnButton614987, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_returnButton614987, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_returnButton614987, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_returnButton614987, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_returnButton614987, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_returnButton614987, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_returnButton614987, &ui_img_return_66_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_width(ui_returnButton614987, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_returnButton614987, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_returnButton614987, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_returnButton614987, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Connect_Filter_Label = lv_label_create(ui_Sensor_Setup_main_Container_5);
lv_obj_set_width( ui_Connect_Filter_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Connect_Filter_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Connect_Filter_Label, 0 );
lv_obj_set_y( ui_Connect_Filter_Label, -65 );
lv_obj_set_align( ui_Connect_Filter_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Connect_Filter_Label,"Please Connect FILTER Sensor");
lv_obj_set_style_text_color(ui_Connect_Filter_Label, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Connect_Filter_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Connect_Filter_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Connect_Filter_Label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Detail_Success_Status_message_9 = lv_label_create(ui_Sensor_Setup_main_Container_5);
lv_obj_set_width( ui_Detail_Success_Status_message_9, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Detail_Success_Status_message_9, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Detail_Success_Status_message_9, 0 );
lv_obj_set_y( ui_Detail_Success_Status_message_9, 20 );
lv_obj_set_align( ui_Detail_Success_Status_message_9, LV_ALIGN_CENTER );
lv_label_set_text(ui_Detail_Success_Status_message_9,"Error in Setup, Try Again");
lv_obj_add_flag( ui_Detail_Success_Status_message_9, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_Detail_Success_Status_message_9, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Detail_Success_Status_message_9, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Detail_Success_Status_message_9, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Detail_Success_Status_message_9, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Detail_Success_Status_message_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Detail_Success_Status_message_9, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Detail_Success_Status_message_10 = lv_label_create(ui_Sensor_Setup_main_Container_5);
lv_obj_set_width( ui_Detail_Success_Status_message_10, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Detail_Success_Status_message_10, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Detail_Success_Status_message_10, 0 );
lv_obj_set_y( ui_Detail_Success_Status_message_10, 15 );
lv_obj_set_align( ui_Detail_Success_Status_message_10, LV_ALIGN_CENTER );
lv_label_set_text(ui_Detail_Success_Status_message_10,"OK, Filter Sensor Connected...");
lv_obj_add_flag( ui_Detail_Success_Status_message_10, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_Detail_Success_Status_message_10, lv_color_hex(0x006A09), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Detail_Success_Status_message_10, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Detail_Success_Status_message_10, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Detail_Success_Status_message_10, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Detail_Success_Status_message_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Detail_Success_Status_message_10, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Filter_setup_error_icon = lv_img_create(ui_Sensor_Setup_main_Container_5);
lv_img_set_src(ui_Filter_setup_error_icon, &ui_img_1019942150);
lv_obj_set_width( ui_Filter_setup_error_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Filter_setup_error_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Filter_setup_error_icon, 0 );
lv_obj_set_y( ui_Filter_setup_error_icon, -25 );
lv_obj_set_align( ui_Filter_setup_error_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Filter_setup_error_icon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Filter_setup_error_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Filter_setup_success_icon = lv_img_create(ui_Sensor_Setup_main_Container_5);
lv_img_set_src(ui_Filter_setup_success_icon, &ui_img_unread_png);
lv_obj_set_width( ui_Filter_setup_success_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Filter_setup_success_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Filter_setup_success_icon, 0 );
lv_obj_set_y( ui_Filter_setup_success_icon, -25 );
lv_obj_set_align( ui_Filter_setup_success_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Filter_setup_success_icon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Filter_setup_success_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_check_and_next_Filter_btn = lv_btn_create(ui_Sensor_Setup_main_Container_5);
lv_obj_set_width( ui_check_and_next_Filter_btn, 80);
lv_obj_set_height( ui_check_and_next_Filter_btn, 35);
lv_obj_set_x( ui_check_and_next_Filter_btn, 0 );
lv_obj_set_y( ui_check_and_next_Filter_btn, 85 );
lv_obj_set_align( ui_check_and_next_Filter_btn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_check_and_next_Filter_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_check_and_next_Filter_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_check_and_next_Filter_btn, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_check_and_next_Filter_btn, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_check_and_next_Filter_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_check_and_next_Filter_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_check_and_next_Filter_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_check_and_next_Filter_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_check_and_next_Filter_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_check_and_next_Filter_btn_label = lv_label_create(ui_Sensor_Setup_main_Container_5);
lv_obj_set_width( ui_check_and_next_Filter_btn_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_check_and_next_Filter_btn_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_check_and_next_Filter_btn_label, 0 );
lv_obj_set_y( ui_check_and_next_Filter_btn_label, 85 );
lv_obj_set_align( ui_check_and_next_Filter_btn_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_check_and_next_Filter_btn_label,"NEXT");
lv_obj_set_style_text_color(ui_check_and_next_Filter_btn_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_check_and_next_Filter_btn_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_check_and_next_Filter_btn_label, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_check_and_next_Filter_btn_label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_check_and_next_Filter_btn_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_check_and_next_Filter_btn_label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Sensor_Setup_main_Container_6 = lv_obj_create(ui_sensors_setup_container);
lv_obj_remove_style_all(ui_Sensor_Setup_main_Container_6);
lv_obj_set_width( ui_Sensor_Setup_main_Container_6, 320);
lv_obj_set_height( ui_Sensor_Setup_main_Container_6, 240);
lv_obj_set_align( ui_Sensor_Setup_main_Container_6, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Sensor_Setup_main_Container_6, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_Sensor_Setup_main_Container_6, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Sensor_Setup_main_Container_6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Sensor_Setup_main_Container_6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Sensor_Setup_main_Container_6, &ui_img_1234_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_sensor_setup_finish_label = lv_label_create(ui_Sensor_Setup_main_Container_6);
lv_obj_set_width( ui_sensor_setup_finish_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_sensor_setup_finish_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_sensor_setup_finish_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_sensor_setup_finish_label,"Sensors Setup Completed,\nDevice Will Restart.");
lv_obj_set_style_text_color(ui_sensor_setup_finish_label, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_sensor_setup_finish_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_sensor_setup_finish_label, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_sensor_setup_finish_label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_sensor_setup_finish_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_sensor_setup_finish_label, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_sensor_setup_finish_icon = lv_img_create(ui_Sensor_Setup_main_Container_6);
lv_img_set_src(ui_sensor_setup_finish_icon, &ui_img_unread_png);
lv_obj_set_width( ui_sensor_setup_finish_icon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_sensor_setup_finish_icon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_sensor_setup_finish_icon, 0 );
lv_obj_set_y( ui_sensor_setup_finish_icon, -50 );
lv_obj_set_align( ui_sensor_setup_finish_icon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_sensor_setup_finish_icon, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_sensor_setup_finish_icon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_factory_reset_container = lv_obj_create(ui_addvansedSettingScreen);
lv_obj_remove_style_all(ui_factory_reset_container);
lv_obj_set_width( ui_factory_reset_container, 320);
lv_obj_set_height( ui_factory_reset_container, 240);
lv_obj_set_align( ui_factory_reset_container, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_factory_reset_container, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_factory_reset_container, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_factory_reset_container, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_factory_reset_container, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_factory_reset_container, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_factory_reset_container, &ui_img_1234_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_reset_factory_notice_text = lv_label_create(ui_factory_reset_container);
lv_obj_set_width( ui_reset_factory_notice_text, 232);
lv_obj_set_height( ui_reset_factory_notice_text, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_reset_factory_notice_text, 0 );
lv_obj_set_y( ui_reset_factory_notice_text, -20 );
lv_obj_set_align( ui_reset_factory_notice_text, LV_ALIGN_CENTER );
lv_label_set_text(ui_reset_factory_notice_text,"Are You Sure For Restore Factory Settings?");
lv_obj_set_style_text_color(ui_reset_factory_notice_text, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_reset_factory_notice_text, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_reset_factory_notice_text, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_reset_factory_notice_text, 7, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_reset_factory_notice_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_reset_factory_notice_text, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_close_factory_container = lv_btn_create(ui_factory_reset_container);
lv_obj_set_width( ui_close_factory_container, 75);
lv_obj_set_height( ui_close_factory_container, 40);
lv_obj_set_x( ui_close_factory_container, -55 );
lv_obj_set_y( ui_close_factory_container, 50 );
lv_obj_set_align( ui_close_factory_container, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_close_factory_container, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_close_factory_container, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_close_factory_container, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_close_factory_container, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_close_factory_container, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_close_factory_container, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_close_factory_container, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_close_factory_container, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label275 = lv_label_create(ui_factory_reset_container);
lv_obj_set_width( ui_Label275, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label275, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label275, -55 );
lv_obj_set_y( ui_Label275, 50 );
lv_obj_set_align( ui_Label275, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label275,"NO");
lv_obj_set_style_text_color(ui_Label275, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label275, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label275, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_submit_factory = lv_btn_create(ui_factory_reset_container);
lv_obj_set_width( ui_submit_factory, 75);
lv_obj_set_height( ui_submit_factory, 40);
lv_obj_set_x( ui_submit_factory, 55 );
lv_obj_set_y( ui_submit_factory, 50 );
lv_obj_set_align( ui_submit_factory, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_submit_factory, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_submit_factory, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_submit_factory, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_submit_factory, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_submit_factory, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_submit_factory, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_submit_factory, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_submit_factory, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label1863 = lv_label_create(ui_factory_reset_container);
lv_obj_set_width( ui_Label1863, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1863, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1863, 55 );
lv_obj_set_y( ui_Label1863, 50 );
lv_obj_set_align( ui_Label1863, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1863,"YES");
lv_obj_set_style_text_color(ui_Label1863, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label1863, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label1863, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_returnButton14, ui_event_returnButton14, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Setting_Save_btn_in_advanced_Screen, ui_event_Setting_Save_btn_in_advanced_Screen, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_AntiFreeze_Temp_Range_Plus_Button, ui_event_AntiFreeze_Temp_Range_Plus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_AntiFreeze_Temp_Range_Minus_Button, ui_event_AntiFreeze_Temp_Range_Minus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_AntiFreeze_Temp_Offset_Plus_Button, ui_event_AntiFreeze_Temp_Offset_Plus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_AntiFreeze_Temp_Offset_Minus_Button, ui_event_AntiFreeze_Temp_Offset_Minus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Compressor_Rest_Time_Plus_Button, ui_event_Compressor_Rest_Time_Plus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Compressor_Rest_Time_Minus_Button, ui_event_Compressor_Rest_Time_Minus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Filter_Alarm_Plus_Button, ui_event_Filter_Alarm_Plus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Filter_Alarm_Minus_Button, ui_event_Filter_Alarm_Minus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_fan_2_range_Plus_Button, ui_event_fan_2_range_Plus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_fan_2_range_Minus_Button, ui_event_fan_2_range_Minus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_fan_2_Switch, ui_event_fan_2_Switch, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_door_alarm_status_Switch, ui_event_door_alarm_status_Switch, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_filter_alarm_status_Switch, ui_event_filter_alarm_status_Switch, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Sensor_Setup_Button, ui_event_Sensor_Setup_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_open_factory_reset_panel, ui_event_open_factory_reset_panel, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_DEVICE_RESTART_Button, ui_event_DEVICE_RESTART_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TabView1, ui_event_TabView1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_submitResetbtn, ui_event_submitResetbtn, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_CancelResetbtn, ui_event_CancelResetbtn, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_returnButton668, ui_event_returnButton668, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_check_and_next_btn_1, ui_event_check_and_next_btn_1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_returnButton6987, ui_event_returnButton6987, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_check_and_next_inlet_btn, ui_event_check_and_next_inlet_btn, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_returnButton64, ui_event_returnButton64, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_check_and_next_Outlet_btn, ui_event_check_and_next_Outlet_btn, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_returnButton625, ui_event_returnButton625, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_check_and_next_Antifreeze_btn, ui_event_check_and_next_Antifreeze_btn, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_returnButton614987, ui_event_returnButton614987, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_check_and_next_Filter_btn, ui_event_check_and_next_Filter_btn, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_close_factory_container, ui_event_close_factory_container, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_submit_factory, ui_event_submit_factory, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_addvansedSettingScreen, ui_event_addvansedSettingScreen, LV_EVENT_ALL, NULL);
uic_addvansedSettingScreen = ui_addvansedSettingScreen;
uic_returnButton14 = ui_returnButton14;
uic_Advanced_Setting_Label = ui_Advanced_Setting_Label;
uic_Setting_Save_btn_in_advanced_Screen = ui_Setting_Save_btn_in_advanced_Screen;
uic_Setting_Save_btn_label_advanced_Screen = ui_Setting_Save_btn_label_advanced_Screen;
uic_TabView1 = ui_TabView1;
uic_AdvancedScreenContainer1 = ui_AdvancedScreenContainer1;
uic_AntiFreeze_Temp_Range_Spinbox = ui_AntiFreeze_Temp_Range_Spinbox;
uic_AntiFreeze_Temp_Range_Plus_Button = ui_AntiFreeze_Temp_Range_Plus_Button;
uic_AntiFreeze_Temp_Range_Minus_Button = ui_AntiFreeze_Temp_Range_Minus_Button;
uic_lable25646 = ui_lable25646;
uic_AdvancedScreenContainer2 = ui_AdvancedScreenContainer2;
uic_AntiFreeze_Temp_Offset_Spinbox = ui_AntiFreeze_Temp_Offset_Spinbox;
uic_AntiFreeze_Temp_Offset_Plus_Button = ui_AntiFreeze_Temp_Offset_Plus_Button;
uic_AntiFreeze_Temp_Offset_Minus_Button = ui_AntiFreeze_Temp_Offset_Minus_Button;
uic_lable2235474 = ui_lable2235474;
uic_AdvancedScreenContainer3 = ui_AdvancedScreenContainer3;
uic_Compressor_Rest_Time_Spinbox = ui_Compressor_Rest_Time_Spinbox;
uic_Compressor_Rest_Time_Plus_Button = ui_Compressor_Rest_Time_Plus_Button;
uic_Compressor_Rest_Time_Minus_Button = ui_Compressor_Rest_Time_Minus_Button;
uic_minutelable11 = ui_minutelable11;
uic_AdvancedScreenContainer4 = ui_AdvancedScreenContainer4;
uic_Filter_Alarm_Spinbox = ui_Filter_Alarm_Spinbox;
uic_Filter_Alarm_Plus_Button = ui_Filter_Alarm_Plus_Button;
uic_Filter_Alarm_Minus_Button = ui_Filter_Alarm_Minus_Button;
uic_lable29854 = ui_lable29854;
uic_Compressor_Rest_Time_Label = ui_Compressor_Rest_Time_Label;
uic_AntiFreeze_Temp_Offset_Label = ui_AntiFreeze_Temp_Offset_Label;
uic_AntiFreeze_Temp_Range_Label = ui_AntiFreeze_Temp_Range_Label;
uic_Filter_Alarm__Range_Label = ui_Filter_Alarm__Range_Label;
uic_AdvancedScreenContainer5 = ui_AdvancedScreenContainer5;
uic_fan_2_range_Spinbox = ui_fan_2_range_Spinbox;
uic_fan_2_range_Plus_Button = ui_fan_2_range_Plus_Button;
uic_fan_2_range_Minus_Button = ui_fan_2_range_Minus_Button;
uic_fan_2_Switch = ui_fan_2_Switch;
uic_enable_fan_2_Label = ui_enable_fan_2_Label;
uic_disable_fan_2_Label = ui_disable_fan_2_Label;
uic_lable29988 = ui_lable29988;
uic_fan_2_range_Label = ui_fan_2_range_Label;
uic_AdvancedScreenContainer6 = ui_AdvancedScreenContainer6;
uic_door_alarm_status_Switch = ui_door_alarm_status_Switch;
uic_enable_door_alarm_status_Label = ui_enable_door_alarm_status_Label;
uic_disable_door_alarm_status_Label = ui_disable_door_alarm_status_Label;
uic_door_function_and_alarm_Label = ui_door_function_and_alarm_Label;
uic_AdvancedScreenContainer7 = ui_AdvancedScreenContainer7;
uic_filter_alarm_status_Switch = ui_filter_alarm_status_Switch;
uic_enable_filter_alarm_status_Label = ui_enable_filter_alarm_status_Label;
uic_disable_filter_alarm_status_Label = ui_disable_filter_alarm_status_Label;
uic_Filter_alarm_switch_Label = ui_Filter_alarm_switch_Label;
uic_Label456 = ui_Label456;
uic_Sensor_Setup_Button = ui_Sensor_Setup_Button;
uic_Sensor_Setup_Button_Label = ui_Sensor_Setup_Button_Label;
uic_Label123 = ui_Label123;
uic_open_factory_reset_panel = ui_open_factory_reset_panel;
uic_factory_reset_btn_Label = ui_factory_reset_btn_Label;
uic_DEVICE_RESTART_Button = ui_DEVICE_RESTART_Button;
uic_DEVICE_RESTART_Button_Label = ui_DEVICE_RESTART_Button_Label;
uic_sensors_setup_container = ui_sensors_setup_container;
uic_Sensor_Setup_Notice_Container = ui_Sensor_Setup_Notice_Container;
uic_Reset_Notice_Label = ui_Reset_Notice_Label;
uic_submitResetbtn = ui_submitResetbtn;
uic_CancelResetbtn = ui_CancelResetbtn;
uic_submitResetbtn_Label = ui_submitResetbtn_Label;
uic_CancelResetbtn_Label = ui_CancelResetbtn_Label;
uic_SensorSetupDangerIcon = ui_SensorSetupDangerIcon;
uic_Reseting_Sensors_Notice_2 = ui_Reseting_Sensors_Notice_2;
uic_Sensor_Setup_main_Container_1 = ui_Sensor_Setup_main_Container_1;
uic_returnButton668 = ui_returnButton668;
uic_disconnect_sensors_Label = ui_disconnect_sensors_Label;
uic_Detail_Success_Status_message_1 = ui_Detail_Success_Status_message_1;
uic_Detail_Success_Status_message_1 = ui_Detail_Success_Status_message_2;
uic_disconnect_error_icon = ui_disconnect_error_icon;
uic_success_disconnect_icon = ui_success_disconnect_icon;
uic_check_and_next_btn_1 = ui_check_and_next_btn_1;
uic_check_and_next_btn_1_label = ui_check_and_next_btn_1_label;
uic_Sensor_Setup_main_Container_2 = ui_Sensor_Setup_main_Container_2;
uic_returnButton6987 = ui_returnButton6987;
uic_Connect_Inlet_Label = ui_Connect_Inlet_Label;
uic_Detail_Success_Status_message_3 = ui_Detail_Success_Status_message_3;
uic_Detail_Success_Status_message_4 = ui_Detail_Success_Status_message_4;
uic_inlet_setup_error_icon = ui_inlet_setup_error_icon;
uic_inlet_setup_success_icon = ui_inlet_setup_success_icon;
uic_check_and_next_inlet_btn = ui_check_and_next_inlet_btn;
uic_check_and_next_inlet_btn_label = ui_check_and_next_inlet_btn_label;
uic_Sensor_Setup_main_Container_3 = ui_Sensor_Setup_main_Container_3;
uic_returnButton64 = ui_returnButton64;
uic_Connect_Outlet_Label = ui_Connect_Outlet_Label;
uic_Detail_Success_Status_message_5 = ui_Detail_Success_Status_message_5;
uic_Detail_Success_Status_message_6 = ui_Detail_Success_Status_message_6;
uic_Outlet_setup_error_icon = ui_Outlet_setup_error_icon;
uic_Outlet_setup_success_icon = ui_Outlet_setup_success_icon;
uic_check_and_next_Outlet_btn = ui_check_and_next_Outlet_btn;
uic_check_and_next_Outlet_btn_label = ui_check_and_next_Outlet_btn_label;
uic_Sensor_Setup_main_Container_4 = ui_Sensor_Setup_main_Container_4;
uic_returnButton625 = ui_returnButton625;
uic_Connect_Antifreeze_Label = ui_Connect_Antifreeze_Label;
uic_Detail_Success_Status_message_7 = ui_Detail_Success_Status_message_7;
uic_Detail_Success_Status_message_8 = ui_Detail_Success_Status_message_8;
uic_Antifreeze_setup_error_icon = ui_Antifreeze_setup_error_icon;
uic_Antifreeze_setup_success_icon = ui_Antifreeze_setup_success_icon;
uic_check_and_next_Antifreeze_btn = ui_check_and_next_Antifreeze_btn;
uic_check_and_next_Antifreeze_btn_label = ui_check_and_next_Antifreeze_btn_label;
uic_Sensor_Setup_main_Container_5 = ui_Sensor_Setup_main_Container_5;
uic_returnButton614987 = ui_returnButton614987;
uic_Connect_Filter_Label = ui_Connect_Filter_Label;
uic_Detail_Success_Status_message_9 = ui_Detail_Success_Status_message_9;
uic_Detail_Success_Status_message_10 = ui_Detail_Success_Status_message_10;
uic_Filter_setup_error_icon = ui_Filter_setup_error_icon;
uic_Filter_setup_success_icon = ui_Filter_setup_success_icon;
uic_check_and_next_Filter_btn = ui_check_and_next_Filter_btn;
uic_check_and_next_Filter_btn_label = ui_check_and_next_Filter_btn_label;
uic_Sensor_Setup_main_Container_6 = ui_Sensor_Setup_main_Container_6;
uic_sensor_setup_finish_label = ui_sensor_setup_finish_label;
uic_sensor_setup_finish_icon = ui_sensor_setup_finish_icon;
uic_factory_reset_container = ui_factory_reset_container;
uic_reset_factory_notice_text = ui_reset_factory_notice_text;
uic_close_factory_container = ui_close_factory_container;
uic_Label275 = ui_Label275;
uic_submit_factory = ui_submit_factory;
uic_Label1863 = ui_Label1863;

}
