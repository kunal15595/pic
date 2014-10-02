/*******************************************************************************
[File]          : EAB_Definitions.h
[Dependencies]  : stdio.h, stdlib.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : Data type definitions, other generic constants, delays, bit operations .
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com      LEAP from v1.0
*******************************************************************************/

#ifndef EAB_DEFINITIONS_H
#define	EAB_DEFINITIONS_H

/*** INCLUDE DEPENDENCIES ***/
#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------*/
/*** DATATYPE DEFINITIONS ***/
typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

#define SUCCESS         1           //Task completed
#define FAILURE         -1          //Task couldn't be completed

uint delayCount = 0;
#define DelayMicrosec(x) _delay((unsigned int)((x)*(SYS_CLK/4000000.0)))
#define DelayMillisec(x)  for(delayCount = 0; delayCount< x;delayCount++)\
                           DelayMicrosec(1000);
/*----------------------------------------------------------------------------*/

#endif	/* EAB_DEFINITIONS_H */

