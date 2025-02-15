#include "VL53_sensors.hpp"

void VL53_sensors::sensorsInit()
{

  // Iniciando o endereçamento dos sensores
  Wire.begin();

  for (uint8_t i = 0; i < number_sensor; i++)
  {
    pinMode(x_shut_pins[i], OUTPUT);
    digitalWrite(x_shut_pins[i], LOW);
  }

  for (uint8_t i = 0; i < number_sensor; i++)
  {
    pinMode(x_shut_pins[i], INPUT);
    sensor[i].init(true);
    sensor[i].setAddress((uint8_t)0x21 + i); // endereço do sensor 1
    sensor[i].setTimeout(40);
  }
}

void VL53_sensors::distanceRead()
{

  for (uint8_t i = 0; i < number_sensor; i++)
  {
    dist[i] = sensor[i].readRangeSingleMillimeters();
  }
}

void VL53_sensors::printDistances()
{

  for (uint8_t i = 0; i < number_sensor; i++)
  {

    Serial.print(" ");
    Serial.print(String(i));
    Serial.print(" ");
    Serial.print(dist[i]);

    Serial.println("\t\t");
  }
}

void VL53_sensors::testRead()
{
/*
  test = 0;
  distTest = sensor[test].readRangeSingleMillimeters();
  Serial.print("Serial.printalor do VL ");
  Serial.print(test);
  Serial.print(": ");
  Serial.println(distTest);

  test = 1;
  distTest = sensor[test].readRangeSingleMillimeters();
  Serial.print("Serial.printalor do VL ");
  Serial.print(test);
  Serial.print(": ");
  Serial.println(distTest);
*/
  test = 1;
  distTest = sensor[test].readRangeSingleMillimeters();
  Serial.print("Serial.printalor do VL ");
  Serial.print(test);
  Serial.print(": ");
  Serial.println(distTest);

  // delay(600);
}