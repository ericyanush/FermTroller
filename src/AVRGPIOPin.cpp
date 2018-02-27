//
// Created by Eric Yanush on 2018-02-24.
//
#include "AVRGPIOPin.hpp"
#include "GPIO.hpp"

using namespace Bedrock::GPIO;

void AVRGPIOPin::setMode(PinMode mode) {
    //clear the current config
    port().DDR &= ~(0b1 << pin);
    port().DDR |= (static_cast<uint8_t>(mode) << pin);
}


PinMode AVRGPIOPin::getMode() {
    return static_cast<PinMode>((port().DDR >> pin) & 0b1);
}

void AVRGPIOPin::on()  {
    port().PORT |= (1 << pin);
}

void AVRGPIOPin::off() {
    port().PORT &= ~(1 << pin);
}

void AVRGPIOPin::toggle()  {
    port().PORT ^= (1 << pin);
}