#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

static const uint8_t TX = 43;
static const uint8_t RX = 44;

static const uint8_t TXD2 = 1;
static const uint8_t RXD2 = 2;

// I2C moved away from the button pins
static const uint8_t SDA = 8;
static const uint8_t SCL = 9;

// Modified elsewhere
static const uint8_t SS = -1;
static const uint8_t MOSI = -1;
static const uint8_t MISO = -1;
static const uint8_t SCK = -1;

static const uint8_t G0 = 0;
static const uint8_t G1 = 1;
static const uint8_t G2 = 2;
static const uint8_t G3 = 3;
static const uint8_t G4 = 4;
static const uint8_t G5 = 5;
static const uint8_t G6 = 6;
static const uint8_t G7 = 7;
static const uint8_t G8 = 8;
static const uint8_t G9 = 9;
static const uint8_t G10 = 10;
static const uint8_t G11 = 11;
static const uint8_t G12 = 12;
static const uint8_t G13 = 13;
static const uint8_t G14 = 14;
static const uint8_t G15 = 15;
static const uint8_t G39 = 39;
static const uint8_t G40 = 40;
static const uint8_t G41 = 41;
static const uint8_t G42 = 42;
static const uint8_t G43 = 43;
static const uint8_t G44 = 44;
static const uint8_t G46 = 46;

static const uint8_t ADC1 = 7;
static const uint8_t ADC2 = 8;

#define FM_RSTPIN 40
#define PIN_CLK 43
#define I2S_SCLK_PIN 43
#define I2S_DATA_PIN 46
#define PIN_DATA 46

#define RGB_LED 21

#define BCLK 41
#define WCLK 43
#define DOUT 42

#define BAD_TX GROVE_SDA
#define BAD_RX GROVE_SCL

// ---------------- Buttons (wire GPIO <-> GND, internal pull-up) ----------------
#define UP_BTN 15   // Prev / Up
#define DW_BTN 14   // Next / Down
#define SEL_BTN 16  // Select / OK
#define ESC_BTN 17  // Back

#define HAS_BTN 0
#define BTN_ALIAS "\"Ok\""
#define BTN_PIN 0
#define BTN_ACT LOW

#define IR_TX_PINS '{{"M5 IR Mod", GROVE_SDA}, {"Pin 1", 1}, {"Pin 2", 2}}'
#define IR_RX_PINS '{{"M5 IR Mod", GROVE_SCL}, {"Pin 1", 1}, {"Pin 2", 2}}'
#define TXLED -1
#define LED_ON HIGH
#define LED_OFF LOW

#define RF_TX_PINS '{{"M5 RF433T", GROVE_SDA}, {"Pin 1", 1}, {"Pin 2", 2}}'
#define RF_RX_PINS '{{"M5 FR433R", GROVE_SCL}, {"Pin 1", 1}, {"Pin 2", 2}}'

#define CC1101_GDO0_PIN 9
#define CC1101_SS_PIN 10
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

#define NRF24_CE_PIN 6
#define NRF24_SS_PIN 7
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

// FP / FM / FG (text sizes) are defined in the .ini via build_src_flags,
// so they only apply to Bruce's own code and never break third-party libraries.

// ---------------- Display: 2.0" ST7789 240x320 ----------------
#define HAS_SCREEN 1
#define ROTATION 1
#define MINBRIGHT 160

#define USER_SETUP_LOADED 1
#define ST7789_DRIVER 1
#define TFT_RGB_ORDER 1  // if red/blue are swapped, change to 0
// If colors look inverted (negative), uncomment the next line:
// #define TFT_INVERSION_ON
#define TFT_WIDTH 240
#define TFT_HEIGHT 320
#define TFT_BACKLIGHT_ON 1
#define TFT_BL 38
#define TFT_RST 5
#define TFT_DC 7
#define TFT_MOSI 11
#define TFT_SCLK 12
#define TFT_CS 10
#define TFT_MISO 13
#define TOUCH_CS -1
#define SMOOTH_FONT 1
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000

// SD card pins moved to unused GPIOs so they never touch the buttons (no SD on this board)
#define SDCARD_CS 47
#define SDCARD_SCK 48
#define SDCARD_MISO 41
#define SDCARD_MOSI 42

#define GROVE_SDA 2
#define GROVE_SCL 1

#define SPI_SCK_PIN 12
#define SPI_MOSI_PIN 11
#define SPI_MISO_PIN 13
#define SPI_SS_PIN 10

#endif /* Pins_Arduino_h */
