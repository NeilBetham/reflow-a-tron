#include "tc.h"

void read_tc(){
	uint8_t buf[2] = {0};
	read_from_spi(2, &buf);
	for(int i = 0; i < 2; i++){
		current_temp.bytes[1 - i] = buf[i];
	}
}