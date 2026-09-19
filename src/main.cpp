/*
 * ATtiny85 Pinout
 *              ┌───────┐
 *         (5)  │1    8 │  (8) VCC
 *   RESET/PB5  │       │  PB2
 *         (3)  │2    7 │  (2) SCK/ADC1
 *  RX/PB3      │       │  SCL
 *         (4)  │3    6 │  (1) MISO/ADC1
 *  TX/PB4      │       │  PB1
 *              │4    5 │  (0) MOSI/ADC0
 *         GND  │       │  LED/PB0
 *              └───────┘
 */

#include <Arduino.h>

#define SENSOR_PIN A1 // Physical Pin 7 (PB2)
#define LED_PIN 0     // Physical Pin 5 (PB0)
#define MOTOR_PIN 1   // Physical Pin 6 (PB1)
#define BUZZER_PIN 3  // Physical Pin 2 (PB3)

volatile int Signal; // holds the incoming raw data
int threshold = 550;
volatile boolean Pulse =
    false; // true when pulse wave is high, false when it's low

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  // 9600 baud is the standard rate
}

void loop() {
  Signal = analogRead(A1);

  if (Signal > threshold) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(MOTOR_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(MOTOR_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }
}
