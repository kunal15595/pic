/*
********************************************************************************
[File]          : ELB_PWM.c
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : ELB PWM configuration functions
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR]                            CHANGES
 v0.1	   	24.10.2012 	shashi.prakash@brigosha.com         Origin
********************************************************************************
*/

#include "ELB_PWM.h"

F32 V_PWM1PeriodMS_F32;
F32 V_PWM1PulseWidthMS_F32;
F32 V_PWM1DutyCycle_F32;
/*
--------------------------------------------------------------------------------
[NAME]  	: PWM1_INIT
[TYPE]		: Public API, accesible Globally
[INPUT] 	: Timer Source Macros and PWM period in Msec
[RETURN]	: None
[DESCRIPTION]   : This function configures the PWM1 module
--------------------------------------------------------------------------------
 */
void PWM1_INIT(U8 v_TimerSource_U8, F32 v_PWMperiod_F32)
{
    // Local Variables
    U16 v_TimerCompare_U16 = 0;
    U32 v_TimerOverFlow_U32 = 0;
    S32 v_Fosc_S32 = 4E6;

    // Get the current Oscillator frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate period register for desired timer tick
    v_TimerOverFlow_U32 = v_PWMperiod_F32*v_Fosc_S32/1E3;
    // Check if the value has exceded, then set the max possible
    if(v_TimerOverFlow_U32>=65535)
    {
      v_TimerCompare_U16 =  65535;
    }
    else
    {
        v_TimerCompare_U16 = v_TimerOverFlow_U32;
    }

    OC1CON1bits.OCTSEL = v_TimerSource_U8;
    OC1CON1bits.OCM = 6;
    OC1RS = v_TimerCompare_U16;
    OC1CON2bits.SYNCSEL = 0x1F;

}
/*
--------------------------------------------------------------------------------
[NAME]  	: PWM1_SET_PulseWidth
[TYPE]		: Public API, accesible Globally
[INPUT] 	: PWM Duty cycle Time in millisecond
[RETURN]	: None
[DESCRIPTION]   : This function configures the PWM1 Dutycycle Time
--------------------------------------------------------------------------------
 */
void PWM1_SET_PulseWidth(F32 v_PWMdutyCycleTime_F32)
{
    // Local Variables
    U16 v_TimerCompare_U16 = 0;
    U32 v_TimerOverFlow_U32 = 0;
    S32 v_Fosc_S32 = 4E6;

    // Get the current Oscillator frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate period register for desired timer tick
    v_TimerOverFlow_U32 = v_PWMdutyCycleTime_F32*v_Fosc_S32/1E3;
    // Check if the value has exceded, then set the max possible
    if(v_TimerOverFlow_U32>=65535)
    {
      v_TimerCompare_U16 =  65535;
    }
    else
    {
        v_TimerCompare_U16 = v_TimerOverFlow_U32;
    }
    OC1R  = v_TimerCompare_U16;
}
/*
--------------------------------------------------------------------------------
[NAME]  	: PWM2_INIT
[TYPE]		: Public API, accesible Globally
[INPUT] 	: Timer Source Macros and PWM period in Msec
[RETURN]	: None
[DESCRIPTION]   : This function configures the PWM1 module
--------------------------------------------------------------------------------
 */
void PWM2_INIT(U8 v_TimerSource_U8, F32 v_PWMperiod_F32)
{
    // Local Variables
    U16 v_TimerCompare_U16 = 0;
    U32 v_TimerOverFlow_U32 = 0;
    S32 v_Fosc_S32 = 4E6;

    // Get the current Oscillator frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate period register for desired timer tick
    v_TimerOverFlow_U32 = v_PWMperiod_F32*v_Fosc_S32/1E3;
    // Check if the value has exceded, then set the max possible
    if(v_TimerOverFlow_U32>=65535)
    {
      v_TimerCompare_U16 =  65535;
    }
    else
    {
        v_TimerCompare_U16 = v_TimerOverFlow_U32;
    }

    OC2CON1bits.OCTSEL = v_TimerSource_U8;
    OC2CON1bits.OCM = 6;
    OC2RS = v_TimerCompare_U16;
    OC2CON2bits.SYNCSEL = 0x1F;
}
/*
--------------------------------------------------------------------------------
[NAME]  	: PWM2_SET_PulseWidth
[TYPE]		: Public API, accesible Globally
[INPUT] 	: PWM Duty cycle Time in millisecond
[RETURN]	: None
[DESCRIPTION]   : This function configures the PWM1 Dutycycle Time
--------------------------------------------------------------------------------
 */
void PWM2_SET_PulseWidth(F32 v_PWMdutyCycleTime_F32)
{
    // Local Variables
    U16 v_TimerCompare_U16 = 0;
    U32 v_TimerOverFlow_U32 = 0;
    S32 v_Fosc_S32 = 4E6;

    // Get the current Oscillator frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate period register for desired timer tick
    v_TimerOverFlow_U32 = v_PWMdutyCycleTime_F32*v_Fosc_S32/1E3;
    // Check if the value has exceded, then set the max possible
    if(v_TimerOverFlow_U32>=65535)
    {
      v_TimerCompare_U16 =  65535;
    }
    else
    {
        v_TimerCompare_U16 = v_TimerOverFlow_U32;
    }
    OC2R  = v_TimerCompare_U16;
}

