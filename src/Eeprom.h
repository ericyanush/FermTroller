#ifndef EEPROM_FERMTROLLER_H
#define EEPROM_FERMTROLLER_H

void saveAlarmStatus(uint8_t zone);

void PROMreadBytes(int addr, uint8_t bytes[], uint8_t numBytes);
int PROMreadInt(int address);

#endif