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
[File]          : ELB_I2C.h
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : I2C Macros and functions for communication
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR]                            CHANGES
 v0.1	   	28.09.2012 	shashi.prakash@brigosha.com         Origin
********************************************************************************
*/

#ifndef ELB_I2C_H
#define	ELB_I2C_H

#define USE_AND_OR

/*** MICROCHIP LIBRARY ***/
#include <i2c.h>

/*** BRIGOSHA LIBRARY ***/
#include "Define.h"
#include "ELB_Osc.h"

/*** BAUD RATE OPTIONS ***/
#define M_FSCL_FastMode       400000
#define M_FSCL_StandardMode   100000

/*** READ WRITE MASK ***/
#define M_I2C_Read              0x01		/* I2C Read mask */
#define M_I2C_Write             0x00		/* I2C Write mask */

/**** INTERRUPT OPTIONS ***/
// Master interrupt
#define MI2C_INT_PRI0     0b10000000
#define MI2C_INT_PRI1     0b10010000
#define MI2C_INT_PRI2     0b10100000
#define MI2C_INT_PRI3     0b10110000
#define MI2C_INT_PRI4     0b11000000
#define MI2C_INT_PRI5     0b11010000
#define MI2C_INT_PRI6     0b11100000
#define MI2C_INT_PRI7     0b11110000
// Slave interrupt
#define SI2C_INT_PRI0     0b00001000
#define SI2C_INT_PRI1     0b00001001
#define SI2C_INT_PRI2     0b00001010
#define SI2C_INT_PRI3     0b00001011
#define SI2C_INT_PRI4     0b00001100
#define SI2C_INT_PRI5     0b00001101
#define SI2C_INT_PRI6     0b00001110
#define SI2C_INT_PRI7     0b00001111

/*** PUBLIC APIs ***/
 void I2C1_INIT(S32, U8);
 void I2C2_INIT(S32, U8);
 void I2C3_INIT(S32, U8 );

 S8 I2C1_WRITE_String(U8, U8, U8 *, U8);
 S8 I2C2_WRITE_String(U8, U8, U8 *, U8);
 S8 I2C3_WRITE_String(U8, U8, U8 *, U8);

 S8 I2C1_READ_String( U8, U8, U8 *, U8);
 S8 I2C2_READ_String( U8, U8, U8 *, U8);
 S8 I2C3_READ_String( U8, U8, U8 *, U8);

#define I2C1_WRITE_Byte(DevAdd, RegAdd, RegValue)  I2C1_WRITE_String(DevAdd, RegAdd, RegValue, 1)
#define I2C2_WRITE_Byte(DevAdd, RegAdd, RegValue)  I2C2_WRITE_String(DevAdd, RegAdd, RegValue, 1)
#define I2C3_WRITE_Byte(DevAdd, RegAdd, RegValue)  I2C3_WRITE_String(DevAdd, RegAdd, RegValue, 1)

#define I2C1_READ_Byte(DevAdd, RegAdd, RegValue)  I2C1_READ_String(DevAdd, RegAdd, RegValue, 1)
#define I2C2_READ_Byte(DevAdd, RegAdd, RegValue)  I2C2_READ_String(DevAdd, RegAdd, RegValue, 1)
#define I2C3_READ_Byte(DevAdd, RegAdd, RegValue)  I2C3_READ_String(DevAdd, RegAdd, RegValue, 1)


#endif	/* ELB_I2C_H */

