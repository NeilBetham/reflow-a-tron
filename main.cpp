/*
 * Reflow-A-Tron.cpp
 *
 * Created: 11/19/2017 6:02:19 PM
 * Author : nbeth
 */
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include "kernel.h"
#include "leash.h"
#include "ticker.h"
#include "event_timer.h"
#include "serial_manager.h"
#include "tc_poller.h"
#include "commander.h"
#include "temp_controller.h"
#include "coefficient_handler.h"
#include "clear_handler.h"
#include "add_segment_handler.h"
#include "start_handler.h"
#include "stop_handler.h"
#include "reset_handler.h"


#define TIMER_CLOCK_PRESCALE 0x04   // Pre-scale 20MHz io clock by 1024
#define TIMER_CLOCK_PERIOD 0x004e   // ( 20MHz / 1024 ) / 0x0013 = 1.001 KHz aka 1ms

int main(void)
{
  // Initialize the kernel
  Kernel kernel;
  
  // Setup Watch Dog
  Leash leash;
  kernel.register_for_event(&leash, tenms);
  
  // Setup task event generator
  Ticker ticker = Ticker(TIMER_CLOCK_PRESCALE, TIMER_CLOCK_PERIOD);
  EventTimer event_timer;
  ticker.register_delegate(&event_timer);
  
  // Setup Serial comm
  SerialManager serial_manager;
  kernel.register_for_event(&serial_manager, tenms);
  kernel.register_for_event(&serial_manager, fault);
  serial_manager.send_now("Reflow-A-Tron starting up...\n");
  
  // Setup TC Polling
  TCPoller tc_poller;
  kernel.register_for_event(&tc_poller, fivehunderedms);
  
  // Setup commander
  Commander commander = Commander(&serial_manager);
  kernel.register_for_event(&commander, char_recv);
  kernel.register_for_event(&commander, hunderedms);
  kernel.register_for_event(&commander, fault);
  
  // Setup temp controller
  TempController temp_control;
  kernel.register_for_event(&temp_control, tenms);
  kernel.register_for_event(&temp_control, fivehunderedms);
  kernel.register_for_event(&temp_control, fault);
  
  // Setup command handlers
  CoefficientHandler coef_handler = CoefficientHandler(&temp_control.pid);
  commander.register_handler(&coef_handler);
  ClearHandler clear_handler = ClearHandler(&(temp_control.profile));
  commander.register_handler(&clear_handler);
  AddSegmentHandler add_seg_handler = AddSegmentHandler(&(temp_control.profile));
  commander.register_handler(&add_seg_handler);
  StartHandler start_handler  = StartHandler(&temp_control);
  commander.register_handler(&start_handler);
  StopHandler stop_handler = StopHandler(&temp_control);
  commander.register_handler(&stop_handler);
  ResetHandler reset_handler = ResetHandler(&leash);
  commander.register_handler(&reset_handler);
  
  
  // Enable interrupts
  sei();
  
  // Enable Watch Dog
  leash.enable();
  
  // Start the event loops
  serial_manager.send("Ready\n");
  ticker.start();
  
  return 0;
}

