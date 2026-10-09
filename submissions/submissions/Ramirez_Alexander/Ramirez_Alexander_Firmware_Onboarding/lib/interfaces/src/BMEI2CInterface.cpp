#include "BMEI2CInterface.h"
#include <Wire.h>

bool BMEI2CInterface::init(){
    // begin()
    _initialized = _bme.begin(BMEConstants::I2C_ADDRESS, &Wire);

    return _initialized;
}

float BMEI2CInterface:: read_temperature() {
    if (_initialized) {
        _temperature_c = _bme.readTemperature();
    }
    return _temperature_c;
}