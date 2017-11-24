/*
 * reflow_profile.h
 *
 * Created: 11/21/2017 7:16:48 PM
 *  Author: nbeth
 */ 


#ifndef REFLOW_PROFILE_H_
#define REFLOW_PROFILE_H_

#include <stdint.h>
#include "profile_segment.h"

#define MAX_REFLOW_PROFILE_SEGMENTS 10


class ReflowProfile {
public:
  ReflowProfile(): dt(0), segment_count(0), total_time(0), segment_time(0), segment_index(0), current_segment(0) {};
  ReflowProfile(uint16_t dt): dt(dt), segment_count(0), total_time(0), segment_time(0), segment_index(0), current_segment(0) {};
  ~ReflowProfile() {};
  
  bool add_segment(const ProfileSegment& segment);
  int32_t get_current_setpoint(int16_t current_temp);

  void clear_profile() { segment_count = 0; total_time = 0; segment_index = 0; segment_index = 0; current_segment = 0; };
  void tick();
  
  uint8_t get_segment_count() { return segment_count; };
  
private:
  uint16_t dt;              // ms per tick call
  uint8_t segment_count;
  uint32_t total_time;
  uint16_t segment_time;
  uint8_t segment_index;
  ProfileSegment* current_segment;
  ProfileSegment segments[MAX_REFLOW_PROFILE_SEGMENTS];
};



#endif /* REFLOW_PROFILE_H_ */