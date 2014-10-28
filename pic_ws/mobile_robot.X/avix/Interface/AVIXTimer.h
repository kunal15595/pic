#ifndef __AVIXTimer_h__
#define __AVIXTimer_h__

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
//	Timer definitions.
//
//=================================================================================================
// INCLUDES
//=================================================================================================
//
#include <limits.h>
#include "AVIXGeneric.h"
#include "AVIXObjectManager.h"
#include "AVIXEvent.h"


//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//
typedef long 	tavixTimerTick;

typedef int 	tavixTimerType;



//=================================================================================================
// MACROS
//=================================================================================================
//
#define AVIX_TIMER_CYCLIC		((tavixTimerType)	0	)
#define AVIX_TIMER_SINGLE_SHOT	((tavixTimerType)	1	)



//-------------------------------------------------------------------------------------------------
// Define the actual system clock period. Because of the used crystal this may be slightly 
// different from the configured one.
//-------------------------------------------------------------------------------------------------
//	
#define AVIX_SYS_CLOCK_ACTUAL_PERIOD	(1000000L / ((avix_DEVICE_CLOCKhz) /					\
							( ((avix_DEVICE_CLOCKhz / 100) * avix_SYS_CLOCK_TICKus) / 10000) ) )



//-------------------------------------------------------------------------------------------------
// Calculate the maximum number of ticks based on the size of tavixTimerTick and the fact that the
// maximum is the maximal signed values for that type.
//-------------------------------------------------------------------------------------------------
//
#define	AVIX_TIMER_MAX_NR_TICKS	((tavixTimerTick)((~((long long)1 << 							\
								((CHAR_BIT * sizeof(tavixTimerTick)) - 1))) - 2 ))



//-------------------------------------------------------------------------------------------------
// Helper macro's to calculate the desired number of timer system ticks based on a human
// comprehensible time notation (sec, ms or us).
//-------------------------------------------------------------------------------------------------
//
#define	AVIX_DELAY_US(us)			(((tavixTimerTick)(us) / AVIX_SYS_CLOCK_ACTUAL_PERIOD) + 	\
									(((tavixTimerTick)(us) % AVIX_SYS_CLOCK_ACTUAL_PERIOD) ?1:0))

#define AVIX_DELAY_MS(ms)			AVIX_DELAY_US(((tavixTimerTick)(ms)) * 1000)

#define AVIX_DELAY_S(s)				AVIX_DELAY_MS(((tavixTimerTick)(s)) * 1000)

#define AVIX_DELAY_MS_US(ms,us)		(AVIX_DELAY_MS(ms) + AVIX_DELAY_US(us))

#define AVIX_DELAY_S_MS(s,ms)		(AVIX_DELAY_S(s) + AVIX_DELAY_MS(ms))

#define AVIX_DELAY_S_MS_US(s,ms,us)	(AVIX_DELAY_S(s) + AVIX_DELAY_MS(ms) + AVIX_DELAY_US(us))



//=================================================================================================
// FUNCTION DEFINITIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
tavixTimerId	
	avixTimer_Get					(	tavixKernelObjectName		pName		);


//-------------------------------------------------------------------------------------------------
tavixTimerId	
	avixTimer_Create				(	tavixKernelObjectName		pName		);


//-------------------------------------------------------------------------------------------------
void 			
	avixTimer_Set					(	tavixTimerId 				timerId, 
										tavixTimerTick				ticks, 
										tavixTimerType 				type		);


//-------------------------------------------------------------------------------------------------
void 			
	avixTimer_SetPeriod				(	tavixTimerId 				timerId, 
										tavixTimerTick 				ticks		);


//-------------------------------------------------------------------------------------------------
void			
	avixTimer_ConnectEventGroup		(	tavixTimerId				timerId,
										tavixEventId				event,
										tavixEventGroupOperation	operation,
										tavixEventFlags 			eventFlags	);


//-------------------------------------------------------------------------------------------------
void 			
	avixTimer_DisconnectEventGroup	(	tavixTimerId 				timerId		);


//-------------------------------------------------------------------------------------------------
int 			
	avixTimer_Start					(	tavixTimerId 				timerId		);


//-------------------------------------------------------------------------------------------------
void			
	avixTimer_StartFromISR			(	tavixTimerId 				timerId		);


//-------------------------------------------------------------------------------------------------
int 			
	avixTimer_Resume				(	tavixTimerId 				timerId		);


//-------------------------------------------------------------------------------------------------
void			
	avixTimer_ResumeFromISR			(	tavixTimerId 				timerId		);


//-------------------------------------------------------------------------------------------------
void 			
	avixTimer_Stop					(	tavixTimerId 				timerId		);


//-------------------------------------------------------------------------------------------------
void 			
	avixTimer_StopFromISR			(	tavixTimerId 				timerId		);


//-------------------------------------------------------------------------------------------------
void 			
	avixTimer_Wait					(	tavixTimerId 				timerId		);


//-------------------------------------------------------------------------------------------------
tavixTimerTick	
	avixTimer_GetRemainingTicks		(	tavixTimerId 				timerId		);


#ifdef __cplusplus
}
#endif

#endif	// __AVIXTimer_h__
