/*
 * profile_segment.h
 *
 * Created: 11/21/2017 7:41:34 PM
 *  Author: nbeth
 */ 


#ifndef PROFILE_SEGMENT_H_
#define PROFILE_SEGMENT_H_

#include <stdint.h>


class ProfileSegment {
  public:
  ProfileSegment(): target_temp(0), ramp_rate(0), time_ms(0), start_temp(0) {};
  ProfileSegment(const ProfileSegment& segment);
  ProfileSegment(int32_t temp_target, uint16_t ramp_rate, uint16_t time_ms): target_temp(temp_target), ramp_rate(ramp_rate), time_ms(time_ms), start_temp(0) {};
  ~ProfileSegment();
  
  uint16_t get_target_temp() { return target_temp; };
  uint16_t get_ramp_rate() { return ramp_rate; };
  uint16_t get_time() { return time_ms; };
  
  int32_t set_start_temp(uint16_t start_temp_) { start_temp = start_temp_; return start_temp; };
  
  int32_t temp_for_time(uint16_t time);
  
  private:
  int32_t target_temp;
  uint16_t ramp_rate;     // ms per C
  uint16_t time_ms;
  
  uint16_t start_temp;
};



#endif /* PROFILE_SEGMENT_H_ */