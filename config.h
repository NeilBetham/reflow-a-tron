/*
 * config.h
 *
 * Created: 3/13/2016 12:11:07 AM
 *  Author: Neil
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_



#define MAIN_TASK_LOOP_PERIOD 0x004e // ( 20MHz / 1024 ) / 0x0013 = 1.001 KHz aka 1ms
#define MAIN_TASK_LOOP_PRESCALE_SELECT 0x04 // Prescale 20MHz io clk by 1024



#endif /* CONFIG_H_ */