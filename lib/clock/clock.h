#ifndef CLOCK_H
#define CLOCK_H

typedef unsigned char   uint8_t;
typedef   signed char   int8_t;

typedef struct 
{
    union
    {
        struct
        {
            uint8_t HSIEN       : 1;
            uint8_t HSIRDY      : 1;
            uint8_t FHWU        : 1;
            uint8_t LSIEN       : 1;
            uint8_t LSIDRY      : 1;
            uint8_t REGAH       : 1;
            uint8_t RESERVED_ICKR_BIT7    : 1;
            uint8_t RESERVED_ICKR_BIT8    : 1;
        }BIT_ICKR;
        uint8_t REG_ICKR;
    }ICKR;

//ECKR    
    union
    {
        struct
        {
            uint8_t HSEEN       : 1;
            uint8_t HSIRDY      : 1;
            uint8_t RESERVED    : 6;
        }BIT_ECKR;
        uint8_t REG_ECKR;
    }ECKR;

    uint8_t RESERVED_AREA0;
   
    union
    {
        struct
        {
            uint8_t CKM0        : 1;
            uint8_t CKM1        : 1;
            uint8_t CKM2        : 1;
            uint8_t CKM3        : 1;
            uint8_t CKM4        : 1;
            uint8_t CKM5        : 1;
            uint8_t CKM6        : 1;
            uint8_t CKM7        : 1;
        }BIT_CMSR;
        uint8_t REG_CMSR;
    }CMSR;
    
    union
    {
        struct
        {
            uint8_t SWI0        : 1;
            uint8_t SWI1        : 1;
            uint8_t SWI2        : 1;
            uint8_t SWI3        : 1;
            uint8_t SWI4        : 1;
            uint8_t SWI5        : 1;
            uint8_t SWI6        : 1;
            uint8_t SWI7        : 1;
        }BIT_SWR;
        uint8_t REG_SWR;
    }SWR;

    union
    {
        struct
        {
            uint8_t SWBSY       : 1;
            uint8_t SWEN        : 1;
            uint8_t SWIEN       : 1;
            uint8_t SWIF        : 1;
            uint8_t RESERVED    : 4;
        }BIT_SWCR;
        uint8_t REG_SWCR;
    }SWCR;
    
//CKDIVR
    union
    {
        struct
        {
            uint8_t CPUDIV      : 3;
            uint8_t HSIDIV      : 2;
            uint8_t RESERVED    : 3;
        }BIT_CKDIVR;
        uint8_t REG_CKDIVR;
    }CKDIVR;

//PCKENR1
    union
    {
        struct
        {
            uint8_t PCKENR10    : 1;
            uint8_t PCKENR11    : 1;
            uint8_t PCKENR12    : 1;
            uint8_t PCKENR13    : 1;
            uint8_t PCKENR14    : 1;
            uint8_t PCKENR15    : 1;
            uint8_t PCKENR16    : 1;
            uint8_t PCKENR17    : 1;
        }BIT_PCKENR1;
        uint8_t REG_PCKENR1;
    }PCKENR1;

//CSSR
    union
    {
        struct
        {
            uint8_t CSSEN       : 1;
            uint8_t AUX         : 1;
            uint8_t CSSIDE      : 1;
            uint8_t CSSD        : 1;
            uint8_t RESERVED    : 4;
        }BIT_CSSR;
        uint8_t REG_CSSR;
    }CSSR;   
    
//CCOR
    union
    {
        struct
        {
            uint8_t CCOEN       : 1;
            uint8_t CCOSEL     : 4;
            uint8_t CCORDY      : 1;
            uint8_t CCOBSY      : 1;
            uint8_t RESERVED    : 1;
        }BIT_CCOR;
        uint8_t REG_CCOR;
    }CCOR;
    
//PCKENR2
    union
    {
        struct
        {
            uint8_t PCKENR20    : 1;
            uint8_t PCKENR21    : 1;
            uint8_t PCKENR22    : 1;
            uint8_t PCKENR23    : 1;
            uint8_t PCKENR24    : 1;
            uint8_t PCKENR25    : 1;
            uint8_t PCKENR26    : 1;
            uint8_t PCKENR27    : 1;
        }BIT_PCKENR2;
        uint8_t REG_PCKENR2;
    }PCKENR2;
    
    uint8_t RESERVED_AREA1;

//HSITRIMR
    union
    {
        struct
        {
            uint8_t HSITRIMR   : 4;
            uint8_t RESERVED    : 4;
        }BIT_HSITRIMR;
        uint8_t REG_HSITRIMR;
    }HSITRIMR;

//SWIMCCR
    union
    {
        struct
        {
            uint8_t SWIMCLK     : 1;
            uint8_t RESERVED    : 7;
        }BIT_SWIMCCR;
        uint8_t REG_SWIMCCR;
    }SWIMCCR;
}CLOCK_Typedef;

//ADDESS START 0x00 50C0
__root __no_init CLOCK_Typedef MY_CLOCK @ 0x0050C0;

#define MY_CLK_ICKR_LSIEN          MY_CLOCK.ICKR.BIT_ICKR.LSIEN
#define MY_CLK_ECKR_HSEEN          MY_CLOCK.ECKR.BIT_ECKR.HSEEN
#define MY_CLK_CKDIVR_HSIDIV       MY_CLOCK.CKDIVR.BIT_CKDIVR.HSIDIV
#define MY_CLK_SWCR_SWEN           MY_CLOCK.SWCR.BIT_SWCR.SWEN
#define MY_CLK_SWR                 MY_CLOCK.SWR.REG_SWR

void Init_CpuClock(void);

#endif // CLOCK_H