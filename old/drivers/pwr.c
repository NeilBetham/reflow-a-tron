#include "pwr.h"
#include <avr/sleep.h>

void sleep(){
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_enable();
	sleep_mode();
}
