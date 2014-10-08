/*****************************************************************************
Copyright (C) 2011-12 Brigosha Technologies Private Limited
Disclaimer		:
 Common:
 Brigosha Technologies products are developed for the consumer goods industry. They may only be used
 within the parameters of the respective valid product data sheet.  Brigosha Technologies products are
 provided with the express understanding that there is no warranty of fitness for a particular purpose.
 They are not fit for use in life-sustaining, safety or security sensitive systems or any system or device
 that may lead to bodily harm or property damage if the system or device malfunctions.


 Special:
 This software module (hereinafter called "Software") and any information on application-sheets
 (hereinafter called "Information") is provided free of charge for the sole purpose to support your
 application work. The Software and Information is subject to the following terms and conditions:

 The Software is specifically designed for the exclusive use for Brigosha Technologies products by
 personnel who have special experience and training. Do not use this Software if you do not have the
 proper experience or training.

 This Software package is provided `` as is `` and without any expressed or implied warranties,
 including without limitation, the implied warranties of merchantability and fitness for a particular
 purpose.

 Brigosha Technologies  deny any liability for the functional impairment of this Software in terms of
 fitness, performance and safety. Brigosha Technologies shall not be liable for any direct or indirect
 damages or injury.

 The Information provided is believed to be accurate and reliable. Brigosha Technologies assumes no
 responsibility for the consequences of use of such Information nor for any infringement of patents or
 other rights of third parties which may result from its use. No license is granted by implication or
 otherwise under any patent or patent rights of Brigosha Technologies. Specifications mentioned in the
 Information are subject to change without notice.

 It is not allowed to deliver the source code of the Software to any third party without permission of
 Brigosha Technologies.

****************************************************************************************************/
/*******************************************************************************
 DESCRIPTION:   This project demonstrates how to use APIs form the
                ELBv21_HardwareConfig file to configure the LCD.

 OUTPUT:        LCD displays a Varible on Line1 and text on Line2
********************************************************************************
*/

/***********DO NOT REMOVE **********/
#define USE_AND_OR          // Macro to use Periheral Lib

/* Default Oscillator setting is FRCDIV at 4MHZ
   Enable below Macros for Various OSCILLATOR SELECTION */
//#define OSC_PRIPLL_32MHZ
//#define OSC_FRCPLL_16MHZ
//#define OSC_SOSC_32KHZ
//#define OSC_LPRC_31KHZ
/***********DO NOT REMOVE **********/

/*** MICROCHIP LIBRARY ***/
#include <stdio.h>
#include <stdlib.h>
#include <p24FJ256GB206.h>
#include "adc.h"

/*** BRIGOSHA LIBRARY ***/
#include "Define.h"
#include "CONFIGbits.h"

#include "ELBv21_HardwareConfig.h"
#include "ELB_OSC.h"
#include "ELB_I2C.h"
#include "ELB_LCD.h"
#include "ELB_PWM.h"


/*** EXTERNAL VARIABLES  ***/
extern  ts_ELB_Hardware Hardware;                   //Hardware Global Structure

/*** GLOBAL VARIABLES ***/
U16 v_PrintData_U16=0;
U8 A_Str_U8[50];
U8 sensor_read;
unsigned int ADCValue;

