#include <astar_thread.h>
#include "ELBv21_HardwareConfig.h"
TAVIX_THREAD_REGULAR astar_thread(void* p){
    tavixTimerId timerId;	// Id the timer is represented by

	//---------------------------------------------------------------------------------------------
	// Create a timer with a cyclic period of 2 ms.
	//---------------------------------------------------------------------------------------------
	timerId = avixTimer_Create("TMR2");
	avixTimer_Set(timerId, AVIX_DELAY_MS(1000), AVIX_TIMER_CYCLIC);
	avixTimer_Start(timerId);

	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Wait for the timer and update the counter. Since my period is 2 ms and the other threads
		// period 1 ms, my counter will be half that of the other thread.
		//-----------------------------------------------------------------------------------------
		avixTimer_Wait(timerId);
                M_ToggleIO(LED3);
//		thread2Var++;
	}
//    printf("In astar thread\n");
//    while(1);
}
