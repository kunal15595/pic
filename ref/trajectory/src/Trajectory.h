/*-------------------------------------------------------------------------
 *                             Trajectory.h                               *
 * Copyright Theta Engineering, Costa Mesa CA, 2014  All Rights Reserved  *
 *------------------------------------------------------------------------*

 This module implements an object-oriented trapezoidal trajectory generator
 for general-purpose motion control applications. For each trajectory
 object allocated, the user specifies an acceleration rate, deceleration
 rate, and a steady-state velocity. The user can then command any
 trajectory object to seek to a destination in either the forward or
 reverse direction, or to stop. A seek can be commanded at any time,
 regardless whether the trajectory is in motion or at rest at the time of
 the command. The transition to the commanded motion is handled smoothly
 in either case.
 
 The real-time aspect of trajectory motion is handled by a function
 TrajectoryUpdate(), which expects to be called at the rate specified
 by TRAJECTORY_FREQ. The constant TRAJECTORY_FREQ can be defined anywhere
 from 1 Hz to 65.536 kHz depending on the user application's needs; the
 default is 1 kHz. Each call to TrajectoryUpdate() advances the
 trajectory object's position, and the return value of TrajectoryUpdate()
 is the trajectory object's present position in real time. It is safe to
 call TrajectoryUpdate() from an ISR.
 
 Position information is encoded as an unsigned 16-bit integer value that
 is treated circularly, i.e., the next position after 65,535 is 0.  For
 example, a seek from 10 to 65500 is a long seek going FORWARD but is a
 very short seek in the REVERSE direction.  The trajectory generator is
 completely agnostic to position zero-crossings.
*/

#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <stdint.h>
#include <stdbool.h>

#define INT16 int16_t
#define INT32 int32_t
#define UINT16 uint16_t
#define UINT32 uint32_t
#define BOOL bool
#define TRUE true
#define FALSE false

// Real-time update rate in Hz (can be any value from 1 to 65536):
#define TRAJECTORY_FREQ 1000

//For caller's use in specifying seek direction or stopping an ongoing seek:
typedef enum {
  STOP,
  FORWARD,
  REVERSE,
}tTRAJECTORY_TYPE;

//Trajectory statuses returned by TrajectoryStatus() reflect physical
//state:
typedef enum {
  TRAJECTORY_DONE,
  TRAJECTORY_FWD_ACCEL,
  TRAJECTORY_FWD_STEADY,
  TRAJECTORY_FWD_DECEL,
  TRAJECTORY_REV_ACCEL,
  TRAJECTORY_REV_STEADY,
  TRAJECTORY_REV_DECEL,
}tTRAJECTORY_STATUS;

//Caller allocates an instance of this structure to create a trajectory
//generator:
typedef struct {
  int eState;                       //Indicates trajectory state (forward/reverse, accel/decel).
  UINT32 lPosition;                 //Present position in units of 1/65536 counts
  INT32 lVelocity;                  //Present velocity in units of TRAJECTORY_FREQ/65536 counts per second
  UINT16 nDestination;              //Target destination in units of counts
  UINT16 nMaxVelocity;              //Maximum velocity in counts per second
  UINT16 nAcceleration;             //Acceleration to apply at start of move,
                                    //in units of TRAJECTORY_FREQ^2/65536 counts per sec^2
  UINT16 nDeceleration;             //Deceleration to apply at end of move,
                                    //in units of TRAJECTORY_FREQ^2/65536 counts per sec^2
}tTRAJECTORY;


void TrajectoryInit(tTRAJECTORY* pTrajectory,
                    UINT16 nMaxVelocity,
                    UINT16 nAcceleration,
                    UINT16 nDeceleration);
/*PURPOSE: To initialize a trajectory object.
  GIVEN:
    pTrajectory - Address of the tTRAJECTORY object to be initialized.
    nMaxVelocity - Sets the maximum velocity of the generated trajectories.
    nAcceleration - Sets the acceleration used for the leading edge of a
      trapezoidal trajectory.
    nDeceleration - Sets the deceleration used for the trailing edge of a
      trapezoidal trajectory.
  ASSUMES: Nothing.
  USAGE: Caller must allocate a tTRAJECTORY object, then call this function
    on it before using any other function in this module.
*/

UINT16 TrajectoryUpdate(tTRAJECTORY* pTrajectory);
/*PURPOSE: To run a trajectory generator.
  GIVEN:
    pTrajectory - Address of caller's trajectory object.
  ASSUMES: TrajectoryInit() has been called.  Being called steadily at TRAJECTORY_FREQ
    times per second for each trajectory object.
  RETURNS: The next position in the trajectory.
  USAGE: This function should be called at the rate specified by TRAJECTORY_FREQ
    on any particular trajectory object in order to provide smooth control and
    for the units to be accurate.
*/

void TrajectorySeek(tTRAJECTORY* pTrajectory,
                    UINT16 nDestination,
                    tTRAJECTORY_TYPE eType);
/*PURPOSE: To trigger the generation of a trajectory that will end at the
    specified destination.
  GIVEN:
    pTrajectory - Address of caller's trajectory object.
    nDestination - Target destination for the trajectory. Ignored
      if eType == STOP.
    eType - FORWARD or REVERSE values specify which direction to use when
      seeking to the desired destination.  It is the caller's responsibility
      to ensure the desired destination can be reached in the direction
      specified.  STOP triggers the start of a deceleration ramp, causing
      a seek to end before the destination is reached.
  ASSUMES: TrajectoryInit() has been called.  TrajectoryUpdate() being
    called at a steady rate.
  USAGE: This function is for use by mainline code in generating
    motion profiles for the entities being controlled.
*/

tTRAJECTORY_STATUS TrajectoryStatus(tTRAJECTORY* pTrajectory);
/*PURPOSE: To provide info on the present status of a trajectory.
  GIVEN:
    pTrajectory - Address of caller's trajectory object.
 ASSUMES: TrajectoryInit() has been called.  TrajectoryUpdate() being
    called at a steady rate.
  RETURNS: A tTRAJECTORY_STATUS value indicating the trajectory's
    present status.
  USAGE: This function is for use by mainline code in determining
    trajectory status.
*/

#endif
