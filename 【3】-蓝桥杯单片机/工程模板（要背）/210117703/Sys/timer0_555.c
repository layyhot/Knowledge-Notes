#include "timer0_555.h"



void Freq_Timer0_Init_555(void)		//100΢��@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x05;
	TL0 = 0;				//���ö�ʱ��ʼֵ
	TH0 = 0;				//���ö�ʱ��ʼֵ
	TR0 = 1;				//��ʱ��0��ʼ��ʱ

}
