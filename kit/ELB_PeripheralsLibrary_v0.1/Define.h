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
[File]          : Define.h
[Version]       : v0.1
[Processor]     : PIC24F
[Compiler]      : MPLABC30
[Description]   : Datatypes and constants macros defintion
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR] 				CHANGES
 v0.1	   	23.09.2012 	shashi.prakash@brigosha.com		Origin
********************************************************************************
*/

#ifndef __DEFINE_H
#define __DEFINE_H

/*** DATA TYPES ****/
typedef char                    S8;
typedef unsigned char           U8;
typedef short                   S16;
typedef unsigned short          U16;
typedef long                    S32;
typedef unsigned long           U32;
typedef long long               S64;
typedef unsigned long long      U64;
typedef double                  F32;

/*** CONSTANTS ****/
#define C_SUCCESS 	1
#define C_FAILURE 	0

#define C_TRUE 		1
#define C_FALSE 	0

#define C_ON		1
#define C_OFF		0

/*** NUMBERS ****/
#define C_ZERO      0
#define C_ONE       1
#define C_TWO       2
#define C_THREE     3
#define C_FOUR      4
#define C_FIVE      5
#define C_SIX       6
#define C_SEVEN     7
#define C_EIGHT     8
#define C_NINE      9
#define C_TEN       10
#define C_ELEVEN    11
#define C_TWELVE    12
#define C_THIRTEEN  13
#define C_FOURTEEN  14
#define C_FIFTEEN   15
#define C_SIXTEEN   16


#endif // End of header file Define.h
















