/*** Include Micorocontroller header files ***/
#include "p24FJ256GB210.h"

#include "Define.h"

/*** GLOBAL VARIABLES ***/
U8 V_Rx2IntFlag_U8;
U8 V_Rx1IntFlag_U8;

U8 V_T1IntFlag_U8=0;        //Interrupt Flag for Push Button

U8 V_T23IntFlag_U8;

U8 V_PBIntFlag_U8 = 0;

/*** Timer ISR variables ***/
U8 V_Timer2Flag_U8=0;
U16 V_Timer2Counter_U16=0;
U16 V_Timer2Threshold_U16=199;

U16 V_DelayThreshold_U16=0;
U16 V_DelayCounter_U16=0; //Counter for the timer
U8 V_DelayFlag_U8=0; //Timer Flag

U8 V_5msFlag_U8=0;
U8 V_20msFlag_U8=0;
U8 V_Counter1_U8=0;
U8 V_Counter2_U8=0;


/*** UART ISR variables ***/
U8 A_RxBuffer_U8[3]={0};
U8 V_WriteIndex_U8 = 0;
U8 V_RxCounter_U8=0;

/*
---------------------------------------------------------------------------------------------------
[NAME]  	 : _CNInterrupt
[TYPE]		 : Interrupt service routine
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]    : This function interrupts when the Push button PB1-3 are
                   pressed or PB1-3 state is changed. The push button interrupt
                   flag is set true. this can be checked to verify for switch press
                   or logical int.
---------------------------------------------------------------------------------------------------
*/
void __attribute__((interrupt,no_auto_psv)) _CNInterrupt(void)
{

	IFS1bits.CNIF = 0;
        V_PBIntFlag_U8 = C_TRUE;

}

/*
---------------------------------------------------------------------------------------------------
[NAME]  	 : _U1RXInterrupt
[TYPE]		 : Interrupt service routine
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]    : This function interrupts when data is being recived in UART1
---------------------------------------------------------------------------------------------------
*/
void __attribute__ ((interrupt,no_auto_psv)) _U1RXInterrupt(void)
{
    IFS0bits.U1RXIF = 0;
    A_RxBuffer_U8[V_WriteIndex_U8++] = U1RXREG;
    V_RxCounter_U8++;
    V_WriteIndex_U8 %=3;

}

/*
---------------------------------------------------------------------------------------------------
[NAME]  	 : _T2Interrupt
[TYPE]		 : Interrupt service routine
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]    : This function Interrupts when the timer compare/Tick value
                   has elapsed. Any multiple of 1 mSec timer can be generated
                   by specifying the value in SampleTime variable.
---------------------------------------------------------------------------------------------------
*/
void __attribute__ ((interrupt,no_auto_psv)) _T2Interrupt(void)
{
    IFS0bits.T2IF =0;
    if((V_Timer2Counter_U16++)==V_Timer2Threshold_U16)
    {
        V_Timer2Counter_U16=0;
        V_Timer2Flag_U8 = 1;
   }
    if((V_DelayCounter_U16++)==V_DelayThreshold_U16)
    {
        V_DelayCounter_U16=0;
        V_DelayFlag_U8 = 1;
    }

    if((V_Counter1_U8++)==49)
    {
        V_Counter1_U8=0;
        V_5msFlag_U8=1;
    }

    if((V_Counter2_U8++)==199)
    {
        V_Counter2_U8=0;
        V_20msFlag_U8=1;
    }

}



