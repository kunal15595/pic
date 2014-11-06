#ifndef __AVIXEvent_h__
#define __AVIXEvent_h__

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
//	Event group definitions
//
//=================================================================================================
// INCLUDES
//=================================================================================================
//
#include "AVIXGeneric.h"
#include "AVIXObjectManager.h"


//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//
typedef unsigned short 	tavixEventFlags;

typedef int 			tavixEventGroupCombine;

typedef int 			tavixEventGroupOperation;



//=================================================================================================
// MACROS
//=================================================================================================
//
#define AVIX_EF_NONE				( (tavixEventFlags)0x0000)
#define AVIX_EF_ALL					(~AVIX_EF_NONE)

#define AVIX_EF(f)					(((tavixEventFlags)0x1) << (f))
#define AVIX_EF_RANGE(a,b)			((	(AVIX_EF_ALL << ((a))) ^ 								\
										(AVIX_EF_ALL <<  (b)) ) | AVIX_EF(a) | AVIX_EF(b)	)

#define AVIX_EF_INVERT_MASKED(f,m)	((f) ^ (AVIX_EF_ALL & (m)))
#define AVIX_EF_INVERT_ALL(f)		AVIX_EF_INVERT_MASKED((f), AVIX_EF_ALL)

#define AVIX_EF_IS_MASKED(v,f,m)	((((m) != AVIX_EF_NONE) && (((v) & (m)) == 					\
									((f) & (m)))) ? 1 : 0)
									
#define AVIX_EF_IS(v,f)				AVIX_EF_IS_MASKED((v),(f),AVIX_EF_ALL)

#define AVIX_EF_IN_MASKED(v,f,m)	(((((v) & (m)) != AVIX_EF_NONE) && (((v) & (m)) == 			\
									((v) & (f)))) ? 1 : 0)

#define AVIX_EF_IN(v,f)				AVIX_EF_IN_MASKED((v), (f), AVIX_EF_ALL)


//-------------------------------------------------------------------------------------------------
#define AVIX_EVENT_GROUP_ALL		((tavixEventGroupCombine)	0	)
#define AVIX_EVENT_GROUP_ANY		((tavixEventGroupCombine)	1	)


//-------------------------------------------------------------------------------------------------
#define AVIX_EVENT_GROUP_CLEAR		((tavixEventGroupOperation)	0	)
#define AVIX_EVENT_GROUP_SET		((tavixEventGroupOperation)	1	)
#define AVIX_EVENT_GROUP_TOGGLE		((tavixEventGroupOperation)	2	)



//=================================================================================================
// FUNCTION DECLARATIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
tavixEventId
	avixEventGroup_Get				(	tavixKernelObjectName		pName				);


//-------------------------------------------------------------------------------------------------
tavixEventId
	avixEventGroup_Create			(	tavixKernelObjectName		pName, 
										tavixEventFlags				initialEventFlags	);


//-------------------------------------------------------------------------------------------------
void
	avixEventGroup_Change			(	tavixEventId 				id,
										tavixEventGroupOperation	operation,
										tavixEventFlags  			eventFlags			);


//-------------------------------------------------------------------------------------------------
void
	avixEventGroup_ChangeFromISR	(	tavixEventId 				id,
										tavixEventGroupOperation	operation,
										tavixEventFlags  			eventFlags			);


//-------------------------------------------------------------------------------------------------
tavixEventFlags
	avixEventGroup_Wait				(	tavixEventId 				id,
										tavixEventFlags  			desiredEventFlags,
										tavixEventGroupCombine		combine,
										tavixEventFlags  			preClearMask,
										tavixEventFlags  			postClearMask		);


//-------------------------------------------------------------------------------------------------
tavixEventFlags
	avixEventGroup_GetEventFlags	(	tavixEventId 				id,
										tavixEventFlags  			postClearMask		);


#ifdef __cplusplus
}
#endif

#endif	// __AVIXEvent_h__
