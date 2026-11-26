/* STM32F103C8T6 启动文件（汇编占位，节选 Reset 向量与栈）
 * 真实工程请用 STM32CubeF1 提供的官方 startup_stm32f103xb.s，
 * 这里给出最小结构说明入口，保证工程能被链接器识别。
 */
    .syntax unified
    .cpu cortex-m3
    .thumb

    .section .stack, "aw", %nobits
    .space 0x400            /* 1KB 栈 */

    .section .isr_vector, "a"
    .word   _estack         /* 栈顶 */
    .word   Reset_Handler   /* 复位向量 */

    .text
    .thumb_func
    .global Reset_Handler
Reset_Handler:
    bl  SystemInit
    bl  main
    b   .

    .weak   Default_Handler
    .thumb_func
Default_Handler:
    b   .
