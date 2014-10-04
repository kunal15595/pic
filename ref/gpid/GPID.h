/*-------------------------------------------------------------------------
 *                                GPID.h                                  *
 * Copyright Theta Engineering, Costa Mesa CA, 2014  All Rights Reserved  *
 *------------------------------------------------------------------------*

 This module provides an object-oriented generic GPID algorithm.
*/

#ifndef GPID_H
#define GPID_H

#include <stdint.h>
#define INT16   int16_t
#define UINT16  uint16_t
#define INT32   int32_t

//Caller allocates an instance of this structure to create a GPID controller:
typedef struct {
  INT16 nGain;      //PID Gain
  INT16 nKp;        //P term
  INT16 nKi;        //I term
  INT16 nKd;        //D term
  INT16 nIClamp;    //Maximum contribution of I term to output
  INT32 lI;         //Integrator
  INT16 nError;     //GPID previous error
  } tGPID;


void GPIDInit(tGPID* pGPID,
              INT16 nGain,
              INT16 nKp,
              INT16 nKi,
              INT16 nKd,
              INT16 nIClamp);
/*PURPOSE: Initializes a GPID object allocated by the caller.
  GIVEN:
    pGPID - address of a tGPID structure allocated by caller.
    nGain - Setting for Gain term
    nKp - Setting for Proportional term.
    nKi - Setting for Integral term.
    nKd - Setting for Derivative term.
    nIClamp - Setting for Integrator Clamp term.
  ASSUMES: Nothing.
  USAGE: Caller must allocate a tGPID object, then call this function
    on it before using any other function in this module.
*/

INT16 GPIDUpdate(tGPID* pGPID, INT16 nSetpoint, INT16 nFeedback);
/*PURPOSE: To run the GPID algorithm.
  GIVEN:
    pGPID - Address of a tGPID structure allocated by caller.
    nSetpoint - The target position for the entity being controlled.
    nFeedback - Feedback signal from the entity being controlled.
  ASSUMES: GPIDInit() was called.
  RETURNS: The drive to be applied to the controlled entity.
  USAGE: This function must be called periodically at a steady rate in order
    to produce smooth control.  The drive value returned by this function
    is clamped to the range of an INT16.  Caller should scale and offset
    this value as appropriate to fit the drive range of the entity being
    controlled.  This algorithm strives to make the nFeedback value match
    the nSetpoint value by means of the drive value it returns.
*/

#endif
