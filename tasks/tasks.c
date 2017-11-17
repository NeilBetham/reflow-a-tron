#include "avr/io.h"
#include "../controls/pid.h"
#include "../controls/tc.h"
#include "../drivers/uart.h"

void onems_task(){
	
}

void tenms_task(){
	
}

void hunderedms_task(){
	run_pid();
}

void fivehunderedms_task(){
	read_tc();
}

void ones_task(){
}
