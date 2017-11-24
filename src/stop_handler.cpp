/*
 * stop_handler.cpp
 *
 * Created: 11/23/2017 9:48:02 PM
 *  Author: nbeth
 */ 
#include <string.h>
#include "stop_handler.h"


void StopHandler::handle_command(SerialManager* serial, char* command, const char* args){
  if(strcmp("stop", command) != 0){
    return;
  }
  
  if(temp_controller->stop()){
    serial->ok();
    } else {
    serial->nok();
  }
}