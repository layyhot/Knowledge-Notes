#include "stm32f10x.h"
#include "bsp_led.h"
#include "pot_adc.h"
#include "oled.h"
#include <stdio.h>

// 定义阈值，当电位器电压超过该阈值时触发LED闪烁
#define THRESHOLD_VOLTAGE 3.0 // 假设阈值为3.0V
// 定义ADC转换值的范围（12位ADC，最大值为4095）
//#define ADC_MAX_VALUE 4095




int main(void)
{
	char voltage_str[10]; // 为字符串预留足够的空间，假设最大长度为10个字符

	led_init();
	OLED_Init();
	pot_adc_init();
	
	
	OLED_ShowString(1, 1, "Voltage:");
	OLED_ShowString(3, 1, "Hello,world!");
	
	
	while (1)
	{
		// 熄灭LED
		GPIO_SetBits(LED_PORT, LED_PIN);
		
		// 读取ADC转换值
		uint16_t adc_value = Read_Pot_ADC();

		// 将ADC转换值转换为电压值
		float voltage = (float)adc_value * (5.0 / ADC_MAX_VALUE);
		
		sprintf(voltage_str, "%.2f", voltage); // 将电压值转换为字符串并保留两位小数
		OLED_ShowString(2, 1, voltage_str); // 在 OLED 上显示电压值
		
		// 如果电压超过阈值，则触发LED闪烁
		if (voltage > THRESHOLD_VOLTAGE)
			LED_Blink();
	}
}





