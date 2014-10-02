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
[File]          : Config_UART.h
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLAB C30
[Description]   : Macros and functions for UART
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR] 			CHANGES
 v0.1		07.10.2011	shashi.prakash@brigosha.com	Modified for PIC24F
********************************************************************************
*/
#ifndef __CONFIG_UART_H
#define __CONFIG_UART_H
 
#include "p24Fxxxx.h"
#include "p24FJ256GB206.h"

#include "Define.h"
#include "ELB_Osc.h"


/*** BAUD RATE MACROS ***/
#define M_300Hz     (S32)300
#define M_1200Hz    (S32)1200
#define M_2400Hz    (S32)2400
#define M_9600Hz    (S32)9600
#define M_10417Hz   (S32)10417
#define M_19_2KHz   (S32)19200
#define M_57_6KHz   (S32)57600
#define M_115_2KHz  (S32)115200

/*** BAUD RATE CONFIG MACROS ***/
#define M_BRGH_High   1
#define M_BRGH_Low    0

/*** INTERRUPT OPTIONS ***/
#define TX_INT_PRI0     0b10000000
#define TX_INT_PRI1     0b10010000
#define TX_INT_PRI2     0b10100000
#define TX_INT_PRI3     0b10110000
#define TX_INT_PRI4     0b11000000
#define TX_INT_PRI5     0b11010000
#define TX_INT_PRI6     0b11100000
#define TX_INT_PRI7     0b11110000

#define RX_INT_PRI0     0b00001000
#define RX_INT_PRI1     0b00001001
#define RX_INT_PRI2     0b00001010
#define RX_INT_PRI3     0b00001011
#define RX_INT_PRI4     0b00001100
#define RX_INT_PRI5     0b00001101
#define RX_INT_PRI6     0b00001110
#define RX_INT_PRI7     0b00001111

#define NO_INT_PRI0     0b00000000

/*** PUBLIC APIs ***/
S8 UART1_INIT(S32, U8, U8);
S8 UART2_INIT(S32, U8, U8);

void UART1_SEND_String(U8 *, U8);
void UART2_SEND_String(U8 *, U8);


#endif // End of header file UART_CONFIG.h

