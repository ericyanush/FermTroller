#ifndef COM_H
#define COM_H

#include <stdint.h>

void logASCIIVersion();

#ifdef BTNIC_EMBEDDED
void btnicRX(int numBytes);
#endif

#endif