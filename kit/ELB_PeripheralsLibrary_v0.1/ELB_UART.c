/*****************************************************************************
Copyright (C) 2011-12 Brigosha Technologies Private Limited
Disclaimer		: 
 Common:
 Brigosha Technologies products are developed for the consumer goods industry. They may only be used 
 within the parameters of the respective valid product data sheet.  Brigosha Technologies products are 
 provided with the express understanding that there is no warranty of fitness for a particular purpose. 
 They are not fit for use in life-sustaining, safety or security sensitive systems or any system or device 
 that may lead to bodily harm or property damage if the system or device malfunctions.


 Special:
 This software module (hereinafter called "Software") and any information on application-sheets 
 (hereinafter called "Information") is provided free of charge for the sole purpose to support your 
 application work. The Software and Information is subject to the following terms and conditions: 

 The Software is specifically designed for the exclusive use for Brigosha Technologies products by 
 personnel who have special experience and training. Do not use this Software if you do not have the 
 proper experience or training. 

 This Software package is provided `` as is `` and without any expressed or implied warranties, 
 including without limitation, the implied warranties of merchantability and fitness for a particular 
 purpose. 

 Brigosha Technologies  deny any liability for the functional impairment of this Software in terms of
 fitness, performance and safety. Brigosha Technologies shall not be liable for any direct or indirect
 damages or injury.
 
 The Information provided is believed to be accurate and reliable. Brigosha Technologies assumes no 
 responsibility for the consequences of use of such Information nor for any infringement of patents or 
 other rights of third parties which may result from its use. No license is granted by implication or 
 otherwise under any patent or patent rights of Brigosha Technologies. Specifications mentioned in the
 Information are subject to change without notice.

 It is not allowed to deliver the source code of the Software to any third party without permission of 
 Brigosha Technologies.

****************************************************************************************************/ 
/*
********************************************************************************
[File]          : Config_UART.c
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLAB C30
[Description]   : UART1 and UART2 Initialization, with Data send functions
--------------------------------------------------------------------------------	
[VERSION]	[DATE]   	[AUTHOR] 			CHANGES
 v0.1		07.10.2011	shashi.prakash@brigosha.com	Modified for PIC24F
********************************************************************************
*/

/*** Include header files ***/
#include "Define.h" 

#include "ELB_UART.h"
/****************************/

/*
-------------------------------------------------------------------------------- 
[NAME]  	 : UART1_INIT
[TYPE]		 : Public API
[INPUT] 	 : Baud Rate, Config for baud rate and Interrupt enable options
[RETURN]	 : Task execution status success or failure
[DESCRIPTION]    : This function initializes the UART1 with desired Baud rate and
                    other default settings   8BIT - NO PARITY - 1 STOP BIT.
--------------------------------------------------------------------------------
*/
S8 UART1_INIT(S32 v_BaudRate_S32, U8 v_BaudConfig_U8, U8 v_IntEnable_U8)
{
    /*** Local variable ***/
    U8 v_TaskStatus_U8 = C_FAILURE, v_Temp_U8=0;
    S32 v_Fosc_S32 = 4E6;
    U8 v_BRGdivisor = 16;
    U16 v_BRG_U16 = 0;

    v_Fosc_S32 = GET_FreqOsc();
    if(v_BaudConfig_U8)
        v_BRGdivisor = 4;


    // Calculate BRG
    v_BRG_U16 =((F32) (v_Fosc_S32)/(v_BRGdivisor*v_BaudRate_S32) - 1);

    /*** Configure Interrupt ***/
    if((v_IntEnable_U8&RX_INT_PRI0) == RX_INT_PRI0)
    {
        v_Temp_U8 = (v_IntEnable_U8<<5);
        v_Temp_U8 = (v_Temp_U8>>5);
        IPC2bits.U1RXIP = v_Temp_U8;    //Setup U1RX interrupt priority
        IFS0bits.U1RXIF = 0;    //Clear the U1RX interrupt status flag
        IEC0bits.U1RXIE = 1;    //Enable U1RX interrupts
    }

    if((v_IntEnable_U8&TX_INT_PRI0) == TX_INT_PRI0)
    {
        v_Temp_U8 = (v_IntEnable_U8&0x70);
        v_Temp_U8 = (v_Temp_U8>>4);
        IPC3bits.U1TXIP = v_Temp_U8;    //Setup U2RX interrupt priority
        IFS0bits.U1TXIF = 0;            //Clear the U2RX interrupt status flag
        IEC0bits.U1TXIE = 1;            //Enable U2RX interrupts
    }

    /*** Configure registers ***/
    U1MODE = 0x00;              // CLR U1MODE register
    U1STA = 0x00;               // CLR U1STA register

    U1BRG = v_BRG_U16;          // Set the Baudrate

    U1MODEbits.BRGH = v_BaudConfig_U8;    //UART_BRGH_value from user
    U1MODEbits.PDSEL = 0;       //UART_NO_PAR_8BIT
    U1MODEbits.STSEL = 0;       //UART_1STOPBIT

    U1MODEbits.UARTEN = 1;      // UART_EN
    U1STAbits.UTXEN = 1;        // UART_TX_ENABLE
                                
    /*** Task Completed ***/
    v_TaskStatus_U8 = C_SUCCESS;

    return v_TaskStatus_U8;
}

