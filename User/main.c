#include "stm32f10x.h"
#include "Device_Conf.H"
#include "HOME.H"
#include "led.h"


//void APB_ON(void)
//{
//	APB1_Cmd ( SPI_LCD12864_CLK, ENABLE );
//	APB2_Cmd ( SPI12864_CS_CLK, ENABLE );
////	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断统一选用中断控制组2
//}

int main(void)
{	
	LED_Init();		//LED端口及时钟初始化 
	while(1)
	{
		led_display(); //led显示			
	}	
	/*// 程序来到main函数之前，启动文件：statup_stm32f10x_hd.s已经调用
	// SystemInit()函数把系统时钟初始化成72MHZ
	// SystemInit()在system_stm32f10x.c中定义
	// 如果用户想修改系统时钟，可自行编写程序修改
//	APB_ON();

	WORKLED_Init();
	init12864();
	Initdelay ();
	USART1_Init();
	EC11_Init();
//	post();
	while( 1 )
	{
//		USART_String(USART1,"仙童科技\n");
//		delayms (250);
//		WORKLED();
//		post();
  	Home_12864 ();
	}*/
}

	


