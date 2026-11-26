cmake_minimum_required(VERSION 3.20)
project(stm32_template C CXX ASM)

# ---- 工具链 ----
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# ---- MCU 参数（按芯片修改）----
set(MCU_FAMILY STM32F1xx)
set(MCU_MODEL STM32F103C8Tx)
add_compile_definitions(${MCU_MODEL})

set(CMAKE_C_FLAGS "-mcpu=cortex-m3 -mthumb -Wall -Wextra -O2 -g")
set(CMAKE_EXE_LINKER_FLAGS "-T${CMAKE_SOURCE_DIR}/STM32F103C8TX_FLASH.ld -Wl,-Map=firmware.map")

# ---- 源文件 ----
file(GLOB SRC_CORE Core/Src/*.c)
list(APPEND SRC Startup/startup_stm32.s)

include_directories(Core/Inc Drivers/CMSIS)

add_executable(firmware.elf ${SRC_CORE} Startup/startup_stm32.s)

# ---- 输出 bin/hex ----
add_custom_command(TARGET firmware.elf POST_BUILD
    COMMAND arm-none-eabi-objcopy -O binary $< ${CMAKE_BINARY_DIR}/firmware.bin
    COMMAND arm-none-eabi-objcopy -O ihex   $< ${CMAKE_BINARY_DIR}/firmware.hex)
