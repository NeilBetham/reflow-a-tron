#include "init.h"
#include <avr/io.h>
#include <avr/wdt.h>
#include "../drivers/timer.h"
#include "../drivers/spi.h"
#include "../drivers/uart.h"
#include "../drivers/pwm.h"

/* Init function for any general initialization that needs to be done */
void init(){
	/* Disable Watchdog*/
	wdt_disable();
	
	/* Set triac control pin to output and low*/
	DDRA  = 0x01;
	PORTA = 0x00;
	
	/* timer init */
	timer_init();
	
	// SPI Init
	init_spi();
	
	// UART Init
	init_uart();
	
	// PWM Init
	init_pwm();
	pwm_set_period(100);
}