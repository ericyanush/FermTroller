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

        class GPIOPin {
        private:
            GPIOPortProvider port;
            uint8_t pin;
        public:
            GPIOPin(GPIOPortProvider port, uint8_t pin) :
                    port(port), pin(pin) {}

            void setMode(PinMode mode) {
                //clear the current config
                port().DDR &= ~(0b1 << pin);
                port().DDR |= (static_cast<uint8_t>(mode) << pin);
            }

            PinMode getMode() {
                return static_cast<PinMode>((port().DDR >> pin) & 0b1);
            }

            void on() {
                port().PORT |= (1 << pin);
            }

            void off() {
                port().PORT &= ~(1 << pin);
            }

            void toggle() {
                port().PORT ^= (1 << pin);
            }
        };
    };
}

#endif //FERMTROLLER_GPIO_HPP
