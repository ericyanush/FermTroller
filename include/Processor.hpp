//
// Created by Eric Yanush on 2018-02-22.
//

#ifndef FERMTROLLER_BOARD_HPP
#define FERMTROLLER_BOARD_HPP

#include <avr/io.h>
#include "GPIO.hpp"

class Processor {
public:
    class GPIOPort {
    public:
        static auto& A() {
            return *reinterpret_cast<Bedrock::GPIO::GPIOPort*>(0x20);
        }
        static auto& B() {
            return *reinterpret_cast<Bedrock::GPIO::GPIOPort*>(0x23);
        }
        static auto& C() {
            return *reinterpret_cast<Bedrock::GPIO::GPIOPort*>(0x26);
        }
        static auto& D() {
            return *reinterpret_cast<Bedrock::GPIO::GPIOPort*>(0x29);
        }
    };
};

#endif //FERMTROLLER_BOARD_HPP
