#ifndef I2C_SOFT_CFG_H
#define I2C_SOFT_CFG_H

#include "delay.h"
#include "GPIO.h"

//typedef unsigned char   uint8_t;
//typedef   signed char   int8_t;
//
typedef unsigned int   uint16_t;
//typedef   signed int    int16_t;

#define I2c_Delay(us)        delay_us(us)

#define I2x_SDA_ON           MY_PB_ODR_ODR5 = 1
#define I2x_SDA_OFF          MY_PB_ODR_ODR5 = 0
#define I2x_SDA_READ         MY_PB_IDR_IDR5

#define I2x_SCL_ON           MY_PB_ODR_ODR4 = 1
#define I2x_SCL_OFF          MY_PB_ODR_ODR4 = 0

void I2c_SDA_Setup( uint8_t OutEnable);
void I2c_SCL_Setup( uint8_t OutEnable);

#endif // I2C_SOFT_CFG_H