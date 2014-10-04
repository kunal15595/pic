/**********************************************************************
* ?2007 Microchip Technology Inc.
*
* FileName:        OC_PWM_Dedicatd_TMR.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       PIC24Fxxxx
* Compiler:        MPLAB?C30 v3.00 or higher
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
* Author        Date      	Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Albert Z.		1/4/09		Original Release
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
* Pin #23, #24, #32, #33, #72, #71, #70, #69, #76 on Explorer 16 with 
* PIC24FJ256GA110 PIM or PIC24FJ256GB110 PIM are 9 output compare 
* modules (OC1 ~ OC9) respectively. 
*
* This code example is tested on PIC24FJ256GA110 and PIC24FJ256GB110. 
* 
* PIC24FJ128GA010 family and PIC24FJ64GA004 family have a different 
* Output Compare module, please read datasheet for more detail. 
* The Family Reference Manual has two sections about Output Compare. 
* For PIC24FJ256GA110 and PIC24FJ256GB110 family, please refer 
* Section 35. Output Compare with Dedicated Timer. 
* For PIC24FJ128GA010 and PIC24FJ64GA004 family, please refer 
* Section 16. Output Compare. 
**********************************************************************/

#include "p24fxxxx.h"

#if defined (__PIC24FJ256GB110__)	//Defined by MPLAB when using 24FJ256GB110 device
    _CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & COE_OFF & FWDTEN_OFF & ICS_PGx2) 
    _CONFIG2( IESO_OFF & FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_HS & FNOSC_PRIPLL & PLLDIV_DIV2 & IOL1WAY_ON)
    _CONFIG3( WPCFG_WPCFGDIS & WPDIS_WPDIS)		//Disable erase/write protect of all memory regions.
#elif defined (__PIC24FJ256GA110__)	//Defined by MPLAB when using 24FJ256GA110 device
    _CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & COE_OFF & FWDTEN_OFF & ICS_PGx2 ) 
    _CONFIG2( FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_HS & FNOSC_PRIPLL & IOL1WAY_ON)
    _CONFIG3( WPCFG_WPCFGDIS & WPDIS_WPDIS)		//Disable erase/write protect of all memory regions.
#else
	#error This code example does not support this device.
#endif

//PPS Outputs for PIC24FJ256GA110 and PIC24FJ256GB110
#define OC1_IO		18
#define OC2_IO		19
#define OC3_IO		20
#define OC4_IO		21
#define OC5_IO		22
#define OC6_IO      23
#define OC7_IO      24
#define OC8_IO      25
#define OC9_IO      35