/*
--------------------------------------------------------------------------------
[NAME]  	 : UART2_INIT
[TYPE]		 : Public API
[INPUT] 	 : BRG Value for desired Baud rate
[RETURN]	 : Task execution status success or failure
[DESCRIPTION]    : This function initializes the UART1 with desired Baud rate and
                   other default settings 8BIT - NO PARITY - 1 STOP BIT. The Baud
                   rate mode is High Baud rate.
--------------------------------------------------------------------------------
*/
S8 UART2_INIT(S32 v_BaudRate_S32, U8 v_BaudConfig_U8, U8 v_IntEnable_U8)
{
    /*** Local variable ***/
    U8 v_TaskStatus_U8 = C_FAILURE, v_Temp_U8=0;
    S32 v_Fosc_S32 = 4E6;
    U8 v_BRGdivisor = 16;
    U16 v_BRG_U16 = 0;

    v_Fosc_S32 = GET_FreqOsc();
    if(v_BaudConfig_U8)
       v_BRGdivisor = 4;
    
    // Calculate BRG
    v_BRG_U16 =((F32) (v_Fosc_S32)/(v_BRGdivisor*v_BaudRate_S32) - 1);

    /*** Configure Interrupt ***/
    if((v_IntEnable_U8&RX_INT_PRI0) == RX_INT_PRI0)
    {
        v_Temp_U8 = (v_IntEnable_U8<<5);
        v_Temp_U8 = (v_Temp_U8>>5);
        IPC7bits.U2RXIP = v_Temp_U8;    //Setup U2RX interrupt priority
        IFS1bits.U2RXIF = 0;            //Clear the U2RX interrupt status flag
        IEC1bits.U2RXIE = 1;            //Enable U2RX interrupts
    }
    if((v_IntEnable_U8&TX_INT_PRI0) == TX_INT_PRI0)
    {
        v_Temp_U8 = (v_IntEnable_U8&0x70);
        v_Temp_U8 = (v_Temp_U8>>4);
        IPC7bits.U2TXIP = v_Temp_U8;    //Setup U2RX interrupt priority
        IFS1bits.U2TXIF = 0;            //Clear the U2RX interrupt status flag
        IEC1bits.U2TXIE = 1;            //Enable U2RX interrupts
    }    
	
    /*** Configure registers ***/
    U2MODE = 0x00;              // CLR U1MODE register
    U2STA = 0x00;               // CLR U1STA register

    U2BRG = v_BRG_U16;          // Set the Baudrate

    U2MODEbits.BRGH = v_BaudConfig_U8;;    //UART_BRGH_value from user
    U2MODEbits.PDSEL = 0;       //UART_NO_PAR_8BIT
    U2MODEbits.STSEL = 0;       //UART_1STOPBIT

    U2MODEbits.UARTEN = 1;      // UART_EN
    U2STAbits.UTXEN = 1;        // UART_TX_ENABLE

    /*** Task Completed ***/
    v_TaskStatus_U8 = C_SUCCESS;

    return v_TaskStatus_U8;
}

/*
--------------------------------------------------------------------------------
[NAME]  	 : UART1_SEND_String
[TYPE]		 : Public API
[INPUT] 	 : Pointer to the array and the length of the array
[RETURN]	 : Task execution status success 
[DESCRIPTION]    : Send an array of specified length through UART1
--------------------------------------------------------------------------------
*/
void UART1_SEND_String(U8 *p_Array_U8, U8 v_Len_U8)
{
	while(v_Len_U8-- )
	{
		while(!U1STAbits.TRMT); 
	  	U1TXREG= *(p_Array_U8++); 
	}
	//return C_SUCCESS;
	
}



/*
--------------------------------------------------------------------------------
[NAME]  	 : UART2_SEND_String
[TYPE]		 : Public API
[INPUT] 	 : Pointer to the array and the length of the array
[RETURN]	 : Task execution status success 
[DESCRIPTION]    : Send an array of specified length through UART2
--------------------------------------------------------------------------------
*/
void UART2_SEND_String(U8 *p_Array_U8, U8 v_Len_U8)
{
	while(v_Len_U8-- )
	{
		while(!U2STAbits.TRMT); 
	  	U2TXREG= *(p_Array_U8++); 
	}
	//return C_SUCCESS;
	
}

