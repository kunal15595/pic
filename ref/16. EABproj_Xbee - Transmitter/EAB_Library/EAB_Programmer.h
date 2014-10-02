/*******************************************************************************
[File]          : EAB_Programmer.h
[Dependencies]  : xc.h, EAB_Definitions.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : macros, enums, structures, functions ONLY for ease of PROGRAMMER.
				  none of these are to be used as API.
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com      LEAP from v1.0
*******************************************************************************/

#ifndef EAB_PROGRAMMER_H
#define	EAB_PROGRAMMER_H

/*** INCLUDE DEPENDENCIES ***/
#include <xc.h>
#include "EAB_Definitions.h"

/*** OSCILLATOR CONFIGURATION SETTINGS ***/
#define OSCCON_CLR          0b10001100
#define INTERNAL_31_25KHZ   0b00000010
#define INTERNAL_250KHZ     0b00010010
#define INTERNAL_500KHZ     0b00100010
#define INTERNAL_1MHZ       0b00110010
#define INTERNAL_2MHZ       0b01000010
#define INTERNAL_4MHZ       0b01010010
#define INTERNAL_8MHZ       0b01100010
#define INTERNAL_16MHZ      0b01110010
#define PRIMARY_8MHZ        0b01100000
#define PRIMARY_16MHZ       0b01110000

/********************************OSCILLATOR************************************/
/*** ENUM FOR FREQUENCY INDEX ***/
 typedef enum
{
    FREQ_31_25KHZ,
    FREQ_250KHZ,
    FREQ_500KHZ,
    FREQ_1MHZ,
    FREQ_2MHZ,
    FREQ_4MHZ,
    FREQ_8MHZ,
    FREQ_16MHZ,
    FREQ_32MHZ,
    FREQ_64MHZ
}FREQ_ENUM;
extern  FREQ_ENUM   OscFreqIndex;
/******************************************************************************/
/**************************TIMER*************************************************/
typedef struct
{   unsigned PRESCALER_2:1;
    unsigned PRESCALER_4:1;
    unsigned PRESCALER_8:2;
    unsigned PRESCALER_16:2 ;
    unsigned PRESCALER_32:3 ;
    unsigned PRESCALER_64:3 ;
    unsigned PRESCALER_128:3 ;
    unsigned PRESCALER_256:3 ;
    unsigned COUNTER_8BIT:1;
    unsigned COUNTER_16BIT:1;
}TIMER0CONFIG_STRUCT;

typedef struct
{
    unsigned PRESCALER_1:1;
    unsigned PRESCALER_2:1;
    unsigned PRESCALER_4:2;
    unsigned PRESCALER_8:2;
}TIMER1CONFIG_STRUCT;

typedef struct
{   unsigned PRESCALER_1 :1 ;
    unsigned PRESCALER_4 :1 ;
    unsigned PRESCALER_16:2 ;
    unsigned POSTSCALER_1:1;
    unsigned POSTSCALER_2:1;
    unsigned POSTSCALER_3:2;
    unsigned POSTSCALER_4:2;
    unsigned POSTSCALER_5:3 ;
    unsigned POSTSCALER_6:3 ;
    unsigned POSTSCALER_7:3 ;
    unsigned POSTSCALER_8:3 ;
    unsigned POSTSCALER_9:4 ;
    unsigned POSTSCALER_10:4;
    unsigned POSTSCALER_11:4 ;
    unsigned POSTSCALER_12:4 ;
    unsigned POSTSCALER_13:4 ;
    unsigned POSTSCALER_14:4 ;
    unsigned POSTSCALER_15:4 ;
    unsigned POSTSCALER_16:4 ;
}TIMER2CONFIG_STRUCT;
/******************************************************************************/
/********************************INTERRUPTS************************************/
 #define  Enable_GlobalInterrupt (RCONbits.IPEN   = 1, INTCONbits.GIE  = 1, INTCONbits.GIEL = 1)
/******************************************************************************/
/********************************I2C*******************************************/
/*** READ & WRITE MASK ***/
#define I2C_Read      		0x01			// I2C Read mask
#define I2C_Write     		0x00			// I2C Write mask
/******************************************************************************/

#endif	/* EAB_PROGRAMMER_H */

