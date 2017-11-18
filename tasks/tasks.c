#include "tasks.h"

void onems_task(){
	pwm_tick();
}

void tenms_task(){
	
}

void hunderedms_task(){
	
}

void fivehunderedms_task(){
	read_tc();
	run_pid();
	
	pwm_set_duty_cycle(get_pid_output());
	
	char print_temp[140] = {0};
	ldiv_t temp_output = ldiv(current_temp.temp_reading * (uint32_t)1023, 4096);
	int32_t fractional = (((int32_t)temp_output.rem * 10) / (int32_t)4096);
	
	sprintf((char*)&print_temp, "Current Temp: %li.%li C, Current Temp Counts: %i, Current PID Output: %li\n\r", temp_output.quot, fractional, current_temp.temp_reading, get_pid_output());
	print((char*)&print_temp);
}

void ones_task(){
}
