#include <Arduino.h>
#include <Wire.h>
#include "LED.h"
#include "Controle_juiz.h"

int juiz_comand;
int ordem_led = 0;
int tempoantigo = 0;

Led led(19, 4, 5, 100);
controle_juiz controle(23);

void setup(){   
    Serial.begin(112500);
    led.init();
    controle.init();
    Serial.println();
    Serial.println("Eu estou funcionando, to esperando você apertar o botão do controle XD");
}

void loop(){    
    juiz_comand = controle.read();

    switch (juiz_comand)
    {
    case (0):
        if (ordem_led == 0){
            led.blue();
        }
            /* code */
        break;

    case (1):
        led.green();
        /* code */
        // LUTAR !!!
        ordem_led = 1;
        break;
    
    case (2):
        led.red();
        ordem_led = 0;
        break;

    default:
        led.black();
    }
}