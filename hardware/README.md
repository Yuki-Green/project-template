# 硬件示例 (Hardware Samples)

本目录提供**多平台最小可运行范例**，按工程情况取舍——用不到的子目录直接删除即可。

| 子目录        | 平台/语言                  | 适用场景                       |
| ------------- | -------------------------- | ------------------------------ |
| `bare-metal/` | 通用 HAL 风格 C + Makefile | MCU 裸机、无 RTOS              |
| `arduino/`    | Arduino / ESP32 (C++)      | 创客、物联网快速原型           |
| `esp-idf/`    | ESP32 官方框架 (CMake)     | 量产级 ESP32 固件（idf.py）   |
| `micropython/`| Raspberry Pi Pico (Python) | 树莓派 Pico / RP2040           |
| `fpga/`       | Verilog + 测试平台         | 数字逻辑、FPGA                 |
| `pcb/`        | 原理图 + PCB + BOM + 制板  | 电路板设计（KiCad 等 EDA）    |

> 这些示例刻意保持「最小」：LED 闪烁 / 读取一个数字输入。它们的作用是
> 给你一个**结构模板**，把真正的业务逻辑替换进去即可。
