/*
 * pwm.h
 *
 * Created: 11/19/2017 9:14:33 PM
 *  Author: nbeth
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <stdint.h>

class PWM {
public:
  PWM(uint8_t* output_register, uint8_t output_pin, uint16_t period, uint16_t duty_cycle): output_register(output_register), output_pin(output_pin), period(period), duty_cycle(duty_cycle), current_count(0) {}; 
  ~PWM();
  
  uint16_t set_duty_cycle(uint16_t duty_cycle);
  uint16_t set_period(uint16_t period);
  
  uint16_t get_duty_cycle();
  uint16_t get_period();
  
  void tick(uint16_t dt);
  
private:
  uint8_t* output_register;
  uint8_t output_pin;
  
  uint16_t period;
  uint16_t duty_cycle;
  
  uint16_t current_count;
};


#endif /* PWM_H_ */