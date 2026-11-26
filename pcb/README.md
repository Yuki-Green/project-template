# 原理图 & PCB (Schematics & PCB)

本目录是电路板设计的脚手架。按工程情况选择 EDA 工具，把对应文件放进来即可。

| 子目录         | 用途                                           |
| -------------- | ---------------------------------------------- |
| `schematics/`  | 原理图源文件（`.sch` / `.kicad_sch` / `.sch`（Eagle）） |
| `board/`       | PCB 布局源文件（`.kicad_pcb` / `.brd`）        |
| `fabrication/` | 制板输出（Gerber、钻孔、坐标/BOM 供贴片）      |
| `kicad-example/` | 一个最小可打开的 KiCad 工程骨架（占位）      |

## 推荐的工程约定

- **原理图和 PCB 同源管理**：和代码一样，每次改版打 Git tag（如 `hw-rev1.0`）。
- **版本化**：在文件名或目录里标注版本（`rev1.0` / `rev1.1`），避免覆盖旧板。
- **制板前自检**：
  - 电气规则检查（ERC）无错
  - 设计规则检查（DRC）无错
  - 丝印无重叠、极性/方向标识清晰
  - 关键网络（电源、地、差分对）已核对

## BOM 与制板输出

- `fabrication/bom.csv` —— 物料清单（见 [bom.csv 模板](fabrication/bom.csv)）
- `fabrication/` 放 Gerber（`.gbr`）、钻孔（`.drl`）、贴片坐标（`.pos`/`.csv`）
- 打样前用免费 Gerber 查看器（如 KiCad GerbView、GerberLogix）复查一遍

## 选型参考

- MCU 最小系统可参考 `../software/bare-metal/` 的 HAL 抽象；
- 无线/ESP 类可参考 `../software/esp-idf/` 或 `../software/arduino/` 的引脚与电源设计。

> 本目录下的 `reference-schematic.svg` 是一个**可读的参考原理图**（电源 + MCU + LED），
> 用于说明本项目板级的典型连接，不是可直接生产的工程文件。
