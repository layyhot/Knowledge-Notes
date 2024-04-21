#include "pot_adc.h"



void pot_adc_init(void)
{
	
	// 初始化LED的GPIO引脚
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// 初始化ADC的GPIO引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// 初始化ADC
	ADC_InitTypeDef ADC_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_InitStructure);

	// 配置ADC通道
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_55Cycles5);

	// 启动ADC
	ADC_Cmd(ADC1, ENABLE);

	// 启动ADC校准
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
}



// 读取ADC转换值
uint16_t Read_Pot_ADC(void)
{
	
	// 启动ADC转换
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);

	// 等待转换完成
	while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	
	return ADC_GetConversionValue(ADC1);
}
