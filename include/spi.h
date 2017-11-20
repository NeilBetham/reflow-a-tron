/*
 * spi.h
 *
 * Created: 11/19/2017 10:04:38 PM
 *  Author: nbeth
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

class SPI {
public:
  SPI(uint8_t* port, uint8_t* data_dir, uint8_t mosi, uint8_t miso, uint8_t sck, uint8_t cs);
  ~SPI();
  
  void init();
  uint8_t read_bytes(void* buffer, uint8_t count);
  uint8_t write_bytes(void* input_buffer, void* output_buffer, uint8_t count);
  
private:
  uint8_t* port;
  uint8_t* data_dir;
  
  uint8_t mosi;
  uint8_t miso;
  uint8_t sck;
  uint8_t cs;
  
  void cs_enable();
  void cs_disable();
};


#endif /* SPI_H_ */