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
 DESCRIPTION:   This project demonstrates how to use APIs form the
                ELB_Timer file to configure the timer1.

OUTPUT:         Toggle LEDs at 1 second second interval
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


/*** BRIGOSHA LIBRARY ***/
#include "Define.h"
#include "CONFIGbits.h"

#include "ELBv21_HardwareConfig.h"
#include "ELB_OSC.h"
#include "ELB_Timer.h"

/*** EXTERNAL VARIABLES ***/
extern ts_ELB_Hardware Hardware;                //Hardware Global Structure
extern V_T1IntFlag_U8;                          //Interrupt Flag for Timer1
                                                //set in ELB_ISR.c
/*** GLOBAL VARIABLES ***/

/*____________________________________________________________________________*/
int main(void)
{
    /*** LOCAL VARIABLES ***/

    /*** CONFIGURE OSCILLATOR ***/
    SET_FreqOsc( FRCDIV_250KHZ );               //Set frequency using macros from ELB Lib
    
    /*** CONFIGURE HARDWARE ****/
     Hardware_INIT();                            //Initialise Hardware functions
     Hardware.ConfigPins_Default();              //Configure Default Hardware for ELB

     /*** INITIALIZE PERIPHERAL ***/
     TIMER1_INIT( 1000, TMR_INT_PRI1 );          //Set Timer1, check the calculator in prog guide
                                                 //for available TimerTicks at Set Frequency
     /*** APPLICATION CODE BEGINS ***/
     
     /*** ENTER ETERNITY ***/
     while(1)
     {
       // Timer1 Interrupt Flag  variable (V_T1IntFlag_U8) is set in the Interrupt
       // Service Routine, when the specified TIMER period has elapsed 
        if(V_T1IntFlag_U8)                          
        {
            V_T1IntFlag_U8=0;                       //Clear Timer1 Interrupt Flag
            M_ToggleIO(LED1);                       //Toggle led1
            M_ToggleIO(LED2);                       //Toggle led2
            M_ToggleIO(LED3);                       //Toggle led3
        }
     }
}
/*____________________________________________________________________________*/
