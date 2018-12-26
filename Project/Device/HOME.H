#ifndef __HOME_H_
#define __HOME_H_

/*************************
页编号总共8位
高三位选择模式，低五位选择页码

*************************/

#define PAGE_LIMIT 12
#define LINE_LIMIT 12
#define LCD_1602_MoceSpeed 4
////////////页码映射///////////
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
////////////页面显示结构体////////////
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
////////////页面结构体初始化函数/////////////
#define Page_InformationTypedef_Init {PAGE_LIMIT,0,Home_Page,LINE_LIMIT,1,0,0}
///////////各功能显示参数结构体//////////////
//typedef struct
//{
// unsigned char Function_Light_Set;
// unsigned char Function_LCD1602;
//}Special_FunctionTypedef;
//#define Page_InfomationTypedef_Init {0,0}
///////////各功能设置函数进入标志//////////////
//typedef struct
//{
// unsigned char Function_Light_Flag;
// unsigned char Function_LCD1602_Flag;
//}Function_FlagTypedef;


void Home_12864 (void);   //主屏幕显示函数
void Home_1602  (void);   //副屏幕显示函数
void Page_Init(unsigned char New_Page_Line);//新页初始化
void Page_gra_Init(unsigned char New_Page_Line);//新桌面始化

/**************************
自检界面
*************************/
void post (void);


#endif

