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
                files to configure the Oscillator frequency.

 OUTPUT:         The Frequency of oscillator is set
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


/*** Brigosha Library ***/
#include "Define.h"
#include "CONFIGbits.h"

#include "ELBv21_HardwareConfig.h"
#include "ELB_OSC.h"

/*** EXTERNAL VARIABLES ***/

/*** GLOBAL VARIABLES ***/

/*____________________________________________________________________________*/
int main(void)
{
    /*** LOCAL VARIABLES ***/
    S32 v_FreqOsc_S32 = 0;                      //To store the Freq

    /*** CONFIGURE OSCILLATOR ***/
    SET_FreqOsc( FRCDIV_8MHZ);                  //Set Frequency of Oscillator
    v_FreqOsc_S32 = GET_FreqOsc();              //Get the frequency which is set
    //To test, Probe OSCO  pin at the Leg of Y1 for Freq/2

    /*** CONFIGURE HARDWARE ****/

    /*** INITIALIZE PERIPHERAL ***/

    /*** APPLICATION CODE BEGINS ***/
    
    /*** ENTER ETERNITY ***/
    while(1)
    {
        /*** RECURRING CODE HERE***/
        //Use TIMER Interrupts to perform time based tasks at fixed interval.
        //Use Peripheral Interrupts to perform event based tasks

    }
}
/*____________________________________________________________________________*/
