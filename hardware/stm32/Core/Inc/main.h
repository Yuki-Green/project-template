#ifndef MAIN_H
#define MAIN_H

#include "stm32f1xx_hal.h"   // 真实工程替换为对应系列头文件

/* 板载 LED 引脚（Blue Pill：PC13） */
#define LED_PIN       GPIO_PIN_13
#define LED_GPIO_PORT GPIOC

void SystemClock_Config(void);
void Error_Handler(void);

#endif /* MAIN_H */
