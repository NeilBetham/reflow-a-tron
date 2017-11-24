/*
 * add_segment_handler.cpp
 *
 * Created: 11/23/2017 9:21:27 PM
 *  Author: nbeth
 */ 
#include <string.h>
#include <stdio.h>
#include "add_segment_handler.h"


void AddSegmentHandler::handle_command(SerialManager* serial, char* command, const char* args){
  if(strcmp("add_segment", command) != 0){
    return;
  }
  
  int32_t target_temp = 0;
  uint16_t ramp_rate = 0;
  uint16_t time_ms = 0;
  
  uint8_t scanned_args = sscanf(args, "%li,%u,%u", &target_temp, &ramp_rate, &time_ms);
  
  if(scanned_args != 3){
    serial->nok();
    return;
  }
  
  ProfileSegment new_segment = ProfileSegment(target_temp, ramp_rate, time_ms);
  if(profile->add_segment(new_segment)){
    serial->ok();
  } else {
    serial->nok();
  }
}