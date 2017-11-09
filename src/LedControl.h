// -----
// OneButton.h - Library for detecting button clicks, doubleclicks and long press pattern on a single button.
// This class is implemented for use with the Arduino environment.
// Copyright (c) by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// More information on: http://www.mathertel.de/Arduino
// -----
// 02.10.2010 created by Matthias Hertel
// 21.04.2011 transformed into a library
// 01.12.2011 include file changed to work with the Arduino 1.0 environment
// 23.03.2014 Enhanced long press functionalities by adding longPressStart and longPressStop callbacks
// 21.09.2015 A simple way for debounce detection added.
// 14.05.2017 Debouncing improvements.
// -----

#ifndef __LEDCONTROL_H__
#define __LEDCONTROL_H__

#include "Arduino.h"

class LedControl
{
    public:
        //Constructor
        LedControl(uint8_t ledPin);
        LedControl(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);

        void ledColor(uint8_t led);
        void ledBlink(uint8_t led, uint16_t period);
        void rgbColor(uint8_t red, uint8_t green, uint8_t blue);
        void rgbBlink(uint8_t red, uint8_t green, uint8_t blue, uint16_t period);
        //loop
        void loop(void);

    private:
        typedef enum {
            RGB_MODE_COLOR = 0,
            RGB_MODE_BLINK
        }rgb_mode_t;

        typedef struct {
            rgb_mode_t rgb_mode;
            uint16_t   rgb_period;
            uint32_t   rgb_color;
            uint32_t   rgb_last_color;
        }rgb_info_t;

        void rgbControl(uint32_t color);
        void rgbToggle(void);

        uint8_t _redPin;     // red pin num
        uint8_t _greenPin;   // green pin num
        uint8_t _bluePin;    // blue pin num
        rgb_info_t _rgb_info;
        system_tick_t _startTime;
};

#endif

