cmake_minimum_required(VERSION 2.8)

set(TEST_TARGET fermtrollerTests)

#build the googlemock/test framework
add_subdirectory(googletest)

#List all test sources
set(FT_TEST_SRCS src/main.cpp src/MuxActuatorsTests.cpp)

#Include the Fermtroller headers
include_directories(../include)

#Include the test dummy headers
include_directories(system dummy_avr)
#List all dummy implementations
set(AVR_DUMMY_SRCS)

#Include any test headers
include_directories(src)

#Include the googletests/mock paths
include_directories(googletest/googletest/include
        googletest/googlemock/include)

add_executable(${TEST_TARGET} ${FT_TEST_SRCS} ${FT_TEST_TARGET_SRCS} ${AVR_DUMMY_SRCS})
target_link_libraries(${TEST_TARGET} gmock gtest)

#Set the language standard
set_property(TARGET ${TEST_TARGET} PROPERTY CXX_STANDARD 14)