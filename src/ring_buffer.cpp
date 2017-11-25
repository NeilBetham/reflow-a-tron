/*
 * ring_buffer.cpp
 *
 * Created: 11/20/2017 12:07:47 AM
 *  Author: nbeth
 */ 
#include <stdint.h>
#include "ring_buffer.h"


bool RingBuffer::store_element(uint8_t data){
  if(occupancy == capacity){
    return false;
  }
  
  if(occupancy != 0){
    head = next_index(head);
  }
  
  buf[head] = data;
  
  occupancy++;
  return true;
}

bool RingBuffer::get_element(uint8_t* out_buf){
  if(occupancy == 0){
    return false;
  }
  
  *out_buf = buf[tail];
  if(head != tail){
    tail = next_index(tail);
  }    
  
  occupancy--;
  return true;
}

int32_t RingBuffer::next_index(int32_t index){
  if((index + 1) == capacity){
    return 0;
  } else {
    return index + 1;
  }
}

uint16_t RingBuffer::slots_available(){
  return capacity - stored_elements();
}

uint16_t RingBuffer::stored_elements(){
  return occupancy;
}