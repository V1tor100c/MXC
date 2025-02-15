#ifndef ENEMY_LOCALIZATION
#define ENEMY_LOCALIZATION

#include "VL53.h"

class Enemy_localization
{
private:
  VL53_sensors sens_dist_lineares;
  float sens_pos_robot[3] = {-45, 0, 45};   // Ângulos dos sensores

public:
  void init_sensors();
  EnemyInfo get_info();
  int number_vls = 3;
};

#endif