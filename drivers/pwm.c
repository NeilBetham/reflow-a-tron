#include "pwm.h"

static uint32_t current_count = 0;
static uint32_t period = 0;
static uint32_t duty_cycle = 0;
static uint8_t tc_fault = 0;

void init_pwm(){
	DDRA |= 1UL << pwm_pin;
	PORTA = 0x00;
}

void pwm_tick(){
	if(tc_fault){
		return;
	}
	if(current_temp.thermo_input){
		pwm_port &= ~(1UL << pwm_pin);
		tc_fault = 1;
	}
	if(current_count == 0){
		pwm_port |= 1UL << pwm_pin;
	}
	if(current_count >= duty_cycle && duty_cycle != period){
		pwm_port &= ~(1UL << pwm_pin);
	}
	if(current_count >= period){
		current_count = 0;
	} else {
		current_count++;
	}
}

void pwm_set_period(uint32_t p){
	period = p;
}

void pwm_set_duty_cycle(uint32_t dc){
	duty_cycle = dc;
}