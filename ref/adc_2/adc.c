/**********************************************************************
* 2009 Microchip Technology Inc.
*
* FileName:        	adc.c
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
* signal to be converted is fed to AN5 channel.
**********************************************************************/
#define USE_AND_OR
#include "p24fxxxx.h"
#include "adc.h"

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


// Global variabled
unsigned int ADCResult[16],DataAvailable=0;

//************************ Interrupt service routine for ADC ***********************************
void __attribute__((interrupt,no_auto_psv)) _ADC1Interrupt(void)
{
 static unsigned char j=0;
 ADCResult[j]= ReadADC10(j);											//Read the ADC cnversion results to ADCResult variable
 j++;
 ADC1_Clear_Intr_Status_Bit;											//Clear interrupt status bit
 if (j==16) 															//Are 16 samples acquired.
  {
   DisableIntADC1;														//If so, disable the ADC
   DataAvailable=1;														//Set th e data available flag bit to interpret the ADC conversion results
  } 
}	


int main(void)
{	
	unsigned char i;	
	unsigned int channel,config1,config2,config3,configportl,configporth=0,configscanl=0,configscanh=0;
		
	CloseADC10();														//Turn off ADC in case if it was operational previously 
	
/************** ADC configuration ***********************************************************
*
*	Use AN5 channel for siganl sampling
*	ADC uses internal RC as source of clock
*	Auto scan is enabled
*	conversion clcok is selected to 254Tcy
*	Sampling interval is selected to 17 TAD
*	ADC interrupt after 16 conversions
*******************************************************************************************/	
	channel= ADC_CH0_POS_SAMPLEA_AN5;									//use AN5 for signal sampling
	config1 = ADC_MODULE_OFF | ADC_CLK_AUTO | ADC_AUTO_SAMPLING_ON ;	
	config2 = ADC_SCAN_ON | ADC_INTR_16_CONV ;
	config3 = ADC_SAMPLE_TIME_17 | ADC_CONV_CLK_254Tcy;
	configportl = 0x0000;
	configscanl = ADC_SCAN_AN5 ;	
	OpenADC10(config1,config2,config3,configportl,configporth,configscanl,configscanh);
	ConfigIntADC10(ADC_INT_ENABLE|ADC_INT_PRI_3); 						//configure ADC interrupt

	EnableADC1;    														//turn on the ADC							
	SetChanADC10(channel);    											//Set the channel to AN5
    while(!DataAvailable);												//wait till the data becomes avaialble
    DataAvailable=0;    												//clear the Data available flag bit
 	
    i = 0;
    while(i <16 )
    {
   	EnableADC1;     													// Turn on the A/D converter    
    while(BusyADC10());	
	DisableADC1;    													// Turnoff the A/D converter
	ADCResult[i] = ReadADC10(i);										//Read the conversion results from buffer to ADCResults		
	i++;  
    }   
	
   CloseADC10(); 														//Close the ADC modue
   
   while(1);															//end of program
}    
  
