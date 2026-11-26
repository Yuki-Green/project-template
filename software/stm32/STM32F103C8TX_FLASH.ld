/* STM32F103C8Tx 链接脚本（Flash 起始 0x0800_0000, 64KB; RAM 0x2000_0000, 20KB）
 * 节选占位，真实工程用 STM32CubeF1 提供的官方版本。
 */
MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 64K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

_estack = 0x20005000;

SECTIONS
{
  .isr_vector : { . = ALIGN(4); KEEP(*(.isr_vector)) . = ALIGN(4); } > FLASH
  .text       : { *(.text*) } > FLASH
  .rodata     : { *(.rodata*) } > FLASH
  .data       : { _sdata = .; *(.data*) _edata = .; } > RAM AT > FLASH
  .bss        : { _sbss = .; *(.bss*) *(COMMON) _ebss = .; } > RAM
}
