#ifndef __AVIXGeneric_h__
#define __AVIXGeneric_h__

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
//	Generic definitions
//
//=================================================================================================
//
// INCLUDES
//
// NOTE: Symbols __AVIX_LIBGEN_PIC24_DSPIC__, __AVIX_LIBGEN_PIC32MX__ or __AVIX_LIBGEN_CORTEX_M3__
// may not be defined in the user environment. These are intended for AVIX-RT internal use.
//=================================================================================================
//
#include <limits.h>
#include "AVIXPortDef.h"

//-------------------------------------------------------------------------------------------------
// The xxx_LIBGEN_xxx symbols are defined for creating the AVIX libraries. Under no circumstance
// may these symbols be defined when building user applications.
//-------------------------------------------------------------------------------------------------
#if ( ! defined( __AVIX_LIBGEN_PIC24_DSPIC__ ))	&&	\
	( ! defined( __AVIX_LIBGEN_PIC32MX__	 ))	&&	\
	( ! defined( __AVIX_LIBGEN_CORTEX_M3__	 ))

	#include 	"..\SysDef\AVIXSystemSettings.h"

#endif



//=================================================================================================
// TYPE DEFINITIONS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
// Function prototype for a Defered Interrupt Handler (DIH)
//-------------------------------------------------------------------------------------------------
typedef void(*tavixDIH)(void *);


//=================================================================================================
// MACROS
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
//	Macros for user level type safe variable manipulation:
//-------------------------------------------------------------------------------------------------
//	-	AVIX_TYPESAFE_EQ: 		 Compare two type safe variables/constants for being equal
//	-	AVIX_TYPESAFE_NEQ: 		 Compare two type safe variables/constants for not being equal
//	-	AVIX_TYPESAFE_TO_VOID:	 Convert type safe variable to void* for passing to functions
//								 with a generic void* typed argument.
//	-	AVIX_TYPESAFE_FROM_VOID: Convert a void* to a type safe variable for use in functions with
//								 a generic void* typed argument.
//-------------------------------------------------------------------------------------------------
//
#define AVIX_TYPESAFE_EQ(_v1,_v2)		((_v1)._tsField == (_v2)._tsField)
#define AVIX_TYPESAFE_NEQ(_v1,_v2)		( ! AVIX_TYPESAFE_EQ((_v1), (_v2)))

#define AVIX_TYPESAFE_TO_VOID(_id)		((void*)((_id)._tsField))
#define AVIX_TYPESAFE_FROM_VOID(_id,_p)	{(_id)._tsField = (_p);}




