/*
 * temp_controller.h
 *
 * Created: 11/22/2017 6:27:00 PM
 *  Author: nbeth
 */ 


#ifndef TEMP_CONTROLLER_H_
#define TEMP_CONTROLLER_H_

#include <stdint.h>
#include "i_event_delegate.h"
#include "pid.h"
#include "pwm.h"
#include "reflow_profile.h"


class TempController: public IEventDelegate {
public:
  TempController();
  ~TempController() {};

  void on_tenms(void* data);
  void on_fivehunderedms(void* data);
  void on_fault(void* data);
  
  bool start();
  bool stop();

  ReflowProfile profile;
  PID pid;

private:
  PWM pwm;
  int16_t current_temp;
  int16_t current_setpoint;
  int16_t output_control;
  bool control_enabled;
};


#endif /* TEMP_CONTROLLER_H_ */