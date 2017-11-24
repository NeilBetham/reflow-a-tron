/*
 * clear_handler.cpp
 *
 * Created: 11/23/2017 8:59:27 PM
 *  Author: nbeth
 */ 
#include <string.h>
#include "clear_handler.h"

void ClearHandler::handle_command(SerialManager* serial, char* command, const char* args){
  if(strcmp("clear_profile", command) != 0){
    return;
  }
  
  reflow_profile->clear_profile();
  serial->ok();
}