/*
 * stop_handler.h
 *
 * Created: 11/23/2017 9:47:09 PM
 *  Author: nbeth
 */ 


#ifndef STOP_HANDLER_H_
#define STOP_HANDLER_H_

#include "i_command_handler.h"
#include "temp_controller.h"

class StopHandler: public ICommandHandler {
  public:
  StopHandler(TempController* temp_controller): temp_controller(temp_controller) {};
  ~StopHandler() {};
  
  void handle_command(SerialManager* serial, char* command, const char* args);
  
  private:
  TempController* temp_controller;
};


#endif /* STOP_HANDLER_H_ */