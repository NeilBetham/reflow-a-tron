/*
 * reset_handler.h
 *
 * Created: 11/23/2017 9:48:46 PM
 *  Author: nbeth
 */ 


#ifndef RESET_HANDLER_H_
#define RESET_HANDLER_H_

#include "i_command_handler.h"
#include "leash.h"

class ResetHandler: public ICommandHandler {
public:
  ResetHandler(Leash* leash): leash(leash) {};
  ~ResetHandler() {};
  
  void handle_command(SerialManager* serial, char* command, const char* args);
  
private:
  Leash* leash;
};




#endif /* RESET_HANDLER_H_ */