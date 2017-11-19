#include "uart.h"

void init_uart(){
	// Configure the baud rate
	UBRR0 = 129;  // 9600 Buad

	
	// Enable the receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	// Set Fame format
	UCSR0C = (1<<UCSZ00)|(1<<UCSZ01);
}

void writeBytes(uint8_t *bytes, uint8_t count){
	while(!(UCSR0A & (1<<UDRE0)));
	for(int index = 0; index < count; index++){
		UDR0 = bytes[index];
		while(!(UCSR0A & (1<<UDRE0)));
	}
}

void print(char* string){
	while(!(UCSR0A & (1<<UDRE0)));
	for(int i = 0; string[i] != 0; i++){
		UDR0 = string[i];
		while(!(UCSR0A & (1<<UDRE0)));
	}
}

void handleData(){
	
}