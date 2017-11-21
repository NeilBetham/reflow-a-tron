/*
 * tc.cpp
 *
 * Created: 11/19/2017 10:46:41 PM
 *  Author: nbeth
 */
#include "tc.h"

void TC::parse_temp(uint8_t* buf, TempReading* reading){
  reading->temp = (buf[1] & 0xF8) >> 3 | ((buf[0] & 0x7F) << 5);
  reading->tc_connnected = (buf[1] & 0x04) == 0;
}