#include <Arduino.h>
#include <Wire.h>
#include "LED.h"
#include "Controle_juiz.h"

#include "Sangue_no_olho.h"

#include "H_bridge_TB6612.hpp"
#include "config.h"

int juiz_comand;
int ordem_led = 0;
int tempoantigo = 0;
int velocidade = 0;

Led led(19, 4, 5, 100);
controle_juiz controle(23);
Enemy_localization VLs;

Motor motor1 = Motor(AIN1, AIN2, PWMA, STBY, offsetA, 10);
Motor motor2 = Motor(BIN1, BIN2, PWMB, STBY, offsetB, 10);

void setup()
{
    Serial.begin(112500);
    led.init();
    VLs.init_sensors();
    controle.init();
    Serial.println();
    Serial.println("Eu estou funcionando, to esperando você apertar o botão do controle XD");
}

void loop()
{
    juiz_comand = controle.read();
    VLs.get_info();
    EnemyInfo info = VLs.get_info();
    Serial.println(info.vl);
    switch (juiz_comand)
    {
    case (0):
        if (ordem_led == 0)
        {
            led.blue();
            velocidade = 0;
            motor1.drive(velocidade);
            motor2.drive(velocidade);
        }
        Serial.println("calma");
        /* code */
        break;

    case (1):
        led.green();
        /* code */
        Serial.println("LUTAR !!!");
        if (info.vl == 0)
        {
            motor1.drive(200);
            motor2.drive(200);
        }
        else if (info.vl == 2)
        {
            motor1.drive(-200);
            motor2.drive(-200);
        }
        else if (info.vl == 1)
        {
            motor1.drive(700);
            motor2.drive(-700);
        }
        else
        {
            motor1.drive(150);
            motor2.drive(150);
        }
        ordem_led = 1;
        break;

    case (2):
        led.red();
        ordem_led = 0;
        Serial.println("morri");
        velocidade = 0;
        motor1.drive(velocidade);
        motor2.drive(velocidade);
        break;

    default:
        led.black();
    }
}