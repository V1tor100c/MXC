#include <VL53L0X.h> 
#include <vector>

// #define SDIST_1 5 //change the pins 
// #define SDIST_2 23
// #define SDIST_3 13

class VL53_sensors
{
private:
    int number_sensor;
    int* x_shut_pins; // Alterado para ponteiro para os pinos
public:
    std::vector<int> dist;
    int distTest;
    int test = 1;

    std::vector<VL53L0X> sensor;

    // Construtor que aceita número de sensores e os pinos
    VL53_sensors(int num, int* pins) : number_sensor(num), x_shut_pins(pins), dist(num), sensor(num) {}
    
    void sensorsInit();
    void distanceRead();
    void printDistances();
    void testRead();
};
