//
// Created by Eric Yanush on 2018-02-23.
//

#ifndef FERMTROLLER_ACTUATORS_HPP
#define FERMTROLLER_ACTUATORS_HPP

#include <stdint.h>

class Actuators {
public:
    virtual void set(uint32_t valueMask) = 0;
    virtual void reset() = 0;
};


#endif //FERMTROLLER_ACTUATORS_HPP
