#include "pico/stdlib.h"
#include "Engine.hpp"
#include "Sensor.hpp"
#include "Pins.hpp"


int main() {

    Sensor sensor_left(Pins::Sensor::LEFT);
    Sensor sensor_right(Pins::Sensor::RIGHT);

    Engine left(
        Pins::Engine::LEFT_1,
        Pins::Engine::LEFT_2
    );

    Engine right(
        Pins::Engine::RIGHT_1,
        Pins::Engine::RIGHT_2
    );

    while (true) {
        
        bool sR = sensor_left.read();
        bool sL = sensor_right.read();

        if (sL && sR) {
            left.stop();
            right.stop();
        } 

        else if (!sL && sR) {
            left.reverse();
            right.forward();
        }

        else if (sL && !sR) {
            left.forward();
            right.reverse();
        }

        else if (!sL && !sR) {
            left.reverse();
            right.reverse();

            sleep_ms(1000);
        }

        else {
            left.forward();
            right.forward();
        }
    }
}
