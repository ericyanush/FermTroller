//
// Created by Eric Yanush on 2018-02-24.
//

#ifndef FERMTROLLER_AVRGPIOPIN_HPP
#define FERMTROLLER_AVRGPIOPIN_HPP

#include "GPIO.hpp"

using namespace Bedrock::GPIO;

class AVRGPIOPin: GPIOPin<AVRGPIOPin> {
public:
    AVRGPIOPin(GPIOPortProvider port, uint8_t pin) : port(port) , pin(pin) { }

    void setMode(PinMode mode);
    PinMode getMode();
    void on();
    void off();
    void toggle();

private:
    GPIOPortProvider port;
    uint8_t pin;
};

#endif //FERMTROLLER_AVRGPIOPIN_HPP
