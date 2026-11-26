# 裸机 C Makefile（占位，需按工具链修改）
# 默认用主机 gcc 编译 stub 版，仅用于验证结构；烧录请用交叉工具链。

CC      ?= gcc
CFLAGS  ?= -std=c11 -Wall -Wextra -O2
SRC     := src/main.c src/board_stub.c
BIN     := firmware.elf

.PHONY: all clean flash

all:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

clean:
	rm -f $(BIN)

# 真实工程示例（取消注释并修改）：
# CC = arm-none-eabi-gcc
# CFLAGS += -mcpu=cortex-m4 -mthumb -T link.ld
# flash: all
#	openocd -f interface.cfg -f target.cfg -c "program $(BIN) verify reset exit"
