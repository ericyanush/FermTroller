//
// Created by Eric Yanush on 2018-02-24.
//

#ifndef FERMTROLLER_MUXACTUATORS_HPP
#define FERMTROLLER_MUXACTUATORS_HPP

#include "Actuators.hpp"
#include "GPIO.hpp"

template <class Pin>
class MuxActuators: Actuators {
public:
    MuxActuators(Pin* masterReset, Pin* latch, Pin* clock, Pin* data): masterReset(masterReset),
                                                                       latch(latch),
                                                                       clock(clock),
                                                                       data(data) {
        masterReset->setMode(Bedrock::GPIO::PinMode::output);
        masterReset->on();
        latch->setMode(Bedrock::GPIO::PinMode::output);
        latch->off();
        clock->setMode(Bedrock::GPIO::PinMode::output);
        clock->off();
        data->setMode(Bedrock::GPIO::PinMode::output);
        data->off();
    }

    virtual void set(uint32_t mask) {
        this->latch->off();

        // shift out data MSB first
        for (int32_t i = 31;  i >= 0; i--) {
            mask & (1<<i) ? this->data->on() : this->data->off();
            this->clock->on();
            this->clock->off();
        }

        this->latch->on();
        this->latch->off();
    }

    virtual void reset()  {
        this->masterReset->off(); // active low
        this->latch->on();

        this->latch->off();
        this->masterReset->on();
    }

private:
    Pin *masterReset, *latch, *clock, *data;
};


#endif //FERMTROLLER_MUXACTUATORS_HPP
