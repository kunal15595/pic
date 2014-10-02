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
[File]          : ELB_LCD.c
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : Macros and functions for LCD communication
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR] 				CHANGES
 v0.1	   	30.12.2012 	gopal.jatiya@brigosha.com		Origin
********************************************************************************
*/

#ifndef ELB_LCD_H
#define	ELB_LCD_H

/*** BRIGOSHA LIBRARY ***/
#include "ELB_OSC.h"
#include "ELB_I2C.h"

/*** MACROS FOR LCD COMMANDS AND COMMUNICATION ***/
#define C_LCD_I2CAdress     0x3E
#define C_CommandAdr        0x00
#define C_DataAddr          0x40
#define C_NewLine           0xC0
#define C_DisplayCLR        0x01
#define C_DisplayHome       0x02

/*** PUBLIC APIs ***/
void INIT_LCD(void);
void LCD_WriteString(U8 ,U8 ,U8 *);
void LCD_Clear(void);

#endif	/* CONFIG_LCD_H */

