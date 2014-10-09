
//	===============================================================================================
//	PRODUCT:			---------- AVIX - (ADVANCED VIRTUAL INTEGRATED EXECUTIVE) RTOS ------------
//	-----------------------------------------------------------------------------------------------
// 	PRODUCT VERSION: 	5.0
// 	COPYRIGHT:			AVIX-RT EMBEDDED SOLUTIONS
//	LICENSE AGREEMENT:	SEE BOTTOM OF THIS FILE
//	-----------------------------------------------------------------------------------------------
//	MODULE:				THIS FILE BELONGS  TO THE AVIX EXTENDED  TUTORIAL APPLICATION WHICH IS DIS-
//						TRIBUTED AS PART OF AVIX.  FOR A DESCRIPTION OF THIS TUTORIAL READ DOCUMENT
//						AVIX_GettingStarted.pdf  WHICH IS INSTALLED  IN THE AVIX DOCUMENT DIRECTORY
//	-----------------------------------------------------------------------------------------------
//	FILENAME:			compSwitchHandling.c
//	-----------------------------------------------------------------------------------------------
//	This file contains the development board switch handling.
//
//	important: 	This file is part of the AVIX extended demo application. It contains a separate 
//				thread for the purpose of explaining the different AVIX mechanisms. This thread
//				is responsible for translating a specific switch on the development board to a
//				write operation of an exchange object. This is a very basic operation and it is 
//				very well possible to integrate this functionality in the LCD component so it will
//				run on the same thread as the LCD control. This would save resources. Reason to 
//				model this as a separate thread is for the sake or clarity.
//	===============================================================================================
//	INCLUDES:
//	===============================================================================================
//
#include "AVIX.h"
#include "AVIXAtomicSFR.h"

#include "controlExchange.h"


//	===============================================================================================
//	EXTERNAL DECLARATIONS
//	===============================================================================================
//


//	===============================================================================================
//	TYPE DEFINITIONS
//	===============================================================================================
//


//	===============================================================================================
//	GLOBAL VARIABLES
//	===============================================================================================
//
static volatile struct
{
	volatile unsigned int*	tris;			// TRIS port for switch bit
	volatile unsigned int*	port;			// PORT for switch bit
	volatile unsigned int*	cnReg;			// Applicable CN register
	unsigned short			bit       : 5;	// Bitnumber in port switch is connected to
	unsigned short			cnBit     : 5;	// CN bitnumber
	unsigned short			prevState : 1;	// State for dynamic switch handling
	unsigned short			newState  : 1;	// State for dynamic switch handling
	
} keyMan[] =
{
#if defined(__32MX360F512L__)

	{.tris=&TRISD, .port=&PORTD, .bit=6,  .cnReg=&CNEN,  .cnBit=15		},	
	{.tris=&TRISD, .port=&PORTD, .bit=7,  .cnReg=&CNEN,  .cnBit=16		},
	{.tris=&TRISD, .port=&PORTD, .bit=13, .cnReg=&CNEN,  .cnBit=19		}

#elif defined(__dsPIC33EP512MU810__) || defined (__PIC24EP512GU810__)

	{.tris=&TRISD, .port=&PORTD, .bit=6,  .cnReg=&CNEND, .cnBit=6		},	
	{.tris=&TRISD, .port=&PORTD, .bit=7,  .cnReg=&CNEND, .cnBit=7		},	
	{.tris=&TRISD, .port=&PORTD, .bit=13, .cnReg=&CNEND, .cnBit=13		}

#else

	{.tris=&TRISD, .port=&PORTD, .bit=6,  .cnReg=&CNEN1, .cnBit=15		},	
	{.tris=&TRISD, .port=&PORTD, .bit=7,  .cnReg=&CNEN2, .cnBit=16-16	},	
	{.tris=&TRISD, .port=&PORTD, .bit=13, .cnReg=&CNEN2, .cnBit=19-16	}

#endif
};

static tavixThreadId switchThreadId;
static tavixExchId   myControlExchange;



//	===============================================================================================
// 	MACROS
//	===============================================================================================
//
#define NR_KEYS (sizeof(keyMan)/sizeof(keyMan[0]))


//	===============================================================================================
//	GLOBAL VARIABLES
//	===============================================================================================
//


//	===============================================================================================
//	FORWARD FUNCTION DECLARATIONS
//	===============================================================================================
//
static TAVIX_THREAD_REGULAR threadSwitch(void* p);



