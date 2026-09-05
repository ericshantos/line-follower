#include "pico/stdlib.h"
#include "Engine.hpp"
#include "AnalogSensor.hpp"
#include "Pins.hpp"


int main() {

    AnalogSensor sensor_left(Pins::Analog::LEFT, 0);
    AnalogSensor sensor_right(Pins::Analog::RIGHT, 1);

    Engine left(
        Pins::Engine::LEFT_1,
        Pins::Engine::LEFT_2
    );

    Engine right(
        Pins::Engine::RIGHT_1,
        Pins::Engine::RIGHT_2
    );

    while (true) {
        
        float sR = sensor_left.read_normalized();
        float sL = sensor_right.read_normalized();

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
