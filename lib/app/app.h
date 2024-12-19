#include "iostm8s005k6.h"
#include <intrinsics.h>
#include "delay.h"
#include "led7Seg.h"
#include "sspi.h"
#include "ic3231.h"
#include "clock.h"

#define STD_ON 1
#define STD_OFF 0
#define HIGH            1
#define LOW             0

#define LED0 MY_PB_ODR_ODR0
#define LED1 MY_PB_ODR_ODR1
#define LED2 MY_PB_ODR_ODR2
#define LED3 MY_PB_ODR_ODR3
#define LED4 MY_PC_ODR_ODR1
#define LED5 MY_PC_ODR_ODR2
#define LED6 MY_PC_ODR_ODR3
#define LED7 MY_PC_ODR_ODR4

#define HC595_LATCH       MY_PE_ODR_ODR5

      
      
void Init_Timer2(void);
void HC595_Init(void);
void HC595_sendData(uint8_t data);
void led7_showTimeDate();
void appInit(void);
void AppMain(void);