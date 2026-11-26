# =====================================================================
# 顶层 Makefile —— 统一入口
# 目标: help / lint / test / build / clean / all
# 说明: 这是一个脚手架。复制模板后，按你的技术栈把具体命令
#       填入对应目标即可。软件各平台在 software/<platform>/ 下
#       有各自构建方式，顶层通过遍历已知子目录统一调度。
# =====================================================================

.DEFAULT_GOAL := help

# 软件源码 / 测试目录
CODE_DIR := code

# 支持「make 构建」的硬件平台（各目录需自带 Makefile）
HW_BUILDABLE := bare-metal esp-idf stm32

.PHONY: help lint test build clean all $(HW_BUILDABLE)

help:
	@echo "可用目标:"
	@echo "  make help    显示本帮助"
	@echo "  make lint    代码风格 / 静态检查"
	@echo "  make test    运行测试"
	@echo "  make build   构建软件 + 硬件固件"
	@echo "  make clean   清理构建产物"
	@echo "  make all     lint + test + build"
	@echo ""
	@echo "硬件平台构建（按需启用，需先装对应工具链）:"
	@echo "  make -C software/bare-metal build   # 裸机 C (gcc)"
	@echo "  make -C software/esp-idf build      # ESP-IDF (idf.py)"
	@echo "其他平台手动构建:"
	@echo "  software/arduino    -> platformio run"
	@echo "  software/micropython-> mpremote run main.py"
	@echo "  software/fpga       -> iverilog + gtkwave"

# ---- 软件：lint / test ----
# 按语言启用，例如:
#   Python: ruff check $(CODE_DIR) / pytest
#   Node:   npm run lint          / npm test
#   Go:     golangci-lint run     / go test ./...
lint:
	@echo ">> [lint] 在 $(CODE_DIR)/ 运行代码检查"
	@echo "   示例: ruff check $(CODE_DIR) | npm run lint | golangci-lint run"
	@echo "   未配置具体工具，跳过（复制模板后启用）。"

test:
	@echo ">> [test] 在 $(CODE_DIR)/tests 运行测试"
	@echo "   示例: pytest | npm test | go test ./..."
	@echo "   未配置具体工具，跳过（复制模板后启用）。"

# ---- 硬件：构建各平台 ----
# 每个平台在自己的目录里有 Makefile，顶层统一调度。
build: $(HW_BUILDABLE)
	@echo ">> [build] 软件构建（按需启用，例如 docker build / npm run build）"

$(HW_BUILDABLE):
	@echo ">> [build:$@] 构建软件平台: $@"
	@if [ -f software/$@/Makefile ]; then \
		$(MAKE) -C software/$@ build || echo "   (跳过 $@：需先配置工具链)"; \
	else \
		echo "   software/$@ 无 Makefile，请按该目录 README 手动构建"; \
	fi

clean:
	@echo ">> [clean] 清理产物"
	@for p in $(HW_BUILDABLE); do \
		if [ -f software/$$p/Makefile ]; then $(MAKE) -C software/$$p clean 2>/dev/null || true; fi; \
	done

all: lint test build
