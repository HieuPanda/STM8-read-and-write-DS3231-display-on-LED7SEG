#ifndef I2C_SOFT_H
#define I2C_SOFT_H

#include "i2c_soft_cfg.h"
#include "GPIO.h"

#define I2C_TIME_DELAY      5     // Min is 2us
#define I2C_CYCLE_TIME_OUT  3
#define I2C_COUNT_TIME_OUT  1000

void I2c_Soft_Init(void);
void I2c_Soft_Start(void);
void I2c_Soft_Stop(void);
void I2c_Soft_WriteByte(uint8_t Byte);
uint8_t I2c_Soft_ReadByte(uint8_t address, uint8_t add_reg);
void I2c_Soft_ReadData(uint8_t address, uint8_t add_reg, uint8_t *data, uint8_t length);

#endif // I2C_SOFT_H