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
#include <p24FJ256GB210.h>
#include <pic24f_periph_features.h>
#include <ports.h>
#include <PPS.h>
#include <math.h>

/*** BRIGOSHA LIBRARY ***/
#include "Define.h"
//#include "CONFIGbits.h"

#include "ELBv21_HardwareConfig.h"
#include "ELB_OSC.h"
#include "ELB_Timer.h"
#include "ELB_UART.h"
#include "ELB_I2C.h"
#include "AMGPsensor.h"

#include "imu.h"

/*** EXTERNAL VARIABLES ***/
extern ts_ELB_Hardware Hardware;                        //Hardware Global Structure
extern ts_AMGPsensor AMGP;                              //Sensor Global Structure
extern U8 V_T23IntFlag_U8;                              //Set in TIMER ISR in file ELB_ISR.c

/*** GLOBAL VARIABLES ***/
F32 V_Pitch_F32 = 0;

/*____________________________________________________________________________*/
int imu_main (void)
{
    /*** LOCAL VARIABLES ***/    

    /*** CONFIGURE OSCILLATOR ***/
//    SET_FreqOsc( FRCDIV_1MHZ );                         //Set frequency of 1 MHZ
    
    /*** CONFIGURE HARDWARE ****/
//    Hardware_INIT();                                    //Initialise Hardware functions
//    Hardware.ConfigPins_Default();                      //Configure Default Hardware for ELB

    /*** INITIALIZE PERIPHERAL ***/
    TIMER23_INIT(100, TMR_INT_PRI1);                    //Proivde timer period in millisecond
    UART1_INIT( M_9600Hz , M_BRGH_High , TX_INT_PRI0);  //Initialise UART1
    I2C1_INIT(400000, MI2C_INT_PRI0 );                  //Inilialize I2C1

    /*** APPLICATION CODE BEGINS ***/ 
    AMGP_INIT(READ_HEADER1,SEND_UART1USB);              //Select Header to mount sensor card and...
                                                        //...UART port to send data out (To be implemented, Modify this in AMGPSensor.h)
    AMGP.Config(Acc|Mag|Gyro|Pres);                        //Select the sensors to work with eg.(Acc|Mag|Pres)
    /*** ENTER ETERNITY ***/
    while(1)
    {
        /*** READ SENSOR DATA AFTER TIMER PERIOD ELAPSED ***/
        if(V_T23IntFlag_U8)                             // Timer period defined in the Timer init function...
        {                                               // ...the timer interrupt flag is set in ELB_ISR.c
            V_T23IntFlag_U8 = 0;                        // Clear the TIMER Interrupt flag variable
            AMGP.Read(Acc|Mag|Gyro|Pres|TempPres);      // Read selected Sensors Data
            AMGP.Send(Acc|Mag|Gyro|Pres|TempPres);      // Send sensors data Packet through selected UART

            V_Pitch_F32 = atan(AMGP.Data.AccY/AMGP.Data.AccZ); // Use sensors Data perfrom calcualtions
        }
    }
}
/*____________________________________________________________________________*/

TAVIX_THREAD_REGULAR imu_thread(void* p){
    while(1);
}

