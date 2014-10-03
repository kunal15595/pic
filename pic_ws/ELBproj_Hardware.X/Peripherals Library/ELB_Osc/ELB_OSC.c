
#include "ELB_OSC.h"

void SET_FreqOsc(U8 v_OscFreq_U8)
{
    U8 v_Temp_U8 = 0, v_CurrOsc_U8=0;

    // Find the current Oscillator
    v_CurrOsc_U8= _COSC;

    // If the current Oscillator has PLL then set the desired Divider
    if((v_CurrOsc_U8==1)|| (v_CurrOsc_U8==3))
    {
        // If input value correct then set the Divider for PLL(32MHZ)
        if(v_OscFreq_U8<=PLL_4MHZ)
        {
            _RCDIV = 0;             // Default 1, hence need to be cleared
            _CPDIV = v_OscFreq_U8;  // Assign Divider
        }       
    }
    else
    {
        // If the current Osc is FRCDIV then set the desired Divider
        if(v_CurrOsc_U8 == 7) 
        {
            // If input value correct then set the divider for FRCDIV(8MHZ)
            if (v_OscFreq_U8>=FRCDIV_8MHZ)
            {
                v_Temp_U8 = v_OscFreq_U8>>4;    // Get the last 4 bits from macro
                _RCDIV = v_Temp_U8;             // Assign the Divider
            }
        }
    }
}


S32 GET_FreqOsc(void)
{
    U8 v_CurrOsc_U8 = 0, v_Temp_U8 =  0;
    U8 v_CPDIV_U8= 0, v_FRCDIV_U8 = 0;
    S32 v_CryFrq_S32 = 4E6;

    v_CurrOsc_U8= _COSC;    // Find the current oscillator
    v_CPDIV_U8  = _CPDIV;   // Find the current Divider for PLL
    v_FRCDIV_U8 = _RCDIV;   // Find the current Divider for FRCDIV

    // Select the current Oscillator
    switch(v_CurrOsc_U8)
    {
            // FRC oscillator 8MHZ, FCY = 4MHZ
        case 0:
            v_CryFrq_S32 = 4E6;
            break;
            // FRCPLL oscillator 32MHZ, calculate FCY depending upon Divider
        case 1:
            v_CryFrq_S32 = 16E6;
            v_Temp_U8 = (U8)1<<v_CPDIV_U8;
            v_CryFrq_S32 = (F32)v_CryFrq_S32/v_Temp_U8;
            break;
            // PRI oscillator 8MHZ, FCY = 4MHZ
        case 2:
            v_CryFrq_S32 = 4E6;
            break;
            // PRIPLL oscillator 32MHZ, calculate FCY depending upon Divider
        case 3:
            v_CryFrq_S32 = 16E6;
            v_Temp_U8 = (U8)1<<v_CPDIV_U8;
            v_CryFrq_S32 = (F32)v_CryFrq_S32/v_Temp_U8;
            break;
            // SOSC oscillator 32.768KHZ, FCY = 32.768KHZ/2.0
        case 4:
            v_CryFrq_S32 = 32768/2.0;
            break;
            // SOSC oscillator 31KHZ, FCY = 31KHZ/2.0
        case 5:
            v_CryFrq_S32 = 31000/2.0;
            break;
            // FRC16 oscillator 500KHZ, FCY = 500KHZ/2.0
        case 6:
            v_CryFrq_S32 = 250000;
            break;
            // FRCDIV oscillator 8MHZ, calculate FCY depending upon Divider
        case 7:
            v_CryFrq_S32 = 4E6;
            v_Temp_U8 = (U8)1<<v_FRCDIV_U8;
            v_CryFrq_S32 = (F32)v_CryFrq_S32/v_Temp_U8;
            break;
    }

    // Return the FCY, Instruction Clock Cycle
    return v_CryFrq_S32;

}
