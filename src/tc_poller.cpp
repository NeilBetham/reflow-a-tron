/*
 * tc_poller.cpp
 *
 * Created: 11/20/2017 10:31:16 PM
 *  Author: nbeth
 */ 

#include <avr/io.h>
#include "tc_poller.h"
#include "kernel.h"
#include "tc.h"

TCPoller::TCPoller(){
  spi = SPI();
}

void TCPoller::on_fivehunderedms(void* data){
  uint8_t buf[2] = {0};
  spi.read_bytes((uint8_t*)&buf, 2);
  TC::parse_temp((uint8_t*)&buf, (TempReading*)&temp);
  
  if(!temp.tc_connnected){
    char msg[] = "Thermocouple Disconnected";
    KERN->handle_event(fault, &msg);
    return;
  } else {
    KERN->handle_event(temp_recv, &(temp.temp));
  }
}