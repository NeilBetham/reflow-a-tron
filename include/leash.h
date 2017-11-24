/*
 * leash.h
 *
 * Created: 11/23/2017 9:55:06 PM
 *  Author: nbeth
 */ 


#ifndef LEASH_H_
#define LEASH_H_

#include <stdint.h>
#include "i_event_delegate.h"

class Leash: public IEventDelegate{
public:
  Leash();
  ~Leash() {};
  
  void on_tenms(void* data) { pet_dog(); };
  
  void pet_dog();
  void reset();
  
  void enable();
  void disable();
  
private:
  uint8_t time_setting;
};



#endif /* LEASH_H_ */