#include "avr/io.h"
#include "../controls/pid.h"
#include "../controls/tc.h"
#include "../drivers/uart.h"
#include <stdio.h>
#include <stdlib.h>

void onems_task(){
	
}

void tenms_task(){
	
}

void hunderedms_task(){
	
}

void fivehunderedms_task(){
	read_tc();
	run_pid();
	
	char print_temp[140] = {0};
	ldiv_t temp_output = ldiv(current_temp.temp_reading * (uint32_t)1023, 4096);
	int32_t fractional = (((int32_t)temp_output.rem * 10) / (int32_t)4096);
	
	sprintf((char*)&print_temp, "Current Temp: %li.%li C\n\r", temp_output.quot, fractional);
	print((char*)&print_temp);
}

void ones_task(){
}
