/*
 * File:   master.h
 * Author: shubham
 *
 * Created on October 30, 2014, 9:52 PM
 */

#ifndef MASTER_H
#define	MASTER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "AVIX.h"
#include "std_int.h"
#define WIDTH 20
#define HEIGHT 20

TAVIX_THREAD_REGULAR master_thread(void* p);


#ifdef	__cplusplus
}
#endif

#endif	/* MASTER_H */

