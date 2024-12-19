#include "app.h"

const uint8_t ledCode[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
 //LED9 0x0E LED10 0x0D LED11 0x0B LED12 0x07
const uint8_t scanCode[4] = {0x0E, 0x0D, 0x0B, 0x07};
      uint8_t valueLed[4] = {0x00, 0x00, 0x00, 0x00};
      
void Init_Timer2(void)
{
    TIM2_PSCR = 4; // chon clock timer 2 = 1Mhz (ftimer = fmater\2 mu PSCR)
    TIM2_ARRH = (uint8_t)((1000>>8) & 0XFF);
    TIM2_ARRL = (uint8_t)(1000 & 0XFF);
    TIM2_CR1_ARPE      = 1;
    TIM2_IER_UIE       = 1;
    TIM2_CR1_CEN       = 1;
}
void HC595_Init(void)
{
    Sspi_Init();
}

void HC595_sendData(uint8_t data)
{
  Sspi_Transmit(data);
  HC595_LATCH = HIGH;
  HC595_LATCH = LOW;
}
void appInit(void)
{
    __disable_interrupt();
    Init_CpuClock();
    Init_Port();
    Init_Timer2();
    I2c_Soft_Init();
    HC595_Init();
    __enable_interrupt();
}

#pragma vector = TIM2_OVR_UIF_vector
__interrupt void TIM2_OVR_UIF_handler(void)
{
    static uint16_t CountTime = 0;
    HC595_sendData(scanCode[CountTime]);

    set_led7Seg(valueLed, CountTime);
    if(++CountTime >= 4)
    {
        CountTime = 0;
    }
    TIM2_SR1_UIF   = 0;
}


//app show time
void led7_showTimeDate()
{
    uint8_t ledDot = 0;
    uint8_t countEffect = 0;
    uint8_t countDot = 0;
    uint8_t gio = 0, phut = 0, giay = 0;
    uint8_t thu = 0, ngay = 0, thang = 0, nam = 0;
    while(1)
    {
        if(++ countDot == 10)
        {
            countDot = 0;
            ledDot |= 0x02;
        }
        if(++ countEffect == 100)
        {
            countEffect = 0;
            
        }
        if(countEffect < 30)
        {
            ledDot &= ~0x02;
            Led7Seg_showNumber(ngay*100 + thang, ledCode , valueLed, ledDot);
        }
        else
        {
            if(countDot == 5)
            {
                ledDot &= ~0x02;
            }
            Led7Seg_showNumber(gio*100 + phut, ledCode , valueLed, ledDot); 
        }
        DS3231_readTime(&gio, &phut, &giay);
        DS3231_readDate(&thu, &ngay, &thang, &nam);
        delay_ms(100);
    }
  
}

void AppMain(void)
{
    //DS3231_writeTime(16,13,50);
    while(1)
    {
        led7_showTimeDate();
    }
}