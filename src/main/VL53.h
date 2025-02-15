#include <VL53L0X.h>
#include <vector>

#define SDIST_1 16
#define SDIST_2 17
#define SDIST_3 18

#ifndef SENSOR_NUMBER
#define SENSOR_NUMBER 3

// Estrutura para armazenar as informações do inimigo
struct EnemyInfo
{
  int vl;
  int min_distance;
  std::vector<int> closest_sensors;
  std::vector<int> distances;
};

class VL53_sensors
{
private:
  int number_sensor = SENSOR_NUMBER;
  int x_shut_pins[SENSOR_NUMBER] = {SDIST_1, SDIST_2, SDIST_3};
  VL53L0X sensor[SENSOR_NUMBER]; // Tamanho corrigido para 3 sensores
public:
  int dist[3]; // Array corrigido para 3 elementos

  void sensorsInit();
  void distanceRead();
  void printDistances();
};

#endif