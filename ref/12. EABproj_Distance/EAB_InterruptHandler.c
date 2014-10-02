/*******************************************************************************
[File]          : EAB_Oscillator.c
[Dependencies]  : EAB_Library.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : High priority and Low priority interrupt handlers
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com      LEAP from v1.0
*******************************************************************************/

#include "EAB_Library.h"

void  interrupt HighPriority_InterruptHandler(void)
{
    /*** CHECK THE INTERRUPT FLAGS OF HIGH PRIORITY INTERRUPT EVENTS ***/
      

}

void  interrupt low_priority LowPriority_InterruptHandler(void)
{
    /*** CHECK THE INTERRUPT FLAGS OF LOW PRIORITY INTERRUPT EVENTS ***/

}