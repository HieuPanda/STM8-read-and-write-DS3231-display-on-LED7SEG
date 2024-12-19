#ifndef LED7SEG_H
#define LED7SEG_H

#include "GPIO.h"

//typedef unsigned char   uint8_t;
//typedef   signed char   int8_t;

typedef unsigned int   uint16_t;
//typedef   signed int    int16_t;


void set_led7Seg(uint8_t *valueLed, uint8_t CountTime);
void Led7Seg_showNumber(uint16_t value, uint8_t const *ledCode,uint8_t *valueLed, uint8_t ledDot);
#endif // LED7SEG_H