#include "ic3231.h"

uint8_t BCD2Dec(uint8_t BCD)
{
    uint8_t L,H;
    L = BCD & 0x0F;
    H = (BCD >>4)*10;
    return (L+H);
}

uint8_t Dec2BCD(uint8_t Dec)
{
    uint8_t L,H;
    L = Dec%10;
    H = (Dec/10)<<4;
    return (L+H);
}

void DS3231_writeReg(uint8_t address, uint8_t addrReg, uint8_t Byte)
{
    I2c_Soft_Start();
    I2c_Soft_WriteByte((address <<1) | 0x00);
    I2c_Soft_WriteByte(addrReg);
    I2c_Soft_WriteByte(Byte);
    I2c_Soft_Stop();
}

void DS3231_writeTime(uint8_t gio, uint8_t phut, uint8_t giay)
{
    DS3231_writeReg(DS3231_ADDRESS, 0x00, Dec2BCD(giay));
    DS3231_writeReg(DS3231_ADDRESS, 0x01, Dec2BCD(phut));
    DS3231_writeReg(DS3231_ADDRESS, 0x02, Dec2BCD((gio & 0x3F)));
}

void DS3231_readTime(uint8_t *gio, uint8_t *phut, uint8_t *giay)
{
    *giay = BCD2Dec(I2c_Soft_ReadByte(DS3231_ADDRESS, 0x00) & 0x7F);
    *phut = BCD2Dec(I2c_Soft_ReadByte(DS3231_ADDRESS, 0x01) & 0x7F);
    *gio  = BCD2Dec(I2c_Soft_ReadByte(DS3231_ADDRESS, 0x02) & 0x3F);
}

void DS3231_writeDate(uint8_t thu, uint8_t ngay, uint8_t thang, uint8_t nam)
{
    DS3231_writeReg(DS3231_ADDRESS, 0x03, Dec2BCD(thu));
    DS3231_writeReg(DS3231_ADDRESS, 0x04, Dec2BCD(ngay));
    DS3231_writeReg(DS3231_ADDRESS, 0x05, Dec2BCD(thang));
    DS3231_writeReg(DS3231_ADDRESS, 0x06, Dec2BCD(nam));
}

void DS3231_readDate(uint8_t *thu, uint8_t *ngay, uint8_t *thang, uint8_t *nam)
{
    *thu   = BCD2Dec(I2c_Soft_ReadByte(DS3231_ADDRESS,0x03) & 0x07);
    *ngay  = BCD2Dec(I2c_Soft_ReadByte(DS3231_ADDRESS,0x04) & 0x3F);
    *thang = BCD2Dec(I2c_Soft_ReadByte(DS3231_ADDRESS,0x05) & 0x1F);
    *nam   = BCD2Dec(I2c_Soft_ReadByte(DS3231_ADDRESS,0x06) & 0xFF);
}
