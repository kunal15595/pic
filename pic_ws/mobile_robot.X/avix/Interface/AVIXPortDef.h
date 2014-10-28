#ifndef __AVIXPortDef_h__
#define __AVIXPortDef_h__

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
//	Definitions for the specific AVIX port (type of target controller and compiler)
//
//=================================================================================================
// MACROS
//=================================================================================================
//
// AVIX version numbering
//-------------------------------------------------------------------------------------------------
#define	__AVIX_VERSION_MAIN__	(5L)
#define	__AVIX_VERSION_SUB__	(0L)
#define __AVIX_VERSION_PATCH__	(0L)
#define	__AVIX_VERSION__		(	(	__AVIX_VERSION_MAIN__ 	<< 16	) | 					\
									(	__AVIX_VERSION_SUB__ 	<<  8	) | 					\
										__AVIX_VERSION_PATCH__			)



//-------------------------------------------------------------------------------------------------
// Determine the controller platform the build is intended for.
//-------------------------------------------------------------------------------------------------
//
#undef	__AVIX_PIC24F__
#undef	__AVIX_PIC24E__
#undef	__AVIX_PIC24H__
#undef	__AVIX_PIC30F__
#undef	__AVIX_PIC33E__
#undef	__AVIX_PIC33F__
#undef	__AVIX_PIC32MX__
#undef  __AVIX_CORTEX_M3__

#undef	__AVIX_COMP_MICROCHIP_C30__
#undef	__AVIX_COMP_MICROCHIP_XC16__
#undef	__AVIX_COMP_MICROCHIP_C32__
#undef	__AVIX_COMP_MICROCHIP_XC32__
#undef	__AVIX_COMP_KEIL_ARMCC__
#undef	__AVIX_COMP_IAR_ICCARM__


//-------------------------------------------------------------------------------------------------
// Controller definitions
//-------------------------------------------------------------------------------------------------
#if (defined __PIC24F__)
	#define	__AVIX_PIC24F__
#endif


//-------------------------------------------------------------------------------------------------
#if (defined __PIC24E__)
	#define	__AVIX_PIC24E__
#endif


//-------------------------------------------------------------------------------------------------
#if (defined __PIC24H__)
	#define	__AVIX_PIC24H__
#endif


//-------------------------------------------------------------------------------------------------
#if (defined __dsPIC30F__)
	#define	__AVIX_PIC30F__
#endif


//-------------------------------------------------------------------------------------------------
#if (defined __dsPIC33E__)
	#define	__AVIX_PIC33E__
#endif


//-------------------------------------------------------------------------------------------------
#if (defined __dsPIC33F__)
	#define	__AVIX_PIC33F__
#endif


//-------------------------------------------------------------------------------------------------
#if (defined __PIC32MX__)
	#define	__AVIX_PIC32MX__
#endif


//-------------------------------------------------------------------------------------------------
#if defined ( __CC_ARM)
	#if (defined __TARGET_CPU_CORTEX_M3)
		#define __AVIX_CORTEX_M3__
	#endif
#endif


//-------------------------------------------------------------------------------------------------
#if defined ( __ICCARM__ )
	#define __AVIX_CORTEX_M3__
#endif




//-------------------------------------------------------------------------------------------------
// Compiler definitions
//-------------------------------------------------------------------------------------------------
#if (defined C30) || (defined __C30__)
	#if !(defined XC16 || defined __XC16__)
		#define	__AVIX_COMP_MICROCHIP_C30__
	#endif
#endif


//-------------------------------------------------------------------------------------------------
#if (defined C30) || (defined __C30__)
	#if (defined XC16 || defined __XC16__)
		#define	__AVIX_COMP_MICROCHIP_XC16__
	#endif
#endif


//-------------------------------------------------------------------------------------------------
#if (defined __PIC32MX__)
	#if !(defined __XC32__ || defined __XC32)
		#define	__AVIX_COMP_MICROCHIP_C32__
	#endif
#endif


//-------------------------------------------------------------------------------------------------
#if (defined __PIC32MX__)
	#if (defined __XC32__ || defined __XC32)
		#define	__AVIX_COMP_MICROCHIP_XC32__
	#endif
#endif


//-------------------------------------------------------------------------------------------------
#if defined ( __CC_ARM)
	#define __AVIX_COMP_KEIL_ARMCC__
#endif


//-------------------------------------------------------------------------------------------------
#if defined ( __ICCARM__ )
	#define __AVIX_COMP_IAR_ICCARM__
#endif




