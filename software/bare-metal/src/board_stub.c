/*
 * board 的桩实现（stub）。
 * 真实工程中删除本文件，替换为具体 MCU（如 STM32 / GD32 / ESP32-C3 裸机）的实现。
 * 这里只是为了让示例能在本机编译、验证逻辑结构。
 */
#include "board.h"

void board_init(void) { /* 实际：配置时钟、GPIO 复用 */ }

void board_led_toggle(uint8_t led_id) { (void)led_id; /* 实际：翻转 GPIO */ }

uint8_t board_din_read(uint8_t pin_id) { (void)pin_id; return 0; }

void board_delay_ms(uint32_t ms)
{
    /* 占位：真实工程用定时器；此处用忙等待近似（仅示例） */
    volatile uint32_t i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1000; j++) { /* 空循环 */ }
}
