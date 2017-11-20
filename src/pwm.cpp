/*
 * pwm.cpp
 *
 * Created: 11/19/2017 9:39:15 PM
 *  Author: nbeth
 */ 

#include "pwm.h"

uint16_t PWM::set_duty_cycle(uint16_t duty_cycle_){
  duty_cycle = duty_cycle_;
  return duty_cycle;
}

uint16_t PWM::set_period(uint16_t period_){
  period = period_;
  return period;
}

void PWM::tick(uint16_t dt){
  current_count += dt;
  if(current_count > duty_cycle){
    *output_register &= ~(1UL << output_pin);
  } else if(current_count >= period) {
    current_count = 0;
    *output_register |= (1UL << output_pin);
  }
}