//-------------------------------------------------------------------------------------------------
// When building in user environment, test if a controller is defined
//-------------------------------------------------------------------------------------------------
//
#if	( ! (defined __AVIX_LIBGEN_PIC24_DSPIC__	)) &&	\
	( ! (defined __AVIX_LIBGEN_PIC32MX__		)) &&	\
	( ! (defined __AVIX_LIBGEN_CORTEX_M3__		)) &&	\
	( !	(defined __AVIX_NO_COMPILER_CHECK__		))

	//---------------------------------------------------------------------------------------------
	#if ( ! (defined __AVIX_PIC24F__	)) &&	\
		( ! (defined __AVIX_PIC24E__	)) &&	\
		( ! (defined __AVIX_PIC24H__	)) &&	\
		( ! (defined __AVIX_PIC30F__	)) &&	\
		( ! (defined __AVIX_PIC33E__	)) &&	\
		( ! (defined __AVIX_PIC33F__	)) &&	\
		( ! (defined __AVIX_PIC32MX__	)) &&	\
		( ! (defined __AVIX_CORTEX_M3__	))

		#error "Target controller not defined, please read applicable AVIX porting manual for details"

	#endif	// Controller check


	//---------------------------------------------------------------------------------------------
	// Test if the correct compiler is defined
	//---------------------------------------------------------------------------------------------
	//
	#undef __AVIX_COMP_DEFINITION_ERROR
	
	#if 	(	defined __AVIX_PIC24F__	) ||	\
			(	defined __AVIX_PIC24E__	) ||	\
			(	defined __AVIX_PIC24H__	) ||	\
			(	defined __AVIX_PIC30F__	) ||	\
			(	defined __AVIX_PIC33E__	) ||	\
			(	defined __AVIX_PIC33F__	)
	
		#if (defined __AVIX_COMP_MICROCHIP_C30__ || defined __AVIX_COMP_MICROCHIP_XC16__)
			#if (defined __AVIX_COMP_MICROCHIP_C30__ && defined __AVIX_COMP_MICROCHIP_XC16__)
				#define __AVIX_COMP_DEFINITION_ERROR
			#else
				#if (	defined __AVIX_COMP_MICROCHIP_C32__		)	||	\
					(	defined __AVIX_COMP_MICROCHIP_XC32__	)	||	\
					(	defined __AVIX_COMP_KEIL_ARMCC__		)	||	\
					(	defined __AVIX_COMP_IAR_ICCARM__		)
					#define __AVIX_COMP_DEFINITION_ERROR
				#endif
			#endif
		#else
			#define __AVIX_COMP_DEFINITION_ERROR
		#endif
	
	#elif 	(	defined __AVIX_PIC32MX__	)
	
		#if (defined __AVIX_COMP_MICROCHIP_C32__ || defined __AVIX_COMP_MICROCHIP_XC32__)
			#if (defined __AVIX_COMP_MICROCHIP_C32__ && defined __AVIX_COMP_MICROCHIP_XC32__)
				#define __AVIX_COMP_DEFINITION_ERROR
			#else
				#if (	defined __AVIX_COMP_MICROCHIP_C30__		)	||	\
					(	defined __AVIX_COMP_MICROCHIP_XC16__	)	||	\
					(	defined __AVIX_COMP_KEIL_ARMCC__		)	||	\
					(	defined __AVIX_COMP_IAR_ICCARM__		)
					#define __AVIX_COMP_DEFINITION_ERROR
				#endif
			#endif
		#else
			#define __AVIX_COMP_DEFINITION_ERROR
		#endif
	
	#elif 	(	defined __AVIX_CORTEX_M3__	)
	
		#if (defined __AVIX_COMP_KEIL_ARMCC__ || defined __AVIX_COMP_IAR_ICCARM__)
			#if (defined __AVIX_COMP_KEIL_ARMCC__ && defined __AVIX_COMP_IAR_ICCARM__)
				#define __AVIX_COMP_DEFINITION_ERROR
			#else
				#if (	defined __AVIX_COMP_MICROCHIP_C30__		)	||	\
					(	defined __AVIX_COMP_MICROCHIP_XC16__	)	||	\
					(	defined __AVIX_COMP_MICROCHIP_C32__		)	||	\
					(	defined __AVIX_COMP_MICROCHIP_XC32__	)
					#define __AVIX_COMP_DEFINITION_ERROR
				#endif
			#endif
		#else
			#define __AVIX_COMP_DEFINITION_ERROR
		#endif
	
	#else
	
		#define __AVIX_COMP_DEFINITION_ERROR
	
	#endif
	
	#if defined __AVIX_COMP_DEFINITION_ERROR
		#error Error in compiler definition, please contact AVIX-RT
	#endif

#endif	// User environment build check


//-------------------------------------------------------------------------------------------------
// Macro to prevent AVIX applications from being compiled with C30 version 3.02 because of a bug in
// this version of the compiler
//-------------------------------------------------------------------------------------------------
//
#if defined __AVIX_COMP_MICROCHIP_C30__
	#if __C30_VERSION__ == 302
		#error A bug in C30 version 3.02 makes AVIX incompatible with this version of the compiler
	#endif
#endif


#ifdef __cplusplus
}
#endif

#endif	// __AVIXPortDef_h__
