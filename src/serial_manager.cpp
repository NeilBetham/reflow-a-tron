/*
 * serial_manager.cpp
 *
 * Created: 11/20/2017 7:43:45 PM
 *  Author: nbeth
 */
#include <stdio.h>
#include <string.h>
#include "kernel.h" 
#include "serial_manager.h"
#include "uart.h"


SerialManager::SerialManager(){
  uart.set_delegate(this);
}

bool SerialManager::send(uint8_t* buf, uint16_t count){
  return uart.send_later(buf, count);
}

void SerialManager::on_tenms(void* data){
  uart.tick();
}

void SerialManager::on_fault(void* data){
  uint8_t msg[] = "Controller faulted";
  uart.send_later((uint8_t*)&msg, 18);
}

void SerialManager::handle_bytes(uint8_t byte){
  KERN->handle_event(char_recv, &byte);
  uart.send_later(&byte, 1);
}

void SerialManager::handle_uart_error(UARTError error){
    char msg[200] = {0};
    snprintf((char*)&msg, 200, "UART Error: %i", error);
    KERN->handle_event(fault, &msg);
}

