
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
//	FILENAME:			compUart.c
//	-----------------------------------------------------------------------------------------------
//	This file contains the functions of the UART component.
//	===============================================================================================
//	INCLUDES:
//	===============================================================================================
//
#include <stdio.h>
#include <string.h>
#include <UART.h>

#include "support.h"

#include "AVIX.h"
#include "AVIXAtomicSFR.h"
#include "controlExchange.h"
#include "adcExchange.h"
#include "compUart.h"


//	===============================================================================================
//	EXTERNAL DECLARATIONS
//	===============================================================================================
//


//	===============================================================================================
//	TYPE DEFINITIONS
//	===============================================================================================
//


//	===============================================================================================
//	GLOBAL VARIABLES
//	===============================================================================================
//


//	===============================================================================================
// 	MACROS
//	===============================================================================================
//
#define FLAG_MSG_RECEIVED					0
#define FLAG_CONTROL_CHANGED				1

#define MSG_TYPE_DATA_EXCHANGE				0
#define MSG_TYPE_SERIAL_CONTROL				1


//-------------------------------------------------------------------------------------------------
// Macro to efficiently copy a const string (So a string in the form "   ") to a buffer. Passed is 
// the string (s), the buffer (b) and an offset (o). The string is copied from location &b[o].
// The offset (o) is updated with the length of the constant string excluding the terminating zero.
//-------------------------------------------------------------------------------------------------
#define COPY_CONST_STRING_TO_BUFFER(s,b,o)	{strcpy(&b[o], (s)); o += (sizeof(s)-1);}




//	===============================================================================================
//	GLOBAL VARIABLES
//	===============================================================================================
//
static tavixExchId		myControlExchange;	// Exchange to write when receiving serial commands
static tavixThreadId	tUart;				// ThreadId of of UART thread
static tavixPipeId		pipeTransmit;		// Id of pipe to send ASCII data to for transmission
static tavixExchConnId	inputConnection;	// Connection where analog data is received on



//	===============================================================================================
//	FORWARD FUNCTION DECLARATIONS
//	===============================================================================================
//
static TAVIX_THREAD_REGULAR threadUART(void* p);
static void uartSendPipeCallback(tavixPipeEvent pipeEvent, int nrBytes, void* pUserData);
static void UARTDeviceInit(void);



//	===============================================================================================
//	EXPORTED FUNCTIONS
//	===============================================================================================
//	***********************************************************************************************
//=================================================================================================
//	Function name: compUart_Init
//	----------------------------
//	Description:
//
//	UART send initialization
//=================================================================================================
//
tavixThreadId compUart_Init(tavixExchId inputExchange, tavixExchId controlExchange)
{
	//---------------------------------------------------------------------------------------------
	// The UART component receives commands through the serial link. Based on these commands the
	// control exchange will be written so remember the exchange id.
	//---------------------------------------------------------------------------------------------
	myControlExchange = controlExchange;
	
	
	//---------------------------------------------------------------------------------------------
	// Create the UART thread which takes care of all the work in this component.
	//---------------------------------------------------------------------------------------------
	tUart = avixThread_Create(	NULL, threadUART, (void*)0, 2, 360, AVIX_THREAD_READY);
	

	//---------------------------------------------------------------------------------------------
	// Create a pipe that will be written by the thread and emptied by the UART ISR. Blocksize is 1
	// since this is a character based pipe.
	//---------------------------------------------------------------------------------------------
	pipeTransmit = avixPipe_Create(NULL, 20, 1, uartSendPipeCallback, NULL);	


	//---------------------------------------------------------------------------------------------
	// The inputExchange is the exchange where the data to transmit is present in. The UART 
	// component must be informed when other components write to this exchange. For this purpose
	// a connection is created. The uart component must be informed of every single write operation
	// other components execute on the exchange. So here a push connection is created
	// (message queue connection, so every write to the exchange will generate a messsage).
	// The UART component also has a connection to the control exchange which is based on event
	// flags. For this reason to the thread message queue an event flag is connected so the thread
	// can be informed of either exchange being written by waiting for the applicable event flags.
	// The connection id is saved. Doing so, when both input channels are inactive, the connection
	// can be disabled to prevent updates to the exchange which are not used from being received.
	//---------------------------------------------------------------------------------------------
	inputConnection = avixExch_ConnectMsgQThread(inputExchange, tUart, MSG_TYPE_DATA_EXCHANGE);
	avixMsgQThread_ConnectEventGroup(tUart, tUart.asEventId, AVIX_EF(FLAG_MSG_RECEIVED));
	
	
	
	//---------------------------------------------------------------------------------------------
	// The control exchange holds info on the active channels. Only an active channel is written
	// to the UART device so a connection to the control exchange is created. Since for this 
	// exchange only the current value is required, a pull connection in the form of a thread event
	// group connection is created.
	//---------------------------------------------------------------------------------------------
	avixExch_ConnectEventGroup(controlExchange, tUart.asEventId, AVIX_EF(FLAG_CONTROL_CHANGED));


	//---------------------------------------------------------------------------------------------
	// Map the UART2 pins for use on the Explorer16 board.
	//---------------------------------------------------------------------------------------------
#if defined(__PIC24FJ256GB210__)

	RPOR8bits.RP17R    = 0x05;	// U2TX map output
	RPINR19bits.U2RXR  = 0x0a;	// U2RX map input
	RPINR19bits.U2CTSR = 0x20;	// U2CTS map input
	RPOR15bits.RP31R   = 0x06;	// U2RTS map output

#elif defined(__PIC24EP512GU810__) || defined(__dsPIC33EP512MU810__)
	
	RPOR9bits.RP101R   = 0x03;	// U2TX map output
	RPINR19bits.U2RXR  = 0x64;	// U2RX map input
	RPINR19bits.U2CTSR = 0x66;	// U2CTS map input
	RPOR12bits.RP109R  = 0x04;	// U2RTS map output
	
#endif
	
	return tUart;
}





