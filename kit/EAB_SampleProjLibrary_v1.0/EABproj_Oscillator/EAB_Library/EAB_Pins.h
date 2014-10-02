/*******************************************************************************
[File]          : EAB_Pins.h
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Programmer.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : Defintions for configuring pins to be used as ANALOG or DIGITAL
				  Functions for enabling external interrupts and Interrupt On Change(IOC)  
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com      LEAP from v1.0
*******************************************************************************/

#ifndef EAB_PINS_H
#define	EAB_PINS_H

/*** INCLUDE DEPENDENCIES ***/
#include <xc.h>
#include "EAB_Definitions.h"
#include "EAB_Programmer.h"

/*----------------------------------------------------------------------------*/
typedef struct
{   /** RA0 /<b> AN0</b> */
     unsigned AN0:1;
    /** RA1 /<b> AN1</b> */
    unsigned AN1:1;
    /** RA2 /<b> AN2</b> */
    unsigned AN2:1;
    /** RA3 /<b> AN3</b> */
    unsigned AN3:1 ;
    /** RA4 /<b> CCP5</b> */
    unsigned PWM5:1 ;
    /** <b>RA5</b> / AN4 / SS1*/
    unsigned RA5:1 ;
    unsigned :2 ;
    /** RB0 / AN12 / CCP4 / <b>SS2</b> / INT0 */
    unsigned SS2:1;
    /** RB1 / AN10 / <b>SCK2</b> / SCL2 / INT1 */
    unsigned SCK2:1;
    /** RB2 / AN8 / <b>SDI2</b> / SDA2 / INT2 */
    unsigned SDI2:1;
    /** RB3 / AN9 / <b>SDO2</b> */
    unsigned SDO2:1 ;
    /** <b>RB4</b> / AN11 / IOC */
    unsigned RB4:1 ;
    /** RB5 / AN13 / <b>CCP3</b> / IOC */
    unsigned PWM3:1 ;
    /** RB6 / <b>TX2</b> / IOC / PGC */
    unsigned TX2:1 ;
    /** RB7 / <b>RX2</b> / IOC / PGD */
    unsigned RX2:1 ;
    /** <b>RC0</b> */
    unsigned RC0:1;
    /** RC1 / <b>CCP2</b> */
    unsigned PWM2:1;
    /** RC2 / AN14 / <b>CCP1</b> */
    unsigned PWM1:1;
    /** RC3 / AN15 / <b>SCL1</b> / SCK1 */
    unsigned SCL1:1 ;
    /** RC4 / AN16 / <b>SDA1</b> / SDI1 */
    unsigned SDA1:1 ;
    /** <b>RC5</b> / AN17 / SDO1 */
    unsigned RC5:1 ;
    /** RC6 / AN18 / <b>TX1</b>  */
    unsigned TX1:1 ;
    /** RC7 / AN19 / <b>RX1</b>  */
    unsigned RX1:1 ;
}DIGITALPINS_STRUCT;

typedef struct
{   /** RA0 /<b> AN0</b> */
     unsigned AN0:1;
    /** RA1 /<b> AN1</b> */
    unsigned AN1:1;
    /** RA2 /<b> AN2</b> */
    unsigned AN2:1;
    /** RA3 /<b> AN3</b> */
    unsigned AN3:1 ;
    unsigned    :1 ;
    /** <b>RA5</b> / AN4 / SS1*/
    unsigned RA5:1 ;
    unsigned    :2 ;
    /** RB0 / AN12 / CCP4 / <b>SS2</b> / INT0 */
    unsigned SS2:1;
    /** RB1 / AN10 / <b>SCK2</b> / SCL2 / INT1 */
    unsigned SCK2:1;
    /** RB2 / AN8 / <b>SDI2</b> / SDA2 / INT2 */
    unsigned SDI2:1;
    /** RB3 / AN9 / <b>SDO2</b> */
    unsigned SDO2:1 ;
    /** <b>RB4</b> / AN11 / IOC */
    unsigned RB4:1 ;
    /** RB5 / AN13 / <b>CCP3</b> / IOC */
    unsigned PWM3:1 ;
    unsigned     :4 ;
    /** RC2 / AN14 / <b>CCP1</b> */
    unsigned PWM1:1;    
    /** RC3 / AN15 / <b>SCL1</b> / SCK1 */
    unsigned SCL1:1 ;
    /** RC4 / AN16 / <b>SDA1</b> / SDI1 */
    unsigned SDA1:1 ;
    /** <b>RC5</b> / AN17 / SDO1 */
    unsigned RC5:1 ;
    /** RC6 / AN18 / <b>TX1</b>  */
    unsigned TX1:1 ;
    /** RC7 / AN19 / <b>RX1</b>  */
    unsigned RX1:1 ;
}ANALOGPINS_STRUCT;

