#ifndef __WORKLED_H_
#define __WORKLED_H_

#include "stm32f10x.h"

#define      APB2_Cmd                                      RCC_APB2PeriphClockCmd
#define      WORKLED_CLK                               RCC_APB2Periph_GPIOC  
#define      WORKLED_PORT                              GPIOC
#define      WORKLED_PIN                               GPIO_Pin_13


void WORKLED_Init(void);//工作指示灯初始化
void WORKLED(void);     //工作指示灯反转

#endif

