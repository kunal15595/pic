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
                ELB_I2C file to configure the I2C Communciation.

 INPUT:         Mount Brigosha Sensor Card on ELB. Flash the Code

 OUTPUT:        Acceleromter Sensor ID and 3 bytes Acceleromter Sensor Data
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
#include "ELB_Timer.h"
#include "ELB_UART.h"
#include "ELB_I2C.h"

/*** EXTERNAL VARIABLES ***/
extern ts_ELB_Hardware Hardware;                        //Hardware Global Structure

/*** GLOBAL VARIABLES ***/

/*____________________________________________________________________________*/
int main (void)
{
    /*** LOCAL VARIABLES ***/    
    U8 v_AccelID_U8=0;                                  //To store Accelerometer Sensor ID
    U8 a_Accel_U8[6];                                   //To store Accelerometer Data

    /*** CONFIGURE OSCILLATOR ***/
    SET_FreqOsc( FRCDIV_1MHZ );                         //Set frequency of 1 MHZ
    
    /*** CONFIGURE HARDWARE ****/
    Hardware_INIT();                                    //Initialise Hardware functions
    Hardware.ConfigPins_Default();                      //Configure Default Hardware for ELB

    /*** INITIALIZE PERIPHERAL ***/
    UART1_INIT( M_9600Hz , M_BRGH_High , TX_INT_PRI0);  //Initialise UART1
    I2C1_INIT(400000, MI2C_INT_PRI0 );                  //Inilialize I2C1

    /*** APPLICATION CODE BEGINS ***/
    I2C1_READ_Byte(0x38, 0x00, &v_AccelID_U8);          //Read Accelemoter ID
    if(v_AccelID_U8 == 2)                               //Check Accelemoter ID
    {        
        UART1_SEND_String(&v_AccelID_U8,1);             //Check Accelemoter ID
    }

    I2C1_READ_String(0x38, 0x02,a_Accel_U8,6 );         //Read 6 Byte Acceleromter Data
    UART1_SEND_String(a_Accel_U8,6);                    //Transmit 6 Byte Data to Hterm

    /*** ENTER ETERNITY ***/
    while(1)
    {
        /*** RECURRING CODE HERE***/
        //Use TIMER Interrupts to perform time based tasks at fixed interval.
        //Use Peripheral Interrupts to perform event based tasks

    }
}
/*____________________________________________________________________________*/



