/*******************************************************************************
[File]          : EAB_CONFIGbits.h
[Dependencies]  : none
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : Select the Default configuration bits.
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com      LEAP from v1.0
*******************************************************************************/

#ifndef EAB_CONFIGBITS_H
#define	EAB_CONFIGBITS_H

/*----------------------------------------------------------------------------*/
/*** CONFIGURATION BITS ***/
//#pragma config FOSC   = HSMP	// Primary oscillator source is external Crystal(8MHZ)
#pragma config FOSC   = INTIO7	// Primary oscillator source is Internal RC oscillator(1MHZ)
#pragma config WDTEN  = OFF     // Watchdog Timer Disable
#pragma config LVP    = OFF     // Single-Supply ICSP Enable bit if MCLRE is 1
#pragma config DEBUG  = OFF     // Background Debug Disable
/*----------------------------------------------------------------------------*/

#endif	/* EAB_CONFIGBITS_H */

