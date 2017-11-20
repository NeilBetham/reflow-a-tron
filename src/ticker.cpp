/*
 * ticker.cpp
 *
 * Created: 11/19/2017 7:16:08 PM
 *  Author: nbeth
 */ 
#include "ticker.h"
#include "utils.h"
#include <avr/interrupt.h>
#include <avr/sleep.h>


Ticker::Ticker(uint8_t clock_pre_scale, uint16_t tick_period){
  // Setup Timer A peripheral
  TCCR1A |= 0x00;
  TCCR1B |= clock_pre_scale | 0x08;
  OCR1AH = (0xFF00 & tick_period) >> 8;
  OCR1AL = (0x00FF & tick_period);

  delegate_count = 0;
  stopped = false;
}

void Ticker::start(){
  // Enable interrupts on capture and compare A
  TIMSK1 |= (1UL << 2);

  // Clear stopped flag
  stopped = false;

  // Loop through delegates
  while(!stopped){
    for(int i = 0; i < delegate_count; i++){
      delegates[i]->tick();
    }
    sleep();
  }
}

void Ticker::stop(){
  // Disable interrupts on capture and compare A
  TIMSK1 &= ~(1UL << 2);
  stopped = false;
}

bool Ticker::register_delegate(ITickee* delegate){
  if(delegate_count < MAX_DELEGATE_COUNT){
    delegates[delegate_count] = delegate;
    delegate_count++;
    return true;
  } else {
    return false;
  }
}

ISR(TIMER1_COMPA_vect){
  // Restart the processor
  sleep_disable();
}
