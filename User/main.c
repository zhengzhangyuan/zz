#include "stm32f10x.h"
#include "Device_Conf.H"
#include "HOME.H"
#include "led.h"


//void APB_ON(void)
//{
//	APB1_Cmd ( SPI_LCD12864_CLK, ENABLE );
//	APB2_Cmd ( SPI12864_CS_CLK, ENABLE );
////	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�ж�ͳһѡ���жϿ�����2
//}

int main(void)
{	
	LED_Init();		//LED�˿ڼ�ʱ�ӳ�ʼ�� 
	while(1)
	{
		led_display(); //led��ʾ			
	}	
	/*// ��������main����֮ǰ�������ļ���statup_stm32f10x_hd.s�Ѿ�����
	// SystemInit()������ϵͳʱ�ӳ�ʼ����72MHZ
	// SystemInit()��system_stm32f10x.c�ж���
	// ����û����޸�ϵͳʱ�ӣ������б�д�����޸�
//	APB_ON();

	WORKLED_Init();
	init12864();
	Initdelay ();
	USART1_Init();
	EC11_Init();
//	post();
	while( 1 )
	{
//		USART_String(USART1,"��ͯ�Ƽ�\n");
//		delayms (250);
//		WORKLED();
//		post();
  	Home_12864 ();
	}*/
}

	


