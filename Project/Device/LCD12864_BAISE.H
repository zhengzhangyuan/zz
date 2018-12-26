#ifndef __LCD12864_BAISE_H_
#define __LCD12864_BAISE_H_
#include "stm32f10x.h"

#define CMD12864 	0XF8
#define DATA12864 	0XFA 

/************************** SPI LCD12864 连接引脚定义********************************/
#define      SPI_12864                                SPI2
#define      APB1_Cmd                                 RCC_APB1PeriphClockCmd
#define      SPI_LCD12864_CLK                         RCC_APB1Periph_SPI2 

#define      APB2_Cmd                                 RCC_APB2PeriphClockCmd
#define      SPI12864_CS_CLK                               RCC_APB2Periph_GPIOB    
#define      SPI12864_CS_PORT                              GPIOB
#define      SPI12864_CS_PIN                               GPIO_Pin_12

#define      APB2_Cmd                                 RCC_APB2PeriphClockCmd
#define      SPI12864_SCK_CLK                              RCC_APB2Periph_GPIOB   
#define      SPI12864_SCK_PORT                             GPIOB  
#define      SPI12864_SCK_PIN                              GPIO_Pin_13

#define      APB2_Cmd                                 RCC_APB2PeriphClockCmd
#define      SPI12864_MISO_CLK                             RCC_APB2Periph_GPIOB    
#define      SPI12864_MISO_PORT                            GPIOB 
#define      SPI12864_MISO_PIN                             GPIO_Pin_14

#define      APB2_Cmd                                 RCC_APB2PeriphClockCmd
#define      SPI12864_MOSI_CLK                             RCC_APB2Periph_GPIOB    
#define      SPI12864_MOSI_PORT                            GPIOB 
#define      SPI12864_MOSI_PIN                             GPIO_Pin_15



/************************** SPI Flash 函数宏定义********************************/
#define      SPI_12864_CS_ENABLE()                       GPIO_SetBits( SPI12864_CS_PORT, SPI12864_CS_PIN )
#define      SPI_12864_CS_DISABLE()                      GPIO_ResetBits( SPI12864_CS_PORT, SPI12864_CS_PIN )

/***************************************
	LCD12864 ,SPI初始化
***************************************/
void Init_SPI12864(void);//  SPI 初始化
void Init_12864 (void);  //12864初始化 
/**************************************
	基础信息发送函数
**************************************/
u8 SPI12864_Sendbyte(u8 SPI12864_Data);//SPI发送函数
void Cmd_12864(u8 cmd);    //12864命令
void Data_12864(u8 data);   //12864数据


#endif

