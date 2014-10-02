/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project demonstrates the usage of functions related ADC
                 -> CONFIGURE ADC
                    There are various pins which can function as ANALOG INPUT pins.
                    There is only one ADC module in the microcontroller, which converts the voltage to digital value.
                    Therfore user needs to select and specify from which pin/adc channel the voltage needs to be sensed.
                    The below function does this work.
                    Example:
                    ADC.SetChannel(CHANNEL_AN2);
                    The function input is the pin name from which the input needs to be sensed.
                    The naming method is CHANNEL_PINNAME. The complete list can be found in EAB_ADC.h

                    The ADC module needs to configured for voltage sensing, the key configuration parameters are Reference voltage,
                    the ADC clock frequency and conversion wait times. This configuration is achieved by the below function
                    Example:
                    ADC.Open();
                    This function configures the ADC module with default values, which is good enough for most of the applications.
                    +Vref = VDD, -Vref = GND, Acquisition time = 12TAD, ADC clock frequency = 1MHZ.
                    NOTE: the ADC clock frequency of 1MHZ cannot be achieved at Oscillatore frequencies of 31.25KHZ and 250KHZ

                 -> READ DATA FROM ADC
                    Once the channel is selcted and ADC module configured. The data can be read using the below function.
                    Example:
                    ADCvalue = ADC.ReadData();
                    This function returns a 16 bit number in which the 10LSB bits contain the value from ADC buffer registers.

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
    /*** LOCAL VARIABLES ***/
    uchar MSB=0, LSB=0;
    short ADCvalue;

    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_8MHZ();                      // Select system clock
    Timer0.SetPeriod_1Sec();                        // Set Timer0 period
    Serial2.Open(9600);                             // Open Serial port with 9600 baudrate

    /*** OPEN ADC  ***/

    PinAnalogIn(AN2);                               // Set AN2 as analog input pin
    ADC.SetChannel(CHANNEL_AN2);                    // Select ADC Channel 2
    ADC.Open();                                     // Open ADC with its default settings

    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        /*** TOGGLE TX1 AND SEND DATA ON SERIAL PORT ***/
        if(Timer0_Flag)                             // Has Timer0 period expired,
        {
            Timer0_Flag = 0;                        // CLEAR TIMERFLAG
            ADCvalue = ADC.ReadData();              // Read ADC Data
            MSB = ADCvalue>>8;
            LSB = ADCvalue;
            Serial2.SendByte(MSB);                  // Send ADC MSB value
            Serial2.SendByte(LSB);                  // Send ADC LSB value
        }
    }
}
/*----------------------------------------------------------------------------*/