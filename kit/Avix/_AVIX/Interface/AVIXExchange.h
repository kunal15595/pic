#ifndef __AVIXExchange_h__
#define __AVIXExchange_h__

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
//	Exchange definitions
//
//=================================================================================================
// INCLUDES
//=================================================================================================
//
#include <stdio.h>
#include "AVIXGeneric.h"
#include "AVIXThread.h"
#include "AVIXPipe.h"
#include "AVIXEvent.h"
#include "AVIXMsg.h"


//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
// - tavixExchCallbackThread: Function prototype for callback functions receiveing a threadId as 
//		kernel object parameter.
//
// tavixExchCallbackPipe: Function prototype for callback functions receiveing a pipeId as kernel 
//		object parameter.
//
// tavixExchCallbackEventGroup: Function prototype for callback functions receiving an event group 
//		id as kernel object parameter.
//-------------------------------------------------------------------------------------------------
//
typedef void (*tavixExchCallbackThread)		(	tavixExchId		exch,
												const void*		pData,
												unsigned int	size,
												tavixThreadId	threadId,
												unsigned short	userParam		);

typedef void (*tavixExchCallbackPipe)		(	tavixExchId		exch,
												const void*		pData,
												unsigned int	size,
												tavixPipeId		pipeId,
												unsigned short	userParam		);

typedef void (*tavixExchCallbackEventGroup)	(	tavixExchId		exch,
												const void*		pData,
												unsigned int	size,
												tavixEventId	eventGroupId,
												unsigned short	userParam		);



//=================================================================================================
// MACROS
//=================================================================================================
//
#define AVIX_EXCH_DATA_PTR(_type,_p)		((_type*)(_p))
#define AVIX_EXCH_DATA_PTR_READ(_type,_p)	AVIX_EXCH_DATA_PTR(const _type,_p)



//=================================================================================================
// FUNCTION DECLARATIONS
//=================================================================================================
//
// ------------------------------------------------------------------------------------------------
// Basic exchange creation and property access
// ------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
tavixExchId		
	avixExch_Create				(	tavixKernelObjectName	pName,
									unsigned int			size,
									const void*				pData	);


//-------------------------------------------------------------------------------------------------
tavixExchId		
	avixExch_Get				(	tavixKernelObjectName 	pName	);


//-------------------------------------------------------------------------------------------------
tavixThreadId	
	avixExch_GetLastWriteThread	(	tavixExchId exchangeId			);


//-------------------------------------------------------------------------------------------------
unsigned int	
	avixExch_GetSize			(	tavixExchId exchangeId			);


// ------------------------------------------------------------------------------------------------
// Subscriber connection
// ------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
tavixExchConnId 
	avixExch_ConnectCallbackEventGroup	(	tavixExchId 				exchangeId,
											tavixExchCallbackEventGroup	pCallback,
											tavixEventId				eventId,
											unsigned short				userParam	);


//-------------------------------------------------------------------------------------------------
tavixExchConnId	
	avixExch_ConnectCallbackPipe		(	tavixExchId 				exchangeId,
											tavixExchCallbackPipe		pCallback,
											tavixPipeId					pipeId,
											unsigned short				userParam	);


//-------------------------------------------------------------------------------------------------
tavixExchConnId 
	avixExch_ConnectCallbackThread		(	tavixExchId 				exchangeId,
											tavixExchCallbackThread		pCallback,
											tavixThreadId				threadId,
											unsigned short				userParam	);


//-------------------------------------------------------------------------------------------------
tavixExchConnId	
	avixExch_ConnectEventGroup			(	tavixExchId					exchangeId,
											tavixEventId 				eventId,
											tavixEventFlags				flags		);


//-------------------------------------------------------------------------------------------------
tavixExchConnId	
	avixExch_ConnectMsgQThread			(	tavixExchId 				exchangeId,
											tavixThreadId 				threadId,
											tavixMsgType 				msgType		);


//-------------------------------------------------------------------------------------------------
tavixExchConnId 
	avixExch_ConnectPipe				(	tavixExchId 				exchangeId,
											tavixPipeId 				pipeId		);


// ------------------------------------------------------------------------------------------------
// Connection management
// ------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void 			
	avixExch_DisableActiveConnection	(	tavixExchId	 		exchangeId			);


//-------------------------------------------------------------------------------------------------
void 			
	avixExch_DisableAllConnections		(	tavixExchId	 		exchangeId			);


//-------------------------------------------------------------------------------------------------
void  			
	avixExch_DisableConnection			(	tavixExchConnId		connectionId		);


//-------------------------------------------------------------------------------------------------
void 			
	avixExch_EnableAllConnections		(	tavixExchId	 		exchangeId			);


//-------------------------------------------------------------------------------------------------
void  			
	avixExch_EnableConnection			(	tavixExchConnId		connectionId		);


//-------------------------------------------------------------------------------------------------
tavixExchId 	
	avixExch_GetConnectionExch			(	tavixExchConnId		connectionId		);


//-------------------------------------------------------------------------------------------------
int  			
	avixExch_GetConnectionMode			(	tavixExchConnId		connectionId		);


// ------------------------------------------------------------------------------------------------
// Safe read/write access
// ------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void 			
	avixExch_Read					(	tavixExchId		exchangeId,
										void*			pBuffer,
										tavixThreadId*	pThreadId					);


//-------------------------------------------------------------------------------------------------
int				
	avixExch_Write					(	tavixExchId		exchangeId,
										const void*		pBuffer						);


// ------------------------------------------------------------------------------------------------
// Direct read/write access
// ------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void*			
	avixExch_Lock					(	tavixExchId exchangeId						);


//-------------------------------------------------------------------------------------------------
void			
	avixExch_Unlock					(	tavixExchId exchangeId						);


//-------------------------------------------------------------------------------------------------
int	 			
	avixExch_UnlockAndNotify		(	tavixExchId exchangeId						);


#ifdef __cplusplus
}
#endif

#endif	// __AVIXExchange_h__
