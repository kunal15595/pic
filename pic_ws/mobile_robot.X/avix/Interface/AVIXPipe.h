#ifndef __AVIXPipe_h__
#define __AVIXPipe_h__

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
//	Pipe definitions
//
//=================================================================================================
// INCLUDES
//=================================================================================================
//
#include "AVIXEvent.h"
#include "AVIXThread.h"


//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
// Type used to pass the event parameter to a pipe callback function.
//-------------------------------------------------------------------------------------------------
typedef int 	tavixPipeEvent;


//-------------------------------------------------------------------------------------------------
// Type used for a pipe callback function.
//-------------------------------------------------------------------------------------------------
typedef void 	(*tavixPipeCallback)(tavixPipeEvent event, int nrBlocks, void* pUserData);


//-------------------------------------------------------------------------------------------------
// Type used to identify the status of an asynchronous request.
//-------------------------------------------------------------------------------------------------
typedef int 	tavixPipeAsyncRegStatus;


//-------------------------------------------------------------------------------------------------
// Type used to identify an asynchronous request.
//-------------------------------------------------------------------------------------------------
typedef struct {const volatile void* _asyncStat;}	tavixPipeAsyncReqId;



//=================================================================================================
// MACRO'S
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
// Values passed as the first parameter of a pipe callback function (type tavixPipeEvent).
//-------------------------------------------------------------------------------------------------
//
#define PIPEINFO_READ_FROM_EMPTY_PIPE	((tavixPipeEvent)	0	)
#define PIPEINFO_PIPE_DATA_WRITTEN		((tavixPipeEvent)	1	)
#define PIPEINFO_DEVICE_STOP_REQUESTED	((tavixPipeEvent)	2	)


//-------------------------------------------------------------------------------------------------
// Return values for function avixPipe_GetStatusAsyncReq (type tavixPipeAsyncRegStatus)
//-------------------------------------------------------------------------------------------------
//
#define PIPE_ASYNCREQ_ABORTED			((tavixPipeAsyncRegStatus)	0	)
#define PIPE_ASYNCREQ_FINISHED			((tavixPipeAsyncRegStatus)	1	)
#define PIPE_ASYNCREQ_PENDING			((tavixPipeAsyncRegStatus)	2	)



//=================================================================================================
// FUNCTION DECLARATIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
tavixPipeId 				
	avixPipe_Create				(	tavixKernelObjectName		pName,
									unsigned int 				numBlocks,
									unsigned int 				blockSize,
									tavixPipeCallback			pCallback,
									const void*					pUserData			);


//-------------------------------------------------------------------------------------------------
tavixPipeId					
	avixPipe_Get				(	tavixKernelObjectName		pName				);


//-------------------------------------------------------------------------------------------------
void						
	avixPipe_FlushAndAbort		(	tavixPipeId 				pipeId				);


//-------------------------------------------------------------------------------------------------
void						
	avixPipe_WriteAsync			(	tavixPipeId 				pipeId,
									const void* 				pWriteBuffer,
									unsigned int 				nrBlocksToWrite,
									tavixEventId				readyEvent,
									tavixEventFlags				readyFlags,
									tavixPipeAsyncReqId*		pReqId				);


//-------------------------------------------------------------------------------------------------
void						
	avixPipe_ReadAsync			(	tavixPipeId 				pipeId,
									void* 						pReadBuffer,
									unsigned int 				nrBlocksToRead,
									tavixEventId				readyEvent,
									tavixEventFlags				readyFlags,
									tavixPipeAsyncReqId*		pReqId				);


//-------------------------------------------------------------------------------------------------
tavixPipeAsyncRegStatus		
	avixPipe_GetStatusAsyncReq	(	const tavixPipeAsyncReqId*	pReqId,
									unsigned int*				pNrBlocksProcessed	);


//-------------------------------------------------------------------------------------------------
tavixPipeAsyncRegStatus		
	avixPipe_AbortAsyncReq		(	tavixPipeAsyncReqId*		pReqId,
									unsigned int*				pNrBlocksProcessed	);


//-------------------------------------------------------------------------------------------------
unsigned int				
	avixPipe_Write				(	tavixPipeId 				pipeId,
									const void* 				pWritebuffer,
									unsigned int 				nrBlocksToWrite		);


//-------------------------------------------------------------------------------------------------
unsigned int				
	avixPipe_Read				(	tavixPipeId 				pipeId,
									void* 						pReadbuffer,
									unsigned int				nrBlocksToRead		);


//-------------------------------------------------------------------------------------------------
int				
	avixPipe_WriteFromISR		(	tavixPipeId 				pipeId,
									const void* 				pWriteBuffer,
									int 						nrBlocksToWrite		);


//-------------------------------------------------------------------------------------------------
int				
	avixPipe_ReadFromISR		(	tavixPipeId 				pipeId,
									void* 						pReadBuffer,
									int							nrBlocksToRead		);


//-------------------------------------------------------------------------------------------------
void						
	avixPipe_StopDeviceFromISR	(	tavixPipeId 				pipeId,
									int 						count				);
								

//-------------------------------------------------------------------------------------------------
void						
	avixPipe_SetHandlerTracePort(	tavixPipeId 				pipeId,
									tavixThreadTracePort 		port, 
									unsigned int bit								);



#ifdef __cplusplus
}
#endif

#endif	// __AVIXPipe_h__
