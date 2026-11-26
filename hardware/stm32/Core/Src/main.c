/*
 * STM32 最小示例（HAL 风格占位）：PC13 LED 翻转。
 * 构建：make build  （需 arm-none-eabi-gcc + 链接脚本）
 * 烧录：make flash  （需 OpenOCD + ST-Link）
 *
 * 真实工程用 STM32CubeMX 生成初始化代码后，把本文件替换/合并即可。
 */
#include "main.h"

int main(void)
{
    /* HAL 初始化（真实工程由 CubeMX 生成 SystemInit/时钟配置） */
    /* HAL_Init(); */
    /* SystemClock_Config(); */

    /* 使能 GPIOC 时钟并配置 PC13 为输出 */
    /* __HAL_RCC_GPIOC_CLK_ENABLE(); */
    /* GPIO_InitTypeDef gpio = {0}; */
    /* gpio.Pin = LED_PIN; gpio.Mode = GPIO_MODE_OUTPUT_PP; */
    /* gpio.Pull = GPIO_NOPULL; gpio.Speed = GPIO_SPEED_FREQ_LOW; */
    /* HAL_GPIO_Init(LED_GPIO_PORT, &gpio); */

    while (1) {
        /* HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN); */
        /* HAL_Delay(500); */
        for (volatile unsigned i = 0; i < 1000000; i++) { /* 占位延时 */ }
    }
}

void Error_Handler(void)
{
    while (1) { /* 错误处理：可在此闪烁错误码 */ }
}
