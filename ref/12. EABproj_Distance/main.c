/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,EAB_Oscillator.h,EAB_Timer.h,EAB_Serial.h,EAB_ADC.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project works for measuring distance of an obstacle w.r.t some specified area
                  
*******************************************************************************/

#define SYS_CLK 8000000        // Required for delay macro functions
                               // Default 1MHZ, else change as per configuration
/*** INCLUDE STANDARD HEADERS & LIBRARY ***/
#include <stdio.h>
#include <stdlib.h>
#include "EAB_Library.h"

/*----------------------------------------------------------------------------*/
void main(void)
{
    /*** LOCAL VARIABLES ***/
    uchar MSB=0, LSB=0;
    short ADCvalue;

    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_8MHZ();              // Select system clock at 8 MHz
    Timer2.SetPeriod(Timer2.config.PRESCALER_16,Timer2.config.POSTSCALER_16,255);     // Set Timer2 at maximum period
    Serial2.Open(9600);                     // Open Serial port with 9600 baudrate
    
    /*** OPEN ADC  ***/
    PinAnalogIn(AN0);                       // AN0 as analog input
    ADC.SetChannel(CHANNEL_AN0);            // Select channel 0
    ADC.Open();                             // Open ADC
    
    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        /*** READ ADC VALUE AND SEND DATA ON SERIAL PORT ***/
        ADCvalue = ADC.ReadData();
        MSB = ADCvalue>>8;
        LSB = ADCvalue;
        Serial2.SendByte(MSB);              // Send higher byte via UART
        Serial2.SendByte(LSB);              // Send lower byte via UART
        Timer2_Flag=0;
        while(!Timer2_Flag);
    }
}
/*----------------------------------------------------------------------------*/
