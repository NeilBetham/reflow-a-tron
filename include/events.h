/*
 * events.h
 *
 * Created: 11/19/2017 8:49:52 PM
 *  Author: nbeth
 */ 


#ifndef EVENTS_H_
#define EVENTS_H_


enum EventType {
  onems,
  tenms,
  hunderedms,
  fivehunderedms,
  ones,
  char_recv,
  line_recv,
  fault,
  event_count
};


#endif /* EVENTS_H_ */