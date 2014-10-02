/*******************************************************************************
[File]          : main.c
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Pins.h,EAB_Oscillator.h,EAB_Timer.h,EAB_Serial.h,EAB_ADC.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : This project works for measuring distance of an obstacle w.r.t some specified area
                  
*******************************************************************************/

#define SYS_CLK 8000000        // Required for delay macro functions
                               // Default 1MHZ, else change as per configuration
/*** INCLUDE STANDARD HEADERS & LIBRARY ***/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "EAB_Library.h"

void PWM1_Config(uchar, uchar);     // Set PWM1 Period of 20ms
void PWM1_SET_PulseWidth(ushort);   // Set PWM1 Pulsewidth of 2ms
void PWM1_Enable(void);             // Enable PWM1
void PWM1_Position(signed char);

signed char Angle;                         // Variable for angle measurement
float PWM1PeriodMS;
float PWM1PulseWidthMS;
float PWM1DutyCycle;
/*----------------------------------------------------------------------------*/

void main(void)
{
    /*** LOCAL VARIABLES ***/

    /*** INTITALIZE OSCILLATOR, PERIPHERAL & HARDWARE ***/
    Oscillator.SetFreq_500KHZ();    // Select system clock at 500 KHz
    Serial2.Open(9600);             // Open Serial port with 9600 baudrate

    PWM1_Config(2,156);             // Set PWM1 Period of 20ms
    PWM1_SET_PulseWidth(46);        // Set PWM1 Pulsewidth of 2ms
    PWM1_Enable();                  // Enable PWM1
    
    /*** PLACE THE REPETITIVE TASKS IN THIS LOOP ***/
    while(1)
    {
        if(Serial2_RxFlag)              // Check if UART2 Buffer is high
        {
            Serial2_RxFlag=0;           // Clear the receiver flag
            Angle= Serial2.ReadByte();  // Put the receive value to variable
            PWM1_Position(Angle);       // Call function
        }
    }
}
/*----------------------------------------------------------------------------*/
/*** Function for converting angle value to pulsewidth of PWM Signals ***/
void PWM1_Position(signed char Angle1 )
{
    float x, x0, y, y0, c;
    uint K;
    float  tosc = 1.0/500000;
    y=Angle1;
    x0=0.0015;
    y0=0;
    c=-0.00001; //slope = (x1-x0)/(y1-y0)
    if(y>60)// condition for input angle
    {
      y=60;
    }
    if(y<-60)
    {
      y=-60;
    }
    // Calculate Duty cycle in millisecond from angle
    x=x0+(y-y0)*c;
     //Calculate the Value of Duty cycle register from Time
    K= x/( tosc* 16);
    PWM1_SET_PulseWidth(K);
}
/*----------------------------------------------------------------------------*/

void PWM1_Config(uchar v_PreScaler_u8,uchar v_PeriodNumber_u8)
{
    signed long v_FreqOsc_s32;
    uchar a_Prescaler_u8[]={1,4,16};
    v_FreqOsc_s32 = 500000;             //FreqOsc

    PinDigitalIn(PWM1);                 // Disable the PWM1 pin output driver
    CCPTMRS0bits.C1TSEL = 0x01;         // Select Timer 4 for PWM use
    CCP1CONbits.CCP1M = 0b1100;         // CCP1 configured in PWM mode

    T4CONbits.T4CKPS = v_PreScaler_u8;
    PR4 = v_PeriodNumber_u8;
    T4CONbits.TMR4ON = 1;               //Enable Timer 1

    PWM1PeriodMS = (4*1000.0*a_Prescaler_u8[v_PreScaler_u8]*v_PeriodNumber_u8/((float)v_FreqOsc_s32));
}
/*----------------------------------------------------------------------------*/

void PWM1_SET_PulseWidth(ushort v_WidthNumber_u16)
{
    float v_FreqOsc_s32;
    ushort v_WidthThreshold_u16 = PR4;
    uchar a_Prescaler_u8[]={1,4,16};
    uchar v_PreScaler_u8 = T4CONbits.T4CKPS;
    v_FreqOsc_s32 = 500000;

    v_WidthThreshold_u16 = 4*v_WidthThreshold_u16 + 1;

    if(v_WidthNumber_u16>v_WidthThreshold_u16)     //Duty cycle cant be more than 100%
        v_WidthNumber_u16 = v_WidthThreshold_u16;  //Setting 100% duty cycle

    CCP1CONbits.DC1B = (uchar)(v_WidthNumber_u16 & 0x0003); //LSB for pulse width1

    CCPR1L = (uchar)((v_WidthNumber_u16 & 0x03FC)>>2);      //MSB for the pulse width

    PWM1PulseWidthMS = (1000.0*v_WidthNumber_u16*a_Prescaler_u8[v_PreScaler_u8])/((float)v_FreqOsc_s32);
    PWM1DutyCycle = (PWM1PulseWidthMS * 100)/PWM1PeriodMS;
}
/*----------------------------------------------------------------------------*/

void PWM1_Enable(void)
{
    PIR5bits.TMR4IF=0;
    while(!PIR5bits.TMR4IF);
    PIR5bits.TMR4IF=0;
    PinDigitalOut(PWM1);                    // Set PWM1 pin direction as output
}
/*----------------------------------------------------------------------------*/


