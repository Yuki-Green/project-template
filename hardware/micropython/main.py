"""
Raspberry Pi Pico (MicroPython) 最小示例：板载 LED 闪烁。

烧录方式：
  1. 按住 BOOTSEL 接上 USB，Pico 变成 U 盘
  2. 复制 firmware/uf2 进去
  3. 把本文件保存为 main.py 复制到 Pico
  或直接用 Thonny / mpremote 运行：
      mpremote run main.py
"""

from machine import Pin
import time

LED = Pin(25, Pin.OUT)  # Pico 板载 LED 在 GPIO25


def main():
    while True:
        LED.toggle()
        print("toggle", time.ticks_ms())
        time.sleep(0.5)


if __name__ == "__main__":
    main()
