/*
 This is a sample sketch to show how to use the LedControlLibrary
*/

#include "LedControl.h"

LedControl ledControl(D1, D2, D3, false, false);

// setup code here, to run once:
void setup()
{
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    Serial.println("Starting Rgb Blink...");

    ledControl.rgbBlink(0xff, 0xff, 0xff, 500);
}

// main code here, to run repeatedly:
void loop()
{
    ledControl.loop();
}

