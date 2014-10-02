/*******************************************************************************
[File]          : EAB_Oscillator.h
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Programmer.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : Functions to configure the system clock.
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com      LEAP from v1.0
*******************************************************************************/

#ifndef EAB_OSCILLATOR_H
#define	EAB_OSCILLATOR_H

/*** INCLUDE DEPENDENCIES ***/
#include <xc.h>
#include "EAB_Definitions.h"
#include "EAB_Programmer.h"

/*----------------------------------------------------------------------------*/
typedef struct
{
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Oscillator Frequency at 31.25KHZ</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Oscillator.SetFreq_31KHZ();</code></td></tr> </table> */
    char (*SetFreq_31KHZ)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Oscillator Frequency at 250KHZ</td></tr>
     *          <tr><td><b>Input    </b></td>  <td>None</td></tr>
     *          <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
     *          <tr><td><b>Example  </b></td>  <td><code>Oscillator.SetFreq_250KHZ();</code></td></tr> </table> */
    char (*SetFreq_250KHZ)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Oscillator Frequency at 500KHZ</td></tr>
     *          <tr><td><b>Input    </b></td>  <td>None</td></tr>
     *          <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
     *          <tr><td><b>Example  </b></td>  <td><code>Oscillator.SetFreq_500KHZ();</code></td></tr> </table> */
    char (*SetFreq_500KHZ)(void);
    /** <table> <tr><td><b>Function </b></td>  <td>Sets Oscillator Frequency at 1MHZ</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Oscillator.SetFreq_1MHZ();</code></td></tr> </table> */
    char (*SetFreq_1MHZ)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Oscillator Frequency at 2MHZ</td> </tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Oscillator.SetFreq_2MHZ();</code></td></tr> </table> */
    char (*SetFreq_2MHZ)(void);
    /** <table> <tr><td><b>Function </b></td>  <td>Sets Oscillator Frequency at 4MHZ</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Oscillator.SetFreq_4MHZ();</code></td></tr> </table> */
    char (*SetFreq_4MHZ)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Oscillator Frequency at 8MHZ</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Oscillator.SetFreq_8MHZ();</code></td></tr> </table> */
   char (*SetFreq_8MHZ)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Oscillator Frequency at 16MHZ</td></tr>
     *          <tr><td><b>Input    </b></td>  <td>None</td></tr>
     *          <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
     *          <tr><td><b>Example  </b></td>  <td><code>Oscillator.SetFreq_16MHZ();</code></td></tr> </table> */
   char (*SetFreq_16MHZ)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Oscillator Frequency at 32MHZ</td></tr>
     *          <tr><td><b>Input    </b></td>  <td>None</td></tr>
     *          <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
     *          <tr><td><b>Example  </b></td>  <td><code>Oscillator.SetFreq_32MHZ();</code></td></tr> </table> */
    char (*SetFreq_32MHZ)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Oscillator Frequency at 64MHZ, <b> NOT AVAILABLE with </b> External Crystal </td></tr>
     *          <tr><td><b>Input    </b></td>  <td>None</td></tr>
     *          <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
     *          <tr><td><b>Example  </b></td>  <td><code>Oscillator.SetFreq_64MHZ();</code></td></tr> </table> */
    char (*SetFreq_64MHZ)(void);
    /**<table>  <tr><td><b>Function </b></td>   <td>Returns Oscillator Frequency </td></tr>
     *          <tr><td><b>Input    </b></td>   <td>None</td></tr>
     *          <tr><td><b>Return   </b></td>   <td>Current oscillator frequency</td></tr>
     *          <tr><td><b>Example  </b></td>   <td> <code> long y;\n y = Oscillator.GetFreq();</code></td>   </tr> </table> */
    long (*GetFreq)(void);
}OSCILLATOR_STRUCT;

/*----------------------------------------------------------------------------*/
/*** GLOBAL VARIABLES ***/
 extern  OSCILLATOR_STRUCT  Oscillator;
 /*----------------------------------------------------------------------------*/

#endif	/* EAB_OSCILLATOR_H */





