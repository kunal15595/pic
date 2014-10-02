/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,EAB_Oscillator.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project demonstrates the control of DC motor
                  
*******************************************************************************/

#define SYS_CLK 8000000                             //Required for delay macro functions
                                                    //Default 1MHZ, else change as per configuration
/*** INCLUDE STANDARD HEADERS & LIBRARY ***/
#include <stdio.h>
#include <stdlib.h>

#include "EAB_Library.h"

/*** GLOBAL VARIABLES ****/

/*----------------------------------------------------------------------------*/
void main(void)
{   
    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_8MHZ();                      //Select system clock at 8 MHz

    PinDigitalOut(RC0);                             //RC0 as digital output
    PinDigitalOut(RC5);                             //RC5 as digital output

    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        PinWrite.RC0=HIGH;                          //Set RC0 output High
        PinWrite.RC5=LOW;                           //Set RC5 output Low
           
        DelayMillisec(5000);                        //wait for 5 sec

        PinWrite.RC0=LOW;                           //Set RC0 output Low
        PinWrite.RC5=LOW;                           //Set RC5 output Low

        DelayMillisec(2000);                        //wait for 2 sec

        PinWrite.RC0=LOW;                           //Set RC0 output Low
        PinWrite.RC5=HIGH;                          //Set RC5 output High

        DelayMillisec(5000);                        //wait for 5 sec

        PinWrite.RC0=LOW;                           //Set RC0 output Low
        PinWrite.RC5=LOW;                           //Set RC5 output Low

        DelayMillisec(2000);                        //wait for 2 sec
    }
}
/*---------------------------------End Of Code--------------------------------*/
