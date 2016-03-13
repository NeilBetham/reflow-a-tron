#include "loop.h"
#include "tasks.h"
#include "../drivers/pwr.h"
#include <stdio.h>

// This variable keeps track of the number of iterations that have progressed in the task loop
uint16_t loop_count = 1;

// loop returns a boolean for the modulus of the loop count vs and input count
#define loop(count) ((loop_count % count) == 0)
//int loop(int count){
//	return((loop_count % count) == 0);
//}

void task_loop() {
	// Call tasks if they are currently up for execution
	if(loop(1)){
		onems_task();
	}
	
	if(loop(10)){
		tenms_task();
	}
	
	if(loop(100)){
		hunderedms_task();
	}
	
	if(loop(1000)){
		ones_task();
		loop_count = 1;
	} else {
		// Increment loop count
		++loop_count;
	}
	
	// Put CPU back to sleep
	sleep();
}

// 1 2 3 4 5 6 7 8 9 10