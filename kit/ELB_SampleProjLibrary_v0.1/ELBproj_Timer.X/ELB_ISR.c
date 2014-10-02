/*
********************************************************************************
[File]          : ELB_ISR.c
[Version]       :
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : Interrupt Service Routine for various peripherals to be written
                  in this file. The name of functions for interrupt service routine
                  can be found in Interrupt Vector Table section of the document
                  "MPLAB_C_Compiler_PIC24_dsPIC_UG_51284J.pdf" placed at
                  INSTALL LOCATION \mplabc30\v3.30c\docs
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR] 				CHANGES
********************************************************************************
*/

/*** MICROCHIP LIBRARY ***/
#include <p24fxxxx.h>
#include <p24FJ256GB206.h>
#include <pic24f_periph_features.h>
#include <timer.h>
#include <ports.h>

/*** BRIGOSHA LIBRARY ***/
#include "Define.h"

/*** GLOBAL VARIABLES ***/
U8 V_T1IntFlag_U8=0;        //Interrupt Flag for Push Button 

/*
--------------------------------------------------------------------------------
[NAME]  	 : _T1Interrupt
[TYPE]		 : Interrupt service routine
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]    : This function Interrupts when the timer1 period has elapsed,
--------------------------------------------------------------------------------
*/

void __attribute__ ((interrupt,no_auto_psv)) _T1Interrupt(void)
{
        IFS0bits.T1IF = 0;
        V_T1IntFlag_U8=1;
}
