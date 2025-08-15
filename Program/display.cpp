// display.cpp
#include "display.h"

// ================================
// Global Variables
// SPI bus, RGB panel, display, touch driver, and LVGL buffers
// ================================
Arduino_DataBus *bus = new Arduino_SWSPI(
    GFX_NOT_DEFINED /* DC */, 42 /* CS */,
    2 /* SCK */, 1 /* MOSI */, GFX_NOT_DEFINED /* MISO */
);                                             // SPI bus for ST7701 display initialization

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    40 /* DE */, 39 /* VSYNC */, 38 /* HSYNC */, 41 /* PCLK */,
    46 /* R0 */, 3 /* R1 */, 8 /* R2 */, 18 /* R3 */, 17 /* R4 */,
    14 /* G0 */, 13 /* G1 */, 12 /* G2 */, 11 /* G3 */, 10 /* G4 */, 9 /* G5 */,
    5 /* B0 */, 45 /* B1 */, 48 /* B2 */, 47 /* B3 */, 21 /* B4 */,
    1 /* hsync_polarity */, 40 /* hsync_front_porch */, 1 /* hsync_pulse_width */, 40 /* hsync_back_porch */,
    1 /* vsync_polarity */, 13 /* vsync_front_porch */, 1 /* vsync_pulse_width */, 32 /* vsync_back_porch */
);                                                                                    // RGB panel driver with Waveshare standard pins and optimized timings

Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
    screenWidth, screenHeight, rgbpanel, SCREEN_ROTATION, true /* auto_flush */,
    bus, GFX_NOT_DEFINED /* RST */, st7701_type1_init_operations, sizeof(st7701_type1_init_operations)); // RGB display with SPI bus

TouchDrvGT911 GT911; // GT911 touch driver
int16_t x[5], y[5];  // Arrays to store touch coordinates (up to 5 points)

static lv_disp_draw_buf_t draw_buf; // LVGL draw buffer
static lv_color_t *buf1 = nullptr;  // First buffer for LVGL
static lv_color_t *buf2 = nullptr;  // Second buffer for LVGL

// ================================
// Display Flushing
// Flush LVGL buffer to the screen
// ================================
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1); // Width of the area to flush
    uint32_t h = (area->y2 - area->y1 + 1); // Height of the area to flush

#if (LV_COLOR_16_SWAP != 0)
    gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
    gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif

    lv_disp_flush_ready(disp); // Signal that flushing is complete
}

// ================================
// Touch Input Management
// Read touch input and update LVGL input device data
// ================================
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    uint8_t touched = GT911.getPoint(x, y, GT911.getSupportTouchPoint()); // Get touch points

    if (touched > 0)
    {
        int16_t touchX = x[0]; // Use first touch point
        int16_t touchY = y[0];

        // Adjust coordinates based on screen rotation
        switch (gfx->getRotation())
        {
        case 0:
            break;
        case 1:
            touchX = y[0];
            touchY = gfx->height() - x[0];
            break;
        case 2:
            touchX = gfx->width() - x[0];
            touchY = gfx->height() - y[0];
            break;
        case 3:
            touchX = gfx->width() - y[0];
            touchY = x[0];
            break;
        }

        data->state = LV_INDEV_STATE_PR; // Touch pressed
        data->point.x = touchX;          // Set X coordinate
        data->point.y = touchY;          // Set Y coordinate

        updateLastTouchTime(millis()); // Update last touch time for UI logic
    }
    else
    {
        data->state = LV_INDEV_STATE_REL; // Touch released
    }
}

