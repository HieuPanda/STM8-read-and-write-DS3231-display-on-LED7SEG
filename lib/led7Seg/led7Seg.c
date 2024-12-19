#include "led7Seg.h"

void set_led7Seg(uint8_t *valueLed, uint8_t CountTime)
{
      /*
    value = MY_PC_ODR;
    value = (value & 0xE1) |((valueLed[CountTime] >>3) & 0x1E);
    lay 4 bit cao cua value ung voi thanh ghi MY_PC_ODR
*/
    MY_PC_ODR = MY_PC_ODR & 0xE1 | ((valueLed[CountTime] >>3) & 0x1E);
    MY_PB_ODR = MY_PB_ODR & 0xF0 | (valueLed[CountTime] & 0x0F);
}
/*
Hien thi gia tri tung led theo thu tu trai sang phai
*/
void Led7Seg_showNumber(uint16_t value, uint8_t const *ledCode,uint8_t *valueLed , uint8_t ledDot)
{
    uint8_t tram, nghin , chuc , dvi;
    
    nghin = value / 1000;
    tram = (value /100) % 10;
    chuc = (value /10 ) % 10;
    dvi = value % 10;
    valueLed[0] = (ledDot & 0x01) ? (ledCode[nghin]  | 0x80) : ledCode[nghin];
    valueLed[1] = (ledDot & 0x02) ? (ledCode[tram] | 0x80) : ledCode[tram];
    valueLed[2] = (ledDot & 0x04) ? (ledCode[chuc] | 0x80) : ledCode[chuc];
    valueLed[3] = (ledDot & 0x08) ? (ledCode[dvi]  | 0x80) : ledCode[dvi];
}