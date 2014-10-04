/**********************************************************************
* 2009 Microchip Technology Inc.
*
* FileName:        	spi.c
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
* Harsha.J.M	04/04/09	First release of source file
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
* Code uses the PERIPHERAL LIBRARY support available with MPLAB C30 Compiler
* Code Tested on:
* EXPLORER 16 demo board with PIC24FJ128GA010 controller
* The Processor starts with the External Crystal (8 Mhz).
*
* SPI Master and Slave are configured on two SPI modules SPI1 & SPI2 available on device
* SPI MASTER: 	SPI1 Module
* SPI SLAVE:	SPI1 Module
*
*Connections:
*		SPI1 (MASTER)				SPI1 (SLAVE)
*		
*		SDO1 	<------------------------->	SDI2  
*		SDI1 	<------------------------->	SDO2 
*		SCK1 	<------------------------->	SCK2  
*		SS1		<------------------------->	SS2   
*
**********************************************************************/
#define USE_AND_OR
#include "p24fxxxx.h"
#include "spi.h"

#if defined(__PIC24FJ256GB110__)
/*************** COFIGURATION **************************************
*	Watchdog Timer Disabled
*	Two Speed Start-up enabled
*	Oscillator Selection: HS oscillator ( 8MHz crystal on EXPLORER 16 Board )
*	Clock switching and clock monitor both enabled
********************************************************************/
_CONFIG1(FWDTEN_OFF & ICS_PGx2)
_CONFIG2(IESO_ON & FNOSC_PRI & FCKSM_CSECME & POSCMOD_HS )
#endif

unsigned char SPI_SLAVE[25],SPI_MASTER[] = "MICROCHIP";
static unsigned char i=0;

//******************** Interrupt sevice rotuine for SPI1 Master ***************************
void __attribute__((interrupt,no_auto_psv)) _SPI1Interrupt(void)
{
	
  SPI1_Clear_Intr_Status_Bit;							//Clear Interrupt status of SPI1		

}

//******************** Interrupt sevice rotuine for SPI2 Slave ***************************
void __attribute__((interrupt,no_auto_psv)) _SPI2Interrupt(void)
{
  SPI2_Clear_Intr_Status_Bit;							//Clear Interrupt status of SPI2
  SPI2_Clear_Recv_OV;  									//Clear recieve overflow of buffer status bit
  SPI_SLAVE[i++] = (unsigned char)ReadSPI2();							//Read the recieved data from Buffer
  SPI_SLAVE[i++] = (unsigned char)((ReadSPI2()&0xFF00)>>8);							//Read the recieved data from Buffer

}

int main(void)
{
   unsigned int SPICON1Value;
   unsigned int SPICON2Value;
   unsigned int SPISTATValue;

   
   /* Turn off SPI modules */
   CloseSPI1();											//Disbale SPI1 mdolue if enabled previously
   CloseSPI2();											//Disbale SPI2 mdolue if enabled previously 
    
 
//***************** SPI1 configuration **********************************************************
/**********************************************************************************************
*
*		SPI1 communication is WORD wide
*		Input data sampled at end of data output time
*		SPI1 in MASTER mode
*		Secondary Prescale 7:1
*		Frame SPI support Disable
*		SPI1 enabled
**********************************************************************************************/
   SPICON1Value = SPI_MODE16_ON |SPI_SMP_ON | MASTER_ENABLE_ON | SEC_PRESCAL_7_1;   
   SPICON2Value = FRAME_ENABLE_OFF;
   SPISTATValue = SPI_ENABLE;     
   OpenSPI1(SPICON1Value,SPICON2Value,SPISTATValue );
   
//***************** SPI2 configuration **********************************************************
/**********************************************************************************************
*
*		SPI2 communication is WORD wide
*		Input data sampled at end of data output time
*		SPI2 in SLAVE mode
*		Frame SPI support Disable
*		SPI2 enabled
**********************************************************************************************/
   SPICON1Value = SPI_MODE16_ON |  MASTER_ENABLE_OFF |SEC_PRESCAL_7_1;
   SPICON2Value = FRAME_ENABLE_OFF;
   SPISTATValue = SPI_ENABLE ; 
   OpenSPI2(SPICON1Value,SPICON2Value,SPISTATValue );     

//************ SPI interrupt configuration ****************************************************** 
	ConfigIntSPI1(SPI_INT_EN | SPI_INT_PRI_4);				//Master with priority 4
	ConfigIntSPI2(SPI_INT_EN | SPI_INT_PRI_1);				//slave with priority 3
  

//**************** MASTER transmission ********************************************************   
   putsSPI1(10,(unsigned int *)SPI_MASTER); 							//write data to buffer
   while(SPI1_Tx_Buf_Full);  						//wait till completion of transmission

//**************** SLAVE reception *************************************************************   

/***************** Turn off SPI module and clear IF bit ******************************************/
   CloseSPI1();
   CloseSPI2();  
   
   while(1);										//end of program
}


