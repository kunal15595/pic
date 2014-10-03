/*
********************************************************************************
[File]          : ELB_ISR.c
[Version]       : 
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : Interrupt Service Routine for various peripherals to be written
                  in this file. For The name of functions for interrupt service routine
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
#include <ports.h>

/*** BRIGOSHA LIBRARY ***/
#include "Define.h"

/*** GLOBAL VARIABLES ***/
U8 V_PBIntFlag_U8=0;            //Interrupt Flag for Push Button 

/*
--------------------------------------------------------------------------------
[NAME]  	 : _CNInterrupt
[TYPE]		 : Interrupt service routine
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]    : This function interrupts when the Change Notification pins
                   connectd to Push button PB1-3 are pressed or PB1-3 state is
                   changed. The push button interrupt flag is set true. this can
                   be checked to verify for switch press or logical int.
--------------------------------------------------------------------------------
*/
void __attribute__((interrupt,no_auto_psv)) _CNInterrupt(void)
{
        InputChange_Clear_Intr_Status_Bit;
	V_PBIntFlag_U8 = C_TRUE;	

}
