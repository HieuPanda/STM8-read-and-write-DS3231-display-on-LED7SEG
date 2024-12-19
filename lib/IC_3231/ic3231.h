#ifndef IC3231_H
#define IC3231_H

#include "i2c_soft.h"

#define DS3231_ADDRESS  0x68

void DS3231_writeTime(uint8_t gio, uint8_t phut, uint8_t giay);
void DS3231_readTime(uint8_t *gio, uint8_t *phut, uint8_t *giay);
void DS3231_writeDate(uint8_t thu, uint8_t ngay, uint8_t thang, uint8_t nam);
void DS3231_readDate(uint8_t *thu, uint8_t *ngay, uint8_t *thang, uint8_t *nam);

#endif // IC3231_H