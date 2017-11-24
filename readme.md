Reflow-A-Tron
=============

# Overview
This is a firmware repo for a reflow controller board that is currently in my
`eagle-stuff` repository. The code is all C++ but without dynamic allocation
as to not run the risk of having to deal with dynamic memory. The controller is
fairly simple. It features a thermocouple sensor which is read over SPI. Serial
communications are handled through a UART to an FTDI USB to serial converter.
Control of the output triac is done using software PWM; I goofed on the port
selection when doing the schematic :shipit:.

# Interface
The control interface to the board is serial at `9600` baud. The protocol is
line based and overall fairly simple.

## Sending A Command
Sending commands to the controller consists of a command followed by a set
of arguments. The command and the arguments, if any, are separated by a `|` symbol.
 - `command|arg1,arg2,agr3,...`

The controller after receiving a command with respond with either `ok` or `nok`.
The former is an indicator that the command was successful and the later that
the command was not successful.

The controller will also periodically send messages indicating it's current
status as well as if any faults occur.

## Available Commands
1. `set_coef|kp,ki,kd` - This sets the coefficients for the PID controller.
  * `kp` - The proportional coefficient in Q15
  * `ki` - The integral coefficient in Q15
  * `kd` - The derivate coefficient in Q15
2. `clear_profile` - This clears the currently stored profile.
3. `add_segment|target_temp,ramp_rate,time_ms` - This adds another segment to
to the reflow profile with the given parameters
  * `index` - The index of these parameters in the reflow profile
  * `target_temp` - The target temp integer for the segment in Q12
  * `ramp_rate` - The number of milliseconds per degree C
  * `time_ms` - The number of milliseconds we should spend in this segment
4. `start` - Start controlling to the
5. `stop` - Stop controlling the output
6. `reset` - Resets the entire controller

## Returned Information
1. `status|current_temp,current_setpoint,pwm_duty_cycle` - Sent periodically
while the controller is running
  * `current_temp` - The current temperature in the oven in counts
  * `current_setpoint` - The current temperature set point being controlled to
  in counts
  * `pwm_duty_cycle` - The current PWM duty cycle in counts
2. `profile|index,elapsed_time,segment_elapsed_time` - Sent periodically during
the execution of a reflow profile
  * `index` - The current profile segment being executed
  * `elapsed_time` - The time in milliseconds that the current profile has
  been executing
  * `segment_elapsed_time` - The time in milliseconds that the current segment
  has been executing
3. `fault|reason` - Sent immediately after a fault has occurred
  * `reason` - A string indicating the reason for the fault

## Conversions
* Temp
  * `counts` to `°C` - For any temp in counts the equation is:
  `(counts * 1023) / 4096`
* Coefficients
  * `float` to `counts` - Multiply float by `2^15`, the integer portion is the
  counts value.
