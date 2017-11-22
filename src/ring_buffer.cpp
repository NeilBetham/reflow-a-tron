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
  
  buf[next_slot()] = data;
  head = next_slot();
  occupancy++;
  return true;
}

int32_t RingBuffer::next_slot(){
  int32_t next = 0;
  if(head == tail){
    if(occupancy == 0){
      return head;
    } else {
      return head + 1;
    }
  }
  
  if(head + 1 >= capacity){
    next = 0;
   } else {
    next = head + 1;
  }
  
  return next;
}

bool RingBuffer::get_element(uint8_t* out_buf){
  if(occupancy == 0){
    return false;
  }
  
  *out_buf = buf[tail];
  if(tail + 1 == capacity){
    tail = 0;
  } else {
    tail++;
  }
  
  occupancy--;
  return true;
}

uint16_t RingBuffer::slots_available(){
  return capacity - stored_elements();
}

uint16_t RingBuffer::stored_elements(){
  return occupancy;
}