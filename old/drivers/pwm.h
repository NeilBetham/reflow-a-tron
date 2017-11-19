#ifndef PWM_H_
#define PWM_H_

#include <stdint.h>
#include "../config.h"
#include "../controls/tc.h"

void init_pwm();
void pwm_tick();
void pwm_set_duty_cycle(uint32_t);
void pwm_set_period(uint32_t);

#endif