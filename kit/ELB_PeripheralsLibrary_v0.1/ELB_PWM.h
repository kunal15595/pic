/*****************************************************************************
Copyright (C) 2011-12 Brigosha Technologies Private Limited
Disclaimer		: 
 Common:
 Brigosha Technologies products are developed for the consumer goods industry. They may only be used 
 within the parameters of the respective valid product data sheet.  Brigosha Technologies products are 
 provided with the express understanding that there is no warranty of fitness for a particular purpose. 
 They are not fit for use in life-sustaining, safety or security sensitive systems or any system or device 
 that may lead to bodily harm or property damage if the system or device malfunctions.


 Special:
 This software module (hereinafter called "Software") and any information on application-sheets 
 (hereinafter called "Information") is provided free of charge for the sole purpose to support your 
 application work. The Software and Information is subject to the following terms and conditions: 

 The Software is specifically designed for the exclusive use for Brigosha Technologies products by 
 personnel who have special experience and training. Do not use this Software if you do not have the 
 proper experience or training. 

 This Software package is provided `` as is `` and without any expressed or implied warranties, 
 including without limitation, the implied warranties of merchantability and fitness for a particular 
 purpose. 

 Brigosha Technologies  deny any liability for the functional impairment of this Software in terms of
 fitness, performance and safety. Brigosha Technologies shall not be liable for any direct or indirect
 damages or injury.
 
 The Information provided is believed to be accurate and reliable. Brigosha Technologies assumes no 
 responsibility for the consequences of use of such Information nor for any infringement of patents or 
 other rights of third parties which may result from its use. No license is granted by implication or 
 otherwise under any patent or patent rights of Brigosha Technologies. Specifications mentioned in the
 Information are subject to change without notice.

 It is not allowed to deliver the source code of the Software to any third party without permission of 
 Brigosha Technologies.

****************************************************************************************************/ 
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

