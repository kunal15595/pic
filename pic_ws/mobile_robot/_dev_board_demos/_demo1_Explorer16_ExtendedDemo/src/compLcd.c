
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
//	FILENAME:			compLcd.c
//	-----------------------------------------------------------------------------------------------
//	This file contains the functions of the LCD component.
//	===============================================================================================
//	INCLUDES:
//	===============================================================================================
//
#include <stdio.h>
#include "AVIX.h"
#include "AVIXAtomicSFR.h"

#include "support.h"

#include "controlExchange.h"
#include "adcExchange.h"
#include "compLcd.h"


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


//	===============================================================================================
// 	MACROS
//	===============================================================================================
//	Port definitions for the LCD display. For these definitions, use is made of the atomic port 
//	manipulation macros from AVIXAtomicSFR.h described in AvixAtomicSFRManipulation.pdf installed 
//	in the AVIX Doc directory. By using these macros, when from a certain SFR other  bitfields are 
//	manipulated from other threads or ISR's, these concurrent manipulations do not conflict.
//	-----------------------------------------------------------------------------------------------
//	RS port is port B bit 15. For a number of controllers it is required to set an ADC 
//	configuration bit in order for this pin to be used as GPIO. In the section below a conditional
//	macro is defined to set the applicable ADC configuration bit when required. For controllers not
//	requiring this ADC bit to be set the applicable macro is defined empty.
//	-----------------------------------------------------------------------------------------------
#if defined(__PIC24FJ256GB210__) || defined(__PIC24EP512GU810__) || defined(__dsPIC33EP512MU810__)

	#define	PREPARE_PIN_RS_AS_DIGITAL()

#elif defined(__PIC24FJ128GA010__)

	#define	PREPARE_PIN_RS_AS_DIGITAL()	avixSFR(AD1PCFG, PCFG15,  WRITE_BF, 1)

#elif defined(__PIC24HJ256GP610__) || defined(__PIC24HJ256GP610A__)

	#define	PREPARE_PIN_RS_AS_DIGITAL()	avixSFR(AD1PCFGL, PCFG15,  WRITE_BF, 1)

#elif defined(__dsPIC33FJ256GP710__) || defined(__dsPIC33FJ256GP710A__)

	#define	PREPARE_PIN_RS_AS_DIGITAL()	avixSFR(AD1PCFGL, PCFG15,  WRITE_BF, 1)
	
#elif defined(__32MX360F512L__)

	#define	PREPARE_PIN_RS_AS_DIGITAL()	avixSFR(AD1PCFG, PCFG15,  WRITE_BF, 1)

#else
	#error current type of controller not supported by demo software
#endif

//	-----------------------------------------------------------------------------------------------
//	Definitions to set the GPIO pins required by the LCD as output pins.
//	-----------------------------------------------------------------------------------------------
#define SET_PIN_RS_OUTPUT()	{	PREPARE_PIN_RS_AS_DIGITAL();						\
								avixSFR		 (TRISB, 	   TRISB15, WRITE_BF, 0);	}
#define SET_PIN_RW_OUTPUT()		avixSFR		 (TRISD, 	   TRISD5,  WRITE_BF, 0)
#define SET_PIN_E_OUTPUT()		avixSFR		 (TRISD, 	   TRISD4,  WRITE_BF, 0)
#define SET_DATA_PORT_OUTPUT()	avixSFR_Range(TRISE,	   0, 7, 	WRITE_BF, 0)


//	-----------------------------------------------------------------------------------------------
//	Definitions to write values to the LCD output pins
//	-----------------------------------------------------------------------------------------------
#define SET_PIN_RS(v)			avixSFR		 (LATB,		   LATB15,	WRITE_BF, (v))
#define SET_PIN_RW(v)			avixSFR		 (LATD,  	   LATD5,	WRITE_BF, (v))
#define SET_PIN_E(v)			avixSFR		 (LATD,  	   LATD4,	WRITE_BF, (v))
#define SET_DATA_PORT_DATA(v)	avixSFR_Range(LATE,  	   0, 7,	WRITE_BF, (v))


