/*******************************************************************************
[File]          : EAB_Oscillator.c
[Dependencies]  : EAB_Library.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : High priority and Low priority interrupt handlers
*******************************************************************************/

#include "EAB_Library.h"
uint INT1_Flag_Variable=0;
uint IR_count=0;

void  interrupt HighPriority_InterruptHandler(void)
{
    /*** CHECK THE INTERRUPT FLAGS OF HIGH PRIORITY INTERRUPT EVENTS ***/
      if(INT1_Flag)
    {
       INT1_Flag_Variable=PinRead.SCK2;
       INT1_Flag_Variable=1;
       IR_count++;
       INT1_Flag=0;
    }
}

void  interrupt low_priority LowPriority_InterruptHandler(void)
{
    /*** CHECK THE INTERRUPT FLAGS OF LOW PRIORITY INTERRUPT EVENTS ***/

}