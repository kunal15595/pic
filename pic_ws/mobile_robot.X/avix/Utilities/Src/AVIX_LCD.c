
/*=================================================================================================
**
**	===============================================================================================
**	PRODUCT:			---------- AVIX - (ADVANCED VIRTUAL INTEGRATED EXECUTIVE) RTOS ------------
**	===============================================================================================
**
**	===============================================================================================
** 	PRODUCT VERSION: 	4.1
** 	COPYRIGHT:			AVIX-RT EMBEDDED SOLUTIONS
**	===============================================================================================
**
**	===============================================================================================
**	UNDER NO CIRCUMSTANCE MAY THE CONTENT OF THIS FILE BE CHANGED. ANY CHANGE OF THE DEFINITIONS IN
**	THIS FILE MAY  LEAD TO AVIX  NOT WORKING OR WORKING  IN A UNPREDICTABLE  MANNER.
**	===============================================================================================
**
**	SOFTWARE LICENSE AGREEMENT
**	--------------------------
**
**	THE  SOFTWARE  SUPPLIED  HEREWITH  AS  THE  CONTENT  OF  THIS FILE IS OWNED BY AVIX-RT EMBEDDED
**	SOLUTIONS  (THE "COMPANY"), AND IS PROTECTED  UNDER APPLICABLE  COPYRIGHT LAWS.  ALL RIGHTS ARE
**	RESERVED.  THE SOFTWARE IS SUPPLIED TO YOU (THE "CUSTOMER")  FOR USE  SOLELY AND EXCLUSIVELY AS
**	PART OF AND TOGETHER WITH PRODUCTS MANUFACTURED BY "COMPANY" AND LICENSED TO "CUSTOMER".
**
**	"COMPANY" LICENSES "CUSTOMER"  THE RIGHT TO USE  THIS FILE FOR THE  SOLE PURPOSE  OF DEVELOPING
**	APPLICATION SOFTWARE BASED ON ONE OF "COMPANIES" PRODUCTS AND FOR EXCLUSIVE USE ON A  SUPPORTED
**	MICROCONTROLLER.
**
**	UNDER NO CIRCUMSTANCE  MAY THE CONTENT OF  THIS FILE,  EITHER PARTIALLY  OR COMPLETE,  BE  MADE
**	PUBLIC, EITHER ELECTRONICALLY OR PRINTED.
**
**	ANY VIOLATION TO THE FOREGOING RESTRICTIONS  MAY SUBJECT THE USER  TO CRIMINAL SANCTIONS  UNDER
**	APPLICABLE LAWS, AS WELL AS TO CIVIL  LIABILITY FOR  THE BREACH  OF THE TERMS AND CONDITIONS OF
**	THIS LICENSE.
**
**	YOU SHOULD REFER TO THE LICENSE AGREEMENT  ACCOMPANYING THE  PRODUCT THIS  SOFTWARE IS  PART OF
**	FOR ADDITIONAL INFORMATION REGARDING YOUR RIGHTS AND OBLIGATIONS.
**
**	THE SOFTWARE  AND DOCUMENTATION  ARE PROVIDED  "AS IS"  WITHOUT  WARRANTY  OF ANY  KIND, EITHER
**	EXPRESS OR IMPLIED, INCLUDING WITHOUT  LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR
**	A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL "COMPANY" BE LIABLE FOR ANY
**	INCIDENTAL, SPECIAL,  INDIRECT OR  CONSEQUENTIAL DAMAGES,  LOST PROFITS  OR LOST  DATA, COST OF
**	PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING
**	BUT NOT  LIMITED TO ANY DEFENSE  THEREOF),  ANY CLAIMS  FOR  INDEMNITY OR CONTRIBUTION,OR OTHER
**	SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF  CONTRACT, TORT  (INCLUDING NEGLIGENCE), BREACH
**	OF WARRANTY, OR OTHERWISE.
**
**	COPYRIGHT (C) 2006-2010 AVIX-RT EMBEDDED SOLUTIONS.  ALL RIGHTS RESERVED.
**
**	===============================================================================================
**
**	Description:
**  ------------
**	This file contains software to control the Explorer 16 LCD display. Data to be displayed is
**	written directly to a structure that is subsequently read by a local thread to be displayed.
**	The struct is protected by a mutex.
**
**=================================================================================================
**	IMPORTANT NOTICE: THIS CODE  IS ONLY MEANT TO  ILLUSTRATE THE SERVER THREAD PRINCIPLE. THE CODE
**	IS (STILL) PIC32 SPECIFIC  DUE TO THE WAY PIC32 PORTS  ARE BEING USED. IN A FUTURE VERSION THIS
**	CODE WILL BE PORTABLE TO PIC24, dsPIC30F AND dsPIC33F.
**=================================================================================================
**
**	Interface:
**	----------
**	avixLCD_Init:			Called before any call to avixLCD_Write
**	avixLCD_Write:			Write a zero terminated string to the LCD, column and row
**							and optionally set blinking on or off
**	avixLCD_SetBlinkMode:	Change blink mode of characters on LCD.
**
**=================================================================================================
**
**=================================================================================================
** INCLUDES
**=================================================================================================
*/
#include <stdio.h>


