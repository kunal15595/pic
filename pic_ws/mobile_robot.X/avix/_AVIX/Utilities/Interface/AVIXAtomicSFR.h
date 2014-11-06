#ifndef __AVIXAtomicSFR_h__
#define __AVIXAtomicSFR_h__

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
//	COPYRIGHT (C) 2006-2011 AVIX-RT EMBEDDED SOLUTIONS.  ALL RIGHTS RESERVED.
//
//	===============================================================================================
//
//	Description:
//  ------------
//	Generic utility definitions.
//
//	Error checking:
//	---------------
//	The avixSFR and avixSFR_Range macros can receive three different command codes, WRITE_BF,
//	READ_BF or INVERT_BF. These command codes are defined in this header. This command code is an
//	integer value and it is easy for the user of this macro to enter a wrong command value.
//
//	A mechanism is built into these macro's to check for this error. In case the macro is used with
//	a command value different than WRITE_BF, READ_BF or INVERT_BF, a compile time error is
//	generated like:
//
//	error: `_avixSFR_IllegalCommandValue_0' undeclared (first use in this function)
//
//	where instead of the zero (0), a different value can be present.
//
//=================================================================================================
// INCLUDES
//=================================================================================================
//
#include "AVIXPortDef.h"


//=================================================================================================
// EXTERNAL DECLARATIONS
//=================================================================================================
//


//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//


//=================================================================================================
// MACROS
//=================================================================================================
//
//	Command values that can be passed to the avixSFR macro. Any other value will result in a 
//	compilation error.
//
#define WRITE_BF 	0x9696
#define READ_BF 	0xa5a5
#define INVERT_BF 	0x5a5a


//	Macro's and typedefs to facilitate avixSFR checking the value of the command argument. For each
//	of the allowed command values a unique type is created. Based on the value passed to the
//	argument by the user, the avixSFR macro creates a type which if it not exists identifies a
//	wrong command value to be passed by the user.
//
#define _avixCheckerTypeReparse(a)	_avixSFR_IllegalCommandValue_##a
#define _avixCheckerType(a)			_avixCheckerTypeReparse(a)
		
typedef int _avixCheckerType(WRITE_BF);
typedef int _avixCheckerType(READ_BF);
typedef int _avixCheckerType(INVERT_BF);	




//	===============================================================================================
//	CONTROLLER SPECIFIC SETTINGS FOR MICROCHIP PIC24 AND dsPIC
//	===============================================================================================
//
#if (	(defined __AVIX_PIC24F__)	||	\
		(defined __AVIX_PIC24E__)	||	\
		(defined __AVIX_PIC24H__)	||	\
		(defined __AVIX_PIC30F__)	||	\
		(defined __AVIX_PIC33E__)	||	\
		(defined __AVIX_PIC33F__))

	//=============================================================================================
	// Internal helper macros not to be used by application code.
	//=============================================================================================
	//
	#define _avixParseStruct(a)			a##BITS
	#define _avixParseStructVar(a)		a##bits
	
	
	
	
	
	//=============================================================================================
	// Set, Invert or read a field from a Special Function Register (SFR)
	//=============================================================================================
	// Arguments:
	// r: SFR Register name as defined in the applicable parts header, e.g. LATA, AD1CON2 etc.
	// f: Field name as defined in the struct definition of the applicable SFR (bitfield)
	// c: Instruction, possible values: WRITE_BF, READ_BF or INVERT_BF
	// ... Only in case c is WRITE_BF, the numeric value to set in the applicable field 
	//=============================================================================================
	//
	#define avixSFR(r,f,c,...)							\
	({													\
		union											\
		{												\
			_avixParseStruct(r) o;						\
			unsigned int		i;						\
		} lcur , lmask={}, lval={}; lmask.o.f = -1;		\
		((c) == WRITE_BF)								\
		?({ 											\
			_avixCheckerType(c) v = __VA_ARGS__+0;		\
			if (lmask.i & (lmask.i-1))					\
			{											\
				lval.o.f = v;							\
				lcur.o = _avixParseStructVar(r);		\
				__asm__ __volatile__					\
				(	" xor %0			"				\
					: "=U"(r)							\
					: "a"(lmask.i & (lval.i^lcur.i)));	\
			}											\
			else										\
			{											\
				if ( v & 1)								\
				{										\
					_avixParseStructVar(r).f = 1;		\
				}										\
				else									\
				{										\
					_avixParseStructVar(r).f = 0;		\
				}										\
			}											\
		}), 0											\
		:((c) == INVERT_BF) 							\
		?({ 											\
			__asm__ __volatile__(" xor %0"				\
				:"=U"(r):"a"(lmask.i));					\
		}), 0	/* (c) == READ_BF */					\
		: _avixParseStructVar(r).f;} )





	//=============================================================================================
	// Set, Invert or read a field from a Special Function Register (SFR) where the field is 
	// specified as two numeric values, specifying the lower and the higher bit of the field. This
	// macro is typically used for the generic ports, A, B, C etc.
	//=============================================================================================
	// Arguments:
	// r: SFR Register name as defined in the applicable parts header, e.g. LATA, AD1CON2 etc.
	// l: Lower bitnumber of desired field
	// u: Upper bitnumber of desired field
	// c: Instruction, possible values: WRITE_BF, READ_BF or INVZ
	// ... Only in case c is WRITE_BF, the numeric value to set in the applicable field 
	//=============================================================================================
	//
	#define avixSFR_Range(r,l,u,c,...)							\
	({															\
		unsigned int lmask, lmaskl, lmasku;						\
		lmaskl = (1 << (l)); 									\
		lmasku = (1 << (u));									\
		lmask  = ((lmaskl-1) ^ (lmasku-1)) | lmaskl | lmasku;	\
		((c) == WRITE_BF)										\
		?({														\
			_avixCheckerType(c) v = __VA_ARGS__+0;				\
			v = (v << (((l) < (u)) ? (l) : (u))) & lmask;		\
			__asm__ __volatile__								\
			(	" xor %0": "=U"(r):"a"(lmask & (v ^ r)));		\
		}), 0													\
		:(((c) == INVERT_BF) 									\
		?({														\
			__asm__ __volatile__(" xor %0":"=U"(r):"a"(lmask));	\
		}), 0													\
		:({	/* (c) == READ_BF */								\
			(r & lmask) >> (((l) < (u)) ? (l) : (u));			\
		}));													\
	})

