#include "tc.h"

void read_tc(){
	for(int i = 0; i < 2; i++){
		uint8_t buf = 0;
		read_from_spi(1, &buf);
		current_temp.bytes[1 - i] = buf;
	}
}