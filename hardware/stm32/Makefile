# STM32 (HAL/CMake) 构建封装
# 依赖：arm-none-eabi-gcc、CMake、OpenOCD（或 STM32CubeProgrammer）
# 用法：
#   make build        # 交叉编译 + 链接，生成 firmware.elf / .bin / .hex
#   make flash        # 通过 OpenOCD 烧录（需 ST-Link）
#   make clean

BUILD_DIR ?= build
TARGET    ?= firmware
MCU       ?= STM32F103C8Tx     # 按实际芯片修改（Blue Pill 常见）
LINKER    ?= STM32F103C8TX_FLASH.ld
OPENOCD_CFG ?= openocd.cfg

CC      := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
SIZE    := arm-none-eabi-size

CFLAGS  := -mcpu=cortex-m3 -mthumb -Wall -Wextra -O2 -g \
           -D$(MCU) -I Core/Inc -IDrivers/CMSIS
LDFLAGS := -T$(LINKER) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map

SRC := Core/Src/main.c Core/Src/system_stm32.c Startup/startup_stm32.s

.PHONY: build flash clean

build:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC) -o $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).bin
	$(OBJCOPY) -O ihex   $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex
	$(SIZE) $(BUILD_DIR)/$(TARGET).elf

flash: build
	openocd -f $(OPENOCD_CFG) -c "program $(BUILD_DIR)/$(TARGET).elf verify reset exit"

clean:
	rm -rf $(BUILD_DIR)
