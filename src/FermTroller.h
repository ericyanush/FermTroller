#ifndef FERMTROLLER_H
#define FERMTROLLER_H

#include <stdint.h>
#include "UI_LCD.h"
#include "Config.h"
#include "HWProfile.h"

extern uint8_t tSensor[NUM_ZONES][8];
extern uint8_t hysteresis[NUM_ZONES];

extern uint8_t alarmStatus[NUM_ZONES];

extern bool logData;

#if defined UI_LCD_4BIT

  #ifndef UI_DISPLAY_SETUP
    extern LCD4Bit LCD;
  #else
    extern LCD4Bit LCD;
  #endif

#elif defined UI_LCD_I2C
extern LCDI2C LCD;
#endif

#endif