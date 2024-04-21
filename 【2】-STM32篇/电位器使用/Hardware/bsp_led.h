#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"  


// ����LED��˸�������λ�����룩
#define BLINK_DELAY 1000


// ����LED����
#define LED_PIN GPIO_Pin_13
#define LED_PORT GPIOC


void delay_ms(uint32_t ms);

void led_init(void);

void LED_Blink(void);// led��˸����


//void led_on(uint32_t led_id);
//void led_off(uint32_t led_id);
//void led_toggle(uint32_t led_id);

#endif /* BSP_LED_H */

