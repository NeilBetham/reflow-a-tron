#include "../config.h"
#include "avr/io.h"

#ifndef SPI_H_
#define SPI_H_

#define DDR_SPI		DDRB
#define PORT_SPI	PORTB
#define DD_MOSI		DDB5
#define DD_MISO		DDB6
#define DD_SCK		DDB7
#define DD_CS		DDB4

void init_spi();
void read_from_spi();

typedef union {
	struct {
		uint8_t bytes[2];
	};
	struct {
		int dummy_sign:1;
		int temp_reading:12;
		int thermo_input:1;
		int device_id:1;
		int state:1;
	};
} temp_reading_t;

temp_reading_t current_temp;

#endif /* SPI_H_ */