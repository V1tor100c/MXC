#include <Arduino.h>
/*
#include "refletancia.h"

// altere o valor 2700 de acordo com o valor de referência entre branco e preto

#define rgt_front_pin 39
#define lft_front_pin 36

float read_sensor_rgt;
float read_sensor_lft;
bool border_rgt;
bool border_lft;

refletancia rgt_front(rgt_front_pin, 2700);
refletancia lft_front(lft_front_pin, 2700);

void setup(){

    rgt_front.init();
    lft_front.init();
    Serial.begin(112500);
}



void loop(){

    read_sensor_rgt = rgt_front.read();
    read_sensor_lft = lft_front.read();

    border_rgt = rgt_front.detect_border();
    border_lft = lft_front.detect_border();

    Serial.print(read_sensor_rgt);
    Serial.print(", ");
    Serial.print(read_sensor_lft);

    Serial.print(", ");
    Serial.print(border_rgt);
    Serial.print(", ");
    Serial.print(border_lft);
    Serial.println("\t");
    // delay(1000);   
}*/

int nivel_sinal1 = 0;
int nivel_sinal2 = 0;
int nivel_sinal3 = 0;

int pino_sensor1 = 34;
int pino_sensor2 = 39;
int pino_sensor3 = 36;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  //Leitura do sensor
  nivel_sinal1 = analogRead(pino_sensor1);
  nivel_sinal2 = analogRead(pino_sensor2);
  nivel_sinal3 = analogRead(pino_sensor3);

  //Envia os dados para o serial monitor
  // Serial.print("Nivel 1: ");
  // Serial.println(nivel_sinal1);
  //Teste o nivel de sinal e acende o led
  if (nivel_sinal1 < 1000)
  {
    Serial.println("Perto 1:");
    Serial.println(nivel_sinal1);
  }
  else
  {
    Serial.print("Longe 1:");
    Serial.println(nivel_sinal1);
  }
  
  // Serial.print("Nivel 2: ");
  // Serial.println(nivel_sinal2);
  //Teste o nivel de sinal e acende o led
  if (nivel_sinal2 < 1000)
  {
    Serial.println("Perto 2 :");
    Serial.println(nivel_sinal2);
  }
  else
  {
    Serial.print("Longe 2:");
    Serial.println(nivel_sinal2);
  }

  // Serial.print("Nivel 3: ");
  // Serial.println(nivel_sinal3);
  //Teste o nivel de sinal e acende o led
  if (nivel_sinal3 < 1000)
  {
    Serial.print("Perto 3:");
    Serial.println(nivel_sinal3);
  }
  else
  {
    Serial.print("Longe 3:");
    Serial.println(nivel_sinal3);
  }
  Serial.println("");
  //Aguarda 500 ms e reinicia o processo
  delay(1000);
}