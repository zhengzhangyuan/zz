#include <stdio.h>
#include <string.h>
#include "Fdelay.H"
#include "LCD12864_VIEW.H"

uint8_t   Fdelay_Flagus=0,Fdelay_Flagms=0;
volatile uint32_t  us_vale=0,ms_vale=127;

void delayus(uint32_t us)
{
	uint32_t   i,ustemp;
	if(!Fdelay_Flagus)
	{
	SysTick_Config(SystemCoreClock/1000000);
	for(i=0;i<us;i++)
	{
		while(!((SysTick->CTRL)&(1<<16)));
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }
	else
	{
		 us++;
 while(--us)
 {
  ustemp=us_vale;
 while(--ustemp);

 }
	}
}


void delayms(uint32_t ms)
{
	uint32_t i;
	if(!Fdelay_Flagms)
	{
	SysTick_Config(SystemCoreClock/1000);
	for(i=0;i<ms;i++)
	{
		while(!((SysTick->CTRL)&(1<<16)));
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }
	else
	{
		while(ms)
		{
//  mstemp=ms_vale;
// while(--mstemp);
		delayus(1000);
			ms--;
		}
	}
}

void Initdelay ()
{
  char str [16]={0};
  char stp [16]={0};
	
sprintf(str,"开始调整");
string12864(0,0,str);
sprintf(str,"核心速度");
switch(SystemCoreClock)
{
 case 1: sprintf(stp,"11.0592"); break;
 case 2: sprintf(stp,"12"); break;
 case 3: sprintf(stp,"22.1184"); break;
 case 4: sprintf(stp,"24"); break;
 case 5: sprintf(stp,"30"); break;
	default : sprintf(stp,"72MHZ");break;
}
strcat(str,stp);
string12864(0,3,str);
delayms(1000);

AdjDelay();

sprintf(str,"调整结束");
string12864(0,1,str);
delayms(2000);
cls12864();
}

void AdjDelay(void)  //延时自动调整函数
{
	SysTick_Config(SystemCoreClock/1000000);
		while(!((SysTick->CTRL)&(1<<16)))
			us_vale++;
		
		us_vale = us_vale * 3;
		//if(us_vale>5){ while(1)string12864(0,1,str);}
	//	 while(1)string12864(0,1,str);
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
		
	Fdelay_Flagus = 1;	
	Fdelay_Flagms = 1;
		
			SysTick_Config(SystemCoreClock/100);//打开系统定时器10ms
}

