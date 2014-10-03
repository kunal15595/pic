/* 
 * File:   ELB_OSC.h
 * Author: Shashu
 *
 * Created on 10 October, 2012, 2:45 PM
 */

#ifndef ELB_OSC_H
#define	ELB_OSC_H

#include <stdio.h>
#include <stdlib.h>
#include <p24FJ256GB206.h>

#include "Define.h"

/*** Macros for Settign Freq ***/

#define PLL_32MHZ       0b00000000
#define PLL_16MHZ       0b00000001
#define PLL_8MHZ        0b00000010
#define PLL_4MHZ        0b00000011

#define FRCDIV_8MHZ     0b00001000
#define FRCDIV_4MHZ     0b00010000
#define FRCDIV_2MHZ     0b00100000
#define FRCDIV_1MHZ     0b00110000
#define FRCDIV_500KHZ   0b01000000
#define FRCDIV_250KHZ   0b01010000
#define FRCDIV_125KHZ   0b01100000
#define FRCDIV_31_25KHZ 0b01110000

void SET_FreqOsc(U8);

S32 GET_FreqOsc(void);



#endif	/* ELB_OSC_H */

