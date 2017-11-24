/*
 * leash.cpp
 *
 * Created: 11/23/2017 9:57:30 PM
 *  Author: nbeth
 */

#define F_CPU 20000000UL // 20MHz
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "leash.h"


Leash::Leash(){
  MCUSR &= ~(1<<WDRF);
  wdt_disable();
}

void Leash::pet_dog(){
  wdt_reset();
}

void Leash::enable(){
  wdt_enable(WDTO_250MS);
}

void Leash::disable(){
  wdt_disable();
}

void Leash::reset(){
  _delay_ms(300);
}

