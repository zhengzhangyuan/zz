#include "stm32f10x.h"
#include "led.h"
#include "Device_Conf.H"
#include "HOME.H"
#define LED GPIO_Pin_All	//管脚宏定义

void delay(u32 i)	  
{
	while(i--);
}

	/*******************************************************************************
* 函 数 名         : led_display
* 函数功能		   : LED显示函数  LED闪烁
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void led_display()
{
	GPIO_SetBits(GPIOC,LED);
	delay(6000000);//延时约为1s
	GPIO_ResetBits(GPIOC,LED);
	delay(6000000);
}
	/*******************************************************************************
* 函数名        	 : LED_Init
* 函数功能	   		 : LED初始化函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void LED_Init()	  //LED初始化函数
{
	GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO

	SystemInit();	//时钟初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//打开时钟端口

	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=LED;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* 初始化GPIO */
}
/*int main ()
{
	LED_Init();		//LED端口及时钟初始化 
	while(1)
	{
		led_display(); //led显示			
	}	
}*/
	
	
