/*
 * pid.h
 *
 * Created: 11/19/2017 6:06:14 PM
 *  Author: nbeth
 */ 


#ifndef PID_H_
#define PID_H_

#include <stdint.h>


class PID
{
public:
  PID() {};
	PID(int16_t* input, int16_t* output, int16_t* setpoint, uint16_t dt): input(input), output(output), setpoint(setpoint), prev_input(0), prev_derivative(0), accumulator(0), dt(dt), min(0), max(0), beta(0) {};
	~PID() {};
	void run();
	void set_coef(int32_t kp_, int32_t ki_, int32_t kd_) { kp = kp_; kis = ki_ * dt; kd = kd_; };
  void set_beta(int16_t beta_) { beta = beta_; };
	void set_limits(int16_t min_, int16_t max_) { min = min_; max = max_; };
	uint32_t get_kp() { return kp; };
	uint32_t get_ki() { return kis / dt; };
	uint32_t get_kd() { return kd; };
	
private:
	int16_t* input;
	int16_t* output;
	int16_t* setpoint;

	int16_t prev_input;
  int32_t prev_derivative;
	int32_t accumulator;
  
	int32_t kp;
	int32_t kis;			// Scale then integrate
	int32_t kd;
	int32_t dt;

	int16_t min;
	int16_t max;
  
  int16_t beta;
};


#endif /* PID_H_ */