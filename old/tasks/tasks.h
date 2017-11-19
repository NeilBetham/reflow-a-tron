#ifndef TASKS_H_
#define TASKS_H_

#include "avr/io.h"
#include "../controls/tc.h"
#include "../controls/pid.h"
#include "../drivers/uart.h"
#include "../drivers/pwm.h"
#include <stdio.h>
#include <stdlib.h>

/* Looping tasks based on time */
void onems_task();
void tenms_task();
void hunderedms_task();
void fivehunderedms_task();
void ones_task();

#endif