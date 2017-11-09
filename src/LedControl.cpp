// -----
// OneButton.cpp - Library for detecting button clicks, doubleclicks and long press pattern on a single button.
// This class is implemented for use with the Arduino environment.
// Copyright (c) by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// More information on: http://www.mathertel.de/Arduino
// -----
// Changelog: see OneButton.h
// -----

#include "LedControl.h"

#define LED_UNUSED_PIN   0xFF

// ----- Initialization and Default Values -----
LedControl::LedControl(uint8_t ledPin)
{
    _redPin = ledPin;
    _greenPin = LED_UNUSED_PIN;
    _bluePin = LED_UNUSED_PIN;
    pinMode(ledPin, OUTPUT);
}

LedControl::LedControl(uint8_t redPin, uint8_t greenPin, uint8_t bluePin)
{
    _redPin = redPin;      // set red pin
    _greenPin = greenPin;  // set green pin
    _bluePin = bluePin;    // set blue pin
    pinMode(_redPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_bluePin, OUTPUT);
}

void LedControl::rgbControl(uint32_t color)
{
    if(LED_UNUSED_PIN != _redPin ) {
        if((color >> 16) & 0xFF) {
            digitalWrite(_redPin, HIGH);
        } else {
            digitalWrite(_redPin, LOW);
        }
    }

    if(LED_UNUSED_PIN != _greenPin ) {
        if((color >> 8) & 0xFF) {
            digitalWrite(_greenPin, HIGH);
        } else {
            digitalWrite(_greenPin, LOW);
        }
    }

    if(LED_UNUSED_PIN != _bluePin ) {
        if(color & 0xFF) {
            digitalWrite(_bluePin, HIGH);
        } else {
            digitalWrite(_bluePin, LOW);
        }
    }
}

void LedControl::rgbToggle(void)
{
    if(_rgb_info.rgb_last_color) {
        rgbControl(0);
        _rgb_info.rgb_last_color = 0;
    } else {
        rgbControl(_rgb_info.rgb_color);
        _rgb_info.rgb_last_color = _rgb_info.rgb_color;
    }
}

void LedControl::ledColor(uint8_t led)
{
    rgbColor(led, 0, 0);
}

void LedControl::ledBlink(uint8_t led, uint16_t period)
{
    rgbBlink(led, 0, 0, period);
}

void LedControl::rgbColor(uint8_t red, uint8_t green, uint8_t blue)
{
    memset(&_rgb_info, 0, sizeof(_rgb_info));

    _rgb_info.rgb_mode = RGB_MODE_COLOR;
    _rgb_info.rgb_color = (red << 16) | (green << 8) | blue;
    rgbControl(_rgb_info.rgb_color);
}

void LedControl::rgbBlink(uint8_t red, uint8_t green, uint8_t blue, uint16_t period)
{
    memset((uint8_t *)&_rgb_info, 0, sizeof(_rgb_info));

    _rgb_info.rgb_mode = RGB_MODE_BLINK;
    _rgb_info.rgb_color = (red << 16) | (green << 8) | blue;
    _rgb_info.rgb_period = period > 100 ? period >> 1 : 50;
    _startTime = millis();
}

void LedControl::loop(void)
{
    system_tick_t now = millis(); // current (relative) time in msecs.

    if(RGB_MODE_BLINK == _rgb_info.rgb_mode) {
        if((now - _startTime) > _rgb_info.rgb_period) {
            rgbToggle();
            _startTime = now;
        }
    }
}

