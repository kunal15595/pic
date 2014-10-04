/*-------------------------------------------------------------------------
 *                             Trajectory.c                               *
 * Copyright Theta Engineering, Costa Mesa CA, 2014  All Rights Reserved  *
 *------------------------------------------------------------------------*

 IMPLEMENTATION NOTES:
 The first 3 elements of the tTRAJECTORY object contain the state of the
 trajectory generator while the remaining elements are configuration
 settings which control trajectory generation.

 SquareRootOf() implements fast integer square roots by a bisection
 algorithm.
 
 DecelRamp() takes a tTRAJECTORY object and an absolute distance. The 
 return value of DecelRamp() is the velocity required to smoothly
 decelerate the trajectory at nDeceleration to the destination point.
 That velocity is found by:
      SquareRootOf(2 * distance * nDeceleration) - nDeceleration/2
 The velocity returned by DecelRamp() decreases as the trajectory approaches
 its destination and distance decreases. If distance is great enough to
 overflow the computation then MAX_INT32 is returned. The computation is
 aware that the 16 lower bits in the fixed-point representations of position
 and velocity are fractional.
 
 TrajectoryUpdate() implements the core trajectory-generator algorithm.
 A basic description of this algorithm is as follows:

 switch(eState) // Update lVelocity according to eState:
    case DONE:
        // do nothing
    case FORWARD_ACCEL:
        lVelocity is set to the minimum of
            (lVelocity + nAcceleration),
            MaxVelocity, and
            DecelRamp.
        If lVelocity + nAcceleration is the minimum, remain in FORWARD_ACCEL.
        If MaxVelocity is the minimum, transition to FORWARD_STEADY.
        If DecelRamp is the minimum, transition to FORWARD_DECEL.
    case FORWARD_STEADY:
        if (lVelocity > DecelRamp)
            lVelocity = DecelRamp, and transition to FORWARD_DECEL.
        else
            Remain in FORWARD_STEADY.
    case FORWARD_DECEL:
        if (DecelRamp <= 0)
            lVelocity = 0 and transition to DONE.
        else
            lVelocity = DecelRamp, and remain in FORWARD_DECEL.
    // REVERSE_ACCEL, REVERSE_STEADY, and REVERSE_DECEL are each handled analogously.
    case STOPPING:
        if (lVelocity > nDeceleration)
            lVelocity -= nDeceleration, and remain in STOPPING.
        else if (lVelocity > 0)
            lVelocity = 0, and transition to DONE.
        // Negative velocity is handled analogously.
 lPosition += lVelocity
 Return the high 16 bits of lPosition.
 
 In the actual implementation of TrajectoryUpdate(), other defensive
 checks and defensive transitions are implemented. For brevity's
 sake these are not shown in the pseudocode above.

 TrajectorySeek() initiates a movement by setting nDestination of the
 tTRAJECTORY object to the value given by the corresponding parameter.
 This must be done without allowing a race condition since
 TrajectorySeek() is mainline code while TrajectoryUpdate(), which is
 using it, may be interrupt code.

 TrajectoryStatus() returns the code from tTRAJECTORY_STATUS that
 best corresponds with the trajectory's current physical motion.
*/

#include "Trajectory.h"     //Interface to this module.


//Trajectory state machine state:
typedef enum {
  DONE,
  FORWARD_ACCEL,
  FORWARD_STEADY,
  FORWARD_DECEL,
  REVERSE_ACCEL,
  REVERSE_STEADY,
  REVERSE_DECEL,
  STOPPING,
} tTRAJECTORY_STATE;



//----------------------------------------------------------------------------
// Private methods section
//----------------------------------------------------------------------------
static UINT16 SquareRootOf(UINT32 lValue)
{
  UINT16 nResult = 1;
  UINT16 nTestBit;
  UINT32 lTemp;

  //Special-case handling for zero:
  if (lValue == 0)
    return 0;
  //Make a copy of supplied argument:
  lTemp = lValue;
  //Shift result left one position for each two positions
  //argument can be shifted right:
  while (lTemp >>= 2)
    nResult <<= 1;
  //We now have the msb of the square root.  Next task is to compute
  //the remaining bits which is done by simple trial and error.
  //Make copy of msb:
  nTestBit = nResult;
  //Shift it right one position at a time:
  while (nTestBit >>= 1)
  {
    //Add shifted bit to result.
    nResult |= nTestBit;
    //Square result.  If it exceeds original value, remove bit:
    if (lValue < (unsigned long)nResult * nResult)
      nResult &= ~nTestBit;
  }
  return nResult;
}


