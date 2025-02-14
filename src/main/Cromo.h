// Motor + VLs

#include "Sangue_no_olho.h"

#include "H_bridge_TB6612.hpp"
#include "config.h"



class Cromo
{
private:
    Enemy_localization VLs;

public:
    void init_cromo();
    void ataque();
    Motor motor1 = Motor(AIN1, AIN2, PWMA, STBY, offsetA, 10);
    Motor motor2 = Motor(BIN1, BIN2, PWMB, STBY, offsetB, 10);
};

void Cromo::init_cromo()
{
    VLs.init_sensors();
}

void Cromo::ataque()
{
    #ifdef PLANO_B

    motor1.drive(1000);
    motor2.drive(1000);
    // Serial.println("PLANO B: GIRO");

    #else

    Serial.println("PLANO A: ATAQUE");

    
    EnemyInfo info = VLs.get_info();

    if (info.vl == 0)
    {
        motor1.drive(-200);
        motor2.drive(200);
    }
    else if (info.vl == 2)
    {
        motor1.drive(-200);
        motor2.drive(200);
    }
    else if (info.vl == 1)
    {
        motor1.drive(700);
        motor2.drive(700);
    }
    else
    {
        motor1.drive(150);
        motor2.drive(150);
    }

    #endif
}