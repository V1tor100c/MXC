#include <VL53L0X.h>

#define SDIST_1 25 //change the pins 
#define SDIST_2 23
#define SDIST_3 13

class VL53_sensors{

private:

  /* data */

public:
  
  int number_sensor = 3; // change this value 
  int x_shut_pins[3] = { SDIST_1, SDIST_2, SDIST_3} ; 
  int dist[1];
  int test = 0;
  int distTest;

  VL53L0X sensor[1];
    
  void sensorsInit(TwoWire &wire);
  int* distanceRead();
  void printDistances();
  void testRead();
};

