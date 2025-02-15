// #define PLANO_B 1 // descomentar para ativar

#include <Arduino.h>
#include <Wire.h>
#include "LED.h"
#include "Controle_juiz.h"
#include "Cromo.h"
#include "Sangue_no_olho.h"

// #include "H_bridge_TB6612.hpp"
// #include "config.h"

int juiz_comand;
int ordem_led = 0;
int tempoantigo = 0;
int velocidade = 0;

Led led(19, 4, 5, 100);
controle_juiz controle(23);
Enemy_localization VLs;
Cromo cromo = Cromo();

// Motor motor1 = Motor(AIN1, AIN2, PWMA, STBY, offsetA, 10);
// Motor motor2 = Motor(BIN1, BIN2, PWMB, STBY, offsetB, 10);

void setup()
{
    Serial.begin(112500);
    led.init();
    VLs.init_sensors();
    controle.init();
    cromo.init_cromo();
    Serial.println();
    Serial.println("Eu estou funcionando, to esperando você apertar o botão do controle XD");
}

void loop()
{

    // VLs.get_info();
    // EnemyInfo info = VLs.get_info();
    // Serial.println(info.vl);
    // juiz_comand = 1;

    juiz_comand = controle.read();
    Serial.println(juiz_comand);
    switch (juiz_comand)
    {
    case (0):
        if (ordem_led == 0)
        {
            led.blue();
            velocidade = 0;
        }
        cromo.parar_motor();
        // Serial.println("calma");
        break;

    case (1):
        led.green();
        Serial.println("LUTAR !!!");
        cromo.ataque();
        ordem_led = 1;
        break;
   
    case (2):
        led.red();
        ordem_led = 0;
        // Serial.println("morri");
        cromo.parar_motor();
        break;

    default:
        led.black();
    }

}