#include "FWLB_Init.H"

static void NVIC__UART1_Configuration(void)
{
	NVIC_InitTypeDef		NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void USART1_Init()
{
	GPIO_InitTypeDef		GPIO_InitStruct;
	USART_InitTypeDef		USART1_InitStruct;
	
	RCC_APB2PeriphClockCmd(USART1_CLK,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = USART1_TX_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = USART1_RX_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	USART1_InitStruct.USART_BaudRate = USART1_BAUDRATE;
	USART1_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART1_InitStruct.USART_StopBits = USART_StopBits_1; 
	USART1_InitStruct.USART_Parity = USART_Parity_No;
	USART1_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART1_InitStruct.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
	USART_Init(USART1,&USART1_InitStruct);
	
//	NVIC_Configuration();
//	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	USART_Cmd(USART1,ENABLE);
}

void USART_String(USART_TypeDef* USARTx, char *str)
{
	unsigned int i=0;
	while(str[i])
	{
		USART_SendData(USARTx,str[i]);
		while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)==RESET);
		i++;
	}
}

