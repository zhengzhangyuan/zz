#include "WORKLED.H"

void WORKLED_Init(void)//工作指示灯初始化
{
	GPIO_InitTypeDef  LED_GPIO;
	
	APB2_Cmd(WORKLED_CLK,ENABLE);
	
	LED_GPIO.GPIO_Pin = WORKLED_PIN;
	LED_GPIO.GPIO_Mode = GPIO_Mode_Out_PP;
	LED_GPIO.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(WORKLED_PORT,&LED_GPIO);
}
void WORKLED(void)    //工作指示灯反转
{
	if(GPIO_ReadOutputDataBit(WORKLED_PORT,WORKLED_PIN))
		GPIO_ResetBits(WORKLED_PORT,WORKLED_PIN);
	else
		GPIO_SetBits(WORKLED_PORT,WORKLED_PIN);
}

