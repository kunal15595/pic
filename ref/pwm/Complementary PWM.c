/******************************************************************************/
//
//							 Software License Agreement
//
// CODE OWNERSHIP AND DISCLAIMER OF LIABILITY

// Microchip Technology Incorporated ("Microchip") retains 
// all ownership and intellectual property rights in the code 
// accompanying this message and in all derivatives hereto.  
// You may use this code, and any derivatives created by any 
// person or entity by or on your behalf, exclusively with 
// Microchip’s proprietary products.  Your acceptance and/or 
// use of this code constitutes agreement to the terms and 
// conditions of this notice.

// CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, 
// BUT NOT LIMITED TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, 
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO 
// THIS CODE, ITS INTERACTION WITH MICROCHIP’S PRODUCTS, COMBINATION 
// WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 

// YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE 
// LIABLE, WHETHER IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE
// OR BREACH OF STATUTORY DUTY), STRICT LIABILITY, INDEMNITY, CONTRIBUTION,
// OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE, EXEMPLARY, INCIDENTAL 
// OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF ANY KIND WHATSOEVER
// RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED
// OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
// ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY 
// RELATED TO THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO 
// MICROCHIP SPECIFICALLY TO HAVE THIS CODE DEVELOPED.

// You agree that you are solely responsible for testing the code and
// determining its suitability.  Microchip has no obligation to modify,
// test, certify, or support the code.

#include <p24fj16mc102.h>

/************************* Define Constants **********************************/
#define PWMPERIOD 14699				// Configure PWM period for 500Hz frequency
                                    // Period calculation for center aligned
                                    // mode is as follows:
                                    // P1TPER = (FCY/((FPWM*(P1TMR Prescaler)*2)) - 1
                                    //        = (14.7MHz/(500*(1)*2)) - 1
                                    //        = 14699


/******************** Set Configuration Bits *********************************/
_CONFIG1(0x3FFF & GCP_OFF & GWRP_OFF & HPOL_ON & ICS_PGD3 & FWDTEN_OFF & PLLKEN_ON)
_CONFIG2(IESO_OFF & PWMLOCK_OFF & PWMPIN_OFF & FNOSC_FRC & FCKSM_CSECMD & OSCIOFNC_ON & IOL1WAY_OFF & LPOL_ON & ALTI2C_OFF & POSCMOD_NONE)


/********************* Function Prototypes **********************************/
void InitMCPWM(void);

/******************************************************************************
* Function:     main(void)
*
* Output:		None
*
* Overview:		Main function used to initialize the clock, and call PWM module function. 
*
* Note:			None
*******************************************************************************/

int main(void)
{
	// Configure Oscillator to operate the device at 14.74Mhz
	__builtin_write_OSCCONH(0x01);		// Start device with FRC and then switch to FRC+PLL
	__builtin_write_OSCCONL(0x01);

	while(OSCCONbits.COSC != 0b001);	// Wait for new Oscillator selection to become FRC+PLL
	
	while(OSCCONbits.LOCK != 1);		// Wait for PLL to lock

    InitMCPWM();						// Initialize MCPWM module

	while(1);							// Call infinite loop


 return 0;
}//end of main function


/******************************************************************************
* Function:     InitMCPWM(void)
*
* Output:		None
*
* Overview:		MC PWM Initialization Function, sets time base, PWM period, Duty Cycle
*
* Note:			None
*******************************************************************************/

