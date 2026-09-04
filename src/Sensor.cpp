#include "Sensor.hpp"

#include "pico/stdlib.h"

Sensor::Sensor(uint pin) 
    :  pin(pin) {

        init();
}

void Sensor::init () {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
};

bool Sensor::read () {
    return gpio_get(pin);
};