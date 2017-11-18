#include "pid.h"

static int32_t pid_control_output = 0;

int32_t PIDCalc(int16_t, int16_t);

void run_pid(){
	static volatile int16_t set = 400;
	pid_control_output = PIDCalc(set, current_temp.temp_reading);
}

int32_t clamp(int32_t input, int32_t min, int32_t max){
	if(input >= max){
		return max;
	} else if(input <= min){
		return min;
	} else {
		return input;
	}
}

int32_t PIDCalc(int16_t set_point, int16_t actual_measurement){
	static int32_t prev_actual = 0;
	static int32_t integral = 0;
	int32_t error = 0;
	int32_t derivative = 0;
	int32_t kif = ((int32_t)ki * dt) >> 16;  // Scale then integrate
	int32_t output = 0;
	
	// Calculate P, I, D
	// Proportion
	error = set_point - actual_measurement;
	
	// Integral
	integral += (error * kif);

	// Windup guard
	integral = clamp(integral, -windup_guard, windup_guard);
	
	// Derivative
	derivative = ((actual_measurement - prev_actual) << 16) / dt;
	
	// Control output
	output = clamp(((kp * error) >> 15) + (integral >> 15) + ((kd * derivative) >> 15), 0, 100);
	
	// Setup prev_actual for next iteration
	prev_actual = actual_measurement;
	
	return output;
}

int32_t get_pid_output(){
	return pid_control_output;
}