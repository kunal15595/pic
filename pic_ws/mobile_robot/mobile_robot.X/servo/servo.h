/* 
 * File:   servo.h
 * Author: kunal-laptop
 *
 * Created on October 29, 2014, 12:24 AM
 */

#ifndef SERVO_H
#define	SERVO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "AVIX.h"
    
TAVIX_THREAD_REGULAR servo_thread(void* p);

#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

