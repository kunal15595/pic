/*******************************************************************************
[File]          : EAB_I2C.h
[Dependencies]  : xc.h, plib/i2c.h, EAB_Definitions.h, EAB_Programmer.h, EAB_Oscillator.h, EAB_Pins.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : Functions to configure I2C communication, read and write data to the slave.
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com      LEAP from v1.0
*******************************************************************************/

#ifndef EAB_I2C_H
#define	EAB_I2C_H

/*** INCLUDE DEPENDENCIES ***/
#include <xc.h>
#include <plib/i2c.h>
#include "EAB_Definitions.h"
#include "EAB_Programmer.h"
#include "EAB_Oscillator.h"
#include "EAB_Pins.h"

/*----------------------------------------------------------------------------*/
typedef struct
{
    /**<table>  <tr><td><b>Function </b></td>  <td>Initialize the I2C1 communication with input clock frequency and default settings of Master Mode, 7 Bit address, 8 Bit data</td></tr>
    *           <tr><td><b>Input    </b></td>  <td>I2C Frequency [I2CFREQ_FAST, I2CFREQ_STANDARD or custom freq ] </td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>I2C1.Open(300000); or \n I2C1.Open(I2CFREQ_FAST);  </code></td></tr> </table> */
    void (*Open)(long);
   /**<table>  <tr><td><b>Function </b></td>  <td>Function to Read a number of bytes from an I2C slave</td></tr>
    *           <tr><td><b>Input    </b></td>  <td><i>Device Address</i> [Address of the device from which we want to read] </td></tr>
    *           <tr><td>                </td>  <td><i>Register Address</i> [Memory address from where the data is to be read]  </td></tr>
    *           <tr><td>                </td>  <td><i>Pointer to array/variable</i> [where data needs to be stored after reading] </td></tr>
    *           <tr><td>                </td>  <td><i>Length</i> [No of bytes to read] </td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>uchar DevAdd = 0x38, RegAdd = 0, ReadData, NoOfBytes = 1;\n I2C1.ReadArray(DevAdd, RegAdd, &ReadData, NoOfBytes);</code></td></tr> </table> */
    char (*ReadArray)(uchar,uchar,uchar *,uchar);
    /**<table>  <tr><td><b>Function </b></td>  <td>Function to Write a number of bytes to an I2C slave</td></tr>
    *           <tr><td><b>Input    </b></td>  <td><i>Device Address</i> [Address of the device from which we want to read] </td></tr>
    *           <tr><td>                </td>  <td><i>Register Address</i> [Memory address to where the data is to be written]  </td></tr>
    *           <tr><td>                </td>  <td><i>Pointer to array/variable</i> [where data  to be written is stored] </td></tr>
    *           <tr><td>                </td>  <td><i>Length</i> [No of bytes to read] </td></tr>
    *           <tr><td><b>Return   </b></td>  <td>SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>  <td><code>uchar DevAdd = 0x38, RegAdd = 0, WriteData = 0x0F, NoOfBytes = 1;\n I2C1.WriteArray(DevAdd, RegAdd, &WriteData, NoOfBytes);</code></td></tr> </table> */
   char (*WriteArray)(uchar,uchar,uchar *,uchar);
}I2C1_STRUCT;

/*----------------------------------------------------------------------------*/
/*** GLOBAL VARIABLES ***/
extern I2C1_STRUCT I2C1;

/*** STANDARD I2C CLOCK FREQUENCIES */
#define I2CFREQ_FAST        400000
#define I2CFREQ_STANDARD    100000
/*----------------------------------------------------------------------------*/

#endif	/* EAB_I2C_H */

