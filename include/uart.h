/*
 * uart.h
 *
 * Created: 11/19/2017 11:08:21 PM
 *  Author: nbeth
 */ 


#ifndef UART_H_
#define UART_H_

#define UART_BUFFER_SIZE 500

#include <stdint.h>
#include "i_byte_receiver.h"
#include "ring_buffer.h"

class UART {
public:
  UART(IByteReceiver* delegate);
  ~UART();
  
  uint8_t send_now(uint8_t* buf, uint8_t count);
  uint8_t read_now(uint8_t* buf, uint8_t count);
  
  bool send_later(uint8_t* buffer, uint8_t count);
  
  void read_ready();
  void write_ready();
  
private:
  IByteReceiver* delegate;
  uint8_t recv_buf[UART_BUFFER_SIZE];
  uint8_t send_buf[UART_BUFFER_SIZE];
  
  RingBuffer recv;
  RingBuffer send;
 
  uint8_t error;
  
  bool any_incoming() { return recv.stored_elements() > 0; };
  bool any_outgoing() { return send.stored_elements() > 0; };
    
  void disable_recv_interrupt();
  void enable_recv_interrupt();
  
  void disable_send_interrupt();
  void enable_send_interrupt();
};




#endif /* UART_H_ */