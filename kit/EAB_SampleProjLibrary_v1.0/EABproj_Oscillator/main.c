
/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project demonstrates the usage of functions related to
                  Oscillators(EAB_Oscillators.h).
                  -> You can configure different System clock frequencies by
                     calling functions from "Oscillator" object
                     eg. Oscillator.SetFreq_8MHZ();
                         Oscillator.SetFreq_1MHZ();
                  -> If you do not configure the Oscillator the Default
                     System clock will be 1MHZ from Internal RC Oscillator
                  -> If you wish to use the external Crystal for the system clock
                     frequencies of 8MZ or 32MHZ, then declare this macro on top,
                     above EAB_Library.h
                     #define USE_EXTERNAL_CRYSTAL
*******************************************************************************/

#define SYS_CLK 8000000             //Required for delay macro functions
                                    //Default 1MHZ, else change as per configuration

/*** INCLUDE STANDARD HEADERS & LIBRARY ***/
#include <stdio.h>
#include <stdlib.h>

#include "EAB_Library.h"

/*** GLOBAL VARIABLES ****/
/*----------------------------------------------------------------------------*/
void main(void)
{
    /*** LOCAL VARIABLES***/

    long y;

    /*** INTITALIZE OSCILLATOR, TIMER & I/Os ***/
    Oscillator.SetFreq_8MHZ();                      // Select system clock at 8 MHz
    y=Oscillator.GetFreq();                         // Returns oscillator current frequency

    PinDigitalOut(TX1);                             // Set TX1 as digital output
    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {

            PinToggle(TX1);                         // Toggle LED D3
            DelayMillisec(100);                     // 100 milli sec delay
     }
}

/*----------------------------------------------------------------------------*/
