#include "BMESPIInterface.h"
#include <Wire.h>

bool BMESPIInterface::init(){
    // begin()
    _initialized = _bme.begin();

    return _initialized;
}

float BMESPIInterface:: read_temperature() {
    if (_initialized) {
        _temperature_c = _bme.readTemperature();
    }
    return _temperature_c;
}