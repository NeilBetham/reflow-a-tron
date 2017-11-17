#include "../config.h"
#include "avr/io.h"
#include <stdint.h>

#ifndef SPI_H_
#define SPI_H_

#define DDR_SPI		DDRB
#define PORT_SPI	PORTB
#define DD_MOSI		DDB5
#define DD_MISO		DDB6
#define DD_SCK		DDB7
#define DD_CS		DDB4

void init_spi();
void read_from_spi(int number_of_bytes, uint8_t* recv_buffer);
void send_to_spi(int number_of_bytes, uint8_t* recv_buffer, uint8_t* send_buffer);

#endif /* SPI_H_ */