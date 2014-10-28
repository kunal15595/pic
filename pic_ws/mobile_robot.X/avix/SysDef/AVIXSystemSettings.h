#ifndef __AVIXSystemSettings_h__
#define __AVIXSystemSettings_h__

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
//  CONTROLLER FAMILY:	PIC24-dsPIC
//	DISTRIBUTION TYPE:	DEMO
//
//=================================================================================================
//
//	IMPORTANT NOTICE:
//	-----------------
//	THIS FILE CONTAINS  THE SETTINGS FOR  THE AVIX CONFIGURABLE  PARAMETERS. DEPENDING  ON THE AVIX
//	DISTRIBUTION TYPE A SUBSET OF THESE PARAMETER MAY BE CHANGED.  REGARDLESS THE AVIX DISTRIBUTION
//	TYPE, THIS  FILE CONTAINS  ALL CONFIGURATION  PARAMETERS WHERE  THE  PARAMETERS THAT MAY NOT BE
//	CHANGED  ARE  CLEARLY IDENTIFIED.  THIS FILE  DOES CONTAIN  ALL  PARAMETERS (CHANGEBLE  AND NOT
//	CHANGEABLE) AS A REFERENCE FOR THE USER AND  SINCE A NUMBER OF  THESE VALUES ARE USED FROM AVIX
//	HEADER FILES.
//
//	=========== DO NOT CHANGE ANY PARAMETER IDENTIFIED BY A "DO NOT CHANGE,..." COMMENT ===========
//
//	========================= ALWAYS KEEP THE ORIGINAL FILE AS A BACKUP. ==========================
//
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
//	---------- COPYRIGHT (C) 2006-2012 AVIX-RT EMBEDDED SOLUTIONS.  ALL RIGHTS RESERVED -----------
//
//	===============================================================================================
//
//	Below are the user configurable settings. These have the following meaning:
//
//	- avix_DEVICE_CLOCKhz: 			Frequency in  Herz the devices are clocked with (device speed).
//									This value is  used by  AVIX to  derive the  settings  for  the
//									hardware timer which is used for  all timing related functiona-
//									lity. Note this value is  not neceserally the same as the clock
//									of the controllers  CPU core.  Great care  must  be taken  this
//									value is correct in order for all timing  related functionality
//									to  be  accurate.  This  value  depends  on  the  clock  of the
//									controllers  CPU core  (instruction  clock)  and  configuration
//									parameters. This  constant can also  be used in the application
//									code to derive hardware timer related values from.
//
//	- avix_TIMER_CLK_SECONDARY:		Constant  defining the source  for the hardware timer AVIX uses
//									for its internal timing. Allowed values are:
//									0: 	The  hardware timer is clocked from the controller internal
//										oscillator. When using sleep mode, the timer will stop when
//										the controller enters sleep mode.
//									1:	The hardware  timer is clocked from the controller external
//										oscillator. When the controller is in sleep mode, the hard-
//										ware timer will continue counting.
//
//	- avix_ROUND_ROBIN_CYCLEus:		Threads having the same priority are scheduled in a round robin
//									fashion. This figure defines the time in micro seconds a thread
//									is allowed  to run before  being preempted by a thread with the
//									same priority. Typically the value used for this parameter lies
//									somewhere between 1000 and 10000 micro seconds.
//
//	- avix_SYS_CLOCK_TICKus:		For  the  basic  timing  needs  of AVIX, use is made of a timer
//									having  a  period  specified  by  this  value. The basic timing
//									period typically  is in the  range 100-1000 micro seconds. With
//									this period, an interrupt is generated which  is used to update
//									both AVIX user level timers and the round robin timer.
//
//	- avix_MEM_POOL_COUNT:			Maximum number of memory pools the user can create
//
//	- avix_MSG_POOL_NR_MESSAGES:	Maximum number  of message  blocks present in the message pool.
//									The value for this constant can be 1 to 254.  When specifying a
//									value of zero(0)  no message pool is  allocated. This value can
//									be used to minimize RAM usage when the application does not use
//									messages.
//
//	- avix_MSG_BODY_NR_BYTES:		The message mechanism of AVIX is based on blocks of memory with
//									a fixed  size for  its data  section. This constant defines the
//									number of bytes that can be placed in a message.
//
//	- avix_SYSTEM_STACK_SIZE:		AVIX  implements a  system stack  used for  interrupts. When an
//									interrupt occurs, the stack is switched to this system stack so
//									not all interrupt stack  space is needed in  each thread stack.
//									This preserves precious RAM.  This constant defines the size in
//									bytes  used for the  system stack.  The size should be based on
//									the sum of all nested interrupt stack needs.
//
//	- avix_MAX_PRIORITY:			Maximum  priority that  can be assigned  to a  thread.  Ideally
//									every  thread runs  at its own unique priority. Minimizing this
//									figure saves memory.
//
//	- avix_TRACING:					Control Thread Activation Tracing. This  parameter may have one
//									of the following values:
//
//									0- Tracing disabled,  trace code  executed.  Using this  value,
//									AVIX will execute trace  code but instead  of asserting  a port
//									assigned to a  thread,  the code  will assert an internal dummy
//									location.
//
//									1- Tracing enabled, trace code executed. Using this value, AVIX
//									will execute  trace code where  for threads having a trace port
//									assigned, this port  will be asserted and for threads having no
//									port assigned a dummy location will be asserted.
//
//									2- Tracing disabled,  no trace code executed. Using this value,
//									AVIX  will  not executed  the  trace  code  leading  to optimal
//									performance.  Using  this  value  AVIX  executes  a   different
//									instruction sequence than with either value 0 or 1.
//
//									Values 0 and 1  exist to  allow having  a build with or without
//									tracing  having the  exact same  performance.  These values are
//									intended to be used  during development where switching between
//									these  values   enable/disable   tracing  without   influencing
//									performance.  This forms the basis  of the non-intrusive aspect
//									of tracing. Regardless  if value 0 or 1 is used, the exact same
//									instruction sequence will be executed.
// 									Regardless  the value  of this  configuration  parameter, trace
// 									ports   can   be   assigned   to   a   thread   using  function
// 									avixThread_SetTracePort.  The  value  of  this  parameter  only
// 									influences how these ports are used by AVIX.
//
//	- avix_EXTENDED_MEMORY:			Number  of  bytes  to  reserve in the controllers extended  RAM
//									section (EDS memory) for extended memory pools.
//
//	- avix_DSP_ENABLED:				Allow dsPIC30F, dsPIC33F and dsPIC33EP controllers  to use  DSP
//									functionality (1) or not use  DSP functionality (0).  Under all
//									circumstances,  DSP usage is allowed from a single thread only!
//									AVIX does not  save the DSP  registers as  part of  the  thread
//									context.  This  flag  takes  care  of  saving  the  controllers
//									register holding the DSP specific addressing modes.
//
//	- avix_MULTI_THREAD_PSV:		Needs to be set 1 under  the condition that  multiple PSV pages
//									are used AND PSV  pages are  used from  multiple  threads. When
//									only using a  single PSV  page OR all PSV pages are used from a
//									single thread only, this flag can be set 0. Setting this flag 1
//									implies the  PSVPAG register  is saved  as part  of the  thread
//									context.  Certain controllers do not have a PSVPAG register but
//									a DSRPAG and DSWPAG register instead. In this case setting this
//									flag 1 saves  DSRPAG and DSWPAG as  part of the thread context.
//
//	- avix_MULTI_THREAD_TBLPAG:		Needs  to be set 1  under the  condition that  direct access to
//									FLASH memory through the TBLPAG  register is done from multiple
//									threads.  When accessing FLASH through the TBLPAG register from
//									a single thread only, this parameter can be set 0.
//
//	- avix_SWI:						Define the name of the interrupt used by AVIX.
//	  avix_SWI_IRQ_REG:				- Define the related interrupt register.
//	  avix_SWI_IRQ_CTRREG:			- Define the related interrupt control register.
//	  avix_SWI_IRQ_LVLREG:			- Define the related interrupt priority register.
//
//	- avix_SYSTMR:					Define the hardware timer used by AVIX by its number.
//	  avix_SYSTMR_IRQ_REG:			- Define the related interrupt register.
//	  avix_SYSTMR_IRQ_CTRREG:		- Define the related interrupt control register.
//	  avix_SYSTMR_IRQ_LVLREG:		- Define the related interrupt priority register.
//
//=================================================================================================
// INCLUDE FILES
//=================================================================================================
#include "AVIXPortDef.h"

