#ifndef BOARD_H
#define BOARD_H

/*
 * 板级抽象层（最小 HAL 占位）。
 * 实际工程中替换为你的 MCU 厂商 SDK 头文件 / 寄存器定义。
 * 这里用弱符号函数，方便在不同板子上实现。
 */

#include <stdint.h>

/* 初始化硬件（时钟、GPIO 等）。厂商 SDK 中实现。 */
void board_init(void);

/* 翻转指定 LED。led_id 从 0 开始。 */
void board_led_toggle(uint8_t led_id);

/* 读取一个按键/数字输入，返回 0 或 1。 */
uint8_t board_din_read(uint8_t pin_id);

/* 毫秒级延时（由 SysTick / 定时器实现）。 */
void board_delay_ms(uint32_t ms);

#endif /* BOARD_H */
