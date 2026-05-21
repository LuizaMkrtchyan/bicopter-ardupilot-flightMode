#include "Copter.h"

static float target_angle = 18.0f;

static int step=4;

bool ModeBicopter::init(bool ignore_checks)
{

    my_angle_pid(3.0f,0.0f,0.0f,0.0f);
    my_rate_pid(0.5f,0.1f,0.4f,200);

    return true;
}

void ModeBicopter::run(){

float actual_angle = ahrs.get_roll_deg();


if(fabsf(actual_angle - target_angle) < 2.0){

    if(target_angle>0){
        target_angle=-step;
    }
    else{
        step++;
        if(step>18){
            target_angle=0.0f;
        }
        else{
            target_angle=step;
        }
    }
}
if
float angle_error = target_angle - actual_angle;
float target_rate = my_angle_pid.get_pid(angle_error);

target_rate=constrain(target_rate,-100.0f,100.0f);


// RATE LOOP
float actual_rate = degrees(ahrs.get_gyro().x);

float rate_error = target_rate - actual_rate;

float pwm=my_accel_pid.get_pid(rate_error);

pwm=constrain(pwm,-300.0f,300.0f);

//---MOTORS---
float throttle = 1150.0f;

float m1=constrain(throttle-pwm,1000,2000);
float m2=constrain(throttle+pwm,1000,2000);

//---OUTPUT---
if (motors->armed())
{
    SRV_Channels::set_output_pwm_chan(0, (int)m1);
    SRV_Channels::set_output_pwm_chan(1, (int)m2);
}
else
{
    SRV_Channels::set_output_pwm_chan(0, (int)1000);
    SRV_Channels::set_output_pwm_chan(1, (int)1000);   
}

hal.console->printf("target ang:%f\tactual ang:%f\ttarget rate:%f\tactual rate:%f\tpwm:%f\tm1:%f\tm2:%f\n",target_angle,actual_angle,target_rate,actual_rate,pwm,m1,m2);

}

float ModeBicopter::constrain(float value, float min, float max)
{
    return (value < min) ? min :
            (value > max) ? max :
            value;
}


