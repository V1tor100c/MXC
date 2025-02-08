#include <Arduino.h>

#define pin_led 2

void setup(){
    Serial.begin(9600);
    pinMode(pin_led, OUTPUT);
}

void loop(){
    digitalWrite(pin_led, HIGH);
    Serial.println("Led ligado.");
    delay(500);

    digitalWrite(pin_led, LOW);
    Serial.println("Led desligado.");
    delay(500);
}