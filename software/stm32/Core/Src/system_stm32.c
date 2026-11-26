/*
 * system_stm32.c 占位：系统时钟/启动相关初始化骨架。
 * 真实工程由 STM32CubeMX 生成完整实现（SystemInit / SystemCoreClockUpdate 等）。
 */
#include "main.h"

uint32_t SystemCoreClock = 8000000; /* 占位：HSE 8MHz，未倍频 */

void SystemInit(void)
{
    /* 真实工程在此配置向量表偏移、FPU、时钟树等 */
}

void SystemCoreClockUpdate(void)
{
    /* 真实工程根据时钟树计算 SystemCoreClock */
}
