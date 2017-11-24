/*
 * coefficient_handler.cpp
 *
 * Created: 11/21/2017 8:34:47 PM
 *  Author: nbeth
 */ 
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "coefficient_handler.h"

void CoefficientHandler::handle_command(SerialManager* serial, char* command, const char* args){
  if(strcmp("set_coef", command) != 0){
    return;
  }
  
  uint32_t kp = 0, ki = 0, kd = 0;
  
  uint8_t scanned_args = sscanf(args, "%lu,%lu,%lu", &kp, &ki, &kd);
  
  if(scanned_args != 3){
    serial->nok();
    return;
  }
  
  pid->set_coef(kp, ki, kd);
  
  serial->ok();
}