//	-----------------------------------------------------------------------------------------------
//	LCD Various definitions
//	-----------------------------------------------------------------------------------------------
#define NR_ROWS								2
#define	NR_COLUMNS							16

#define LCD_REFRESH_MS						50

#define FLAG_MAIN_TIMER						0
#define FLAG_CONTROL_EXCHANGE_NEW_DATA		1
#define FLAG_ADC_EXCHANGE_NEW_DATA			2



//	===============================================================================================
//	GLOBAL VARIABLES
//	===============================================================================================
//	Management struct used for containing display data. Each character is stored together with a
//	changed flag. When a character is written by a client, the changed flag is set. This flag is 
//	used when the LCD thread updates the LCD. It scans all changed flags and if the flag is set, 
//	the character is writtten to the LCD
//	-----------------------------------------------------------------------------------------------
static struct sDispData
{
	char 			character : 8;
	unsigned char	changed   : 1;
} lcdData[NR_ROWS * NR_COLUMNS];


//	-----------------------------------------------------------------------------------------------
//	The LCD module connects to the two Exchange objects it requires. A connection to an Exchange is
//	identified by a connection id. The connection id's are maintained to access the Exchanges.
//	-----------------------------------------------------------------------------------------------
static AVIX_OBJECT_ID_DEFINE(tavixExchConnId, adcConnection		);
static AVIX_OBJECT_ID_DEFINE(tavixExchConnId, controlConnection	);



//	===============================================================================================
//	FORWARD FUNCTION DECLARATIONS
//	===============================================================================================
//
static TAVIX_THREAD_REGULAR 			threadLCD(void* p);
static void 							compLCD_WriteCharacters(char* pText, int row, int column);
static __attribute__((noinline)) void	LCDOut (unsigned char addr, unsigned char data);




//	===============================================================================================
//	EXPORTED FUNCTIONS
//	===============================================================================================
//	***********************************************************************************************
//	===============================================================================================
//	FUNCTION:	compLcd_Init
//	========================
//	Initialize the LCD component
//	===============================================================================================
//
tavixThreadId compLcd_Init(tavixExchId adcExch, tavixExchId controlExch)
{
	struct sDispData*	pDispData;
	AVIX_OBJECT_ID_DEFINE(tavixThreadId, lcdThreadId);
	AVIX_OBJECT_ID_DEFINE(tavixTimerId,  timerId	);

	//---------------------------------------------------------------------------------------------
	// Initially the LCD data structure is filled with blanks and all changed flags are set. This
	// will automatically lead to an initialized LCD.
	//---------------------------------------------------------------------------------------------
	pDispData = &lcdData[0];
	do
	{
		pDispData->character = ' ';
		pDispData->changed   = 1;
		pDispData++;
	} while (pDispData != &lcdData[sizeof(lcdData)/sizeof(lcdData[0])]);


	//---------------------------------------------------------------------------------------------
	// Create the LCD main controlling thread
	//---------------------------------------------------------------------------------------------
	lcdThreadId = avixThread_Create(NULL, threadLCD, NULL, 1, 360, AVIX_THREAD_READY);


	//---------------------------------------------------------------------------------------------
	// The LCD thread 'observes' two Exchange objects, one containing the ADC data and one with the
	// controlling data. Both connections are 'Pull' type, when the content of the Exchange is
	// modified, an event flag in the thread event group is set to identify the content has changed
	//---------------------------------------------------------------------------------------------
	controlConnection = avixExch_ConnectEventGroup
							(controlExch, lcdThreadId.asEventId, AVIX_EF(FLAG_CONTROL_EXCHANGE_NEW_DATA));
	adcConnection 	  = avixExch_ConnectEventGroup
							(adcExch, lcdThreadId.asEventId, AVIX_EF(FLAG_ADC_EXCHANGE_NEW_DATA));


	//---------------------------------------------------------------------------------------------
	// The LCD thread will wake periodically to check whether new data is available in the exchange
	// objects that has to be shown (ADC) or controls how the data is to be shown (control).
	// For this purpose a timer is created. To this timer another event flag is connected that will
	// be set when the timer expires. Doing so, the thread can wait for the timer event flag and
	// when set, the flags returned by the wait will also contain the flags set by the Exchanges.
	//---------------------------------------------------------------------------------------------
	timerId = avixTimer_Create(NULL);

	avixTimer_ConnectEventGroup(timerId, lcdThreadId.asEventId, AVIX_EVENT_GROUP_SET, AVIX_EF(FLAG_MAIN_TIMER));
	avixTimer_Set(timerId, AVIX_DELAY_MS(LCD_REFRESH_MS), AVIX_TIMER_CYCLIC);
	avixTimer_Start(timerId);
	
	return lcdThreadId;
}




