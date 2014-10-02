/**********************************************************************
* © 2005 Microchip Technology Inc.
*
* FileName:        main.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC30Fxxxx
* Compiler:        MPLAB® C30 v3.00 or higher
* IDE:             MPLAB® IDE v7.52 or later
* Dev. Board Used: dsPICDEM 1.1 Development Board
* Hardware Dependencies: None
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and 
* intellectual property rights in the code accompanying this message and in all 
* derivatives hereto.  You may use this code, and any derivatives created by 
* any person or entity by or on your behalf, exclusively with Microchip,s 
* proprietary products.  Your acceptance and/or use of this code constitutes 
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO 
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A 
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP,S 
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER 
* IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), 
* STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, 
* PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF 
* ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN 
* ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT 
* ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO 
* THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO 
* HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and 
* determining its suitability.  Microchip has no obligation to modify, test, 
* certify, or support the code.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author            Date      Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* HV/SB             11/15/05  First release of source file
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
*
**********************************************************************/

#include <dsp.h>

/*
Variable Declaration required for each PID controller in your application
*/
/* Declare a PID Data Structure named, fooPID */
tPID fooPID;
/* The fooPID data structure contains a pointer to derived coefficients in X-space and */
/* pointer to controler state (history) samples in Y-space. So declare variables for the */
/* derived coefficients and the controller history samples */
fractional abcCoefficient[3] __attribute__ ((section (".xbss, bss, xmemory")));
fractional controlHistory[3] __attribute__ ((section (".ybss, bss, ymemory")));
/* The abcCoefficients referenced by the fooPID data structure */
/* are derived from the gain coefficients, Kp, Ki and Kd */
/* So, declare Kp, Ki and Kd in an array */
fractional kCoeffs[] = {0,0,0};

/*
Main function demonstrating the use of PID(), PIDInit() and PIDCoeffCalc()
functions from DSP library in MPLAB C30 v3.00 and higher
*/
int main (void)
{
/*
Step 1: Initialize the PID data structure, fooPID
*/
        fooPID.abcCoefficients = &abcCoefficient[0];    /*Set up pointer to derived coefficients */
        fooPID.controlHistory = &controlHistory[0];     /*Set up pointer to controller history samples */
        PIDInit(&fooPID);                               /*Clear the controler history and the controller output */
	kCoeffs[0] = Q15(0.7);
	kCoeffs[1] = Q15(0.2);
	kCoeffs[2] = Q15(0.07);
        PIDCoeffCalc(&kCoeffs[0], &fooPID);             /*Derive the a,b, & c coefficients from the Kp, Ki & Kd */

/*
Step 2: Use the PID Controller
*/
        fooPID.controlReference = Q15(0.74) ;           /*Set the Reference Input for your controller */
        fooPID.measuredOutput = Q15(0.453) ;            /*Typically the measuredOutput variable is a plant response*/
                                                        /*measured from an A/D input or a sensor. */
                                                        /*In this example we manually set it to some value for */
                                                        /*demonstration but the user should note that this value will */
                                                        /*keep changing in a real application*/
        while (1)                                       /*We use a while(1) loop here for demonstration purposes.*/
        {                                               /*Typically, the PID calculation may be triggered off a timer*/
                                                        /*or A/D interrupt */

                PID(&fooPID);                           /*Call the PID controller using the new measured input */
                                                        /*The user may place a breakpoint on "PID(&fooPID)", halt the debugger,*/
                                                        /*tweak the measuredOutput variable within the watch window */
                                                        /*and then run the debugger again */
        }

}
