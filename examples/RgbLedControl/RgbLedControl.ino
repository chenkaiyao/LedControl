/*
 This is a sample sketch to show how to use the LedControlLibrary
*/

#include "LedControl.h"

LedControl ledControl(D1, D2, D3, false, false);

static void SystemTickHandle(void)
{
    //该函数处理时间尽量短, 不允许阻塞
    ledControl.loop();
}

// setup code here, to run once:
void setup()
{
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    Serial.println("Starting Rgb Blink...");

    System.onSysTick(SystemTickHandle);
    ledControl.rgbBlink(0xff, 0xff, 0xff, 500);
}

// main code here, to run repeatedly:
void loop()
{
    ledControl.loop();
}