#endif	//  #if (	(defined __AVIX_PIC24F__)	||
		//			(defined __AVIX_PIC24E__)	||
		//			(defined __AVIX_PIC24H__)	||
		//			(defined __AVIX_PIC30F__)	||
		//			(defined __AVIX_PIC30E__)	||
		//			(defined __AVIX_PIC33F__))







//	===============================================================================================
//	CONTROLLER SPECIFIC SETTINGS FOR MICROCHIP PIC32MX
//	===============================================================================================
//
#if defined (__AVIX_PIC32MX__)

	//=============================================================================================
	// Internal helper macros not to be used by application code.
	//=============================================================================================
	//
	#define _avixParseSR(r,e)		r##e
	#define _avixParseFldDef(r,f,e)	_##r##_##f##_##e
	#define _avixParseStructVar(a)	a##bits





	//=============================================================================================
	// Set, Invert or read a field from a Special Function Register (SFR)
	//=============================================================================================
	// Arguments:
	// r: SFR Register name as defined in the applicable parts header, e.g. LATA, AD1CON2 etc.
	// f: Field name as defined in the struct definition of the applicable SFR (bitfield)
	// c: Instruction, possible values: WRITE_BF, READ_BF or INVERT_BF
	// ... Only in case c is WRITE_BF, the numeric value to set in the applicable field 
	//=============================================================================================
	//
	#define avixSFR(r,f,c,...)									\
	(((c) == WRITE_BF)											\
	?({															\
		_avixCheckerType(c) v = __VA_ARGS__+0;					\
		if (_avixParseFldDef(r,f,LENGTH) == 1)					\
		{														\
			if (v & 1)											\
			{													\
				_avixParseSR(r,SET) =							\
					_avixParseFldDef(r,f,MASK);					\
			}													\
			else												\
			{													\
				_avixParseSR(r,CLR) =							\
					_avixParseFldDef(r,f,MASK);					\
			}													\
		}														\
		else													\
		{														\
			_avixParseSR(r,INV) = 								\
				_avixParseFldDef(r,f,MASK) &					\
				(((v) << _avixParseFldDef(r,f,POSITION)) ^ r);	\
		}														\
	}), 0														\
	: 															\
	(((c) == INVERT_BF) 										\
	?															\
		(_avixParseSR(r,INV) = _avixParseFldDef(r,f,MASK)) 		\
	:	/* (c) == READ_BF */									\
		_avixParseStructVar(r).f ))





	//=============================================================================================
	// Set, Invert or read a field from a Special Function Register (SFR) where the field is 
	// specified as two numeric values, specifying the lower and the higher bit of the field. This
	// macro is typically used for the generic ports, A, B, C etc.
	//=============================================================================================
	// Arguments:
	// r: SFR Register name as defined in the applicable parts header, e.g. LATA, AD1CON2 etc.
	// l: Lower bitnumber of desired field
	// u: Upper bitnumber of desired field
	// c: Instruction, possible values: WRITE_BF, READ_BF or INVERT_BF
	// ... Only in case c is WRITE_BF, the numeric value to set in the applicable field 
	//=============================================================================================
	//
	#define avixSFR_Range(r,l,u,c,...)						\
	({														\
		unsigned int lmask, lmaskl, lmasku;					\
		lmaskl = (1 << (l)); 								\
		lmasku = (1 << (u));								\
		lmask = ((lmaskl-1) ^ (lmasku-1)) | lmaskl | lmasku;\
		((c) == WRITE_BF)									\
		?({													\
			_avixCheckerType(c) v = __VA_ARGS__+0;			\
			if ((l) == (u))									\
			{												\
				if( v & 1)									\
				{											\
					_avixParseSR(r,SET) = lmask;			\
				}											\
				else										\
				{											\
					_avixParseSR(r,CLR) = lmask;			\
				}											\
			}												\
			else											\
			{												\
				_avixParseSR(r,INV) = lmask & 				\
					(((v) << (((l)<(u))? (l): (u))) ^ r);	\
			}												\
		}), 0												\
		:(((c) == INVERT_BF) 								\
		?({ 												\
			_avixParseSR(r,INV) = lmask;					\
		}), 0												\
		:({ /* (c) == READ_BF */							\
			(r & lmask) >> (((l) < (u)) ? (l) : (u));		\
		}));												\
	})

#endif	// defined (__AVIX_PIC32MX__)





//	===============================================================================================
//	CONTROLLER SPECIFIC SETTINGS FOR CORTEX M3
//	===============================================================================================
//
#if defined (__AVIX_CORTEX_M3__)


#endif  // defined (__AVIX_CORTEX_M3__)




//=================================================================================================
// GLOBAL VARIABLES
//=================================================================================================
//


//=================================================================================================
// FORWARD FUNCTION DECLARATIONS
//=================================================================================================
//

#ifdef __cplusplus
}
#endif

#endif	// __AVIXAtomicSFR_h__
