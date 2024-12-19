#ifndef GPIO_H
#define GPIO_H

typedef unsigned char   uint8_t;
typedef   signed char   int8_t;

typedef struct
{
    union
    {
        struct
        {
           uint8_t ODR0 : 1;
           uint8_t ODR1 : 1;
           uint8_t ODR2 : 1;
           uint8_t ODR3 : 1;
           uint8_t ODR4 : 1;
           uint8_t ODR5 : 1;
           uint8_t ODR6 : 1;
           uint8_t ODR7 : 1;     
        }BIT_ODR;
        uint8_t REG_ODR;
    }ODR;
    union
    {
        struct
        {
           uint8_t IDR0 : 1;
           uint8_t IDR1 : 1;
           uint8_t IDR2 : 1;
           uint8_t IDR3 : 1;
           uint8_t IDR4 : 1;
           uint8_t IDR5 : 1;
           uint8_t IDR6 : 1;
           uint8_t IDR7 : 1;     
        }BIT_IDR;
        uint8_t REG_IDR;
    }IDR;
    union
    {
        struct
        {
           uint8_t DDR0 : 1;
           uint8_t DDR1 : 1;
           uint8_t DDR2 : 1;
           uint8_t DDR3 : 1;
           uint8_t DDR4 : 1;
           uint8_t DDR5 : 1;
           uint8_t DDR6 : 1;
           uint8_t DDR7 : 1;     
        }BIT_DDR;
        uint8_t REG_DDR;
    }DDR;     
    union
    {
        struct
        {
            uint8_t C10 : 1;
            uint8_t C11 : 1;
            uint8_t C12 : 1;
            uint8_t C13 : 1;
            uint8_t C14 : 1;
            uint8_t C15 : 1;
            uint8_t C16 : 1;
            uint8_t C17 : 1;     
         }BIT_CR1;
        uint8_t REG_CR1;    
    }CR1;
    union
    {
        struct
        {
            uint8_t C20 : 1;
            uint8_t C21 : 1;
            uint8_t C22 : 1;
            uint8_t C23 : 1;
            uint8_t C24 : 1;
            uint8_t C25 : 1;
            uint8_t C26 : 1;
            uint8_t C27 : 1;     
         }BIT_CR2;
        uint8_t REG_CR2;    
    }CR2;
} GPIO_Typdef;

__root __no_init GPIO_Typdef GPIOB @ 0x005005;
__root __no_init GPIO_Typdef GPIOC @ 0x00500A;
__root __no_init GPIO_Typdef GPIOD @ 0x00500F;
__root __no_init GPIO_Typdef GPIOE @ 0x005014;

//GPIOB.
//PortA 0x00 5000 , portB 0x00 5005 , portC 0x00 500A,  portD 0x00 500F. 

#define MY_PB_ODR   GPIOB.ODR.REG_ODR
#define MY_PC_ODR   GPIOC.ODR.REG_ODR
#define MY_PD_ODR   GPIOD.ODR.REG_ODR

#define MY_PB_ODR_ODR0              GPIOB.ODR.BIT_ODR.ODR0
#define MY_PB_ODR_ODR1              GPIOB.ODR.BIT_ODR.ODR1
#define MY_PB_ODR_ODR2              GPIOB.ODR.BIT_ODR.ODR2
#define MY_PB_ODR_ODR3              GPIOB.ODR.BIT_ODR.ODR3
#define MY_PB_ODR_ODR4              GPIOB.ODR.BIT_ODR.ODR4
#define MY_PB_ODR_ODR5              GPIOB.ODR.BIT_ODR.ODR5
#define MY_PB_ODR_ODR6              GPIOB.ODR.BIT_ODR.ODR6
#define MY_PB_ODR_ODR7              GPIOB.ODR.BIT_ODR.ODR7

#define MY_PB_DDR_DDR0              GPIOB.DDR.BIT_DDR.DDR0
#define MY_PB_DDR_DDR1              GPIOB.DDR.BIT_DDR.DDR1
#define MY_PB_DDR_DDR2              GPIOB.DDR.BIT_DDR.DDR2
#define MY_PB_DDR_DDR3              GPIOB.DDR.BIT_DDR.DDR3
#define MY_PB_DDR_DDR4              GPIOB.DDR.BIT_DDR.DDR4
#define MY_PB_DDR_DDR5              GPIOB.DDR.BIT_DDR.DDR5
#define MY_PB_DDR_DDR6              GPIOB.DDR.BIT_DDR.DDR6
#define MY_PB_DDR_DDR7              GPIOB.DDR.BIT_DDR.DDR7

