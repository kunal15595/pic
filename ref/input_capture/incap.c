/**********************************************************************
* 2009 Microchip Technology Inc.
*
* FileName:        	incap.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       	PIC24F
* Compiler:        	MPLAB C30 v3.11 or higher
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all 
* ownership and intellectual property rights in the code accompanying
* this message and in all derivatives hereto.  You may use this code,
* and any derivatives created by any person or entity by or on your 
* behalf, exclusively with Microchip's proprietary products.  Your 
* acceptance and/or use of this code constitutes agreement to the 
* terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS". NO 
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT 
* NOT LIMITED TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, 
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS 
* CODE, ITS INTERACTION WITH MICROCHIP'S PRODUCTS, COMBINATION WITH 
* ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE 
* LIABLE, WHETHER IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR
* BREACH OF STATUTORY DUTY), STRICT LIABILITY, INDEMNITY, 
* CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
* EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR 
* EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER 
* CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE
* DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW, 
* MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS
* CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP 
* SPECIFICALLY TO HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and 
* determining its suitability.  Microchip has no obligation to modify,
* test, certify, or support the code.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date      	Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Jyoti Shrinivas	04/04/09	First version of source file - v1
* Harsha.J.M			Modifications with library - version v1.1
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
* Code uses the PERIPHERAL LIBRARY support available with MPLAB C30 Compiler
* Code Tested on:
* EXPLORER 16 demo board with PIC24FJ256GB110 controller
* The Processor starts with the External Crystal (8 Mhz).
*
* Uses Input Capture 1 unit
* signal to be captured is applied to RP2. (This pn is configured for IC1 using PPS feature)
* This program captures the two successive faaling edges signals applied on IC1 pin and calculates the time interval between them.
**********************************************************************/
#define USE_AND_OR
#include "p24fxxxx.h"
#include "incap.h"
#include "PPS.h"

#if defined(__PIC24FJ256GB110__)
/*************** COFIGURATION **************************************
*	Watchdog Timer Disabled
*	Two Speed Start-up enabled
*	Oscillator Selection: HS oscillator ( 8MHz crystal on EXPLORER 16 Board )
*	Clock switching and clock monitor both enabled
********************************************************************/
_CONFIG1(FWDTEN_OFF & ICS_PGx2)
_CONFIG2(IESO_ON & FNOSC_PRI & FCKSM_CSECME & POSCMOD_HS & PLLDIV_DIV2 & IOL1WAY_OFF)
#endif

int Interrupt_Count = 0 , Int_flag, count;
unsigned int timer_first_edge, timer_second_edge;

// Interrupt service routine for Input Capture
void __attribute__((interrupt,no_auto_psv)) _IC1Interrupt(void)
{
Interrupt_Count++;					//Number Input Capture counts
if(Interrupt_Count == 1)
ReadCapture1(&timer_first_edge);	//Read the Time count for first capture of signal
else if(Interrupt_Count == 2)
{
ReadCapture1(&timer_second_edge);	//read the time count for second capture sgnal
Int_flag = 1;						//On two captured signals set the flag
}		
IC1_Clear_Intr_Status_Bit;			//Interrupt status clear
}


int main(void)
{
   unsigned int period , config1=0 ,config2=0;

//******************** RP2 pin is configured as IC1 using PPS feature *****************************************   
	iPPSInput(IN_FN_PPS_IC1,IN_PIN_PPS_RP2);  
   
   Int_flag = 0; 				//Initialize interrupt flag
//*************************** Configure Input Capture unit *************************************************
/**************************** Configration settings ********************************************************
*
*		Input Cature Interrupt Enabled with interrupt priority set to 4
*		Inpt capture unit uses Timer 1 as source of count
*		Input capture in every falling edge
*		IC cascade disabled
*		Interrupt on first capture
*		Stop IC during Idle Mode
*********************************************************************************************************/   
   ConfigIntCapture1(IC_INT_ON |IC_INT_PRIOR_4);
   config1 = IC_IDLE_STOP | IC_TIMER1_SRC | IC_INT_1CAPTURE | IC_EVERY_FALL_EDGE;
   config2 = IC_CASCADE_DISABLE ;//| IC_SYNC_ENABLE | IC_SYNC_TRIG_IN_TMR2;
   T1CON = 0x8000;
   OpenCapture1_GB(config1,config2);   						//Configure Input Capture module
   
      while(!Int_flag);   									//wait till two succssive falling edges
      period = timer_second_edge - timer_first_edge;		//calculate the time between two successive falling edges

      Interrupt_Count = 0;
      count = 0;
  
	  CloseCapture1();										//disable the Input Catpture module
	  while(1);												//end of program
   
}