#include "AVIX.h"			/* AVIX required definitions			*/
#include "AVIXAtomicSFR.h"	/* Macro's for atomic SFR manipulation	*/



/*=================================================================================================
** EXTERNAL DECLARATIONS
**=================================================================================================
*/


/*=================================================================================================
** TYPE DEFINITIONS
**=================================================================================================
*/


/*=================================================================================================
** MACROS
**=================================================================================================
**
** Port definitions for the LCD display. For these definitions, use is made
** of the atomic port manipulation macros from AVIXAtomicSFR.h. These macros
** are described in AvixAtomicSFRManipulation.pdf installed in the AVIX
** Doc directory. By using these macros, when from a certain SFR other 
** bitfields are manipulated from other threads or ISR's, these concurrent
** manipulations do not conflict.
**
** Data port is port E bit 0..7. 
*/
#define SET_DATA_PORT_OUTPUT	avixSFR_Range(TRISE, 0, 7, WRITE_BF, 0)
#define SET_DATA_PORT_DATA(v)	avixSFR_Range(LATE,  0, 7, WRITE_BF, (v))


/* RS port is port B bit 15. Note that for using port B it is 
** required to set the ADC pin configuration register AD1PCFG
** bit 15 to 1 also. Note bit that it is a coincidence that both
** AD1PCFG and the LCD RS pin use bit 15!
** Also note that the different controllers this LCD module works for
** have different ADC capabilities and thus different ADPCFG register names.
** For this reason the following part 
*/
#if defined(__PIC24FJ256GB210__)
	#define ADCRegister		AD1PCFG		// ADC Pin Configuration register for 24FJ128GA010
#elif defined(__PIC24HJ256GP610__)
	#define ADCRegister		AD1PCFGL	// ADC Pin Configuration register for 24HJ256GP610
#elif defined(__dsPIC33FJ256GP710__) || defined(__dsPIC33FJ256GP710A__)
	#define ADCRegister		AD1PCFGL	// ADC Pin Configuration register for 33FJ256GP710
#elif defined(__32MX360F512L__)
	#define ADCRegister		AD1PCFG		// ADC Pin Configuration register for 32MX360F512L
#else
	#error current type of controller not supported by demo software
#endif

#define SET_PIN_RS_OUTPUT		{											\
								avixSFR(ADCRegister, PCFG15,  WRITE_BF, 1); 	\
								avixSFR(TRISB, 	 	 TRISB15, WRITE_BF, 0);	}
#define SET_PIN_RS(v)			avixSFR(LATB, 	 	 LATB15,  WRITE_BF, (v))


/* RW port is port D bit 5
*/
#define SET_PIN_RW_OUTPUT		avixSFR(TRISD, TRISD5, WRITE_BF, 0)
#define SET_PIN_RW(v)			avixSFR(LATD,  LATD5,  WRITE_BF, (v))


/* E port is port D bit 4
*/
#define SET_PIN_E_OUTPUT		avixSFR(TRISD, TRISD4, WRITE_BF, 0)
#define SET_PIN_E(v)			avixSFR(LATD,  LATD4,  WRITE_BF, (v))


/* Display size
*/
#define NR_ROWS			2
#define	NR_COLUMNS		16

/* Refresh rate and blink rate
*/
#define LCD_REFRESH_MS	100
#define LCD_BLINK_MS	500



