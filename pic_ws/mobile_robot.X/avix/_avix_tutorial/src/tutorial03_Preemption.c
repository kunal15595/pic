
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
//	FILENAME:			tutorial03_Preemption.c
//	-----------------------------------------------------------------------------------------------
//	Description:
//  ------------
//	Tutorial application 3: Two round robin threads each incrementing a global watch variable. A 
//	third thread having a higher priority sits in an endless loop waiting for a timer to expire.
//	When the timer expires this thread preempts the currently running thread and will update a
//	third watch variable.
//	===============================================================================================
//	INCLUDES:
//	===============================================================================================
//
#include "stdio.h"		// Needed for definition of NULL
#include "AVIX.h"		// Allow AVIX functions to be used



//	------------------------------------------------------------------------------------------------
//	Forward function declarations for the thread functions.
//	------------------------------------------------------------------------------------------------
TAVIX_THREAD_REGULAR t03_thread1(void* p);
TAVIX_THREAD_REGULAR t03_thread2(void* p);
TAVIX_THREAD_REGULAR t03_thread3(void* p);



//	------------------------------------------------------------------------------------------------
//	Variables to watch the progress of the tutorial. Variable tutorialId holds the number of the 
//	currently running tutorial. The thread variables are updated by the threads according the 
//	specific behaviour of the tutorial.
//	------------------------------------------------------------------------------------------------
extern volatile int  tutorialId;
extern volatile long thread1Var;
extern volatile long thread2Var;
extern volatile long thread3Var;




//	===============================================================================================
//	FUNCTION:	t03Preemption
//	=========================
//	Main function for tutorial 3, Preemption. This function is called from avixMain present in
//	_tutorialMain.c and is responsible for initializing the application.
//	===============================================================================================
//
void t03Preemption(void)
{
	//---------------------------------------------------------------------------------------------
	// Register two threads at equal priority. These will be scheduled round robin meaning AVIX 
	// will activate them in turn for the configured round robin period.
	//---------------------------------------------------------------------------------------------
	avixThread_Create("TRR1", t03_thread1, NULL, 1, 500, AVIX_THREAD_READY);
	avixThread_Create("TRR2", t03_thread2, NULL, 1, 500, AVIX_THREAD_READY);


	//---------------------------------------------------------------------------------------------
	// Register a third thread with a priority higher than the other two threads. When ready to 
	// run, this thread will preempt the other threads.
	//---------------------------------------------------------------------------------------------
	avixThread_Create("TPE",  t03_thread3, NULL, 2, 500, AVIX_THREAD_READY);
}



//	===============================================================================================
//	FUNCTION:	t03_thread1
//	=======================
//	Function that will run as a thread under control of AVIX. This function updates thread1Var as 
//	can be observed in the watch window.
//	===============================================================================================
//
TAVIX_THREAD_REGULAR t03_thread1(void* p)
{
	while(1)
	{
		thread1Var++;
	}
}



//	===============================================================================================
//	FUNCTION:	t03_thread2
//	=======================
//	Function that will run as a thread under control of AVIX. This function updates thread2Var as 
//	can be observed in the watch window.
//	===============================================================================================
//
TAVIX_THREAD_REGULAR t03_thread2(void* p)
{
	while(1)
	{
		thread2Var++;
	}
}



//	===============================================================================================
//	FUNCTION:	t03_thread3
//	=======================
//	Function that will run as a thread under control of AVIX. This function updates thread3Var as 
//	can be observed in the watch window.
//	===============================================================================================
//
TAVIX_THREAD_REGULAR t03_thread3(void* p)
{
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// This thread will sleep for one millisecond after which it wakes up. Since the priority 
		// is higher than that of the other two threads, this thread will preempt the thread 
		// currently active and run after which it will sleep again.
		//-----------------------------------------------------------------------------------------
		avixThread_Sleep(AVIX_DELAY_MS(1));
		
		thread3Var++;
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
