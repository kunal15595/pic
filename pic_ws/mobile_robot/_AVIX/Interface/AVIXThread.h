#ifndef __AVIXThread_h__
#define __AVIXThread_h__

#ifdef __cplusplus
	extern "C" {
#endif 

//=================================================================================================
//
//	===============================================================================================
//	PRODUCT:			---------- AVIX - (ADVANCED VIRTUAL INTEGRATED EXECUTIVE) RTOS ------------
//	===============================================================================================
//
//	===============================================================================================
// 	PRODUCT VERSION: 	5.0
// 	COPYRIGHT:			AVIX-RT EMBEDDED SOLUTIONS
//	===============================================================================================
//
//	===============================================================================================
//	UNDER NO CIRCUMSTANCE MAY THE CONTENT OF THIS FILE BE CHANGED. ANY CHANGE OF THE DEFINITIONS IN
//	THIS FILE MAY  LEAD TO AVIX  NOT WORKING OR WORKING  IN A UNPREDICTABLE  MANNER.
//	===============================================================================================
//
//	SOFTWARE LICENSE AGREEMENT
//	--------------------------
//
//	THE  SOFTWARE  SUPPLIED  HEREWITH  AS  THE  CONTENT  OF  THIS FILE IS OWNED BY AVIX-RT EMBEDDED
//	SOLUTIONS  (THE "COMPANY"), AND IS PROTECTED  UNDER APPLICABLE  COPYRIGHT LAWS.  ALL RIGHTS ARE
//	RESERVED.  THE SOFTWARE IS SUPPLIED TO YOU (THE "CUSTOMER")  FOR USE  SOLELY AND EXCLUSIVELY AS
//	PART OF AND TOGETHER WITH PRODUCTS MANUFACTURED BY "COMPANY" AND LICENSED TO "CUSTOMER".
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
//
//	Description:
//  ------------
//	Definitions needed for thread functionality
//
//=================================================================================================
//
//=================================================================================================
// INCLUDES
//=================================================================================================
//
#include "AVIXObjectManager.h"
#include "AVIXGeneric.h"
#include "AVIXTimer.h"


//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//
typedef int 				tavixThreadSuspended;

typedef int 				tavixThreadTracePort;

typedef unsigned short		tavixPriority;

typedef void (__AVIX_TASK*	tavixThreadFuncType)(void *);



//=================================================================================================
// MACRO'S
//=================================================================================================
//
#define AVIX_THREAD_READY			((tavixThreadSuspended)	0	)
#define AVIX_THREAD_SUSPENDED		((tavixThreadSuspended)	1	)


#define AVIX_TRACE_PORT_A			((tavixThreadTracePort)	0	)
#define AVIX_TRACE_PORT_B			((tavixThreadTracePort)	1	)
#define AVIX_TRACE_PORT_C			((tavixThreadTracePort)	2	)
#define AVIX_TRACE_PORT_D			((tavixThreadTracePort)	3	)
#define AVIX_TRACE_PORT_E			((tavixThreadTracePort)	4	)
#define AVIX_TRACE_PORT_F			((tavixThreadTracePort)	5	)
#define AVIX_TRACE_PORT_G			((tavixThreadTracePort)	6	)
#define AVIX_TRACE_PORT_H			((tavixThreadTracePort)	7	)
#define AVIX_TRACE_PORT_I			((tavixThreadTracePort)	8	)
#define AVIX_TRACE_PORT_J			((tavixThreadTracePort)	9	)
#define AVIX_TRACE_PORT_K			((tavixThreadTracePort)	10	)
#define AVIX_TRACE_PORT_L			((tavixThreadTracePort)	11	)
#define AVIX_TRACE_PORT_M			((tavixThreadTracePort)	12	)
#define AVIX_TRACE_PORT_N			((tavixThreadTracePort)	13	)
#define AVIX_TRACE_PORT_O			((tavixThreadTracePort)	14	)
#define AVIX_TRACE_NONE				((tavixThreadTracePort)	15	)

#define TRACE_IDLE_THREAD_ID		AVIX_OBJECT_ID_NULL(tavixThreadId)

#define TAVIX_THREAD_REGULAR 		__AVIX_NORETURN __AVIX_TASK void

#define AVIX_TIMEOUT(func,to)		(avixThread_ArmTimeOut(to), (func), avixThread_TimeOutOccured())

#define	AVIX_TIMEOUT_WAIT_FOREVER	(AVIX_TIMER_MAX_NR_TICKS + 1)



//=================================================================================================
// FUNCTION DECLARATIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
tavixThreadId
	avixThread_Create					(	tavixKernelObjectName	pName,
											tavixThreadFuncType 	pThread,
											void*					threadParam,
											tavixPriority 			iPriority,
											unsigned int 			iStackSize,
											tavixThreadSuspended	fSuspended	);


//-------------------------------------------------------------------------------------------------
tavixThreadId 	
	avixThread_Get						(	tavixKernelObjectName	pName		);


//-------------------------------------------------------------------------------------------------
void 			
	avixThread_Suspend					(	void								);


//-------------------------------------------------------------------------------------------------
void 			
	avixThread_Resume					(	tavixThreadId 			id			);


//-------------------------------------------------------------------------------------------------
void 			
	avixThread_ResumeFromISR			(	tavixThreadId 			id			);


//-------------------------------------------------------------------------------------------------
void			
	avixThread_Relinquish				(	void								);


//-------------------------------------------------------------------------------------------------
void			
	avixThread_ArmTimeOut				(	tavixTimerTick			ticks		);


//-------------------------------------------------------------------------------------------------
int				
	avixThread_TimeOutOccured			(	void								);


//-------------------------------------------------------------------------------------------------
tavixThreadId 	
	avixThread_GetIdCurrent				(	void								);


//-------------------------------------------------------------------------------------------------
void 			
	avixThread_SetTracePort				(	tavixThreadId 			thread, 
											tavixThreadTracePort	portIndex, 
											unsigned int 			bit			);


//-------------------------------------------------------------------------------------------------
void 			
	avixThread_SetTracePortAndResume	(	tavixThreadId 			thread, 
											tavixThreadTracePort 	portIndex, 
											unsigned int 			bit			);


//-------------------------------------------------------------------------------------------------
void			
	avixThread_PulseTracePort			(	void								);


//-------------------------------------------------------------------------------------------------
void 			
	avixThread_Sleep					(	tavixTimerTick const	ticks		);



#ifdef __cplusplus
}
#endif

#endif	// __AVIXThread_h__
