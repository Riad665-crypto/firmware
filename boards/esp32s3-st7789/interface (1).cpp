#include "core/powerSave.h"
#include "core/utils.h"
#include <interface.h>

// No touchscreen on this board. Navigation is done with 4 buttons:
//   OK   = BTN_PIN (GPIO 0, boot button)  -> SelPress
//   UP   = GPIO 4                          -> PrevPress
//   DOWN = GPIO 6                          -> NextPress
//   ESC  = GPIO 15                         -> EscPress
// Each extra button goes from its GPIO to GND (internal pull-up used).
#define BRUCE_UP_BTN 4
#define BRUCE_DOWN_BTN 6
#define BRUCE_ESC_BTN 15

void _setup_gpio() {
    pinMode(BRUCE_UP_BTN, INPUT_PULLUP);
    pinMode(BRUCE_DOWN_BTN, INPUT_PULLUP);
    pinMode(BRUCE_ESC_BTN, INPUT_PULLUP);

    bruceConfig.colorInverted = 1;
}

// Runs AFTER tft.init()
void _post_setup_gpio() {
    pinMode(TFT_BL, OUTPUT);
    analogWrite(TFT_BL, 255);
}

int getBattery() { return 0; }

bool isCharging() { return false; }

void _setBrightness(uint8_t brightval) { analogWrite(TFT_BL, brightval); }

/*********************************************************************
** Function: InputHandler
** Handles PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    static unsigned long lastPress = 0;
    const unsigned long debounce = 200;

    checkPowerSaveTime();

    bool sel = (digitalRead(BTN_PIN) == BTN_ACT);
    bool up = (digitalRead(BRUCE_UP_BTN) == LOW);
    bool down = (digitalRead(BRUCE_DOWN_BTN) == LOW);
    bool back = (digitalRead(BRUCE_ESC_BTN) == LOW);

    if (!(sel || up || down || back)) return;

    // Debounce / repeat rate. Never block here (no while-loops),
    // otherwise the keyboard screen can stall.
    if (millis() - lastPress < debounce) return;
    lastPress = millis();

    if (!wakeUpScreen()) AnyKeyPress = true;
    if (sel) SelPress = true;
    if (up) PrevPress = true;
    if (down) NextPress = true;
    if (back) EscPress = true;
}

void powerOff() { esp_deep_sleep_start(); }

void goToDeepSleep() { esp_deep_sleep_start(); }

void checkReboot() {}
