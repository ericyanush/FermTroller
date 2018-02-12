#ifndef TEMP_H
#define TEMP_H

void tempInit();
void convertAll();
void updateTemps();
bool tsReady();
bool validAddr(uint8_t * addr);
void getDSAddr(uint8_t addrRet[8]);
int read_temp(uint8_t * addr);
#endif