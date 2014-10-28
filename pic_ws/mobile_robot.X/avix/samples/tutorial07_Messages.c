
//	===============================================================================================
//	PRODUCT:			---------- AVIX - (ADVANCED VIRTUAL INTEGRATED EXECUTIVE) RTOS ------------
//	-----------------------------------------------------------------------------------------------
// 	PRODUCT VERSION: 	5.0
// 	COPYRIGHT:			AVIX-RT EMBEDDED SOLUTIONS
//	LICENSE AGREEMENT:	SEE BOTTOM OF THIS FILE
//	-----------------------------------------------------------------------------------------------
//	MODULE:				THIS FILE BELONGS  TO THE BASIC AVIX TUTORIAL APPLICATION WHICH IS DISTRI-
//						BUTED AS PART OF AVIX.  FOR A DESCRIPTION OF THIS TUTORIAL READ DOCUMENT
//						AVIX_GettingStarted.pdf  WHICH IS INSTALLED  IN THE AVIX DOCUMENT DIRECTORY
//	-----------------------------------------------------------------------------------------------
//	FILENAME:			tutorial07_Messages.c
//	-----------------------------------------------------------------------------------------------
//	Description:
//  ------------
//	Tutorial application 7: Two threads both in an endless loop waiting for a timer to expire. The 
//	timer waited for by thread 1 has a period of 1ms. The timer waited for by thread 2 has a period
//	of 2ms. Both threads increment a global watch variable where thread1 will update twice as fast
//	as thread2 because of the difference in timer period. On activation, each of the threads will
//	take its count value and send this to a third thread using a message. The third thread
//	waits for messages coming from thread1 and thread2. Thread3 will read the count values from
//	the message and calculate the average value which is placed in a third global watch variable.
//
//	See tutorial8 for the same functionality using pipes instead of messages to communicate the count
//	values to thread 3.
//	===============================================================================================
//	INCLUDES:
//	===============================================================================================
//
#include "stdio.h"		// Needed for definition of NULL
#include "AVIX.h"		// Allow AVIX functions to be used



//	-----------------------------------------------------------------------------------------------
//	Forward function declarations for the thread functions.
//	-----------------------------------------------------------------------------------------------
TAVIX_THREAD_REGULAR t07_thread1(void* p);
TAVIX_THREAD_REGULAR t07_thread2(void* p);
TAVIX_THREAD_REGULAR t07_thread3(void* p);



//	-----------------------------------------------------------------------------------------------
//	Variables to watch the progress of the tutorial. Variable tutorialId holds the number of the 
//	currently running tutorial. The thread variables are updated by the threads according the 
//	specific behaviour of the tutorial.
//	-----------------------------------------------------------------------------------------------
extern volatile int  tutorialId;
extern volatile long thread1Var;
extern volatile long thread2Var;
extern volatile long thread3Var;



//	===============================================================================================
//	FUNCTION:	t07Messages
//	=======================
//	Main function for d07EventFlags. This function is called from avixMain present in 
//	_tutorialMain.c and is responsible for initializing the application.
//	===============================================================================================
//
void t07Messages(void)
{
	//---------------------------------------------------------------------------------------------
	// Register two threads. Both will create a timer and update a counter. Thread1 will run twice 
	// as often as thread2 as can be observed in the threads counter values. Both threads will send 
	// their counter value to a third thread using a message.
	//---------------------------------------------------------------------------------------------
	avixThread_Create("THR1", t07_thread1, NULL, 1, 500, AVIX_THREAD_READY);
	avixThread_Create("THR2", t07_thread2, NULL, 1, 500, AVIX_THREAD_READY);


	//---------------------------------------------------------------------------------------------
	// Register a thread that will wait for messages from the other threads.
	//---------------------------------------------------------------------------------------------
	avixThread_Create("THR3", t07_thread3, NULL, 2, 500, AVIX_THREAD_READY);
}



