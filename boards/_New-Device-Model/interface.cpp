#include "core/powerSave.h"
#include <interface.h>

/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() {
    pinMode(UP_BTN, INPUT_PULLUP);
    pinMode(DW_BTN, INPUT_PULLUP);
    pinMode(SEL_BTN, INPUT_PULLUP);
    pinMode(ESC_BTN, INPUT_PULLUP);
}

/***************************************************************************************
** Function name: _post_setup_gpio()
** Location: main.cpp
** Description:   second stage gpio setup to make a few functions work
***************************************************************************************/
void _post_setup_gpio() {
    // Backlight on (the TFT library may not drive it on this board)
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
}

/***************************************************************************************
** Function name: getBattery()
** location: display.cpp
** Description:   Delivers the battery value from 1-100
***************************************************************************************/
int getBattery() { return 0; }

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
**********************************************************************/
void _setBrightness(uint8_t brightval) {
    // simple on/off backlight (0..255 -> PWM)
    analogWrite(TFT_BL, brightval);
}

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    checkPowerSaveTime();
    PrevPress = false;
    NextPress = false;
    SelPress = false;
    AnyKeyPress = false;
    EscPress = false;

    bool up = digitalRead(UP_BTN) == BTN_ACT;
    bool down = digitalRead(DW_BTN) == BTN_ACT;
    bool sel = digitalRead(SEL_BTN) == BTN_ACT;
    bool esc = digitalRead(ESC_BTN) == BTN_ACT;
    bool any = up || down || sel || esc;

    if (any) {
        if (!wakeUpScreen()) AnyKeyPress = true;
        else goto END;
    }
    if (up) { PrevPress = true; }
    if (down) { NextPress = true; }
    if (esc) { EscPress = true; }
    if (sel) { SelPress = true; }
END:
    if (AnyKeyPress) {
        long tmp = millis();
        while ((millis() - tmp) < 200 &&
               (digitalRead(UP_BTN) == BTN_ACT || digitalRead(DW_BTN) == BTN_ACT ||
                digitalRead(SEL_BTN) == BTN_ACT || digitalRead(ESC_BTN) == BTN_ACT));
    }
}

/*********************************************************************
** Function: powerOff
** location: mykeyboard.cpp
** Turns off the device (or try to)
**********************************************************************/
void powerOff() {}

/*********************************************************************
** Function: checkReboot
** location: mykeyboard.cpp
** Btn logic to turn off the device (name is odd btw)
**********************************************************************/
void checkReboot() {}
