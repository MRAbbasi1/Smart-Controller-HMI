// display.cpp

// -----------------------------------
// Display and Touch Module
// -----------------------------------

#include "display.h"

// ============================ Global Variables ============================

// TFT display instance
TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight);

// LVGL drawing buffer
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *buf1 = NULL;
static lv_color_t *buf2 = NULL;

// ============================ Display Flushing ============================

/**
 * @brief Flushes pixel data to the display.
 * @param disp LVGL display driver.
 * @param area Area to flush.
 * @param color_p Pixel color data.
 */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

// ============================ Touch Input Management =====================

/**
 * @brief Reads touchpad input and updates LVGL input data.
 * @param indev_driver LVGL input device driver.
 * @param data LVGL input data structure.
 */
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    uint16_t touchX, touchY;
    bool touched = tft.getTouch(&touchX, &touchY, 400);

    if (!touched)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;
        updateLastTouchTime(millis()); // Update touch timeout in uiLogic

#if (SCREEN_ROTATION == 1) || (SCREEN_ROTATION == 3)
        data->point.x = touchY;
        data->point.y = touchX;
#else
        data->point.x = touchX;
        data->point.y = touchY;
#endif
    }
}

// ============================ Display Setup ============================

/**
 * @brief Initializes the display, touch, and UI components.
 */
void displaySetup()
{
    Serial.println("[Display] Initializing screen...");

    // Allocate display buffers in PSRAM
    buf1 = (lv_color_t *)heap_caps_malloc(SIZE_SCREEN_BUFFER * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    if (!buf1)
    {
        Serial.println("[Display][ERROR] Failed to allocate buffer1 in PSRAM!");
        return;
    }

    buf2 = (lv_color_t *)heap_caps_malloc(SIZE_SCREEN_BUFFER * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    if (!buf2)
    {
        Serial.println("[Display][ERROR] Failed to allocate buffer2 in PSRAM!");
        heap_caps_free(buf1);
        return;
    }

    // Initialize LVGL drawing buffer
    lv_disp_draw_buf_init(&draw_buf, buf1, buf2, SIZE_SCREEN_BUFFER);

    // Initialize LVGL library
    lv_init();

    // Initialize TFT display
    tft.begin();
    tft.setRotation(SCREEN_ROTATION);

    // Set touch calibration based on rotation
#if SCREEN_ROTATION == 0
    uint16_t calData[5] = {230, 3580, 330, 3600, 4};
#elif SCREEN_ROTATION == 1
    uint16_t calData[5] = {215, 3438, 281, 3430, 6};
#elif SCREEN_ROTATION == 2
    uint16_t calData[5] = {230, 3580, 330, 3600, 2};
#elif SCREEN_ROTATION == 3
    uint16_t calData[5] = {230, 3580, 330, 3600, 0};
#endif
    tft.setTouch(calData);

    // Set up LVGL display driver
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // Set up LVGL touch input driver
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    // Initialize UI components
    ui_init();

    // Load boot screen
    lv_scr_load(ui_Boot_Screen);

    Serial.println("[Display] Screen, touch, and UI setup completed.");
}

// ============================ Main Loop ==============================

/**
 * @brief Handles display tasks and UI updates in the main loop.
 */
void displayLoop()
{
    // Process LVGL tasks
    lv_timer_handler();

    // Check for touch timeout and switch to main screen if needed
    if (millis() - getLastTouchTime() > getTimeoutDuration() && lv_scr_act() != ui_mainScreen && !isAnyContainerVisible())
    {
        switchToMainScreen();
    }

    // Update UI elements
    updateMainScreenUI();
    updateStatusScreenUI();

    // Small delay to prevent blocking
    delay(5);
}