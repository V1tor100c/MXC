#include "Sangue_no_olho.h"

void Enemy_localization::init_sensors()
{
  sens_dist_lineares.sensorsInit();
}

EnemyInfo Enemy_localization::get_info()
{
  EnemyInfo info;
  sens_dist_lineares.distanceRead();

  // Inicializa com valor máximo
  info.min_distance = 10000;
  info.vl = -1;

  // Coleta distâncias e encontra a mínima
  for (int i = 0; i < number_vls; i++)
  {
    int current_dist = sens_dist_lineares.dist[i];
    info.distances.insert(info.distances.begin() + i, current_dist);

    if (current_dist < info.min_distance)
    {
      info.min_distance = current_dist;
      info.vl = i;
    }
  }

  return info;
}