//=================================================================================================
//	Function name: threadUART
//	-------------------------
//	Description:
//
//	UART thread. This thread is responsible for:
//	-	Observing the input exchange to serialize the data to the UART device.
//	-	Observing the control exchange to enable/disable individual channel serialization
//	-	Handling messages from the serial input to deal with commands received here.
//=================================================================================================
//
static TAVIX_THREAD_REGULAR threadUART(void* p)
{
	char				buffer[20];
	int					buffOffset;
	tAdcSamples			adcValues;
	tAppControl			control;
	tavixMsgId			msg;
	tavixEventFlags		flags;
	unsigned char		serialMsgVal;
	
	//---------------------------------------------------------------------------------------------
	// The control exchange contains enable/disable flags for the individual input channels. Read
	// the content to obtain the initial state.
	//---------------------------------------------------------------------------------------------
	avixExch_Read(myControlExchange, &control, NULL);
	
	
	//---------------------------------------------------------------------------------------------
	// Initialize the UART device
	//---------------------------------------------------------------------------------------------
	UARTDeviceInit();
	
		
	//---------------------------------------------------------------------------------------------
	// The thread sits in an endless loop, waiting for instructions on what to do.
	//---------------------------------------------------------------------------------------------
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// The thread wait for event flags. Two sources are present:
		// - 	When a message is received, an event flag is set since during initialization the
		//		thread event group is connected to the message queue (flag FLAG_MSG_RECEIVED).
		// -	When the control exchange receives a new value an event flag is set since during
		//		initialization a thread event group connection is created for the control exchange.
		//
		//	So the thread waits for one or both flags to become set. Note that only the control
		//	exchange connection flag is cleared as part of the wait. The message queue event flag
		//	is controlled by the message mechanism and is set as long as messages are present in 
		//	the queue. This flag may not be cleared by the wait.
		//-----------------------------------------------------------------------------------------
		flags = avixEventGroup_Wait
					(	avixThread_GetIdCurrent().asEventId,
						AVIX_EF(FLAG_MSG_RECEIVED) | AVIX_EF(FLAG_CONTROL_CHANGED), 
						AVIX_EVENT_GROUP_ANY, 
						AVIX_EF_NONE, 
						AVIX_EF(FLAG_CONTROL_CHANGED)	);	// Flag to clear, read above why this
															// is only the control connection flag.


		//-----------------------------------------------------------------------------------------
		// Test the flags returned from the wait operation to determine the source.
		//-----------------------------------------------------------------------------------------
		if (AVIX_EF_IN(AVIX_EF(FLAG_MSG_RECEIVED), flags))
		{
			//-------------------------------------------------------------------------------------
			// Since flag FLAG_MSG_RECEIVED is set, a message is guaranteed to be present in the 
			// message queue so the following call will not block.
			//-------------------------------------------------------------------------------------
			msg = avixMsgQThread_Receive();


			//-------------------------------------------------------------------------------------
			// For messages two sources exist, the input exchange connection and the UART receive
			// ISR. The source is distinguished by the message type. Type MSG_TYPE_SERIAL_CONTROL
			// identifies a message from the UART receive interrupt handler.
			//
			// Important: Note that in the following section, based on the command character
			// received from the uart, a straightfoward operation is executed on the control
			// exchange even though the UART component is one of the observers itself. So the
			// change made to the control exchange will result in a notification to the UART
			// component itself. This is desirable and leads to a high level of modularity.
			// Just consider the send and the receive part of this component to be autonomous and
			// realize other components can also write to the control exchange.
			//-------------------------------------------------------------------------------------
			if (avixMsg_GetType(msg) == MSG_TYPE_SERIAL_CONTROL)
			{
				//---------------------------------------------------------------------------------
				// Read the command character from the message and take the applicable action.
				//---------------------------------------------------------------------------------
				serialMsgVal = avixMsg_GetChar(msg);
				
				switch (serialMsgVal)
				{
					case 'c':
					case 'C':
						controlExchUpdateChannels(myControlExchange);
						break;
						
					case 'u':
					case 'U':
						controlExchUpdateSamplePeriod(myControlExchange, 1);
						break;

					case 'd':
					case 'D':
						controlExchUpdateSamplePeriod(myControlExchange, 0);
						break;
				}
			}

			//-------------------------------------------------------------------------------------
			// If the message type is not MSG_TYPE_SERIAL_CONTROL it must be a message generated
			// because the data exchange has been written. Read the data from the message, compose
			// the ASCII string for the active channels and write to the pipe which is read by the
			// UART ISR to send out to the client. Writing to the pipe automatically activates
			// the transmit interrupt. For details see the pipe callback function 
			// uartSendPipeCallback
			//-------------------------------------------------------------------------------------
			else
			{
				avixMsg_GetIndirect(msg, &adcValues, sizeof(adcValues));
		
				buffOffset = 0;
				buffer[buffOffset] = 0;
		
				if (control.input1Active)
				{
					COPY_CONST_STRING_TO_BUFFER("CH1:", buffer, buffOffset);
					buffOffset += convertIntToString(adcValues.channel1, &buffer[buffOffset], 0);
				}
				
				if (control.input2Active)
				{
					//-----------------------------------------------------------------------------
					// If both channels are active, the string is separated with a '-'
					//-----------------------------------------------------------------------------
					if (control.input1Active)
					{
						COPY_CONST_STRING_TO_BUFFER("-CH2:", buffer, buffOffset);
					}
					else
					{
						COPY_CONST_STRING_TO_BUFFER("CH2:", buffer, buffOffset);
					}
					buffOffset += convertIntToString(adcValues.channel2, &buffer[buffOffset], 0);
				}
				COPY_CONST_STRING_TO_BUFFER("\r\n", buffer, buffOffset);
				
				//---------------------------------------------------------------------------------
				// The string to transmit is written to the pipe. Connected to the pipe is a call-
				// back which will activate the Uart transmit interrupt.
				//---------------------------------------------------------------------------------
				avixPipe_Write(pipeTransmit, buffer, buffOffset);
			}
			avixMsg_Free(msg);
		}


		//-----------------------------------------------------------------------------------------
		// Test if the result of the event group wait operation contains the flag identifying the
		// control exchange was written.
		//-----------------------------------------------------------------------------------------
		if (AVIX_EF_IN(AVIX_EF(FLAG_CONTROL_CHANGED), flags))
		{
			//-------------------------------------------------------------------------------------
			// If so, read the content of the control exchange. If one or both channels are enabled
			// the connection to the data exchange is enabled.
			//-------------------------------------------------------------------------------------
			avixExch_Read(myControlExchange, &control, NULL);
			
			if ((control.input1Active) || (control.input2Active))
			{
				avixExch_EnableConnection(inputConnection);
			}
			else
			{
				//---------------------------------------------------------------------------------
				// If both channels are disabled, also disable the connection so writes to the
				// data exchange will not result in this component to be active. The Uart component 
				// does not know if in the meantime still messages have been generated so in order
				// not to process 'old' messages when reactivated again, the queue is flushed.
				//---------------------------------------------------------------------------------
				avixExch_DisableConnection(inputConnection);
				avixMsgQThread_Flush();
			}
		}
	}
}