//	===============================================================================================
//	CONTROLLER SPECIFIC SETTINGS FOR PIC24 AND dsPIC
//	===============================================================================================
//
#if (	(defined __AVIX_PIC24F__)				||	\
		(defined __AVIX_PIC24E__)				||	\
		(defined __AVIX_PIC24H__)				||	\
		(defined __AVIX_PIC30F__)				||	\
		(defined __AVIX_PIC33E__)				||	\
		(defined __AVIX_PIC33F__)				||	\
		(defined __AVIX_LIBGEN_PIC24_DSPIC__))

	#define AVIX_ASM			__asm__ __volatile__
	#define AVIX_NEAR			__attribute__((near))
	#define __AVIX_NORETURN		__attribute__((noreturn))
	#define __AVIX_TASK


	//---------------------------------------------------------------------------------------------
	// Macro to declare interrupt handlers (ISR's) that prevent the stack of each individual thread
	// to be used for storing a lot of interrupt context which would put a load on the stack of
	// every individual thread. This macro switches the stack pointer for an ISR to a system stack
	// area. When an interrupt occurs, 6 bytes are stored on the stack of the interrupted thread.
	// The stack is switched and the remainder of the interrupt context is stored on the (single)
	// system stack. When every ISR uses this macro, the worst case load on the stack of the thread
	// is 42 bytes, 6 bytes per interrupt times 7 levels. These 6 bytes are the 4 bytes from the
	// ISR (return address and SR) plus the content of register w0 which is used inside this macro.
	//
	// For saving the PSV register use could be made of the auto_psv option. This is not done for
	// reason of a bug related to auto_psv and the stack frame in version 3.10 of the compiler.
	// A workaround for this bug is using no_auto_psv so when the PSV register must be saved this
	// is done explicitly in the macro.
	//---------------------------------------------------------------------------------------------
	//
	extern volatile unsigned int	_avixCnfgSysStackTop;
	extern volatile unsigned int	_avixSysStackBottom;


	//---------------------------------------------------------------------------------------------
	// 	THE FOLLOWING MACRO'S  ARE NOT  ALLOWED TO  BE USED IN AN APPLICATION. THESE MACROS ARE
	//	USED TO DEFINE THE AVIX APPLICATION LEVEL INTERRUPT MACROS.
	//---------------------------------------------------------------------------------------------
	//
	#define _avixInternalISR_Prologue								\
			"	push	w0;										\n"	\
			"	mov		w15, w0;								\n"	\
			"	cp		_avixCnfgSysStackTop;					\n"	\
			"	bra		gtu, 0f;								\n"	\
			"	mov		_avixSysStackBottom, w15;				\n"	\
			"0:	push	w0;										\n"

	#define _avixInternalISR_Activate								\
			"	rcall 	1f;										\n"

	#define _avixInternalISR_Epilogue								\
			"	pop		w15;									\n"	\
			"	pop		w0;										\n"	\
			"	retfie;											\n"	\
			"1:	mov		SR, w0;									\n"	\
			"	mov.b	w0, [w15-1];				  			  "

	#if ((avix_DSP_ENABLED != 0) && ((defined __AVIX_PIC30F__) ||	\
	(defined __AVIX_PIC33E__) ||									\
	(defined __AVIX_PIC33F__)))
	
		#define _avixInternalISR_PushDSPAddrRegCond					\
			"	push	MODCON;									\n"	\
			"	mov		#0x0fff, w0;							\n"	\
			"	mov		w0, MODCON;								\n"
		#define _avixInternalISR_PopDSPAddrRegCond					\
			"	pop		MODCON;									\n"
	#else
	
		#define _avixInternalISR_PushDSPAddrRegCond
		#define _avixInternalISR_PopDSPAddrRegCond
	
	#endif

	#define _avixDeclareISRInternalUse(f,p,s)						\
																	\
		void __attribute__((__interrupt__							\
			(														\
				__preprologue__										\
				(	_avixInternalISR_Prologue						\
					_avixInternalISR_PushDSPAddrRegCond				\
					_avixInternalISR_Activate						\
					_avixInternalISR_PopDSPAddrRegCond				\
					_avixInternalISR_Epilogue						\
				)													\
			),														\
			p, s)) f(void)





	//=============================================================================================
	// These macro's are for user code ISR declaration.
	//---------------------------------------------------------------------------------------------
	//	avixDeclareISR:			Declare a regular ISR using the system stack
	//	avixDeclareISRShadow:	Declare an ISR using the shadow register and the system stack
	//---------------------------------------------------------------------------------------------
	//	Arguments:
	//	- f: Function name. This is the name belonging to the ISR this macro is used for. See
	//			Microchip documentation for a relation between ISR and ISR function name.
	//	- p: PSV usage, either 'no_auto_psv' if the ISR does not need to use the compiler managed
	//			PSV page. 'auto_psv' to set PSVPAG to the compiler managed PSV page and save and
	//			restore the current PSVPAG value.
	//=============================================================================================
	//
	#define avixDeclareISR(f,p)			_avixDeclareISRInternalUse(f,p,)
	#define avixDeclareISRShadow(f,p)	_avixDeclareISRInternalUse(f,p,shadow)


#endif  // (	(defined __AVIX_PIC24F__)						||
		//		(defined __AVIX_PIC24E__)						||
		//		(defined __AVIX_PIC24H__)						||
		//		(defined __AVIX_PIC30F__)						||
		//		(defined __AVIX_PIC33E__)						||
		//		(defined __AVIX_PIC33F__)						||
		//		(defined defined __AVIX_LIBGEN_PIC24_DSPIC__))











