/*
 * start_handler.h
 *
 * Created: 11/23/2017 9:34:35 PM
 *  Author: nbeth
 */ 


#ifndef START_HANDLER_H_
#define START_HANDLER_H_

#include "i_command_handler.h"
#include "temp_controller.h"

class StartHandler: public ICommandHandler {
public:
  StartHandler(TempController* temp_controller): temp_controller(temp_controller) {};
  ~StartHandler() {};
  
  void handle_command(SerialManager* serial, char* command, const char* args);
  
private:
  TempController* temp_controller;
};


#endif /* START_HANDLER_H_ */