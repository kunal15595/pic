/*
***************************************************************************************************
[File]			: Config_UART.h
[Processor]     : PIC24F Baud rate calculation equation used.
[Compiler]      : MPLAB C30
[Description]   : UART related Macros and function deffinitions.        
--------------------------------------------------------------------------------------------------- 	
[VERSION]	[DATE]   	[AUTHOR] 							CHANGES
 v1.0	   	22.12.2010 	shashi.prakash@brigosha.com			Origin, written for PIC32
 v2.0		07.10.2011	shashi.prakash@brigosha.com			Modified for PIC24F
***************************************************************************************************
*/ 
#ifndef __CONFIG_UART_H
#define __CONFIG_UART_H
 
#include "p24Fxxxx.h"
#include "p24FJ256GB206.h"

#include "Define.h"
#include "ELB_ConfigOsc.h"


/*********Baud Rate Macros*********/
#define M_300Hz     (S32)300
#define M_1200Hz    (S32)1200
#define M_2400Hz    (S32)2400
#define M_9600Hz    (S32)9600
#define M_10417Hz   (S32)10417
#define M_19_2KHz   (S32)19200
#define M_57_6KHz   (S32)57600
#define M_115_2KHz  (S32)115200

/*** BaudRate Config Macros ***/
#define M_BRGH_High   1
#define M_BRGH_Low    0

/**** Interrupt Options ***/
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

/*** Function Definitions ***/

S8 UART1_INIT(S32, U8, U8);
S8 UART2_INIT(S32, U8, U8);

void UART1_SEND_String(U8 *, U8);
void UART2_SEND_String(U8 *, U8);


#endif // End of header file UART_CONFIG.h

