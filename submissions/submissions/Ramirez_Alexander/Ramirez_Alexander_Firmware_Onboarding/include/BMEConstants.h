#pragma once
#include <Arduino.h>
namespace BMEConstants
{
// I2C
constexpr uint8_t I2C_ADDRESS = 0x77;
// SPI
constexpr uint8_t SPI_PIN = 10;
// Serial
constexpr unsigned long SERIAL_BAUD = 115200;
// LED Pin (adjust if wrong)
constexpr uint8_t LED_PIN = 7;

// Temperature mapping; Lower and Upper bound guesses
constexpr float TEMP_MIN = 20.0f;
constexpr float TEMP_MAX = 35.0f;

// Delays for toggling (miliseconds)
constexpr unsigned long SLOW_BLINK_INTERVAL = 1000;
constexpr unsigned long FAST_BLINK_INTERVAL = 100;

// Timing
constexpr unsigned long SENSOR_READ = 250;
constexpr unsigned long SERIAL_PRINT = 1000;


}