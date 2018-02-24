//
// Created by Eric Yanush on 2018-02-24.
//

#include "MuxActuators.hpp"

MuxActuators::MuxActuators(Pin *masterReset, Pin *latch, Pin *clock, Pin *data): masterReset(masterReset),
                                                                                 latch(latch),
                                                                                 clock(clock),
                                                                                 data(data) {
    masterReset->on();
    latch->off();
    clock->off();
    data->off();
}

void MuxActuators::reset() {
    this->masterReset->off(); // active low
    this->latch->on();

    this->latch->off();
    this->masterReset->on();
}

void MuxActuators::set(uint32_t mask) {
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