/*=================================================================================================
** GLOBAL VARIABLES
**=================================================================================================
**
** Management struct used for containing display data. Each character is stored together with a
** changed flag. When a character is written by a client, the changed flag is set. This flag is 
** used when the LCD thread updates the LCD. It scans all changed flags in a critical section and
** if the flag is set, the update flag is set. Next outside the critical section the LCD thread
** again scans all data to find the update flags that are set. For those characters that have their
** update flag set, the data is written to the LCD.
*/
struct
{
	struct avixChar
	{
		struct sDispData
		{
			char 			t:8;		/* Character to display 										*/
			unsigned char 	blinking:1;	/* Flag set when character must blink 							*/
			unsigned char	changed:1;	/* Flag set when character value or blink flag is written 		*/
			unsigned char	update:1;	/* Flag set by lcd control thread when char pos needs update	*/
		}	content[NR_ROWS * NR_COLUMNS];
	}				page;
	tavixMutexId	mutex;				/* Mutex to guard access to char buffer from multiple threads	*/
} lcd;



/*=================================================================================================
** FORWARD FUNCTION DECLARATIONS
**=================================================================================================
*/
static __attribute__((noinline)) void	LCDOut (unsigned char addr, unsigned char data);
static TAVIX_THREAD_REGULAR 			threadLCD(void* p);




/*=================================================================================================
** EXPORTED USER FUNCTIONS
**=================================================================================================
*/

/*=================================================================================================
**	Function name:	avixLCD_Init
**	----------------------------
**	Description:
**	
**	Initialization routine for the LCD. This function must be called before any thread making use
**	of the LCD functions, preferably from within avixMain. Reason is that here the mutex is
**	created which is used when writing to the shared memory forming the interface between the LCD
**	thread and the client threads.
**
**	Postcondition:
**	--------------
**	Thread at priority 1 with a stack of 700 bytes.
**
**=================================================================================================
*/
tavixThreadId avixLCD_Init()
{
	tavixThreadId 		tid;
	struct sDispData*	pData;
	
	/* Start the thread responsible for display management;
	*/
	tid = avixThread_Create("tLCD", threadLCD, NULL, 1, 350, AVIX_THREAD_READY);
		
	/* Create the mutex responsible for guarding access to the shared memory forming
	** the interface between the LCD thread and the client threads.
	*/
	lcd.mutex = avixMutex_Create(NULL, AVIX_MUTEX_UNLOCKED);
	
	/* Initialize the data buffer with blanks, non-flashing. The changed flag is set 1
	** for every character so initially all blanks will be written to the LCD
	*/
	pData = &lcd.page.content[0];
	do
	{
		pData->t		= ' ';	/* Initial value is white space 						*/
		pData->blinking	= 0;	/* Initially character is not blinking 					*/
		pData->changed	= 1;	/* Setting changed takes care of initial blank display	*/
		pData->update   = 0;	/* Set by controlling thread							*/
		
		pData++;
	} while (pData != &lcd.page.content[NR_ROWS*NR_COLUMNS]);
	
	return tid;
}






/*=================================================================================================
**	Function name:	avixLCD_Write
**	-----------------------------
**	Description:
**	
**	Write text to LCD.
**
**=================================================================================================
*/
void avixLCD_Write(char* pText, int row, int column, int blink)
{
	struct sDispData*	pData;
	
	/* Guard the function against writing outside the array for characters
	*/
	if ((row >= 0) && (row < NR_ROWS) && (column >= 0) && (column < NR_COLUMNS))
	{
		/* Lock the lcd data mutex so the coming operation
		** can not be interrupted by another thread.
		*/
		avixMutex_Lock(lcd.mutex);
		
		/* Set the data pointer to the desired cursor position
		*/
		pData = &lcd.page.content[(row * NR_COLUMNS) + column];
		
		/* Continue copying new characters as long as there are new characters
		** (trailing zero not yet encountered) and the end of the LCD module 
		** internal data buffer is not reached
		*/
		while(*pText && (pData < &lcd.page.content[NR_ROWS * NR_COLUMNS]))
		{
			/* If data at current position differs from current, save the
			** character in the lcd data structure and set the changed flag
			*/
			if ((pData->blinking != blink) || (pData->t != *pText))
			{
				pData->blinking	= blink;
				pData->t		= *pText;
				pData->changed	= 1;
			}	
			pText++;
			pData++;
		}
		
		/* Unlock the mutex so other operations are possible again
		*/
		avixMutex_Unlock(lcd.mutex);
	}
}





