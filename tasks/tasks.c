#include "avr/io.h"
#include "../controls/pid.h"
#include "../drivers/spi.h"
#include "../drivers/uart.h"

void onems_task(){
	
}

void tenms_task(){
	
}

void hunderedms_task(){
	run_pid();
}

void fivehunderedms_task(){
	read_from_spi();
	
	writeBytes("HelloWorld\n\r", 13);
}

void ones_task(){
}
