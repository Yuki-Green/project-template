# {{PROJECT_NAME}}

> 一句话描述这个项目是做什么的。把它写给「第一次打开这个仓库的陌生人」看。

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
![GitHub last commit](https://img.shields.io/github/last-commit/{{OWNER}}/{{REPO_NAME}})
![GitHub issues](https://img.shields.io/github/issues/{{OWNER}}/{{REPO_NAME}})

---

## 📌 项目简介

用 2–4 段话说明：

- 解决什么问题 / 痛点
- 目标用户是谁
- 它和同类项目的区别（可选）

## 🚀 快速开始

```bash
# 1. 克隆仓库
git clone https://github.com/{{OWNER}}/{{REPO_NAME}}.git
cd {{REPO_NAME}}

# 2. 安装依赖（按你的技术栈替换）
# npm install / pip install -r requirements.txt / go mod download

# 3. 运行
# 把启动命令写在这里
```

## 📦 安装

```bash
# 安装方式
```

## 🔧 用法示例

```bash
# 给出一个最小可运行的例子
```

## 🗂️ 目录结构

仓库主体分为三大目录，各司其职：

| 目录       | 用途                         |
| ---------- | ---------------------------- |
| `code/`    | 软件代码 + 测试              |
| `software/`| 嵌入式软件示例（多平台，按需取用） |
| `pcb/`     | 原理图 + PCB + BOM + 制板    |
| `docs/`    | 说明文档                     |

```
project-template/
├── .github/            # GitHub 模板（Issue/PR/CI/Dependabot）
│   ├── ISSUE_TEMPLATE/
│   └── workflows/
├── code/               # 【代码】软件源码 + 测试
│   └── tests/          #   测试
├── software/           # 【嵌入式软件】多平台示例（按需取用）
│   ├── bare-metal/     #   通用 HAL 风格 C + Makefile
│   ├── arduino/        #   Arduino / ESP32 (C++) + platformio.ini
│   ├── esp-idf/        #   ESP32 官方框架 (CMake/idf.py)
│   ├── stm32/          #   STM32 HAL + CMake/Make
│   ├── micropython/    #   Raspberry Pi Pico (Python)
│   └── fpga/           #   Verilog 闪烁模块 + 测试平台
├── pcb/                # 【硬件/电路】原理图 + PCB + BOM + 制板输出
│   ├── schematics/     #   原理图源文件
│   ├── board/          #   PCB 布局源文件
│   ├── fabrication/    #   制板输出（Gerber/BOM/坐标）
│   └── kicad-example/  #   KiCad 工程占位
├── docs/               # 【文档】说明文档
├── .gitignore
├── LICENSE
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── SECURITY.md
└── README.md
```

> 嵌入式软件示例详见 [software/README.md](software/README.md)；电路/PCB 详见 [pcb/README.md](pcb/README.md)。按工程情况保留对应子目录，其余删除即可。

## 🔧 嵌入式开发总览（software + pcb）

本模板把「**跑在芯片上的软件**」和「**承载芯片的电路板**」拆成两个独立目录，
便于分别迭代、分别打版本。典型配合流程：

```
需求 → pcb/ 画板(原理图+PCB) → 打样 → software/ 写固件 → 烧录验证
             ↑________ BOM/引脚约束反馈 ________↑
```

### software/ —— 嵌入式软件（固件）
按芯片/框架选一个平台目录，其余删除。每个目录都是最小可运行示例（LED 闪烁等）。

| 平台         | 语言/框架            | 构建方式                       | 适用场景            |
| ------------ | -------------------- | ------------------------------ | ------------------- |
| `bare-metal` | C（HAL 占位）        | `make -C software/bare-metal`  | 无 RTOS 裸机       |
| `arduino`    | C++（Arduino/ESP32） | `platformio run`               | 创客 / 快速原型     |
| `esp-idf`    | C（ESP-IDF/CMake）   | `make -C software/esp-idf`     | 量产级 ESP32 固件  |
| `stm32`      | C（HAL/CMake/Make）  | `make -C software/stm32`       | 通用 STM32 MCU     |
| `micropython`| Python               | `mpremote run main.py`         | 树莓派 Pico        |
| `fpga`       | Verilog              | `iverilog` + 仿真              | 数字逻辑 / FPGA    |

顶层 `make build` 会自动遍历 `bare-metal / esp-idf / stm32` 三个自带 Makefile 的平台统一构建。

### pcb/ —— 电路（原理图 + PCB）
与 `software/` 同级，独立管理电路板设计。

| 子目录         | 内容                                   |
| -------------- | -------------------------------------- |
| `schematics/`  | 原理图源文件（`.kicad_sch` / `.sch`）  |
| `board/`       | PCB 布局源文件（`.kicad_pcb` / `.brd`）|
| `fabrication/` | 制板输出：Gerber / 钻孔 / BOM（`bom.csv`）/ 贴片坐标 |
| `kicad-example/`| 最小可打开的 KiCad 工程占位            |

`pcb/reference-schematic.svg` 是一张**可读的参考原理图**（电源→MCU→LED），
不依赖任何 EDA 即可在浏览器查看；正式设计请放在 `schematics/` 与 `board/`。

### 两者如何对齐
- **引脚**：`pcb/` 中 MCU 的 GPIO 分配要和 `software/` 里代码中的引脚定义一致
  （如 `software/stm32/Core/Inc/main.h` 的 `LED_PIN`、ESP32 的 `BLINK_GPIO`）。
- **版本**：建议对硬件和固件分别打 tag（如 `hw-rev1.0` / `fw-v1.0`），避免混淆。
- **制板前自检**：ERC/DRC 无错、丝印清晰、电源/地/关键网络核对完毕再投板。

## 🛠️ 开发

说明本地开发流程：分支策略、提交规范、如何运行测试等。

```bash
# make test / npm test / pytest
```

## 🤝 贡献

欢迎贡献！请先阅读 [CONTRIBUTING.md](CONTRIBUTING.md)。
提交 Issue 前请使用对应的 Issue 模板。

## 🔒 安全

发现安全漏洞？请按 [SECURITY.md](SECURITY.md) 的流程私下报告，**不要**公开 Issue。

## 📄 许可证

本项目基于 [MIT License](LICENSE) 开源。

## ✉️ 联系方式

- 维护者：{{OWNER}}
- Email：{{EMAIL}}
