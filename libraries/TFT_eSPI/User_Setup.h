// ESP32 S3 - ili9341 2.8" - v1.2

#define USER_SETUP_INFO "User_Setup"

#define ILI9341_DRIVER

// #define TFT_WIDTH 320
// #define TFT_HEIGHT 240

#define TFT_MISO 13 // (leave TFT SDO disconnected if other SPI devices share MISO)
#define TFT_MOSI 11
#define TFT_SCLK 12
#define TFT_CS 9  // Chip select control pin
#define TFT_DC 3  // Data Command control pin
#define TFT_RST 8 // Reset pin (could connect to RST pin)

// touch screen not select bcs Touch use another bus.
#define TOUCH_CS 18 // Chip select pin (T_CS) of touch screen(default is 5)

#define LOAD_GLCD  // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2 // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4 // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6 // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7 // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:.
#define LOAD_FONT8 // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
#define LOAD_GFXFF // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

#define SMOOTH_FONT

// TFT SPI clock frequency
// #define SPI_FREQUENCY  20000000
// #define SPI_FREQUENCY  27000000
#define SPI_FREQUENCY 40000000
// #define SPI_FREQUENCY  80000000

// The ESP32 has 2 free SPI ports i.e. VSPI and HSPI, the VSPI is the default.
// If the VSPI port is in use and pins are not accessible (e.g. TTGO T-Beam)
// then uncomment the following line:
// #define USE_HSPI_PORT
// #define USE_FSPI_PORT

// Optional reduced SPI frequency for reading TFT
#define SPI_READ_FREQUENCY 16000000

// SPI clock frequency for touch controller
#define SPI_TOUCH_FREQUENCY 2500000

// #define SUPPORT_TRANSACTIONS