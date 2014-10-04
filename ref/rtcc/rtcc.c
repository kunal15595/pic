/**********************************************************************
* 2009 Microchip Technology Inc.
*
* FileName:        	rtcc.c
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
* Uses LCD panel on EXPLORER 16 to display time
**********************************************************************/
#define USE_AND_OR
#include "realtime_clock.h"

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


rtccTimeDate RtccTimeDate ,RtccTimeDateVal,RtccAlrmTimeDate ,RtccAlrmTimeDateVal;
BOOL update_time =1;
BOOL update_alarm ;
BOOL Time_Input_out_of_range;
unsigned int  msec, sec, min, hr,MSD, MdD, LSD;

//************************* Interrupt service routine for RTCC *****************************
void __attribute__ ((interrupt,no_auto_psv)) _RTCCInterrupt (void)
{
  mRtcc_Clear_Intr_Status_Bit;						//clear the interrupt status
}	

int main(void)
{
	LCDInit();				//LCD initialization
	
   RtccInitClock();       //turn on clock source 
   mRtccSetIntPriority(4); 	//set interrupt priority to 4 
   mRtccSetInt(1);
   RtccWrOn();            //enable RTCC peripheral   
    
//***************** Set the TIME & DATA and TIME *****************************************	
   RtccTimeDate.f.hour = 1;
   RtccTimeDate.f.min =  1;
   RtccTimeDate.f.sec =  0;
   RtccTimeDate.f.mday = 4;
   RtccTimeDate.f.mon =  4;
   RtccTimeDate.f.year = 9;   
  
   mRtccOn();   
   update_alarm = RtccWriteTimeDate(&RtccTimeDate,0);

      /* Update the Time if requested */
    while(1)
	{
      RtccReadTimeDate(&RtccTimeDateVal);
      LCDL1Home();
      DisplayDate(RtccTimeDateVal.f.mday,RtccTimeDateVal.f.mon,RtccTimeDateVal.f.year);
      LCDL2Home();
      DisplayTime(RtccTimeDateVal.f.hour,RtccTimeDateVal.f.min,RtccTimeDateVal.f.sec,0);
	}
}

void DisplayTime(char hours, char minutes, char seconds,char milli_secs )
{

	LCDL2Home();

	LCDPut(((hours&0x30)>>4)+0x30);
	LCDPut((hours&0x0F)+0x30);
	LCDPut(':');

	LCDPut(((minutes&0x70)>>4)+0x30);
	LCDPut((minutes&0x0F)+0x30);
	LCDPut(':');

	LCDPut(((seconds&0x70)>>4)+0x30);
	LCDPut((seconds&0x0F)+0x30);
	LCDPut(':');

	LCDPut(MdD+0x30);
	LCDPut(LSD+0x30);
}

void DisplayDate(char day, char month, char year)
{

	LCDL1Home();

	LCDPut(((day&0x30)>>4)+0x30);
	LCDPut((day&0x0F)+0x30);
	LCDPut('/');

	LCDPut(((month&0x10)>>4)+0x30);
	LCDPut((month&0x0F)+0x30);
	LCDPut('/');

	LCDPut(((year&0xF0)>>4)+0x30);
	LCDPut((year&0x0F)+0x30);


}



