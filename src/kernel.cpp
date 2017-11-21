/*
 * kernel.cpp
 *
 * Created: 11/19/2017 7:46:38 PM
 *  Author: nbeth
 */ 
#include "kernel.h"

Kernel* Kernel::instance;

Kernel::Kernel(){
  sub_count = 0;
  Kernel::instance = this;
}

bool Kernel::register_for_event(IEventDelegate* delegate, EventType type){
  if(sub_count < MAX_EVENT_SUBSCRIPTION_COUNT){
    subs[sub_count].delegate = delegate;
    subs[sub_count].et = type;
    sub_count++;
    return true;
  } else {
    return false;
  }
}

void Kernel::handle_event(EventType type, void* data){
  for(int i = 0; i < sub_count; i++){
    if(subs[i].et == type){
      (subs[i].delegate->*cb_functions[type])(data);
    }
  }
}
