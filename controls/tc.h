#include <stdint.h>
#include "../drivers/spi.h"
#include "../drivers/uart.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef TC_H_
#define TC_H_

typedef union {
	struct {
		uint16_t data;
	};
	struct {
		uint8_t bytes[2];
	};
	struct {
		uint16_t state:1;
		uint16_t device_id:1;
		uint16_t thermo_input:1;
		uint16_t temp_reading:12;
		uint16_t dummy_sign:1;
	};
} temp_reading_t;

volatile temp_reading_t current_temp;

#endif /* TC_H_ */ 