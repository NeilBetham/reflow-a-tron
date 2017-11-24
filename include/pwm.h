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
  PWM() {};
  PWM(volatile uint8_t* output_register, volatile uint8_t* output_datadir, uint8_t output_pin, uint16_t period, uint16_t duty_cycle); 
  ~PWM() {};
  
  uint16_t set_duty_cycle(uint16_t duty_cycle);
  uint16_t set_period(uint16_t period);
  
  uint16_t get_duty_cycle() { return duty_cycle; };
  uint16_t get_period();
  
  void tick(uint16_t dt);
  
private:
  volatile uint8_t* output_register;
  volatile uint8_t* output_datadir;
  uint8_t output_pin;
  
  uint16_t period;
  uint16_t duty_cycle;
  
  uint16_t current_count;
};


#endif /* PWM_H_ */