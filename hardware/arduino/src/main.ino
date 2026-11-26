/*
 * Arduino / ESP32 最小示例：板载 LED 闪烁 + 串口打印。
 * 编译：Arduino IDE 或 `platformio run`（见 platformio.ini）
 */

#define LED_PIN 2        // ESP32 板载 LED 常见引脚；Arduino Uno 用 13
#define BAUD_RATE 115200

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(BAUD_RATE);
    while (!Serial) { /* 等待串口就绪（部分板子需要） */ }
    Serial.println("Hardware template booted.");
}

void loop()
{
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED on");
    delay(500);

    digitalWrite(LED_PIN, LOW);
    Serial.println("LED off");
    delay(500);
}
