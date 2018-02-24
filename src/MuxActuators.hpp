//
// Created by Eric Yanush on 2018-02-24.
//

#ifndef FERMTROLLER_MUXACTUATORS_HPP
#define FERMTROLLER_MUXACTUATORS_HPP

#include "Actuators.hpp"
#include "GPIO.hpp"

class MuxActuators: Actuators {
    using Pin = Bedrock::GPIO::GPIOPin;
public:
    MuxActuators(Pin* masterReset, Pin* latch, Pin* clock, Pin* data);

    virtual void set(uint32_t mask);
    virtual void reset();

private:
    Pin *masterReset, *latch, *clock, *data;
};


#endif //FERMTROLLER_MUXACTUATORS_HPP
