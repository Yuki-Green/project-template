/*
 * 裸机 C 最小示例：LED 闪烁 + 按键读取（HAL 占位版）。
 * 编译：在 bare-metal/ 目录下执行 `make`
 */

#include "board.h"

int main(void)
{
    board_init();

    uint32_t count = 0;

    while (1) {
        /* 每 500ms 翻转 LED0 */
        board_led_toggle(0);

        /* 示例：读取按键，可按住某键改变行为 */
        if (board_din_read(0)) {
            count++;
        }

        board_delay_ms(500);
    }

    /* 永远不会到达这里，但保留以防编译器告警 */
    return 0;
}
