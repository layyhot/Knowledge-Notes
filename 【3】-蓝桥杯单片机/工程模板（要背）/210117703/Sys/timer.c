#include "timer.h"


void Timer1_Init(void)		//1����@12.000MHz
{
	AUXR &= 0xBF;			//��ʱ��ʱ��12Tģʽ
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TL1 = 0x18;				//���ö�ʱ��ʼֵ
	TH1 = 0xFC;				//���ö�ʱ��ʼֵ
	TF1 = 0;				//���TF1��־
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
	
	ET1 = 1;				//ʹ�ܶ�ʱ��1�ж�
}


