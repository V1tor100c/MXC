
// #include "mpu.h"
#include <Arduino.h>
// #include <VL53L0X.h> 
#include "VL53_sensors.hpp"


#define SCL_SDIST 22
#define SDA_SDIST 21

// XSHUT, uma porta por sensor 
#define SDIST_1 16  //25
#define SDIST_2 17
#define SDIST_3 18

#define N_SENSOR 3
int x_shut_pins[N_SENSOR] = {SDIST_1, SDIST_2, SDIST_3};

VL53_sensors sensores(N_SENSOR, x_shut_pins);

void setup(){

  Serial.begin(115200);

  sensores.sensorsInit();

}


void loop(){ 
  sensores.testRead();
 /*
  sensores.distanceRead();


  for (uint8_t i = 0; i < N_SENSOR; i++){

       Serial.print(" ");
       Serial.print(String(i));
       Serial.print(" ");
       Serial.print(sensores.dist[i]);

  }
      Serial.println("\t\t");
*/
}   

