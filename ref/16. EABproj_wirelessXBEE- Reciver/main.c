/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,EAB_Oscillator.h,EAB_Timer.h,EAB_Serial.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project demonstrates the receiver end of wireless robot
                           
*******************************************************************************/

#define SYS_CLK 8000000       //  Required for delay macro functions
                              //  Default 1MHZ, else change as per configuration
/*** INCLUDE STANDARD HEADERS & LIBRARY ***/
#include <stdio.h>
#include <stdlib.h>

#include "EAB_Library.h"

/*** GLOBAL VARIABLES ****/

/*----------------------------------------------------------------------------*/
void main(void)
{
    /***LOCAL variable***/
    uchar Rcv_Data=0;

    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_8MHZ();              // Select system clock at 8 MHz

    /**Set Timer0 at 0.2 Sec**/
    Timer0.SetPeriod(Timer0.config.PRESCALER_8,Timer0.config.COUNTER_16BIT);

    Serial2.Open(9600);                     // Select UART2 at 9600 Baud Rate
    Serial1.Open(9600);                     // Select UART1 at 9600 Baud Rate

    PinDigitalOut(RC0);                     // RC0 as Digital Output
    PinDigitalOut(RA5);                     // RA5 as Digital Output
    PinDigitalOut(RB4);                     // RB4 as Digital Output
    PinDigitalOut(SDO2);                    // SDO2 as Digital Output
    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        /*** SEND THE RECEIVED DATA ON SERIAL PORT ***/
        if(Serial1_RxFlag)                  // Check receiver1 flag
        {
            Serial2_SendByte(Serial1_ReadByte());   //Transmit via UART2
            Rcv_Data=Serial1_ReadByte();            //Read data from UART1
            Serial1_RxFlag=0;               // Clear the flag
        }
        switch(Rcv_Data)                    //check condition
        {
            case 'W':
            case 'w':
            {
                PinWrite.RC0 = 1;                 // Set RC0 Output High
                PinWrite.RA5 = 0;                 // Set RA5 Output Low
                PinWrite.RB4 = 1;                 // Set RB4 Output High
                PinWrite.SDO2= 0;                 // Set SDO2 Output Low

                break;
            }
            case 'A':
            case 'a':
            {
                PinWrite.RC0 = 0;                 // Set RC0 Output Low
                PinWrite.RA5 = 1;                 // Set RA5 Output High
                PinWrite.RB4 = 1;                 // Set RB4 Output High
                PinWrite.SDO2= 0;                 // Set SDO2 Output Low

                Timer0_Flag = 0;
                while(Timer0_Flag==0);
                Rcv_Data = '0';

                PinWrite.RC0 = 0;                 // Set RC0 Output Low
                PinWrite.RA5 = 0;                 // Set RA5 Output Low
                PinWrite.RB4 = 0;                 // Set RB4 Output Low
                PinWrite.SDO2= 0;                 // Set SDO2 Output Low

                break;
            }
            case 'D':
            case 'd':
            {
                PinWrite.RC0 = 1;                 // Set RC0 Output High
                PinWrite.RA5 = 0;                 // Set RA5 Output Low
                PinWrite.RB4 = 0;                 // Set RB4 Output Low
                PinWrite.SDO2= 1;                 // Set SDO2 Output High

                Timer0_Flag = 0;
                while(Timer0_Flag==0);
                Rcv_Data = '0';

                PinWrite.RC0 = 0;                 // Set RC0 Output Low
                PinWrite.RA5 = 0;                 // Set RA5 Output Low
                PinWrite.RB4 = 0;                 // Set RB4 Output Low
                PinWrite.SDO2= 0;                 // Set SDO2 Output Low
                break;
            }
            case 'S':
            case 's':
            {
                PinWrite.RC0 = 0;                 // Set RC0 Output Low
                PinWrite.RA5 = 1;                 // Set RA5 Output High
                PinWrite.RB4 = 0;                 // Set RB4 Output Low
                PinWrite.SDO2= 1;                 // Set SDO2 Output High
                Timer0_Flag = 0;
                while(Timer0_Flag==0);
                Rcv_Data= '0';
                PinWrite.RC0 = 0;                 // Set RC0 Output Low
                PinWrite.RA5 = 0;                 // Set RA5 Output Low
                PinWrite.RB4 = 0;                 // Set RB4 Output Low
                PinWrite.SDO2= 0;                 // Set SDO2 Output Low
                break;
            }
            case 'X':
            case 'x':
            {
                PinWrite.RC0 = 0;                 // Set RC0 Output Low
                PinWrite.RA5 = 0;                 // Set RA5 Output Low
                PinWrite.RB4 = 0;                 // Set RB4 Output Low
                PinWrite.SDO2= 0;                 // Set SDO2 Output Low
                break;
            }
        }
    }
}
/*----------------------------------------------------------------------------*/
