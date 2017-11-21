/*
 * spi.cpp
 *
 * Created: 11/19/2017 10:04:30 PM
 *  Author: nbeth
 */ 
#include "spi.h"
#include "avr/io.h"


SPI::SPI(){
  port = &PORTB;
  data_dir = &DDRB;
  mosi = DDB5;
  miso = DDB6;
  sck = DDB7;
  cs = DDB4;
  
  // Configure data direction on specified port
  *data_dir |= (
    (1UL << cs) |
    (1UL << sck) |
    (1UL << mosi)
  );
  
  PORTB |= (1UL << cs);
  
  // Configure SPI interface
  SPCR = (
    (1 << SPE) |               // SPI Enable
    (0 << DORD) |              // Data Order (0:MSB first / 1:LSB first)
    (1 << MSTR) |              // Master/Slave select
    (0 << SPR1) | (1 << SPR0) |    // SPI Clock Rate
    (0 << CPOL)|              // Clock Polarity (0:SCK low / 1:SCK hi when idle)
    (0 << CPHA)				// Clock Phase (0:leading / 1:trailing edge sampling)
  );
  
  SPSR = (
    (1UL << SPI2X)
  );
}

uint8_t SPI::read_bytes(void* buffer, uint8_t count){
  uint8_t buf[count] = {0};
  return write_bytes((void*)buf, buffer, count);
}

uint8_t SPI::write_bytes(void* input_buffer, void* out_buffer, uint8_t count){
  uint8_t cycles = 0;
  cs_enable();
  for(int i = 0; i < count; i++){
    SPDR = ((uint8_t*)input_buffer)[i];
    while((SPSR & (1UL << SPIF)) == 0);
    ((uint8_t*)out_buffer)[i] = SPDR;
    cycles++;
  }
  cs_disable();
  return cycles;
}

void SPI::cs_enable(){
  *port &= ~(1UL << cs);
}

void SPI::cs_disable(){
  *port |= (1UL << cs);
}