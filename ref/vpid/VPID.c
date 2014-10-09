/*-------------------------------------------------------------------------
 *                                VPID.c                                  *
 * Copyright Theta Engineering, Costa Mesa CA, 2014  All Rights Reserved  *
 *------------------------------------------------------------------------*

 IMPLEMENTATION NOTES:
 VPIDUpdate() implements a "velocity" GPID algorithm. It differs from a
 standard GPID algorithm in that derivative of the error plays the role
 ordinarily played by the plain error. The algorithm does the following:

 1. nError = nSetpoint - nFeedback
 2. lProportional = (nError - nError1) * nKp
 3. lIntegral = nError * nKi
 4. lDerivative = (-2*nError1 + nError + nError2) * nKd
 5. nError2 = nError1, nError1 = nError
 6. nDrive = (lProportional + lIntegral + lDerivative) * nGain + nError

 Clamping to the range of a 32-bit integer is done at appropriate places
 during the calculation.
*/

#include "VPID.h"     //Interface for this module.


//----------------------------------------------------------------------------
// Private methods section
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// Public methods section
//----------------------------------------------------------------------------
void VPIDInit(tVPID* pVPID,
              INT32 nInit,
              INT32 nGain,
              INT32 nKp,
              INT32 nKi,
              INT32 nKd)
  {
  pVPID->nGain = nGain;
  pVPID->nKp = nKp;
  pVPID->nKi = nKi;
  pVPID->nKd = nKd;
  pVPID->nError1 = 0;
  pVPID->nError2 = 0;
  pVPID->nDrive1 = nInit;
  }


INT32 VPIDUpdate(tVPID* pVPID, INT32 nSetpoint, INT32 nFeedback)
  {
  INT64 lAcc, lProportional, lIntegral, lDerivative;
  INT32 nError;

  //Determine error:
  lAcc = nSetpoint - nFeedback;
  //Clamp to 32 bits:
  if (lAcc > 0x7FFFFFFF)
    nError = 0x7FFFFFFF;
  else if (lAcc < -0x7FFFFFFF)
    nError = -0x7FFFFFFF;
  else
    nError = lAcc;
  
  //Determine proportional signal:
  lProportional = nError;
  lProportional -= pVPID->nError1;
  lProportional *= pVPID->nKp;
  lProportional /= 0x10000;
  
  //Determine integral signal:
  lIntegral = nError;
  lIntegral *= pVPID->nKi;
  lIntegral /= 0x10000;
  
  //Determine derivative signal:
  lDerivative = pVPID->nError1;
  lDerivative *= -2;
  lDerivative += nError;
  lDerivative += pVPID->nError2;
  lDerivative *= pVPID->nKd;
  lDerivative /= 0x10000;
  
  //Determine drive:
  lAcc = lProportional;
  lAcc += lIntegral;
  lAcc += lDerivative;
  
  //Add PID result to result in proportion to G term:
  lAcc *= pVPID->nGain;
  lAcc /= 0x10000;
  lAcc += pVPID->nDrive1;
  
  //Clamp to 32 bits:
  if (lAcc > 0x7FFFFFFF)
    lAcc = 0x7FFFFFFF;
  else if (lAcc < -0x7FFFFFFF)
    lAcc = -0x7FFFFFFF;

  //Shift:
  pVPID->nError2 = pVPID->nError1;
  pVPID->nError1 = nError;
  pVPID->nDrive1 = lAcc;

  //return lAcc
  return lAcc;
  }

