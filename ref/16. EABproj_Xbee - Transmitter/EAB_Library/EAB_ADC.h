/*******************************************************************************
[File]          : EAB_ADC.h
[Dependencies]  : xc.h, EAB_Definitions.h, EAB_Programmer.h, EAB_Oscillator.h EAB_Pins.h
[Processor]     : PIC18F26K22
[Compiler]      : XC8 v1.30
[Description]   : Functions to configure the analog to digital converter, Read 
                  analog input buffer, select the channel on which to sample the
				  voltage.
--------------------------------------------------------------------------------
[VERSION]   [DATE]      [AUTHOR] 			CHANGES
 v2.0       30.03.2014 	shashi.praksh@brigosha.com       LEAP from v1.0
*******************************************************************************/

#ifndef EAB_ADC_H
#define	EAB_ADC_H

/*** INCLUDE DEPENDENCIES ***/
#include <xc.h>
#include "EAB_Definitions.h"
#include "EAB_Programmer.h"
#include "EAB_Oscillator.h"
#include "EAB_Pins.h"

/*----------------------------------------------------------------------------*/
#define ACQUISTION_TIME_2TAD        1
#define ACQUISTION_TIME_4TAD        2
#define ACQUISTION_TIME_6TAD        3
#define ACQUISTION_TIME_8TAD        4
#define ACQUISTION_TIME_12TAD       5
#define ACQUISTION_TIME_16TAD       6
#define ACQUISTION_TIME_20TAD       7

#define VREF_POSITIVE_AVDD          0
#define VREF_POSITIVE_EXT           1

#define  VREF_NEGATIVE_AVSS         0       
#define  VREF_NEGATIVE_EXT          1

#define RESULT_FORMAT_LEFTALIGN     0
#define RESULT_FORMAT_RIGHTALIGN    1

#define ADC_ACQUISTION_TIME     ACQUISTION_TIME_12TAD
#define ADC_VREF_POSITIVE       VREF_POSITIVE_AVDD
#define ADC_VREF_NEGATIVE       VREF_NEGATIVE_AVSS
#define ADC_RESULT_FORMAT       RESULT_FORMAT_RIGHTALIGN

#define CHANNEL_AN0         0b00000
#define CHANNEL_AN1         0b00001
#define CHANNEL_AN2         0b00010
#define CHANNEL_AN3         0b00011
#define CHANNEL_RA5         0b00100
#define CHANNEL_SDI2        0b01000
#define CHANNEL_SDO2        0b01001
#define CHANNEL_SCK2        0b01010
#define CHANNEL_RB4         0b01011
#define CHANNEL_SS2         0b01100
#define CHANNEL_PWM3        0b01101
#define CHANNEL_PWM1        0b01110
#define CHANNEL_SCL1        0b01111
#define CHANNEL_SDA1        0b10000
#define CHANNEL_RC5         0b10001
#define CHANNEL_TX1         0b10010
#define CHANNEL_RX1         0b10011
#define CHANNEL_CTMU        0b11101
#define CHANNEL_DAC         0b11110
#define CHANNEL_FVRBUF2     0b11111

typedef struct
{
    /**<table>  <tr><td><b>Function </b></td>   <td> Initialize ADC with default, \n +Vref = VDD, -Vref = GND, \n Acquisition time  = 12 TAD \n ADC clock frequency = 1MHZ)  <b> NOT AVAILABLE at </b> 31.25 KHZ,250 KHZ </td>   </tr>
    *           <tr><td><b>Input    </b></td>   <td> none</td></tr>
    *           <tr><td><b>Return   </b></td>   <td> SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>   <td><code> ADC.Open();</code></td> </tr> </table>    */
    char (*Open)(void);
    /**<table>  <tr><td><b>Function </b></td>   <td> Select the ADC channel to read value of voltage input</tr>
    *           <tr><td><b>Input    </b></td>   <td> CHANNEL_xx[pin name] \n eg. CHANNEL_RB4 </td></tr>
    *           <tr><td><b>Return   </b></td>  <td>  SUCCESS[1] if function could execute the intended TASK, else FAILURE[-1]</td></tr>
    *           <tr><td><b>Example  </b></td>   <td> <code> ADC.SetChannel(ADC.config.CHANNEL1);</code></td> </tr> </table>    */
    char(*SetChannel)(uchar);
    /**<table>  <tr><td><b>Function </b></td>   <td> Read ADC data based on allignment </tr>
    *           <tr><td><b>Input    </b></td>   <td> none </td>   </tr>
    *           <tr><td><b>Return   </b></td>   <td> ADC value stored in Integer/Short</td>    </tr>
    *           <tr><td><b>Example  </b></td>   <td> <code> ADC.ReadData();</code></td> </tr> </table>    */
    short (*ReadData)(void);
}ADC_struct;

extern ADC_struct ADC;
#endif	/* EAB_ADC_H */

