#ifndef __AVIXPower_h__
#define __AVIXPower_h__

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
//	Power Mode definitions
//	
//=================================================================================================
// INCLUDES
//=================================================================================================
//
#include "AVIXObjectManager.h"
#include "AVIXPortDef.h"


//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//
typedef int 	tavixPowerMode;

typedef void (*tavixPowerCallbackFunc)(tavixPowerMode);


//-------------------------------------------------------------------------------------------------
// For the Cortex-M3 port only, the application may overrule the AVIX system timer with a custom
// implementation. This custom implementation is expected to callback to AVIX to inform AVIX a 
// timer period has elapsed. tavixSysTickHandler is the type of the AVIX function to callback.
//-------------------------------------------------------------------------------------------------
//
#if defined (__AVIX_CORTEX_M3__)
	typedef void (*tavixSysTickHandler)(void);
#endif



//=================================================================================================
// MACROS
//=================================================================================================
//
#define AVIX_POWER_REDUCTION_NONE	((tavixPowerMode)	0x0000	)
#define AVIX_POWER_REDUCTION_LOW	((tavixPowerMode)	0x0001	)
#define AVIX_POWER_REDUCTION_HIGH	((tavixPowerMode)	0x0002	)



//=================================================================================================
// FUNCTION DECLARATIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
void 			
	avixPower_SetMode			(	tavixPowerMode 			mode	);


//-------------------------------------------------------------------------------------------------
void 			
	avixPower_SetModeFromISR	(	tavixPowerMode 			mode	);


//-------------------------------------------------------------------------------------------------
tavixPowerMode	
	avixPower_GetMode			(	void							);


//-------------------------------------------------------------------------------------------------
tavixPowerMode	
	avixPower_GetModeFromISR	(	void							);


//-------------------------------------------------------------------------------------------------
void 			
	avixPower_SetCallback		(	tavixPowerCallbackFunc	pFunc	);




#ifdef __cplusplus
}
#endif

#endif	// __AVIXPower_h__
