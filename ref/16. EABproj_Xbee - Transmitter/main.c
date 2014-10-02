/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,EAB_Oscillator.h,EAB_Serial.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project demonstrates the transmitter end of wireless robot
                           
*******************************************************************************/

#define SYS_CLK 8000000        // Required for delay macro functions
                               // Default 1MHZ, else change as per configuration
/*** INCLUDE STANDARD HEADERS & LIBRARY ***/
#include <stdio.h>
#include <stdlib.h>

#include "EAB_Library.h"

/*** GLOBAL VARIABLES ****/

/*----------------------------------------------------------------------------*/
void main(void)
{

    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_8MHZ();              // Select system clock at 8 MHz

    Serial2.Open(9600);                     // Select UART2 at 9600 Baud Rate
    Serial1.Open(9600);                     // Select UART1 at 9600 Baud Rate
    
    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        /*** SEND THE RECEIVED DATA ON SERIAL PORT ***/
        if(Serial2_RxFlag)                  // Check receiver1 flag
        {
            Serial1_SendByte(Serial2_ReadByte());   //Transmit via UART1
            Serial2_RxFlag=0;               // Clear the Flag
        }
    }
}
/*----------------------------------------------------------------------------*/
