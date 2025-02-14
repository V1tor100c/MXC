#include <VL53L0X.h>
#include <vector>

#define SDIST_1 25
#define SDIST_2 23
#define SDIST_3 13

// Estrutura para armazenar as informações do inimigo
struct EnemyInfo {
    float min_distance;
    std::vector<int> closest_sensors;
    std::vector<float> distances;
};

class VL53_sensors {
private:
    int number_sensor = 3;
    int x_shut_pins[3] = {SDIST_1, SDIST_2, SDIST_3};
    VL53L0X sensor[3];  // Tamanho corrigido para 3 sensores
public:
    int dist[3];  // Array corrigido para 3 elementos
    
    void sensorsInit(TwoWire &wire);
    void distanceRead();
    void printDistances();
};