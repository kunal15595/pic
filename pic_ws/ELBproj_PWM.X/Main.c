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
#include <incap.h>
#include <outcompare.h>

/*** BRIGOSHA LIBRARY ***/
#include "Define.h"
#include "CONFIGbits.h"

#include "ELBv21_HardwareConfig.h"
#include "ELB_OSC.h"
#include "ELB_PWM.h"
#include "ELB_Timer.h"
#include "ELB_LCD.h"

/*** EXTERNAL VARIABLES ***/
extern ts_ELB_Hardware Hardware;               //Hardware Global Structure

/*** GLOBAL VARIABLES ***/
U8 A_Str_U8[50];
unsigned int Capture1, Capture2;
int Interrupt_Count = 0 , Int_flag, count, temp_edge_index;
unsigned int timer_first_edge, timer_second_edge,timer_third_edge,
        first_edge, second_edge , third_edge, temp_edge, edge_buffer[122], pulse;

int count = 0;
int read_enable = 0;
int main(void)
{
    /*** LOCAL VARIABLES ***/
    unsigned int period , period2, config1=0 ,config2=0;
    Int_flag = 0;
    /*** CONFIGURE OSCILLATOR ***/
    SET_FreqOsc( FRCDIV_1MHZ );                    //Set Frequency
    
    /*** CONFIGURE HARDWARE ****/
    Hardware_INIT();                               //Initialise Hardware functions
    LCD_INIT();
    //NOTE: PPS Unlock & Lock Sequence not required when Using  Hardware.ConfigPins_Default()
     __builtin_write_OSCCONL(OSCCON & 0xbf);        //UNLCOK PPS
//        Hardware.ConfigPins_PWM(USE1 | USE2 | USE4 | USE3 );              //Configure the PWM Pins to use
        PWM4_DIR = DIR_OUT; // Set PWM4 as Output
        PWM4 = C_OFF;
        iPPSInput(IN_FN_PPS_IC1, IN_PIN_PPS_RP10);
        iPPSOutput(OUT_PIN_PPS_RP12, OUT_FN_PPS_OC1);
        iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_OC9);
     __builtin_write_OSCCONL(OSCCON | 0x40);        //LOCK PPS
    Int_flag = 0;
    
    // timers
    T1CON = 0x8000;
    T2CON = 0x8000;
    T1CONbits.TCKPS = 0b00;
    T2CONbits.TCKPS = 0b01;
    T3CON = 0x8000;
    T4CON = 0x8000;
    T4CONbits.TCKPS = 0b01;

    // input capture
    ConfigIntCapture1(IC_INT_ON | IC_INT_PRIOR_4);
    config1 = IC_IDLE_STOP | IC_TIMER2_SRC | IC_INT_1CAPTURE | IC_EVERY_EDGE;
    config2 = IC_CASCADE_DISABLE /*| IC_SYNC_ENABLE | IC_SYNC_TRIG_IN_TMR2*/;
    OpenCapture1_GB(config1, config2);

    // output compare
    EnableIntOC9;
    OC9R = 0x5FF0;
    OC9RS = 0x5FF4;
    OC9CON1bits.OCTSEL = 0b000;
    OC9CON2bits.SYNCSEL = 0x1F;
    OC9CON1bits.OCM = 0b110;
    OC9CON2bits.OCINV =  1;
//    PR1 = 2000;// period for timer 1
//    PR2 = 0xFFFF;

//    IFS0bits.IC1IF = 0; // Clear the IC1 interrupt status flag
//    IEC0bits.IC1IE = 1; // Enable IC1 interrupts
//    IPC0bits.IC1IP = 1; // Set module interrupt priority as 1
    //    IC1CON1 = 0x1C24;
    //    IC1CON2 = 0x0040;
//    IC1CON1bits.ICSIDL = 0; //Continue in idle mode
//    IC1CON1bits.ICI = 0b00; //Interrupt on every capture
//    IC1CON1bits.ICM = 0b001; //Every edge

//    EnableIntIC1;

     /*** INITIALIZE PERIPHERAL ***/
//     TIMER3_INIT( 1000, TMR_INT_PRI7 );
     PWM1_INIT(PWMsrc_FOSC, 20);                    //Set PWM Period of 20 mSec
//     PWM3_INIT(PWMsrc_Timer1, 100);                    //Set PWM Period of 1000 mSec
//     PWM3_INIT(PWMsrc_FOSC, 30);
     /*** APPLICATION CODE BEGINS ***/
//     PWM3_SET_PulseWidth(1);
     PWM1_SET_PulseWidth(1.3);

