#ifndef PINS_HPP
#define PINS_HPP

#include "pico/stdlib.h"


namespace Pins {

    namespace Engine {
        constexpr uint LEFT_1 = 13;
        constexpr uint LEFT_2 = 12;

        constexpr uint RIGHT_1 = 11;
        constexpr uint RIGHT_2 = 10;
    };

    namespace Sensor {
        constexpr uint LEFT = 17;
        constexpr uint RIGHT = 16;
    };
}

#endif