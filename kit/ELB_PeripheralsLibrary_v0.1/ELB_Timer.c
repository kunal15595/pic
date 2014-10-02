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
/*
********************************************************************************
[File]          : ELB_Timer.C
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : ELB Timer configuration Functions
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR]                            CHANGES
 v0.1	   	17.10.2012 	shashi.prakash@brigosha.com         Origin
********************************************************************************
*/

/*** Include header files ***/
#include "ELB_TIMER.h"

/*
--------------------------------------------------------------------------------
[NAME]  	: TIMER1_INIT
[TYPE]		: Public API
[INPUT] 	: Timer Tick in millisecond and Interrupt confiuration from macros
[RETURN]	: None
[DESCRIPTION]   : This function initializes the Timer1 with desired value for 
                  Clock Tick and enables the interrupts
--------------------------------------------------------------------------------
*/
void TIMER1_INIT( F32 v_TickInMsec_F32, U8 v_IntConfig_U8)
{
       // Local Variables
	U16 v_TimerCompare_U16 = 0;
        U32 v_TimerOverFlow_U32 = 0;
        S32 v_Fosc_S32 = 4E6;

        // Get the current Oscillator frequency
        v_Fosc_S32 = GET_FreqOsc();
        // Calculate period register for desired timer tick
	v_TimerOverFlow_U32 = v_TickInMsec_F32*v_Fosc_S32/1E3;
        // Check if the value has exceded, then set the max possible
        if(v_TimerOverFlow_U32>=65535)
        {
          v_TimerCompare_U16 =  65535;
        }
        else
        {
            v_TimerCompare_U16 = v_TimerOverFlow_U32;
        }

        // Enable Interrupts
        if(v_IntConfig_U8)
        {
            v_IntConfig_U8 &= ~TMR_INT_PRI0;
            IPC0bits.T1IP = v_IntConfig_U8; //Setup Timer1 interrupt for desired priority level
            IFS0bits.T1IF = 0;              //Clear Timer1 interrupt status flag
            IEC0bits.T1IE = 1;              //Enable Timer1 interrupts
        }
        
        // Clear the registers
        T1CON= 0;
	TMR1 = 0;

        // Load the period compare register ,
	PR1 = v_TimerCompare_U16;
        // Start Timer1 with prescaler 1:1 and clock source as instruction cycle
        T1CONbits.TCKPS = 0;
        T1CONbits.TCS = 0;
        T1CONbits.TON = 1;      
                                           
}

/*
--------------------------------------------------------------------------------
[NAME]  	: TIMER2_INIT
[TYPE]		: Public API
[INPUT] 	: Timer Tick in millisecond and Interrupt confiuration from macros
[RETURN]	: None
[DESCRIPTION]   : This function initializes the Timer2 with desired value for 
                  Clock Tick and enables the interrupts
--------------------------------------------------------------------------------
*/
void TIMER2_INIT( F32 v_TickInMsec_F32, U8 v_IntConfig_U8)
{
        // Local Variables
	U16 v_TimerCompare_U16 = 0;
        U32 v_TimerOverFlow_U32 = 0;
        S32 v_Fosc_S32 = 4E6;

        // Get the current Oscillator frequency
        v_Fosc_S32 = GET_FreqOsc();
        // Calculate period register for desired timer tick
	v_TimerOverFlow_U32 = v_TickInMsec_F32*v_Fosc_S32/1E3;
        // Check if the value has exceded
        if(v_TimerOverFlow_U32>=65535)
        {
          v_TimerCompare_U16 =  65535;
        }
        else
        {
            v_TimerCompare_U16 = v_TimerOverFlow_U32;
        }

        // Enable Interrupts
        if(v_IntConfig_U8)
        {
            v_IntConfig_U8 &= ~TMR_INT_PRI0;
            IPC1bits.T2IP = v_IntConfig_U8; //Setup Timer2 interrupt for desired priority level
            IFS0bits.T2IF = 0;              //Clear Timer2 interrupt status flag
            IEC0bits.T2IE = 1;              //Enable Timer2 interrupts
        }

       // Clear the registers
        T2CON= 0;                           
	TMR2 = 0;                           
        
        // Load the period compare register ,
	PR2 = v_TimerCompare_U16;           
        // Start Timer2 with prescaler 1:1 and clock source as instruction cycle
        T2CONbits.TCKPS = 0;
        T2CONbits.TCS = 0;
	T2CONbits.TON = 1;                  
                                            
}

