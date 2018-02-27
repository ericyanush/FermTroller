//
// Created by Eric Yanush on 2018-02-22.
//

#ifndef FERMTROLLER_GPIO_HPP
#define FERMTROLLER_GPIO_HPP

#include "types.hpp"

namespace Bedrock {
    namespace GPIO {

        class GPIOPort {
        public:
            dev_reg8_t PIN;
            dev_reg8_t DDR;
            dev_reg8_t PORT;
        };

        /**
         * Typdef a function type to return instance of GPIOPort
         * We add a level of indirection here to allow for easy mock testing
         */
        using GPIOPortProvider = GPIOPort& (*)(void);

        enum class PinMode : uint8_t {
            input = 0b0,
            output = 0b1
        };

        template <typename derived>
        class GPIOPin {
        public:

            void setMode(PinMode mode) {
                static_cast<derived*>(this)->setMode();
            }

            PinMode getMode() {
                return static_cast<derived*>(this)->getMode();
            }

            void on() {
                static_cast<derived*>(this)->on();
            }

            void off() {
                static_cast<derived*>(this)->off();
            }

            void toggle() {
                static_cast<derived*>(this)->toggle();
            }
        };
    };
}

#endif //FERMTROLLER_GPIO_HPP
