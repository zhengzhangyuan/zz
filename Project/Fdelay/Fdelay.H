#ifndef  __Fdelay_H_
#define  __Fdelay_H_
#include "stm32f10x.h"
//#include "Device_Conf.H"

void delayus(uint32_t );
void delayms(uint32_t );
void Initdelay (void);//延时调整函数
void AdjDelay(void);  //延时自动调整函数


#endif

