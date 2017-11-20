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
	int32_t error = *setpoint - *input;
	
	// Integral
	accumulator += clamp(error * kis, min, max);

	// Derivative
	int32_t derivative = (((int32_t)*input - prev_input) << 16) / dt;

	// Calculate the output
	*output = clamp(((kp * error) >> 15) + ((accumulator) >> 15) + ((kd * derivative) >> 15) , min, max);

	// Setup for next iteration
	prev_input = *input;
}
