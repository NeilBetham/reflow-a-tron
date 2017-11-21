/*
 * serial_manager.h
 *
 * Created: 11/20/2017 7:29:07 PM
 *  Author: nbeth
 */ 


#ifndef SERIAL_MANAGER_H_
#define SERIAL_MANAGER_H_
#include "i_byte_receiver.h"
#include "uart.h"

class SerialManager : public IEventDelegate, public IByteReceiver {
public:
  SerialManager();
  ~SerialManager() {};
  
  bool send(uint8_t* buf, uint16_t count);
  
  void on_tenms(void* data);
  void on_fault(void* data);
 
  void handle_bytes(uint8_t byte);
  void handle_uart_error(UARTError error);
  
private:
  UART uart;
};


#endif /* SERIAL_MANAGER_H_ */