#ifndef UI_H
#define UI_H

#include <stdint.h>
#include <menu.h>

void uiInit();
void UIinitEEPROM();
void uiEvent(uint8_t eventID, uint8_t eventParam);

void unlockUI();
void lockUI();

void uiCore();

void screenInit(uint8_t screen);
void screenRefresh(uint8_t screen);
void screenEnter(uint8_t screen);

void screenAbout();

void splashScreen();

void menuAlarmZones();
void menuAlarms(uint8_t zone);

void menuSetup();
void assignSensor();

void displayAssignSensorTemp(int sensor);

void cfgOutputs();

void cfgOutput(uint8_t zone, char sTitle[]);

unsigned long cfgValveProfile (char sTitle[], unsigned long defValue);

#ifdef UI_DISPLAY_SETUP
void adjustLCD();
#endif

uint8_t scrollMenu(char sTitle[], menu *objMenu);

void drawMenu(char sTitle[], menu *objMenu);

uint8_t getChoice(menu *objMenu, uint8_t iRow);

bool confirmChoice(const char *choice, uint8_t row);

bool confirmAbort();

bool confirmDel();

long getValue_P(const char *sTitle, long defValue, uint8_t precision, long minValue, long maxValue, const char *dispUnit);

long getValue(char sTitle[], long defValue, uint8_t precision, long minValue, long maxValue, const char *dispUnit);

int getTimerValue(const char *sTitle, int defMins, uint8_t maxHours);

void getString(const char *sTitle, char defValue[], uint8_t chars);

uint8_t ASCII2enc(uint8_t charin);

uint8_t enc2ASCII(uint8_t charin);

#endif