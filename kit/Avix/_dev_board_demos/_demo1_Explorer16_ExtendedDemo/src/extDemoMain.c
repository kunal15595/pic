
//	===============================================================================================
//	PRODUCT:			---------- AVIX - (ADVANCED VIRTUAL INTEGRATED EXECUTIVE) RTOS ------------
//	-----------------------------------------------------------------------------------------------
// 	PRODUCT VERSION: 	5.0
// 	COPYRIGHT:			AVIX-RT EMBEDDED SOLUTIONS
//	LICENSE AGREEMENT:	SEE BOTTOM OF THIS FILE
//	-----------------------------------------------------------------------------------------------
//	MODULE:				THIS FILE BELONGS  TO THE AVIX EXTENDED  TUTORIAL APPLICATION WHICH IS DIS-
//						TRIBUTED AS PART OF AVIX.  FOR A DESCRIPTION OF THIS TUTORIAL READ DOCUMENT
//						AVIX_GettingStarted.pdf  WHICH IS INSTALLED  IN THE AVIX DOCUMENT DIRECTORY
//	-----------------------------------------------------------------------------------------------
//	FILENAME:			extDemoMain.c
//	-----------------------------------------------------------------------------------------------
//	This file contains function avixMain which is the AVIX application main entry point. This 
//	component has the following responsibilities:
//	-	Create the two Exchange objects used to interface the different software components.
//	-	Call the initialization functions of the individual software components.
//	===============================================================================================
//	INCLUDES:
//	===============================================================================================
//
#include "stdio.h"
#include "AVIX.h"

#include "controlExchange.h"
#include "adcExchange.h"

#include "compUart.h"
#include "compLcd.h"
#include "compAdcSampling.h"
#include "compSwitchHandling.h"


//	===============================================================================================
//	EXTERNAL DECLARATIONS
//	===============================================================================================
//
extern void systemSetup(void);


//	===============================================================================================
//	TYPE DEFINITIONS
//	===============================================================================================
//


//	===============================================================================================
//	STATIC VARIABLES
//	===============================================================================================
//


//	===============================================================================================
//	FORWARD FUNCTION DECLARATIONS
//	===============================================================================================
//




//	***********************************************************************************************
//	===============================================================================================
//	FUNCTION:	avixMain
//	====================
//	avixMain is the entry point of an AVIX application. This function is comparable to main in a 
//	regular application. Note when this function runs, no multithreading is active yet. 
//	This function is responsible for:
//	-	Create the two Exchange objects that form the interface between the different software 
//		components contained in this application.
//	-	Call the initialization functions of the four individual software components.
//	On exit of avixMain, the threads created in the component initialization start running.
//	===============================================================================================
//
void avixMain(void)
{
	AVIX_OBJECT_ID_DEFINE(tavixExchId, controlExchId);
	AVIX_OBJECT_ID_DEFINE(tavixExchId, adcExchId);
	tavixThreadId tid;
	
	
	//---------------------------------------------------------------------------------------------
	// Low level MCU initialization.
	//---------------------------------------------------------------------------------------------
	systemSetup();


	//---------------------------------------------------------------------------------------------
	// Create and initialize the Exchange objects. 
	//---------------------------------------------------------------------------------------------
	controlExchId = controlExchCreateAndInit();
	adcExchId 	  = adcExchCreateAndInit();


	//---------------------------------------------------------------------------------------------
	// Initialize the different application software components. Pass the exchange id's so the 
	// components can decide for themselves how to connect in the most effective way.
	//---------------------------------------------------------------------------------------------
	tid = compAdcSampling_Init(adcExchId, controlExchId);
	avixThread_SetTracePort(tid, AVIX_TRACE_PORT_A, 1);
	
	tid = compUart_Init(adcExchId, controlExchId);
	avixThread_SetTracePort(tid, AVIX_TRACE_PORT_A, 2);

	tid = compLcd_Init(adcExchId, controlExchId);
	avixThread_SetTracePort(tid, AVIX_TRACE_PORT_A, 3);

	tid = compSwitchHandling_Init(controlExchId);
	avixThread_SetTracePort(tid, AVIX_TRACE_PORT_A, 4);
	
	avixThread_SetTracePort(TRACE_IDLE_THREAD_ID, AVIX_TRACE_PORT_A, 5);
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
