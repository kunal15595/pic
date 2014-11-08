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
#include "imu.h"
#include "servo.h"
#include "xbee.h"
#include "motor.h"
#include "ping.h"
#include "stdbool.h"

#define WIDTH 10
#define HEIGHT 10

struct coordinate{
    int x,y;
};



TAVIX_THREAD_REGULAR master_thread(void* p);


enum node_type{
    FREE,
    WALL,
    PATH
};

void set_map(uint32_t x,uint32_t y,enum node_type);
uint8_t inline get_map(uint32_t x,uint32_t y);

#ifdef	__cplusplus
}
#endif

#endif	/* MASTER_H */