void InitMCPWM(void)
{
	P1TCONbits.PTOPS = 0;   			// Choose PWM time base 1:1 postscale
	P1TCONbits.PTCKPS = 0;  			// Choose PWM time base 1:1 prescale
	P1TCONbits.PTMOD = 2;				// Choose Center Aligned PWM with 
	                                    // single interrupt mode per PWM period

    P1TPER = PWMPERIOD;					// Configure PWM period
	P1DC1 = PWMPERIOD;					// Configure Duty cycle to be 50%. In 
	                                    // center-aligned mode, this is the 
	                                    // same as the period value
	P1DC2 = PWMPERIOD;					// Configure Duty cycle to be 50%. In 
	                                    // center-aligned mode, this is the 
	                                    // same as the period value
	P1DC3 = PWMPERIOD;					// Configure Duty cycle to be 50%. In 
	                                    // center-aligned mode, this is the 
	                                    // same as the period value
	P1DTCON1bits.DTAPS=0;				// Clock period for Dead Time Unit A is Tcy
	P1DTCON1bits.DTA=10;				// Dead time value for Dead Time Unit A


    // Faults are enabled by default, so disable FLTA1
	// FLTA1 pin must be pulled high externally in order to clear and disable the fault
	// Writing to P1FLTACON register requires unlock sequence
	// Use builtin function to write 0x0000 to P1FLTACON register
	//if using compiler version 3.30B or later use line below
	// __builtin_write_PWMSFR(&P1FLTACON, 0x0000, &PWM1KEY);
	//else use
	asm("mov #0xabcd,w10");				// Load first unlock key to w10 register
	asm("mov #0x4321,w11");				// Load second unlock key to w11 register
	asm("mov #0x0000,w0");				// Load desired value of P1FLTACON register in w0
	asm("mov w10, PWM1KEY");			// Write first unlock key to PWM1KEY register
	asm("mov w11, PWM1KEY");			// Write second unlock key to PWM1KEY register
	asm("mov w0,P1FLTACON");			// Write desired value to P1FLTACON register
	
	// Faults are enabled by default, so disable FLTB1
	// FLTB1 pin must be pulled high externally in order to clear and disable the fault
	// Writing to P1FLTBCON register requires unlock sequence
	// Use builtin function to write 0x0000 to P1FLTBCON register
	//if using compiler version 3.30B or later use line below
	//__builtin_write_PWMSFR(&P1FLTBCON, 0x0000, &PWM1KEY);
	//else use
	asm("mov #0xabcd,w10");				// Load first unlock key to w10 register
	asm("mov #0x4321,w11");				// Load second unlock key to w11 register
	asm("mov #0x0000,w0");				// Load desired value of P1FLTBCON register in w0
	asm("mov w10, PWM1KEY");			// Write first unlock key to PWM1KEY register
	asm("mov w11, PWM1KEY");			// Write second unlock key to PWM1KEY register
	asm("mov w0,P1FLTBCON");			// Write desired value to P1FLTBCON register
	
	// Enable all PWMs using PWM1CON1 register
	// Writing to PWM1CON1 register requires unlock sequence
	// Use builtin function to write 0x0000 to PWM1CON1 register
	//if using compiler version 3.30B or later use line below
	//__builtin_write_PWMSFR(&PWM1CON1, 0x0077, &PWM1KEY);
	//else use
		asm("mov #0xabcd,w10");				// Load first unlock key to w10 register
	asm("mov #0x4321,w11");				// Load second unlock key to w11 register
	asm("mov #0x0077,w0");				// Load desired value of PWM1CON1 register in w0
	asm("mov w10, PWM1KEY");			// Write first unlock key to PWM1KEY register
	asm("mov w11, PWM1KEY");			// Write second unlock key to PWM1KEY register
	asm("mov w0,PWM1CON1");				// Write desired value to PWM1CON1 register
	
	P1OVDCON = 0x3F00;	                // All PWM outputs controlled by PWM module
	                                    // PWM outputs will be configured as inactive
	                                    // when overrides are enabled.				

    PWM1CON2 = 0x0000;					// 1:1 postscale values
										// Updates to the active PxDCy registers 
										// are sync to the PWM time base
										// Output overrides via the PxOVDCON
										//  register occuron the next TCY boundary
										// Updates from duty cycle and period
										//  buffer registers are enabled

	P1TCONbits.PTEN = 1;				// Enable the MC PWM module
	
}//end of MC PWM Initialization function