//	===============================================================================================
//	CONTROLLER SPECIFIC SETTINGS FOR PIC32MX
//	===============================================================================================
//
#if ((defined __AVIX_PIC32MX__) || (defined __AVIX_LIBGEN_PIC32MX__))

	#define AVIX_ASM			__asm__ __volatile__
	#define AVIX_NEAR
	#define __AVIX_NORETURN		__attribute__((noreturn))
	#define __AVIX_TASK


	//---------------------------------------------------------------------------------------------
	// PIC32 specific macro's for ISR system stack usage. When using these macro's for ISR
	// declaration ISR's use no stack space on the individual thread stack's. This greatly reduces
	// RAM usage. An average PIC32 ISR uses ~100 bytes to save the context and a  further ~50 bytes
	// when calling functions from the ISR. In the worst case interrupt nesting scenario, this
	// means 7 interrupts are active leading to a stack usage of ~1KB. Without using these macro's,
	// the stack of each individual thread has to anticipate for this meaning with 15 threads a
	// total of 15KB of RAM is used for interrupt context saving. When decclaring interrupts with
	// these macro's, the ISR switches to a system stack meaning all nested ISR's use the same
	// stack reducing the stack usage to a worst case of ~1KB, regardless the number of threads.
	//
	// Two macro's are present:
	// ------------------------
	// avixDeclareISR(v):		v is the vector number for which symbolic constants are defined in
	//							the controller specific header file. This macro can be used for any
	//							desired interrupt and interrupt priority.
	//
	// avixDeclareISRShadow(v):	v is the vector number for which symbolic constants are defined in
	//							the controller specific header file. This macro may only be used
	//							with priority 7 interrupts. Use is made of the shadow register set
	//							for ISR context saving which is automatically  activated for
	//							priority 7 interrupts. It is the user responsibility to set the
	//							priority for those interrupts to value 7. Using this macro with
	//							interrupts not having priority 7 leads to system failure.
	//
	// Important:	Note that the argument to these macro's differ from the argument passed to the
	//				same macro's present for PIC24F/PIC24H/dsPIC30F and dsPIC33F: For the PIC32
	//				version the argument to the macro's is the interrupt vector NUMBER. For the 16
	//				bit parts the argument to these macro's is the interrupt handler NAME.
	//
	//				For PIC32 shadow register usage is implictly related to interrupts with
	//				priority 7. This differs from the 16 bit parts where the priority level used
	//				with the shadow register set can be freely chosen.
	//---------------------------------------------------------------------------------------------
	//
	#define _ap1(a)		#a
	#define _ap0(a)		_ap1(a)
	#define _aps(r,o)	AVIX_ASM ("sw $"#r", "#o"($sp)")
	#define _apl(r,o)	AVIX_ASM ("lw $"#r", "#o"($sp)")

	#define avixDeclareISR(v)												\
	__attribute__((__noinline__)) void _func##v(void);						\
	void __attribute__((naked))__attribute__((vector(v))) _isr##v(void)		\
	{	AVIX_ASM (".set noreorder");										\
		AVIX_ASM (".set noat");												\
																			\
		AVIX_ASM (".extern	avixCnfgSysStackTop, 4");						\
																			\
		AVIX_ASM ("rdpgpr	$sp, $sp");										\
		AVIX_ASM ("lw		$k0, avixCnfgSysStackTop");						\
		AVIX_ASM ("sltu		$k1, $k0, $sp");								\
		AVIX_ASM ("movz		$k0, $sp, $k1");								\
		AVIX_ASM ("sw		$sp, -4($k0)");									\
		AVIX_ASM ("addiu	$sp, $k0, -112");								\
																			\
		AVIX_ASM ("mfc0    	$k0, $"_ap0(_CP0_CAUSE));						\
		AVIX_ASM ("mfc0		$k1, $"_ap0(_CP0_STATUS));						\
		AVIX_ASM ("srl		$k0, $k0," _ap0(_CP0_CAUSE_RIPL_POSITION));		\
		_aps(k1, 104);														\
		AVIX_ASM ("ins		$k1, $k0, "_ap0(_CP0_STATUS_IPL_POSITION)",		\
								"_ap0(_CP0_STATUS_IPL_LENGTH));				\
		AVIX_ASM ("mfc0    	$k0, $"_ap0(_CP0_EPC));							\
		AVIX_ASM ("ins		$k1, $zero, "_ap0(_CP0_STATUS_EXL_POSITION)",	\
								4");										\
		_aps(k0, 100);														\
		AVIX_ASM ("mtc0		$k1, $"_ap0(_CP0_STATUS));						\
																			\
		_aps(a0, 96);														\
		_aps(a1, 92);														\
		AVIX_ASM ("mflo		$a0");											\
		AVIX_ASM ("mfhi		$a1");											\
		_aps(a2, 88);														\
		_aps(a3, 84);														\
		_aps(t0, 80);														\
		_aps(t1, 76);														\
		_aps(t2, 72);														\
		_aps(t3, 68);														\
		_aps(t4, 64);														\
		_aps(t5, 60);														\
		_aps(t6, 56);														\
		_aps(t7, 52);														\
		_aps(t8, 48);														\
		_aps(t9, 44);														\
		_aps(at, 40);														\
		_aps(ra, 36);														\
		_aps(v0, 32);														\
		_aps(v1, 28);														\
		_aps(a0, 24);														\
																			\
		AVIX_ASM ("jal		_func"#v);										\
		_aps(a1, 20);														\
																			\
		_apl(a1, 20);														\
		_apl(a0, 24);														\
		AVIX_ASM ("mthi		$a1");											\
		AVIX_ASM ("mtlo		$a0");											\
		_apl(v1, 28);														\
		_apl(v0, 32);														\
		_apl(ra, 36);														\
		_apl(at, 40);														\
		_apl(t9, 44);														\
		_apl(t8, 48);														\
		_apl(t7, 52);														\
		_apl(t6, 56);														\
		_apl(t5, 60);														\
		_apl(t4, 64);														\
		_apl(t3, 68);														\
		_apl(t2, 72);														\
		_apl(t1, 76);														\
		_apl(t0, 80);														\
		_apl(a3, 84);														\
		_apl(a2, 88);														\
		_apl(a1, 92);														\
		_apl(a0, 96);														\
																			\
		AVIX_ASM ("di");													\
		AVIX_ASM ("ehb");													\
		_apl(k0, 100);														\
		_apl(k1, 104);														\
		AVIX_ASM ("mtc0		$k0, $"_ap0(_CP0_EPC));							\
		AVIX_ASM ("mtc0 	$k1, $"_ap0(_CP0_STATUS));						\
		_apl(sp, 108);														\
		AVIX_ASM ("eret");													\
		AVIX_ASM ("nop");													\
		AVIX_ASM (".set reorder");											\
		AVIX_ASM (".set at");												\
	} __attribute((__noinline__)) void _func##v(void)


	#define avixDeclareISRShadow(v)											\
	__attribute__((__noinline__)) void _func##v(void);						\
	void	__attribute__((naked))__attribute__((vector(v))) _isr##v(void)	\
	{	AVIX_ASM (".set noreorder");										\
		AVIX_ASM (".set noat");												\
																			\
		AVIX_ASM (".extern	avixCnfgSysStackTop, 4");						\
																			\
		AVIX_ASM ("rdpgpr	$sp, $sp");										\
		AVIX_ASM ("lw		$k0, avixCnfgSysStackTop");						\
		AVIX_ASM ("sltu		$k1, $k0, $sp");								\
		AVIX_ASM ("movz		$k0, $sp, $k1");								\
		AVIX_ASM ("sw		$sp, -4($k0)");									\
		AVIX_ASM ("mfc0		$k1, $"_ap0(_CP0_STATUS));						\
		AVIX_ASM ("addiu	$sp, $k0, -32");								\
																			\
		_aps(k1, 24);														\
		AVIX_ASM ("ori		$k1, $k1, "										\
								"7 << " _ap0(_CP0_STATUS_IPL_POSITION));	\
		AVIX_ASM ("ins		$k1, $zero, "_ap0(_CP0_STATUS_EXL_POSITION)",	\
											4");							\
		AVIX_ASM ("mtc0		$k1, $"_ap0(_CP0_STATUS));						\
		AVIX_ASM ("mflo		$k0");											\
		AVIX_ASM ("mfhi		$k1");											\
		_aps(k0, 20);														\
																			\
		AVIX_ASM ("jal		_func"#v);										\
		_aps(k1, 16);														\
																			\
		_apl(k1, 16);														\
		_apl(k0, 20);														\
		AVIX_ASM ("mthi		$k1");											\
		AVIX_ASM ("mtlo		$k0");											\
		_apl(k0, 24);														\
		_apl(sp, 28);														\
		AVIX_ASM ("mtc0 	$k0, $"_ap0(_CP0_STATUS));						\
		AVIX_ASM ("eret");													\
		AVIX_ASM ("nop");													\
		AVIX_ASM (".set reorder");											\
		AVIX_ASM (".set at");												\
	} __attribute__((__noinline__)) void _func##v(void)


#endif	// ((defined __AVIX_PIC32MX__) || (defined __AVIX_LIBGEN_PIC32MX__))












//	===============================================================================================
//	CONTROLLER SPECIFIC SETTINGS FOR CORTEX M3
//	===============================================================================================
//
#if ((defined __AVIX_CORTEX_M3__) || (defined __AVIX_LIBGEN_CORTEX_M3__))

	#define AVIX_ASM
	#define AVIX_NEAR

	#if defined (__AVIX_COMP_KEIL_ARMCC__)
		#define __AVIX_NORETURN		__attribute__((noreturn))
		#define __AVIX_TASK
	#endif

	#if defined (__AVIX_COMP_IAR_ICCARM__)
		#define __AVIX_NORETURN		__noreturn
		#define __AVIX_TASK			__task
	#endif




	//---------------------------------------------------------------------------------------------
	//	Since CORTEX-M3 offers a hardware system stack, no software implementation is needed.
	//	For reasons of compatibility with non CORTEX ports, these macros are still offered. All
	//	they offer is an alternative way of declaring the ISR.
	//---------------------------------------------------------------------------------------------
	//
	#define avixDeclareISR(ISRName)			void  ISRName(void)
	#define avixDeclareISRShadow(ISRName)	void  ISRName(void)

#endif  // ((defined __AVIX_CORTEX_M3__) || (defined __AVIX_LIBGEN_CORTEX_M3__))



//=================================================================================================
// FUNCTION DECLARATIONS
//=================================================================================================
//
extern void	avixDIH_Queue(tavixDIH, void*);


#ifdef __cplusplus
}
#endif

#endif	// __AVIXGeneric_h__
