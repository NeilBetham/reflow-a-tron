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

temp_reading_t current_temp;

#endif /* SPI_H_ */