#ifndef _POT_ADC_H
#define _POT_ADC_H

#include "stm32f10x.h"  


// ����ADCͨ��
#define ADC_CHANNEL ADC_Channel_0//PA0


// ����ADCת��ֵ�ķ�Χ��12λADC�����ֵΪ4095��
#define ADC_MAX_VALUE 4095


void pot_adc_init(void);

uint16_t Read_Pot_ADC(void);

#endif 