#define MY_PB_IDR_IDR0              GPIOB.IDR.BIT_IDR.IDR0
#define MY_PB_IDR_IDR1              GPIOB.IDR.BIT_IDR.IDR1
#define MY_PB_IDR_IDR2              GPIOB.IDR.BIT_IDR.IDR2
#define MY_PB_IDR_IDR3              GPIOB.IDR.BIT_IDR.IDR3
#define MY_PB_IDR_IDR4              GPIOB.IDR.BIT_IDR.IDR4
#define MY_PB_IDR_IDR5              GPIOB.IDR.BIT_IDR.IDR5
#define MY_PB_IDR_IDR6              GPIOB.IDR.BIT_IDR.IDR6
#define MY_PB_IDR_IDR7              GPIOB.IDR.BIT_IDR.IDR7

#define MY_PB_CR1_C10              GPIOB.CR1.BIT_CR1.C10
#define MY_PB_CR1_C11              GPIOB.CR1.BIT_CR1.C11
#define MY_PB_CR1_C12              GPIOB.CR1.BIT_CR1.C12
#define MY_PB_CR1_C13              GPIOB.CR1.BIT_CR1.C13
#define MY_PB_CR1_C14              GPIOB.CR1.BIT_CR1.C14
#define MY_PB_CR1_C15              GPIOB.CR1.BIT_CR1.C15
#define MY_PB_CR1_C16              GPIOB.CR1.BIT_CR1.C16
#define MY_PB_CR1_C17              GPIOB.CR1.BIT_CR1.C17

#define MY_PB_CR2_C20              GPIOB.CR2.BIT_CR2.C20
#define MY_PB_CR2_C21              GPIOB.CR2.BIT_CR2.C21
#define MY_PB_CR2_C22              GPIOB.CR2.BIT_CR2.C22
#define MY_PB_CR2_C23              GPIOB.CR2.BIT_CR2.C23
#define MY_PB_CR2_C24              GPIOB.CR2.BIT_CR2.C24
#define MY_PB_CR2_C25              GPIOB.CR2.BIT_CR2.C25
#define MY_PB_CR2_C26              GPIOB.CR2.BIT_CR2.C26
#define MY_PB_CR2_C27              GPIOB.CR2.BIT_CR2.C27


//PORT C
#define MY_PC_ODR_ODR0              GPIOC.ODR.BIT_ODR.ODR0
#define MY_PC_ODR_ODR1              GPIOC.ODR.BIT_ODR.ODR1
#define MY_PC_ODR_ODR2              GPIOC.ODR.BIT_ODR.ODR2
#define MY_PC_ODR_ODR3              GPIOC.ODR.BIT_ODR.ODR3
#define MY_PC_ODR_ODR4              GPIOC.ODR.BIT_ODR.ODR4
#define MY_PC_ODR_ODR5              GPIOC.ODR.BIT_ODR.ODR5
#define MY_PC_ODR_ODR6              GPIOC.ODR.BIT_ODR.ODR6
#define MY_PC_ODR_ODR7              GPIOC.ODR.BIT_ODR.ODR7

#define MY_PC_DDR_DDR0              GPIOC.DDR.BIT_DDR.DDR0
#define MY_PC_DDR_DDR1              GPIOC.DDR.BIT_DDR.DDR1
#define MY_PC_DDR_DDR2              GPIOC.DDR.BIT_DDR.DDR2
#define MY_PC_DDR_DDR3              GPIOC.DDR.BIT_DDR.DDR3
#define MY_PC_DDR_DDR4              GPIOC.DDR.BIT_DDR.DDR4
#define MY_PC_DDR_DDR5              GPIOC.DDR.BIT_DDR.DDR5
#define MY_PC_DDR_DDR6              GPIOC.DDR.BIT_DDR.DDR6
#define MY_PC_DDR_DDR7              GPIOC.DDR.BIT_DDR.DDR7

#define MY_PC_IDR_IDR0              GPIOC.IDR.BIT_IDR.IDR0
#define MY_PC_IDR_IDR1              GPIOC.IDR.BIT_IDR.IDR1
#define MY_PC_IDR_IDR2              GPIOC.IDR.BIT_IDR.IDR2
#define MY_PC_IDR_IDR3              GPIOC.IDR.BIT_IDR.IDR3
#define MY_PC_IDR_IDR4              GPIOC.IDR.BIT_IDR.IDR4
#define MY_PC_IDR_IDR5              GPIOC.IDR.BIT_IDR.IDR5
#define MY_PC_IDR_IDR6              GPIOC.IDR.BIT_IDR.IDR6
#define MY_PC_IDR_IDR7              GPIOC.IDR.BIT_IDR.IDR7

