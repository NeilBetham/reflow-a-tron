/*
 * event_timer.cpp
 *
 * Created: 11/20/2017 8:51:57 PM
 *  Author: nbeth
 */
#include "event_timer.h"
#include "kernel.h"

void EventTimer::tick(){
  if(loop(1)){
    KERN->handle_event(onems, 0);
  }
  
  if(loop(10)){
    KERN->handle_event(tenms, 0);
  }
  
  if(loop(100)){
    KERN->handle_event(hunderedms, 0);
  }
  
  if(loop(500)){
    KERN->handle_event(fivehunderedms, 0);
  }
  
  if(loop(1000)){
    KERN->handle_event(ones, 0);
    tick_count = 1;
  } else {
    tick_count++;
  }
}

bool EventTimer::loop(uint16_t count){
  return (count % tick_count) == 0;
}