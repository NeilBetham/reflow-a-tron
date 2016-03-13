#include "timer.h"
#include "avr/interrupt.h"
#include "avr/io.h"
#include "avr/sleep.h"
#include "../config.h"
#include <stdio.h>

void timer_init(){
	TCCR1A |= 0x00; // Set timer to Clear Timer on Capture mode
	TCCR1B |= MAIN_TASK_LOOP_PRESCALE_SELECT | 0x08;
	OCR1AH = (0xFF00 & MAIN_TASK_LOOP_PERIOD) >> 8;
	OCR1AL = (0x00FF & MAIN_TASK_LOOP_PERIOD);
	TIMSK1 |= 2; // Enable interrupts on capture and compare A
	
	// Enable interrupts
	sei();
}

ISR(TIMER1_COMPA_vect){
	// Disable interrupts
	cli();
	sleep_disable();
}