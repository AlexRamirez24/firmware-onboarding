#pragma once
#include <etl/singleton.h>
#include "BMEConstants.h"

// Decides how fast the LED will blink depending on temperature collected.

class LEDController {

    public:
        // default
        LEDController() = default;

        // Map temperature to blink rate; Slower rate for lower temp and vice versa
        static unsigned long temp_to_interval(float temperature_c);

        //update loop
        bool update(float temperature_c, unsigned long now);

        unsigned long get_interval_ms() const{
            return _interval;
        }
        bool get_led_state() const{
            return _led_state;
        }

    private:

        unsigned long _interval = BMEConstants:: SLOW_BLINK_INTERVAL;
        unsigned long _last_toggle = 0;
        bool _led_state = false;
};
using LEDControllerInstance = etl::singleton<LEDController>;
