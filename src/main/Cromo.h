// Motor + VLs

#include "Sangue_no_olho.h"

#include "H_bridge_TB6612.hpp"
#include "config.h"
#include "Vel_controller.hpp"

#define DISTANCE_TO_ACCEPT_READ 450 // +- 40 mm fake
#define VEL_CURVA_RAP 200
#define VEL_CURVA_DEV 100
#define VEL_VIRAR 200
// #define VEL_FRENTE 300
#define VEL_FRENTE 700

#define GANHO_RAMPA 10


class Cromo
{
private:
    Enemy_localization VLs;
    Vel_controller vel_controller = Vel_controller();

public:
    void init_cromo();
    void ataque();
    void parar_motor();
    Motor motor_esquerda = Motor(AIN1, AIN2, PWMA, STBY, offsetA, 10);
    Motor motor_direita = Motor(BIN1, BIN2, PWMB, STBY, offsetB, 10);
    int vel = 0;
    int vel_target = 0;
    bool trigger_rampa = false;

    void move(int vel)
    {
        motor_esquerda.drive(-vel);
        motor_direita.drive(-vel);
    }
    void move_direita(int vel_dir, int vel_esq)
    {
        motor_esquerda.drive(-vel_esq);
        motor_direita.drive(vel_dir);
    }
    void move_esquerda(int vel_dir, int vel_esq)
    {
        motor_esquerda.drive(vel_esq);
        motor_direita.drive(-vel_dir);
    }
    void gira_direita(int vel)
    {
        motor_esquerda.drive(-vel);
        motor_direita.drive(vel);
    }
    void gira_esquerda(int vel)
    {
        motor_esquerda.drive(vel);
        motor_direita.drive(-vel);
    }
    void parar()
    {
        motor_esquerda.drive(0);
        motor_direita.drive(0);
    }
    void girar()
    {
        motor_esquerda.drive(-150);
        motor_direita.drive(150);
    }
};

void Cromo::init_cromo()
{
    VLs.init_sensors();
}

void Cromo::ataque()
{

#ifdef PLANO_B

    motor_esquerda.drive(200);
    motor_direita.drive(-200);
    Serial.println("PLANO B: GIRO");

#else

    // Serial.println("PLANO A: ATAQUE");

    EnemyInfo info = VLs.get_info();

    bool accept_distance = info.min_distance < DISTANCE_TO_ACCEPT_READ;
    if (accept_distance)
    {

        if (info.vl == 0)
        {
            // motor_esquerda.drive(-200);
            // motor_direita.drive(200);
            gira_direita(VEL_VIRAR);
            Serial.println("Direita");
        }
        else if (info.vl == 2)
        {
            // motor_esquerda.drive(200);
            // motor_direita.drive(-200);
            gira_esquerda(VEL_VIRAR);
            Serial.println("Esquerda");
        }
        else if (info.vl == 1)
        {
            if(trigger_rampa == false)
            {
                trigger_rampa = true;
                vel = 0;
            }
            // motor_esquerda.drive(-700);
            // motor_esquerda.drive(-300);
            // motor_direita.drive(-700);
            // motor_direita.drive(-300);
            // move(VEL_FRENTE);
            vel = vel_controller.vel_rampa(vel, VEL_FRENTE, GANHO_RAMPA);
            Serial.println(vel);
            move(vel);

            Serial.println("Frente");
        }
    }
    else
    {
        // motor_esquerda.drive(-150);
        // motor_direita.drive(150);
        girar();
        Serial.println("Gira");
    }

    // reset vars
    if(info.vl != 1) trigger_rampa = false;

#endif
}

void Cromo::parar_motor()
{
    Serial.println("para para para");
    // motor1.drive(0);
    // motor2.drive(0);
    parar();
}