#ifndef UART_H_
#define UART_H_

#include "../config.h"
#include "avr/io.h"

void init_uart();
void writeBytes(uint8_t *bytes, uint8_t count);
void print(char* string);

#endif