static INT32 DecelRamp(tTRAJECTORY* pTrajectory, UINT16 nDistance)
{
  UINT32 lTemp;

  // Multiplication of two ints cannot overflow:
  lTemp = nDistance;
  lTemp *= pTrajectory->nDeceleration;
  // Check if times two will overflow:
  if (lTemp >= 0x80000000)
    return INT32_MAX;
  // Times two is safe:
  lTemp <<= 1;
  lTemp = SquareRootOf(lTemp);
  lTemp <<= 8;
  //Make sure end of trajectory crosses zero:
  lTemp -= pTrajectory->nDeceleration / 2; // negative result is possible
  return lTemp;
}



//----------------------------------------------------------------------------
// Public methods section
//----------------------------------------------------------------------------
void TrajectoryInit(tTRAJECTORY* pTrajectory,
                    UINT16 nMaxVelocity,
                    UINT16 nAcceleration,
                    UINT16 nDeceleration)
{
    pTrajectory->lPosition = 0;
    pTrajectory->nDestination = 0;
    pTrajectory->lVelocity = 0;
    pTrajectory->eState = DONE;

    pTrajectory->nMaxVelocity = nMaxVelocity;
    pTrajectory->nAcceleration = nAcceleration;
    pTrajectory->nDeceleration = nDeceleration;
}

