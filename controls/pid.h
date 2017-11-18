#ifndef PID_H_
#define PID_H_

#include "../config.h"
#include "tc.h"
#include <math.h>
#include <stdint.h>


void run_pid();
int32_t get_pid_output();

#endif