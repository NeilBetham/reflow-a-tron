/*
 * uart.cpp
 *
 * Created: 11/19/2017 11:08:30 PM
 *  Author: nbeth
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"

static UART* global_handler = 0;

UART::UART(){
  delegate = 0;
  error = uart_no_error;
  
  global_handler = this;
  
  recv = RingBuffer((uint8_t*)&recv_buf, UART_BUFFER_SIZE);
  send = RingBuffer((uint8_t*)&send_buf, UART_BUFFER_SIZE);
  
  // Configure the baud rate
  UBRR0 = 129;  // 9600 Buad

  // Enable the receiver and transmitter
  UCSR0B = (1UL << RXEN0) | (1UL << TXEN0) | (1UL << RXCIE0);
    
  // 8N1 Frame Format
  UCSR0C = (1ul << UCSZ00) | (1UL << UCSZ01);
}


uint8_t UART::send_now(uint8_t* buf, uint8_t count){
  disable_send_interrupt();
  uint8_t sent_count = 0;
  while(!(UCSR0A & (1UL << UDRE0)));
  for(int index = 0; index < count; index++){
    UDR0 = buf[index];
    while(!(UCSR0A & (1<<UDRE0)));
    sent_count++;
  }
  enable_send_interrupt();
  return sent_count;
}

uint8_t UART::read_now(uint8_t* buf, uint8_t count){
  disable_recv_interrupt();
  uint8_t recv_count = 0;
  for(int i = 0; i < count; i++){
    while(!(UCSR0A & (1UL << RXC0)));
    buf[i] = UDR0;
    recv_count++;
  }
  enable_recv_interrupt();
  return recv_count;
}

bool UART::send_later(uint8_t* buffer, uint8_t count){
  cli();
  if(send.slots_available() < count){
    return false;
  }
  for(uint8_t i = 0; i < count; i++){
    send.store_element(buffer[i]);
  }
  enable_send_interrupt();
  sei();
  return true;
}

void UART::tick(){
  if(recv.stored_elements() == 0){
    return;
  }
  
  for(int i = 0; i < 10; i++){
    uint8_t elem;
    
    if(!recv.get_element(&elem)){
      break;
    }
    
    send_later(&elem, 1);
    if(delegate){
      delegate->handle_bytes(elem);
    }      
  }
}

void UART::read_ready(){
  uint8_t byte = UDR0;
  if(!recv.store_element(byte)){
    error = uart_read_buffer_overrun;
  }
}


void UART::write_ready(){
  uint8_t to_send;
  if(!send.get_element(&to_send)){
    disable_send_interrupt();
    return;
  }
  
  UDR0 = to_send;
}

void UART::disable_recv_interrupt(){
  UCSR0B &= ~(1UL << RXCIE0);
}

void UART::enable_recv_interrupt(){
  UCSR0B |= (1UL << RXCIE0);
}

void UART::disable_send_interrupt(){
  UCSR0B &= ~(1UL << UDRIE0);
}

void UART::enable_send_interrupt(){
  UCSR0B |= (1UL << UDRIE0);
}




ISR(USART0_RX_vect){
  cli();
  if(!global_handler){
    return;
  }
  
  global_handler->read_ready();
  sei();
}

ISR(USART0_UDRE_vect){
  cli();
  if(!global_handler){
    return;
  }
  
  global_handler->write_ready();
  sei();
}