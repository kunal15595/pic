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
 DESCRIPTION:   This project is to read the Data from GPS card
                Mounted on HEADER2 (TX, RX2)

 OUTPUT:        Received data from GPS is sent on  USB-Serial port (TX1, RX1).
                To view the data in real time plug the USB cable on USB-Serial
                Port(P7) and to laptop, then run the  Fasttrack software, else
                use any hyperterminal software
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
#include <p24FJ256GB206.h>
#include <pic24f_periph_features.h>
#include <ports.h>
#include <stdio.h>
#include <stdlib.h>

/*** BRIGOSHA LIBRARY ***/
#include "Define.h"
#include "CONFIGbits.h"

#include "ELBv21_HardwareConfig.h"
#include "ELB_OSC.h"
#include "ELB_Timer.h"
#include "ELB_UART.h"

/*** EXTERNAL VARIABLES ***/
extern ts_ELB_Hardware Hardware;                        //Hardware Global Structure
extern U8 V_Rx2IntFlag_U8;                              //Set in ELB_ISR.c
/*** GLOBAL VARIABLES ***/

/*____________________________________________________________________________*/
int main(void)
{
    /*** LOCAL VARIABLES ***/
    U8 v_RxData_U8=0;
    
    /*** CONFIGURE OSCILLATOR ***/    
    SET_FreqOsc( FRCDIV_1MHZ );                         //Set Frequency of 1MHZ
    
    /*** CONFIGURE HARDWARE ****/
    Hardware_INIT();                                    //Initialise Hardware functions
    Hardware.ConfigPins_Default();                      //Configure Default Hardware for ELB

    /*** INITIALIZE PERIPHERAL ***/
    UART1_INIT( M_9600Hz , M_BRGH_High , RX_INT_PRI1);  //Initialise UART1
    UART2_INIT( M_9600Hz , M_BRGH_High , RX_INT_PRI1);
    
    /*** APPLICATION CODE BEGINS ***/

    /*** ENTER ETERNITY ***/
    while(1)
    {
       // UART2 Recieve Interrupt Flag  variable (V_Rx1IntFlag_U8) is set in the Interrupt
       // Service Routine, whenever a byte is recieved in UART2 buffer from GPS
        if(V_Rx2IntFlag_U8)                             //Check if data available in UART buffer
        {
            V_Rx2IntFlag_U8 = 0;                        // Clear the Rx2 interrupt Flag
            v_RxData_U8 = U2RXREG;                      //Read the value recieved in UART buffer
            UART1_SEND_String(& v_RxData_U8,1 );        //Send the recieved bytes on USB-Serial Port
        }
    }
}
/*____________________________________________________________________________*/
