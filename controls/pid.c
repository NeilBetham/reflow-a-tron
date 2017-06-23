#include "pid.h"

void run_pid(){
	static volatile int16_t set = 100;
	static volatile int16_t actual = 90;
	PIDCalc(set, actual);
}

void PIDCalc(int16_t set_point, int16_t actual_measurement){
	static int32_t prev_error = 0;	// Q2
	static int32_t integral = 0;	// Q16
	int32_t error = 0;				// Q2
	int32_t derivative = 0;			// Q16
	int32_t output = 0;				// Q16
	int32_t kif = (ki * (int32_t)dt) >> 16;  // Q16 - Scale then integrate
	
	// Calculate P, I, D
	// Proportion
	error = set_point - actual_measurement;
	
	// Integral
	
	integral += ((error) * dt) >> 2;
	// Windup guard
	if(integral < -(windup_guard)){
		integral = -(windup_guard);
	}else if(integral > windup_guard){
		integral = windup_guard;
	}
	
	// Derivative
	derivative = ((error - prev_error) << 16) / dt;
	
	// Control output
	pid_control_output = ((kp * error) >> 16) + ((ki * integral) >> 16) + ((kd * derivative) >> 16);
	
	// Setup prev_error for next iteration
	prev_error = error;
}