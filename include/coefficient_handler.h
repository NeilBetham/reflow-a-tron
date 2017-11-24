/*
 * coefficient_handler.h
 *
 * Created: 11/21/2017 8:30:16 PM
 *  Author: nbeth
 */ 


#ifndef COEFFICIENT_HANDLER_H_
#define COEFFICIENT_HANDLER_H_

#include "i_command_handler.h"
#include "pid.h"
#include "kernel.h"


class CoefficientHandler: public ICommandHandler {
public:
  CoefficientHandler(PID* pid_): pid(pid_) {};
  ~CoefficientHandler() {};
    
  void handle_command(SerialManager* serial, char* command, const char* args);
private:
  PID* pid;
};



#endif /* COEFFICIENT_HANDLER_H_ */