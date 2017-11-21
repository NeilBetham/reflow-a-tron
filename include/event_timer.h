/*
 * event_timer.h
 *
 * Created: 11/20/2017 8:45:46 PM
 *  Author: nbeth
 */ 


#ifndef EVENT_TIMER_H_
#define EVENT_TIMER_H_

#include "i_tickee.h"
#include <stdint.h>

class EventTimer: public ITickee {
public:
  EventTimer(): tick_count(1) {};
  ~EventTimer() {};
  void tick();
  
private:
  bool loop(uint16_t count);

  uint16_t tick_count;
};



#endif /* EVENT_TIMER_H_ */