/*
--------------------------------------------------------------------------------
[NAME]  	: PWM3_INIT
[TYPE]		: Public API, accesible Globally
[INPUT] 	: Timer Source Macros and PWM period in Msec
[RETURN]	: None
[DESCRIPTION]   : This function configures the PWM1 module
--------------------------------------------------------------------------------
 */

void PWM3_INIT(U8 v_TimerSource_U8, F32 v_PWMperiod_F32)
{
    // Local Variables
    U16 v_TimerCompare_U16 = 0;
    U32 v_TimerOverFlow_U32 = 0;
    S32 v_Fosc_S32 = 4E6;

    // Get the current Oscillator frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate period register for desired timer tick
    v_TimerOverFlow_U32 = v_PWMperiod_F32*v_Fosc_S32/1E3;
    // Check if the value has exceded, then set the max possible
    if(v_TimerOverFlow_U32>=65535)
    {
      v_TimerCompare_U16 =  65535;
    }
    else
    {
        v_TimerCompare_U16 = v_TimerOverFlow_U32;
    }

    OC3CON1bits.OCTSEL = v_TimerSource_U8;
    OC3CON1bits.OCM = 6;
    OC3RS = v_TimerCompare_U16;
    OC3CON2bits.SYNCSEL = 0x1F;
}
/*
--------------------------------------------------------------------------------
[NAME]  	: PWM3_SET_PulseWidth
[TYPE]		: Public API, accesible Globally
[INPUT] 	: PWM Duty cycle Time in millisecond
[RETURN]	: None
[DESCRIPTION]   : This function configures the PWM1 Dutycycle Time
--------------------------------------------------------------------------------
 */
void PWM3_SET_PulseWidth(F32 v_PWMdutyCycleTime_F32)
{
    // Local Variables
    U16 v_TimerCompare_U16 = 0;
    U32 v_TimerOverFlow_U32 = 0;
    S32 v_Fosc_S32 = 4E6;

    // Get the current Oscillator frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate period register for desired timer tick
    v_TimerOverFlow_U32 = v_PWMdutyCycleTime_F32*v_Fosc_S32/1E3;
    // Check if the value has exceded, then set the max possible
    if(v_TimerOverFlow_U32>=65535)
    {
      v_TimerCompare_U16 =  65535;
    }
    else
    {
        v_TimerCompare_U16 = v_TimerOverFlow_U32;
    }
    OC3R  = v_TimerCompare_U16;
}

/*
--------------------------------------------------------------------------------
[NAME]  	: PWM4_INIT
[TYPE]		: Public API, accesible Globally
[INPUT] 	: Timer Source Macros from ELB_PWM.h and PWM period in Msec
[RETURN]	: None
[DESCRIPTION]   : This function configures the PWM1 module
--------------------------------------------------------------------------------
 */
void PWM4_INIT(U8 v_TimerSource_U8, F32 v_PWMperiod_F32)
{
    // Local Variables
    U16 v_TimerCompare_U16 = 0;
    U32 v_TimerOverFlow_U32 = 0;
    S32 v_Fosc_S32 = 4E6;

    // Get the current Oscillator frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate period register for desired timer tick
    v_TimerOverFlow_U32 = v_PWMperiod_F32*v_Fosc_S32/1E3;
    // Check if the value has exceded, then set the max possible
    if(v_TimerOverFlow_U32>=65535)
    {
      v_TimerCompare_U16 =  65535;
    }
    else
    {
        v_TimerCompare_U16 = v_TimerOverFlow_U32;
    }

    OC4CON1bits.OCTSEL = v_TimerSource_U8;
    OC4CON1bits.OCM = 6;
    OC4RS = v_TimerCompare_U16;
    OC4CON2bits.SYNCSEL = 0x1F;
}

/*
--------------------------------------------------------------------------------
[NAME]  	: PWM4_SET_PulseWidth
[TYPE]		: Public API, accesible Globally
[INPUT] 	: PWM Duty cycle Time in millisecond
[RETURN]	: None
[DESCRIPTION]   : This function configures the PWM1 Dutycycle Time
--------------------------------------------------------------------------------
 */
void PWM4_SET_PulseWidth(F32 v_PWMdutyCycleTime_F32)
{
    // Local Variables
    U16 v_TimerCompare_U16 = 0;
    U32 v_TimerOverFlow_U32 = 0;
    S32 v_Fosc_S32 = 4E6;

    // Get the current Oscillator frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate period register for desired timer tick
    v_TimerOverFlow_U32 = v_PWMdutyCycleTime_F32*v_Fosc_S32/1E3;
    // Check if the value has exceded, then set the max possible
    if(v_TimerOverFlow_U32>=65535)
    {
      v_TimerCompare_U16 =  65535;
    }
    else
    {
        v_TimerCompare_U16 = v_TimerOverFlow_U32;
    }
    OC4R  = v_TimerCompare_U16;
}
