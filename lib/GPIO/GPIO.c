#include "GPIO.h"

void Init_Port(void)
{
    MY_PB_DDR_DDR0        = 1;  //Chon Chan A1 o che do output mode
    MY_PB_CR1_C10         = 1;  //Chon che do Push pull co the keo len 1 hoac xuong 0 cho chan A1
    MY_PB_ODR_ODR0        = 0;  // set chan PA1 = 0, out 0V
    
    //cau hinh led 1
    MY_PB_DDR_DDR1        = 1;  //Chon Chan A1 o che do output mode
    MY_PB_CR1_C11         = 1;  //Chon che do Push pull cho chan A1
    MY_PB_ODR_ODR1        = 0;  // set chan PA1 = 0, out 0V
    
    //cau hinh led 2
    MY_PB_DDR_DDR2        = 1;  //Chon Chan A1 o che do output mode
    MY_PB_CR1_C12         = 1;  //Chon che do Push pull cho chan A1
    MY_PB_ODR_ODR2        = 0;  // set chan PA1 = 0, out 0V

    //cau hinh led 3
    MY_PB_DDR_DDR3        = 1;  //Chon Chan A1 o che do output mode
    MY_PB_CR1_C13         = 1;  //Chon che do Push pull cho chan A1
    MY_PB_ODR_ODR3        = 0;  // set chan PA1 = 0, out 0V    

    //cau hinh led 4
    MY_PC_DDR_DDR1        = 1;  //Chon Chan A1 o che do output mode
    MY_PC_CR1_C11         = 1;  //Chon che do Push pull cho chan A1
    MY_PC_ODR_ODR1        = 0;  // set chan PA1 = 0, out 0V   

    //cau hinh led 5
    MY_PC_DDR_DDR2        = 1;  //Chon Chan A1 o che do output mode
    MY_PC_CR1_C12         = 1;  //Chon che do Push pull cho chan A1
    MY_PC_ODR_ODR2        = 0;  // set chan PA1 = 0, out 0V 
    
    //cau hinh led 6
    MY_PC_DDR_DDR3        = 1;  //Chon Chan A1 o che do output mode
    MY_PC_CR1_C13         = 1;  //Chon che do Push pull cho chan A1
    MY_PC_ODR_ODR3        = 0;  // set chan PA1 = 0, out 0V
    
    //cau hinh led 7
    MY_PC_DDR_DDR4        = 1;  //Chon Chan A1 o che do output mode
    MY_PC_CR1_C14         = 1;  //Chon che do Push pull cho chan A1
    MY_PC_ODR_ODR4        = 0;  // set chan PA1 = 0, out 0V   
}