/*
 * temp_controller.cpp
 *
 * Created: 11/22/2017 7:01:28 PM
 *  Author: nbeth
 */ 
#include <avr/io.h>
#include "temp_controller.h"

TempController::TempController(){
  pwm = PWM(&PORTA, &DDRA, 0, 1000, 0);
  pid = PID(&current_temp, &output_control, &current_setpoint, 10);
  
  current_temp = 0;
  current_setpoint = 0;
  output_control = 0;
  control_enabled = false;
}

void TempController::on_tenms(void* data){
  pwm.tick(10);
}

void TempController::on_fivehunderedms(void* data){
  if(control_enabled){
    current_setpoint = profile.get_current_setpoint(current_temp);
    if(current_setpoint < 0){
      pwm.set_duty_cycle(0);
      control_enabled = false;
      return;
    }
    
    pid.run();
    pwm.set_duty_cycle(output_control);
  } else {
    pwm.set_duty_cycle(0);
  }
}

void TempController::on_fault(void* data){
  control_enabled = false;
}