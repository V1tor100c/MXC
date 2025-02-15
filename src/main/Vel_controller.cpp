#include "Vel_controller.hpp"

int Vel_controller::get_signal(int vel_old, int vel_target){

    int signal = (vel_old < vel_target)? 1 : -1;
    return signal;
}

int Vel_controller::adjust_vel(int signal, int vel_old, int ganho){
    return vel_old + (ganho * signal);
}

int Vel_controller::saturate(int vel, int vel_target){
    if (vel > vel_target && vel_target > 0){
        vel = vel_target;
    }
    else if (vel < vel_target && vel_target < 0){
        vel = vel_target;
    }
    return vel;
}

int Vel_controller::vel_rampa(int vel, int vel_target, int ganho){
    

    if(vel == vel_target) return vel;
        
    
    int signal = get_signal(vel, vel_target);
    int vel_new = adjust_vel(signal, vel, ganho);
    int vel_saturated = saturate(vel_new, vel_target);
    
    return vel_saturated;
}