#ifndef __AVIX_LCD_h__
#define __AVIX_LCD_h__

/*=================================================================================================
**
**	===============================================================================================
**	PRODUCT:			---------- AVIX - (ADVANCED VIRTUAL INTEGRATED EXECUTIVE) RTOS ------------
**	===============================================================================================
**
**	===============================================================================================
** 	PRODUCT VERSION: 	4.1
** 	COPYRIGHT:			AVIX-RT EMBEDDED SOLUTIONS
**	===============================================================================================
**
**	===============================================================================================
**	UNDER NO CIRCUMSTANCE MAY THE CONTENT OF THIS FILE BE CHANGED. ANY CHANGE OF THE DEFINITIONS IN
**	THIS FILE MAY  LEAD TO AVIX  NOT WORKING OR WORKING  IN A UNPREDICTABLE  MANNER.
**	===============================================================================================
**
**	SOFTWARE LICENSE AGREEMENT
**	--------------------------
**
**	THE  SOFTWARE  SUPPLIED  HEREWITH  AS  THE  CONTENT  OF  THIS FILE IS OWNED BY AVIX-RT EMBEDDED
**	SOLUTIONS  (THE "COMPANY"), AND IS PROTECTED  UNDER APPLICABLE  COPYRIGHT LAWS.  ALL RIGHTS ARE
**	RESERVED.  THE SOFTWARE IS SUPPLIED TO YOU (THE "CUSTOMER")  FOR USE  SOLELY AND EXCLUSIVELY AS
**	PART OF AND TOGETHER WITH PRODUCTS MANUFACTURED BY "COMPANY" AND LICENSED TO "CUSTOMER".
**
**	"COMPANY" LICENSES "CUSTOMER"  THE RIGHT TO USE  THIS FILE FOR THE  SOLE PURPOSE  OF DEVELOPING
**	APPLICATION SOFTWARE BASED ON ONE OF "COMPANIES" PRODUCTS AND FOR EXCLUSIVE USE ON A  SUPPORTED
**	MICROCONTROLLER.
**
**	UNDER NO CIRCUMSTANCE  MAY THE CONTENT OF  THIS FILE,  EITHER PARTIALLY  OR COMPLETE,  BE  MADE
**	PUBLIC, EITHER ELECTRONICALLY OR PRINTED.
**
**	ANY VIOLATION TO THE FOREGOING RESTRICTIONS  MAY SUBJECT THE USER  TO CRIMINAL SANCTIONS  UNDER
**	APPLICABLE LAWS, AS WELL AS TO CIVIL  LIABILITY FOR  THE BREACH  OF THE TERMS AND CONDITIONS OF
**	THIS LICENSE.
**
**	YOU SHOULD REFER TO THE LICENSE AGREEMENT  ACCOMPANYING THE  PRODUCT THIS  SOFTWARE IS  PART OF
**	FOR ADDITIONAL INFORMATION REGARDING YOUR RIGHTS AND OBLIGATIONS.
**
**	THE SOFTWARE  AND DOCUMENTATION  ARE PROVIDED  "AS IS"  WITHOUT  WARRANTY  OF ANY  KIND, EITHER
**	EXPRESS OR IMPLIED, INCLUDING WITHOUT  LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR
**	A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL "COMPANY" BE LIABLE FOR ANY
**	INCIDENTAL, SPECIAL,  INDIRECT OR  CONSEQUENTIAL DAMAGES,  LOST PROFITS  OR LOST  DATA, COST OF
**	PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING
**	BUT NOT  LIMITED TO ANY DEFENSE  THEREOF),  ANY CLAIMS  FOR  INDEMNITY OR CONTRIBUTION,OR OTHER
**	SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF  CONTRACT, TORT  (INCLUDING NEGLIGENCE), BREACH
**	OF WARRANTY, OR OTHERWISE.
**
**	COPYRIGHT (C) 2006-2010 AVIX-RT EMBEDDED SOLUTIONS.  ALL RIGHTS RESERVED.
**
**	===============================================================================================
**
**	Description:
**  ------------
**	Interface of the generic LCD module.
**
**=================================================================================================
**
**	History:
**-------------------------------------------------------------------------------------------------
**	File version	Date		Author	Description
**-------------------------------------------------------------------------------------------------
**	1.0.0			12212008	LvS		Initial version
**
**=================================================================================================
**
**=================================================================================================
** INCLUDES
**=================================================================================================
*/
#include "AVIXThread.h"


/*=================================================================================================
** EXTERNAL DECLARATIONS
**=================================================================================================
*/
tavixThreadId	avixLCD_Init(void);
void 			avixLCD_Write(char* pText, int row, int column, int blink);
void 			avixLCD_SetBlinkMode(int row, int column, int count, int blink);





/*=================================================================================================
** TYPE DEFINITIONS
**=================================================================================================
*/


/*=================================================================================================
** MACROS
**=================================================================================================
**
*/

#endif	/* __AVIX_LCD_h__ */