//	===============================================================================================
//	EXPORTED FUNCTIONS
//	===============================================================================================
//	***********************************************************************************************
//	===============================================================================================
//	FUNCTION:	compSwitchHandling_Init
//	===================================
//	Initialize the switch handling component. This function is intended to be called from the 
//	application initialization code at which time the scheduler is not yet active. Therefore there
//	is no risk of concurrent access of the different controller registers and thus the operations
//	on these registers need not to be thread safe.
//	===============================================================================================
//
tavixThreadId compSwitchHandling_Init(tavixExchId controlExchange)
{
	int	i;

	myControlExchange = controlExchange;

	//---------------------------------------------------------------------------------------------
	// Initialize the configured ports as input pins.
	//---------------------------------------------------------------------------------------------
	for(i = 0; i < NR_KEYS; i++)
	{
		*keyMan[i].tris |= (1 << keyMan[i].bit);
	}
	
		
	//---------------------------------------------------------------------------------------------
	// Activate the change notification module which is only required for the PIC32. For the 16 bit 
	// parts it is sufficient to set the individual CN bit.
	//---------------------------------------------------------------------------------------------
#if defined(__32MX360F512L__)
	CNCONbits.ON = 1;
#endif	


	//---------------------------------------------------------------------------------------------
	// For the PIC24FJ256GB210, PIC24EP512GU810 and dsPIC33EP512MU810 (parts with EDS memory), 
	// besides the TRIS register, for a number of pins the analog function needs to be switched 
	// off. This happens to be the case with RD6 and RD7 which are used for the switches on the 
	// Explorer16 board.
	//---------------------------------------------------------------------------------------------
#if defined (__PIC24FJ256GB210__)

	ANSDbits.ANSD6 = 0;
	ANSDbits.ANSD7 = 0;

#endif

#if defined (__PIC24EP512GU810__) || defined (__dsPIC33EP512MU810__)

	ANSELDbits.ANSD6 = 0;
	ANSELDbits.ANSD7 = 0;

#endif
	

	//---------------------------------------------------------------------------------------------
	// Enable the applicable change notifications and do an initial read of the port
	//---------------------------------------------------------------------------------------------
	for(i = 0; i < NR_KEYS; i++)
	{
		*keyMan[i].cnReg    |= (1 << keyMan[i].cnBit);
		keyMan[i].prevState  = (*keyMan[i].port & (1 << keyMan[i].bit)) ? 0 : 1;
	}


	//---------------------------------------------------------------------------------------------
	// Set change notification interrupt level etc.
	//---------------------------------------------------------------------------------------------
	IFS1bits.CNIF = 0;	/* Reset the interrupt flag	*/
	IEC1bits.CNIE = 1;	/* Enable cn interrupts		*/


	//---------------------------------------------------------------------------------------------
	// Set the interrupt priority
	//---------------------------------------------------------------------------------------------
#if defined(__32MX360F512L__)
	IPC6bits.CNIP = 1;	/* Interrupt priority 1		*/
#else
	IPC4bits.CNIP = 1;	/* Interrupt priority 1		*/
#endif

	//---------------------------------------------------------------------------------------------
	// Create the thread responsible for interpreting the switch and translating this to an 
	// exchange related action.
	//---------------------------------------------------------------------------------------------
	switchThreadId = avixThread_Create(NULL, threadSwitch, (void*)0, 1, 500, AVIX_THREAD_READY);
	
	return switchThreadId;
}





//	===============================================================================================
//	FUNCTION:	threadSwitch
//	========================
//	Thread belonging to the switch component. Switch handling is based on change notification
//	interrupts. When a change notification interrupt occurs, the interrupt handler sets an event
//	flag waking up this thread to take care of debouncing the switch and translating the switch
//	being pressed to the applicable action on an exchange object other components are 'listening'
//	===============================================================================================
//
static TAVIX_THREAD_REGULAR threadSwitch(void* p)
{
	int i;
			
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Wait until a change notification interrupt occurs which sets an event flag waking me up.
		//-----------------------------------------------------------------------------------------
		avixEventGroup_Wait
				(	avixThread_GetIdCurrent().asEventId,
					AVIX_EF(0), 
					AVIX_EVENT_GROUP_ANY, 
					AVIX_EF_NONE, 
					AVIX_EF(0)	);


		//-----------------------------------------------------------------------------------------
		// Wait 2 ms for debouncing
		//-----------------------------------------------------------------------------------------
		avixThread_Sleep(AVIX_DELAY_MS(2));
		
		
		//-----------------------------------------------------------------------------------------
		// Now check which key has changed and enable cn notification again.
		//-----------------------------------------------------------------------------------------
		for(i = 0; i < NR_KEYS; i++)
		{
			//-------------------------------------------------------------------------------------
			// A pressed switch is identified by a state != 0 (1). This is the case when the port
			// reads a value of zero. Pressing a switch pulls the port pin low!
			//-------------------------------------------------------------------------------------
			keyMan[i].newState  = (*keyMan[i].port  & (0x0001 << keyMan[i].bit)) ? 0 : 1;

			if (keyMan[i].newState != keyMan[i].prevState)
			{
				keyMan[i].prevState = keyMan[i].newState;
				
				if ((i == 0) && (keyMan[0].newState))
				{
					controlExchUpdateSamplePeriod(myControlExchange, 1);
				}
				if ((i == 1) && (keyMan[1].newState))
				{
					controlExchUpdateSamplePeriod(myControlExchange, 0);
				}
				if ((i == 2) && (keyMan[2].newState))
				{
					controlExchUpdateChannels(myControlExchange);
				}
			}
		}
	}
}	






