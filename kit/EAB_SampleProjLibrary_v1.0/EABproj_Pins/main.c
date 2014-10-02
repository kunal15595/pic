/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project demonstrates the usage of objects in EAB_Pins.h
                  to configure the pins in the hardware.
                  In general any Pin can have either of these three functionalites
                  1> ANALOG : Used to sense an anlog input voltage between GND and VDD/VREF
                  2> DIGITAL: To Read(INPUT) or Write(OUTPUT) Logic level voltages(GND/VDD)
                  3> PERIPHERAL: Work as special function pin to perform various tasks such as
                                Serial/I2C/SPI communication etc. These peripherals also sometime
                                place requirement on the pin to be confiugred as ANALOG or DIGITAL
                                before PERIPHERAL module is enabled.
*******************************************************************************/

#define SYS_CLK 8000000                 // Required for delay macro functions
                                        // Default 1MHZ, else change as per configuration
/*** INCLUDE STANDARD HEADERS & LIBRARY ***/
#include <stdio.h>
#include <stdlib.h>

#include "EAB_Library.h"


/*** GLOBAL VARIABLES ****/

extern uint INT1_Flag_Variable=0;
extern uint IR_count;
uint count=0;
uint array[2];

/*----------------------------------------------------------------------------*/
void main(void)
{

    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_8MHZ();              // Select system clock
    PinDigitalOut(TX1);                     // Set Pin TX1 as digital output
    Timer0.SetPeriod_1Sec();                // Select timer0 at 1 sec
    Serial2.Open(9600);                     // Select UART2 at 9600 Baud Rate

    /*** ENABLE INTERRUPTS IF REQUIRED ***/

    ExternalInt.EnableINT1interrupt(HIGH);  // Interrupt with high priority for INT1 is enabled
    ExternalInt.EnableINT1_SCK2(FALLING_EDGE); // Interrupt for INT1 will occurat falling edge

    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
       /*** TOGGLE TX1 AND SEND DATA ON SERIAL PORT ***/
       if(Timer0_Flag)                              // Has Timer0 period expired,
        {
            Timer0_Flag = 0;                        // CLEAR TIMERFLAG
            PinToggle(TX1);                         // TOGGLE TX1 LED
            count= IR_count;
            IR_count=0;
            array[0]=count;
            array[1]=count>>8;

            Serial2.SendArray(&array,2);

        }
    }
}
/*----------------------------------------------------------------------------*/
