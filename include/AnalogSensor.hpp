#ifndef ANALOG_SENSOR_HPP
#define ANALOG_SENSOR_HPP

#include "pico/stdlib.h"
#include <stdint.h>
#include <cstdint>

class AnalogSensor {
private:
    uint gpio;
    uint adc_channel;

    void init();

public:
    AnalogSensor(uint gpio, uint adc_channel);

    uint16_t read();
    float read_voltage();
    float read_normalized();
};

#endif