//-------------------------------------------------------------------------------------------------
// PLATFORM SPECIFIC HEADER
//-------------------------------------------------------------------------------------------------
//
#if defined __AVIX_COMP_MICROCHIP_C30__
#if defined __AVIX_PIC24F__
#include <p24Fxxxx.h>
#endif

#if defined __AVIX_PIC24H__
#include <p24Hxxxx.h>
#endif

#if defined __AVIX_PIC24E__
#include <p24Exxxx.h>
#endif

#if defined __AVIX_PIC30F__
#include <p30Fxxxx.h>
#endif

#if defined __AVIX_PIC33E__
#include <p33Exxxx.h>
#endif

#if defined __AVIX_PIC33F__
#include <p33Fxxxx.h>
#endif
#else
#include <xc.h>
#endif



//=================================================================================================
// AVIX GENERIC SETTINGS.			See port  guide in directory  {install}/_AVIX/Doc for  details.
//=================================================================================================
//
#define avix_DEVICE_CLOCKhz         16000000                 // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_TIMER_CLK_SECONDARY    0                        // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_ROUND_ROBIN_CYCLEus    10000                    // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_SYS_CLOCK_TICKus       100                      // DO NOT CHANGE FOR DEMO DISTRIBUTION

#define avix_MEM_POOL_COUNT         2                        // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_MSG_POOL_NR_MESSAGES   5                        // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_MSG_BODY_NR_BYTES      4                        // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_SYSTEM_STACK_SIZE      150                      // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_MAX_PRIORITY           5                        // DO NOT CHANGE FOR DEMO DISTRIBUTION

