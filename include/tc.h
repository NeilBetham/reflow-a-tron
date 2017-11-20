/*
 * tc.h
 *
 * Created: 11/19/2017 10:46:30 PM
 *  Author: nbeth
 */ 


#ifndef TC_H_
#define TC_H_

#include <stdint.h>

typedef struct{
  uint16_t temp;
  bool tc_connnected;
} TempReading;


class TC {
public:
  static void parse_temp(uint8_t* buf, TempReading* reading);
};


#endif /* TC_H_ */