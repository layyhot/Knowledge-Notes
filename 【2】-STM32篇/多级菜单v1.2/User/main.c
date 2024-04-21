#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Timer.h"
#include "Encoder.h"
#include "Key.h"
#include "OLED.h"
#include "menu.h"


int main(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);		//Enables or disables the Low Speed APB (APB1) peripheral clock.
	PWR_WakeUpPinCmd(ENABLE);
	
	Timer_Init();
	OLED_Init();
	Encoder_Init();
	Key_Init();
	
	while(1)
	{
		main_menu();
		
		OLED_Clear();
		OLED_Update();
		PWR_EnterSTOPMode(PWR_Regulator_ON, PWR_STOPEntry_WFI);	//SIOP模式
		SystemInit();
		Key_Reset_All();
	}
}
