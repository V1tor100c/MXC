#ifndef VEL_CONTROLLER
#define VEL_CONTROLLER

class Vel_controller
{
private:

    int get_signal(int vel_old, int vel_target);
    int adjust_vel(int signal, int vel_old, int ganho);
    int saturate(int vel, int vel_target);

public:

    int vel_rampa(int vel, int vel_target, int ganho);
};



#endif