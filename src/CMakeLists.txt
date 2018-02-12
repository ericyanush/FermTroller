# Source files for BrewTroller
set(SOURCE_FILES
        Com.cpp
        Com_BTnic.h
        Com_BTPD.cpp
        Com_S0ASC.cpp
        EEPROM.h
        EEPROM.cpp
        Enum.h
        Events.cpp
        FermCore.cpp
        FermTroller.h
        FermTroller.cpp
        HWProfile.h
        Outputs.cpp
        PVOut.h
        Temp.cpp
        UI.cpp
        UI_LCD.h
        Util.cpp)

execute_process(COMMAND git describe --tags --abbrev=0
                OUTPUT_VARIABLE VER_STR
                OUTPUT_STRIP_TRAILING_WHITESPACE)
message(STATUS "Building FermTroller version: " ${VER_STR})

####################
# User selectable compile time options
####################
set(board  "BT_PHOENIX_HERMS" CACHE STRING "BrewTroller Hardware Board Target, available options:
BT_10_21                 --> 1.0 - 2.1
BT_22_24                 --> 2.2 - 2.4
BT_3X                    --> 3.X
BT_4P                    --> 4.X Pro
OT_BX1_HERMS             --> BX1 HERMS
OT_BX1_HERMSI2CLCD       --> BX1 HERMS + I2CLCD
OT_BX1_RIMSDF            --> BX1 RIMS / Direct Fired
OT_BX1_RIMSDFI2CLCD      --> BX1 RIMS / Direct Fired + I2CLCD
OT_BX1_SINGLEVESSEL      --> BX1 Single Vessel
OT_BX1_STEAMPWM          --> BX1 Steam or PWM Pump
OT_BX1_STEAMPWMI2CLCD    --> BX1 Steam or PWM Pump + I2CLCD
OT_DX1_HERMS             --> DX1 HERMS
OT_DX1_RIMSDF            --> DX1 RIMS / Direct Fired
OT_DX1_SINGLEVESSEL      --> DX1 Single Vessel
OT_DX1_STEAMPWM          --> DX1 Steam or PWM Pump
OT_EX1_HERMS             --> EX1 HERMS
OT_EX1_RIMSDF            --> EX1 RIMS / Direct Fired
OT_EX1_SINGLEVESSEL      --> EX1 Single Vessel
OT_EX1_STEAMPWM          --> EX1 Steam or PWM Pump
BT_PHOENIX_HERMS         --> Phoenix HERMS
BT_PHOENIX_RIMS          --> Phoenix RIMS
BT_PHOENIX_SINGLE_VESSEL --> Phoenix Single Vessel
BT_PHOENIX_STEAM_PWM     --> Phoenix Steam or PWM Pump") # Default to DX1 Herms build
add_definitions("-D${board}")
message(STATUS "Building BrewTroller for   " ${board})

#####
# Basic Options
#####
option(USEMETRIC "Use Metric Units" OFF)

# Generate Configuration header
configure_file(Config.in.h "${PROJECT_BINARY_DIR}/Config.h")
include_directories(${PROJECT_BINARY_DIR})

###################
# Build Setup
###################
add_avr_executable(FermTroller-${board} ${SOURCE_FILES})

# Link libraries
target_link_libraries(FermTroller-${board}.elf FT-libs)
