//#include <stdbool.h>
#include "EC11.H"

uint16_t   HKEY;
uint8_t       FLAG;

static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
	  /* Configure one bit for preemption priority */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* Configure one bit for preemption priority */
  /* 配置中断源 */
  NVIC_InitStructure.NVIC_IRQChannel = EC11T_IRQ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
//	NVIC_InitStructure.NVIC_IRQChannel = EC11R_IRQ;
//  NVIC_Init(&NVIC_InitStructure);	
//	
//	NVIC_InitStructure.NVIC_IRQChannel = EC11L_IRQ;
//  NVIC_Init(&NVIC_InitStructure);
}

void  EC11_Init()
{
	GPIO_InitTypeDef			EC11_Config;
	EXTI_InitTypeDef      EXTI_Config;
	
	FLAG = 0,HKEY = 0;
	
		/* config the extiline clock and AFIO clock */
	RCC_APB2PeriphClockCmd(EC11_CLK,ENABLE);
	
		NVIC_Configuration();//中断设置
	
		/* EXTI line gpio config*/	
  EC11_Config.GPIO_Pin = EC11T_Pin;       
  EC11_Config.GPIO_Mode = GPIO_Mode_IPU;	 // 上拉输入
  GPIO_Init(EC11_Port, &EC11_Config);
	
		/* EXTI line mode config */
  GPIO_EXTILineConfig(EC11T_PORTSOURCE,EC11T_PINSOURCE); 
  EXTI_Config.EXTI_Line = EC11T_LINE;
  EXTI_Config.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_Config.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断
  EXTI_Config.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_Config); 
	
			/* EXTI line gpio config*/	
  EC11_Config.GPIO_Pin = EC11R_Pin;       
  GPIO_Init(EC11_Port, &EC11_Config);
	
		/* EXTI line mode config */
  GPIO_EXTILineConfig(EC11R_PORTSOURCE,EC11R_PINSOURCE); 
  EXTI_Config.EXTI_Line = EC11R_LINE;
  EXTI_Init(&EXTI_Config); 
	
				/* EXTI line gpio config*/	
  EC11_Config.GPIO_Pin = EC11L_Pin;       
  GPIO_Init(EC11_Port, &EC11_Config);
	
		/* EXTI line mode config */
  GPIO_EXTILineConfig(EC11L_PORTSOURCE,EC11L_PINSOURCE); 
  EXTI_Config.EXTI_Line = EC11L_LINE;
  EXTI_Init(&EXTI_Config); 
	
}

void EC11L_SAY()
{
	if(FLAG)
	{
		FLAG = 0;
		HKEY = 1;
	}
	else
	{
		FLAG = 1;
	}
}

void EC11R_SAY()
{
	if(FLAG)
	{
		FLAG = 0;
		HKEY = 2;
	}
	else
	{
		FLAG = 1;
	}
}

void EC11T_SAY()
{
	HKEY = 6;
}

