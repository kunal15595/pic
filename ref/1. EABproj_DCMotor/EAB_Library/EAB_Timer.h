/*******************************************************************************
[File]          : EAB_Timer.h
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Programmer.h, EAB_Oscillator.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : Functions to configure the Timers with fixed period or variable
                  periods. Also enable the interrupts for the timer.
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com       LEAP from v1.0
*******************************************************************************/

#ifndef EAB_TIMER_H
#define	EAB_TIMER_H

/*** INCLUDE DEPENDENCIES ***/
#include <xc.h>
#include "EAB_Definitions.h"
#include "EAB_Programmer.h"
#include "EAB_Oscillator.h"

/*----------------------------------------------------------------------------*/
typedef struct
{
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Timer0 period 1 second, <b> AVAILABLE at</b>  ALL Oscillator frequencies </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer0.SetPeriod_1Sec();</code></td></tr> </table> */
    char (*SetPeriod_1Sec)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Timer0 period 130 millisecond, <b> AVAILABLE at</b>  ALL Oscillator frequencies </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer0.SetPeriod_130milliSec();</code></td></tr> </table> */
    char (*SetPeriod_130milliSec)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Timer0 period 16 millisecond, <b> NOT AVAILABLE at </b> 31.25 KHZ </td> </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer0.SetPeriod_16milliSec();</code></td></tr> </table> */
    char (*SetPeriod_16milliSec)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Timer0 period 1 millisecond, <b> NOT AVAILABLE at </b> 31.25 KHZ, 250KHZ, 500KHZ, 1MHZ </td>  </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer0.SetPeriod_1milliSec();</code></td></tr> </table> */
    char (*SetPeriod_1milliSec)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>sets Timer0 period, see Period calculation </td>  </td></tr>
    *           <tr><td><b>Input    </b></td>  <td><i>PRESCALER_xx</i> [2,4,8...,128,256] </td></tr>
    *           <tr><td>                </td>  <td><i>COUNTER_xx</i>  [8BIT or 16BIT] </td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer0.SetPeriod(Timer0.config.PRESCALER_16, Timer0.config.COUNTER_16BIT);</code></td></tr>
    *           <tr><td><b>Period   </b></td>  <td> = (4/SYS_CLK)*PRESCALER*(2^8 OR 2^16) </td></tr> </table> */
    char (*SetPeriod)(uchar,uchar);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Timer0 Interrupt, Capture the Timer0 expire event in the HighPriority_InterruptHandler(), <i> its default interrupt priority is HIGH</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer0.EnableInterruptHIGH(); </code></td></tr> </table> */
    char (*EnableInterruptHIGH)(void);
    /**<table>  <tr><td><b>Structure</b></td>   <td> Confiuration settings for  Timer0 </td>   </tr>
    *           <tr><td><b>Fields   </b></td>   <td><i>PRESCALER_xx</i>[2,4,8...,128,256] </td></tr>
    *           <tr><td>                </td>   <td><i>COUNTER_xx</i> [8BIT or 16BIT] </td></tr>
    *           <tr><td><b>Example  </b></td>   <td> <code> Timer0.config.PRESCALER_32, \n Timer0.config.COUNTER_16BIT </code></td> </tr> </table> */
    TIMER0CONFIG_STRUCT config;
}TIMER0_STRUCT;

