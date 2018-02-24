//
// Created by Eric Yanush on 2018-02-22.
//

#include <util/delay.h>
#include "Processor.hpp"
#include "GPIO.hpp"

void init();

int main() {
    using Pin = Bedrock::GPIO::GPIOPin;
    using PinMode = Bedrock::GPIO::PinMode;

    Pin b(Processor::GPIOPort::B, 0);
    b.setMode(PinMode::output);

    while(true) {
        b.on();
        _delay_ms(500);
        b.off();
        _delay_ms(100);
    }
}