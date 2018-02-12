#ifndef COM_H
#define COM_H

#include <stdint.h>

void logASCIIVersion();

void printFieldUL (unsigned long uLong);
void printFieldPS (const char *sText);

void updateCom();

#ifdef BTNIC_EMBEDDED
void btnicRX(int numBytes);
void updateI2CBTnic();
#endif

#ifdef COM_SERIAL0
    #if COM_SERIAL0 == BTNIC
        void updateS0BTnic();
    #endif
#endif

void comEvent(byte eventID, int eventParam);

#endif