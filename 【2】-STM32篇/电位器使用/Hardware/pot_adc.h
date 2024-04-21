#ifndef _POT_ADC_H
#define _POT_ADC_H

#include "stm32f10x.h"  


// 定义ADC通道
#define ADC_CHANNEL ADC_Channel_0//PA0


// 定义ADC转换值的范围（12位ADC，最大值为4095）
#define ADC_MAX_VALUE 4095


void pot_adc_init(void);

uint16_t Read_Pot_ADC(void);

#endif 

