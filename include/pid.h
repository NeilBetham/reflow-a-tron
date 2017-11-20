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
	PID(int16_t* input, int16_t* output, int16_t* setpoint, uint16_t dt): input(input), output(output), setpoint(setpoint), prev_input(0), accumulator(0), dt(dt), min(0), max(0) {};
	~PID();
	void run();
	void set_coef(uint32_t kp_, uint32_t ki_, uint32_t kd_, uint16_t dt_) { kp = kp_; kis = ki_ * dt; kd = kd_; dt = dt_;};
	void set_limits(int16_t min_, int16_t max_) { min = min_; max = max_; };
	uint32_t get_kp() { return kp; };
	uint32_t get_ki() { return kis / dt; };
	uint32_t get_kd() { return kd; };
	
private:
	int16_t* input;
	int16_t* output;
	int16_t* setpoint;

	int16_t prev_input;
	int32_t accumulator;
	uint32_t kp;
	uint32_t kis;			// Scale then integrate
	uint32_t kd;
	uint16_t dt;

	int16_t min;
	int16_t max;
};


#endif /* PID_H_ */