//
// Created by Eric Yanush on 2018-02-24.
//

#ifndef FERMTROLLER_BOARD_HPP
#define FERMTROLLER_BOARD_HPP

#include "Actuators.hpp"

class Board {
public:
    virtual Actuators actuators() = 0;
};

#endif //FERMTROLLER_BOARD_HPP
