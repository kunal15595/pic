/*-------------------------------------------------------------------------
 *                                GPID.c                                  *
 * Copyright Theta Engineering, Costa Mesa CA, 2014  All Rights Reserved  *
 *------------------------------------------------------------------------*

 IMPLEMENTATION NOTES:
 GPIDUpdate() implements a GPID algorithm.  A basic description of this
 algorithm is as follows:

   1. INT16 nErr = nSetpoint - nFeedback;  no special effort required
      to deal with arithmetic overflow.
 For all the following steps, saturating arithmetic is used in order to
 avoid arithmetic overflow:
   2. nErr * nKi is added to the lI element of the GPID object.
   3. If the magnitude of lI/2^16 exceeds nIClamp, then set the magnitude of
      lI to nIClamp*2^16, preserving the sign of lI.
   4. Return the result of the following expression:
        (nErr * nKp + lI/2^16 + (nErr - nError) * nKd) * nGain
*/

#include "GPID.h"     //Interface for this module.

#define CLAMP(a, min, max) (a = ((a > max) ? max : ((a < min) ? min : a)))


//----------------------------------------------------------------------------
// Private methods section
//----------------------------------------------------------------------------
//Utility function for adding INT32s without overflow:
static inline INT32 SumInt32(INT32 nA, INT32 nB)
{
    INT32 nSum;

    nSum = nA + nB;
    //If sign of operands is the same, but sign of answer is different,
    if ((nSum ^ nA) & 0x80000000 && (nSum ^ nB) & 0x80000000)
    {
        //we have overflow so clamp it:
        if (nSum < 0)
            nSum = 0x7FFFFFFF;
        else
            nSum = -0x7FFFFFFF;
    }
    return nSum;
}



//----------------------------------------------------------------------------
// Public methods section
//----------------------------------------------------------------------------
void GPIDInit(tGPID* pGPID,
              INT16 nGain,
              INT16 nKp,
              INT16 nKi,
              INT16 nKd,
              INT16 nIClamp)
{
    pGPID->nGain = nGain;
    pGPID->nKp = nKp;
    pGPID->nKi = nKi;
    pGPID->nKd = nKd;
    pGPID->nIClamp = nIClamp;
    pGPID->lI = 0;
    pGPID->nError = 0;
}


INT16 GPIDUpdate(tGPID* pGPID, INT16 nSetpoint, INT16 nFeedback)
{
    INT16 nErr;
    INT32 lDrive, lProportional, lIntegral, lDerivative;
    INT32 lIClamp;

    //Determine error:
    nErr = nSetpoint - nFeedback;

    //Determine proportional term:
    lProportional = nErr;
    lProportional *= pGPID->nKp;
    CLAMP(lProportional, INT16_MIN, INT16_MAX);

    //Determine integral term:
    lIntegral = nErr;
    lIntegral *= pGPID->nKi;
    lIntegral = SumInt32(lIntegral, pGPID->lI);
    lIClamp = ((INT32)(pGPID->nIClamp)) << 16;
    CLAMP(lIntegral, -lIClamp, lIClamp);
    pGPID->lI = lIntegral;

    //Determine derivative term:
    lDerivative = nErr;
    lDerivative -= pGPID->nError;
    CLAMP(lDerivative, INT16_MIN, INT16_MAX);
    lDerivative *= pGPID->nKd;
    CLAMP(lDerivative, INT16_MIN, INT16_MAX);

    //Update nError for next cycle:
    pGPID->nError = nErr;

    //Determine drive:
    lDrive = lProportional;
    lDrive += lIntegral >> 16;
    lDrive += lDerivative;
    lDrive *= pGPID->nGain;
    CLAMP(lDrive, INT16_MIN, INT16_MAX);

    return lDrive;
}
