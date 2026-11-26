# ESP-IDF 构建封装（需要已安装并激活 ESP-IDF 环境）
# 用法:
#   make build      # 等价于 idf.py build
#   make flash      # idf.py -p $(PORT) flash
#   make monitor    # idf.py -p $(PORT) monitor
#   make clean      # idf.py fullclean

PORT ?= /dev/ttyUSB0
IDF_PY ?= idf.py

.PHONY: build flash monitor clean all

build:
	$(IDF_PY) build

flash: build
	$(IDF_PY) -p $(PORT) flash

monitor:
	$(IDF_PY) -p $(PORT) monitor

clean:
	$(IDF_PY) fullclean

all: build
