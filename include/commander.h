/*
 * commander.h
 *
 * Created: 11/20/2017 1:41:00 AM
 *  Author: nbeth
 */ 


#ifndef COMMANDER_H_
#define COMMANDER_H_

#include <stdint.h>
#include "i_command_handler.h"
#include "i_event_delegate.h"

#define COMMAND_BUFFER_SIZE 500
#define MAX_COMMAND_HANDLERS 10

class Commander : public IEventDelegate {
public:
  Commander();
  ~Commander() {};
  void on_char_recv(void* data);
  
  void on_hunderedms(void* data);
  void on_fault(void* data);
  
  bool register_handler(ICommandHandler* handler);
  
private:
  uint16_t content_length;
  char incomming_buffer[COMMAND_BUFFER_SIZE];
  ICommandHandler* handlers[MAX_COMMAND_HANDLERS];
  uint8_t handler_count;
  
  void process_command();
};



#endif /* COMMANDER_H_ */