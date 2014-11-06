
//	===============================================================================================
//	PRODUCT:			---------- AVIX - (ADVANCED VIRTUAL INTEGRATED EXECUTIVE) RTOS ------------
//	-----------------------------------------------------------------------------------------------
// 	PRODUCT VERSION: 	5.0
// 	COPYRIGHT:			AVIX-RT EMBEDDED SOLUTIONS
//	LICENSE AGREEMENT:	SEE BOTTOM OF THIS FILE
//	-----------------------------------------------------------------------------------------------
//	MODULE:				THIS FILE BELONGS  TO THE BASIC AVIX TUTORIAL APPLICATION WHICH IS DISTRI-
//						BUTED AS PART OF AVIX.  FOR A DESCRIPTION OF THIS TUTORIAL READ DOCUMENT
//						AVIX_GettingStarted.pdf  WHICH IS INSTALLED  IN THE AVIX DOCUMENT DIRECTORY
//	-----------------------------------------------------------------------------------------------
//	FILENAME:			systemSetup.c
//	-----------------------------------------------------------------------------------------------
//	Description:
//  ------------
//	This file contains the controller specific configuration variables and a function systemSetup
//	which executes initialization code required to set the controllers speed.
//	===============================================================================================
//	INCLUDES:
//	===============================================================================================
//
#include "AVIX.h"


#if defined(__PIC24FJ128GA010__)

	_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & COE_OFF & FWDTEN_OFF & ICS_PGx2) 
	_CONFIG2( FCKSM_CSDCMD & OSCIOFNC_ON & POSCMOD_XT & FNOSC_PRIPLL )

#elif defined (__PIC24FJ256GB206__)

	_CONFIG1( WDTPS_PS32768 & FWPSA_PR128  & ALTVREF_ALTVREDIS & WINDIS_OFF   & FWDTEN_OFF     & ICS_PGx2     & GWRP_OFF    & GCP_OFF     & JTAGEN_OFF) 
	_CONFIG2( POSCMOD_XT    & IOL1WAY_OFF  & OSCIOFNC_OFF      & OSCIOFNC_OFF & FCKSM_CSDCMD   & FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2 & IESO_OFF)
	_CONFIG3( WPFP_WPFP255  & SOSCSEL_SOSC & WUTSEL_LEG        & WPDIS_WPDIS  & WPCFG_WPCFGDIS & WPEND_WPENDMEM) 
	
#elif defined (__PIC24FJ256GB210__)

	_CONFIG1( WDTPS_PS32768 & FWPSA_PR128  & ALTVREF_ALTVREDIS & WINDIS_OFF   & FWDTEN_OFF     & ICS_PGx2     & GWRP_OFF    & GCP_OFF     & JTAGEN_OFF)
	_CONFIG2( POSCMOD_XT    & IOL1WAY_OFF  & OSCIOFNC_OFF      & OSCIOFNC_OFF & FCKSM_CSDCMD   & FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2 & IESO_OFF)
	_CONFIG3( WPFP_WPFP255  & SOSCSEL_SOSC & WUTSEL_LEG        & WPDIS_WPDIS  & WPCFG_WPCFGDIS & WPEND_WPENDMEM)

#elif  defined(__PIC24FJ64GB004__)

	_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & FWDTEN_OFF & ICS_PGx2) 
	_CONFIG2( FCKSM_CSDCMD & OSCIOFNC_ON & POSCMOD_XT & FNOSC_PRIPLL )

#elif defined(__dsPIC30F6014A__)

	_FOSC(CSW_FSCM_OFF & XT_PLL16);
	_FWDT(WDT_OFF);				
	_FBORPOR(PBOR_ON & BORV_27 & PWRT_4 & MCLR_EN);
	_FBS(CODE_PROT_OFF);
	_FSS(CODE_PROT_OFF);
	_FGS(CODE_PROT_OFF);

#elif defined(__PIC24HJ256GP610__	)	||	\
	  defined(__dsPIC33FJ256GP710__	)	||	\
	  defined(__PIC24HJ256GP610A__  )	||	\
	  defined(__dsPIC33FJ256GP710A__)	||	\
	  defined(__PIC24EP512GU810__	)	||	\
	  defined(__dsPIC33EP512MU810__	)	||	\
	  defined(__dsPIC33EP64MC204__	)

	_FOSCSEL(FNOSC_FRC);
	_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);
	_FWDT(FWDTEN_OFF);

