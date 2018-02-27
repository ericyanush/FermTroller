//
// Created by Eric Yanush on 2018-02-22.
//

#include <util/delay.h>
#include <AVRGPIOPin.hpp>
#include "Processor.hpp"


int main() {
    using PinMode = Bedrock::GPIO::PinMode;

    auto b = AVRGPIOPin(Processor::GPIOPort::B, 0);
    b.setMode(PinMode::output);

    while(true) {
        b.on();
        _delay_ms(800);
        b.off();
        _delay_ms(100);
    }
}