#define avix_TRACING                1                        // DO NOT CHANGE FOR DEMO DISTRIBUTION





//=================================================================================================
// AVIX PORT SPECIFIC SETTINGS.		See port  guide in directory  {install}/_AVIX/Doc for  details.
//=================================================================================================
//
//-------------------------------------------------------------------------------------------------
// Number of bytes for extended memory pools for PIC24-dsPIC controllers with EDS memory.
//-------------------------------------------------------------------------------------------------
//
#define avix_EXTENDED_MEMORY        60000                    // DO NOT CHANGE FOR DEMO DISTRIBUTION



//-------------------------------------------------------------------------------------------------
// DSP and FLASH Settings.			See port  guide in directory  {install}/_AVIX/Doc for  details.
//-------------------------------------------------------------------------------------------------
//
#define avix_DSP_ENABLED            0                        // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_MULTI_THREAD_PSV       0                        // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_MULTI_THREAD_TBLPAG    0                        // DO NOT CHANGE FOR DEMO DISTRIBUTION



//-------------------------------------------------------------------------------------------------
// Specify the AVIX interrupt.		See port  guide in directory  {install}/_AVIX/Doc for  details.
// - The interrupt register configuration below is for the PIC24FJ256GB210 controller.
// - When using a  different controller and/or a different interrupt,  make sure the three register
//   definitions comply with the selected controller/interrupt combination.
//-------------------------------------------------------------------------------------------------
//
#define avix_SWI                    INT4                     // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_SWI_IRQ_REG            IFS3                     // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_SWI_IRQ_CTRREG         IEC3                     // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_SWI_IRQ_LVLREG         IPC13                    // DO NOT CHANGE FOR DEMO DISTRIBUTION



//-------------------------------------------------------------------------------------------------
// Specify the AVIX hardware timer.	See port  guide in directory  {install}/_AVIX/Doc for  details.
// - The timer interrupt register configuration below is for the PIC24FJ256GB210 controller.
// - When  using a  different controller  and/or a  different timer,  make sure  the three register
//   definitions comply with the selected controller/timer combination.
//-------------------------------------------------------------------------------------------------
//
#define avix_SYSTMR                 5                        // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_SYSTMR_IRQ_REG         IFS1                     // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_SYSTMR_IRQ_CTRREG      IEC1                     // DO NOT CHANGE FOR DEMO DISTRIBUTION
#define avix_SYSTMR_IRQ_LVLREG      IPC7                     // DO NOT CHANGE FOR DEMO DISTRIBUTION



#ifdef __cplusplus
}
#endif

#endif	// __AVIXSystemSettings_h__