#define MY_PC_CR1_C10              GPIOC.CR1.BIT_CR1.C10
#define MY_PC_CR1_C11              GPIOC.CR1.BIT_CR1.C11
#define MY_PC_CR1_C12              GPIOC.CR1.BIT_CR1.C12
#define MY_PC_CR1_C13              GPIOC.CR1.BIT_CR1.C13
#define MY_PC_CR1_C14              GPIOC.CR1.BIT_CR1.C14
#define MY_PC_CR1_C15              GPIOC.CR1.BIT_CR1.C15
#define MY_PC_CR1_C16              GPIOC.CR1.BIT_CR1.C16
#define MY_PC_CR1_C17              GPIOC.CR1.BIT_CR1.C17

#define MY_PC_CR2_C20              GPIOC.CR2.BIT_CR2.C20
#define MY_PC_CR2_C21              GPIOC.CR2.BIT_CR2.C21
#define MY_PC_CR2_C22              GPIOC.CR2.BIT_CR2.C22
#define MY_PC_CR2_C23              GPIOC.CR2.BIT_CR2.C23
#define MY_PC_CR2_C24              GPIOC.CR2.BIT_CR2.C24
#define MY_PC_CR2_C25              GPIOC.CR2.BIT_CR2.C25
#define MY_PC_CR2_C26              GPIOC.CR2.BIT_CR2.C26
#define MY_PC_CR2_C27              GPIOC.CR2.BIT_CR2.C27

//PORT D
#define MY_MY_PD_ODR_ODR0              GPIOD.ODR.BIT_ODR.ODR0
#define MY_MY_PD_ODR_ODR1              GPIOD.ODR.BIT_ODR.ODR1
#define MY_MY_PD_ODR_ODR2              GPIOD.ODR.BIT_ODR.ODR2
#define MY_MY_PD_ODR_ODR3              GPIOD.ODR.BIT_ODR.ODR3
#define MY_MY_PD_ODR_ODR4              GPIOD.ODR.BIT_ODR.ODR4
#define MY_MY_PD_ODR_ODR5              GPIOD.ODR.BIT_ODR.ODR5
#define MY_MY_PD_ODR_ODR6              GPIOD.ODR.BIT_ODR.ODR6
#define MY_MY_PD_ODR_ODR7              GPIOD.ODR.BIT_ODR.ODR7

#define MY_MY_PD_DDR_DDR0              GPIOD.DDR.BIT_DDR.DDR0
#define MY_MY_PD_DDR_DDR1              GPIOD.DDR.BIT_DDR.DDR1
#define MY_MY_PD_DDR_DDR2              GPIOD.DDR.BIT_DDR.DDR2
#define MY_MY_PD_DDR_DDR3              GPIOD.DDR.BIT_DDR.DDR3
#define MY_MY_PD_DDR_DDR4              GPIOD.DDR.BIT_DDR.DDR4
#define MY_MY_PD_DDR_DDR5              GPIOD.DDR.BIT_DDR.DDR5
#define MY_MY_PD_DDR_DDR6              GPIOD.DDR.BIT_DDR.DDR6
#define MY_MY_PD_DDR_DDR7              GPIOD.DDR.BIT_DDR.DDR7

#define MY_MY_PD_IDR_IDR0              GPIOD.IDR.BIT_IDR.IDR0
#define MY_MY_PD_IDR_IDR1              GPIOD.IDR.BIT_IDR.IDR1
#define MY_MY_PD_IDR_IDR2              GPIOD.IDR.BIT_IDR.IDR2
#define MY_MY_PD_IDR_IDR3              GPIOD.IDR.BIT_IDR.IDR3
#define MY_MY_PD_IDR_IDR4              GPIOD.IDR.BIT_IDR.IDR4
#define MY_MY_PD_IDR_IDR5              GPIOD.IDR.BIT_IDR.IDR5
#define MY_MY_PD_IDR_IDR6              GPIOD.IDR.BIT_IDR.IDR6
#define MY_MY_PD_IDR_IDR7              GPIOD.IDR.BIT_IDR.IDR7

#define MY_MY_PD_CR1_C10              GPIOD.CR1.BIT_CR1.C10
#define MY_MY_PD_CR1_C11              GPIOD.CR1.BIT_CR1.C11
#define MY_MY_PD_CR1_C12              GPIOD.CR1.BIT_CR1.C12
#define MY_MY_PD_CR1_C13              GPIOD.CR1.BIT_CR1.C13
#define MY_MY_PD_CR1_C14              GPIOD.CR1.BIT_CR1.C14
#define MY_MY_PD_CR1_C15              GPIOD.CR1.BIT_CR1.C15
#define MY_MY_PD_CR1_C16              GPIOD.CR1.BIT_CR1.C16
#define MY_MY_PD_CR1_C17              GPIOD.CR1.BIT_CR1.C17

