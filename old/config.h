/*
 * config.h
 *
 * Created: 3/13/2016 12:11:07 AM
 *  Author: Neil
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#include "avr/io.h"

// Task Loop Timing Configs
#define MAIN_TASK_LOOP_PERIOD 0x004e // ( 20MHz / 1024 ) / 0x0013 = 1.001 KHz aka 1ms
#define MAIN_TASK_LOOP_PRESCALE_SELECT 0x04 // Prescale 20MHz io clk by 1024

// PID Controller Configs
// Scaled by Q16
#define kp				6554	// 0.1
#define kd				655		// 0.01
#define ki				6554	// 0.1
#define dt				32768	// 0.01
#define windup_guard	6553600

// SPI Interface Config
#define spi_baud 9 // (20 / (2 * 1)) - 1 = 9 => 1MHz
#define spi_mode 1 // Setup on clk rising followed by read on clk falling

// PWM Config
#define pwm_port PORTA
#define pwm_pin 0x00

#endif /* CONFIG_H_ */