//=================================================================================================
//	Function name: UART Transmit Interrupt handler.
//	-----------------------------------------------
//	Description:
//
//	UART Transmit interrupt handler. This interrupt handler is responsible for transmitting.
//=================================================================================================
//
avixDeclareISR(_U2TXInterrupt, no_auto_psv)
{
	unsigned char 	buffer[4];
	int 			i;
	int 			nrChars;
	
	nrChars = avixPipe_ReadFromISR(pipeTransmit, buffer, sizeof(buffer)/sizeof(buffer[0]));
	
	for (i = 0; i < nrChars; i++)
	{
		WriteUART2(buffer[i]);
	}
	
	//-----------------------------------------------------------------------------------------
	// Activate the pipe callback to test if the transmit interrupt must be disabled since no
	// characters to transmit are available anymore. For this purpose pass the number of
	// characters that was read from the pipe.
	//-----------------------------------------------------------------------------------------
	avixPipe_StopDeviceFromISR(pipeTransmit, nrChars);
}





//=================================================================================================
//	Function name: UART Receive Interrupt handler.
//	----------------------------------------------
//	Description:
//
//	UART Receive interrupt handler. This interrupt handler is responsible for receiving.
//=================================================================================================
//
avixDeclareISR(_U2RXInterrupt, no_auto_psv)
{
	tavixMsgId		msg;
	
	avixSFR(IFS1, U2RXIF, WRITE_BF, 0);	// Atomic clear of receive interrupt bit.
	msg = avixMsg_AllocateFromISR(MSG_TYPE_SERIAL_CONTROL);		// The type of the message is
	avixMsg_PutCharFromISR(msg, ReadUART2());					// used to distinguish from 
	avixMsgQThread_SendFromISR(msg, tUart);						// the data connection message.
}




