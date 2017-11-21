/*
 * kernel.h
 *
 * Created: 11/19/2017 7:46:49 PM
 *  Author: nbeth
 */ 


#ifndef KERNEL_H_
#define KERNEL_H_

#include <stdint.h>
#include "i_event_delegate.h"
#include "events.h"

#define MAX_EVENT_SUBSCRIPTION_COUNT 20
#define KERN Kernel::instance

typedef struct {
  IEventDelegate* delegate;
  EventType et;
} EventSubscription;

class Kernel {
public:
  Kernel();
  ~Kernel() {};

  bool register_for_event(IEventDelegate* delegate, EventType type);
  void handle_event(EventType type, void* data);
  
  static Kernel* instance;

private:
  EventSubscription subs[MAX_EVENT_SUBSCRIPTION_COUNT];
  uint8_t sub_count;
};



#endif /* KERNEL_H_ */