#ifndef UTIL_H
#define UTIL_H

void strLPad(char retString[], uint8_t len, char pad);
void vftoa(long val, char retStr[], uint8_t precision, bool decimal);
void truncFloat(char retStr[], uint8_t len);
unsigned long pow10(uint8_t power);

#endif