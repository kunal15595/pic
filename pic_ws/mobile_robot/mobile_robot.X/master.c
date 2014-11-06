#include "master.h"
#include "ELBv21_HardwareConfig.h"

TAVIX_THREAD_REGULAR master_thread(void* p){
    tavixTimerId timerId;	// Id the timer is represented by

	//---------------------------------------------------------------------------------------------
	// Create a timer with a cyclic period of 1 ms.
	//---------------------------------------------------------------------------------------------
	timerId = avixTimer_Create("TMR1");
	avixTimer_Set(timerId, AVIX_DELAY_MS(1000), AVIX_TIMER_CYCLIC);
	avixTimer_Start(timerId);

	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Wait for the timer and update the counter. Since my period is 1 ms and the other threads
		// period 2 ms, my counter will be double that of the other thread.
		//-----------------------------------------------------------------------------------------
		avixTimer_Wait(timerId);
                M_ToggleIO(LED2);
//		thread1Var++;
	}
//    printf("In master thread");
//    while(1);
}