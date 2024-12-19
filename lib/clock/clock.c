#include "clock.h"
// __root  CLOCK_Typedef MY_CLOCK @ 0x0050C0;
void Init_CpuClock(void)
{
    MY_CLK_ICKR_LSIEN     = 1;  //Enable che di low speed internal RC ~ 128khz de nuoi còi và ic thoi gian thuc
    MY_CLK_ECKR_HSEEN     = 0;	// disenable high speed external, clean/set by software
    MY_CLK_CKDIVR_HSIDIV  = 0x00;  //  HSI prescaler, khong chia
    MY_CLK_SWCR_SWEN      = 1;	//	SWEN: swith start/stop, enable clock swith execution chuyen sang thach anh noi
    MY_CLK_SWR            = 0XE1;  //thanh ghi clock marter, chon HSI lam clock source
}