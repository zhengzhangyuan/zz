#ifndef __P12864_H_
#define __P12864_H_

#include "LCD12864_VIEW.H"

/**********************************
 	������Ч
***********************************/

#define UP 1
#define DOWN 0
#define SLOW 15000
#define NORMAL 5000
#define FAST  0
#define POSITIVE 1
#define OPPOSITE 0
#define NEW      1
#define OLD      0

typedef enum
{
  Baiye_X,			 //��Ҷ��
  Baiye_X_Clear,
  Round_S,			 //��ת
  Round_S_Clear,
  Suijixian_Y,		 //�������
  Suijixian_Y_Clear,
  Into_Y,			  //Y�����
  Out_Y,			  //Y���˳�
  Fanzhuan,			  //��ת
  Draw				  //��ʾͼƬ
} gra12864_Mode;
//���亯��
void Fgraphic12864(unsigned int speed,unsigned char dir,unsigned char mode,const unsigned char pic[64][16]);	  
//ʵ�ֲ���
void ygra12864 (unsigned int speed,char dir,const unsigned char pic[64][16]);
void yogra12864 (unsigned int speed,char dir,const unsigned char pic[64][16]);
void xgra12864_baiyechuang (unsigned int speed,char dir,const unsigned char pic[64][16]);
void roundgra12864_solo (unsigned int speed,char dir,const unsigned char pic[64][16]);
void suijixiantiaogra12864 (unsigned int speed,char dir,const unsigned char pic[64][16]);
void croundgra12864_solo (unsigned int speed);
void csuijixiantiaogra12864 (unsigned int speed);
void cxgra12864_baiyechuang (unsigned int speed);
void fanzhuan12864(void);
void Draw12864(unsigned char dir,const unsigned char pic[64][16]);
/***********************************
�����������
************************************/
#define BIG  2
#define MIDDLE 1
#define SMALL  0
void sumgra12864(char xdip,char ydip,char size,char *string);
/*********************
	��ͼ����
**********************/
void clsgraphic (void)	  ;
/********************
	���з���
********************/
void fanbai (unsigned char line) ;
/***************************
	 ���淴��
***************************/
void fanbai_gra (unsigned char new,unsigned char lines);
/**************************
	ָ��
**************************/
void point_line (unsigned char on,unsigned char lines);
/***************************
	 ��������ʾ
***************************/
void ratio_display (unsigned char lines,unsigned char ratio[8]);
/*******************
	��Ļ����ģʽ��������
*******************/
void string12864_all(unsigned int Delay,unsigned char deviation,unsigned char pages, char **str) ;


#endif
