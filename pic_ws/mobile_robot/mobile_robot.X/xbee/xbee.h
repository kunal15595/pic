/* 
 * File:   xbee.h
 * Author: kunal-laptop
 *
 * Created on October 29, 2014, 12:15 AM
 */

#ifndef XBEE_H
#define	XBEE_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdbool.h>
#include <uart.h>
#include <PPS.h>
#include <incap.h>
#include <outcompare.h>

#include "AVIX.h"
#include "Define.h"
#include "ELBv21_HardwareConfig.h"
#include "ELB_OSC.h"
#include "ELB_Timer.h"
#include "ELB_UART.h"
#include "ELB_LCD.h"

TAVIX_THREAD_REGULAR xbee_thread(void* p);
#ifdef	__cplusplus
}
#endif

#endif	/* XBEE_H */

