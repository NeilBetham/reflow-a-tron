#include "avr/io.h"
#include "../controls/pid.h"
#include "../drivers/spi.h"
#include <stdio.h>

void onems_task(){
	
}

void tenms_task(){
	
}

void hunderedms_task(){
	run_pid();
}

void fivehunderedms_task(){
	read_from_spi();
}

void ones_task(){
}
