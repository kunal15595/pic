/* 
 * File:   main.c
 * Author: kunal-laptop
 *
 * Created on October 3, 2014, 11:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/drv_tmr1.h"
#include "mcc_generated_files/pin_manager.h"
#include "config.h"
/*
 * Main Application
 */
int main(int argc, char** argv) {

    // initialize pin manager
    PIN_MANAGER_Initialize();

    // initialize the device
    bool statusTimer1;
    uint16_t period;
    uint16_t value;
    uint16_t count;
    uint16_t count2;

    count = 0x00;
    count2 = 0x00;


    period = 0xfff0;

    DRV_TMR1_Initialize();

    DRV_TMR1_Period16BitSet(period);

    if((value = DRV_TMR1_Period16BitGet())== period)
    {
        DRV_TMR1_Start();
    }

    while(1)
    {
        DRV_TMR1_Tasks();
        count2++;
        if( (statusTimer1 = DRV_TMR1_GetElapsedThenClear()) == true)
        {
            IO_RE2_SetHigh();
            count++;
            IO_RE1_Toggle();
            DRV_TMR1_Initialize();
        }
    }

    


    return (EXIT_SUCCESS);
}

