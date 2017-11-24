/*
 * clear_handler.h
 *
 * Created: 11/23/2017 8:59:15 PM
 *  Author: nbeth
 */ 


#ifndef CLEAR_HANDLER_H_
#define CLEAR_HANDLER_H_

#include "i_command_handler.h"
#include "reflow_profile.h"


class ClearHandler: public ICommandHandler {
public:
  ClearHandler(ReflowProfile* reflow_profile): reflow_profile(reflow_profile) {};
  
  void handle_command(SerialManager* serial, char* command, const char* args);
  
private:
  ReflowProfile* reflow_profile;
};



#endif /* CLEAR_HANDLER_H_ */