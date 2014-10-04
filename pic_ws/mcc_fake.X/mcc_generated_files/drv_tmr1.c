
/**
  TMR1 Generated Driver API Header File 

  @Company
    Microchip Technology Inc.

  @File Name
    drv_tmr1.c

  @Summary
    This is the generated header file for the TMR1 driver using MPLAB® Code Configurator

  @Description
    This header file provides APIs for driver for TMR1. 
    Generation Information : 
        Product Revision  :  MPLAB® Code Configurator - v2.0.1
        Device            :  PIC24FJ128GA310
        Version           :  0.5
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.21
        MPLAB 	          :  MPLAB X 2.10
*/

/*
Copyright (c) 2013 - 2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "drv_tmr1.h"

/**
  Section: Data Type Definitions
*/

/** TMR Driver Hardware Instance Object

  @Summary
    Defines the object required for the maintainence of the hardware instance.

  @Description
    This defines the object required for the maintainence of the hardware
    instance. This object exists once per hardware instance of the peripheral.

*/

typedef struct _DRV_TMR_OBJ_STRUCT
{
    /* Timer Elapsed */
    bool                                                    timerElapsed;
    /*Software Counter value*/
    uint8_t                                                 count;

} DRV_TMR_OBJ;

static DRV_TMR_OBJ drv_tmr1_obj;

/**
  Section: Driver Interface
*/


void DRV_TMR1_Initialize (void)
{
    //TMR1 0; 
    TMR1 = 0x0000;
    //Period Value = 5.69600 ms; PR1 178; 
    PR1 = 0x2FB2;
    //TSIDL disabled; TGATE disabled; TCS FOSC/2; TSYNC disabled; TCKPS 1:64; TECS SOSC; TON enabled; 
    T1CON = 0x8020;

    drv_tmr1_obj.timerElapsed = false;

}


void DRV_TMR1_Tasks( void )
{
    /* Check if the Timer Interrupt/Status is set */
    if(IFS0bits.T1IF)
    {
        drv_tmr1_obj.count++;
        drv_tmr1_obj.timerElapsed = true;
        IFS0bits.T1IF = false;
    }
}


void DRV_TMR1_Period16BitSet( uint16_t value )
{
    /* Update the counter values */
    PR1 = value;

    /* Reset the status information */
    drv_tmr1_obj.timerElapsed = false;
}

uint16_t DRV_TMR1_Period16BitGet( void )
{
    return( PR1 );
}

void DRV_TMR1_Counter16BitSet ( uint16_t value )
{
    /* Update the counter values */
    PR1 = value;
    /* Reset the status information */
    drv_tmr1_obj.timerElapsed = false;
}

uint16_t DRV_TMR1_Counter16BitGet( void )
{
    return( TMR1 );
}

void DRV_TMR1_Start( void )
{
    /* Reset the status information */
    drv_tmr1_obj.timerElapsed = false;


    /* Start the Timer */
    T1CONbits.TON = 1;
}

void DRV_TMR1_Stop( void )
{
    /* Stop the Timer */
    T1CONbits.TON = false;


}

bool DRV_TMR1_GetElapsedThenClear(void)
{
    bool status;
    
    status = drv_tmr1_obj.timerElapsed;

    if(status == true)
    {
        drv_tmr1_obj.timerElapsed = false;
    }
    return status;
}

uint8_t DRV_TMR1_SoftwareCounterGet(void)
{
    return drv_tmr1_obj.count;
}

void DRV_TMR1_SoftwareCounterClear(void)
{
    drv_tmr1_obj.count = 0; 
}

/**
 End of File
*/
