/*
 * reset_handler.cpp
 *
 * Created: 11/23/2017 10:31:48 PM
 *  Author: nbeth
 */ 

#include "string.h"
#include "reset_handler.h"

void ResetHandler::handle_command(SerialManager* serial, char* command, const char* args){
  if(strcmp("reset", command) != 0){
    return;
  }
  
  serial->ok();
  leash->reset();
}