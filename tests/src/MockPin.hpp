//
// Created by Eric Yanush on 2018-02-25.
//

#ifndef FERMTROLLER_MOCKPIN_HPP
#define FERMTROLLER_MOCKPIN_HPP

#include "gmock/gmock.h"
#include "GPIO.hpp"

class MockPin: Bedrock::GPIO::GPIOPin<MockPin> {
public:

    MOCK_METHOD1(setMode, void(Bedrock::GPIO::PinMode mode));
    MOCK_METHOD0(getMode, Bedrock::GPIO::PinMode());
    MOCK_METHOD0(on, void());
    MOCK_METHOD0(off, void());
    MOCK_METHOD0(toggle, void());
};


#endif //FERMTROLLER_MOCKPIN_HPP
