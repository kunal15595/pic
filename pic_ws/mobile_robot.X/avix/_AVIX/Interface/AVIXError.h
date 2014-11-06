#ifndef __AVIXError_h__
#define __AVIXError_h__

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
//	Error code definitions
//	
//=================================================================================================
//
//=================================================================================================
// INCLUDES
//=================================================================================================
//


//=================================================================================================
// EXTERNAL DECLARATIONS
//=================================================================================================
//


//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//
typedef int	tavixErrorCode;
typedef void (*tavixErrorFunc)(tavixErrorCode errorCode);


//=================================================================================================
// MACROS
//=================================================================================================
//
#define	AVIXE_NO_ERROR											((tavixErrorCode)	0		)

#define	AVIXE_SYSTEM_DISTRIBUTION_LIMIT_REACHED					((tavixErrorCode)	1		)
#define	AVIXE_SYSTEM_OUT_OF_MEMORY								((tavixErrorCode)	2		)
#define	AVIXE_SYSTEM_THREAD_FUNCTION_RETURNED					((tavixErrorCode)	3		)
	
#define	AVIXE_KERNEL_OBJECT_GET_WITH_NO_NAME					((tavixErrorCode)	100		)
#define	AVIXE_KERNEL_OBJECT_DUPLICATE_OBJECT_NAME				((tavixErrorCode)	101		)
#define	AVIXE_KERNEL_OBJECT_SAME_NAME_DIFFERENT_TYPES			((tavixErrorCode)	102		)

#define	AVIXE_THREAD_PRIORITY_OUT_OF_CONFIGURED_RANGE			((tavixErrorCode)	200		)
#define	AVIXE_THREAD_ILLEGAL_TIMEOUT_SEQUENCE					((tavixErrorCode)	201		)

#define	AVIXE_TIMER_INVALID_ARGUMENT_VALUE						((tavixErrorCode)	300		)
#define	AVIXE_TIMER_INVALID_FUNCTION_IN_UNINITIALIZED_STATE 	((tavixErrorCode)	301		)
	
#define	AVIXE_MUTEX_UNLOCK_ATTEMPT_NOT_BY_OWNING_THREAD			((tavixErrorCode)	400		)
#define	AVIXE_MUTEX_UNLOCK_CALLED_WHEN_NOT_LOCKED				((tavixErrorCode)	401		)
#define	AVIXE_MUTEX_DEADLOCK									((tavixErrorCode)	402		)

#define	AVIXE_SEMAPHORE_INVALID_ARGUMENT_VALUE					((tavixErrorCode)	500		)
	
#define	AVIXE_MSG_WRITER_IS_NOT_OWNER_OF_MSG					((tavixErrorCode)	600		)
#define	AVIXE_MSG_WRITE_OUTSIDE_MSG_BODY						((tavixErrorCode)	601		)
#define	AVIXE_MSG_READER_IS_NOT_OWNER_OF_MSG					((tavixErrorCode)	602		)
#define	AVIXE_MSG_READ_OUTSIDE_MSG_BODY							((tavixErrorCode)	603		)
#define	AVIXE_MSG_REPLY_TO_INVALID_THREAD						((tavixErrorCode)	604		)
#define AVIXE_MSG_ALLOCATE_WITHOUT_MESSAGE_POOL_CONFIGURED		((tavixErrorCode)	605		)
	
#define	AVIXE_MEMPOOL_INVALID_ARGUMENT_VALUE					((tavixErrorCode)	700		)
#define	AVIXE_MEMPOOL_MAX_NR_POOLS_REACHED						((tavixErrorCode)	701		)
#define	AVIXE_MEMPOOL_INVALID_BLOCK_ID							((tavixErrorCode)	702		)
#define	AVIXE_MEMPOOL_EXT_MEM_OUT_OF_MEMORY						((tavixErrorCode)	703		)

#define AVIXE_EXCHANGE_INVALID_ARGUMENT_VALUE					((tavixErrorCode)	800		)
#define AVIXE_EXCHANGE_FUNC_NOT_ALLOWED_FROM_CALLBACK			((tavixErrorCode)	801		)
#define AVIXE_EXCHANGE_MESSAGE_SIZE_TOO_SMALL					((tavixErrorCode)	802		)
#define AVIXE_EXCHANGE_PIPE_BLOCK_SIZE_NOT_EQUAL_EXCHANGE_SIZE	((tavixErrorCode)	803		)
#define AVIXE_EXCHANGE_DUPLICATE_CONNECTION						((tavixErrorCode)	804		)

#define AVIXE_EVENT_GROUP_INVALID_ARGUMENT_VALUE				((tavixErrorCode)	900		)
	
#define	AVIXE_USER_ERROR_BASE									((tavixErrorCode)	10000	)



#ifdef AVIX_DEBUG
	#define AVIX_ASSERT(_condition, _code)		if (!(_condition)) {avixError_Throw(_code);}
#else
	#define AVIX_ASSERT(_condition, _code)
#endif
#define AVIX_ASSERT_ALWAYS(_condition, _code)	if (!(_condition)) {avixError_Throw(_code);}



//=================================================================================================
// FUNCTION DECLARATIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
void
	avixError_SetHandler	(	tavixErrorFunc pErrorFunc		);


//-------------------------------------------------------------------------------------------------
void
	avixError_Throw			(	tavixErrorCode userErrorCode	);


#ifdef __cplusplus
}
#endif

#endif	// __AVIXError_h__
