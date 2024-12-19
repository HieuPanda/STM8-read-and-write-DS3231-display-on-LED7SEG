#ifndef SSPI_H
#define SSPI_H

#include "GPIO.h"

//typedef unsigned char  uint8_t;

void Sspi_Init(void);
uint8_t Sspi_Transmit(uint8_t byte);

#endif // SSPI_H