/*
 * ESP-IDF 最小示例：板载/外接 LED 闪烁。
 * 构建：在 esp-idf/ 目录执行 `make build`（等价 idf.py build）
 * 烧录：make flash PORT=/dev/ttyUSB0
 * 串口：make monitor
 */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

/* 闪烁引脚，默认 GPIO2（可在 sdkconfig.defaults 修改） */
#define BLINK_GPIO CONFIG_BLINK_GPIO

void app_main(void)
{
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
