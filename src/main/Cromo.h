// Motor + VLs

#include "Sangue_no_olho.h"

#include "H_bridge_TB6612.hpp"
#include "config.h"

#define DISTANCE_TO_ACCEPT_READ 450 // +- 40 mm fake
#define VEL_VIRAR 200
#define VEL_FRENTE 300

class Cromo
{
private:
    Enemy_localization VLs;

public:
    void init_cromo();
    void ataque();
    void parar_motor();
    Motor motor1 = Motor(AIN1, AIN2, PWMA, STBY, offsetA, 10);
    Motor motor2 = Motor(BIN1, BIN2, PWMB, STBY, offsetB, 10);

    void move(int vel){
        motor1.drive(-vel);
        motor2.drive(-vel);
    }
    void move_direita(int vel){
        motor1.drive(-vel);
        motor2.drive(vel);
    }
    void move_esquerda(int vel){
        motor1.drive(vel);
        motor2.drive(-vel);
    }
    void parar(){
        motor1.drive(0);
        motor2.drive(0);
    }

};

void Cromo::init_cromo()
{
    VLs.init_sensors();
}

void Cromo::ataque()
{

#ifdef PLANO_B

    motor1.drive(200);
    motor2.drive(-200);
    Serial.println("PLANO B: GIRO");

#else

    // Serial.println("PLANO A: ATAQUE");

    EnemyInfo info = VLs.get_info();

    bool accept_distance = info.min_distance < DISTANCE_TO_ACCEPT_READ;
    if(accept_distance){

        if (info.vl == 0)
        {
            // motor1.drive(-200);
            // motor2.drive(200);
            move_direita(VEL_VIRAR);
            Serial.println("Direita");
        }
        else if (info.vl == 2)
        {
            // motor1.drive(200);
            // motor2.drive(-200);
            move_esquerda(VEL_VIRAR);

            Serial.println("Esquerda");
        }
        else if (info.vl == 1)
        {
            // motor1.drive(-700);
            // motor1.drive(-300);
            // motor2.drive(-700);
            // motor2.drive(-300);
            move(VEL_FRENTE);
            Serial.println("Frente");
        }
    }
    else
    {
        motor1.drive(-150);
        motor2.drive(150);
        Serial.println("Vai devagar");
    }

#endif

}

void Cromo::parar_motor()
{
    Serial.println("para para para");
    // motor1.drive(0);
    // motor2.drive(0);
    parar();
}