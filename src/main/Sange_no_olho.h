#include "VL53.h"

class Enemy_localization {
private:
    VL53_sensors sens_dist_lineares;
    float sens_pos_robot[3] = {-90, 180, 90}; // Ângulos dos sensores
    const float similarity_threshold = 50.0; // Margem de similaridade em mm

public:
    void init_sensors(TwoWire &wire);
    EnemyInfo get_info();
};

void Enemy_localization::init_sensors(TwoWire &wire) {
    sens_dist_lineares.sensorsInit(wire);
}

EnemyInfo Enemy_localization::get_info() {
    EnemyInfo info;
    sens_dist_lineares.distanceRead();

    // Inicializa com valor máximo
    info.min_distance = 10000;
    info.distances.resize(3);

    // Coleta distâncias e encontra a mínima
    for (int i = 0; i < 3; i++) {
        float current_dist = sens_dist_lineares.dist[i];
        info.distances[i] = current_dist;

        if (current_dist < info.min_distance) {
            info.min_distance = current_dist;
        }
    }

    // Verifica quais sensores estão na faixa de similaridade
    for (int i = 0; i < 3; i++) {
        float diff = abs(info.distances[i] - info.min_distance);
        if (diff <= similarity_threshold) {
            info.closest_sensors.push_back(i);
        }
    }

    return info;
}
