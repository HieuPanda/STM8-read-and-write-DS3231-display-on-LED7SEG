#include "i2c_soft_cfg.h"

void I2c_SDA_Setup( uint8_t OutEnable)
{
    /*chon che do output mode va Chon che do Push pull*/
    MY_PB_DDR_DDR5 = OutEnable;
    MY_PB_CR1_C15 = 1;
}

void I2c_SCL_Setup( uint8_t OutEnable)
{
    MY_PB_DDR_DDR4 = OutEnable;
    MY_PB_CR1_C14 = 1;
}