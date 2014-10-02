/*******************************************************************************
[File]          : EAB_Serial.h
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Programmer.h, EAB_Oscillator.h EAB_Pins.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : Functions to configure and communicate with Srial port 1 and 2.
                  Also enable the Interrupt for data recieve event.
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com      LEAP from v1.0
*******************************************************************************/

#ifndef EAB_SERIAL_H
#define	EAB_SERIAL_H

/*** INCLUDE DEPENDENCIES ***/
#include <xc.h>
#include "EAB_Definitions.h"
#include "EAB_Programmer.h"
#include "EAB_Oscillator.h"
#include "EAB_Pins.h"

/*----------------------------------------------------------------------------*/
typedef struct
{
    /**<table>  <tr><td><b>Function </b></td>  <td>Initialize the serial port with input BaudRate and default communication settings of 8-N-1.  All BaudRates are <b> NOT AVAILABLE at  </b> 31.25 KHZ,250 KHZ</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Baud Rate [300,1200, 2400, 4800, 9600, 14400,19200,28800, 38400, 57600, 115200] </td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Serial2.Open(9600);</code></td></tr> </table> */
    char (*Open)(long);
    /**<table>  <tr><td><b>Function </b></td>  <td>Send a single byte of data from the serial port </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Single byte data or a variable</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>char data = 'a'; \n Serial2.SendByte(data); OR \n  Serial2.SendByte(100); </code></td></tr> </table> */
    char (*SendByte)(char);
    /**<table>  <tr><td><b>Function </b></td>  <td>Send an array of data  upto 255 bytes from the serial port </td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Pointer to array</td></tr>
    *           <tr><td>                </td>  <td>Number of bytes to transmit</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>char ArrayData[5] = {1,2,3,4,5}; \n Serial2.SendArray(ArrayData,5); </code></td></tr> </table> */
   char (*SendArray)(char *, uchar);
   /**<table>   <tr><td><b>Function </b></td>   <td> Send a string from the serial port till the null character  </td> </tr>
   *            <tr><td><b>Input    </b></td>   <td> Pointer to string  </td> </tr>
   *            <tr><td><b>Return   </b></td>   <td> SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1] </td> </tr>
   *            <tr><td><b>Example  </b></td>   <td> <code> char StringData[] ="Hello "; \n Serial2.SendString(StringData);</code></td> </tr> </table>    */
    char (*SendString)(char *);
   /**<table>   <tr><td><b>Function </b></td>   <td> Read a byte of data from the received buffer  </tr>
   *            <tr><td><b>Input    </b></td>   <td> None   </td> </tr>
   *            <tr><td><b>Return   </b></td>   <td> Return value from received buffer </td> </tr>
   *            <tr><td><b>Example  </b></td>   <td> <code> char RcvByte; \n RcvByte = Serial2.ReadByte();</code></td> </tr> </table>    */
    char (*ReadByte)(void);
    /**<table>  <tr><td><b>Function </b></td>  <td>Enable the Serial Recieve Interrupt. Capture the data recieve event in  HighPriority/LowPriority_InterruptHandler()</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>Interrupt Prioiry [HIGH or LOW]</td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>Serial2.EnableRxInterrupt(HIGH); </code></td></tr> </table> */
    char (*EnableRxInterrupt)(uchar);
    
}SERIAL_STRUCT;

/*----------------------------------------------------------------------------*/
/*** GLOBAL VARIABLES ***/
extern SERIAL_STRUCT Serial2;
extern SERIAL_STRUCT Serial1;

/*** ALTERNATE MACROS FUNCTIONS FOR READ AND SEND BYTES ***/
#define Serial1_ReadByte()      RC1REG
#define Serial2_ReadByte()      RC2REG
#define Serial1_SendByte(x)     (TX1REG = x)
#define Serial2_SendByte(x)     (TX2REG = x)
/*** MACROS FOR SERIAL INTERRUPT FLAGS ***/
#define Serial1_RxFlag   PIR1bits.RC1IF
#define Serial2_RxFlag   PIR3bits.RC2IF
#define Serial1_TxFlag   PIR1bits.TX1IF
#define Serial2_TxFlag   PIR3bits.TX2IF
/*----------------------------------------------------------------------------*/

#endif	/* EAB_SERIAL_H */