// ================================
// Display and Touch Setup
// Initialize display, touch controller, and LVGL
// ================================
void displaySetup()
{
    uint32_t currentTime = millis();

#ifdef Serial
    Serial.begin(115200); // Start serial communication for debugging
    Serial.printf("[Display][INFO][%lu] Initializing screen...\n", currentTime);
#endif

    // Initialize I2C for GT911 touch controller
    Wire.begin(15, 7);     // SDA: GPIO15, SCL: GPIO7
    
    Wire.setClock(400000); // Set I2C frequency to 400kHz

    GT911.setPins(-1, 16); // INT: GPIO16
    if (!GT911.begin(Wire, GT911_SLAVE_ADDRESS_L, 15, 7))
    {
#ifdef Serial
        Serial.printf("[Display][ERROR][%lu] Failed to find GT911 - check your wiring!\n", currentTime);
#endif
        while (1)
        {
            delay(1000); // Halt if GT911 initialization fails
        }
    }
#ifdef Serial
    Serial.printf("[Display][INFO][%lu] GT911 touch sensor initialized.\n", currentTime);
#endif
    GT911.setMaxTouchPoint(1); // Support single-touch

    // Optional: Configure GT911 registers for higher sensitivity and sampling rate
    // Enable after verifying I2C hardware (e.g., 4.7kΩ or 10kΩ pull-up resistors, stable connections)
    /*
    auto writeGT911Register = [](uint16_t reg, uint8_t value) {
        uint32_t currentTime = millis();
        Wire.beginTransmission(GT911_SLAVE_ADDRESS_L);
        Wire.write((uint8_t)(reg >> 8));   // Register address (high byte)
        Wire.write((uint8_t)(reg & 0xFF)); // Register address (low byte)
        Wire.write(value);                 // Value
        if (Wire.endTransmission() != 0)
        {
#ifdef Serial
            Serial.printf("[Display][ERROR][%lu] Failed to write to GT911 register 0x%04X\n", currentTime, reg);
#endif
        }
    };
    delay(100); // Delay to ensure GT911 is ready
    writeGT911Register(0x804D, 0x2C); // Touch sensitivity (conservative high value)
    writeGT911Register(0x8050, 0x03); // Sampling rate (conservative high value)
    */

    // Initialize display
    gfx->begin();
    gfx->setRotation(SCREEN_ROTATION); // Set screen rotation

    // Allocate buffers in PSRAM
    buf1 = (lv_color_t *)heap_caps_malloc(SIZE_SCREEN_BUFFER * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    if (!buf1)
    {
#ifdef Serial
        Serial.printf("[Display][ERROR][%lu] Failed to allocate buffer1 in PSRAM!\n", currentTime);
#endif
        while (1)
            delay(1000); // Halt if allocation fails
    }
#ifdef Serial
    Serial.printf("[Display][INFO][%lu] Buffer1 allocated at %p, size: %d bytes\n", currentTime, buf1, SIZE_SCREEN_BUFFER * sizeof(lv_color_t));
#endif

    buf2 = (lv_color_t *)heap_caps_malloc(SIZE_SCREEN_BUFFER * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    if (!buf2)
    {
#ifdef Serial
        Serial.printf("[Display][ERROR][%lu] Failed to allocate buffer2 in PSRAM!\n", currentTime);
#endif
        heap_caps_free(buf1);
        while (1)
            delay(1000); // Halt if allocation fails
    }
#ifdef Serial
    Serial.printf("[Display][INFO][%lu] Buffer2 allocated at %p, size: %d bytes\n", currentTime, buf2, SIZE_SCREEN_BUFFER * sizeof(lv_color_t));
#endif

    // Initialize LVGL draw buffer
    lv_disp_draw_buf_init(&draw_buf, buf1, buf2, SIZE_SCREEN_BUFFER);

    // Initialize LVGL library
    lv_init();

    // Set up LVGL display driver
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;    // Horizontal resolution
    disp_drv.ver_res = screenHeight;   // Vertical resolution
    disp_drv.flush_cb = my_disp_flush; // Flush callback
    disp_drv.draw_buf = &draw_buf;     // Draw buffer
    disp_drv.sw_rotate = 1;            // Enable software rotation
    lv_disp_drv_register(&disp_drv);   // Register display driver

    // Set up LVGL input device driver for touch
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER; // Touch input type
    indev_drv.read_cb = my_touchpad_read;   // Touch read callback
    lv_indev_drv_register(&indev_drv);      // Register input driver

    // Initialize custom UI components
    ui_init();

    // Load boot screen
    lv_scr_load(ui_Boot_Screen);

#ifdef Serial
    Serial.printf("[Display][INFO][%lu] Screen, touch, and UI setup completed.\n", currentTime);
#endif
}

// ================================
// Main Display Loop
// Process LVGL tasks and update UI
// ================================
void displayLoop()
{
    uint32_t currentTime = millis();

    // Process LVGL tasks
    lv_timer_handler();

    // Check for touch timeout and switch to main screen if needed
    if (millis() - getLastTouchTime() > getTimeoutDuration() && lv_scr_act() != ui_mainScreen && !isAnyContainerVisible())
    {
        switchToMainScreen();
#ifdef Serial
        Serial.printf("[Display][INFO][%lu] Switched to main screen due to touch timeout\n", currentTime);
#endif
    }

    // Update UI elements
    updateMainScreenUI();
    updateStatusScreenUI();

    // Short delay to prevent blocking
    delay(5);
}