#elif defined(__32MX360F512L__)

	#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
	#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_1, ICESEL = ICS_PGx2

#else
	#error current type of controller not supported by demo software
#endif






//	===============================================================================================
//	FUNCTION:	systemSetup
//	=======================
//	Set the controller specifics
//	===============================================================================================
//
void systemSetup(void)
{
	//---------------------------------------------------------------------------------------------
	// The 24H and 33F needs dynamic settings to set the clock to the right speed
	//---------------------------------------------------------------------------------------------
#if	defined(__PIC24HJ256GP610__   )	||	\
	defined(__dsPIC33FJ256GP710__ )	||	\
	defined(__PIC24HJ256GP610A__  )	||	\
	defined(__dsPIC33FJ256GP710A__)

	//---------------------------------------------------------------------------------------------
	// The settings below set up the oscillator and PLL for 40 MIPS
	// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
	// Fosc= 8M*40/(2*2)=80Mhz for 8M input clock
	//---------------------------------------------------------------------------------------------
	PLLFBD				= 40 - 2;		// M=38
	CLKDIVbits.PLLPOST	= 2  - 2;		// N1=2
	CLKDIVbits.PLLPRE	= 2  - 2;		// N2=2
	OSCTUN				= 0;			// Tune FRC oscillator, if FRC is used

	RCONbits.SWDTEN		= 0;			// Disable Watch Dog Timer
	
	__builtin_write_OSCCONH(0x03);		// clock switch to incorporate PLL. Initiate Clock Switch to Primary
										// Oscillator with PLL (NOSC=0b011)
	__builtin_write_OSCCONL(0x01);		// Start clock switching
	
	while (OSCCONbits.COSC != 0b011);	// Wait for Clock switch to occur	

	while(OSCCONbits.LOCK != 1);		// Wait for PLL to lock

#elif 	defined(__PIC24EP512GU810__  )	||	\
		defined(__dsPIC33EP512MU810__)


	//---------------------------------------------------------------------------------------------
	// The settings below set up the oscillator and PLL for 60 MIPS
	// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
	// Fosc= 8M*70/(2*2)=120Mhz for 8M input clock
	//---------------------------------------------------------------------------------------------
	PLLFBD				= 70 - 2;		// M=58
	CLKDIVbits.PLLPOST	= 2  - 2;		// N1=2
	CLKDIVbits.PLLPRE	= 2  - 2;		// N2=2
	OSCTUN				= 0;			// Tune FRC oscillator, if FRC is used

	RCONbits.SWDTEN		= 0;			// Disable Watch Dog Timer
	
	__builtin_write_OSCCONH(0x03);		// clock switch to incorporate PLL. Initiate Clock Switch to Primary
										// Oscillator with PLL (NOSC=0b011)
	__builtin_write_OSCCONL(0x01);		// Start clock switching
	
	while (OSCCONbits.COSC != 0b011);	// Wait for Clock switch to occur	

	while(OSCCONbits.LOCK != 1);		// Wait for PLL to lock
	
#elif defined(__32MX360F512L__)

	unsigned int cache_status;
	
	//---------------------------------------------------------------------------------------------
	// Set speed and related cache and wait state settings based on configured speed The number of 
	// wait states is 2. Since this figure is only used here, it is hard coded instead of #defined
	//---------------------------------------------------------------------------------------------
	mCheConfigure(2);
    cache_status = mCheGetCon();
    cache_status |= CHE_CONF_PF_ALL;
    mCheConfigure(cache_status);
    
#else
	
#endif
}




