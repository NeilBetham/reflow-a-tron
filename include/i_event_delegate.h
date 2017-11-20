/*
 * i_event_delegate.h
 *
 * Created: 11/19/2017 8:32:51 PM
 *  Author: nbeth
 */ 


#ifndef I_EVENT_DELEGATE_H_
#define I_EVENT_DELEGATE_H_

#include "events.h"

class IEventDelegate {
public:
  virtual void on_onems(void* data);
  virtual void on_tenms(void* data);
  virtual void on_hunderedms(void* data);
  virtual void on_fivehunderedms(void* data);
  virtual void on_ones(void* data);
  virtual void on_char_recv(void* data);
  virtual void on_line_recv(void* data);
  virtual void on_fault (void* data);
};

typedef void (IEventDelegate::*Callback)(void* data);
const Callback cb_functions[event_count] = {
  &IEventDelegate::on_onems,
  &IEventDelegate::on_tenms,
  &IEventDelegate::on_hunderedms,
  &IEventDelegate::on_fivehunderedms,
  &IEventDelegate::on_ones,
  &IEventDelegate::on_char_recv,
  &IEventDelegate::on_line_recv,
  &IEventDelegate::on_fault
};

#endif /* I_EVENT_DELEGATE_H_ */