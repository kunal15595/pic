#ifndef __AVIXMemory_h__
#define __AVIXMemory_h__

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
//	Memory management
//
//=================================================================================================
// INCLUDES
//=================================================================================================
//
#include <stdio.h>
#include "AVIXGeneric.h"
#include "AVIXObjectManager.h"
#include "AVIXSharedDefs.h"


//=================================================================================================
// INTERNAL MACROS (For AVIX use only, under no circumstance may application code use these macros)
// Reason these definition are present in an external interface header is that presence of EDS
// (Extended Memory) can only be determined when building the user application.
//=================================================================================================
//
#if (	defined (__AVIX_PIC24F__) || defined (__AVIX_PIC24E__) || 								\
		defined (__AVIX_PIC33E__)) && defined (__HAS_EDS__)
	#if (avix_EXTENDED_MEMORY > 0)
		#define AVIX_EDS						__eds__
		#define __EXTMEM_DIFF_PTR_TYPE__		1
	#else
		#define AVIX_EDS
		#define __EXTMEM_DIFF_PTR_TYPE__		0
	#endif
#else
	#define AVIX_EDS
	#define __EXTMEM_DIFF_PTR_TYPE__			0
#endif



//=================================================================================================
// EXTERNAL DECLARATIONS (Not for application use, AVIX internal use only!) Reason these definition 
// are present in an external interface header is that presence of EDS (Extended Memory) can only 
// be determined when building the user application.
//=================================================================================================
//
void*			_f_InternalMemPoolConvBlockIdToPtr(tavixMemBlockId memBlockId);
AVIX_EDS void*	_f_InternalMemPoolConvBlockIdToPtrExt(tavixMemBlockId memBlockId);



//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//


//=================================================================================================
// MACROS
//=================================================================================================
//
#define AVIX_MEM_BLOCK_ID_VALID(_id)			((_id._tsField) != NULL)

#if (__EXTMEM_DIFF_PTR_TYPE__ == 0)
	#define AVIX_MEM_BLOCK_PTR(_type,_id)		((_type*)_f_InternalMemPoolConvBlockIdToPtr(_id))
	#define AVIX_MEM_BLOCK_PTR_EXT(_type,_id)	((_type*)_f_InternalMemPoolConvBlockIdToPtr(_id))
#else
	#define AVIX_MEM_BLOCK_PTR(_type,_id)		((_type*)_f_InternalMemPoolConvBlockIdToPtr(_id))
	#define AVIX_MEM_BLOCK_PTR_EXT(_type,_id)	((AVIX_EDS _type*)_f_InternalMemPoolConvBlockIdToPtrExt(_id))
#endif



//=================================================================================================
// FUNCTION DECLARATIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
tavixMemPoolId
	avixMemPool_Create				(	tavixKernelObjectName	pName,
										unsigned int 			numBlocks,
										unsigned int			blockSize	);


//-------------------------------------------------------------------------------------------------
tavixMemPoolId
	avixMemPool_CreateExt			(	tavixKernelObjectName	pName,
										unsigned int			numBlocks,
										unsigned int			blockSize	);


//-------------------------------------------------------------------------------------------------
tavixMemPoolId
	avixMemPool_Get					(	tavixKernelObjectName	pName		);


//-------------------------------------------------------------------------------------------------
tavixMemBlockId
	avixMemPool_Allocate			(	tavixMemPoolId			poolId		);


//-------------------------------------------------------------------------------------------------
tavixMemBlockId
	avixMemPool_Free				(	tavixMemBlockId			memBlockId	);


//-------------------------------------------------------------------------------------------------
tavixMemBlockId
	avixMemPool_AllocateFromISR		(	tavixMemPoolId			poolId		);


//-------------------------------------------------------------------------------------------------
tavixMemBlockId
	avixMemPool_FreeFromISR			(	tavixMemBlockId			memBlockId	);


//-------------------------------------------------------------------------------------------------
int
	avixMemPool_GetSizeBlock		(	tavixMemBlockId			memBlockId	);


//-------------------------------------------------------------------------------------------------
int
	avixMemPool_GetSizeBlockFromISR (	tavixMemBlockId			memBlockId	);


#ifdef __cplusplus
}
#endif

#endif	// __AVIXMemory_h__
