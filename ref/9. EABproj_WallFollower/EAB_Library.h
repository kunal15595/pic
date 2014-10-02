/*******************************************************************************
[File]          : EAB_Library.h
[Dependencies]  : Include all EAB Libray Headers
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : Include all the header files located in the EAB_Library folder.
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com       Origin
*******************************************************************************/

#ifndef EAB_LIBRARY_H
#define	EAB_LIBRARY_H

#ifndef EAB_CONFIGBITS_H    
    #include "EAB_Library/EAB_CONFIGbits.h"
#endif

#ifndef EAB_DEFINITIONS_H
#include "EAB_Library/EAB_Definitions.h"
#endif

#ifndef EAB_PINS_H
    #include "EAB_Library/EAB_Pins.h"
#endif

#ifndef EAB_OSCILLATOR_H
    #include "EAB_Library/EAB_Oscillator.h"
#endif

#ifndef EAB_TIMER_H
    #include "EAB_Library/EAB_Timer.h"
#endif

#ifndef EAB_SERIAL_H
    #include "EAB_Library/EAB_Serial.h"
#endif

#ifndef EAB_I2C_H
    #include "EAB_Library/EAB_I2C.h"
#endif

#ifndef EAB_ADC_H
    #include "EAB_Library/EAB_ADC.h"
#endif

#endif	/* EAB_LIBRARY_H */