typedef struct
{
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Interrupt for INT0 connected to SS2 pin. </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Edge on which Interrupt should occur [RISING_EDGE or FALLING_EDGE]</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>ExternalInt.EnableINT0_SS2(RISING_EDGE); </code></td></tr> </table> */
    char (*EnableINT0_SS2)(uchar);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Interrupt for INT1 connected to SCK2 pin. </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Edge on which Interrupt should occur [RISING_EDGE or FALLING_EDGE]</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>ExternalInt.EnableINT1_SCK2(FALLING_EDGE); </code></td></tr> </table> */
    char (*EnableINT1_SCK2)(uchar);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Interrupt for INT2 connected to SDI2 pin. </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Edge on which Interrupt should occur [RISING_EDGE or FALLING_EDGE]</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>ExternalInt.EnableINT2_SDI2(FALLING_EDGE); </code></td></tr> </table> */
    char (*EnableINT2_SDI2)(uchar);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the IOC on pin connected to RB4. This will cause Interrupt on both the edges </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>ExternalInt.EnableIOC_RB4(); </code></td></tr> </table> */
    char (*EnableIOC_RB4)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the IOC on pin connected to PWM3. This will cause Interrupt on both the edges </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>ExternalInt.EnableIOC_PWM3(); </code></td></tr> </table> */
    char (*EnableIOC_PWM3)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Interrupt for INT0, capture the INT0 event in the HighPriority_InterruptHandler(), The default priority for INT0 is high</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>None</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>ExternalInt.EnableINT0interruptHIGH(); </code></td></tr> </table> */
    char (*EnableINT0interruptHIGH)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Interrupt for INT1, capture the INT1 event in the HighPriority/LowPriority_InterruptHandler()</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Interrupt Prioiry [HIGH or LOW]</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>ExternalInt.EnableINT1interrupt(LOW); </code></td></tr> </table> */
    char (*EnableINT1interrupt)(uchar);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Interrupt for INT2, capture the INT2 event in the HighPriority/LowPriority_InterruptHandler()</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Interrupt Prioiry [HIGH or LOW]</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>ExternalInt.EnableINT2interrupt(LOW); </code></td></tr> </table> */
    char (*EnableINT2interrupt)(uchar);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Interrupt for IOC, capture the IOC event in the HighPriority/LowPriority_InterruptHandler()</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Interrupt Prioiry [HIGH or LOW]</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>ExternalInt.EnableIOCinterrupt(LOW); </code></td></tr> </table> */
    char (*EnableIOCinterrupt)(uchar);
}EXTERNALINT_STRUCT;

/*----------------------------------------------------------------------------*/
/*** GLOBAL VARIABLES ***/
extern volatile DIGITALPINS_STRUCT PinRead      @ 0xF80;    // PORTA, PORTB, PORTC
extern volatile DIGITALPINS_STRUCT PinWrite     @ 0xF89;    // LATA,  LATB,  LATC
extern volatile DIGITALPINS_STRUCT PinDirection @ 0xF92;    // TRISA, TRISB, TRISC
extern volatile DIGITALPINS_STRUCT  PinFunction  @ 0xF38;    // ANSELA,ANSELB,ANSELC
extern EXTERNALINT_STRUCT ExternalInt;

/*** MACROS FOR CONFIGURATION ***/
#define ANALOG          1                   // Set Pin Function
#define DIGITAL         0                   // Set Pin Function
#define OUTPUT          0                   // Set Pin Direction
#define INPUT           1                   // Set Pin Direction
#define HIGH            1                   // Digital High or 1
#define LOW             0                   // Digital Low  or 0
#define RISING_EDGE     1                   // Inerrupt will occur on transtion from LOW to HIGH
#define FALLING_EDGE    0                   // Interrupt will occur on transtion form HIGH to LOW

/*** INTERRUPT FLAGS ***/
#define INT0_Flag       INTCONbits.INT0IF   //Interrupt flag for external INT0
#define INT1_Flag       INTCON3bits.INT1IF  //Interrupt flag for external INT1
#define INT2_Flag       INTCON3bits.INT2IF  //Interrupt flag for external INT2
#define IOC_Flag        INTCONbits.RBIF     //Interrupt flag for IOC on RB port

/*** MACRO FUNCTIONS ***/
#define PinToggle(pin)      (PinWrite.##pin =!PinWrite.##pin)         //Change the Pin state between HIGH/LOW
#define PinDigitalOut(pin)  (PinFunction.##pin = DIGITAL, PinDirection.##pin = OUTPUT )
#define PinDigitalIn(pin)   (PinFunction.##pin = DIGITAL, PinDirection.##pin = INPUT )
#define PinAnalogOut(pin)   (PinFunction.##pin = ANALOG, PinDirection.##pin = OUTPUT )
#define PinAnalogIn(pin)    (PinFunction.##pin = ANALOG, PinDirection.##pin = INPUT )
/*----------------------------------------------------------------------------*/

#endif	/* PINS_H */

