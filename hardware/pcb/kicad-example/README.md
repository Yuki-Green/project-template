# KiCad 工程骨架（示例）

这是一个**最小可打开**的 KiCad 工程占位，目的只是让目录结构完整、
新人 clone 后能直接 `File → Open Project` 看到空工程。

> 注意：占位文件不含真实元件/连线，请以 `schematics/` 和 `board/` 的正式工程为准，
> 或把真实 `.kicad_pro / .kicad_sch / .kicad_pcb` 覆盖此处。

## 实际工程建议结构

```
kicad-example/
├── project-template.kicad_pro   # 工程（复制后改名）
├── project-template.kicad_sch   # 原理图
├── project-template.kicad_pcb   # PCB
├── fp-lib-table                 # 封装库表（按需）
└── sym-lib-table                # 符号库表（按需）
```

## 常用命令

- 原理图：`kicad-cli sch edit --input xxx.kicad_sch`
- 导出 Gerber：`kicad-cli pcb export gerbers --output ../fabrication/gerbers/ xxx.kicad_pcb`
- ERC/DRC：在 KiCad GUI 中运行，或用 `kicad-cli` 的检验子命令
