#ifndef EEPROM_FERMTROLLER_H
#define EEPROM_FERMTROLLER_H

void loadVlvConfigs();
void setTSAddr(uint8_t zone, uint8_t addr[8]);
void setHysteresis(uint8_t output, uint8_t value);
void setAlarmThresh(uint8_t output, uint8_t value);
void setAlarmStatus(uint8_t zone, uint8_t value);
void saveAlarmStatus(uint8_t zone);
void setCoolMinOn(uint8_t zone, uint8_t value);
void setCoolMinOff(uint8_t zone, uint8_t value);
void setSetpoint(uint8_t zone, int value);
void setValveCfg(uint8_t profile, unsigned long value);
char* getZoneName(uint8_t zone, char name[]);
void setZoneName(uint8_t zone, char name[]);

void initEEPROM();

long PROMreadLong(int address);
void PROMwriteLong(int address, long value);
int PROMreadInt(int address);
void PROMwriteInt(int address, int value);
void PROMwriteBytes(int addr, uint8_t bytes[], uint8_t numBytes);
void PROMreadBytes(int addr, uint8_t bytes[], uint8_t numBytes);

#endif