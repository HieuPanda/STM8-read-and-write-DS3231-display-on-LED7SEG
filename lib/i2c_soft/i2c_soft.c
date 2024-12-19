#include "i2c_soft.h"

void I2c_Soft_Init(void)
{
    I2c_SDA_Setup(1);
    I2c_SCL_Setup(1);
    I2x_SDA_ON;
    I2x_SCL_ON;
}

void I2c_Soft_Start(void)
{
    I2x_SDA_ON;
    I2x_SCL_ON;
    I2c_Delay(I2C_TIME_DELAY);
    I2x_SDA_OFF;
    I2c_Delay(I2C_TIME_DELAY);
    I2x_SCL_OFF;
    I2c_Delay(I2C_TIME_DELAY);
}

void I2c_Soft_Stop(void)
{
    // truoc khi stop
    I2x_SDA_ON;
    I2x_SCL_OFF;
    I2c_Delay(I2C_TIME_DELAY);
    //Bat dau stop
    I2x_SDA_OFF;
    I2c_Delay(I2C_TIME_DELAY);
    I2x_SCL_ON;
    I2x_SDA_ON;
    I2c_Delay(I2C_TIME_DELAY);
}

void I2c_Soft_WriteByte(uint8_t Byte)
{
    uint16_t CountTime = 0;
    for(uint8_t count = 0; count<8 ; count ++)
    {
        if((Byte & 0x80) == 0x80)
        {
            I2x_SDA_ON;
        }
        else
        {
            I2x_SDA_OFF;
        }
        
        I2x_SCL_ON;
        I2c_Delay(I2C_TIME_DELAY);
        I2x_SCL_OFF;
        Byte <<= 1;
        if(count != 7)
    	  I2c_Delay(I2C_TIME_DELAY);
    }
    I2x_SDA_ON;
    I2c_SDA_Setup(0);
    //doi tin hieu ACK, slave se keo SDA xuong thap
    while(I2x_SDA_READ == 1)
    {
        if(++ CountTime == I2C_COUNT_TIME_OUT)
        {
            CountTime = 0;
            I2c_Soft_Stop();
            return;
        }
        I2c_Delay(I2C_CYCLE_TIME_OUT);
    }
    //Neu ACk da keo SDA xuong thap
    I2x_SDA_ON;
    I2x_SCL_ON;
    I2c_Delay(I2C_TIME_DELAY);
    I2x_SCL_OFF;    
    I2c_SDA_Setup(1);
}

uint8_t I2c_Soft_ReadByte(uint8_t address, uint8_t add_reg)
{
    uint8_t result;
    //gui tin hieu start, sau do gui byte address de ghi du lieu, sau do gui byte add_reg
    I2c_Soft_Start();
    I2c_Soft_WriteByte((address << 1) | 0x00);
    I2c_Soft_WriteByte(add_reg);
    
    //gui tin hieu de doc du lieu
    I2c_Soft_Start();
    I2c_Soft_WriteByte((address << 1) | 0x01);
    
    //keo chan SDA ve mode input de doc du lieu
    I2c_SDA_Setup(0);
    for(uint8_t count=0; count<8; count++)
    {
        result <<= 1;
        I2x_SCL_ON;
        I2c_Delay(I2C_TIME_DELAY/2 + 1);
        result |= I2x_SDA_READ;
        I2c_Delay(I2C_TIME_DELAY/2 + 1);
        I2x_SCL_OFF; 
        I2c_Delay(I2C_TIME_DELAY + 1);
    }
    //Sau khi doc du lieu xong chuyen SDA ve output mode va gui tin hieu stop
    I2c_SDA_Setup(1);
    I2x_SDA_ON;
    I2x_SCL_ON;
    I2c_Delay(I2C_TIME_DELAY);
    I2x_SCL_OFF;
    I2c_Delay(I2C_TIME_DELAY);
    
    I2c_Soft_Stop();
    return result;
}

void I2c_Soft_ReadData(uint8_t address, uint8_t add_reg, uint8_t *data, uint8_t length)
{
    
    I2c_Soft_Start();
    I2c_Soft_WriteByte(address | 0x00);
    I2c_Soft_WriteByte(add_reg);
    
    //gui tin hieu de doc du lieu
    I2c_Soft_Start();
    I2c_Soft_WriteByte(address | 0x01);
    
    for(uint8_t countData = 0; countData < length; countData++)
    {
        for(uint8_t count=0; count<8; count++)
        {
            data[countData] <<= 1;
            I2x_SCL_ON;
            I2c_Delay(I2C_TIME_DELAY/2 + 1);
            data[countData] |= I2x_SDA_READ;
            I2c_Delay(I2C_TIME_DELAY/2 + 1);
            I2x_SCL_OFF; 
            I2c_Delay(I2C_TIME_DELAY/2 + 1);
        }
        //Sau khi doc du lieu xong chuyen SDA ve output mode va gui tin hieu stop
        I2c_SDA_Setup(0);
        if(countData == length -1)
        {
            I2x_SDA_ON;
        }
        else
        {
            I2x_SDA_OFF;
        }
        I2x_SCL_ON;
        I2c_Delay(I2C_TIME_DELAY);
        I2x_SCL_OFF;
        I2c_Delay(I2C_TIME_DELAY);
    }
    I2c_Delay(I2C_TIME_DELAY);    
    I2c_Soft_Stop();
}

