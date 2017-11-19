#include "init/init.h"
#include "tasks/loop.h"

int main(void)
{
	/* Init the micro */
	init();
	
	
	/* Call task loop */
	while (1){ task_loop(); }
}

