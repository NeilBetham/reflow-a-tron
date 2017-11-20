/*
 * i_command_handler.h
 *
 * Created: 11/20/2017 2:15:28 AM
 *  Author: nbeth
 */ 


#ifndef I_COMMAND_HANDLER_H_
#define I_COMMAND_HANDLER_H_

class ICommandHandler {
public:
  virtual bool handle_command(const char* command);  
};



#endif /* I_COMMAND_HANDLER_H_ */