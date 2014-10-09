
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
//	FILENAME:			compAdcSampling.c
//	-----------------------------------------------------------------------------------------------
//	This file contains ADC channel sampling code.
//	===============================================================================================
//	INCLUDES:
//	===============================================================================================
//
#include "AVIX.h"
#include "AVIXAtomicSFR.h"

#include "ADC.h"

#include "adcExchange.h"
#include "controlExchange.h"


//	===============================================================================================
//	EXTERNAL DECLARATIONS
//	===============================================================================================
//


//	===============================================================================================
//	TYPE DEFINITIONS
//	===============================================================================================
//
typedef struct
{
	unsigned short channel;
	unsigned short value;
} tADCValue;


//	===============================================================================================
//	GLOBAL VARIABLES
//	===============================================================================================
//
static tavixExchId	myPublishExchange;
static tavixExchId	myPeriodExchange;
static tavixPipeId	myPipe;



//	===============================================================================================
// 	MACROS
//	===============================================================================================
//
#define FLAG_MAIN_TIMER						0
#define FLAG_CONTROL_EXCHANGE_NEW_DATA		1


//	===============================================================================================
//	GLOBAL VARIABLES
//	===============================================================================================
//


//	===============================================================================================
//	FORWARD FUNCTION DECLARATIONS
//	===============================================================================================
//
static TAVIX_THREAD_REGULAR adcThread(void* param);
static void 				adcPipeCallback(tavixPipeEvent pipeEvent, int nrBytes, void* pUserData);
static void 				initAdcDevice(void);



//	===============================================================================================
//	EXPORTED FUNCTIONS
//	===============================================================================================
//	***********************************************************************************************
//	===============================================================================================
//	FUNCTION:	compAdcSampling_Init
//	================================
//	Initialize the ADC sampling component
//	===============================================================================================
//
tavixThreadId compAdcSampling_Init(tavixExchId publishExchange, tavixExchId periodExchange)
{
	tavixThreadId 	threadADC;

	
	//---------------------------------------------------------------------------------------------
	// Remember the two exchange object id's. myPublishExchange is required to write out the
	// scanned ADC samples, myPeriodExchange is an input exchange containing the sample period
	// which can be changed by someone writing to this exchange.
	//---------------------------------------------------------------------------------------------
	myPublishExchange = publishExchange;
	myPeriodExchange  = periodExchange;


	//---------------------------------------------------------------------------------------------
	// Create the main ADC conversion thread.
	//---------------------------------------------------------------------------------------------
	threadADC = avixThread_Create
					(	NULL,					// Human readable name is not required
						adcThread,				// Function running as thread
						(void*)0,				// Thread function parameter
						3,						// Thread priority
						400,					// Size of thread stack in bytes
						AVIX_THREAD_READY);		// Initial thread status	
						
						
	//---------------------------------------------------------------------------------------------
	// Create a pipe used between the ADC interrupt handler and the ADC thread. The pipe receives
	// a pointer to a device callback function so when the ADC thread reads from the pipe, the
	// callback can activate the actual ADC conversion.
	//---------------------------------------------------------------------------------------------
	myPipe = avixPipe_Create(NULL, 3, sizeof(tADCValue), adcPipeCallback, NULL);
	
	
	//---------------------------------------------------------------------------------------------
	// Connect to the period exchange so a thread event flag is set when the value of this exchange
	// changes. The connection id does not need to be saved since when the thread event flag is set
	// the new value is read from the exchange.
	//---------------------------------------------------------------------------------------------
	avixExch_ConnectEventGroup(periodExchange, threadADC.asEventId, AVIX_EF(FLAG_CONTROL_EXCHANGE_NEW_DATA));
		
	
	return threadADC;
}




