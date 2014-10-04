/*-------------------------------------------------------------------------
 *                                VPID.h                                  *
 * Copyright Theta Engineering, Costa Mesa CA, 2014  All Rights Reserved  *
 *------------------------------------------------------------------------*
  
This module implements a generic "velocity" PID algorithm.  This algorithm
is free from a phenomena known as "integrator wind-up".  It can never 
integrate "past the rails".  A direct consequence of this however is 
some behavior that might not be expected when it is being used in a loop 
that uses mostly proportional gain.  

Should the input conditions and proportional gain be such that the output 
is driven to the "rail", the effect is as though the integrator is 
immediately adjusted, even if the I term is zero!  As soon as the input 
error stops increasing and starts to decrease, the output will lift off 
the rail even though the product of error and proportional gain still 
exceeds the output range.  The setpoint is rendered essentially meaningless 
with respect to P.  Only if there is some I term configured will the control 
loop eventually correct itself back to the setpoint.  In other words, the
setpoint is only meaningful with respect to the I term.

Hence it is not recommended to use velocity PID in control loops that require
mostly P and little or no I.
*/

#ifndef VPID_H
#define VPID_H

#include <stdint.h>
#define INT32 int32_t
#define INT64 int64_t

//Caller allocates and creates an instance of this structure to create 
//a VPID controller:
typedef struct {      
  INT32 nGain;      //PID Gain: 16.16 (16 bits integer, 16 bits fraction, etc)
  INT32 nKp;        //P term: 16.16
  INT32 nKi;        //I term: 16.16
  INT32 nKd;        //D term: 16.16
  INT32 nError1;    //GPID previous error
  INT32 nError2;    //GPID 2nd previous error
  INT32 nDrive1;    //GPID previous drive
  } tVPID;


void VPIDInit(tVPID* pVPID,
              INT32 nInit,
              INT32 nGain,
              INT32 nKp,
              INT32 nKi,
              INT32 nKd);
/*PURPOSE: Initializes a VPID object allocated by the caller.
  GIVEN: 
    pVPID - address of a tVPID structure allocated by caller.
    nInit - Value to initialize feedback controller to.
    nGain - Setting for Gain term
    nKp - Setting for Proportional term.
    nKi - Setting for Integral term.
    nKd - Setting for Derivative term.
  ASSUMES: Nothing.
  USAGE: Caller must allocate a tVPID object, then call this function
    on it before using any other function in this module.
*/

INT32 VPIDUpdate(tVPID* pVPID, INT32 nSetpoint, INT32 nFeedback);
/*PURPOSE: To implement the VPID algorithm.
  GIVEN:
    pGPID - address of a tVPID structure allocated by caller
    nFeedback - Feedback signal from the entity being controlled.
  ASSUMES: VPIDInit() was called.
  RETURNS: The drive to be applied to the controlled entity. 
  USAGE: This function must be called periodically at a steady rate in order
    to produce smooth control.  The drive value returned by this function
    is clamped to the range of an INT32.  Caller should scale this value 
    as appropriate to fit the drive range of the entity being controlled.
    This function executes in 9.64uS on a PIC32MX at optimization -O0 and
    CPU clock of 49.152MHz, 4.64uS at -O3.
*/

#endif
