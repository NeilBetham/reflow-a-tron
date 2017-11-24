/*
 * profile_segment.cpp
 *
 * Created: 11/21/2017 7:41:57 PM
 *  Author: nbeth
 */ 
#include "profile_segment.h"
#include "utils.h"

ProfileSegment::ProfileSegment(const ProfileSegment& segment){
  target_temp = segment.target_temp;
  ramp_rate = segment.ramp_rate;
  time_s = segment.time_s;
}

int32_t ProfileSegment::temp_for_time(uint16_t time){
  if(time >= time_s){
    return -1;
  }
  
  if(ramp_rate == 0){
    return target_temp;
  }
  
  return clamp((time * ramp_rate) + start_temp, 0, target_temp);
}