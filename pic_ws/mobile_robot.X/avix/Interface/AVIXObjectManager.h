#ifndef __AVIXObjectManager_h__
#define __AVIXObjectManager_h__

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
//	All kernel objects have id's based on the same type safe mechanism. The required definitions
//	are in this file.
//
//=================================================================================================
// INCLUDES
//=================================================================================================
//
#include "AVIXGeneric.h"


//=================================================================================================
// MACROS
//=================================================================================================
//
// MACRO'S TO GENERATE TYPES FOR THE DIFFERENT KERNEL OBJECTS THAT ARE UNIQUE IN THE SENSE THAT
// MIXING THEM WILL GENERATE A COMPILER ERROR. THIS PREVENTS (COMPILE TIME) THAT FOR INSTANCE A
// MUTEX ID IS PASSED TO A FUNCTION REQUIRING A THREAD ID.
//-------------------------------------------------------------------------------------------------
// >>>> THESE MACROS ARE FOR AVIX INTERNAL USE ONLY AND MAY NOT BE USED IN AN APPLICATION !!!!
//-------------------------------------------------------------------------------------------------
//
#define _AVIX_KERNEL_TYPESAFE_EL(_t,_v)		(_t){._tsField = _v}
#define	_AVIX_KERNEL_TYPE(_t) 				typedef union {void* _tsField;		}_t
#define	_AVIX_KERNEL_TYPE_EXT(_t, _s) 		typedef union {void* _tsField; _s;	}_t




//-------------------------------------------------------------------------------------------------
// AVIX_OBJECT_ID_DEFINE:	Define a kernel object id guaranteed to be invalid (initial state).
// AVIX_OBJECT_ID_VALID:	Test if a kernel object id is valid (initialized).
// AVIX_OBJECT_ID_NULL:		Return a kernel object id having an invalid value.
//-------------------------------------------------------------------------------------------------
//
#define AVIX_OBJECT_ID_DEFINE(_type,_var)	_type _var = {._tsField = NULL}
#define AVIX_OBJECT_ID_VALID(_id)			(_id._tsField != NULL)
#define AVIX_OBJECT_ID_NULL(_type)			_AVIX_KERNEL_TYPESAFE_EL(_type, NULL)




//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//
// Kernel object name type, used for all different types of kernel objects
//-------------------------------------------------------------------------------------------------
//
typedef	const char*	tavixKernelObjectName;	// Human readable name


//-------------------------------------------------------------------------------------------------
// Unique id types for all kernel types based on the above described structure mechanism.
//-------------------------------------------------------------------------------------------------
//
_AVIX_KERNEL_TYPE		( tavixEventId     						);		// Full kernel object
_AVIX_KERNEL_TYPE_EXT	( tavixThreadId, tavixEventId asEventId	);		// Full kernel object
_AVIX_KERNEL_TYPE		( tavixMutexId     						);		// Full kernel object
_AVIX_KERNEL_TYPE		( tavixSemaphoreId 						);		// Full kernel object
_AVIX_KERNEL_TYPE		( tavixTimerId     						);		// Full kernel object
_AVIX_KERNEL_TYPE		( tavixPipeId      						);		// Full kernel object
_AVIX_KERNEL_TYPE		( tavixMemPoolId   						);		// Full kernel object
_AVIX_KERNEL_TYPE		( tavixExchId      						);		// Full kernel object

_AVIX_KERNEL_TYPE		( tavixMsgId       						);		// Basic kernel object
_AVIX_KERNEL_TYPE		( tavixMemBlockId  						);		// Basic kernel object
_AVIX_KERNEL_TYPE		( tavixExchConnId  						);		// Basic kernel object




//-------------------------------------------------------------------------------------------------
// tavixKernelObjectId:
// --------------------
// Type for passing kernel object id's of every kernel object type offered by AVIX to a function.
// AVIX uses this type with function avixMsg_PutKernelObjectId to put a kernel object id in a
// message. Foreseen usage of this type is through the C99 compound literal mechanism. Suppose a
// thread id named threadId must be passed to a message, this is accomplished using the following
// syntax:
//
//      avixMsg_PutKernelObjectId(msg, (tavixKernelObjectId){.thread = threadId } );
//                                     \                                        /
//                                      `--------------------------------------'
//                                        compound literal containing threadId
//
// A compound literal used like in this example is a temporary object of the designated agregate
// type which can be used everywhere a value of type tavixKernelObjectId is required. See C99
// language definitions for more details.
//-------------------------------------------------------------------------------------------------
//
typedef union
{
	tavixThreadId		thread;
	tavixMutexId		mutex;
	tavixSemaphoreId	semaphore;
	tavixEventId		event;
	tavixTimerId		timer;
	tavixPipeId			pipe;
	tavixMemPoolId		memPool;
	tavixExchId			exch;
	tavixMsgId			msg;
	tavixMemBlockId		memBlock;
	tavixExchConnId		exchConn;
} tavixKernelObjectId;





//-------------------------------------------------------------------------------------------------
// tavixKernelObjectIdp:
// ---------------------
// Type for passing kernel object id addresses of every kernel object type offered by AVIX to a
// function. AVIX uses this type with function avixMsg_GetKernelObjectId to get a kernel object id
// from a message. Foreseen usage of this type is through the C99 compound literal mechanism.
// Suppose a thread id must be read from a message, this is accomplished using the following
// syntax:
//
//      tavixThreadId threadId;
//      avixMsg_GetKernelObjectId(msg, (tavixKernelObjectId){.thread = &threadId } );
//                                     \                                        /
//                                      `--------------------------------------'
//                                    compound literal containing address of threadId
//
// A compound literal used like in this example is a temporary object of the designated agregate
// type which can be used everywhere a value of type tavixKernelObjectIdp is required. See C99
// language definitions for more details.
//-------------------------------------------------------------------------------------------------
//
typedef union
{
	tavixThreadId*		thread;
	tavixMutexId*		mutex;
	tavixSemaphoreId*	semaphore;
	tavixEventId*		event;
	tavixTimerId*		timer;
	tavixPipeId*		pipe;
	tavixMemPoolId*		memPool;
	tavixExchId*		exch;
	tavixMsgId*			msg;
	tavixMemBlockId*	memBlock;
	tavixExchConnId*	exchConn;
} tavixKernelObjectIdp;


#ifdef __cplusplus
}
#endif

#endif	// __AVIXObjectManager_h__
