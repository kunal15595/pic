
/**********************************************************************
* © 2005 Microchip Technology Inc.
*
* FileName:        isr_INTpin.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC33Fxxxx/PIC24Hxxxx
* Compiler:        MPLAB® C30 v3.00 or higher
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and 
* intellectual property rights in the code accompanying this message and in all 
* derivatives hereto.  You may use this code, and any derivatives created by 
* any person or entity by or on your behalf, exclusively with Microchip's
* proprietary products.  Your acceptance and/or use of this code constitutes 
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO 
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A 
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP'S 
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER 
* IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), 
* STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, 
* PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF 
* ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN 
* ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT 
* ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO 
* THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO 
* HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and 
* determining its suitability.  Microchip has no obligation to modify, test, 
* certify, or support the code.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author            Date      Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Richard Fischer   07/18/05  INTx pin interrupt handler
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
*
**********************************************************************/

#if defined(__dsPIC33F__)
#include "p33fxxxx.h"
#elif defined(__PIC24H__)
#include "p24hxxxx.h"
#endif

#include "common.h"



/*---------------------------------------------------------------------
  Function Name: INT1Interrupt
  Description:   INT1 pin Interrupt Handler
  Inputs:        None
  Returns:       None
-----------------------------------------------------------------------*/
void __attribute__ ((interrupt, no_auto_psv)) _INT1Interrupt( void )
{
	unsigned int temp_delay = 0x8FFF;
	
	/* crude delay for debounce, may need to adjust */
	while ( temp_delay --);   // crude short delay

	unsigned char valid_key = 0;
	
	if ( !(PORTA & 0x2000) ) {      // RA13
		valid_key = 1;
	}
	else if ( !PORTAbits.RA14 ) {   // RA14 
		valid_key = 2;
	}
	else if ( !PORTAbits.RA15 ) {   // RA15
		valid_key = 3;
	}
	
	switch ( valid_key )               // evaluate expression 
	{
		case ( 1 ):                    // test if hours will be incremented
			hours++;                   // increment hours
			if ( hours > 23 )          // test if hours will roll over
			{
				hours = 0x00;          // yes, so reset hours
			}
			break;                     // exit from switch evaluation
			
		case ( 2 ):                    // test if minutes will be incremented
			minutes++;                 // increment minutes
			if ( minutes > 59  )       // test if minutes will roll over
			{
				minutes = 0x00;        // yes, so reset minutes
			}
			break;                     // exit from switch evaluation
 
		case ( 3 ):                    // test if seconds will be incremented
			seconds++;                 // increment seconds
			if ( seconds > 59 )        // test if seconds will roll over
			{
				seconds = 0x00;        // yes, so reset seconds
			}
			break;                     // exit from switch evaluation
	
		default:                       // if no match occurs
			break;                     // exit from switch evaluation
	}	

	valid_key = 0;

	/* reset interrupt flag */
	IFS1bits.INT1IF = 0;    
}	
