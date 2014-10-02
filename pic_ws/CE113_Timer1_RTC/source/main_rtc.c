
/**********************************************************************
* © 2005 Microchip Technology Inc.
*
* FileName:        main_rtc.c
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
* Richard Fischer   07/18/05  Real-Time Clock example using Timer 1
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:  
* Code Tested on:
* dsPICdem1.1 Demo board with dsPIC33FJ256GP710 controller &
* Explorer 16 Demo board with  PIC24HJ256GP610/dsPIC33FJ256GP710 controller
* The Processor starts with the Internal oscillator without PLL enabled and then the Clock is switched to PLL Mode.
**********************************************************************/

#if defined(__dsPIC33F__)
#include "p33fxxxx.h"
#elif defined(__PIC24H__)
#include "p24hxxxx.h"
#endif

// Select the Board 
#define __dsPICDEM1_1_BRD__     0       // dsPICDEM Development Board
#define __EXPLORER16_BRD__      1       // Explorer 16 Development Board

#include "LCD_demoBrd.h"
#include "LCD_exp16Brd.h"

#include "common.h"




//Macros for Configuration Fuse Registers:
//Invoke macros to set up  device configuration fuse registers.
//The fuses will select the oscillator source, power-up timers, watch-dog
//timers etc. The macros are defined within the device
//header files. The configuration fuse registers reside in Flash memory.


// Internal FRC Oscillator
_FOSCSEL(FNOSC_FRC);		// FRC Oscillator 
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF  & POSCMD_NONE); 
								// Clock Switching is Enabled and Fail Safe Clock Monitor is disabled
								// OSC2 Pin Function: OSC2 is Clock Output
								// Primary Oscillator Mode: Disabled


_FWDT(FWDTEN_OFF);              // Watchdog Timer Enabled/disabled by user software


void Update_LCD( void );

int main ( void )
{

// Configure Oscillator to operate the device at 40Mhz
// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
// Fosc= 8M*40/(2*2)=80Mhz for 8M input clock
	PLLFBD=38;					// M=40
	CLKDIVbits.PLLPOST=0;		// N1=2
	CLKDIVbits.PLLPRE=0;		// N2=2
	OSCTUN=0;					// Tune FRC oscillator, if FRC is used

// Disable Watch Dog Timer
	RCONbits.SWDTEN=0;

// Clock Switch to incorporate PLL
	__builtin_write_OSCCONH(0x01);		// Initiate Clock Switch to 
													// FRC with PLL (NOSC=0b001)
	__builtin_write_OSCCONL(0x01);		// Start clock switching
	while (OSCCONbits.COSC != 0b001);	// Wait for Clock switch to occur	

// Wait for PLL to lock
	while(OSCCONbits.LOCK!=1) {};



	/* Initialize some general use variables */
	hours, minutes, seconds = 0;
	rtc_lcd_update = 0;

	/* set LED0 pins as outputs */
	TRISDbits.TRISD0 = 0; 


    #if(__dsPICDEM1_1_BRD__)

    	/* Initialize SPI and LCD Display */
    	Display_Setup();
    	LCD_HomeClear();
    
    
    	/* position LCD cursor at column, row */
        LCD_CharPos(0,0);
        Display_String(" Real Time Clock  ");
        /* position LCD cursor at column, row */
        LCD_CharPos(0,2);
        Display_String("Time> 00 : 00 : 00  ");
        /* position LCD cursor at column, row */
        LCD_CharPos(0,3);
        Display_String("      Hrs  Min  Sec ");
    
        Delay(1000);

    #endif

    #if(__EXPLORER16_BRD__)

	Init_LCD();
	home_clr();

    puts_lcd((unsigned char *) "Real Time Clock",15);
	line_2();
	puts_lcd((unsigned char *) "00 : 00 : 00 ",12);

	Delay(1000);

    #endif 



  	/* Initialize Timer 1 for 32KHz real-time clock operation */
    Init_Timer1();
    /* Initialize INT1 pin used for setting Time-of-Day */
    Init_INTpin();

     
    while ( 1 ) { 
      if ( rtc_lcd_update ) 
	  {
           Update_LCD();
           rtc_lcd_update = 0;
      }	 	
	};
	
	return 0;
}


/*---------------------------------------------------------------------
  Function Name: Update_LCD
  Description:   Update LCD for real-time clock data
  Inputs:        None
  Returns:       None
-----------------------------------------------------------------------*/


#if(__EXPLORER16_BRD__)
void Update_LCD( void )
{

   	hexdec( hours );
	line_2();
    lcd_data(tens + 0x30);
    lcd_data(ones + 0x30);
    puts_lcd((unsigned char *)" : ",3);   

    hexdec( minutes );
    lcd_data(tens + 0x30);
    lcd_data(ones + 0x30);
    puts_lcd((unsigned char *)" : ",3);   	 

  	hexdec( seconds );
    lcd_data(tens + 0x30);
    lcd_data(ones + 0x30);
   
}
#endif


#if(__dsPICDEM1_1_BRD__)
void Update_LCD( void )
{

   	hexdec( hours );
   	/* position LCD cursor at column, row */
	LCD_CharPos(6,2);
	LCD_WriteNext(tens + 0x30)
	LCD_WriteNext(ones + 0x30)
    
    hexdec( minutes );
    /* position LCD cursor at column, row */
	LCD_CharPos(11,2);
	LCD_WriteNext(tens + 0x30)
	LCD_WriteNext(ones + 0x30)
	 
  	hexdec( seconds );
	/* position LCD cursor at column, row */
	LCD_CharPos(16,2);
	LCD_WriteNext(tens + 0x30)
	LCD_WriteNext(ones + 0x30)
   
}
#endif 
