/*
 * i_byte_receiver.h
 *
 * Created: 11/19/2017 11:18:19 PM
 *  Author: nbeth
 */ 


#ifndef I_BYTE_RECEIVER_H_
#define I_BYTE_RECEIVER_H_

typedef enum {
  uart_no_error,
  uart_read_buffer_overrun,
  uart_write_buffer_overrun,
  uart_error_count
} UARTError;


class IByteReceiver {
public:
  virtual ~IByteReceiver();
  virtual void handle_bytes(uint8_t byte);
  virtual void handle_uart_error(UARTError error);
};


#endif /* I_BYTE_RECEIVER_H_ */