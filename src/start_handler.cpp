/*
 * start_handler.cpp
 *
 * Created: 11/23/2017 9:42:04 PM
 *  Author: nbeth
 */ 
#include <string.h>
#include "start_handler.h"


void StartHandler::handle_command(SerialManager* serial, char* command, const char* args){
  if(strcmp("start", command) != 0){
    return;
  }    
  
  if(temp_controller->start()){
    serial->ok();
  } else {
    serial->nok();
  }
}