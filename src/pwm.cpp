/*
 * pwm.cpp
 *
 * Created: 11/19/2017 9:39:15 PM
 *  Author: nbeth
 */ 

#include "pwm.h"

PWM::PWM(volatile uint8_t* output_register_, volatile uint8_t* output_datadir_, uint8_t output_pin_, uint16_t period_, uint16_t duty_cycle_){
  output_register = output_register_;
  output_datadir = output_datadir_;
  output_pin = output_pin_;
  
  period = period_;
  duty_cycle = duty_cycle_;
  
  *output_datadir |= (1UL << output_pin);
}

uint16_t PWM::set_duty_cycle(uint16_t duty_cycle_){
  duty_cycle = duty_cycle_;
  return duty_cycle;
}

uint16_t PWM::set_period(uint16_t period_){
  period = period_;
  return period;
}

void PWM::tick(uint16_t dt){
  if(duty_cycle == 0){
    *output_register &= ~(1UL << output_pin);
    return;
  }
  
  if(current_count == 0){
    *output_register |= (1UL << output_pin);
  }
  
  current_count += dt;
  
  if(current_count > duty_cycle && current_count <= period){
    *output_register &= ~(1UL << output_pin);
  }
  
  if(current_count >= period) {
    current_count = 0;
  }
}