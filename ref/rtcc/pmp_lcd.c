/*****************************************************************************
 *
 * LCD Driver for PIC24.
 *
 *****************************************************************************
 * FileName:        lcd.c
 * Dependencies:    
 * Processor:       
 * Compiler:       	
 * Linker:          
 * Company:         Microchip Technology Incorporated
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the "Company") is intended and supplied to you, the Company's
 * customer, for use solely and exclusively with products manufactured
 * by the Company. 
 *
 * The software is owned by the Company and/or its supplier, and is 
 * protected under applicable copyright laws. All rights are reserved. 
 * Any use in violation of the foregoing restrictions may subject the 
 * user to criminal sanctions under applicable laws, as well as to 
 * civil liability for the breach of the terms and conditions of this 
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES, 
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT, 
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR 
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 * A simple LCD driver for LCDs interface through the PMP
 * 
 *
 *

 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include "realtime_clock.h"


unsigned int _uLCDloops;

void pmp_Init(void)
{
	unsigned int mode,control,port,addrs,interrupt;
	
    control = BIT_PMP_ON | BIT_RD_WR_ON | BIT_RD_WR_HI ;
	mode = BIT_MODE_MASTER_1 | BIT_WAITB_4_TCY  | BIT_WAITM_15_TCY | BIT_WAITE_4_TCY ;
	port = BIT_P0;
	addrs = 0x0000;
	interrupt = 0x0000;
	
	PMPClose();
	PMPOpen(control,mode,port,addrs,interrupt);
}		

void LCDInit(void)
{	
    pmp_Init();

	_uLCDloops = LCD_STARTUP;
	Wait(_uLCDloops);

	_uLCDloops = LCD_F_INSTR;
	PMDIN1 = 0b00111000;			// Set the default function
	Wait(_uLCDloops);

	_uLCDloops = LCD_STARTUP;
	Wait(_uLCDloops);

	_uLCDloops = LCD_F_INSTR;
	PMDIN1 = 0b00001100;
	Wait(_uLCDloops);

	_uLCDloops = LCD_STARTUP;
	Wait(_uLCDloops);

	_uLCDloops = LCD_S_INSTR;
	PMDIN1 = 0b00000001;			// Clear the display
	Wait(_uLCDloops);

	_uLCDloops = LCD_STARTUP;
	Wait(_uLCDloops);

	_uLCDloops = LCD_S_INSTR;
	PMDIN1 = 0b00000110;			// Set the entry mode
     
	Wait(_uLCDloops);

	LCDClear();
	LCDHome();
}



void LCDHome(void)
{
	_uLCDloops = LCD_S_INSTR;
//	PMADDR = 0x0000;
    PMPSetAddress(0x0000); 
	PMDIN1 = 0b00000010;
	while(_uLCDloops)
	_uLCDloops--;
}


void LCDL1Home(void)
{
	_uLCDloops = LCD_S_INSTR;
//	PMADDR = 0x0000;
    PMPSetAddress(0x0000); 
	PMDIN1 = 0b10000000;
	while(_uLCDloops)
	_uLCDloops--;
}

void LCDL2Home(void)
{
	_uLCDloops = LCD_S_INSTR;
	//PMADDR = 0x0000;
	PMPSetAddress(0x0000); 
	PMDIN1 = 0b11000000;
	while(_uLCDloops)
	_uLCDloops--;
}


void LCDClear(void)
{
	_uLCDloops = LCD_S_INSTR;
	//PMADDR = 0x0000;
	PMPSetAddress(0x0000); 
	PMDIN1 = 0b00000001;
	while(_uLCDloops)
	_uLCDloops--;
}

void LCDPut(char A)
{
	_uLCDloops = LCD_F_INSTR;
//	PMADDR = 0x0001;
    PMPSetAddress(0x0001); 
	PMDIN1 = A;
	while(_uLCDloops)
	_uLCDloops--;
	Nop();
	Nop();
	Nop();
	Nop();
}



void Wait(unsigned int B)
{
	while(B)
	B--;
}


void DisplayMSG(unsigned char *array)
{
  unsigned char i=0,line=1;	
	LCDL1Home();	
	 while (*array)           // Continue display characters from STRING untill NULL character appears.
	 {
	  LCDPut(*array++);  // Display selected character from the STRING.
	  if (i>19 && line==1)
	  {
	   LCDL2Home();
	   line++;
	  }
	   i++;	        
     }
}
