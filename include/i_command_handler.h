/*
 * i_command_handler.h
 *
 * Created: 11/20/2017 2:15:28 AM
 *  Author: nbeth
 */ 


#ifndef I_COMMAND_HANDLER_H_
#define I_COMMAND_HANDLER_H_

#include "serial_manager.h"

class ICommandHandler {
public:
  virtual void handle_command(SerialManager* serial, char* command, const char* args) = 0;
};



#endif /* I_COMMAND_HANDLER_H_ */