#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "pico/stdlib.h"

class Sensor {
private:
    uint pin;

    void init();

public:
    Sensor(uint pin);

    bool read();
};

#endif