//	===============================================================================================
//	FUNCTION:	Change notification interrupt handler
//	=================================================
//	Change notification interrupt handler. Note the interrupt handler is defined with an AVIX
//	provided macro leading to the ISR making use of the configured system stack and thus not 
//	putting any load on the stack of the individual threads.
//	===============================================================================================
//
#if defined(__32MX360F512L__)
avixDeclareISR(_CHANGE_NOTICE_VECTOR)
#else
avixDeclareISR(_CNInterrupt, no_auto_psv)
#endif
{
	int i;
	
	//---------------------------------------------------------------------------------------------
	// Read the different ports to reset the change notification
	//---------------------------------------------------------------------------------------------
	for(i = 0; i < NR_KEYS; i++)
	{
		keyMan[i].newState  = (*keyMan[i].port  & (0x0001 << keyMan[i].bit)) ? 0 : 1;
	}
	
	//---------------------------------------------------------------------------------------------
	// Reset the interrupt in an atomic way
	//---------------------------------------------------------------------------------------------
	avixSFR(IFS1, CNIF, WRITE_BF, 0);
	

	//---------------------------------------------------------------------------------------------
	// Set the event flag the thread is waiting for.
	//---------------------------------------------------------------------------------------------
	avixEventGroup_ChangeFromISR(switchThreadId.asEventId, AVIX_EVENT_GROUP_SET, AVIX_EF(0));
}




//	===============================================================================================
//	***********************************************************************************************
//	===============================================================================================
//	SOFTWARE LICENSE AGREEMENT
//	--------------------------
//
//	THE  SOFTWARE  SUPPLIED  HEREWITH  AS  THE  CONTENT  OF  THIS FILE IS OWNED BY AVIX-RT EMBEDDED
//	SOLUTIONS  (THE "COMPANY"), AND IS PROTECTED  UNDER APPLICABLE  COPYRIGHT LAWS.  ALL RIGHTS ARE
//	RESERVED.  THE SOFTWARE IS SUPPLIED TO YOU (THE "CUSTOMER")  FOR USE  SOLELY AND EXCLUSIVELY AS
//	PART OF AND TOGETHER WITH PRODUCTS MANUFACTURED BY "COMPANY" AND LICENSED TO "CUSTOMER".
//
//	THE SOFTWARE IS PROVIDED ON AN AS-IS BASIS WITHOUT  CHARGE AND IS SUBJECT TO ALTERATIONS. IT IS 
//	THE "CUSTOMERS" OBLIGATION TO FULLY TEST THE SOFTWARE IN ITS ENVIRONMENT AND TO  ENSURE  PROPER 
//	FUNCTIONALITY, QUALIFICATION AND COMPLIANCE WITH COMPONENT SPECIFICATIONS.
//
//	IN  THE  EVENT  THE  SOFTWARE  DELIVERABLE  INCLUDES THE  USE OF  OPEN SOURCE  COMPONENTS,  THE 
//	PROVISIONS OF  THE GOVERNING  OPEN SOURCE  LICENSE AGREEMENT  SHALL APPLY  WITH RESPECT TO SUCH 
//	SOFTWARE DELIVERABLE. THE "COMPANY" DOES NOT WARRANT  THAT THE DELIVERABLES DO NOT INFRINGE ANY 
//	THIRD PARTY INTELLECTUAL  PROPERTY RIGHT (IPR).  IN THE EVENT THAT THE  DELIVERABLES INFRINGE A 
//	THIRD PARTY IPR IT IS THE SOLE RESPONSIBILITY OF THE "CUSTOMER" TO OBTAIN NECESSARY LICENSES TO 
//	CONTINUE THE  USAGE OF THE DELIVERABLE.
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
