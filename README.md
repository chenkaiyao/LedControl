# Arduino LedControl Library

## 库简介

LedControl是一个用户指示灯控制库，方便用户获取设备的状况。该库支持单个led指示灯和RGB三色灯的控制。

## 库使用方法

### 对象

LedControl(uint8_t ledPin, uint8_t invert, uint8_t pwm)

定义单个Led指示灯对象。 参数：
* ledPin : led灯控制pin
* invert : led灯控制是否相反。 true: 表示反向控制，此时ledPin输出高电平，灯灭。
* pwm    : led灯是否支持亮度控制。 true: 支持亮度控制

LedControl(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, uint8_t invert, uint8_t pwm)

定义RGB三色灯指示灯对象。 参数：
* redPin : led灯控制pin
* greenPin : led灯控制pin
* bluePin : led灯控制pin
* invert : led灯控制是否相反。 true: 表示反向控制，此时ledPin输出高电平，灯灭。
* pwm    : led灯是否支持亮度控制。 true: 支持亮度控制

### 函数接口

void ledColor(uint8_t led)

控制单个LED灯开关。 led为亮度。如果pwm为false, 只要led大于0，LED都亮。

void ledBlink(uint8_t led, uint16_t period)

控制单个LED灯闪灯，led为亮度，period为闪灯周期。

void rgbColor(uint8_t red, uint8_t green, uint8_t blue)

控制RGB 三色灯开关。 red为红灯亮度。如果pwm为false, 只要led大于0，LED都亮。

void rgbBlink(uint8_t red, uint8_t green, uint8_t blue, uint16_t period)

控制RGB 三色灯闪灯，red为红灯亮度。period为闪灯周期。

void loop(void)

指示灯处理，该函数必须频繁调用。可以放入定时器定期执行或者放入loop()函数内。  


