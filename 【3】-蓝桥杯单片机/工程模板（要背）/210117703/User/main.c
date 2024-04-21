#include <STC15F2K60S2.H>
#include <stdio.h>
#include <intrins.h>
#include "init_cls_der.h"
#include "dsp_led.h"
#include "dsp_seg.h"
#include "key.h"
#include "timer.h"
#include "timer0_555.h"
//#include "timer0_PWM.h"

#include "onewire.h"
#include "ds1302.h"
#include "iic.h"

//三大金刚
void Led_Pro(void);
void Seg_Pro(void);
void Key_Pro(void);
void Delay750ms(void);

sbit PWM_Cont = P3^4;

//LED变量
unsigned char ucled;

//SEG变量
unsigned char seg_str[10], pos;
unsigned char seg_buf[8] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

//KEY变量
unsigned char key_value;
unsigned char key_down, key_old;

//定时器延时变量
unsigned long ms_dida;
unsigned char Key_Slow_Down;
unsigned int Seg_Slow_Down;
unsigned char Led_Slow_Down;

//555测频变量
unsigned int freq;

////PWM变量
//unsigned char PWM_Num;

//温度变量--可以用，可不用
float temperature;

//DS1302时间模块
unsigned char uRtc[3] = {23, 59, 55};

//IIC数据储存模块
unsigned char EEPROM_str[4] = {1, 2, 3, 9};
unsigned char ADC_User;

//BOOL变量
bit LED_Dsp_flag;
bit Long_Down_flag;
bit isDoubleClick;


//自定义变量
unsigned char us_key;
unsigned long ms_Tick_isDoubleClick;

int main()
{
	Cls_Der();
	Timer1_Init();
//	Timer0_Init();
	Freq_Timer0_Init_555();
	EA = 1;
	Read_Onewire();
	Write_Time(uRtc);
	
	
	Write_EEPROM(64, EEPROM_str, 4);
	
	us_key = 4;
	ucled = 0xaa;
	
	Delay750ms();
	
	while(1)
	{
		Led_Pro();
		Seg_Pro();
		Key_Pro();
	}
	
}

//void Timer0_Isr(void) interrupt 1
//{
//	
//	if(PWM_Num < 1)  {PWM_Cont = 1;Dsp_Led(0xff);}
//	else {PWM_Cont = 0; Dsp_Led(0);}
//	
//	if(++PWM_Num >= 10)	{PWM_Num = 0;}
//	`
//}


void Timer1_Isr(void) interrupt 3
{
	ms_dida++;
	
	if(++ Key_Slow_Down == 10) Key_Slow_Down = 0;
	if(++ Seg_Slow_Down == 500) Seg_Slow_Down = 0;
	if(++ Led_Slow_Down == 100) Led_Slow_Down = 0;
	
	
	
	
		
	
	Dsp_Seg(seg_buf, pos);
	if(++ pos == 8)  pos = 0;
	Dsp_Led(ucled);
	
	if(ms_dida%1000 == 0)
	{
		freq = (TH0 << 8) | TL0;
		TH0 = 0;
		TL0 = 0;
	}
}


void Key_Pro(void)
{
	if(Key_Slow_Down) return;
	Key_Slow_Down = 1;
	
	
	key_value = Scan_Key();
	key_down = key_value & (key_value ^ key_old);
	key_old = key_value;
	
	
	switch(key_down)
	{
		case 7 :
			LED_Dsp_flag ^= 1;
			break;
		case 6:
			us_key = 6;
			break;
		case 5:
			us_key = 5;
			break;
		case 11:
			us_key = 11;
			break;
		case 10:
			us_key = 10;
			break;
		case 15:
			us_key = 15;
			break;
		case 17:
			us_key = 17;
			break;
		case 19:
			if (isDoubleClick) 
			{
				// 第二次按键下降沿，执行双击事件的相应操作
				// 这里可以触发某个功能或执行其他操作
				us_key = 60;
				isDoubleClick = 0;  // 重置双击事件标志位
			}
			else 
			{
				us_key = 61;
				isDoubleClick = 1;
				ms_Tick_isDoubleClick = ms_dida;
			}
			
			break;
//		default:
//			if(key_down != 0)	us_key = key_down;
//			break;
	}
	
	
	
	
	
	
	switch(key_old)//这个结构很常见，判别是哪个按键按下去了，根据按键按下的情况，控制内部数据变量的变化
	{
		case 17:
			if(us_key == 17)Long_Down_flag = 1;
			break;
		default:
			if (ms_dida - ms_Tick_isDoubleClick > 200) isDoubleClick = 0;
			Long_Down_flag = 0;
			break;
	}
}



void Seg_Pro(void)
{
	if(Seg_Slow_Down) return;
	Seg_Slow_Down = 1;
	
	
	switch(us_key)
	{
		case 6:
			Read_Time(uRtc);
			sprintf(seg_str, "%02d-%02d-%02d", (unsigned int)uRtc[0], (unsigned int)uRtc[1], (unsigned int)uRtc[2]);
			break;
		case 5:
			sprintf(seg_str, "C11-%4.2f", (Read_Onewire()/16.0));
			break;
		case 11:
			Read_EEPROM(64, EEPROM_str, 4);
			sprintf(seg_str, "%02d-%02d-%02d", (unsigned int)EEPROM_str[1], (unsigned int)EEPROM_str[0], (unsigned int)EEPROM_str[0]);
			
			break;
		case 10:
			sprintf(seg_str, "AU---%03d", (unsigned int)(Read_ADC(0x43)));
			break;
		case 15:
			sprintf(seg_str, "F--%5d", (unsigned int)freq);
			break;
	
		case 17:
			if(Long_Down_flag) {sprintf(seg_str, "L0N-%4.2f", (Read_Onewire()/16.0));}
			else sprintf(seg_str, "L0N--L0N");
			break;
		case 60:
			sprintf(seg_str, "22-22-22");
			break;
		case 61:
			sprintf(seg_str, "11-11-11");
			break;
		default:
			sprintf(seg_str, "%02d123456", (unsigned int)us_key);
			break;
	}
	
	Seg_Str_To_Buf(seg_str, seg_buf);
}


void Led_Pro(void)
{
	if(Led_Slow_Down) return;
	Led_Slow_Down = 1;
	
	if(LED_Dsp_flag)
	{ucled = 0xff ^ ucled;}
	
	else if(us_key == 6)
	{ucled = 0xe7;}
	else if(us_key == 5)
	{ucled = 0xc3;}
}


void Delay750ms(void)	//@12.000MHz
{
	unsigned char data i, j, k;

	i = 35;
	j = 51;
	k = 182;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
