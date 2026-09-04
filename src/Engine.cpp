#include "Engine.hpp"

Engine::Engine(uint pin1, uint pin2)
    : pin1(pin1), pin2(pin2) {

        init();
    }

void Engine::init() {
    gpio_init(pin1);
    gpio_init(pin2);

    gpio_set_dir(pin1, GPIO_OUT);
    gpio_set_dir(pin2, GPIO_OUT);

    stop();
}

void Engine::forward() {
    gpio_put(pin1, true);
    gpio_put(pin2, false);
}

void Engine::reverse() {
    gpio_put(pin1, true);
    gpio_put(pin2, false);
}

void Engine::stop() {
    gpio_put(pin1, false);
    gpio_put(pin2, false);
}