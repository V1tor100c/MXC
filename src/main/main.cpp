#include <Arduino.h>
#include "MX0.h"
#include "LED.h"
#include "Controle_juiz.h"

int juiz_comand;
int ordem_led = 0;
int tempoantigo = 0;

Led led(26, 4, 5, 100);
controle_juiz controle(34);

MX0 razoes;

void setup(){   
    Serial.begin(112500);

    robo_speed.angular = 0 ;
    robo_speed.linear = 0 ;
    robo_moviment.init();
    
    razoes.init();robot_speed robo_speed;

// VL53_sensors vltest;
    led.init();

    controle.init();
    Serial.println();
    Serial.println("Eu estou funcionando, to esperando você apertar o botão do controle XD");
    
}

void loop(){
    
    juiz_comand = controle.read();
    juiz_comand = 1;
    // Serial.print("JC ");
    // Serial.print(juiz_comand);
    // Serial.print(" ");

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

        robo_speed = razoes.process();
        

        /* code */
        ordem_led = 1;
        break;
    
     case (2):
        led.red();
        // robo_speed.angular = 0 ;
        // robo_speed.linear = 0 ;
        ordem_led = 0;
        break;

     default:
        led.black();
    }
}