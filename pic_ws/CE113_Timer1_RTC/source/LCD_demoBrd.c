
/**********************************************************************
* © 2005 Microchip Technology Inc.
*
* FileName:        LCD_demoBrd.c
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
* Richard Fischer   07/18/05  dsPICDEM 1.1 board LCD routines
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
**********************************************************************/

#if defined(__dsPIC33F__)
#include "p33fxxxx.h"
#elif defined(__PIC24H__)
#include "p24hxxxx.h"
#endif

#include "LCD_demoBrd.h"


/*---------------------------------------------------------------------
  Function Name: Display_Setup
  Description:   Initialize the SPI port to communicate with the LCD display
  Inputs:        None
  Returns:       None
-----------------------------------------------------------------------*/
void Display_Setup( void )
{
	unsigned int dummy;
	TRISGbits.TRISG9 = 0;               // and set as output	
    LATG=(PORTG | 0x0200);              // Set slave select HIGH (RG9) 
//    LATG=(PORTG & 0xFDFF);              // Set slave select LOW (RG9) 
	SPI2CON1 = 0x003c;                  // Master mode, SCK = Fcy/64 = 230kHz, Input data sampled at 
	                                    // middle of output time, Data clocked out on rising edge, Clk idle is low
	SPI2STAT = 0x8000;                  // Enable SPI port
}


 
/*---------------------------------------------------------------------
  Function Name: Display_Byte
  Description:   Send a character to the LCD
  Inputs:        Byte to Display on dsPICDEM 1.1 Board LCD
  Returns:       None
-----------------------------------------------------------------------*/
void Display_Byte( unsigned char ByteToDisplay )
{
	unsigned int dummy;

//    LATG=(PORTG | 0x0200);              // Set slave select HIGH (RG9)     	         
	SPI2STATbits.SPIROV = 0;            // Clear overflow flag
	dummy = SPI2BUF;                    // Read buffer to avoid overflow

    LATG=(PORTG & 0xFDFF);              // Set slave select LOW (RG9) for new transmission
    SPI2BUF = ByteToDisplay;            // Write the data to the output buffer
    while (SPI2STATbits.SPIRBF == 0);   // Wait for transmission to complete
    LATG=(PORTG | 0x0200);              // Set slave select HIGH (RG9) 
}


/*---------------------------------------------------------------------
  Function Name: Display_ClrCol
  Description:   Clear a column x of the display
  Inputs:        ..
  Returns:       None
-----------------------------------------------------------------------*/
void Display_ClrCol( unsigned char x )
{
		unsigned char counter;
		counter = 32;			   // Load counter to clear pixel 32 times
		while(counter > 0){
   		   Display_Byte(0xd9);	    // Load command to clear a pixel, Call routine to send the command to the display
	   	   Display_Byte(x);	 	    // Load X location of pixel, Call routine to send the command to the display
		   Display_Byte(counter--); // Load Y location of pixel, Call routine to send the command to the display
		}
}


/*---------------------------------------------------------------------
  Function Name: Display_Pixel
  Description:   Display a pixel at x,y of the display
  Inputs:        ..
  Returns:       None
-----------------------------------------------------------------------*/
void Display_Pixel( unsigned char x,unsigned char y )
{
		Display_Byte(0xd8);		// Load command to set a pixel, Call routine to send the command to the display
		Display_Byte(x);		// Load X location of pixel, Call routine to send the command to the display
		Display_Byte(y);		// Load Y location of pixel, Call routine to send the command to the display
}


/*---------------------------------------------------------------------
  Function Name: Display_String
  Description:   Send a string of characters to the LCD
  Inputs:        ..
  Returns:       None
-----------------------------------------------------------------------*/
void Display_String( unsigned char *Data )
{
   while(*Data)
   {
      Display_Byte(0xa8);
      Display_Byte(*Data++);
   }	
}

