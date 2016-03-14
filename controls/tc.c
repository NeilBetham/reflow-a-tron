#include "tc.h"

typedef struct {
	uint16_t dummy_sign_bit: 1;
	uint16_t temp_reading: 12;
	uint16_t tc_input: 1;
	uint16_t device_id: 1;
	uint16_t state: 1;
} tc_data;

typedef union   {
	uint16_t raw;
	tc_data data;
} tc_reading;

void read_tc(){
	
}