/*
********************************************************************************
[File]          : ELB_PWM.h
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : ELB PWM configuration functions
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR]                            CHANGES
 v0.1	   	24.10.2012 	shashi.prakash@brigosha.com         Origin
********************************************************************************
*/

#ifndef ELB_PWM_H
#define	ELB_PWM_H

#include <p24fj256gb206.h>

#include "Define.h"
#include "ELB_OSC.h"

/*** MACROS FOR PWM TIMER SOURCE SELECTION ***/
#define PWMsrc_Timer2 0b00000000
#define PWMsrc_Timer3 0b00000001
#define PWMsrc_Timer4 0b00000010
#define PWMsrc_Timer5 0b00000011
#define PWMsrc_Timer1 0b00000100
#define PWMsrc_FOSC   0b00000111


/*** PUBLIC APIs ***/
void PWM1_INIT(U8 , F32 );
void PWM1_SET_PulseWidth(F32 );

void PWM2_INIT(U8 , F32 );
void PWM2_SET_PulseWidth(F32 );

void PWM3_INIT(U8 , F32 );
void PWM3_SET_PulseWidth(F32 );

void PWM4_INIT(U8 , F32 );
void PWM4_SET_PulseWidth(F32 );

#endif	/* ELB_PWM_H */

