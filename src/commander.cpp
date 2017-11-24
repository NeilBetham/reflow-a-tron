/*
 * commander.cpp
 *
 * Created: 11/20/2017 1:49:55 AM
 *  Author: nbeth
 */
#include <string.h>
#include <stdio.h>
#include "commander.h"
#include "kernel.h"

Commander::Commander(SerialManager* serial_){
  content_length = 0;
  memset(&incomming_buffer, 0, COMMAND_BUFFER_SIZE);
  handler_count = 0;
  serial = serial_;
}

bool Commander::register_handler(ICommandHandler* handler){
  if(handler_count == MAX_COMMAND_HANDLERS){
    return false;
  }
  
  handlers[handler_count] = handler;
  handler_count++;
  return true;
}

void Commander::on_char_recv(void* byte){
  if(!(content_length < (COMMAND_BUFFER_SIZE - 1))){
    char msg[] = "Command buffer overflow";
    KERN->handle_event(fault, &msg);
    return;
  }
  
  incomming_buffer[content_length] = *((uint8_t*)(byte));
  content_length++;
  
  if(incomming_buffer[content_length - 1] == '\n' || incomming_buffer[content_length - 1] == '\r'){
    incomming_buffer[content_length] = 0;
    process_command();
    content_length = 0;
  }
}

void Commander::on_hunderedms(void* data){
}

void Commander::on_fault(void* data){
}

void Commander::process_command(){
  char total[COMMAND_BUFFER_SIZE] = {0};
  
  memcpy(&total, &incomming_buffer, COMMAND_BUFFER_SIZE);
  
  char* args_ptr = (char*)&total;
  char* command_ptr = strsep(&args_ptr,"|\r\n");
  
  
  for(int i = 0; i < handler_count; i++){
    handlers[i]->handle_command(serial, command_ptr, args_ptr);
  }
}  