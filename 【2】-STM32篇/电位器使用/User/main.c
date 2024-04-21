#include "stm32f10x.h"
#include "bsp_led.h"
#include "pot_adc.h"
#include "oled.h"
#include <stdio.h>

// ������ֵ������λ����ѹ��������ֵʱ����LED��˸
#define THRESHOLD_VOLTAGE 3.0 // ������ֵΪ3.0V
// ����ADCת��ֵ�ķ�Χ��12λADC�����ֵΪ4095��
//#define ADC_MAX_VALUE 4095




int main(void)
{
	char voltage_str[10]; // Ϊ�ַ���Ԥ���㹻�Ŀռ䣬������󳤶�Ϊ10���ַ�

	led_init();
	OLED_Init();
	pot_adc_init();
	
	
	OLED_ShowString(1, 1, "Voltage:");
	OLED_ShowString(3, 1, "Hello,world!");
	
	
	while (1)
	{
		// Ϩ��LED
		GPIO_SetBits(LED_PORT, LED_PIN);
		
		// ��ȡADCת��ֵ
		uint16_t adc_value = Read_Pot_ADC();

		// ��ADCת��ֵת��Ϊ��ѹֵ
		float voltage = (float)adc_value * (5.0 / ADC_MAX_VALUE);
		
		sprintf(voltage_str, "%.2f", voltage); // ����ѹֵת��Ϊ�ַ�����������λС��
		OLED_ShowString(2, 1, voltage_str); // �� OLED ����ʾ��ѹֵ
		
		// �����ѹ������ֵ���򴥷�LED��˸
		if (voltage > THRESHOLD_VOLTAGE)
			LED_Blink();
	}
}





