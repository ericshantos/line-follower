#include "AnalogSensor.hpp"
#include "hardware/adc.h"

AnalogSensor::AnalogSensor(uint gpio, uint adc_channel)
    : gpio(gpio), adc_channel(adc_channel) {

        init();
    }

void AnalogSensor::init() {
    adc_init();
    adc_gpio_init(gpio);
}

uint16_t AnalogSensor::read() {
    adc_select_input(adc_channel);
    return adc_read();
}

float AnalogSensor::read_normalized() {
    return static_cast<float>(read()) / 4095.0f;
}