//	===============================================================================================
//	FUNCTION:	threadLCD
//	=====================
//	Function that will run as an autonomous thread controlling the content of the LCD.
//	===============================================================================================
//
static TAVIX_THREAD_REGULAR threadLCD(void* p)
{
	tavixEventFlags		flags;
	tAdcSamples			adcValues;
	tAppControl			control;
	struct sDispData*	pDispData;
	char				buffer[8];
	int					i;

	//---------------------------------------------------------------------------------------------
	// Initialize the HD44780 controller, taking into account the specified wait times (minimum)
	//---------------------------------------------------------------------------------------------
	SET_PIN_E(0);	
	SET_PIN_RS_OUTPUT();	
	SET_PIN_E_OUTPUT();
	SET_PIN_RW_OUTPUT();
   	SET_DATA_PORT_OUTPUT();

	avixThread_Sleep(AVIX_DELAY_MS(40));	// Initial power up delay is 40 ms

	LCDOut(0, 0x30);						// The next part is the defined initialization 
	avixThread_Sleep(AVIX_DELAY_MS(5));		// sequence with HD44780 specified delays
											//
	LCDOut(0, 0x30);						//
	avixThread_Sleep(AVIX_DELAY_US(100));	//
											//
   	LCDOut(0, 0x30);						//
	avixThread_Sleep(AVIX_DELAY_US(50));	//
  
	//---------------------------------------------------------------------------------------------
  	// From now on between every command a minimim of 37us must be waited according the HD44780 
  	// command specification, except the clear which requires a minimum of 1.37ms
	//---------------------------------------------------------------------------------------------
	LCDOut(0, 0x38);						// Function set, 8 bit interface,
	avixThread_Sleep(AVIX_DELAY_US(50));	// two display lines and font

	LCDOut(0, 0x08);						// Display off, cursor off, no blink
	avixThread_Sleep(AVIX_DELAY_US(50));	//

	LCDOut(0, 0x01);						// Clear entire display
	avixThread_Sleep(AVIX_DELAY_MS(2));		//

	LCDOut(0, 0x0c);						// Display on, cursor off
	avixThread_Sleep(AVIX_DELAY_US(50));	//

	LCDOut(0, 0x06);						// No shifting
	avixThread_Sleep(AVIX_DELAY_US(50));	//


	//---------------------------------------------------------------------------------------------
	// The LCD component creates a thread event group connection to the control exchange so event
	// flag FLAG_CONTROL_EXCHANGE_NEW_DATA (#defined) is set when the exchange is written. When
	// this flag is set, the LCD thread reads the control. Initially the LCD thread needs the value
	// of this exchange also. By explicitly setting the event flag here, in the main loop the
	// initial read of the control exchange is forced.
	//---------------------------------------------------------------------------------------------
	avixEventGroup_Change
		(	avixThread_GetIdCurrent().asEventId, 
			AVIX_EVENT_GROUP_SET, 
			AVIX_EF(FLAG_CONTROL_EXCHANGE_NEW_DATA));

	
	//---------------------------------------------------------------------------------------------
	// The content of the display is:
	//  ----------------
	// |ch.1 ch.2 period|
	// |xxxx yyyy   zms |
	//  ----------------
	// xxxx is the numeric value of adc channel1, yyyy is the numeric value of adc channel2 and z
	// is the sample period in milliseconds. When a channel is disabled, xxxx and/or yyyy are ----
	// The upper line is constant, this is written next and the ms text.
	//---------------------------------------------------------------------------------------------
	compLCD_WriteCharacters("ch.1 ch.2 period", 0, 0);
	compLCD_WriteCharacters("ms", 1, 13);
	

	//---------------------------------------------------------------------------------------------
	// LCD Thread main loop
	//---------------------------------------------------------------------------------------------
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Wait for the main cycle timer (event flag FLAG_MAIN_TIMER). When this flag is set 
		// because the timer expires, the flags returned from the wait function also contain other
		// flags that are set during the expired period. These are the flags of the two exchange
		// objects with the data to display and with the control information.
		//-----------------------------------------------------------------------------------------
		flags = avixEventGroup_Wait
					(	avixThread_GetIdCurrent().asEventId,
						AVIX_EF(FLAG_MAIN_TIMER),
						AVIX_EVENT_GROUP_ANY,
						AVIX_EF_NONE,
						AVIX_EF(FLAG_MAIN_TIMER) 					|
							AVIX_EF(FLAG_CONTROL_EXCHANGE_NEW_DATA) |
							AVIX_EF(FLAG_ADC_EXCHANGE_NEW_DATA) 		);



		//-----------------------------------------------------------------------------------------
		// Test if the control exchange has been written and if so, read the value. The control
		// exchange contains the ADC sample period and the enable flags of the two ADC channels.
		//-----------------------------------------------------------------------------------------
		if (AVIX_EF_IN(AVIX_EF(FLAG_CONTROL_EXCHANGE_NEW_DATA), flags))
		{
			avixExch_Read(avixExch_GetConnectionExch(controlConnection), &control, NULL);
			
			//-------------------------------------------------------------------------------------
			// Read the sample period and write to its location on the LCD. For the sample period
			// the leading zeros are replaced by blanks which is taken care of by the third param
			// to function convertIntToString.
			//-------------------------------------------------------------------------------------
			i = convertIntToString(control.samplePeriod, buffer, 1);
			compLCD_WriteCharacters(&buffer[i-2], 1, 11);
		}
						
						
		//-----------------------------------------------------------------------------------------
		// Test if the ADC values have been written so there is new LCD data to display. The ADC
		// channels are written with a much higher frequency than they are read here. Intermediate
		// values are not seen by the LCD thread but this is no problem with UI functionality.
		//-----------------------------------------------------------------------------------------
		if (AVIX_EF_IN(AVIX_EF(FLAG_ADC_EXCHANGE_NEW_DATA), flags))
		{
			avixExch_Read(avixExch_GetConnectionExch(adcConnection), &adcValues, NULL);
			
			if (control.input1Active)	// If input1 is active (must be displayed), make it so
			{
				(void)convertIntToString(adcValues.channel1, buffer, 0);
				compLCD_WriteCharacters(buffer, 1, 0);
			}
			else						// Else show a value indicating the input is inactive
			{
				compLCD_WriteCharacters("----", 1, 0);
			}

			if (control.input2Active)	// If input2 is active (must be displayed), make it so
			{
				(void)convertIntToString(adcValues.channel2, buffer, 0);
				compLCD_WriteCharacters(buffer, 1, 5);
			}
			else						// Else show a value indicating the input is inactive
			{
				compLCD_WriteCharacters("----", 1, 5);
			}
		}		


		//-----------------------------------------------------------------------------------------
		// Scan the local data structure for changed characters and if so, send to the LCD. The 
		// local data structure is written by the compLCD_WriteCharacters function.
		//-----------------------------------------------------------------------------------------
		pDispData = &lcdData[0];
		for (i = 0; i < NR_ROWS*NR_COLUMNS; i++)
		{
			if (pDispData->changed)
			{
				pDispData->changed = 0;

				//---------------------------------------------------------------------------------
				// Send address to LCD followed by data
				//---------------------------------------------------------------------------------
				LCDOut(0, 0x80 | (i / NR_COLUMNS ? 0x40 : 0x00) | i % NR_COLUMNS);
				avixThread_Sleep(AVIX_DELAY_US(50));

				LCDOut(1, pDispData->character);
				avixThread_Sleep(AVIX_DELAY_US(50));
			}
			pDispData++;
		}
	}
}