//	===============================================================================================
//	FUNCTION:	threadLCD
//	=====================
//	Function that will run as an autonomous thread controlling the sampling of the ADC channels.
//	===============================================================================================
//
static TAVIX_THREAD_REGULAR adcThread(void* param)
{
	tavixTimerId	myTimer;
	unsigned short	currentSamplePeriod;
	tADCValue 		val[2];
	tavixEventFlags	eventFlags;
	tAdcSamples		outputData;
	tAppControl	 	control;

	//---------------------------------------------------------------------------------------------
	// The ADC thread will wake periodically to scan the channels. For this purpose a timer is
	// created. To this timer another event flag is connected that will be set when the timer 
	// expires. Doing so, the thread can wait for the timer event flag and when set, the flags 
	// returned by the wait will also contain the flags set by the Exchange connection made above.
	//
	// For the initial timer period, the control exchange is read first. Note that the control
	// exchange contains the enable/disable for the two channels and the timer period. Only the
	// timer period is needed so to check whether this has changed, a local copy is maintained.
	//---------------------------------------------------------------------------------------------
	avixExch_Read(myPeriodExchange, &control, NULL);
	currentSamplePeriod = control.samplePeriod;

	myTimer = avixTimer_Create(NULL);

	avixTimer_ConnectEventGroup(myTimer, avixThread_GetIdCurrent().asEventId, AVIX_EVENT_GROUP_SET, AVIX_EF(FLAG_MAIN_TIMER));
	avixTimer_Set(myTimer, AVIX_DELAY_MS(control.samplePeriod), AVIX_TIMER_CYCLIC);
	avixTimer_Start(myTimer);

	
	//---------------------------------------------------------------------------------------------
	// ADC Thread main loop
	//---------------------------------------------------------------------------------------------
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Wait for one or both of the event flags that are relevant for this thread. After one is 
		// set read the flags in a local variable and clear the flags.
		//-----------------------------------------------------------------------------------------
		eventFlags = avixEventGroup_Wait
						(	avixThread_GetIdCurrent().asEventId,
							AVIX_EF(FLAG_MAIN_TIMER) | AVIX_EF(FLAG_CONTROL_EXCHANGE_NEW_DATA),
							AVIX_EVENT_GROUP_ANY,
							AVIX_EF_NONE,
							AVIX_EF(FLAG_MAIN_TIMER) | AVIX_EF(FLAG_CONTROL_EXCHANGE_NEW_DATA)	);
				
				

		//-----------------------------------------------------------------------------------------
		// When my main timer expires read ADC data and write data to the exchange.
		//-----------------------------------------------------------------------------------------
		if (AVIX_EF_IN(AVIX_EF(FLAG_MAIN_TIMER), eventFlags))
		{
			avixPipe_Read(myPipe, (unsigned char*)val, sizeof(val)/sizeof(val[0]));

			outputData.channel1 = val[0].value;
			outputData.channel2 = val[1].value;

			avixExch_Write(myPublishExchange, &outputData);
		}
		

		//-------------------------------------------------------------------------------------
		// When the sample period changes, reconfigure the timer. The control exchange contains
		// the sample period and the enable/disable of the two ADC channels. The latter value
		// is not used by this component. The ADC component always samples two channels.
		// so to learn if the period has changed, the current value is compared to the new
		// value and the timer is only reinitialized if there is a difference.
		//-------------------------------------------------------------------------------------
		if (AVIX_EF_IN(AVIX_EF(FLAG_CONTROL_EXCHANGE_NEW_DATA), eventFlags))
		{
			avixExch_Read(myPeriodExchange, &control, NULL);
			
			if (control.samplePeriod != currentSamplePeriod)
			{
				currentSamplePeriod = control.samplePeriod;
				
				avixTimer_SetPeriod(myTimer, AVIX_DELAY_MS(currentSamplePeriod));
			}
		}
	}
}





