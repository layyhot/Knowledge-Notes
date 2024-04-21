#ifndef __MENU_H
#define __MENU_H
#include "stm32f10x.h"                  // Device header
#include <string.h>
#include "OLED.h"
#include "Encoder.h"
#include "Key.h"

#include "Game_Snake.h" 
#include "game_of_life.h" 

#define		WORD_H 		16				//字高word height

enum CursorStyle
{
	reverse,
	mouse,
	frame,
};
	
extern enum CursorStyle CurStyle;
extern int8_t Speed_Factor;				//光标动画速度;
extern float Roll_Speed;				//滚动动画速度;

/**********************************************************/
struct option_class
{
	char* Name;				//选项名字
	void (*func)(void);		//函数指针
	uint8_t NameLen;		//由于中文占三个字节,用strlen计算名字宽度不再准确,故需额外储存名字宽度
};
/**********************************************************/
int8_t menu_Roll_event(void);
int8_t menu_Enter_event(void);
int8_t menu_Back_event(void);
void run_menu(struct option_class* option);
uint8_t Get_NameLen(char* String);

/**********************************************************/
void main_menu(void);
void tools_menu(void);
void games_menu(void);
void Setting_menu(void);
void Information(void);

/**********************************************************/

#endif