//	===============================================================================================
//	***********************************************************************************************
//	===============================================================================================
//	SOFTWARE LICENSE AGREEMENT
//	--------------------------
//
//	THE  SOFTWARE  SUPPLIED  HEREWITH  AS  THE  CONTENT  OF  THIS FILE IS OWNED BY AVIX-RT EMBEDDED
//	SOLUTIONS  (THE "COMPANY"), AND IS PROTECTED  UNDER APPLICABLE  COPYRIGHT LAWS.  ALL RIGHTS ARE
//	RESERVED.  THE SOFTWARE IS SUPPLIED TO YOU (THE "CUSTOMER")  FOR USE  SOLELY AND EXCLUSIVELY AS
//	PART OF AND TOGETHER WITH PRODUCTS MANUFACTURED BY "COMPANY" AND LICENSED TO "CUSTOMER".
//
//	THE SOFTWARE IS PROVIDED ON AN AS-IS BASIS WITHOUT  CHARGE AND IS SUBJECT TO ALTERATIONS. IT IS 
//	THE "CUSTOMERS" OBLIGATION TO FULLY TEST THE SOFTWARE IN ITS ENVIRONMENT AND TO  ENSURE  PROPER 
//	FUNCTIONALITY, QUALIFICATION AND COMPLIANCE WITH COMPONENT SPECIFICATIONS.
//
//	IN  THE  EVENT  THE  SOFTWARE  DELIVERABLE  INCLUDES THE  USE OF  OPEN SOURCE  COMPONENTS,  THE 
//	PROVISIONS OF  THE GOVERNING  OPEN SOURCE  LICENSE AGREEMENT  SHALL APPLY  WITH RESPECT TO SUCH 
//	SOFTWARE DELIVERABLE. THE "COMPANY" DOES NOT WARRANT  THAT THE DELIVERABLES DO NOT INFRINGE ANY 
//	THIRD PARTY INTELLECTUAL  PROPERTY RIGHT (IPR).  IN THE EVENT THAT THE  DELIVERABLES INFRINGE A 
//	THIRD PARTY IPR IT IS THE SOLE RESPONSIBILITY OF THE "CUSTOMER" TO OBTAIN NECESSARY LICENSES TO 
//	CONTINUE THE  USAGE OF THE DELIVERABLE.
//
//	"COMPANY" LICENSES "CUSTOMER"  THE RIGHT TO USE  THIS FILE FOR THE  SOLE PURPOSE  OF DEVELOPING
//	APPLICATION SOFTWARE BASED ON ONE OF "COMPANIES" PRODUCTS AND FOR EXCLUSIVE USE ON A  SUPPORTED
//	MICROCONTROLLER.
//
//	UNDER NO CIRCUMSTANCE  MAY THE CONTENT OF  THIS FILE,  EITHER PARTIALLY  OR COMPLETE,  BE  MADE
//	PUBLIC, EITHER ELECTRONICALLY OR PRINTED.
//
//	ANY VIOLATION TO THE FOREGOING RESTRICTIONS  MAY SUBJECT THE USER  TO CRIMINAL SANCTIONS  UNDER
//	APPLICABLE LAWS, AS WELL AS TO CIVIL  LIABILITY FOR  THE BREACH  OF THE TERMS AND CONDITIONS OF
//	THIS LICENSE.
//
//	YOU SHOULD REFER TO THE LICENSE AGREEMENT  ACCOMPANYING THE  PRODUCT THIS  SOFTWARE IS  PART OF
//	FOR ADDITIONAL INFORMATION REGARDING YOUR RIGHTS AND OBLIGATIONS.
//
//	THE SOFTWARE  AND DOCUMENTATION  ARE PROVIDED  "AS IS"  WITHOUT  WARRANTY  OF ANY  KIND, EITHER
//	EXPRESS OR IMPLIED, INCLUDING WITHOUT  LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR
//	A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL "COMPANY" BE LIABLE FOR ANY
//	INCIDENTAL, SPECIAL,  INDIRECT OR  CONSEQUENTIAL DAMAGES,  LOST PROFITS  OR LOST  DATA, COST OF
//	PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING
//	BUT NOT  LIMITED TO ANY DEFENSE  THEREOF),  ANY CLAIMS  FOR  INDEMNITY OR CONTRIBUTION,OR OTHER
//	SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF  CONTRACT, TORT  (INCLUDING NEGLIGENCE), BREACH
//	OF WARRANTY, OR OTHERWISE.
//
//	COPYRIGHT (C) 2006-2012 AVIX-RT EMBEDDED SOLUTIONS.  ALL RIGHTS RESERVED.
//
//	===============================================================================================
