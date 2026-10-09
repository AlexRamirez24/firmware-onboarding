#include "LEDController.h"

// Actually controllers rates from temperature. Uses .h file.

unsigned long LEDController:: temp_to_interval(float temperature_c) {

    using namespace BMEConstants;
    if (temperature_c <= TEMP_MIN) {
        return SLOW_BLINK_INTERVAL;
    }

    if (temperature_c >= TEMP_MAX) {
        return FAST_BLINK_INTERVAL;
    }

    // Defines how far between the range temp is at.
    const float fraction = (temperature_c - TEMP_MIN) / (TEMP_MAX - TEMP_MIN);

    // How much interval can shrink
    const float span = static_cast<float> (SLOW_BLINK_INTERVAL - FAST_BLINK_INTERVAL);

    return SLOW_BLINK_INTERVAL - static_cast<unsigned long> (fraction  * span);
}

bool LEDController::update(float temperature_c, unsigned long now) {
    _interval = temp_to_interval(temperature_c);

    if (now - _last_toggle >= _interval) {
        _last_toggle = now;
        _led_state = !_led_state;
    }
    return _led_state;
}