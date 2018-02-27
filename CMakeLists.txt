#  BrewTroller 2.x CMake File
#  Using contributions from cmake-avr from Matthias Kleemann
#  github.com/mkleemann/cmake-avr
#

cmake_minimum_required(VERSION 2.8)

# Set Processor Vars
set(AVR_MCU atmega1284p CACHE STRING "Hardware targets, available options:
          atmega1284p
          atmega644p")
set(MCU_SPEED "16000000UL")

# Toolchain file needs to be included before any compiler flags on some systems
include(avr_toolchain.cmake)

# Older versions of CMake (< 3) require the toolchain file to be included before the project definition
project(FermTroller)

# Set Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -flto -mcall-prologues -fno-split-wide-types -fshort-enums -Wall -Wextra -funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -Os")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -mcall-prologues -fno-split-wide-types -fshort-enums -Wall -Wextra -Wno-switch -Wno-return-type -Wno-maybe-uninitialized -Wno-sequence-point -funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -std=c++14 -fno-exceptions -Os")

add_definitions("-DF_CPU=${MCU_SPEED}")

add_subdirectory(tests EXCLUDE_FROM_ALL)
add_subdirectory(src)