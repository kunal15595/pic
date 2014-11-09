/* 
 * File:   ping.h
 * Author: kunal-laptop
 *
 * Created on October 29, 2014, 12:23 AM
 */

#ifndef PING_H
#define	PING_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "AVIX.h"
    
TAVIX_THREAD_REGULAR ping_thread(void* p);
void ping();

#ifdef	__cplusplus
}
#endif

#endif	/* PING_H */

