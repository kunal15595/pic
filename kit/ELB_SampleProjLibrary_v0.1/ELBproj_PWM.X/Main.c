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
/*****************************************************************************
 DESCRIPTION:   This project demonstrates how to use APIs form the ELB_ConfigOsc
                files to configure the PWM.

 OUTPUT:       The PWM2 channel is configured as PWM Signal output
******************************************************************************/

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
#include <pic24f_periph_features.h>
#include <ports.h>
#include <PPS.h>


/*** BRIGOSHA LIBRARY ***/
#include "Define.h"
#include "CONFIGbits.h"

#include "ELBv21_HardwareConfig.h"
#include "ELB_OSC.h"
#include "ELB_PWM.h"

/*** EXTERNAL VARIABLES ***/
extern ts_ELB_Hardware Hardware;               //Hardware Global Structure

/*** GLOBAL VARIABLES ***/

int main(void)
{
    /*** LOCAL VARIABLES ***/

    /*** CONFIGURE OSCILLATOR ***/
    SET_FreqOsc( FRCDIV_4MHZ );                    //Set Frequency
    
    /*** CONFIGURE HARDWARE ****/
    Hardware_INIT();                               //Initialise Hardware functions
    
    //NOTE: PPS Unlock & Lock Sequence not required when Using  Hardware.ConfigPins_Default()
     __builtin_write_OSCCONL(OSCCON & 0xbf);        //UNLCOK PPS
        Hardware.ConfigPins_PWM(USE2);              //Configure the PWM Pins to use
     __builtin_write_OSCCONL(OSCCON | 0x40);        //LOCK PPS
     
     /*** INITIALIZE PERIPHERAL ***/
     PWM2_INIT(PWMsrc_FOSC, 20);                    //Set PWM Period of 20 mSec

     /*** APPLICATION CODE BEGINS ***/
     PWM2_SET_PulseWidth(5);                        //Set PWM1 Dutycycle Time 5 mSec
     //To Test, Probe the Pin1 of PWM connector J7

    /*** ENTER ETERNITY ***/
    while(1)
    {
        /*** RECURRING CODE HERE***/
        //Use TIMER Interrupts to perform time based tasks at fixed interval.
        //Use Peripheral Interrupts to perform event based tasks
    }
      
}

