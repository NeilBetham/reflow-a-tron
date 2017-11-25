/*
 * pid.cpp
 *
 * Created: 11/19/2017 6:06:03 PM
 *  Author: nbeth
 */ 

#include "pid.h"
#include "utils.h"

void PID::run() {
	// Calculate P I D
	// Proportion
	int32_t error = (int32_t)(*setpoint) - (int32_t)(*input);
	
	// Integral
	accumulator += error * kis;
  accumulator = clamp(accumulator, min, ((int32_t)max << 15));

	// Derivative
	int32_t derivative = (((int32_t)(*input) - prev_input) << 12) / dt;

	// Calculate the output
	*output = clamp(((kp * error) >> 15) + (accumulator >> 15) - ((kd * derivative) >> 15) , min, max);

	// Setup for next iteration
	prev_input = *input;
}
