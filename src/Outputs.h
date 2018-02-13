#ifndef OUTPUTS_H
#define OUTPUTS_H

void pinInit();
void resetOutputs();
void processOutputs();
void updateValves();
unsigned long computeValveBits();

bool isAlarmAllZones();

void updateAlarm();

void setBuzzer(bool alarmON);

#endif