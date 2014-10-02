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
[File]          : ELB_Timer.h
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : ELB Timer configuration Macros and Functions definitions
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR]                            CHANGES
 v0.1	   	17.10.2012 	shashi.prakash@brigosha.com         Origin
********************************************************************************
*/

#ifndef ELB_TIMER_H
#define	ELB_TIMER_H

#include <p24FJ256GB206.h>
#include "Define.h"
#include "ELB_Osc.h"

/**** INTERRUPT OPTIONS ***/
#define TMR_INT_PRI0     0b00001000
#define TMR_INT_PRI1     0b00001001
#define TMR_INT_PRI2     0b00001010
#define TMR_INT_PRI3     0b00001011
#define TMR_INT_PRI4     0b00001100
#define TMR_INT_PRI5     0b00001101
#define TMR_INT_PRI6     0b00001110
#define TMR_INT_PRI7     0b00001111

/*** PUBLIC APIs ***/
void TIMER1_INIT(F32 , U8);
void TIMER2_INIT(F32 , U8);
void TIMER3_INIT(F32 , U8);

void TIMER23_INIT(F32 , U8);
void TIMER45_INIT(F32 , U8);

#endif	/* ELB_TIMER_H */

