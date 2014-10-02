/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,EAB_Oscillator.h,EAB_Timer.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project designs a smart gate system
                  
*******************************************************************************/

#define SYS_CLK 8000000        //Required for delay macro functions
                               //Default 1MHZ, else change as per configuration
/*** INCLUDE STANDARD HEADERS & LIBRARY ***/
#include <stdio.h>
#include <stdlib.h>

#include "EAB_Library.h"

/*** GLOBAL VARIABLES ****/

/*----------------------------------------------------------------------------*/
void main(void)
{
    /*** LOCAL VARIABLES ***/
    uint i=0;

    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_8MHZ();                  // Select system clock at 8 MHz

    Timer0.SetPeriod(Timer0.config.PRESCALER_128,Timer0.config.COUNTER_16BIT) ;
                                                // Set Timer0 period with 4 sec
    Timer2.SetPeriod(Timer2.config.PRESCALER_16,Timer2.config.POSTSCALER_16,255);
                                         // set Timer2 period with maximum value

    PinDigitalOut(RC0);                             // RC0 as digital output
    PinDigitalOut(RA5);                             // RA5 as digital output
    PinDigitalIn(RB4);                              // RB4 as digital output
    PinDigitalIn(RC5);                              // RC5 as digital output

    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        if((PinRead.RB4 || PinRead.RC5)==1)         // Check for logic high at
                                                    // RB4 or RC5
        {
            PinWrite.RC0=LOW;                       // Set RC0 output Low
            PinWrite.RA5=HIGH;                      // Set RA5 output Low
            for(i=0;i<10;i++)
            {
                Timer2_Flag=0;
                while(Timer2_Flag ==0);             // Wait for timer2 flag
            }
            PinWrite.RC0=LOW;                       // Set RC0 output Low
            PinWrite.RA5=LOW;                       // Set RA5 output Low
            Timer0_Flag=0;
            while(Timer0_Flag ==0);                 // Wait for timer0 flag

            while((PinRead.RB4 || PinRead.RC5)==0); // Check for logic low at
                                                    // RB4 or RC5
            PinWrite.RC0=HIGH;                      // Set RC0 output High
            PinWrite.RA5=LOW;                       // Set RA5 output Low
            for(i=0;i<10;i++)
            {
                Timer2_Flag=0;
                while(Timer2_Flag ==0);             // Wait for timer2 flag
            }
            PinWrite.RC0=LOW;                       // Set RC0 output Low
            PinWrite.RA5=LOW;                       // Set RA5 output Low
            Timer0_Flag =0;
            while(Timer0_Flag ==0);                 // Wait for timer0 flag
        }
    }
}
/*-----------------------------End Of Code------------------------------------*/
