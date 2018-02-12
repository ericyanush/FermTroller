#ifndef FERMTROLLER_H
#define FERMTROLLER_H

#include <stdint.h>
#include "UI_LCD.h"
#include "Config.h"
#include "HWProfile.h"

#ifdef HEARTBEAT
    extern pin hbPin;
#endif

extern uint8_t tSensor[NUM_ZONES][8];
extern int temp[NUM_ZONES];
extern double setpoint[NUM_ZONES];
extern uint8_t hysteresis[NUM_ZONES];
extern uint8_t alarmThresh[NUM_ZONES];
extern uint8_t coolMinOn[NUM_ZONES];
extern uint8_t coolMinOff[NUM_ZONES];

//Shared buffer
extern char buf[20];

extern uint8_t alarmStatus[NUM_ZONES];
extern unsigned long coolTime[NUM_ZONES];

extern bool logData;

extern const char BT[] PROGMEM;
extern const char BTVER[] PROGMEM;
extern unsigned BUILD;

//Log Strings
extern const char LOGCMD[] PROGMEM;
extern const char LOGDEBUG[] PROGMEM;
extern const char LOGSYS[] PROGMEM;
extern const char LOGCFG[] PROGMEM;
extern const char LOGDATA[] PROGMEM;

#if defined UI_LCD_4BIT

  #ifndef UI_DISPLAY_SETUP
    extern LCD4Bit LCD;
  #else
    extern LCD4Bit LCD;
  #endif

#elif defined UI_LCD_I2C
extern LCDI2C LCD;
#endif

#define NUM_VLVCFGS NUM_ZONES * 2 + 1 //Per zone Heat and Cool + Global Alarm
extern unsigned long vlvConfig[NUM_VLVCFGS];
extern unsigned long actHeats;
extern unsigned long actCools;

#endif