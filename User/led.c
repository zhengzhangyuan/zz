#include "stm32f10x.h"
#include "led.h"
#include "Device_Conf.H"
#include "HOME.H"
#define LED GPIO_Pin_All	//�ܽź궨��

void delay(u32 i)	  
{
	while(i--);
}

	/*******************************************************************************
* �� �� ��         : led_display
* ��������		   : LED��ʾ����  LED��˸
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void led_display()
{
	GPIO_SetBits(GPIOC,LED);
	delay(6000000);//��ʱԼΪ1s
	GPIO_ResetBits(GPIOC,LED);
	delay(6000000);
}
	/*******************************************************************************
* ������        	 : LED_Init
* ��������	   		 : LED��ʼ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void LED_Init()	  //LED��ʼ������
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO

	SystemInit();	//ʱ�ӳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//��ʱ�Ӷ˿�

	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=LED;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
}
/*int main ()
{
	LED_Init();		//LED�˿ڼ�ʱ�ӳ�ʼ�� 
	while(1)
	{
		led_display(); //led��ʾ			
	}	
}*/
	
	
