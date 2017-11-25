/*
 * temp_controller.cpp
 *
 * Created: 11/22/2017 7:01:28 PM
 *  Author: nbeth
 */ 
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include "temp_controller.h"

TempController::TempController(SerialManager* serial_){
  pwm = PWM(&PORTA, &DDRA, 0, TEMP_CONTROLLER_PWM_PERIOD, 0);
  pid = PID(&current_temp, &output_control, &current_setpoint, 2048);
  profile = ReflowProfile(1);
  
  pid.set_limits(0, TEMP_CONTROLLER_PWM_PERIOD);
  pid.set_coef(32768, 50, 6553);
  
  current_temp = 0;
  current_setpoint = 0;
  output_control = 0;
  control_enabled = false;
  faulted = false;
  
  serial = serial_;
}

void TempController::on_tenms(void* data){
  pwm.tick(10);
}

void TempController::on_fivehunderedms(void* data){
  if(control_enabled && !faulted){
    current_setpoint = profile.get_current_setpoint(current_temp);
    if(current_setpoint < 0){
      current_setpoint = 0;
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
  faulted = true;
  pwm.set_duty_cycle(0);
}

void TempController::on_temp_recv(void* data){
  current_temp = *((int16_t*)data);
}

void TempController::on_ones(void* data){
  if(control_enabled){
    profile.tick();
  }
  
  char msg[500] = {0};
  memset(&msg, 0, 500);
  sprintf(msg, "status|%i,%i,%u\n\r", current_temp, current_setpoint, pwm.get_duty_cycle());
  serial->send((char*)&msg);
  
  memset(&msg, 0, 500);
  if(control_enabled){
    sprintf(msg, "profile|%u,%lu,%u\n\r", profile.get_segment_index(), profile.get_total_time(), profile.get_segement_time());
    serial->send((char*)&msg);
  }
}

bool TempController::start(){
  if(profile.get_segment_count() < 1 || faulted){
    return false;
  }
  
  profile.reset();
  
  control_enabled = true;
  return control_enabled;
}

bool TempController::stop(){
  control_enabled = false;
  return !control_enabled;
}