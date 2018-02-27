//
// Created by Eric Yanush on 2018-02-25.
//

#include "gtest/gtest.h"
#include "../../include/MuxActuators.hpp"
#include "MockPin.hpp"
#include <memory>

using ::testing::Eq;
using ::testing::InSequence;
using ::testing::Sequence;

class MuxActuatorsTests: public ::testing::Test {
public:

    virtual void SetUp() {
        // As we call these methods on construction, we are forced to expect them
        // here to prevent GTEST from whining about them.
        EXPECT_CALL(mr, setMode(Eq(Bedrock::GPIO::PinMode::output)));
        EXPECT_CALL(mr, on());
        EXPECT_CALL(latch, off());
        EXPECT_CALL(latch, setMode(Eq(Bedrock::GPIO::PinMode::output)));
        EXPECT_CALL(clock, off());
        EXPECT_CALL(clock, setMode(Eq(Bedrock::GPIO::PinMode::output)));
        EXPECT_CALL(data, off());
        EXPECT_CALL(data, setMode(Eq(Bedrock::GPIO::PinMode::output)));
        actuators = new MuxActuators<MockPin>(&mr, &latch, &clock, &data);
    }

    virtual void TearDown() {
        delete actuators;
    }

    MockPin mr, latch, clock, data;
    MuxActuators<MockPin> *actuators;

};

TEST_F(MuxActuatorsTests, TestSetup) {
    EXPECT_CALL(mr, setMode(Eq(Bedrock::GPIO::PinMode::output)));
    EXPECT_CALL(mr, on());
    EXPECT_CALL(latch, off());
    EXPECT_CALL(latch, setMode(Eq(Bedrock::GPIO::PinMode::output)));
    EXPECT_CALL(clock, off());
    EXPECT_CALL(clock, setMode(Eq(Bedrock::GPIO::PinMode::output)));
    EXPECT_CALL(data, off());
    EXPECT_CALL(data, setMode(Eq(Bedrock::GPIO::PinMode::output)));

    MuxActuators<MockPin> actuators(&mr, &latch, &clock, &data);
}

TEST_F(MuxActuatorsTests, TestReset) {
    InSequence enforcer;
    EXPECT_CALL(mr, off());
    EXPECT_CALL(latch, on());
    EXPECT_CALL(latch, off());
    EXPECT_CALL(mr, on());

    actuators->reset();
}

TEST_F(MuxActuatorsTests, TestSet) {
    Sequence dataSeq;
    uint32_t testvalue = 1 << 12;
    EXPECT_CALL(data, off()).Times(19).InSequence(dataSeq);
    EXPECT_CALL(data, on()).InSequence(dataSeq);
    EXPECT_CALL(data, off()).Times(12).InSequence(dataSeq);

    Sequence latchSeq;
    EXPECT_CALL(latch, off()).InSequence(latchSeq);
    EXPECT_CALL(latch, on()).InSequence(latchSeq);
    EXPECT_CALL(latch, off()).InSequence(latchSeq);

    Sequence clockSeq;
    EXPECT_CALL(clock, on()).Times(32);
    EXPECT_CALL(clock, off()).Times(32);

    actuators->set(testvalue);
}

TEST_F(MuxActuatorsTests, TestSetMSB) {
    Sequence dataSeq;
    uint32_t testvalue = 1 << 31;
    EXPECT_CALL(data, on()).InSequence(dataSeq);
    EXPECT_CALL(data, off()).Times(31).InSequence(dataSeq);

    Sequence latchSeq;
    EXPECT_CALL(latch, off()).InSequence(latchSeq);
    EXPECT_CALL(latch, on()).InSequence(latchSeq);
    EXPECT_CALL(latch, off()).InSequence(latchSeq);

    Sequence clockSeq;
    EXPECT_CALL(clock, on()).Times(32);
    EXPECT_CALL(clock, off()).Times(32);

    actuators->set(testvalue);
}

TEST_F(MuxActuatorsTests, TestSetLSB) {
    Sequence dataSeq;
    uint32_t testvalue = 1;
    EXPECT_CALL(data, off()).Times(31).InSequence(dataSeq);
    EXPECT_CALL(data, on()).InSequence(dataSeq);

    Sequence latchSeq;
    EXPECT_CALL(latch, off()).InSequence(latchSeq);
    EXPECT_CALL(latch, on()).InSequence(latchSeq);
    EXPECT_CALL(latch, off()).InSequence(latchSeq);

    Sequence clockSeq;
    EXPECT_CALL(clock, on()).Times(32);
    EXPECT_CALL(clock, off()).Times(32);

    actuators->set(testvalue);
}