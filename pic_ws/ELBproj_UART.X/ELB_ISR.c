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
/*** MICROCHIP LIBRARY ***/
#include <p24fxxxx.h>
#include <p24FJ256GB206.h>
#include <pic24f_periph_features.h>
#include <uart.h>

#include "Define.h"

/*** GLOBAL VARIABLES ***/
U8 V_Rx1IntFlag_U8=0;

/*
---------------------------------------------------------------------------------------------------
[NAME]  	 : _U1RXInterrupt
[TYPE]		 : Interrupt service routine
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]    : This function interrupts when data is being recived in UART1
---------------------------------------------------------------------------------------------------
*/
void __attribute__ ((interrupt,no_auto_psv)) _U1RXInterrupt(void)
{
   	U1RX_Clear_Intr_Status_Bit;
        V_Rx1IntFlag_U8 = 1;

}



