#ifndef EEPROM_h
#define EEPROM_h

void saveAlarmStatus(uint8_t zone);

void PROMreadBytes(int addr, uint8_t bytes[], uint8_t numBytes);

#endif