/*
--------------------------------------------------------------------------------
[NAME]  	: TIMER3_INIT
[TYPE]		: Public API
[INPUT] 	: Timer Tick in millisecond and Interrupt confiuration from macros
[RETURN]	: None
[DESCRIPTION]   : This function initializes the Timer3 with desired value for 
                  Clock Tick and enables the interrupts
--------------------------------------------------------------------------------
*/
void TIMER3_INIT( F32 v_TickInMsec_F32, U8 v_IntConfig_U8)
{
        // Local Variables
	U16 v_TimerCompare_U16 = 0;
        U32 v_TimerOverFlow_U32 = 0;
        S32 v_Fosc_S32 = 4E6;

        // Get the current Oscillator frequency
        v_Fosc_S32 = GET_FreqOsc();
        // Calculate period register for desired timer tick
	v_TimerOverFlow_U32 = v_TickInMsec_F32*v_Fosc_S32/1E3;
        // Check if the value has exceded
        if(v_TimerOverFlow_U32>=65535)
        {
          v_TimerCompare_U16 =  65535;
        }
        else
        {
            v_TimerCompare_U16 = v_TimerOverFlow_U32;
        }

        // Enable Interrupts
        if(v_IntConfig_U8)
        {
            v_IntConfig_U8 &= ~TMR_INT_PRI0;
            IPC2bits.T3IP = v_IntConfig_U8; //Setup Timer3 interrupt for desired priority level
            IFS0bits.T3IF = 0;              //Clear Timer3 interrupt status flag
            IEC0bits.T3IE = 1;              //Enable Timer3 interrupts
        }

        // Clear the registers
        T3CON=0x0000;                       
	TMR3 = 0x00;

        // Load the period compare register ,
	PR3 = v_TimerCompare_U16;           
        // Start Timer3 with prescaler 1:1 and clock source as instruction cycle
        T3CONbits.TCKPS = 0;
        T3CONbits.TCS = 0;
	T3CONbits.TON = 1;                                             

}


/*
--------------------------------------------------------------------------------
[NAME]  	: TIMER23_INIT
[TYPE]		: Public API
[INPUT] 	: Timer Tick in millisecond and Interrupt confiuration from macros
[RETURN]	: None
[DESCRIPTION]   : This function initializes the 32 bit Timer23, concatenating 
                  Timer2 and Timer3 with desired value for Clock Tick and
                  enables the interrupts
--------------------------------------------------------------------------------
*/
void TIMER23_INIT( F32 v_TickInMsec_F32, U8 v_IntConfig_U8)
{
        // Local Variables
	U32 v_TimerCompare_U32 = 0;
        S32 v_Fosc_S32 = 4E6;

        // Get the current Oscillator frequency
        v_Fosc_S32 = GET_FreqOsc();
        // Calculate period register for desired timer tick
	v_TimerCompare_U32 = v_TickInMsec_F32*v_Fosc_S32/1E3;

        // Clear the registers
        T2CON= 0; T3CON= 0;
	TMR2 = 0; TMR3 = 0;

        // Enable the 32 bit timer T32
        T2CONbits.T32 = 1;
                
        // Enable Interrupts
        if(v_IntConfig_U8)
        {
            v_IntConfig_U8 &= ~TMR_INT_PRI0;
            IPC2bits.T3IP = v_IntConfig_U8; //Setup Timer3 interrupt for desired priority level
            IFS0bits.T3IF = 0;              //Clear Timer3 interrupt status flag
            IEC0bits.T3IE = 1;              //Enable Timer3 interrupts
        }

        // Load the period compare register ,
	PR2 = (U16)v_TimerCompare_U32;
        PR3 = (U16)(v_TimerCompare_U32>>16);

        //Start Timer1 with prescaler 1:1 and clock source as instruction cycle
        T2CONbits.TCKPS = 0;
        T2CONbits.TCS = 0;
	T2CONbits.TON = 1;

}

/*
--------------------------------------------------------------------------------
[NAME]  	: TIMER45_INIT
[TYPE]		: Public API
[INPUT] 	: Timer Tick in millisecond and Interrupt confiuration from macros
[RETURN]	: None
[DESCRIPTION]   : This function initializes the  32 bit Timer45, concatenating 
                  Timer4 and Timer5 with desired value for Clock Tick and
                  enables the interrupts
--------------------------------------------------------------------------------
*/
void TIMER45_INIT( F32 v_TickInMsec_F32, U8 v_IntConfig_U8)
{
        // Local Variables
	U32 v_TimerCompare_U32 = 0;
        S32 v_Fosc_S32 = 4E6;

        // Get the current Oscillator frequency
        v_Fosc_S32 = GET_FreqOsc();
        // Calculate period register for desired timer tick
	v_TimerCompare_U32 = v_TickInMsec_F32*v_Fosc_S32/1E3;

        // Clear the registers
        T4CON= 0; T5CON= 0;
	TMR4 = 0; TMR5 = 0;

        // Enable the 32 bit timer T45
        T4CONbits.T45 = 1;

        // Enable Interrupts
        if(v_IntConfig_U8)
        {
            v_IntConfig_U8 &= ~TMR_INT_PRI0;
            IPC7bits.T5IP = v_IntConfig_U8; //Setup Timer5 interrupt for desired priority level
            IFS1bits.T5IF = 0;              //Clear Timer5 interrupt status flag
            IEC1bits.T5IE = 1;              //Enable Timer5 interrupts
        }

        // Load the period compare register ,
	PR4 = (U16)v_TimerCompare_U32;
        PR5 = (U16)(v_TimerCompare_U32>>16);

        //Start Timer1 with prescaler 1:1 and clock source as instruction cycle
        T4CONbits.TCKPS= 0;
        T4CONbits.TCS  = 0;
	T4CONbits.TON  = 1;

}
