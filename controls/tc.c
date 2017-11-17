#include "tc.h"

void read_tc(){
	char print_temp[140] = {0};
	read_from_spi(2, &(current_temp.bytes));
	
	volatile uint32_t num = current_temp.temp_reading * (uint32_t)1023;
	
	volatile ldiv_t temp_output = ldiv(num, 4096);
	volatile int32_t fractional = (((int32_t)temp_output.rem * (int32_t)10) / (int32_t)4096);
	
	sprintf(&print_temp, "Current Temp: %li.%i C\n\r", temp_output.quot, fractional);
	print(&print_temp);
}