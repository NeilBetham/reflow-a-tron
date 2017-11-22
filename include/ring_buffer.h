/*
 * ring_buffer.h
 *
 * Created: 11/20/2017 12:07:37 AM
 *  Author: nbeth
 */ 


#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

class RingBuffer {
public:
  RingBuffer(): buf(0), capacity(0), head(0), tail(0) {};
  RingBuffer(uint8_t* managed_buffer, uint16_t capacity): buf(managed_buffer), capacity(capacity), occupancy(0), head(0), tail(0) {};
  bool store_element(uint8_t data);
  bool get_element(uint8_t* buf);
  uint16_t slots_available();
  uint16_t stored_elements();
  
private:
  uint8_t* buf;
  uint16_t capacity;
  uint16_t occupancy;
  int32_t head;
  int32_t tail;
  
  int32_t next_slot();
};



#endif /* RING_BUFFER_H_ */