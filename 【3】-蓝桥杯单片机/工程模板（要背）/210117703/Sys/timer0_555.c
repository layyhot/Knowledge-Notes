#include "timer0_555.h"



void Freq_Timer0_Init_555(void)		//100微秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x05;
	TL0 = 0;				//设置定时初始值
	TH0 = 0;				//设置定时初始值
	TR0 = 1;				//定时器0开始计时

}
