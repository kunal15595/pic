/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project demonstrates the usage of functions related to
                  serial communication
                  -> HOW TO CONFIGURE/INTIALIZE SERIAL COMMUNICATION
                     The most important configuration for serial communciation is
                     the data rate known as Baud Rate. This can be provided as input to the serial
                     port open function. The other default settings are 8-N-1.
                     i.e. 8 data bits, No Parity,  1 Stop bit
                     Example:
                      - Serial2.Open(9600);
                      - Serial2.Open(115200);
                  -> HOW TO SEND DATA OVER SERIAL PORT
                     Different scenarios require to send a byte of data, or a number of bytes,
                     or a string. There are three functions to serve these needs
                     Examples
                     - char data = 'a';
                       Serial2.SendByte(data);
                       Serial2.SendByte(100);
                       Serial2_SendByte(100); //For faster execution times
                    -  char ArrayData[5] ={1,2,3,4,5};
                       Serial2.SendArray(ArrayData,5);
                    -  char StringData[] ="Hello ";
                       Serial2.SendString(StringData);
                  -> HOW TO READ DATA RECIEVED IN THE SERIAL PORT
                     The data recieved is stored in the serial recieve buffer and
                     event flag is generated for notiifcation. So you can check this flag,
                     if it is true then new data byte has come to serial buffer, then the read the buffer
                     Example :
                     -  char RcvByte;
                        if(Serial2_RxFlag)
                        {
                            RcvByte = Serial2.ReadByte();
                        }
                  -> HOW TO ENABLE SERIAL DATA RECIEVE INTERRUPT
                     Example :
                     - Serial2.EnableRxInterrupt(HIGH);
                     - Then check the Serial2_RxFlag in the HighPriority_InterruptHandler();
                     - for serial send and recieve byte use Alternate functions
                        Serial2_SendByte(data);
                        Data = Serial2_ReadByte();
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
    /*** LOCAL VARIABLES ***/
    char data = 'a';
    char ArrayData[5] ={1,2,3,4,5};
    char StringData[] ="Hello";

    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_8MHZ();                   // Select system clock
    Timer0.SetPeriod_1Sec();                     // Set Timer0 period

    /*** OPEN SERIAL PORT WITH 9600 BAUDRATE ***/
    Serial2.Open(9600);

    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        /*** TOGGLE TX1 LED AND SEND DATA ON SERIAL PORT ***/
        if(Timer0_Flag)                         //Has Timer0 period expired,
        {
            Timer0_Flag = 0;                    //Clear TimerFlag
    
            Serial2.SendByte(data);             //Send a single byte varible
            Serial2.SendByte(100);              //Send a single byte of data
            Serial2.SendArray(ArrayData,5);     //Send a number of bytes stored in an array
            Serial2.SendString(StringData);     //send a number of bytes stored as string
        }
    }
}

/*----------------------------------------------------------------------------*/