//     PWM3_SET_PulseWidth(10);

                            //Set PWM1 Dutycycle Time 5 mSec
     //To Test, Probe the Pin1 of PWM connector J7

    LED1_DIR = DIR_OUT; // Set LED1 as Output
    LED1 = C_OFF;
    LED2_DIR = DIR_OUT; // Set LED1 as Output
    LED2 = C_OFF;
    LED3_DIR = DIR_OUT; // Set LED1 as Output
    LED3 = C_OFF;
    /*** ENTER ETERNITY ***/
     int buf[100];
     Int_flag = 2;
    

         //LOCK PPS
    while (1) {
//        while (!read_enable);

         //wait till two succssive falling edges
//        M_ToggleIO(LED1);
//        period = timer_second_edge - timer_first_edge;
//        period2 = 65535 + timer_first_edge - timer_second_edge;


            
            int j;
            for(j=1;j<5;j++){
                if(edge_buffer[j+1] - edge_buffer[j] > 30){
                    if(edge_buffer[j+1] - edge_buffer[j] < 500){
                        pulse = edge_buffer[j+1] - edge_buffer[j];
                        break;
                    }else{
                        pulse = 11111;
                    }
                }else{
                    pulse = 11111;
                }
            }
            
            if(pulse != 11111){
                LCD_Clear();
                sprintf(A_Str_U8, "%u", pulse); // Print variable to string
                LCD_WriteString(1, 1, A_Str_U8);
            }

//            sprintf(A_Str_U8, "%u", timer_second_edge); // Print variable to string
//            LCD_WriteString(1, 8, A_Str_U8);
//            sprintf(A_Str_U8, "%u", abs(timer_second_edge - timer_first_edge)); // Print variable to string
//            LCD_WriteString(2, 1, A_Str_U8);
//            sprintf(A_Str_U8, "%u", abs(timer_third_edge - timer_second_edge)); // Print variable to string
//            LCD_WriteString(2, 7, A_Str_U8);
//            DELAY_mSec(100);
//            sprintf(A_Str_U8, "%d", Interrupt_Count); // Print variable to string
//            LCD_WriteString(2, 8, A_Str_U8);

//        Int_flag = 0;
            read_enable = 0;
        
//        __builtin_write_OSCCONL(OSCCON & 0xbf);
//        iPPSOutput(OUT_PIN_PPS_RP10, OUT_FN_PPS_OC4);
//        __builtin_write_OSCCONL(OSCCON | 0x40);
//
//        PWM4 = C_OFF;
//        PWM4 = C_ON;
//        PWM4 = C_OFF;
//        DELAY_mSec(200);
        
//        DELAY_mSec(200);
//        LATEbits.LATE5 = 1;
//        DELAY_mSec(500);
//        LATEbits.LATE5 = 0;

//        ReadCapture1_v4(buf) ;
        /*** RECURRING CODE HERE***/
        //Use TIMER Interrupts to perform time based tasks at fixed interval.
        //Use Peripheral Interrupts to perform event based tasks
        int i;
        for (i = 40; i < 100; i++) {
            PWM1_SET_PulseWidth(0.02 * i);
            DELAY_mSec(20);

        }
        while (i>=40) {
            PWM1_SET_PulseWidth(0.02 * i);
            DELAY_mSec(20);
            i--;
        }
    }
      
}

//void __attribute__ ((interrupt,no_auto_psv)) _IC1Interrupt(void)
//{
//    count++;
//    M_ToggleIO(LED3);
//    if(PORTBbits.RB1 == 1)
//   {
//        M_ToggleIO(LED1);
//      Capture1 = IC1BUF;
//   }
//   else if(PORTBbits.RB1 == 0)
//   {
//       M_ToggleIO(LED2);
//      Capture1 = IC1BUF;
//   }
//   IFS0bits.IC1IF = 0; //Clear flag
////    Capture1 = IC1BUF; // Read and save off first capture entry
////    Capture2 = IC1BUF; // Read and save off second capture entry
//}


//void _ISR _IC1Interrupt(void)
//{
//    LED3= C_ON;
//if(PORTBbits.RB10 == 1)
//{
//    M_ToggleIO(LED2);
////    DELAY_mSec(100);
//    //Restart_Timer2();
////trash = IC1BUF;
//}
//else if(PORTBbits.RB10 == 0)
//{
////yaw_input = IC1BUF;
////TARGET_ZRATE = ZRATE_RANGE*(yaw_input - YAW_MID)/(YAW_MAX - YAW_MIN);
////if(TARGET_ZRATE < 1.0 && TARGET_ZRATE > -1.0) {TARGET_ZRATE = 0;}
//}
////Reset_Timer4();
//IFS0bits.IC1IF = 0; //Clear IC1 interrupt flag
//}

//void __attribute__ ((interrupt,no_auto_psv)) _T2Interrupt(void)
//{
//        IFS0bits.T1IF = 0;
//}

void __attribute__((interrupt,no_auto_psv)) _IC1Interrupt(void)
{
    M_ToggleIO(LED2);
    ReadCapture1(&temp_edge);
    if(temp_edge > 0x6000 && temp_edge < 0x7000){
        edge_buffer[++temp_edge_index]= temp_edge;
        if(temp_edge_index > 120)temp_edge_index=50;
    }else{
        temp_edge_index = 0;
    }
    IC1_Clear_Intr_Status_Bit;
//    if(read_enable){
//        M_ToggleIO(LED3);
//        Interrupt_Count++;					//Number Input Capture counts
//        if(Int_flag == 0){
//            ReadCapture1(&timer_first_edge);	//Read the Time count for first capture of signal
//            Int_flag = 1;
//        }else if(Int_flag == 1){
//            ReadCapture1(&timer_second_edge);	//read the time count for second capture sgnal
//            Int_flag = 2;						//On two captured signals set the flag
//        }
        read_enable = 1;
//    }
			//Interrupt status clear
}

void __attribute__((interrupt,no_auto_psv)) _OC9Interrupt(void){
//
//    read_enable = 1;
    OC9_Clear_Intr_Status_Bit;
}

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void) {
    IFS0bits.T1IF = 0;

}
