#include "LCD12864_BAISE.H"
#include "Fdelay.H"


/***************************************
	LCD12864 ,SPI初始化
***************************************/
void Init_SPI12864()//  SPI 初始化
{
  SPI_InitTypeDef  SPI12864_Config;
  GPIO_InitTypeDef GPIO12864_Config;
	
  
  /* Enable SPI1 and GPIO clocks */
  /*!< SPI_FLASH_SPI_CS_GPIO, SPI_FLASH_SPI_MOSI_GPIO, 
       SPI_FLASH_SPI_MISO_GPIO, SPI_FLASH_SPI_DETECT_GPIO 
       and SPI_FLASH_SPI_SCK_GPIO Periph clock enable */
  /*!< SPI_FLASH_SPI Periph clock enable */

  /*!< Configure SPI_FLASH_SPI_CS_PIN pin: SPI_FLASH Card CS pin */
	APB1_Cmd ( SPI_LCD12864_CLK, ENABLE );
	APB2_Cmd ( SPI12864_CS_CLK, ENABLE );

	
//	APB2_Cmd ( SPI12864_CS_CLK, ENABLE );
  GPIO12864_Config.GPIO_Pin = SPI12864_CS_PIN;
	GPIO12864_Config.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO12864_Config.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(SPI12864_CS_PORT, &GPIO12864_Config);
	
  /*!< Configure SPI_FLASH_SPI pins: SCK */
//	APB2_Cmd ( SPI12864_SCK_CLK, ENABLE );
  GPIO12864_Config.GPIO_Pin = SPI12864_SCK_PIN;
  GPIO12864_Config.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(SPI12864_SCK_PORT, &GPIO12864_Config);

  /*!< Configure SPI_FLASH_SPI pins: MISO */
//	APB2_Cmd ( SPI12864_MISO_CLK, ENABLE );
  GPIO12864_Config.GPIO_Pin = SPI12864_MISO_PIN;
  GPIO_Init(SPI12864_MISO_PORT, &GPIO12864_Config);

  /*!< Configure SPI_FLASH_SPI pins: MOSI */
//	APB2_Cmd ( SPI12864_MOSI_CLK, ENABLE );
  GPIO12864_Config.GPIO_Pin = SPI12864_MOSI_PIN;
  GPIO_Init(SPI12864_MOSI_PORT, &GPIO12864_Config);

  /* Deselect the FLASH: Chip Select high */
  SPI_12864_CS_DISABLE();
	


  /* SPI1 configuration */
  // W25X16: data input on the DIO pin is sampled on the rising edge of the CLK. 
  // Data on the DO and DIO pins are clocked out on the falling edge of CLK.
  SPI12864_Config.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI12864_Config.SPI_Mode = SPI_Mode_Master;
  SPI12864_Config.SPI_DataSize = SPI_DataSize_8b;
  SPI12864_Config.SPI_CPOL = SPI_CPOL_High;
  SPI12864_Config.SPI_CPHA = SPI_CPHA_2Edge;
  SPI12864_Config.SPI_NSS = SPI_NSS_Soft;
  SPI12864_Config.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
  SPI12864_Config.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI12864_Config.SPI_CRCPolynomial = 7;//SPI分频数控制，0-7对应（2）1--（2）8
  SPI_Init(SPI_12864 , &SPI12864_Config);

  /* Enable SPI1  */
  SPI_Cmd(SPI_12864 , ENABLE);
}



void Init_12864 () //12864初始化 
{
	Init_SPI12864(); 
	
	// delayms(200);
   delayms(10);
   Cmd_12864(0x30);       //选择基本指令集
   delayus(200);         //延时大于100us
   Cmd_12864(0x03);       //选择8bit数据流
   delayus(20);         //延时大于37us
   Cmd_12864(0x0c);       //开显示(无游标、不反白)
   delayus(50);         //延时大于100us
   Cmd_12864(0x01);       //清除显示，并且设定地址指针为00H
   delayms(15);           //延时大于10ms
   Cmd_12864(0x06);       //指定在资料的读取及写入时，设定游标的移动方向及指定显示的移位，光标从右向左加1位移动
   delayus(50);         //延时大于100us
}

/**************************************
	基础信息发送函数
**************************************/
u8 SPI12864_Sendbyte(u8 SPI12864_Data)//SPI发送函数
{
	  /* Loop while DR register in not emplty */
  while (SPI_I2S_GetFlagStatus(SPI_12864 , SPI_I2S_FLAG_TXE) == RESET);

  /* Send byte through the SPI1 peripheral */
  SPI_I2S_SendData(SPI_12864 , SPI12864_Data);

  /* Wait to receive a byte */
  while (SPI_I2S_GetFlagStatus(SPI_12864 , SPI_I2S_FLAG_RXNE) == RESET);

  /* Return the byte read from the SPI bus */
  return SPI_I2S_ReceiveData(SPI_12864 );
}


void Cmd_12864(u8 cmd)    //12864命令
{
	 SPI_12864_CS_ENABLE();
	SPI12864_Sendbyte(CMD12864);
	SPI12864_Sendbyte(cmd&0XF0);
	SPI12864_Sendbyte(cmd<<4);
	 SPI_12864_CS_DISABLE();
}
void Data_12864(u8 data)   //12864数据
{
	SPI_12864_CS_ENABLE();
	SPI12864_Sendbyte(DATA12864);
	SPI12864_Sendbyte(data&0XF0);
	SPI12864_Sendbyte(data<<4);
    SPI_12864_CS_DISABLE();
}

