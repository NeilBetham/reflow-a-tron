/*
 * profile_segment.cpp
 *
 * Created: 11/21/2017 7:41:57 PM
 *  Author: nbeth
 */ 
#include "profile_segment.h"


ProfileSegment::ProfileSegment(const ProfileSegment& segment){
  target_temp = segment.target_temp;
  ramp_rate = segment.ramp_rate;
  time_ms = segment.time_ms;
}

int32_t ProfileSegment::temp_for_time(uint16_t time){
  if(ramp_rate == 0){
    return target_temp;
  }
  
  if(time > time_ms){
    return -1;
  }
  
  return (time / ramp_rate) + start_temp;
}