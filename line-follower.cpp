#include "pico/stdlib.h"


const uint SENSOR_L = 17;
const uint SENSOR_R = 16;

const uint ENGINE_L_1 = 13;
const uint ENGINE_L_2 = 12;

const uint ENGINE_R_1 = 11;
const uint ENGINE_R_2 = 10;

struct Engine {
    uint pin1;
    uint pin2;

    void forward();
    void to_stop();
    void reverse();
};

void Engine::forward () {
    gpio_put(pin1, true);
    gpio_put(pin2, false);
};

void Engine::to_stop () {
    gpio_put(pin1, false);
    gpio_put(pin2, false);
};

void Engine::reverse () {
    gpio_put(pin1, false);
    gpio_put(pin2, true);
}

Engine engine_left = {
    ENGINE_L_1,
    ENGINE_L_2
};

Engine engine_right = {
    ENGINE_R_1,
    ENGINE_R_2
};

void init_sensor(const uint pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
}

void init_engine (const Engine& engine) {
    gpio_init(engine.pin1);
    gpio_set_dir(engine.pin1, GPIO_OUT);

    gpio_init(engine.pin2);
    gpio_set_dir(engine.pin2, GPIO_OUT);
};

int main() {

    init_sensor(SENSOR_L);
    init_sensor(SENSOR_R);

    init_engine(engine_left);
    init_engine(engine_right);

    while (true) {
        
        bool sR = gpio_get(SENSOR_R);
        bool sL = gpio_get(SENSOR_L);

        if (sL && sR) {
            engine_left.to_stop();
            engine_right.to_stop();
        } 

        else if (!sL && sR) {
            engine_left.reverse();
            engine_right.forward();
        }

        else if (sL && !sR) {
            engine_left.forward();
            engine_right.reverse();
        }

        else {
            engine_left.forward();
            engine_right.forward();
        }
    }
}
