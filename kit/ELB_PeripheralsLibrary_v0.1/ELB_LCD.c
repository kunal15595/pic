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
[File]          : ELB_LCD.c
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : LCD intiialize, clear and write functions
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR] 				CHANGES
 v0.1	   	30.12.2012 	gopal.jatiya@brigosha.com		Origin
********************************************************************************
*/

#include "ELB_LCD.h"

/*** GLOBAL VARIABLES ***/
U8 V_LCDCommand_U8;

/*** LOCAL FUNCTIONS ***/
void LCD_Home(void);
void LCD_NewLine(void);

/*
--------------------------------------------------------------------------------
[NAME]  	 : LCD_INIT
[TYPE]		 : Public API
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]    : This function initializes the LCD. 
--------------------------------------------------------------------------------
*/
void LCD_INIT(void)
{
    I2C3_INIT(400000, MI2C_INT_PRI0 );          //Specify I2C3 Clock

    /*** Wait for 40 mSec ***/
    DELAY_mSec(40);

    /*** Function Set (0x38), Wait = 30 uSec  ***/
    V_LCDCommand_U8=0x38;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(1);

    /*** Function Set (0x39), Wait = 30 uSec ***/
    V_LCDCommand_U8=0x39;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(1);

    /*** InternalOSc Freq Set (0x14), Wait = 30 uSec ***/
    V_LCDCommand_U8=0x14;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(1);

    /*** Contrast Set (0x78), Wait = 30 uSec ***/
    V_LCDCommand_U8=0x78;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(1);

    /*** Power ICON/Contrast/Control (0x5E), Wait = 30 uSec ***/
    V_LCDCommand_U8=0x5D;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(1);

    /*** Follower Control (0x6A) 0x6D, Wait = 200 mSec ***/
    V_LCDCommand_U8=0x6D;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(200);

    /*** Display ON/OFF (0x0C) , Wait = 30 uSec ***/
    V_LCDCommand_U8=0x0C;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(1);

    /*** CLEAR Display (0x01) , Wait = 2 mSec ***/
    V_LCDCommand_U8=0x01;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(2);

    /*** Entry Mode Set (0x06) , Wait = 30 uSec ***/
    V_LCDCommand_U8=0x06;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(10);

    /*** Function Set (0x39), Wait = 30 uSec ***/
    V_LCDCommand_U8=0x39;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(1);
    /*** CLEAR Display (0x01) , Wait = 2 mSec ***/
    V_LCDCommand_U8=0x01;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(2);

}

/*
--------------------------------------------------------------------------------
[NAME]  	 : LCD_WriteString
[TYPE]		 : Public API
[INPUT] 	 : v_Row_u8: Vertical Cursor Position: (Line Number 1 or 2)
                   v_Column_u8: Horizontal Cursor Position: (1-16)
                   p_String_u8: Pointer to the text to be written on LCD
[RETURN]	 : None
[DESCRIPTION]    : This function prints the string on the LCD. The length of string
                   should be not more than 32, if written on the 1st line and not
                   more than 16 if written in the 2nd line
--------------------------------------------------------------------------------
*/
void LCD_WriteString(U8 v_Row_u8,U8 v_Column_u8,U8 *p_String_u8)
{
    U8 a_TempBuffer_u8[16];
    U8 v_Index_u8=0;
    U8 v_Counter_u8;
    U8 v_Length_u8=0;

    if(v_Row_u8==1)
    {
        LCD_Home();
    }
    else
        LCD_NewLine();

    V_LCDCommand_U8=0x38;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    DELAY_mSec(1);

    for(v_Counter_u8=0;v_Counter_u8<(v_Column_u8-1);v_Counter_u8++)
    {
        V_LCDCommand_U8=0x14;
        I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
    }

    while(p_String_u8[v_Index_u8++]!='\0')
        v_Length_u8++;
    v_Index_u8=0;
    if(v_Length_u8<=(16-v_Column_u8+1))
        I2C3_WRITE_String(C_LCD_I2CAdress,C_DataAddr, p_String_u8, v_Length_u8 );	// Write  Text
    else
    {
        
        if(v_Row_u8==1)
        {    I2C3_WRITE_String(C_LCD_I2CAdress,C_DataAddr, p_String_u8, 16-v_Column_u8+1 );
            for(v_Counter_u8=16-v_Column_u8+1;v_Counter_u8<v_Length_u8;v_Counter_u8++)
            {
                a_TempBuffer_u8[v_Index_u8++]=p_String_u8[v_Counter_u8];
                if(v_Index_u8==16)
                {
                    break;
                }
            }
            LCD_NewLine();
            I2C3_WRITE_String(C_LCD_I2CAdress,C_DataAddr, a_TempBuffer_u8, v_Index_u8 );
        }
        else
            I2C3_WRITE_String(C_LCD_I2CAdress,C_DataAddr, p_String_u8, 16-v_Column_u8+1 );
    }

}

/*
--------------------------------------------------------------------------------
[NAME]  	 : LCD_Clear
[TYPE]		 : Public API
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]    : This function clears the LCD
--------------------------------------------------------------------------------
*/
void LCD_Clear(void)
{
    V_LCDCommand_U8=C_DisplayCLR;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
}

/*
--------------------------------------------------------------------------------
[NAME]  	 : LCD_Home
[TYPE]		 : Local Function
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]    : This function sets the cursor to beginning of line 1
--------------------------------------------------------------------------------
*/
void LCD_Home(void)
{
    V_LCDCommand_U8=C_DisplayHome;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
}

/*
--------------------------------------------------------------------------------
[NAME]  	 : LCD_NewLine
[TYPE]		 : Local Function
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]    : This function sets the cursor to beginning of line 2
--------------------------------------------------------------------------------
*/
void LCD_NewLine(void)
{
    V_LCDCommand_U8=C_NewLine;
    I2C3_WRITE_Byte(C_LCD_I2CAdress,C_CommandAdr, &V_LCDCommand_U8);
}