typedef struct
{
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Timer1 period, see Period calculation </td>  </td></tr>
    *           <tr><td><b>Input    </b></td>  <td><i>PRESCALER_xx</i> [1,2,4,8] </td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer1.SetPeriod(Timer1.config.PRESCALER_4);</code></td></tr>
    *           <tr><td><b>Period   </b></td>  <td> = (4/SYS_CLK)*PRESCALER*(65536) </td></tr> </table> */
    char(*SetPeriod)(uchar);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Timer1 Interrupt, Capture the Timer1 expire event in the HighPriority/LowPriority_InterruptHandler()</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Interrupt Prioiry [HIGH or LOW]</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer1.EnableInterrupt(HIGH); </code></td></tr> </table> */
    char(*EnableInterrupt)(uchar);
    /**<table>  <tr><td><b>Structure</b></td>   <td> Confiuration settings for  Timer1 </td>   </tr>
    *           <tr><td><b>Fields   </b></td>   <td><i>PRESCALER_xx</i>[1,2,4,8] </td></tr>
    *           <tr><td><b>Example  </b></td>   <td> <code> Timer1.config.PRESCALER_4 </code></td> </tr> </table> */
    TIMER1CONFIG_STRUCT config;
}TIMER1_STRUCT;

typedef struct
{
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Timer2 period at 1 milli seconds, <b> AVAILABLE  </b> at ALL Oscillator frequencies</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer2.SetPeriod_1milliSec(); </code></td></tr> </table> */
    char (*SetPeriod_1milliSec)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Sets Timer2 at 100 micro seconds, <b> NOT AVAILABLE  </b> at <code>31.25KHZ</code> oscillator frequency</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer2.SetPeriod_100microSec(); </code></td></tr> </table> */
    char (*SetPeriod_100microSec)(void);
    /**<table>  <tr><td><b>Function </b></td>   <td> sets Timer2 period, see Period calculation </td> </tr>
    *           <tr><td><b>Input    </b></td>   <td><i>PRESCALER_xx</i>[1,4,16]</td></tr>
    *           <tr><td>                </td>   <td><i>POSTSCALER_xx</i>[1,2,3,...,15,16]</td></tr>
    *           <tr><td>                </td>   <td><i>counter</i> [0,1,2,3...254,255] </td></tr>
    *           <tr><td><b>Return   </b></td>   <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>   <td> <code> Timer2.SetPeriod(Timer2.config.PRESCALER_16, Timer2.config.POSTSCALER_10, 200);</code></td>   </tr>
    *           <tr><td><b>Period   </b></td>   <td> = (4/OSC FREQ)*PRESCALER*POSTSCALER*COUNTER </td></tr> </table> */
    char (*SetPeriod)(uchar, uchar,uchar);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Timer2 Interrupt, Capture the Timer1 expire event in the HighPriority/LowPriority_InterruptHandler()</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Interrupt Prioiry [HIGH or LOW]</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Timer2.EnableInterrupt(LOW); </code></td></tr> </table> */
    char(*EnableInterrupt)(uchar);
    /**<table>  <tr><td><b>Structure</b></td>   <td>Confiuration settings for  Timer2 </td></tr>
    *           <tr><td><b>Fields   </b></td>   <td><i>PRESCALER_xx</i> [1,4,16]    </td></tr>
    *           <tr><td>            </b></td>   <td><i>POSTSCALER_xx</i>[1,2,3...,15,16] </td></tr>
    *           <tr><td><b>Example  </b></td>   <td> <code> Timer2.config.PRESCALER_10, \n Timer2.config.POSTSCALER_4 </code></td> </tr></table> */
    TIMER2CONFIG_STRUCT config;
}TIMER2_STRUCT ;

/*----------------------------------------------------------------------------*/
/*** GLOBAL VARIABLES ***/
extern const TIMER0_STRUCT Timer0;
extern const TIMER1_STRUCT Timer1;
extern const TIMER2_STRUCT Timer2;

/*** MACROS FOR TIMER INTERRUPT FLAGS ***/
#define Timer0_Flag INTCONbits.TMR0IF
#define Timer1_Flag PIR1bits.TMR1IF
#define Timer2_Flag PIR1bits.TMR2IF
#define Timer3_Flag PIR2bits.TMR3IF
#define Timer4_Flag PIR5bits.TMR4IF
#define Timer5_Flag PIR5bits.TMR5IF
#define Timer6_Flag PIR5bits.TMR6IF
/*----------------------------------------------------------------------------*/

#endif	/* EAB_TIMER_H */