/*=================================================================================================
**	Function name:	avixLCD_SetBlinkMode
**	------------------------------------
**	Description:
**	
**	Change blink mode of designed group of characters
**
**=================================================================================================
*/
void avixLCD_SetBlinkMode(int row, int column, int count, int blink)
{
	struct sDispData*	pData;

	/* Guard the function against writing outside the array for characters
	*/
	if ((row >= 0) && (row < NR_ROWS) && (column >= 0) && (column < NR_COLUMNS))
	{
		/* Lock the lcd data mutex so the coming operation
		** can not be interrupted by another thread.
		*/
		avixMutex_Lock(lcd.mutex);
		
		/* Set the data pointer to the desired cursor position
		*/
		pData = &lcd.page.content[(row * NR_COLUMNS) + column];
		
		/* Continue processing characters as long as there are characters to change
		** and the end of the LCD module internal data buffer is not reached
		*/
		while(count && (pData < &lcd.page.content[NR_ROWS * NR_COLUMNS]))
		{
			/* If current character blink mode differs from new blink mode,
			** change it
			*/
			if (pData->blinking	!= blink)
			{
				pData->blinking	= blink;
				pData->changed	= 1;
			}	
			count--;
			pData++;
		}
		
		/* Free access to data are again
		*/
		avixMutex_Unlock(lcd.mutex);
	}
}
	






/*=================================================================================================
**	Function name:	threadLCD
**	-------------------------
**	Description:
**	
**	Initialize the LCD and cyclic update the LCD with changed data
**
**	Design decission:
*	-----------------
**	This thread polls the changed flags in the data with a period of LCD_REFRESH_MS. Chances are
**	most of the time it does not find any changes and thus woke up for nothing. Especially using an
**	RTOS an event could be defined to only wake up the thread if there is something to do.
**	This code does not pretend to be the most optimized and further on, the LCD thread is supposed
**	to run at the systems lowest priority so it will only kick in when there is no more important
**	work.
**
**	An alternative approach could be the following:
**	-----------------------------------------------
**	Let the thread wait for one of its local event flags. When data is written and there is a
**	change, the calling function sets this flag. Doing so the thread will only wake when there is
**	changed data.
**	For the blinking a second flag can be used. When blinking is active, a timer is started with
**	the desired blink period.
**
**=================================================================================================
*/
static TAVIX_THREAD_REGULAR threadLCD(void* p)
{
	/* These are local variables for this function so these will exist as long as the thread
	** is running.
	*/
	struct sDispData*	pData;
	int 				i;
	int					update;				/* Flag set when LCD needs updating		*/
	int					blinkCount;			/* Counter blinking number of ms		*/
	int					blinkState;			/* Toggled every xxx ms for blinking	*/
	int					blinkStateChanged;	/* Set true if blinkState is changed	*/
		
	/* Initialize the LCD, taking into account the different wait
	** cycles specified by the lcd documentation
	*/
	SET_PIN_E(0);	
	SET_PIN_RS_OUTPUT;	
	SET_PIN_E_OUTPUT;
	SET_PIN_RW_OUTPUT;
   	SET_DATA_PORT_OUTPUT;

	avixThread_Sleep(AVIX_DELAY_MS(40));	/* Initial power up delay is 40 ms		*/

	LCDOut(0, 0x30);						/* The next part is the defined 		*/
	avixThread_Sleep(AVIX_DELAY_MS(5));		/* initialization sequence with HD44780	*/
	LCDOut(0, 0x30);						/* specified delays in between			*/
	avixThread_Sleep(AVIX_DELAY_US(100));
   	LCDOut(0, 0x30);						
	avixThread_Sleep(AVIX_DELAY_US(50));
  
  	/* From now on between every command a minimim of 37us must be waited
  	** according the HD44780 command specification, except the clear
  	** which requires a minimum of 1.37ms
  	*/ 	
	LCDOut(0, 0x38);						/* Function set, 8 bit interface,	*/
	avixThread_Sleep(AVIX_DELAY_US(50));	/* two display lines and font		*/

	LCDOut(0, 0x08);						/* Display off, cursor off,			*/
	avixThread_Sleep(AVIX_DELAY_US(50));	/* no blink							*/

	LCDOut(0, 0x01);						/* Clear entire display			*/
	avixThread_Sleep(AVIX_DELAY_MS(2));

	LCDOut(0, 0x0c);						/* Display on, cursor off			*/
	avixThread_Sleep(AVIX_DELAY_US(50));


	LCDOut(0, 0x06);						/* No shifting						*/
	avixThread_Sleep(AVIX_DELAY_US(50));


	/* Initialize the blinking stuff
	*/
	blinkCount = LCD_BLINK_MS;
	blinkState = 0;
	
	while(1)
	{
		/* Sleep for the refresh time. This is quite a brute force implementation, every
		** cycle the thread wakes up to see if the LCD content needs to be updated.
		** This is not inefficient since the LCD thread runs at the lowest priority
		** so this can be thought of something like an idle thread.
		*/
		avixThread_Sleep(AVIX_DELAY_MS(LCD_REFRESH_MS));
		
		/* Decrement the blink counter and if expired change the blinkstate
		*/
		blinkCount -= LCD_REFRESH_MS;
		blinkStateChanged = 0;
		if (blinkCount <= 0)
		{
			blinkCount = LCD_BLINK_MS;
			blinkState = blinkState ? 0 : 1;
			blinkStateChanged = 1;
		}
		
		/* Determine in a critical section which char positions need update. Here the changed
		** flag is copied to the update flag which is used during the actual writing to the
		** LCD. This is quite an important structure. Here the data is scanned and while
		** scanned it is locked with a mutex. This implies that threads wanting to write
		** while this scanning is going on have to wait. So it is important this goes 
		** as fast as possible. This is the reason the actual writing to the LCD is done
		** outside the critical section guarded by the mutex since this is a relativelly
		** slow process.
		*/
		avixMutex_Lock(lcd.mutex);

		/* Set the 'global' update flag fals, the scanning will reveal if an update
		** is required
		*/
		update = 0;
		pData = &lcd.page.content[0];
		do
		{
			/* Initially for an individual character the update flag is reset.
			** Only if the character is changed its corresponding update flag
			** needs to be set
			*/
			pData->update = 0;
			if(pData->changed ||(pData->blinking && blinkStateChanged))
			{
				pData->update = 1;
				update = 1;
			}
			pData->changed = 0;
			
			pData++;
		} while (pData != &lcd.page.content[NR_ROWS*NR_COLUMNS]);

		avixMutex_Unlock(lcd.mutex);

		/* And now do the (relativelly slow) update of the lcd. This update is done
		** outside the critical section since it is rather slow. The struct is
		** only read here and because it is done outside the critical section it can
		** happen data is written which is obsolete. In that case however in a future
		** cycle this will be overwritten with new data too fast for the human eye to
		** notice any disturbance.
		*/
		if (update)
		{
			pData = &lcd.page.content[0];
			for (i = 0; i < NR_ROWS*NR_COLUMNS; i++)
			{
				if (pData->update)
				{
					/* Send address to LCD followed by data
					*/
					LCDOut(0, 0x80 | (i/NR_COLUMNS ? 0x40 : 0x00) | i%NR_COLUMNS);
					avixThread_Sleep(AVIX_DELAY_US(50));
					
					/* If the character needs blinking, alternativelly the actual character
					** and a white space ' ' is writtten to get the blinking effect
					*/
					LCDOut(1, (pData->blinking && blinkState) ? ' ' : pData->t);
					avixThread_Sleep(AVIX_DELAY_US(50));
				}
				pData++;
			}
		}
	}
}