//	===============================================================================================
//	FUNCTION:	compLCD_WriteCharacters
//	===================================
//	Write a character string to the LCD data buffer. By writing the LCD content to a RAM buffer the
//	write can be very fast. When the LCD is periodically updated, the content of this buffer is
//	read to write to the LCD which is a slow process because of all the waits that have to be
//	inserted in between the individual characters.
//	===============================================================================================
//
static void compLCD_WriteCharacters(char* pText, int row, int column)
{
	struct sDispData*	pDispData;
	
	//---------------------------------------------------------------------------------------------
	// Guard the function against writing outside the buffer
	//---------------------------------------------------------------------------------------------
	if ((row >= 0) && (row < NR_ROWS) && (column >= 0) && (column < NR_COLUMNS))
	{
		//-----------------------------------------------------------------------------------------
		// Set the pointer to the row/column determined location in the buffer and copy the new
		// characters as long as there are characters available (up to trailing zero) and the end
		// of the data buffer is not reached.
		//-----------------------------------------------------------------------------------------
		pDispData = &lcdData[(row * NR_COLUMNS) + column];
		
		while(*pText && (pDispData < &lcdData[NR_ROWS * NR_COLUMNS]))
		{
			//-------------------------------------------------------------------------------------
			// If the character for the current position differs from the current value, set
			//-------------------------------------------------------------------------------------
			if (pDispData->character != *pText)
			{
				pDispData->character = *pText;
				pDispData->changed	 = 1;
			}	
			pText++;
			pDispData++;
		}
	}
}





