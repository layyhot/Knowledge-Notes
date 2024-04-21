#include "bsp_led.h"


void led_init(void)
{
	// 初始化LED的GPIO引脚
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = LED_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_PORT, &GPIO_InitStructure);
	// 熄灭LED
	GPIO_SetBits(LED_PORT, LED_PIN);
}

// 控制LED闪烁函数
void LED_Blink(void)
{
  // 熄灭LED
  GPIO_SetBits(LED_PORT, LED_PIN);
  
  // 延时
  delay_ms(BLINK_DELAY);
  
  // 点亮LED
  GPIO_ResetBits(LED_PORT, LED_PIN);
  
  // 延时
  delay_ms(BLINK_DELAY);
}


// 毫秒级延时函数
void delay_ms(uint32_t ms)
{
  uint32_t i;
  for (i = 0; i < ms; i++)
  {
    uint32_t j;
    for (j = 0; j < 1000; j++);
  }
}

