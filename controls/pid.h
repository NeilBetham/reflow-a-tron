#include "../config.h"
#include <math.h>
#include <stdint.h>

#ifndef PID_H_
#define PID_H_

static volatile int32_t pid_control_output = 0;

void run_pid();

#endif