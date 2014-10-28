#ifndef __AVIXMsg_h__
#define __AVIXMsg_h__

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
//	------------
//	Message functionality
//
//=================================================================================================
// INCLUDES
//=================================================================================================
//
#include "AVIXObjectManager.h"
#include "AVIXThread.h"
#include "AVIXEvent.h"


//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
// 	A message has a type so in case a thread can receive multiple types, it can distinguish them to
//	'know' what the structure of the content is.
//-------------------------------------------------------------------------------------------------
//
typedef unsigned char tavixMsgType;



//=================================================================================================
// MACROS
//=================================================================================================
//
#define avixMsg_PutCharFromISR(_msg,_cont)				avixMsg_PutChar			 ((_msg), (_cont))
#define avixMsg_PutShortFromISR(_msg,_cont)				avixMsg_PutShort		 ((_msg), (_cont))
#define avixMsg_PutIntFromISR(_msg,_cont)				avixMsg_PutInt			 ((_msg), (_cont))
#define avixMsg_PutLongFromISR(_msg,_cont)				avixMsg_PutLong			 ((_msg), (_cont))
#define avixMsg_PutPtrFromISR(_msg,_cont)				avixMsg_PutPtr			 ((_msg), (_cont))
#define avixMsg_PutKernelObjectIdFromISR(_msg,_cont)	avixMsg_PutKernelObjectId((_msg), (_cont))
#define avixMsg_PutIndirectFromISR(_msg,_cont,_size)	avixMsg_PutIndirect		 ((_msg), (_cont), (_size))


//=================================================================================================
// FUNCTION DECLARATIONS
//=================================================================================================
//
tavixMsgId 	 	avixMsg_Allocate					(	tavixMsgType			msgType			);
tavixMsgId 		avixMsg_AllocateFromISR				(	tavixMsgType 			msgType			);
void 		 	avixMsg_Reuse						(	tavixMsgId 				msgId, 
														tavixMsgType 			msgType			);
void 		 	avixMsg_Free						(	tavixMsgId 				msgId			);

tavixMsgType	avixMsg_GetType						(	tavixMsgId 				msgId			);
tavixThreadId	avixMsg_GetSender					(	tavixMsgId 				msgId			);

void 		 	avixMsg_PutChar						(	tavixMsgId 				msgId, 
														unsigned char			msgContent		);
void 		 	avixMsg_PutShort					(	tavixMsgId 				msgId, 
														unsigned short			msgContent		);
void 		 	avixMsg_PutInt						(	tavixMsgId 				msgId, 
														unsigned int			msgContent		);
void 		 	avixMsg_PutLong						(	tavixMsgId 				msgId, 
														unsigned long			msgContent		);
void 		 	avixMsg_PutPtr						(	tavixMsgId 				msgId, 
														const void*				msgContent		);
void 		 	avixMsg_PutKernelObjectId			(	tavixMsgId 				msgId, 
														tavixKernelObjectId		msgContent		);
void 		 	avixMsg_PutIndirect					(	tavixMsgId 				msgId, 
														const void*				msgContent, 
														int 					msgContentSize	);

unsigned char	avixMsg_GetChar						(	tavixMsgId 				msgId			);
unsigned short	avixMsg_GetShort					(	tavixMsgId 				msgId			);
unsigned int  	avixMsg_GetInt			 			(	tavixMsgId 				msgId			);
unsigned long 	avixMsg_GetLong						(	tavixMsgId 				msgId			);
void*		 	avixMsg_GetPtr						(	tavixMsgId 				msgId			);
void 		 	avixMsg_GetKernelObjectId			(	tavixMsgId 				msgId, 
														tavixKernelObjectIdp	pKernelId		);
void 		 	avixMsg_GetIndirect					(	tavixMsgId				msgId, 
														void*					msgContent, 
														int 					msgContentSize	);


void 	  	 	avixMsgQThread_Send					(	tavixMsgId 				msg, 
														tavixThreadId			destThread		);
void 	  	 	avixMsgQThread_SendFromISR			(	tavixMsgId 				msg, 
														tavixThreadId 			destThread		);
void 	  	 	avixMsgQThread_Reply				(	tavixMsgId 				msg				);
tavixMsgId	 	avixMsgQThread_Receive				(	void);

void			avixMsgQThread_Flush				(	void									);

void			avixMsgQThread_ConnectEventGroup	(	tavixThreadId			receivingThread,
														tavixEventId			event,
														tavixEventFlags 		eventFlags		);

void 			avixMsgQThread_DisconnectEventGroup(	tavixThreadId			receivingThread	);


#ifdef __cplusplus
}
#endif

#endif	// __AVIXMsg_h__