UINT16 TrajectoryUpdate(tTRAJECTORY* pTrajectory)
{
    INT32 lDecelRamp;
    UINT16 nPosition = pTrajectory->lPosition >> 16;
    UINT32 lMaxVelocity = ((UINT32)(pTrajectory->nMaxVelocity) << 16) / TRAJECTORY_FREQ;

    // Update nVelocity:
    switch(pTrajectory->eState)
    {
        default: // DONE
            break;

        case FORWARD_ACCEL:
            lDecelRamp = DecelRamp(pTrajectory, pTrajectory->nDestination - nPosition);
            if (lDecelRamp <= 0)
            {
                pTrajectory->lVelocity = 0;
                pTrajectory->eState = DONE;
                break;
            }
            pTrajectory->lVelocity += pTrajectory->nAcceleration;
            if (pTrajectory->lVelocity >= lMaxVelocity)
            {
                pTrajectory->lVelocity = lMaxVelocity;
                pTrajectory->eState = FORWARD_STEADY;
            }
            if (pTrajectory->lVelocity >= lDecelRamp)
            {
                pTrajectory->lVelocity = lDecelRamp;
                pTrajectory->eState = FORWARD_DECEL;
            }
            break;
            
        case FORWARD_STEADY:
            lDecelRamp = DecelRamp(pTrajectory, pTrajectory->nDestination - nPosition);
            if (lDecelRamp <= 0)
            {
                pTrajectory->lVelocity = 0;
                pTrajectory->eState = DONE;
                break;
            }
            if (pTrajectory->lVelocity >= lDecelRamp)
            {
                pTrajectory->lVelocity = lDecelRamp;
                pTrajectory->eState = FORWARD_DECEL;
            }
            break;
            
        case FORWARD_DECEL:
            lDecelRamp = DecelRamp(pTrajectory, pTrajectory->nDestination - nPosition);
            if (lDecelRamp > pTrajectory->lVelocity)
            {
                pTrajectory->lVelocity = 0;
                pTrajectory->eState = DONE;
            }
            else if (lDecelRamp <= 0)
            {
                pTrajectory->lVelocity = 0;
                pTrajectory->eState = DONE;
            }
            else
            {
                pTrajectory->lVelocity = lDecelRamp;
            }
            break;
            
        case REVERSE_ACCEL:
            lDecelRamp = DecelRamp(pTrajectory, nPosition - pTrajectory->nDestination);
            if (lDecelRamp <= 0)
            {
                pTrajectory->lVelocity = 0;
                pTrajectory->eState = DONE;
                break;
            }
            pTrajectory->lVelocity -= pTrajectory->nAcceleration;
            if (pTrajectory->lVelocity <= -lMaxVelocity)
            {
                pTrajectory->lVelocity = -lMaxVelocity;
                pTrajectory->eState = REVERSE_STEADY;
            }
            if (pTrajectory->lVelocity <= -lDecelRamp)
            {
                pTrajectory->lVelocity = -lDecelRamp;
                pTrajectory->eState = REVERSE_DECEL;
            }
            break;
            
        case REVERSE_STEADY:
            lDecelRamp = DecelRamp(pTrajectory, nPosition - pTrajectory->nDestination);
            if (lDecelRamp <= 0)
            {
                pTrajectory->lVelocity = 0;
                pTrajectory->eState = DONE;
                break;
            }
            if (pTrajectory->lVelocity <= -lDecelRamp)
            {
                pTrajectory->lVelocity = -lDecelRamp;
                pTrajectory->eState = REVERSE_DECEL;
            }
            break;

        case REVERSE_DECEL:
            lDecelRamp = DecelRamp(pTrajectory, nPosition - pTrajectory->nDestination);
            if (-lDecelRamp < pTrajectory->lVelocity)
            {
                pTrajectory->lVelocity = 0;
                pTrajectory->eState = DONE;
            }
            else if (lDecelRamp <= 0)
            {
                pTrajectory->lVelocity = 0;
                pTrajectory->eState = DONE;
            }
            else
            {
                pTrajectory->lVelocity = -lDecelRamp;
            }
            break;
            
        case STOPPING:
            if (pTrajectory->lVelocity > pTrajectory->nDeceleration)
            {
                pTrajectory->lVelocity -= pTrajectory->nDeceleration;
            }
            else if (pTrajectory->lVelocity < -pTrajectory->nDeceleration)
            {
                pTrajectory->lVelocity += pTrajectory->nDeceleration;
            }
            else
            {
                pTrajectory->lVelocity = 0;
                pTrajectory->eState = DONE;
            }
            break;
    }
    
    // Update lPosition:
    pTrajectory->lPosition += pTrajectory->lVelocity;
    
    // Return updated position to caller:
    return (pTrajectory->lPosition >> 16);
}


void TrajectorySeek(tTRAJECTORY* pTrajectory,
                    UINT16 nDestination,
                    tTRAJECTORY_TYPE eTrajectoryType)
{
    pTrajectory->eState = DONE; //Prevents race condition if TrajectoryUpdate()
                                //is being called asynchronously.
    switch(eTrajectoryType)
    {
      case FORWARD:
        pTrajectory->nDestination = nDestination;
        pTrajectory->eState = FORWARD_ACCEL;
        break;

      case REVERSE:
        pTrajectory->nDestination = nDestination;
        pTrajectory->eState = REVERSE_ACCEL;
        break;

      default: //STOP
        pTrajectory->eState = STOPPING;
        break;
    }
}


tTRAJECTORY_STATUS TrajectoryStatus(tTRAJECTORY* pTrajectory)
{
  switch(pTrajectory->eState)
  {
    default: // DONE
      return TRAJECTORY_DONE;

    case FORWARD_ACCEL:
      if (pTrajectory->lVelocity > 0)
        return TRAJECTORY_FWD_ACCEL;
      else
        return TRAJECTORY_FWD_DECEL;

    case FORWARD_STEADY:
      return TRAJECTORY_FWD_STEADY;

    case FORWARD_DECEL:
      return TRAJECTORY_FWD_DECEL;

    case REVERSE_ACCEL:
      if (pTrajectory->lVelocity < 0)
        return TRAJECTORY_REV_ACCEL;
      else
        return TRAJECTORY_REV_DECEL;

    case REVERSE_STEADY:
      return TRAJECTORY_REV_STEADY;

    case REVERSE_DECEL:
      return TRAJECTORY_REV_DECEL;
  }
}