//	===============================================================================================
//	FUNCTION:	Interrupt handler for ADC1
//	======================================
//	ADC Interrupt handler. The ADC sampling is set one input at a time so no use of DMA is required
//	Since two inputs are used (input 4, the temperature sensor and input 5, the potmeter), the
//	interrupt handler contains a counter which after two conversions passes the input data to the
//	pipe so it can be handled further by the thread reading this pipe.
//	===============================================================================================
//
avixDeclareISR(_ADC1Interrupt, no_auto_psv)
{
	tADCValue adcVal[2];
	
	//---------------------------------------------------------------------------------------------
	// Atomic clear the interrupt flag using an AVIX utility macro.
	//---------------------------------------------------------------------------------------------
	avixSFR(IFS0, AD1IF, WRITE_BF, 0);
	
	
	//---------------------------------------------------------------------------------------------
	// Store the input data in the right array element.
	//---------------------------------------------------------------------------------------------
	adcVal[0].channel = 0;
	adcVal[0].value   = ADC1BUF0;

	adcVal[1].channel = 1;
	adcVal[1].value   = ADC1BUF1;

	//-----------------------------------------------------------------------------------------
	// Stop the ADC device and the timer used for conversion.
	//-----------------------------------------------------------------------------------------
	AD1CON1bits.ADON = 0;
	T3CONbits.TON    = 0;
	
	//-----------------------------------------------------------------------------------------
	// Write the input data to the pipe for further handling by thread reading the pipe.
	//-----------------------------------------------------------------------------------------
	avixPipe_WriteFromISR(myPipe, &adcVal[0], sizeof(adcVal)/sizeof(adcVal[0]));
}




//	===============================================================================================
//	FUNCTION:	adcPipeCallback
//	===========================
//	ADC pipe callback called when pipe is read by ADC thread. When pipe is empty, the conversion
//	is started. After conversion of two inputs is done, the ISR will disable the ADC1 and timer3
//	Conversion is started again when thread reads from empty pipe. So thread is responsible for
//	main timing of conversion.
//	===============================================================================================
//
static void adcPipeCallback(tavixPipeEvent pipeEvent, int nrBytes, void* pUserData)
{
	switch(pipeEvent)
	{
		case PIPEINFO_READ_FROM_EMPTY_PIPE:
			initAdcDevice();
			break;
		
		default:
			break;
	}
}




//	===============================================================================================
//	FUNCTION:	initAdcDevice
//	=========================
//	Start the ADC device, using timer 3 to start the actual conversion.
//	===============================================================================================
//
static void initAdcDevice(void)
{
	AD1CON1bits.FORM  = 0;		// Data Output Format: Regular integer
	AD1CON1bits.SSRC  = 2;		// Sample Clock Source: GP Timer starts conversion
	AD1CON1bits.ASAM  = 1;		// ADC Sample Control: Sampling begins immediately after conversion

	AD1CON2bits.SMPI  = 1;		// 2 ADC Channels are scanned
	AD1CON2bits.BUFM  = 0;		// Buffer configured as one 16-word buffers
	AD1CON2bits.CSCNA = 1;		// Scan inputs (two inputs are used).

	AD1CON3bits.ADRC  = 0;		// ADC Clock is derived from Systems Clock
	AD1CON3bits.ADCS  = 31;		// ADC Conversion Clock Tad=Tcy*(ADCS+1)=(1/8M)*2*32 = 8us (125Khz)
								// ADC Conversion Time for 10-bit Tc=12*Tab = 96us

	AD1CSSL 		  = 0x0000;	// Disable scanning for all inputs
	AD1CSSLbits.CSSL4 = 1;		// Add input 4 to scan list
	AD1CSSLbits.CSSL5 = 1;		// Add input 5 to scan list.

	
        
	IFS0bits.AD1IF   = 0;		// Clear the A/D interrupt flag bit
	IEC0bits.AD1IE   = 1;		// Enable A/D interrupt 
	IPC3bits.AD1IP   = 5;		// Set interrupt priority 5
	
	AD1CON1bits.ADON = 1;		// Turn on the A/D converter


	//---------------------------------------------------------------------------------------------
	// Initialize the timer for starting the actual conversion. Timer period is 125us.
	//---------------------------------------------------------------------------------------------
	TMR3          = 0x0000;
	PR3           = (50 * (avix_DEVICE_CLOCKhz / 1000000)) - 1;
	IFS0bits.T3IF = 0;
	IEC0bits.T3IE = 0;
	T3CONbits.TON = 1;
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
