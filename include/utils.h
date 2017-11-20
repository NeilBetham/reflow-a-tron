/*
 * utils.h
 *
 * Created: 11/19/2017 6:52:20 PM
 *  Author: nbeth
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#include <avr/sleep.h>

int32_t clamp(int32_t input, int32_t min, int32_t max);
void sleep();

#endif /* UTILS_H_ */