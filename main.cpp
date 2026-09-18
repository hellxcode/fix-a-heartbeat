#include <Arduino.h>



#define LED_PIN 0


volatile int Signal; // holds the incoming raw data
int threshold = 550;
volatile boolean Pulse = false; // true when pulse wave is high, false when it's low


void setup(){
 pinMode(LED_PIN, OUTPUT);
  // 9600 baud is the standard rate
}


void loop(){
 Signal = analogRead(A1);

 if(Signal > threshold){
   digitalWrite(LED_PIN, HIGH);
 } else{
  digitalWrite(LED_PIN, LOW);
 }
}
