/*
********************************************************************************
[File]          : ELB_LCD.c
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : Macros and functions for LCD communication
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR] 				CHANGES
 v0.1	   	30.12.2012 	gopal.jatiya@brigosha.com		Origin
********************************************************************************
*/

#ifndef ELB_LCD_H
#define	ELB_LCD_H

/*** BRIGOSHA LIBRARY ***/
#include "ELB_OSC.h"
#include "ELB_I2C.h"

/*** MACROS FOR LCD COMMANDS AND COMMUNICATION ***/
#define C_LCD_I2CAdress     0x3E
#define C_CommandAdr        0x00
#define C_DataAddr          0x40
#define C_NewLine           0xC0
#define C_DisplayCLR        0x01
#define C_DisplayHome       0x02

/*** PUBLIC APIs ***/
void INIT_LCD(void);
void LCD_WriteString(U8 ,U8 ,U8 *);
void LCD_Clear(void);

#endif	/* CONFIG_LCD_H */

