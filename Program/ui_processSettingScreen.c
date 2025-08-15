// ui_processSettingScreen.c


#include "ui.h"

void ui_processSettingScreen_screen_init(void)
{
ui_processSettingScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_processSettingScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_processSettingScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_processSettingScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_processSettingScreen, &ui_img_1234_png, LV_PART_MAIN | LV_STATE_DEFAULT );

ui_returnButton5 = lv_btn_create(ui_processSettingScreen);
lv_obj_set_width( ui_returnButton5, 60);
lv_obj_set_height( ui_returnButton5, 30);
lv_obj_set_x( ui_returnButton5, -125 );
lv_obj_set_y( ui_returnButton5, -100 );
lv_obj_set_align( ui_returnButton5, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_returnButton5, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_returnButton5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_returnButton5, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_returnButton5, lv_color_hex(0x0D0246), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_returnButton5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_returnButton5, &ui_img_return_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_color(ui_returnButton5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_returnButton5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_returnButton5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_returnButton5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_returnButton5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_returnButton5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ProcessSettingCTRL = lv_label_create(ui_processSettingScreen);
lv_obj_set_width( ui_ProcessSettingCTRL, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ProcessSettingCTRL, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ProcessSettingCTRL, 0 );
lv_obj_set_y( ui_ProcessSettingCTRL, -100 );
lv_obj_set_align( ui_ProcessSettingCTRL, LV_ALIGN_CENTER );
lv_label_set_text(ui_ProcessSettingCTRL,"CUSTOMER SETTING");
lv_obj_set_style_text_color(ui_ProcessSettingCTRL, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_ProcessSettingCTRL, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_ProcessSettingCTRL, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Setting_Save_btn = lv_btn_create(ui_processSettingScreen);
lv_obj_set_width( ui_Setting_Save_btn, 60);
lv_obj_set_height( ui_Setting_Save_btn, 30);
lv_obj_set_x( ui_Setting_Save_btn, 125 );
lv_obj_set_y( ui_Setting_Save_btn, -100 );
lv_obj_set_align( ui_Setting_Save_btn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Setting_Save_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Setting_Save_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Setting_Save_btn, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Setting_Save_btn, lv_color_hex(0x00BE10), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Setting_Save_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Setting_Save_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Setting_Save_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Setting_Save_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Setting_Save_btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Setting_Save_btn_label = lv_label_create(ui_processSettingScreen);
lv_obj_set_width( ui_Setting_Save_btn_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Setting_Save_btn_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Setting_Save_btn_label, 124 );
lv_obj_set_y( ui_Setting_Save_btn_label, -101 );
lv_obj_set_align( ui_Setting_Save_btn_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Setting_Save_btn_label,"Save");
lv_obj_set_style_text_color(ui_Setting_Save_btn_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Setting_Save_btn_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Setting_Save_btn_label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ProcessScreenContainer1 = lv_obj_create(ui_processSettingScreen);
lv_obj_remove_style_all(ui_ProcessScreenContainer1);
lv_obj_set_width( ui_ProcessScreenContainer1, 150);
lv_obj_set_height( ui_ProcessScreenContainer1, 80);
lv_obj_set_x( ui_ProcessScreenContainer1, -80 );
lv_obj_set_y( ui_ProcessScreenContainer1, -31 );
lv_obj_set_align( ui_ProcessScreenContainer1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_ProcessScreenContainer1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_ProcessScreenContainer1, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ProcessScreenContainer1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ProcessScreenContainer1, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_ProcessScreenContainer1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_ProcessScreenContainer1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_ProcessScreenContainer1, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_ProcessScreenContainer1, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Compressor_Range_Spinbox = lv_spinbox_create(ui_ProcessScreenContainer1);
lv_obj_set_width( ui_Compressor_Range_Spinbox, 45);
lv_obj_set_height( ui_Compressor_Range_Spinbox, 35);
lv_obj_set_x( ui_Compressor_Range_Spinbox, 0 );
lv_obj_set_y( ui_Compressor_Range_Spinbox, 5 );
lv_obj_set_align( ui_Compressor_Range_Spinbox, LV_ALIGN_CENTER );
lv_spinbox_set_digit_format( ui_Compressor_Range_Spinbox, 2, 0);
lv_spinbox_set_range( ui_Compressor_Range_Spinbox, 20,50 );
lv_spinbox_set_cursor_pos(ui_Compressor_Range_Spinbox, 1 - 1);
lv_spinbox_set_value( ui_Compressor_Range_Spinbox, 21 );
lv_obj_set_style_border_color(ui_Compressor_Range_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Compressor_Range_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Compressor_Range_Spinbox, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_Compressor_Range_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Compressor_Range_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Compressor_Range_Spinbox, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_blend_mode(ui_Compressor_Range_Spinbox, LV_BLEND_MODE_ADDITIVE, LV_PART_CURSOR| LV_STATE_DEFAULT);
lv_obj_set_style_opa(ui_Compressor_Range_Spinbox, 0, LV_PART_CURSOR| LV_STATE_DEFAULT);

ui_Compressor_Range_Plus_Button = lv_btn_create(ui_ProcessScreenContainer1);
lv_obj_set_width( ui_Compressor_Range_Plus_Button, 45);
lv_obj_set_height( ui_Compressor_Range_Plus_Button, 45);
lv_obj_set_x( ui_Compressor_Range_Plus_Button, 48 );
lv_obj_set_y( ui_Compressor_Range_Plus_Button, 5 );
lv_obj_set_align( ui_Compressor_Range_Plus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Compressor_Range_Plus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Compressor_Range_Plus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Compressor_Range_Plus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Compressor_Range_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Compressor_Range_Plus_Button, &ui_img_plus_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_Compressor_Range_Plus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Compressor_Range_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Compressor_Range_Plus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Compressor_Range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Compressor_Range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Compressor_Range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Compressor_Range_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Compressor_Range_Minus_Button = lv_btn_create(ui_ProcessScreenContainer1);
lv_obj_set_width( ui_Compressor_Range_Minus_Button, 45);
lv_obj_set_height( ui_Compressor_Range_Minus_Button, 45);
lv_obj_set_x( ui_Compressor_Range_Minus_Button, -48 );
lv_obj_set_y( ui_Compressor_Range_Minus_Button, 5 );
lv_obj_set_align( ui_Compressor_Range_Minus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Compressor_Range_Minus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Compressor_Range_Minus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Compressor_Range_Minus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Compressor_Range_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Compressor_Range_Minus_Button, &ui_img_1731839073, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_Compressor_Range_Minus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Compressor_Range_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Compressor_Range_Minus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Compressor_Range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Compressor_Range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Compressor_Range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Compressor_Range_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lable3951 = lv_label_create(ui_ProcessScreenContainer1);
lv_obj_set_width( ui_lable3951, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lable3951, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lable3951, 1 );
lv_obj_set_y( ui_lable3951, 25 );
lv_obj_set_align( ui_lable3951, LV_ALIGN_CENTER );
lv_label_set_text(ui_lable3951," C° ");
lv_obj_set_style_text_font(ui_lable3951, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_lable3951, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_lable3951, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_lable3951, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ProcessScreenContainer2 = lv_obj_create(ui_processSettingScreen);
lv_obj_remove_style_all(ui_ProcessScreenContainer2);
lv_obj_set_width( ui_ProcessScreenContainer2, 150);
lv_obj_set_height( ui_ProcessScreenContainer2, 80);
lv_obj_set_x( ui_ProcessScreenContainer2, 80 );
lv_obj_set_y( ui_ProcessScreenContainer2, -31 );
lv_obj_set_align( ui_ProcessScreenContainer2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_ProcessScreenContainer2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_ProcessScreenContainer2, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ProcessScreenContainer2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ProcessScreenContainer2, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_ProcessScreenContainer2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_ProcessScreenContainer2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_ProcessScreenContainer2, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_ProcessScreenContainer2, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Compressor_Offste_Spinbox = lv_spinbox_create(ui_ProcessScreenContainer2);
lv_obj_set_width( ui_Compressor_Offste_Spinbox, 45);
lv_obj_set_height( ui_Compressor_Offste_Spinbox, 35);
lv_obj_set_x( ui_Compressor_Offste_Spinbox, 0 );
lv_obj_set_y( ui_Compressor_Offste_Spinbox, 5 );
lv_obj_set_align( ui_Compressor_Offste_Spinbox, LV_ALIGN_CENTER );
lv_spinbox_set_digit_format( ui_Compressor_Offste_Spinbox, 2, 0);
lv_spinbox_set_range( ui_Compressor_Offste_Spinbox, 0,15 );
lv_spinbox_set_cursor_pos(ui_Compressor_Offste_Spinbox, 1 - 1);
lv_spinbox_set_value( ui_Compressor_Offste_Spinbox, 1 );
lv_obj_set_style_border_color(ui_Compressor_Offste_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Compressor_Offste_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Compressor_Offste_Spinbox, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_Compressor_Offste_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Compressor_Offste_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Compressor_Offste_Spinbox, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_blend_mode(ui_Compressor_Offste_Spinbox, LV_BLEND_MODE_ADDITIVE, LV_PART_CURSOR| LV_STATE_DEFAULT);
lv_obj_set_style_opa(ui_Compressor_Offste_Spinbox, 0, LV_PART_CURSOR| LV_STATE_DEFAULT);

ui_Compressor_Offset_Plus_Button = lv_btn_create(ui_ProcessScreenContainer2);
lv_obj_set_width( ui_Compressor_Offset_Plus_Button, 45);
lv_obj_set_height( ui_Compressor_Offset_Plus_Button, 45);
lv_obj_set_x( ui_Compressor_Offset_Plus_Button, 48 );
lv_obj_set_y( ui_Compressor_Offset_Plus_Button, 5 );
lv_obj_set_align( ui_Compressor_Offset_Plus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Compressor_Offset_Plus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Compressor_Offset_Plus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Compressor_Offset_Plus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Compressor_Offset_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Compressor_Offset_Plus_Button, &ui_img_plus_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_Compressor_Offset_Plus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Compressor_Offset_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Compressor_Offset_Plus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Compressor_Offset_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Compressor_Offset_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Compressor_Offset_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Compressor_Offset_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Compressor_Offset_Minus_Button = lv_btn_create(ui_ProcessScreenContainer2);
lv_obj_set_width( ui_Compressor_Offset_Minus_Button, 45);
lv_obj_set_height( ui_Compressor_Offset_Minus_Button, 45);
lv_obj_set_x( ui_Compressor_Offset_Minus_Button, -48 );
lv_obj_set_y( ui_Compressor_Offset_Minus_Button, 5 );
lv_obj_set_align( ui_Compressor_Offset_Minus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Compressor_Offset_Minus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Compressor_Offset_Minus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Compressor_Offset_Minus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Compressor_Offset_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Compressor_Offset_Minus_Button, &ui_img_1731839073, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_Compressor_Offset_Minus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Compressor_Offset_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Compressor_Offset_Minus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Compressor_Offset_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Compressor_Offset_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_Compressor_Offset_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_Compressor_Offset_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lable39854 = lv_label_create(ui_ProcessScreenContainer2);
lv_obj_set_width( ui_lable39854, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lable39854, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lable39854, 1 );
lv_obj_set_y( ui_lable39854, 25 );
lv_obj_set_align( ui_lable39854, LV_ALIGN_CENTER );
lv_label_set_text(ui_lable39854," C° ");
lv_obj_set_style_text_font(ui_lable39854, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_lable39854, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_lable39854, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_lable39854, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ProcessScreenContainer3 = lv_obj_create(ui_processSettingScreen);
lv_obj_remove_style_all(ui_ProcessScreenContainer3);
lv_obj_set_width( ui_ProcessScreenContainer3, 150);
lv_obj_set_height( ui_ProcessScreenContainer3, 90);
lv_obj_set_x( ui_ProcessScreenContainer3, 80 );
lv_obj_set_y( ui_ProcessScreenContainer3, 67 );
lv_obj_set_align( ui_ProcessScreenContainer3, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_ProcessScreenContainer3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_ProcessScreenContainer3, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ProcessScreenContainer3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ProcessScreenContainer3, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_ProcessScreenContainer3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_ProcessScreenContainer3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_ProcessScreenContainer3, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_ProcessScreenContainer3, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_High_Temp_Alarm_Spinbox = lv_spinbox_create(ui_ProcessScreenContainer3);
lv_obj_set_width( ui_High_Temp_Alarm_Spinbox, 45);
lv_obj_set_height( ui_High_Temp_Alarm_Spinbox, 35);
lv_obj_set_x( ui_High_Temp_Alarm_Spinbox, 0 );
lv_obj_set_y( ui_High_Temp_Alarm_Spinbox, 5 );
lv_obj_set_align( ui_High_Temp_Alarm_Spinbox, LV_ALIGN_CENTER );
lv_spinbox_set_digit_format( ui_High_Temp_Alarm_Spinbox, 2, 0);
lv_spinbox_set_range( ui_High_Temp_Alarm_Spinbox, 20,50 );
lv_spinbox_set_cursor_pos(ui_High_Temp_Alarm_Spinbox, 1 - 1);
lv_spinbox_set_value( ui_High_Temp_Alarm_Spinbox, 40 );
lv_obj_set_style_border_color(ui_High_Temp_Alarm_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_High_Temp_Alarm_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_High_Temp_Alarm_Spinbox, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_High_Temp_Alarm_Spinbox, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_High_Temp_Alarm_Spinbox, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_High_Temp_Alarm_Spinbox, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_blend_mode(ui_High_Temp_Alarm_Spinbox, LV_BLEND_MODE_ADDITIVE, LV_PART_CURSOR| LV_STATE_DEFAULT);
lv_obj_set_style_opa(ui_High_Temp_Alarm_Spinbox, 0, LV_PART_CURSOR| LV_STATE_DEFAULT);

ui_High_Temp_Alarm_Plus_Button = lv_btn_create(ui_ProcessScreenContainer3);
lv_obj_set_width( ui_High_Temp_Alarm_Plus_Button, 45);
lv_obj_set_height( ui_High_Temp_Alarm_Plus_Button, 45);
lv_obj_set_x( ui_High_Temp_Alarm_Plus_Button, 48 );
lv_obj_set_y( ui_High_Temp_Alarm_Plus_Button, 5 );
lv_obj_set_align( ui_High_Temp_Alarm_Plus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_High_Temp_Alarm_Plus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_High_Temp_Alarm_Plus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_High_Temp_Alarm_Plus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_High_Temp_Alarm_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_High_Temp_Alarm_Plus_Button, &ui_img_plus_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_High_Temp_Alarm_Plus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_High_Temp_Alarm_Plus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_High_Temp_Alarm_Plus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_High_Temp_Alarm_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_High_Temp_Alarm_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_High_Temp_Alarm_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_High_Temp_Alarm_Plus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_High_Temp_Alarm_Minus_Button = lv_btn_create(ui_ProcessScreenContainer3);
lv_obj_set_width( ui_High_Temp_Alarm_Minus_Button, 45);
lv_obj_set_height( ui_High_Temp_Alarm_Minus_Button, 45);
lv_obj_set_x( ui_High_Temp_Alarm_Minus_Button, -48 );
lv_obj_set_y( ui_High_Temp_Alarm_Minus_Button, 5 );
lv_obj_set_align( ui_High_Temp_Alarm_Minus_Button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_High_Temp_Alarm_Minus_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_High_Temp_Alarm_Minus_Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_High_Temp_Alarm_Minus_Button, lv_color_hex(0x080052), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_High_Temp_Alarm_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_High_Temp_Alarm_Minus_Button, &ui_img_1731839073, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_color(ui_High_Temp_Alarm_Minus_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_High_Temp_Alarm_Minus_Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_High_Temp_Alarm_Minus_Button, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_High_Temp_Alarm_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_High_Temp_Alarm_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_High_Temp_Alarm_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_High_Temp_Alarm_Minus_Button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_lable37892 = lv_label_create(ui_ProcessScreenContainer3);
lv_obj_set_width( ui_lable37892, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_lable37892, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_lable37892, 1 );
lv_obj_set_y( ui_lable37892, 25 );
lv_obj_set_align( ui_lable37892, LV_ALIGN_CENTER );
lv_label_set_text(ui_lable37892," C° ");
lv_obj_set_style_text_font(ui_lable37892, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_lable37892, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_lable37892, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_lable37892, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ProcessScreenContainer4 = lv_obj_create(ui_processSettingScreen);
lv_obj_remove_style_all(ui_ProcessScreenContainer4);
lv_obj_set_width( ui_ProcessScreenContainer4, 150);
lv_obj_set_height( ui_ProcessScreenContainer4, 45);
lv_obj_set_x( ui_ProcessScreenContainer4, -80 );
lv_obj_set_y( ui_ProcessScreenContainer4, 40 );
lv_obj_set_align( ui_ProcessScreenContainer4, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_ProcessScreenContainer4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_ProcessScreenContainer4, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ProcessScreenContainer4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ProcessScreenContainer4, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_ProcessScreenContainer4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_ProcessScreenContainer4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_ProcessScreenContainer4, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_ProcessScreenContainer4, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_PressureAlarmSwitch = lv_switch_create(ui_ProcessScreenContainer4);
lv_obj_set_width( ui_PressureAlarmSwitch, 50);
lv_obj_set_height( ui_PressureAlarmSwitch, 25);
lv_obj_set_x( ui_PressureAlarmSwitch, 45 );
lv_obj_set_y( ui_PressureAlarmSwitch, 5 );
lv_obj_set_align( ui_PressureAlarmSwitch, LV_ALIGN_CENTER );
lv_obj_add_state( ui_PressureAlarmSwitch, LV_STATE_CHECKED );     /// States
lv_obj_set_style_bg_color(ui_PressureAlarmSwitch, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PressureAlarmSwitch, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_PressureAlarmSwitch, lv_color_hex(0x00B639), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_PressureAlarmSwitch, 255, LV_PART_MAIN| LV_STATE_CHECKED);

lv_obj_set_style_bg_color(ui_PressureAlarmSwitch, lv_color_hex(0x00B639), LV_PART_INDICATOR | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_PressureAlarmSwitch, 255, LV_PART_INDICATOR| LV_STATE_CHECKED);

ui_PressureAlarmSwitch_ONlabel = lv_label_create(ui_ProcessScreenContainer4);
lv_obj_set_width( ui_PressureAlarmSwitch_ONlabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_PressureAlarmSwitch_ONlabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_PressureAlarmSwitch_ONlabel, -50 );
lv_obj_set_y( ui_PressureAlarmSwitch_ONlabel, 5 );
lv_obj_set_align( ui_PressureAlarmSwitch_ONlabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_PressureAlarmSwitch_ONlabel,"ON");
lv_obj_add_flag( ui_PressureAlarmSwitch_ONlabel, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_PressureAlarmSwitch_ONlabel, lv_color_hex(0x00BE10), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_PressureAlarmSwitch_ONlabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_PressureAlarmSwitch_ONlabel, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_PressureAlarmSwitch_OFFlabel = lv_label_create(ui_ProcessScreenContainer4);
lv_obj_set_width( ui_PressureAlarmSwitch_OFFlabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_PressureAlarmSwitch_OFFlabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_PressureAlarmSwitch_OFFlabel, -50 );
lv_obj_set_y( ui_PressureAlarmSwitch_OFFlabel, 5 );
lv_obj_set_align( ui_PressureAlarmSwitch_OFFlabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_PressureAlarmSwitch_OFFlabel,"OFF");
lv_obj_add_flag( ui_PressureAlarmSwitch_OFFlabel, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_PressureAlarmSwitch_OFFlabel, lv_color_hex(0xFF0400), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_PressureAlarmSwitch_OFFlabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_PressureAlarmSwitch_OFFlabel, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ProcessScreenContainer5 = lv_obj_create(ui_processSettingScreen);
lv_obj_remove_style_all(ui_ProcessScreenContainer5);
lv_obj_set_width( ui_ProcessScreenContainer5, 150);
lv_obj_set_height( ui_ProcessScreenContainer5, 45);
lv_obj_set_x( ui_ProcessScreenContainer5, -80 );
lv_obj_set_y( ui_ProcessScreenContainer5, 94 );
lv_obj_set_align( ui_ProcessScreenContainer5, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_ProcessScreenContainer5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_ProcessScreenContainer5, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ProcessScreenContainer5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ProcessScreenContainer5, 96, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_ProcessScreenContainer5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_ProcessScreenContainer5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_ProcessScreenContainer5, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_ProcessScreenContainer5, LV_BORDER_SIDE_FULL, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TempAlarmSwitch = lv_switch_create(ui_ProcessScreenContainer5);
lv_obj_set_width( ui_TempAlarmSwitch, 50);
lv_obj_set_height( ui_TempAlarmSwitch, 25);
lv_obj_set_x( ui_TempAlarmSwitch, 45 );
lv_obj_set_y( ui_TempAlarmSwitch, 5 );
lv_obj_set_align( ui_TempAlarmSwitch, LV_ALIGN_CENTER );
lv_obj_add_state( ui_TempAlarmSwitch, LV_STATE_CHECKED );     /// States
lv_obj_set_style_bg_color(ui_TempAlarmSwitch, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TempAlarmSwitch, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TempAlarmSwitch, lv_color_hex(0x00B639), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_TempAlarmSwitch, 255, LV_PART_MAIN| LV_STATE_CHECKED);

lv_obj_set_style_bg_color(ui_TempAlarmSwitch, lv_color_hex(0x00B639), LV_PART_INDICATOR | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_TempAlarmSwitch, 255, LV_PART_INDICATOR| LV_STATE_CHECKED);

ui_TempAlarmSwitch_ONlabel = lv_label_create(ui_ProcessScreenContainer5);
lv_obj_set_width( ui_TempAlarmSwitch_ONlabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TempAlarmSwitch_ONlabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TempAlarmSwitch_ONlabel, -50 );
lv_obj_set_y( ui_TempAlarmSwitch_ONlabel, 5 );
lv_obj_set_align( ui_TempAlarmSwitch_ONlabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_TempAlarmSwitch_ONlabel,"ON");
lv_obj_add_flag( ui_TempAlarmSwitch_ONlabel, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_TempAlarmSwitch_ONlabel, lv_color_hex(0x00BE10), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TempAlarmSwitch_ONlabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TempAlarmSwitch_ONlabel, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TempAlarmSwitch_OFFlabel = lv_label_create(ui_ProcessScreenContainer5);
lv_obj_set_width( ui_TempAlarmSwitch_OFFlabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TempAlarmSwitch_OFFlabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TempAlarmSwitch_OFFlabel, -50 );
lv_obj_set_y( ui_TempAlarmSwitch_OFFlabel, 5 );
lv_obj_set_align( ui_TempAlarmSwitch_OFFlabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_TempAlarmSwitch_OFFlabel,"OFF");
lv_obj_add_flag( ui_TempAlarmSwitch_OFFlabel, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_TempAlarmSwitch_OFFlabel, lv_color_hex(0xFF0400), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TempAlarmSwitch_OFFlabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TempAlarmSwitch_OFFlabel, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_High_Temp_Alarm_Label = lv_label_create(ui_processSettingScreen);
lv_obj_set_width( ui_High_Temp_Alarm_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_High_Temp_Alarm_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_High_Temp_Alarm_Label, 80 );
lv_obj_set_y( ui_High_Temp_Alarm_Label, 20 );
lv_obj_set_align( ui_High_Temp_Alarm_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_High_Temp_Alarm_Label," Temp Alarm ");
lv_obj_set_style_text_color(ui_High_Temp_Alarm_Label, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_High_Temp_Alarm_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_High_Temp_Alarm_Label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_High_Temp_Alarm_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_High_Temp_Alarm_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_High_Temp_Alarm_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_High_Pressure_Alarm_Label = lv_label_create(ui_processSettingScreen);
lv_obj_set_width( ui_High_Pressure_Alarm_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_High_Pressure_Alarm_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_High_Pressure_Alarm_Label, -80 );
lv_obj_set_y( ui_High_Pressure_Alarm_Label, 20 );
lv_obj_set_align( ui_High_Pressure_Alarm_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_High_Pressure_Alarm_Label," Pressure Alarm ");
lv_obj_set_style_text_color(ui_High_Pressure_Alarm_Label, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_High_Pressure_Alarm_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_High_Pressure_Alarm_Label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_High_Pressure_Alarm_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_High_Pressure_Alarm_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_High_Pressure_Alarm_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Compressor_Offset_Label = lv_label_create(ui_processSettingScreen);
lv_obj_set_width( ui_Compressor_Offset_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Compressor_Offset_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Compressor_Offset_Label, 80 );
lv_obj_set_y( ui_Compressor_Offset_Label, -70 );
lv_obj_set_align( ui_Compressor_Offset_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Compressor_Offset_Label," Comp Range ");
lv_obj_set_style_text_color(ui_Compressor_Offset_Label, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Compressor_Offset_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Compressor_Offset_Label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_Compressor_Offset_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Compressor_Offset_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Compressor_Offset_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Compressor_Range_Label = lv_label_create(ui_processSettingScreen);
lv_obj_set_width( ui_Compressor_Range_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Compressor_Range_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Compressor_Range_Label, -80 );
lv_obj_set_y( ui_Compressor_Range_Label, -70 );
lv_obj_set_align( ui_Compressor_Range_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Compressor_Range_Label," Compressor ");
lv_obj_set_style_text_color(ui_Compressor_Range_Label, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Compressor_Range_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Compressor_Range_Label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_Compressor_Range_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Compressor_Range_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Compressor_Range_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_High_Temp_Alarm_Switch_Label = lv_label_create(ui_processSettingScreen);
lv_obj_set_width( ui_High_Temp_Alarm_Switch_Label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_High_Temp_Alarm_Switch_Label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_High_Temp_Alarm_Switch_Label, -80 );
lv_obj_set_y( ui_High_Temp_Alarm_Switch_Label, 75 );
lv_obj_set_align( ui_High_Temp_Alarm_Switch_Label, LV_ALIGN_CENTER );
lv_label_set_text(ui_High_Temp_Alarm_Switch_Label," Temp Alarm ");
lv_obj_set_style_text_color(ui_High_Temp_Alarm_Switch_Label, lv_color_hex(0x080041), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_High_Temp_Alarm_Switch_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_High_Temp_Alarm_Switch_Label, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_High_Temp_Alarm_Switch_Label, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_High_Temp_Alarm_Switch_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_High_Temp_Alarm_Switch_Label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_returnButton5, ui_event_returnButton5, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Setting_Save_btn, ui_event_Setting_Save_btn, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Compressor_Range_Plus_Button, ui_event_Compressor_Range_Plus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Compressor_Range_Minus_Button, ui_event_Compressor_Range_Minus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Compressor_Offset_Plus_Button, ui_event_Compressor_Offset_Plus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Compressor_Offset_Minus_Button, ui_event_Compressor_Offset_Minus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_High_Temp_Alarm_Plus_Button, ui_event_High_Temp_Alarm_Plus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_High_Temp_Alarm_Minus_Button, ui_event_High_Temp_Alarm_Minus_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PressureAlarmSwitch, ui_event_PressureAlarmSwitch, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TempAlarmSwitch, ui_event_TempAlarmSwitch, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_processSettingScreen, ui_event_processSettingScreen, LV_EVENT_ALL, NULL);
uic_processSettingScreen = ui_processSettingScreen;
uic_returnButton5 = ui_returnButton5;
uic_ProcessSettingCTRL = ui_ProcessSettingCTRL;
uic_Setting_Save_btn = ui_Setting_Save_btn;
uic_Setting_Save_btn_label = ui_Setting_Save_btn_label;
uic_ProcessScreenContainer1 = ui_ProcessScreenContainer1;
uic_Compressor_Range_Spinbox = ui_Compressor_Range_Spinbox;
uic_Compressor_Range_Plus_Button = ui_Compressor_Range_Plus_Button;
uic_Compressor_Range_Minus_Button = ui_Compressor_Range_Minus_Button;
uic_lable3951 = ui_lable3951;
uic_ProcessScreenContainer2 = ui_ProcessScreenContainer2;
uic_Compressor_Offste_Spinbox = ui_Compressor_Offste_Spinbox;
uic_Compressor_Offset_Plus_Button = ui_Compressor_Offset_Plus_Button;
uic_Compressor_Offset_Minus_Button = ui_Compressor_Offset_Minus_Button;
uic_lable39854 = ui_lable39854;
uic_ProcessScreenContainer3 = ui_ProcessScreenContainer3;
uic_High_Temp_Alarm_Spinbox = ui_High_Temp_Alarm_Spinbox;
uic_High_Temp_Alarm_Plus_Button = ui_High_Temp_Alarm_Plus_Button;
uic_High_Temp_Alarm_Minus_Button = ui_High_Temp_Alarm_Minus_Button;
uic_lable37892 = ui_lable37892;
uic_ProcessScreenContainer4 = ui_ProcessScreenContainer4;
uic_PressureAlarmSwitch = ui_PressureAlarmSwitch;
uic_PressureAlarmSwitch_ONlabel = ui_PressureAlarmSwitch_ONlabel;
uic_PressureAlarmSwitch_OFFlabel = ui_PressureAlarmSwitch_OFFlabel;
uic_ProcessScreenContainer5 = ui_ProcessScreenContainer5;
uic_TempAlarmSwitch = ui_TempAlarmSwitch;
uic_TempAlarmSwitch_ONlabel = ui_TempAlarmSwitch_ONlabel;
uic_TempAlarmSwitch_OFFlabel = ui_TempAlarmSwitch_OFFlabel;
uic_High_Temp_Alarm_Label = ui_High_Temp_Alarm_Label;
uic_High_Pressure_Alarm_Label = ui_High_Pressure_Alarm_Label;
uic_Compressor_Offset_Label = ui_Compressor_Offset_Label;
uic_Compressor_Range_Label = ui_Compressor_Range_Label;
uic_High_Temp_Alarm_Label = ui_High_Temp_Alarm_Switch_Label;

}