#define MY_MY_PD_CR2_C20              GPIOD.CR2.BIT_CR2.C20
#define MY_MY_PD_CR2_C21              GPIOD.CR2.BIT_CR2.C21
#define MY_MY_PD_CR2_C22              GPIOD.CR2.BIT_CR2.C22
#define MY_MY_PD_CR2_C23              GPIOD.CR2.BIT_CR2.C23
#define MY_MY_PD_CR2_C24              GPIOD.CR2.BIT_CR2.C24
#define MY_MY_PD_CR2_C25              GPIOD.CR2.BIT_CR2.C25
#define MY_MY_PD_CR2_C26              GPIOD.CR2.BIT_CR2.C26
#define MY_MY_PD_CR2_C27              GPIOD.CR2.BIT_CR2.C27

//PORT E
#define MY_PE_ODR_ODR0              GPIOE.ODR.BIT_ODR.ODR0
#define MY_PE_ODR_ODR1              GPIOE.ODR.BIT_ODR.ODR1
#define MY_PE_ODR_ODR2              GPIOE.ODR.BIT_ODR.ODR2
#define MY_PE_ODR_ODR3              GPIOE.ODR.BIT_ODR.ODR3
#define MY_PE_ODR_ODR4              GPIOE.ODR.BIT_ODR.ODR4
#define MY_PE_ODR_ODR5              GPIOE.ODR.BIT_ODR.ODR5
#define MY_PE_ODR_ODR6              GPIOE.ODR.BIT_ODR.ODR6
#define MY_PE_ODR_ODR7              GPIOE.ODR.BIT_ODR.ODR7

#define MY_PE_DDR_DDR0              GPIOE.DDR.BIT_DDR.DDR0
#define MY_PE_DDR_DDR1              GPIOE.DDR.BIT_DDR.DDR1
#define MY_PE_DDR_DDR2              GPIOE.DDR.BIT_DDR.DDR2
#define MY_PE_DDR_DDR3              GPIOE.DDR.BIT_DDR.DDR3
#define MY_PE_DDR_DDR4              GPIOE.DDR.BIT_DDR.DDR4
#define MY_PE_DDR_DDR5              GPIOE.DDR.BIT_DDR.DDR5
#define MY_PE_DDR_DDR6              GPIOE.DDR.BIT_DDR.DDR6
#define MY_PE_DDR_DDR7              GPIOE.DDR.BIT_DDR.DDR7

#define MY_PE_IDR_IDR0              GPIOE.IDR.BIT_IDR.IDR0
#define MY_PE_IDR_IDR1              GPIOE.IDR.BIT_IDR.IDR1
#define MY_PE_IDR_IDR2              GPIOE.IDR.BIT_IDR.IDR2
#define MY_PE_IDR_IDR3              GPIOE.IDR.BIT_IDR.IDR3
#define MY_PE_IDR_IDR4              GPIOE.IDR.BIT_IDR.IDR4
#define MY_PE_IDR_IDR5              GPIOE.IDR.BIT_IDR.IDR5
#define MY_PE_IDR_IDR6              GPIOE.IDR.BIT_IDR.IDR6
#define MY_PE_IDR_IDR7              GPIOE.IDR.BIT_IDR.IDR7

#define MY_PE_CR1_C10              GPIOE.CR1.BIT_CR1.C10
#define MY_PE_CR1_C11              GPIOE.CR1.BIT_CR1.C11
#define MY_PE_CR1_C12              GPIOE.CR1.BIT_CR1.C12
#define MY_PE_CR1_C13              GPIOE.CR1.BIT_CR1.C13
#define MY_PE_CR1_C14              GPIOE.CR1.BIT_CR1.C14
#define MY_PE_CR1_C15              GPIOE.CR1.BIT_CR1.C15
#define MY_PE_CR1_C16              GPIOE.CR1.BIT_CR1.C16
#define MY_PE_CR1_C17              GPIOE.CR1.BIT_CR1.C17

#define MY_PE_CR2_C20              GPIOE.CR2.BIT_CR2.C20
#define MY_PE_CR2_C21              GPIOE.CR2.BIT_CR2.C21
#define MY_PE_CR2_C22              GPIOE.CR2.BIT_CR2.C22
#define MY_PE_CR2_C23              GPIOE.CR2.BIT_CR2.C23
#define MY_PE_CR2_C24              GPIOE.CR2.BIT_CR2.C24
#define MY_PE_CR2_C25              GPIOE.CR2.BIT_CR2.C25
#define MY_PE_CR2_C26              GPIOE.CR2.BIT_CR2.C26
#define MY_PE_CR2_C27              GPIOE.CR2.BIT_CR2.C27

void Init_Port(void);

#endif // GPIO_H