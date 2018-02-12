#ifndef COM_H
#define COM_H

#include <stdint.h>

void logASCIIVersion();

void printFieldUL (unsigned long uLong);
void printFieldPS (const char *sText);

void updateCom();

#ifdef BTNIC_EMBEDDED
void btnicRX(int numBytes);
#endif

void comEvent(byte eventID, int eventParam);

#endif