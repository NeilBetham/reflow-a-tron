/*
 * reflow_profile.cpp
 *
 * Created: 11/21/2017 7:25:00 PM
 *  Author: nbeth
 */ 
#include "reflow_profile.h"

bool ReflowProfile::add_segment(const ProfileSegment& segment){
  if(!(segment_count < MAX_REFLOW_PROFILE_SEGMENTS)){
    return false;
  }
  
  segments[segment_count] = segment;
  segment_count++;
  
  return true;
}

void ReflowProfile::tick(){
  total_time += dt;
  segment_time += dt;
}

int32_t ReflowProfile::get_current_setpoint(uint16_t current_temp){
  // Check if current segment has been initialzied, if not set it now
  if(!current_segment){
    current_segment = &segments[segment_index];
    current_segment->set_start_temp(current_temp);
  }
  
  // Get the temp we should be at for this given time
  int32_t target_temp = current_segment->temp_for_time(segment_time);
  
  // If the segment returns -1 then it is complete
  if(target_temp < 0){
    // Get an estimated amount of time that we should have been executing the new stage for
    uint16_t next_segment_time = segment_time - current_segment->get_time();
    
    // If we have another segment to execute, load it and return it's set point
    if(segment_index < segment_count){
      segment_index++;
      current_segment++;
      
      current_segment->set_start_temp(current_temp);
      target_temp = current_segment->temp_for_time(next_segment_time);
      segment_time = next_segment_time;
      return target_temp;
    } else {
      return -1;
    }
  }
  
  return target_temp;
}