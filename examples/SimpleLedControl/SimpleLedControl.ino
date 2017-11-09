/*
 This is a sample sketch to show how to use the LedControlLibrary
*/

#include "LedControl.h"

LedControl ledControl(D1, false, false);

// setup code here, to run once:
void setup()
{
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    Serial.println("Starting led Blink...");

    ledControl.ledBlink(0xff, 500);
}

// main code here, to run repeatedly:
void loop()
{
    ledControl.loop();
}

