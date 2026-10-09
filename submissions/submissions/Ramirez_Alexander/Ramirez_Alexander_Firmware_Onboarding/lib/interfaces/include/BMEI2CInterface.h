#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

// Talks to the sensor reader (BME280) over I2C and stores temperature for blinks.

class BMEI2CInterface{

    public:
    BMEI2CInterface() = default;

    // Start the sensor 
    bool init();
    
    // Read temperature from sensor and store
    float read_temperature();

    // getter
    float get_temperature() const{
        return _temperature_c;
    }

    bool is_initialized() const{
        return _initialized;
    }


    // default constructor
    private:

    Adafruit_BME280 _bme;
    float _temperature_c = 0.0f;
    bool _initialized = false;
};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
