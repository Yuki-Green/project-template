# STM32 (HAL/CMake) 平台

STM32 裸机/RTOS 工程骨架，基于 **STM32Cube HAL + arm-none-eabi-gcc + CMake/Makefile**。
示例芯片：STM32F103C8T6（Blue Pill），可改成任意 STM32 系列。

## 目录
```
stm32/
├── CMakeLists.txt        # CMake 构建（推荐，跨平台）
├── Makefile              # Make 构建封装
├── STM32F103C8TX_FLASH.ld# 链接脚本（按芯片改）
├── openocd.cfg           # 烧录配置（ST-Link/SWD）
├── Core/
│   ├── Inc/main.h        # 主头（LED 引脚、HAL 包含）
│   └── Src/main.c        # PC13 LED 翻转示例
│   └── Src/system_stm32.c# 系统时钟初始化骨架
├── Drivers/CMSIS/        # 放 CMSIS / HAL 库（复制模板后填入）
└── Startup/startup_stm32.s # 启动文件（用 CubeF1 官方版替换）
```

## 依赖
- 工具链：`arm-none-eabi-gcc`
- 构建：`cmake` 或 `make`
- 烧录：`openocd` + ST-Link（或 STM32CubeProgrammer）

## 使用
```bash
# 方式 A：CMake
cmake -B build -DCMAKE_TOOLCHAIN_FILE=... && cmake --build build

# 方式 B：Make
make build
make flash      # 通过 OpenOCD 烧录
```

> 这是**结构占位**：把 STM32CubeMX 生成的 HAL 库、启动文件、时钟配置覆盖进来即可。
> 仓库体积考虑，未包含 HAL 源码，请在 Drivers/ 自行放入对应 STM32Cube 包。
