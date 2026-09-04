#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "pico/stdlib.h"

class Engine {
private:
    uint pin1;
    uint pin2;

    void init();

public:
    Engine(uint pin1, uint pin2);

    void forward();
    void reverse();
    void stop();
};

#endif