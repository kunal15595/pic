/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project demonstrates the usage of functions related ADC
                  
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
    uchar MSB=0,LSB=0;
    short ADCvalue;
   
    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_8MHZ();              // Select system clock

    Timer2.SetPeriod(Timer2.config.PRESCALER_16,Timer2.config.POSTSCALER_16,255) ; // Set Timer0 period with 4 sec

    Serial2.Open(9600);
 
    PinDigitalOut(RC0);                 //RC0 as digital output
    PinDigitalOut(RA5);                 //RC5 as digital output
    PinDigitalOut(RB4);                 //RC0 as digital output
    PinDigitalOut(SDO2);                 //RC5 as digital output
    PinDigitalOut(RC5);

    /*** OPEN ADC  ***/
    PinAnalogIn(AN0);
    ADC.SetChannel(CHANNEL_AN0);
    ADC.Open();

    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        ADCvalue = ADC.ReadData();
        MSB = ADCvalue>>8;
        LSB = ADCvalue;
        Serial2.SendByte(MSB);
        Serial2.SendByte(LSB);
        
        if(ADCvalue>24 && ADCvalue<=35)
        {
            PinWrite.RC0=HIGH;
            PinWrite.RA5=LOW;
            PinWrite.RB4=HIGH;
            PinWrite.SDO2=LOW;
            PinWrite.RC5=LOW;
        }

        if(ADCvalue<=24)
        {
            while(ADCvalue <=26)
            {
                PinWrite.RC0=HIGH;
                PinWrite.RA5=LOW;
                PinWrite.RB4=LOW;
                PinWrite.SDO2=HIGH;
                PinWrite.RC5=HIGH;

                Timer2_Flag=0;
                while(Timer2_Flag==0);

                PinWrite.RC0=1;
                PinWrite.RA5=0;
                PinWrite.RB4=1;
                PinWrite.SDO2=0;
                PinWrite.RC5=0;

                Timer2_Flag=0;
                while(Timer2_Flag==0);

                ADCvalue = ADC.ReadData();
            }
        }
        
        if(ADCvalue >35)
        {
            while(ADCvalue>=34)
            {
                PinWrite.RC0=0;
                PinWrite.RA5=HIGH;
                PinWrite.RB4=HIGH;
                PinWrite.SDO2=LOW;
                PinWrite.RC5=LOW;

                Timer2_Flag=0;
                while(Timer2_Flag==0);

                PinWrite.RC0=HIGH;
                PinWrite.RA5=LOW;
                PinWrite.RB4=HIGH;
                PinWrite.SDO2=LOW;
                PinWrite.RC5=LOW;

                Timer2_Flag=0;
                while(Timer2_Flag==0);

                ADCvalue = ADC.ReadData();
            }
        }
    }
}
/*----------------------------------------------------------------------------*/
