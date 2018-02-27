# Source files for BrewTroller
set(SOURCE_FILES
        FermTroller.cpp
        AVRGPIOPin.cpp)

execute_process(COMMAND git describe --tags --abbrev=0
                OUTPUT_VARIABLE VER_STR
                OUTPUT_STRIP_TRAILING_WHITESPACE)
message(STATUS "Building FermTroller version: " ${VER_STR})

###################
# Build Setup
###################
include_directories(../include)
add_avr_executable(FermTroller-${board} ${SOURCE_FILES})

