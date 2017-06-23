#include "spi.h"

void init_spi(){
	// Setup output pins
	DDR_SPI = (1<<DD_CS) | (1<<DD_SCK);
	PORT_SPI |= (1<<DD_CS);
	
	
	// Setup spi controller settings
	SPCR = (
		(1<<SPE)|               // SPI Enable
		//(0<<SPIE)|              // SPI Interupt Enable
		(0<<DORD)|              // Data Order (0:MSB first / 1:LSB first)
		(1<<MSTR)|              // Master/Slave select
		(0<<SPR1)|(1<<SPR0)|    // SPI Clock Rate
		(0<<CPOL)|              // Clock Polarity (0:SCK low / 1:SCK hi when idle)
		(0<<CPHA)				// Clock Phase (0:leading / 1:trailing edge sampling)
	);
}

void read_from_spi(){
	PORT_SPI &= ~(1<<DD_CS);
	for(int i = 0; i < 2; i++){
		SPDR = 0x00;
		while((SPSR & (1<<SPIF)) == 0);
		current_temp.bytes[1 - i] = SPDR;
	}
	PORT_SPI |= (1<<DD_CS);
}
