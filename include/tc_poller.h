/*
 * tc_poller.h
 *
 * Created: 11/20/2017 10:11:20 PM
 *  Author: nbeth
 */ 


#ifndef TC_POLLER_H_
#define TC_POLLER_H_

#include "i_event_delegate.h"
#include "spi.h"
#include "tc.h"

class TCPoller: public IEventDelegate {
public:
  TCPoller();
  ~TCPoller() {};
  
  void on_fivehunderedms(void* data);
  
private:
  bool faulted;
  SPI spi;
  TempReading temp;
};


#endif /* TC_POLLER_H_ */