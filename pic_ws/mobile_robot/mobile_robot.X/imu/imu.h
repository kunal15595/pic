/* 
 * File:   imu.h
 * Author: shubham
 *
 * Created on November 6, 2014, 2:02 PM
 */

#ifndef IMU_H
#define	IMU_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "AVIX.h"
    
TAVIX_THREAD_REGULAR imu_thread(void* p);

#ifdef	__cplusplus
}
#endif

#endif	/* IMU_H */

