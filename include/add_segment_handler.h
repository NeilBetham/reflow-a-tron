/*
 * add_segment_handler.h
 *
 * Created: 11/23/2017 9:21:13 PM
 *  Author: nbeth
 */ 


#ifndef ADD_SEGMENT_HANDLER_H_
#define ADD_SEGMENT_HANDLER_H_

#include "i_command_handler.h"
#include "reflow_profile.h"

class AddSegmentHandler: public ICommandHandler {
public:
  AddSegmentHandler(ReflowProfile* profile): profile(profile) {};
  ~AddSegmentHandler() {};
    
  void handle_command(SerialManager* serial, char* command, const char* args);
  
private:
  ReflowProfile* profile;  
};




#endif /* ADD_SEGMENT_HANDLER_H_ */