//	===============================================================================================
//	FUNCTION:	t07_thread1
//	=======================
//	Function that will run as a thread under control of AVIX. This function updates thread1Var as 
//	can be observed in the watch window.
//	===============================================================================================
//
TAVIX_THREAD_REGULAR t07_thread1(void* p)
{
	tavixTimerId	timerId;	// Id the timer is represented by
	tavixThreadId	msgThread;	// Id of the thread to send a message to.
	tavixMsgId		msg;
	
	//---------------------------------------------------------------------------------------------
	// Create a timer with a cyclic period of 1 ms.
	//---------------------------------------------------------------------------------------------
	timerId = avixTimer_Create("TMR1");
	avixTimer_Set(timerId, AVIX_DELAY_MS(1), AVIX_TIMER_CYCLIC);
	avixTimer_Start(timerId);
	

	//---------------------------------------------------------------------------------------------
	// Obtain the id of the third thread so I can send a message to this thread.
	//---------------------------------------------------------------------------------------------
	msgThread = avixThread_Get("THR3");
	
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Wait for the timer and update the counter. Since my period is 1 ms and the other threads 
		// period 2 ms, my counter will be double that of the other thread.
		//-----------------------------------------------------------------------------------------
		avixTimer_Wait(timerId);
		
		thread1Var++;
		

		//-----------------------------------------------------------------------------------------
		// Allocate a message, fill it with the counter value and send to the third thread.
		//-----------------------------------------------------------------------------------------
		msg = avixMsg_Allocate(1);				// Allocate a message and give it id 1 so the receiver knows
												// the origin.
		
		avixMsg_PutLong(msg, thread1Var);		// Set the counter value in the message.
		
		avixMsgQThread_Send(msg, msgThread);	// Send the message.
	}
}



//	===============================================================================================
//	FUNCTION:	t07_thread2
//	=======================
//	Function that will run as a thread under control of AVIX. This function updates thread2Var as 
//	can be observed in the watch window.
//	===============================================================================================
//
TAVIX_THREAD_REGULAR t07_thread2(void* p)
{
	tavixTimerId	timerId;	// Id the timer is represented by
	tavixThreadId	msgThread;	// Id of the thread to send a message to.
	tavixMsgId		msg;
	
	//---------------------------------------------------------------------------------------------
	// Create a timer with a cyclic period of 1 ms.
	//---------------------------------------------------------------------------------------------
	timerId = avixTimer_Create("TMR2");
	avixTimer_Set(timerId, AVIX_DELAY_MS(2), AVIX_TIMER_CYCLIC);
	avixTimer_Start(timerId);
	

	//---------------------------------------------------------------------------------------------
	// Obtain the id of the third thread so I can send a message to this thread.
	//---------------------------------------------------------------------------------------------
	msgThread = avixThread_Get("THR3");
	
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Wait for the timer and update the counter. Since my period is 2 ms and the other threads 
		// period 1 ms, my counter will be half that of the other thread.
		//-----------------------------------------------------------------------------------------
		avixTimer_Wait(timerId);
		
		thread2Var++;
		

		//-----------------------------------------------------------------------------------------
		// Allocate a message, fill it with the counter value and send to the third thread.
		//-----------------------------------------------------------------------------------------
		msg = avixMsg_Allocate(2);				// Allocate a message and give it id 2 so the receiver knows
												// the origin.
		
		avixMsg_PutLong(msg, thread2Var);		// Set the counter value in the message.
		
		avixMsgQThread_Send(msg, msgThread);	// Send the message
	}
}



//	===============================================================================================
//	FUNCTION:	t07_thread3
//	=======================
//	Function that will run as a thread under control of AVIX. This function updates thread3Var as 
//	can be observed in the watch window.
//	===============================================================================================
//
TAVIX_THREAD_REGULAR t07_thread3(void* p)
{
	tavixMsgId	msg;			// id of the receive message
	long 		count1 = 0;		// Variable holding the counter received from thread 1
	long 		count2 = 0;		// Variable holding the counter received from thread 1
	int			msg1received;	// variable to know sender 1 data is received.
	int			msg2received;	// variable to know sender 2 data is received.
	
	//---------------------------------------------------------------------------------------------
	// Initially no data is received so both flags are 0
	//---------------------------------------------------------------------------------------------
	msg1received = 0; 
	msg2received = 0; 
	
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Wait for a message from another thread and return the message id in msg
		//-----------------------------------------------------------------------------------------
		msg = avixMsgQThread_Receive();
		
		
		//-----------------------------------------------------------------------------------------
		// I know to expect a type 1 and a type 2 message so now check which one this is.
		//-----------------------------------------------------------------------------------------
		if (avixMsg_GetType(msg) == 1)
		{
			msg1received = 1;				// So the thread1 data is received, set flag
			count1 = avixMsg_GetLong(msg);	// and read the value from the message.
		}
		
		if (avixMsg_GetType(msg) == 2)
		{
			msg2received = 1;				// So the thread2 data is received, set flag
			count2 = avixMsg_GetLong(msg);	// and read the value from the message.
		}
		
		//-----------------------------------------------------------------------------------------
		// Free the message so it can be reused again
		//-----------------------------------------------------------------------------------------
		avixMsg_Free(msg);


		//-----------------------------------------------------------------------------------------
		// When data of both threads is received, the average is calculated and set in the variable 
		// so it can be watched.
		//-----------------------------------------------------------------------------------------
		if (msg1received && msg2received)
		{
			thread3Var = (count1 + count2) / 2;
		}
	}
}




