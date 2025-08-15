// ui.c
#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_anim_t * loadingIMG_Animation(lv_obj_t *TargetObject, int delay);

// EVENTS
lv_obj_t *ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
lv_anim_t * loadingIMG_Animation(lv_obj_t *TargetObject, int delay)
{
    ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_img_set_src(TargetObject, &ui_img_loading_png); // تنظیم تصویر loading.png

    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 3600); // چرخش از 0 تا 360 درجه
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
    lv_anim_t *out_anim = lv_anim_start(&PropertyAnimation_0);

    return out_anim;
}

///////////////////// SCREENS ////////////////////
void ui_init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Boot_Screen_screen_init();
    ui_controlSettingScreen_screen_init();
    ui_processSettingScreen_screen_init();
    ui_addvansedSettingScreen_screen_init();
    ui_statusScreen_screen_init();
    ui_mainScreen_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Boot_Screen);
}

void ui_destroy(void)
{
    ui_Boot_Screen_screen_destroy();
    ui_controlSettingScreen_screen_destroy();
    ui_processSettingScreen_screen_destroy();
    ui_addvansedSettingScreen_screen_destroy();
    ui_statusScreen_screen_destroy();
    ui_mainScreen_screen_destroy();
}