#ifndef __HOME_H_
#define __HOME_H_

/*************************
ҳ����ܹ�8λ
����λѡ��ģʽ������λѡ��ҳ��

*************************/

#define PAGE_LIMIT 12
#define LINE_LIMIT 12
#define LCD_1602_MoceSpeed 4
////////////ҳ��ӳ��///////////
typedef enum
{
 Home_Page = 0X80,
 Game_Page = 0X01,
 Inveter_Page = 0X02,
 Set_Page = 0X03,
 About_Page = 0X04,
 Light_Page = 0X05,
 Light_Set_Page = 0X26,
 Time_Set_Page  = 0X27,
 Bldc_Page      = 0X28,
}Page_Address;
////////////ҳ����ʾ�ṹ��////////////
typedef struct
{
 unsigned char Max_Page;
 unsigned char Last_Page;
 unsigned char Now_Page;
 unsigned char Max_Line;
 unsigned char Last_Line;
 unsigned char Now_Line;
 unsigned char Special_Function;
}Page_InformationTypedef;
////////////ҳ��ṹ���ʼ������/////////////
#define Page_InformationTypedef_Init {PAGE_LIMIT,0,Home_Page,LINE_LIMIT,1,0,0}
///////////��������ʾ�����ṹ��//////////////
//typedef struct
//{
// unsigned char Function_Light_Set;
// unsigned char Function_LCD1602;
//}Special_FunctionTypedef;
//#define Page_InfomationTypedef_Init {0,0}
///////////���������ú��������־//////////////
//typedef struct
//{
// unsigned char Function_Light_Flag;
// unsigned char Function_LCD1602_Flag;
//}Function_FlagTypedef;


void Home_12864 (void);   //����Ļ��ʾ����
void Home_1602  (void);   //����Ļ��ʾ����
void Page_Init(unsigned char New_Page_Line);//��ҳ��ʼ��
void Page_gra_Init(unsigned char New_Page_Line);//������ʼ��

/**************************
�Լ����
*************************/
void post (void);


#endif
