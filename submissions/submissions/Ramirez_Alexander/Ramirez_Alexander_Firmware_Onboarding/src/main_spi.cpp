#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

namespace {
    unsigned long last_read = 0;
    unsigned long last_print = 0;
    float temperature_c = 0.0f;
}

void setup() {
    Serial.begin(BMEConstants::SERIAL_BAUD);

    pinMode(BMEConstants:: LED_PIN, OUTPUT);
    digitalWrite(BMEConstants:: LED_PIN, LOW);

    BMESPIInterfaceInstance::create();
    LEDControllerInstance:: create();

    if (!BMESPIInterfaceInstance:: instance().init()) {
        Serial.println("ERROR: BME sensor not found using SPI");
        digitalWrite(BMEConstants::LED_PIN, HIGH);
        while(true) {}
    }

    Serial.println("BME Sensor ready! SPI version");
    temperature_c = BMESPIInterfaceInstance:: instance().read_temperature();


}

void loop() {
    const unsigned long now = millis();

    if (now - last_read >= BMEConstants:: SENSOR_READ) {
        last_read = now;
        temperature_c = BMESPIInterfaceInstance:: instance().read_temperature();
    }

    const bool led_on = LEDControllerInstance::instance().update(temperature_c, now);
    digitalWrite(BMEConstants::LED_PIN, led_on ? HIGH : LOW);

    if (now - last_print >= BMEConstants::SERIAL_PRINT) {
        last_print = now;
        Serial.print("Temp:");
        Serial.print(temperature_c, 2);
        Serial.print(" | toggle every");
        Serial.print(LEDControllerInstance::instance().get_interval_ms());
    }
}