//	===============================================================================================
//	FUNCTION:	LCDOut
//	==================
//	Write a single byte to an LDC device address
//	===============================================================================================
//
static __attribute__((noinline)) void LCDOut (unsigned char addr, unsigned char data)
{
	SET_PIN_RW(0);				// Set direction for writing to LCD controller
	SET_PIN_RS(addr);			// Command data mode based on argument
	SET_DATA_PORT_DATA(data);	// Set the actual data bits for the LCD

	SET_PIN_E(1);				// Now the E pin must be pulled high for some
	AVIX_ASM ("nop");			// time and then low again. This is too short
	AVIX_ASM ("nop");			// to use an AVIX timer and it is far too much
	AVIX_ASM ("nop");			// work and overhead to use a hardware timer
	AVIX_ASM ("nop");			// So for this reason the delay is created
	AVIX_ASM ("nop");			// by just doing nothing for ~12 cycles which
	AVIX_ASM ("nop");			// is 12 * 12.5 ns is 150ns at 80 MIPS
	AVIX_ASM ("nop");
	AVIX_ASM ("nop");			// True, this part is sensitive for switching
	AVIX_ASM ("nop");			// to a much faster device!!!
	AVIX_ASM ("nop");			// Might this happen the required changes are
	AVIX_ASM ("nop");			// localized here and no other code is
	AVIX_ASM ("nop");			// influenced
	SET_PIN_E(0);
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
