/*
 * commander.cpp
 *
 * Created: 11/20/2017 1:49:55 AM
 *  Author: nbeth
 */ 
#include <stdio.h>
#include <string.h>
#include "commander.h"
#include "kernel.h"

Commander::Commander(){
  content_length = 0;
  memset(&incomming_buffer, 0, COMMAND_BUFFER_SIZE);
  handler_count = 0;
}

void Commander::handle_bytes(uint8_t byte){
  if(!(content_length < COMMAND_BUFFER_SIZE)){
    char msg[] = "Command buffer overflow";
    KERN->handle_event(fault, &msg);
  } else {
    content_length++;
  }
  incomming_buffer[content_length - 1] = byte;
  
  if(incomming_buffer[content_length - 1] == '\n'){
    process_command();
    content_length = 0;
  }
}

void Commander::handle_uart_error(UARTError error){
  char msg[200] = {0};
  snprintf((char*)&msg, 200, "UART Error: %i", error);
  KERN->handle_event(fault, &msg);
}

void Commander::on_hunderedms(void* data){
}

void Commander::process_command(){
  for(int i = 0; i < handler_count; i++){
    handlers[i]->handle_command((const char*)&incomming_buffer);
  }    
}  