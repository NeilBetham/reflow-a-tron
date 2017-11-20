/*
 * ticker.h
 *
 * Created: 11/19/2017 7:16:20 PM
 *  Author: nbeth
 */ 


#ifndef TICKER_H_
#define TICKER_H_

#include <stdint.h>
#include "i_tickee.h"

#define MAX_DELEGATE_COUNT 10


class Ticker {
public:
  Ticker(uint8_t clock_pre_scale, uint16_t tick_period);
  ~Ticker();
  void start();
  void stop();
  bool register_delegate(ITickee* delegate);

private:
  ITickee* delegates[MAX_DELEGATE_COUNT];
  uint8_t delegate_count;
  bool stopped;
  
};


#endif /* TICKER_H_ */