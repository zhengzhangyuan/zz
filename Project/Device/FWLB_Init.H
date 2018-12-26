#ifndef  __FWLB_Init_H_
#define  __FWLB_Init_H_

#include "stm32f10x.h"

#define   USART1_CLK						RCC_APB2Periph_USART1
#define		USART1_CLK_CMD				RCC_APB2PeriphClockCmd
#define		USART1_BAUDRATE				115200

#define		USART1_GPIO_Port				GPIOA
#define		USART1_TX_Pin						GPIO_Pin_9
#define		USART1_RX_Pin						GPIO_Pin_10

void USART1_Init(void);
void USART_String(USART_TypeDef* USARTx, char *);

#endif


