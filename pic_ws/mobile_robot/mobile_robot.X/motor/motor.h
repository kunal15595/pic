/* 
 * File:   motor.h
 * Author: kunal-laptop
 *
 * Created on October 29, 2014, 12:30 AM
 */

#ifndef MOTOR_H
#define	MOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "AVIX.h"

TAVIX_THREAD_REGULAR motor_thread(void* p);


#ifdef	__cplusplus
}
#endif

#endif	/* MOTOR_H */

