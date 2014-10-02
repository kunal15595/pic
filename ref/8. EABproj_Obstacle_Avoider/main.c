/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,EAB_Oscillator.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project shows the demo of a obstacle avoiding robot
                  
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
   
    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_8MHZ();          // Select system clock at 8 MHz

    PinDigitalOut(TX1);                 // TX1 as digital Output
    PinDigitalOut(RX1);                 // RX1 as digital Output

    PinWrite.TX1    = LOW;              // Set TX1 Output Low
    PinWrite.RX1    = LOW;              // Set RX1 Output Low

    PinDigitalOut(RC0);                 // RC0 as digital Output
    PinDigitalOut(RA5);                 // RA5 as digital Output
    PinDigitalOut(RB4);                 // RB4 as digital Output
    PinDigitalOut(SDO2);                // SDO2 as digital Output

    PinWrite.RC0    = LOW;              // Set RC0 Output Low
    PinWrite.RA5    = LOW;              // Set RA5 Output Low
    PinWrite.RB4    = LOW;              // Set RB4 Output Low
    PinWrite.SDO2   = LOW;              // Set SDO2 Output Low

    PinDigitalIn(AN0);                  // AN0 as digital Input
    PinDigitalIn(AN1);                  // AN1 as digital Input

    PinWrite.AN0    = LOW;              //Set AN0 Output Low
    PinWrite.AN1    = LOW;              //Set AN1 Output Low


    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
         if(PinRead.AN0 == HIGH)        // Check Input State
        {
            PinWrite.RC0    = LOW;      // Set AN0 Output Low
            PinWrite.RA5    = HIGH;     // Set RA5 Output High
            PinWrite.TX1    = LOW;      // Set TX1 Output Low
        }
        if(PinRead.AN0 == LOW)          // Check Input State
        {
            PinWrite.RC0    = HIGH;     // Set RC0 Output high
            PinWrite.RA5    = LOW;      // Set RA5 Output Low
            PinWrite.TX1    = HIGH;     // Set TX1 Output high
        }
        if(PinRead.AN1 == HIGH)         // Check Input State
        {
            PinWrite.RB4    = LOW;      // Set RB4 Output Low
            PinWrite.SDO2   = HIGH;     // Set SDO2 Output High
            PinWrite.RX1    = LOW;      // Set RX1 Output Low
        }
        if(PinRead.AN1 == LOW)          // Check Input State
        {
            PinWrite.RB4    = HIGH;      //Set RB4 Output High
            PinWrite.SDO2   = LOW;      // Set SDO2 Output Low
            PinWrite.RX1    = HIGH;     // Set RX1 Output High
        }
    }
}
/*----------------------------------------------------------------------------*/


