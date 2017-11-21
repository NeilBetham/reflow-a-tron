/*
 * ring_buffer.cpp
 *
 * Created: 11/20/2017 12:07:47 AM
 *  Author: nbeth
 */ 
#include <stdint.h>
#include "ring_buffer.h"


bool RingBuffer::store_element(uint8_t data){
  if(next_slot() < 0){
    return false;
  }
  
  buf[next_slot()] = data;
  head = next_slot();
  return true;
}

bool RingBuffer::get_element(uint8_t* out_buf){
  if(head == tail){
    return false;
  }
  
  *out_buf = buf[tail];
  if(tail + 1 == capacity){
    tail = 0;
  } else {
    tail++;
  }
  return true;
}

uint16_t RingBuffer::slots_available(){
  return capacity - stored_elements();
}

int32_t RingBuffer::next_slot(){
  int32_t next = 0;
  if(head + 1 >= capacity){
    next = 0;
  } else {
    next = head + 1;
  }
  
  if(next == tail){
    return -1;
  } else {
    return next;
  }
}

uint16_t RingBuffer::stored_elements(){
  if(head > tail){
    return (head + 1) - tail;
  } else {
    return (capacity - tail) + head + 1;
  }
}