int main (void)
{
	// Disable Watch Dog Timer
	RCONbits.SWDTEN = 0;
	
	// Configure RA6 as output
	ODCAbits.ODA6 = 0;
	TRISAbits.TRISA6 = 0;

	// PPS
	// Unlock Registers
	__builtin_write_OSCCONL(OSCCON & 0xbf);
	// Configure Output Functions *********************
	RPOR6bits.RP13R 	= OC1_IO;	// RP13	pin#23
	RPOR0bits.RP1R 		= OC2_IO;	// RP1	pin#24
	RPOR4bits.RP8R 		= OC3_IO;	// RP8	pin#32
	RPOR4bits.RP9R 		= OC4_IO;	// RP9	pin#33
	
	RPOR5bits.RP11R 	= OC5_IO;	// RP11	pin#72
	RPOR6bits.RP12R 	= OC6_IO;	// RP12	pin#71
	RPOR1bits.RP3R 		= OC7_IO;	// RP3	pin#70
	RPOR2bits.RP4R 		= OC8_IO;	// RP4	pin#69
	
	RPOR12bits.RP24R 	= OC9_IO;	// RP24	pin#76
	// Lock Registers
	__builtin_write_OSCCONL(OSCCON | 0x40);

	/*  
	The following configuration for OC1, OC2, OC3 and OC4 will set the 
	Output Compare modules for PWM mode w/o FAULT pin enabled, 
	a 50%/75% duty cycle and PWM frequency of 1 kHz at Fosc = 32 MHz. 
	System clock is selected as the clock for the PWM time base 
	and no interrupt is enabled. The four PWM channels are synchronised
	by OC1, therefore OC1 should be initialized at last. OC2 and OC4 are
	complementary to OC1 and OC3 respectively. 
	
	Find the Period register value for a desired PWM frequency of 1 kHz, 
	where Fosc = 8 MHz with PLL (32 MHz device clock rate). 
	Tcy = 2/Fosc = 62.5 ns
	PWM Period   =  1/PWM Frequency = 1/1 kHz = 1000 ¦Ìs
	PWM Period   = (OC1RS + 1) * Tcy
	1000 ¦Ìs = (OC1RS + 1) * 62.5 ns * 1 
	OC1RS = 15999 (0x3E7F)
	*/

	OC2CON1				= 0; 		// It is a good practice to clear off the control bits initially
	OC2CON2				= 0;
	OC2R				= 0x1f3f;	// Initialize Compare Register1 with 50% duty cycle
//	OC2RS				= 0x3e7f;	// This period is synchronized by OC1
	OC2CON2bits.SYNCSEL	= 0x1;		// synchronized by the OC1 module
	OC2CON1bits.OCTSEL	= 0x7;		// System Clock (Tcy) is the clock source for output Compare
	OC2CON1bits.OCFLT	= 0;		// No PWM Fault condition has occurred (this bit is only used when OCM<2:0> = 111)
	OC2CON2bits.OCINV	= 1;		// OCx output is inverted
	OC2CON1bits.OCM		= 0x6;		// Edge-aligned PWM mode on OC

	OC3CON1				= 0; 		// It is a good practice to clear off the control bits initially
	OC3CON2				= 0;
	OC3R				= 0x2edf;	// Initialize Compare Register1 with 75% duty cycle
//	OC3RS				= 0x3e7f;	// This period is synchronized by OC1
	OC3CON2bits.SYNCSEL	= 0x1;		// synchronized by the OC1 module
	OC3CON1bits.OCTSEL	= 0x7;		// System Clock (Tcy) is the clock source for output Compare
	OC3CON1bits.OCFLT	= 0;		// No PWM Fault condition has occurred (this bit is only used when OCM<2:0> = 111)
	OC3CON2bits.OCINV	= 0;		// OCx output is not inverted
	OC3CON1bits.OCM		= 0x6;		// Edge-aligned PWM mode on OC

	OC4CON1				= 0; 		// It is a good practice to clear off the control bits initially
	OC4CON2				= 0;
	OC4R				= 0x2edf;	// Initialize Compare Register1 with 75% duty cycle
//	OC4RS				= 0x3e7f;	// This period is synchronized by OC1
	OC4CON2bits.SYNCSEL	= 0x1;		// synchronized by the OC1 module
	OC4CON1bits.OCTSEL	= 0x7;		// System Clock (Tcy) is the clock source for output Compare
	OC4CON1bits.OCFLT	= 0;		// No PWM Fault condition has occurred (this bit is only used when OCM<2:0> = 111)
	OC4CON2bits.OCINV	= 1;		// OCx output is inverted
	OC4CON1bits.OCM		= 0x6;		// Edge-aligned PWM mode on OC

	OC1CON1				= 0; 		// It is a good practice to clear off the control bits initially
	OC1CON2				= 0;
	OC1R				= 0x1f3f;	// Initialize Compare Register1 with 50% duty cycle
	OC1RS				= 0x3e7f;	// Calculate the desired period for OC1, OC2, OC3 and OC4.
	OC1CON2bits.SYNCSEL	= 0x1;		// synchronized by the OC1 module
	OC1CON1bits.OCTSEL	= 0x7;		// System Clock (Tcy) is the clock source for output Compare
	OC1CON1bits.OCFLT	= 0;		// No PWM Fault condition has occurred (this bit is only used when OCM<2:0> = 111)
	OC1CON2bits.OCINV	= 0;		// OCx output is not inverted
	OC1CON1bits.OCM		= 0x6;		// Edge-aligned PWM mode on OC

	/*  
	The following configuration for OC5, OC6, OC7 and OC8 will set the 
	Output Compare modules for PWM mode w/o FAULT pin enabled, 
	a 50% duty cycle and PWM frequency of 50 kHz at Fosc = 32 MHz. 
	Timer 1 is selected as the clock for the PWM time base 
	and Timer 1 interrupt is enabled. The four PWM channels are 
	synchronised by Timer 1, and the waveforms continue one after
	the other. 
	
	Find the Period register value for a desired PWM frequency of 50 kHz, 
	where Fosc = 8 MHz with PLL (32 MHz device clock rate). 
	Tcy = 2/Fosc = 62.5 ns
	PWM Period   =  1/PWM Frequency = 1/50 kHz = 20 ¦Ìs
	PWM Period   = (PR1 + 1) * Tcy * (Timer 1 Prescale Value)
	20 ¦Ìs = (PR1 + 1) * 62.5 ns * 1 
	PR1 = 319 (0x13f)
	*/
	T1CON				= 0;		// Timer 1 is clock for OC5, OC6, OC7 and OC8.
	PR1					= 0x13f;	// This is the period of OC5, OC6, OC7 and OC8. 
	T1CONbits.TCKPS		= 0;		// Timer Input Clock Prescale is 1:1
	IFS0bits.T1IF		= 0;		// Clear Output Compare interrupt flag
	IEC0bits.T1IE		= 1;		// Enable Output Compare interrupts
	
	OC5CON1				= 0; 		// It is a good practice to clear off the control bits initially
	OC5CON2				= 0;
	OC5R				= 0x0;		// Initialize Compare Register1 with desired rising edge of the pulse
	OC5RS				= 0x7f;		// Initialize Compare Register1 with desired falling edge of the pulse
	OC5CON2bits.SYNCSEL	= 0x0b;		// synchronized by the Timer 1
	OC5CON1bits.OCTSEL	= 0x4;		// Timer 1 is the clock source for output Compare
	OC5CON1bits.OCFLT	= 0;		// No PWM Fault condition has occurred (this bit is only used when OCM<2:0> = 111)
	OC5CON2bits.OCINV	= 0;		// OCx output is not inverted
	OC5CON1bits.OCM		= 0x7;		// Center-aligned PWM mode on OC

	OC6CON1				= 0; 		// It is a good practice to clear off the control bits initially
	OC6CON2				= 0;
	OC6R				= 0x3f;		// Initialize Compare Register1 with desired rising edge of the pulse
	OC6RS				= 0xbf;		// Initialize Compare Register1 with desired falling edge of the pulse
	OC6CON2bits.SYNCSEL	= 0x0b;		// synchronized by the Timer 1
	OC6CON1bits.OCTSEL	= 0x4;		// Timer 1 is the clock source for output Compare
	OC6CON1bits.OCFLT	= 0;		// No PWM Fault condition has occurred (this bit is only used when OCM<2:0> = 111)
	OC6CON2bits.OCINV	= 0;		// OCx output is not inverted
	OC6CON1bits.OCM		= 0x7;		// Center-aligned PWM mode on OC

	OC7CON1				= 0; 		// It is a good practice to clear off the control bits initially
	OC7CON2				= 0;
	OC7R				= 0x7f;		// Initialize Compare Register1 with desired rising edge of the pulse
	OC7RS				= 0xff;		// Initialize Compare Register1 with desired falling edge of the pulse
	OC7CON2bits.SYNCSEL	= 0x0b;		// synchronized by the Timer 1
	OC7CON1bits.OCTSEL	= 0x4;		// Timer 1 is the clock source for output Compare
	OC7CON1bits.OCFLT	= 0;		// No PWM Fault condition has occurred (this bit is only used when OCM<2:0> = 111)
	OC7CON2bits.OCINV	= 0;		// OCx output is not inverted
	OC7CON1bits.OCM		= 0x7;		// Center-aligned PWM mode on OC

	OC8CON1				= 0; 		// It is a good practice to clear off the control bits initially
	OC8CON2				= 0;
	OC8R				= 0xbf;		// Initialize Compare Register1 with desired rising edge of the pulse
	OC8RS				= 0x13f;	// Initialize Compare Register1 with desired falling edge of the pulse
	OC8CON2bits.SYNCSEL	= 0x0b;		// synchronized by the Timer 1
	OC8CON1bits.OCTSEL	= 0x4;		// Timer 1 is the clock source for output Compare
	OC8CON1bits.OCFLT	= 0;		// No PWM Fault condition has occurred (this bit is only used when OCM<2:0> = 111)
	OC8CON2bits.OCINV	= 0;		// OCx output is not inverted
	OC8CON1bits.OCM		= 0x7;		// Center-aligned PWM mode on OC
	
	T1CONbits.TON		= 1;		// Output compare modules do not run until sync source is switched on

	/*  
	The following configuration for OC9 will set the Output Compare
	modules for PWM mode w/o FAULT pin enabled, a 33% duty cycle
	and PWM frequency of 20 Hz at Fosc = 32 MHz. 
	Timer 2 is selected as the clock for the PWM time base 
	and no interrupt is enabled. The PWM channel is	synchronised 
	by itself. 
	
	Find the Period register value for a desired PWM frequency of 20 Hz, 
	where Fosc = 8 MHz with PLL (32 MHz device clock rate). 
	Tcy = 2/Fosc = 62.5 ns
	PWM Period   =  1/PWM Frequency = 1/20 Hz = 50 ms
	PWM Period   = (OC9RS + 1) * Tcy * (Timer 2 Prescale Value)
	50 ms = (OC9RS + 1) * 62.5 ns * 64 
	OC9RS = 12499 (0x30d3)
	*/
	T2CON				= 0;		// Timer 2 is clock for OC9.
	T2CONbits.TCKPS		= 2;		// Timer Input Clock Prescale is 1:64
	
	OC9CON1				= 0; 		// It is a good practice to clear off the control bits initially
	OC9CON2				= 0;
	OC9R				= 0x1046;	// Initialize Compare Register1 with desired duty cycle
	OC9RS				= 0x30d3;	// Initialize Compare Register1 with desired period
	OC9CON2bits.SYNCSEL	= 0x1f;		// synchronized by itself
	OC9CON1bits.OCTSEL	= 0x0;		// Timer 2 is the clock source for output Compare
	OC9CON1bits.OCFLT	= 0;		// No PWM Fault condition has occurred (this bit is only used when OCM<2:0> = 111)
	OC9CON2bits.OCINV	= 0;		// OCx output is not inverted
	OC9CON1bits.OCM		= 0x6;		// Edge-aligned PWM mode on OC
	T2CONbits.TON		= 1;		// Output compare modules do not run until sync source is switched on


	while(1)
	{
		Idle();
	}

	return 0;
}

// Example code for Timer1 ISR can be probed as the start time of every period. 
void __attribute__ ((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
	IFS0bits.T1IF = 0;
	__builtin_btg((unsigned int *)&LATA, 6);
}
