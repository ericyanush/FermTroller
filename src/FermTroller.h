#ifndef FERMTROLLER_H
#define FERMTROLLER_H

#include <stdint.h>
#include "UI_LCD.h"
#include "Config.h"
#include "HWProfile.h"
#include "PVOut.h"

#ifdef USEMETRIC
#define SETPOINT_MULT 50
  #define SETPOINT_DIV 2
#else
#define SETPOINT_MULT 100
#define SETPOINT_DIV 1
#endif

#ifdef HEARTBEAT
    extern pin hbPin;
#endif

void softReset();

extern uint8_t tSensor[NUM_ZONES][8];
extern int temp[NUM_ZONES];
extern double setpoint[NUM_ZONES];
extern uint8_t hysteresis[NUM_ZONES];
extern uint8_t alarmThresh[NUM_ZONES];
extern int zonePwr[NUM_ZONES];
extern uint8_t coolMinOn[NUM_ZONES];
extern uint8_t coolMinOff[NUM_ZONES];

#if defined PVOUT_TYPE_GPIO
#define PVOUT
extern PVOutGPIO Valves;

#elif defined PVOUT_TYPE_MUX
#define PVOUT
  extern PVOutMUX Valves;
#elif defined PVOUT_TYPE_MODBUS
  #define PVOUT
  extern PVOutMODBUS Valves;
#endif

//Shared buffer
extern char buf[20];

extern uint8_t alarmStatus[NUM_ZONES];
extern unsigned long coolTime[NUM_ZONES];

extern bool logData;

extern const char BT[];
extern const char BTVER[];
extern unsigned BUILD;

//Log Strings
extern const char LOGCMD[];
extern const char LOGDEBUG[];
extern const char LOGSYS[];
extern const char LOGCFG[];
extern const char LOGDATA[];

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
extern bool buzzStatus;
extern unsigned long actHeats;
extern unsigned long actCools;

#endif