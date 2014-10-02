/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project demonstrates the usage of functions related I2C communication
                 -> CONFIGURE I2C COMMUNICATION
                    The I2C communication needs to configured for the Clock Frequency.
                    This need to be provided as input to the I2C open function. There are
                    two standard Frequencies of 100KHZ(I2CFRE_STANDARD) and 400KHZ(I2CFREQ_FAST).
                    The other default settings for communication are Master mode, 7 bit address, 8 bit data
                    Example:
                     - I2C1.Open(I2CFREQ_STANDARD);
                     - I2C1.Open(300000);
                 -> READ DATA FROM I2C slave device
                    To read data from an I2C slave we need the Device Address, the Register address from
                    where to read, a pointer to variable/Array to store the data and number to bytes to be read.
                    Example
                    - uchar DevAdd = 0x38, RegAdd = 0, ReadData, NoOfBytes = 1;
                      I2C1.ReadArray(DevAdd, RegAdd, &ReadData, NoOfBytes);
                -> WRITE DATA TO I2C slave device
                    To write data to an I2C slave we need the Device Address, the Register address to
                    where write, a pointer to variable/Array where data to be written is stored  and
 *                  number to bytes to be write.
                    Example
                    - uchar DevAdd = 0x38, RegAdd = 0, WriteData = 0x0F, NoOfBytes = 1;
                      I2C1.WriteArray(DevAdd, RegAdd, &WriteData, NoOfBytes);

*******************************************************************************/

#define SYS_CLK 8000000                           //Required for delay macro functions
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
    uchar AccelID=0;
    uchar TxData=5;

    /*** INTITALIZE OSCILLATOR, TIMER & I/Os ***/
    Oscillator.SetFreq_8MHZ();                      // Select system clock at 8 MHz
    Timer0.SetPeriod_1Sec();                        // Select timer0 for 1 sec time
    Serial2.Open(9600);                             // Set baud rate at 9600

    /*** OPEN I2C ***/
    I2C1.Open(I2CFREQ_FAST);                        // Open I2C1 with default settings

    I2C1.ReadArray(0x38, 0x00, &AccelID,1);         // Read Accelerometer sensor data
    I2C1.WriteArray(0x38,0x0F,&TxData,1);           // Write on Accelerometer register
    I2C1.ReadArray(0x38,0x0F,&TxData,1);            // Read the written data

     /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        if(Timer0_Flag)                             // Check for timer 0 flaf
        {
            Timer0_Flag=0;                          // Clear the flag
            Serial2.SendArray(&AccelID,1);          // Transmit 1 Byte from array to Hetrm
            Serial2.SendArray(&TxData,1);           // Transmit 1 Byte from the array to Hterm
        }
    }
}
/*----------------------------------------------------------------------------*/
