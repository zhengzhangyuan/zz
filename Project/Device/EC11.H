#ifndef __EC11_H_
#define __EC11_H_

#include "stm32f10x.h"

#define  EC11_Port          GPIOA
#define  EC11_CLK           (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)  

#define  EC11L_Pin          GPIO_Pin_0
#define  EC11L_PORTSOURCE   GPIO_PortSourceGPIOA
#define  EC11L_PINSOURCE    GPIO_PinSource0
#define  EC11L_LINE         EXTI_Line0
#define  EC11L_IRQ  			  EXTI0_IRQn
#define  EC11L_IRQHandler   EXTI0_IRQHandler

#define  EC11R_Pin					GPIO_Pin_1
#define  EC11R_PORTSOURCE		GPIO_PortSourceGPIOA
#define  EC11R_PINSOURCE		GPIO_PinSource1
#define  EC11R_LINE					EXTI_Line1
#define  EC11R_IRQ					EXTI1_IRQn
#define  EC11R_IRQHandler   EXTI1_IRQHandler

#define  EC11T_Pin					GPIO_Pin_2
#define  EC11T_PORTSOURCE   GPIO_PortSourceGPIOA
#define  EC11T_PINSOURCE    GPIO_PinSource2
#define  EC11T_LINE					EXTI_Line2
#define  EC11T_IRQ					EXTI2_IRQn
#define  EC11T_IRQHandler   EXTI2_IRQHandler


void  EC11_Init(void);//初始化
void EC11L_SAY(void);//左旋
void EC11R_SAY(void);//右旋
void EC11T_SAY(void);//按下

#endif