//=================================================================================================
//	Function name: uartSendPipeCallback
//	-----------------------------------
//	Description:
//
//	Callback function connected to the pipe the thread uses to send data to the ISR. This callback
// 	is responsible for controlling the send interrupt status.
//=================================================================================================
//
static void uartSendPipeCallback(tavixPipeEvent pipeEvent, int nrBytes, void* pUserData)
{
	switch(pipeEvent)
	{
	case PIPEINFO_PIPE_DATA_WRITTEN:			// User thread has written data, enable transmit 
		avixSFR(IEC1, U2TXIE, WRITE_BF, 1);		// interrupt.
		break;
		
	case PIPEINFO_DEVICE_STOP_REQUESTED:		// Case when ISR calls avixPipe_StopDeviceFromISR
		if (nrBytes)
		{
			avixSFR(IFS1, U2TXIF, WRITE_BF, 0);	// If there are still bytes to write, just reset 
		}										// interrupt flag
		else
		{
			avixSFR(IEC1, U2TXIE, WRITE_BF, 0);	// If no more bytes to write, disable interrupt 
		}										// but leave interrupt flag so the interrupt will
		break;									// fire when enabled again.
		
	default:
		break;
	}
}





//=================================================================================================
//	Function name: UARTDeviceInit	
//	-----------------------------
//	Description:
//
//	Low leven UART initialization
//=================================================================================================
//
static void UARTDeviceInit(void)
{
	//---------------------------------------------------------------------------------------------
	// Initialize UART module 2 for sending and receiving
	//---------------------------------------------------------------------------------------------
	OpenUART2
		(	UART_EN					&	
			UART_IDLE_CON			&
			UART_EN_WAKE			&
			UART_DIS_LOOPBACK		&
			UART_UEN_00				&
			UART_DIS_ABAUD			&
			UART_NO_PAR_8BIT		&
			UART_1STOPBIT			&
			UART_IrDA_DISABLE		&
			UART_MODE_SIMPLEX		&
			UART_UXRX_IDLE_ONE		&
			UART_BRGH_FOUR
			,
			UART_INT_TX_BUF_EMPTY	&
			UART_IrDA_POL_INV_ZERO	&	// When no character, line is high!
			UART_TX_ENABLE			&
			UART_INT_RX_CHAR		&
			UART_ADR_DETECT_DIS		&
			UART_RX_OVERRUN_CLEAR
			,
			((avix_DEVICE_CLOCKhz/(4L * 115200)) - 1));	
			

	SetPriorityIntU2TX(3);
	DisableIntU2TX; 
	SetPriorityIntU2RX(2);
	EnableIntU2RX;
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
