/******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project demonstrates the usage of functions related to
                  Timers(EAB_Timer.h).
                  -> HOW TO SET TIMER PERIOD
                     There are three timers "Timer0", "Timer1", "Timer2"
                     Each Timer object has a fixed period functions and a
                     configurable function. The supported periods are as follows
                     Timer0 -> 1 second, 130 millsecond, 16 millisecond, 1 millisecond, Configurable Period
                     Timer1 -> Configurable period
                     Timer2 -> 1 millisecond, 100 microsecond, Configurable period
                     Example:
                      - Timer0.SetPeriod_16millSec();
                      - Timer0.SetPeriod(Timer0.config.Prescaler_32. Timer0.config.COUNTET_16BIT);
                      - Timer1.SetPeriod(Timer1.config.PRESCALER_8);
                      - Timer2.SetPeriod_100microSec();
                      - Timer2.SetPeriod(Timer2.config.PRESCALER_16,Timer2.config.POSTSCALER_16, 255);
                  -> THE TIMER PERIOD EXPIRE FLAGS
                     You can either check the Timer period expire flag in the while(1) or in
                     Interrupt handler after enabling interrupt.
                     - Timer0 -> Timer0Flag
                     - Timer1 -> Timer1Flag
                     - Timer2 -> Timer2Flag
                  -> HOW TO ENABLE INTERRUPT
                     Each Timer has an associated Enable Interrupt function.
                     The Interrupt can have Priority HIGH or LOW, which needs
                     to be provided to the function input. The Timer0 has default
                     priority as HIGH
                     - Timer0.EnableInterruptHIGH();
                     - Timer1.EnableInterrupt(HIGH);
                     - Timer2.EnableInterrupt(LOW);
                       After Enabling interrupt you need to check the TimerFlag in the
                     respective High/LowPrioiry_InterruptHandler located in file
                    "EAB_InterruptHandler.c"
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
    /*** INTITALIZE OSCILLATOR, TIMER & I/Os ***/
    Oscillator.SetFreq_8MHZ();                      // Select system clock at 8 MHz

    Timer0.SetPeriod_1Sec();                        // Select timer0 for 1 sec time
    Timer2.SetPeriod(Timer2.config.PRESCALER_16,Timer2.config.POSTSCALER_16,255);   //Set timer2 for its maximum time

    PinDigitalOut(TX1);                             // Set TX1 as digital output
    PinDigitalOut(RX1);                             // Set RX1 as digital output

    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        if(Timer0_Flag)                             // Check Timer0 Flag
        {
            Timer0_Flag=0;                          // Clear the Flag
            PinToggle(TX1);                         // Toggle LED D3
        }
        if(Timer2_Flag)                             // Check Timer2 Flag
        {
            Timer2_Flag=0;                          // Clear the Flag
            PinToggle(RX1);                         // Toggle LED D4
        }
        
    }
}
/*----------------------------------------------------------------------------*/
