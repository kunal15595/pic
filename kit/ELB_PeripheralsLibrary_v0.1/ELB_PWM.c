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
