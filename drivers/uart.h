#include "../config.h"
#include "avr/io.h"

void init_uart();
void writeBytes(uint8_t *bytes, uint8_t count);