/*=================================================================================================
**	Function name:	LCDOut
**	----------------------
**	Description:
**	
**	Low level LCD write routine. This function writes a byte to the HD44780 LCD controller
**
**	Not sure whether all low level timing is according specification HD44780.
**
**=================================================================================================
*/
static __attribute__((noinline)) void LCDOut (unsigned char addr, unsigned char data)
{
	SET_PIN_RW(0);				/* Set direction for writing to LCD controller	*/
	SET_PIN_RS(addr);			/* Command data mode based on argument			*/
	SET_DATA_PORT_DATA(data);	/* Set the actual data bits for the LCD			*/

	SET_PIN_E(1);				/* Now the E pin must be pulled high for some	*/
	asm volatile ("nop");		/* time and the low again. This is too short	*/
	asm volatile ("nop");		/* to use an AVIX timer and it is far too much	*/
	asm volatile ("nop");		/* work and overhead to use a hardware timer	*/
	asm volatile ("nop");		/* So for this reason the delay is created		*/
	asm volatile ("nop");		/* by just doing nothing for ~12 cycles which	*/
	asm volatile ("nop");		/* is 12 * 12.5 ns is 150ns at 80 MIPS			*/
	asm volatile ("nop");
	asm volatile ("nop");		/* True, this part is sensitive for switching	*/
	asm volatile ("nop");		/* to a much faster device!!!					*/
	asm volatile ("nop");       /* Might this happen the required changes are   */
	asm volatile ("nop");		/* localized here and no other code is          */
	asm volatile ("nop");       /* influenced                                   */
	SET_PIN_E(0);
}

