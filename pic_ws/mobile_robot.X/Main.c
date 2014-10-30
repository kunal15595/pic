//
////	===============================================================================================
////	PRODUCT:			---------- AVIX - (ADVANCED VIRTUAL INTEGRATED EXECUTIVE) RTOS ------------
////	-----------------------------------------------------------------------------------------------
//// 	PRODUCT VERSION: 	5.0
//// 	COPYRIGHT:			AVIX-RT EMBEDDED SOLUTIONS
////	LICENSE AGREEMENT:	SEE BOTTOM OF THIS FILE
////	-----------------------------------------------------------------------------------------------
////	MODULE:				THIS FILE BELONGS  TO THE BASIC AVIX TUTORIAL APPLICATION WHICH IS DISTRI-
////						BUTED AS PART OF AVIX.  FOR A DESCRIPTION OF THIS TUTORIAL READ DOCUMENT
////						AVIX_GettingStarted.pdf  WHICH IS INSTALLED  IN THE AVIX DOCUMENT DIRECTORY
////	-----------------------------------------------------------------------------------------------
////	FILENAME:			_tutorialMain.c
////	-----------------------------------------------------------------------------------------------
////	Description:
////  ------------
////	Main file of AVIX tutorial software. From this file the different tutorial application
////	initialization functions are called. To activate a desired tutorial, uncomment the applicable
////	function.
////	===============================================================================================
////	INCLUDES:
////	===============================================================================================
////
//#include "AVIX.h"
//
///*** MICROCHIP LIBRARY ***/
//#include <stdio.h>
//#include <stdlib.h>
//#include <p24FJ256GB210.h>
//#include <pic24f_periph_features.h>
//#include <ports.h>
//
//#include "adc.h"
//
///*** BRIGOSHA LIBRARY ***/
//#include "Define.h"
////#include "CONFIGbits.h"
//
//#include "ELBv21_HardwareConfig.h"
//#include "ELB_OSC.h"
//#include "ELB_I2C.h"
//#include "ELB_LCD.h"
//#include "ELB_PWM.h"
//#include "ELB_Timer.h"
//
//
//
///*** EXTERNAL VARIABLES  ***/
//extern  ts_ELB_Hardware Hardware;                   //Hardware Global Structure
//
//extern U8 V_T1IntFlag_U8;
//
////	-----------------------------------------------------------------------------------------------
////	External function declarations.
////	-----------------------------------------------------------------------------------------------
//extern void systemSetup(void);
//
//
//
//
//
//
//
//
////	===============================================================================================
////	FUNCTION:	myErrorFunc
////	=======================
////	Central AVIX error handler. Set breakpoint at while loop to catch errors in development
////	environment
////	===============================================================================================
////
//void myErrorFunc(tavixErrorCode errorCode)
//{
//    printf("error\n");
//	while(1);
//}
//
//
//
////	===============================================================================================
////	FUNCTION:	avixMain
////	====================
////	Main function for AVIX based project. From here specific selected tutorial function is called.
////	===============================================================================================
////
//int astar_test_main();
//
//void avixMain(void)
//{
//	//---------------------------------------------------------------------------------------------
//	// Setup the system and install an AVIX central error handler.
//	//---------------------------------------------------------------------------------------------
//	systemSetup();
//	avixError_SetHandler(myErrorFunc);
//
//        /*** CONFIGURE OSCILLATOR ***/
////    SET_FreqOsc( FRCDIV_250KHZ );               //Set frequency using macros from ELB Lib
//
//    /*** CONFIGURE HARDWARE ****/
////     Hardware_INIT();                            //Initialise Hardware functions
////     Hardware.ConfigPins_Default();              //Configure Default Hardware for ELB
//
//     /*** INITIALIZE PERIPHERAL ***/
//     TIMER1_INIT( 1000, TMR_INT_PRI1 );          //Set Timer1, check the calculator in prog guide
//                                                 //for available TimerTicks at Set Frequency
//
//
//	//---------------------------------------------------------------------------------------------
//	// Select the desired tutorial by setting the number of the desired tutorial in variable
//	// tutorialId. This variable is set in the development environment watch window.
//	//---------------------------------------------------------------------------------------------
//     astar_test_main();
//}
//
//
//
//
////	===============================================================================================
////	***********************************************************************************************
////	===============================================================================================
////	SOFTWARE LICENSE AGREEMENT
////	--------------------------
////
////	THE  SOFTWARE  SUPPLIED  HEREWITH  AS  THE  CONTENT  OF  THIS FILE IS OWNED BY AVIX-RT EMBEDDED
////	SOLUTIONS  (THE "COMPANY"), AND IS PROTECTED  UNDER APPLICABLE  COPYRIGHT LAWS.  ALL RIGHTS ARE
////	RESERVED.  THE SOFTWARE IS SUPPLIED TO YOU (THE "CUSTOMER")  FOR USE  SOLELY AND EXCLUSIVELY AS
////	PART OF AND TOGETHER WITH PRODUCTS MANUFACTURED BY "COMPANY" AND LICENSED TO "CUSTOMER".
////
////	THE SOFTWARE IS PROVIDED ON AN AS-IS BASIS WITHOUT  CHARGE AND IS SUBJECT TO ALTERATIONS. IT IS
////	THE "CUSTOMERS" OBLIGATION TO FULLY TEST THE SOFTWARE IN ITS ENVIRONMENT AND TO  ENSURE  PROPER
////	FUNCTIONALITY, QUALIFICATION AND COMPLIANCE WITH COMPONENT SPECIFICATIONS.
////
////	IN  THE  EVENT  THE  SOFTWARE  DELIVERABLE  INCLUDES THE  USE OF  OPEN SOURCE  COMPONENTS,  THE
////	PROVISIONS OF  THE GOVERNING  OPEN SOURCE  LICENSE AGREEMENT  SHALL APPLY  WITH RESPECT TO SUCH
////	SOFTWARE DELIVERABLE. THE "COMPANY" DOES NOT WARRANT  THAT THE DELIVERABLES DO NOT INFRINGE ANY
////	THIRD PARTY INTELLECTUAL  PROPERTY RIGHT (IPR).  IN THE EVENT THAT THE  DELIVERABLES INFRINGE A
////	THIRD PARTY IPR IT IS THE SOLE RESPONSIBILITY OF THE "CUSTOMER" TO OBTAIN NECESSARY LICENSES TO
////	CONTINUE THE  USAGE OF THE DELIVERABLE.
////
////	"COMPANY" LICENSES "CUSTOMER"  THE RIGHT TO USE  THIS FILE FOR THE  SOLE PURPOSE  OF DEVELOPING
////	APPLICATION SOFTWARE BASED ON ONE OF "COMPANIES" PRODUCTS AND FOR EXCLUSIVE USE ON A  SUPPORTED
////	MICROCONTROLLER.
////
////	UNDER NO CIRCUMSTANCE  MAY THE CONTENT OF  THIS FILE,  EITHER PARTIALLY  OR COMPLETE,  BE  MADE
////	PUBLIC, EITHER ELECTRONICALLY OR PRINTED.
////
////	ANY VIOLATION TO THE FOREGOING RESTRICTIONS  MAY SUBJECT THE USER  TO CRIMINAL SANCTIONS  UNDER
////	APPLICABLE LAWS, AS WELL AS TO CIVIL  LIABILITY FOR  THE BREACH  OF THE TERMS AND CONDITIONS OF
////	THIS LICENSE.
////
////	YOU SHOULD REFER TO THE LICENSE AGREEMENT  ACCOMPANYING THE  PRODUCT THIS  SOFTWARE IS  PART OF
////	FOR ADDITIONAL INFORMATION REGARDING YOUR RIGHTS AND OBLIGATIONS.
////
////	THE SOFTWARE  AND DOCUMENTATION  ARE PROVIDED  "AS IS"  WITHOUT  WARRANTY  OF ANY  KIND, EITHER
////	EXPRESS OR IMPLIED, INCLUDING WITHOUT  LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR
////	A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL "COMPANY" BE LIABLE FOR ANY
////	INCIDENTAL, SPECIAL,  INDIRECT OR  CONSEQUENTIAL DAMAGES,  LOST PROFITS  OR LOST  DATA, COST OF
////	PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING
////	BUT NOT  LIMITED TO ANY DEFENSE  THEREOF),  ANY CLAIMS  FOR  INDEMNITY OR CONTRIBUTION,OR OTHER
////	SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF  CONTRACT, TORT  (INCLUDING NEGLIGENCE), BREACH
////	OF WARRANTY, OR OTHERWISE.
////
////	COPYRIGHT (C) 2006-2012 AVIX-RT EMBEDDED SOLUTIONS.  ALL RIGHTS RESERVED.
////
////	===============================================================================================