int main(void)
{
    /*** LOCAL VARIABLES ***/

    /*** CONFIGURE OSCILLATOR ***/
    SET_FreqOsc( FRCDIV_8MHZ );                     //Set Frequency of Oscillator

    /*** CONFIGURE HARDWARE ****/
    Hardware_INIT();                                //Intialize Hardware
    Hardware.ConfigPins_Default();                  //Configure Hardware

    //NOTE: PPS Unlock & Lock Sequence not required when Using  Hardware.ConfigPins_Default()
     __builtin_write_OSCCONL(OSCCON & 0xbf);        //UNLCOK PPS
        Hardware.ConfigPins_PWM(USE2);              //Configure the PWM Pins to use
     __builtin_write_OSCCONL(OSCCON | 0x40);        //LOCK PPS

//      __builtin_write_OSCCONL(OSCCON & 0xbf);        //UNLCOK PPS
//    Hardware.ConfigPins_Motor(USE1|USE2);
//    __builtin_write_OSCCONL(OSCCON | 0x40);        //LOCK PPS

    MotA1 = C_ON; // Set state to OFF
    MotA2 = C_OFF; // Set state to OFF
    
    /*** INITIALIZE PERIPHERAL ***/
    CLKDIVbits.RCDIV0=0;     //clock divider to 0
    PWM2_INIT(PWMsrc_FOSC, 10);
//
    PWM2_SET_PulseWidth(5);                        //Set PWM1 Dutycycle Time 5 mSec
     //To Test, Probe the Pin1 of PWM connector J7

    LCD_INIT();                                     //Initialize LCD
//    LED1_DIR = DIR_OUT;                    // Set LED1 as Output
//    LED1 = C_OFF;                      	// Set state to OFF
//    RE5_IN;


    

    // AN0 input pin is analog

    AD1CON1 = 0x2202; // Configure sample clock source
    // and conversion trigger mode.
    // Unsigned Fraction format (FORM<1:0>=10),
    // Manual conversion trigger (SSRC<2:0>=000),
    // Manual start of sampling (ASAM=0),
    // No operation in Idle mode (ADSIDL=1),
    // S/H in Sample (SAMP = 1)
    AD1CON2 = 0; // Configure A/D voltage reference
    // and buffer fill modes.
    // Vr+ and Vr- from AVdd and AVss (VCFG<2:0>=000),
    // Inputs are not scanned,
    // Interrupt after every sample
    AD1CON3 = 0x0100; // Configure sample time = 1Tad,
    // A/D conversion clock as Tcy
    AD1CHS = 1; // Configure input channels,
    // S/H+ input is AN1,
    // S/H- input is Vr- (AVss).
    AD1CSSL = 0; // No inputs are scanned.
    IFS0bits.AD1IF = 0; // Clear A/D conversion interrupt.
    // Configure A/D interrupt priority bits (AD1IP<2:0>) here, if
    // required. Default priority level is 4.
//    IEC0bits.AD1IE = 1; // Enable A/D conversion interrupt
    AD1CON1bits.ADON = 1; // Turn on A/D
    AD1CON1bits.SAMP = 1; // Start sampling the input   

    //this just gives us a little delay between measurements
    U32 i = 0xFFFFF; //sets i to 1048575
    while (i--); //delay function

    AD1CON1bits.SAMP = 0; // End A/D sampling and start conversion
    // Example code for A/D ISR:


    
    
    
    
//    sensor_read = LATE;

    /*8** APPLICATION CODE BEGINS ***/
    v_PrintData_U16= 2013;                          // Store some Value to print


    /*** ENTER ETERNITY ***/
    while(1)
    {
//        MotA1 = C_ON; // Set state to OFF
//        MotA2 = C_OFF; // Set state to OFF

        
        /*** RECURRING CODE HERE***/
//        sprintf(A_Str_U8,"%d ", v_PrintData_U16);       // Print variable to string
//        LCD_WriteString(1, 0, A_Str_U8);                //print varible on Line1

//        sprintf(A_Str_U8,"BRIGOSHA TECH.");            // Print variable to string
//        LCD_WriteString(2, 2, A_Str_U8);               //print string on second line second column
        //Use TIMER Interrupts to perform time based tasks at fixed interval.
        //Use Peripheral Interrupts to perform event based tasks
        v_PrintData_U16++;

        AD1CON1bits.SAMP = 1; // start sampling...

        U32 i = 0xFFFF; //sets i to 1048575
        while (i--); //delay function

        AD1CON1bits.SAMP = 0; // start converting
        while (!AD1CON1bits.DONE){}; // conversion done?
        ADCValue = ADC1BUF0; // yes then get ADC value

        LCD_Clear();
        sprintf(A_Str_U8,"%u ", ADCValue);       // Print variable to string
        LCD_WriteString(2, 2, A_Str_U8);                //print varible on Line1
        //
    }

}