//	===============================================================================================
//	***********************************************************************************************
//	===============================================================================================
//	SOFTWARE LICENSE AGREEMENT
//	--------------------------
//
//	THE  SOFTWARE  SUPPLIED  HEREWITH  AS  THE  CONTENT  OF  THIS FILE IS OWNED BY AVIX-RT EMBEDDED
//	SOLUTIONS  (THE "COMPANY"), AND IS PROTECTED  UNDER APPLICABLE  COPYRIGHT LAWS.  ALL RIGHTS ARE
//	RESERVED.  THE SOFTWARE IS SUPPLIED TO YOU (THE "CUSTOMER")  FOR USE  SOLELY AND EXCLUSIVELY AS
//	PART OF AND TOGETHER WITH PRODUCTS MANUFACTURED BY "COMPANY" AND LICENSED TO "CUSTOMER".
//
//	THE SOFTWARE IS PROVIDED ON AN AS-IS BASIS WITHOUT  CHARGE AND IS SUBJECT TO ALTERATIONS. IT IS 
//	THE "CUSTOMERS" OBLIGATION TO FULLY TEST THE SOFTWARE IN ITS ENVIRONMENT AND TO  ENSURE  PROPER 
//	FUNCTIONALITY, QUALIFICATION AND COMPLIANCE WITH COMPONENT SPECIFICATIONS.
//
//	IN  THE  EVENT  THE  SOFTWARE  DELIVERABLE  INCLUDES THE  USE OF  OPEN SOURCE  COMPONENTS,  THE 
//	PROVISIONS OF  THE GOVERNING  OPEN SOURCE  LICENSE AGREEMENT  SHALL APPLY  WITH RESPECT TO SUCH 
//	SOFTWARE DELIVERABLE. THE "COMPANY" DOES NOT WARRANT  THAT THE DELIVERABLES DO NOT INFRINGE ANY 
//	THIRD PARTY INTELLECTUAL  PROPERTY RIGHT (IPR).  IN THE EVENT THAT THE  DELIVERABLES INFRINGE A 
//	THIRD PARTY IPR IT IS THE SOLE RESPONSIBILITY OF THE "CUSTOMER" TO OBTAIN NECESSARY LICENSES TO 
//	CONTINUE THE  USAGE OF THE DELIVERABLE.
//
//	"COMPANY" LICENSES "CUSTOMER"  THE RIGHT TO USE  THIS FILE FOR THE  SOLE PURPOSE  OF DEVELOPING
//	APPLICATION SOFTWARE BASED ON ONE OF "COMPANIES" PRODUCTS AND FOR EXCLUSIVE USE ON A  SUPPORTED
//	MICROCONTROLLER.
//
//	UNDER NO CIRCUMSTANCE  MAY THE CONTENT OF  THIS FILE,  EITHER PARTIALLY  OR COMPLETE,  BE  MADE
//	PUBLIC, EITHER ELECTRONICALLY OR PRINTED.
//
//	ANY VIOLATION TO THE FOREGOING RESTRICTIONS  MAY SUBJECT THE USER  TO CRIMINAL SANCTIONS  UNDER
//	APPLICABLE LAWS, AS WELL AS TO CIVIL  LIABILITY FOR  THE BREACH  OF THE TERMS AND CONDITIONS OF
//	THIS LICENSE.
//
//	YOU SHOULD REFER TO THE LICENSE AGREEMENT  ACCOMPANYING THE  PRODUCT THIS  SOFTWARE IS  PART OF
//	FOR ADDITIONAL INFORMATION REGARDING YOUR RIGHTS AND OBLIGATIONS.
//
//	THE SOFTWARE  AND DOCUMENTATION  ARE PROVIDED  "AS IS"  WITHOUT  WARRANTY  OF ANY  KIND, EITHER
//	EXPRESS OR IMPLIED, INCLUDING WITHOUT  LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR
//	A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL "COMPANY" BE LIABLE FOR ANY
//	INCIDENTAL, SPECIAL,  INDIRECT OR  CONSEQUENTIAL DAMAGES,  LOST PROFITS  OR LOST  DATA, COST OF
//	PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING
//	BUT NOT  LIMITED TO ANY DEFENSE  THEREOF),  ANY CLAIMS  FOR  INDEMNITY OR CONTRIBUTION,OR OTHER
//	SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF  CONTRACT, TORT  (INCLUDING NEGLIGENCE), BREACH
//	OF WARRANTY, OR OTHERWISE.
//
//	COPYRIGHT (C) 2006-2012 AVIX-RT EMBEDDED SOLUTIONS.  ALL RIGHTS RESERVED.
//
//	===============================================================================================
