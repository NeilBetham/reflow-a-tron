/*
 * utils.cpp
 *
 * Created: 11/19/2017 8:53:25 PM
 *  Author: nbeth
 */ 
#include "utils.h"

int32_t clamp(int32_t input, int32_t min, int32_t max){
  if(input >= max){
    return max;
    } else if(input <= min){
    return min;
    } else {
    return input;
  }
}


void sleep(){
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  sleep_mode();
}