/**********************************************************************
* 2011 Microchip Technology Inc.
*
* FileName:        numtoletter.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       PIC24FJ128GA010
* Compiler:        MPLAB C30 v3.11 or higher
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
* Author            Date      		Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Mark Pallones		02/25/11		First Release
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
* Code Tested on:
* Explorer 16 Demo board with  PIC24FJ128GA010 controller
*
* DESCRIPTION:
* This code example describes how to use RTCC on PIC24F. Here I display
* Year,Day,Week,Weekday,Hour,Minute,Seconds using RTCC on the LCD via PMP. It also display
* a message on the LCD once the alarm is triggered.Based on initial condition the alarm will trigger after 30 sec 
* where the date will change from July 11 to July 12
***********************************************************************************************************/
#include <p24fj128ga010.h>
#include "LCD.h"
#include "rtcc.h"


RTCC _time;
RTCC _time_chk;

char _time_str[16] = "                ";		
char _date_str[16] = "                ";


void displayTime(void)
{
	// Process time object only if time is not being set
	while (1) {
		// Grab the time
		RCFGCALbits.RTCPTR = 0;			
		_time.prt00 = RTCVAL;
		RCFGCALbits.RTCPTR = 1;			
		_time.prt01 = RTCVAL;
		RCFGCALbits.RTCPTR = 2;			
		_time.prt10 = RTCVAL;
		RCFGCALbits.RTCPTR = 3;			
		_time.prt11 = RTCVAL;

		// Grab the time again 
		RCFGCALbits.RTCPTR = 0;			
		_time_chk.prt00 = RTCVAL;
		RCFGCALbits.RTCPTR = 1;			
		_time_chk.prt01 = RTCVAL;
		RCFGCALbits.RTCPTR = 2;			
		_time_chk.prt10 = RTCVAL;
		RCFGCALbits.RTCPTR = 3;			
		_time_chk.prt11 = RTCVAL;

		// Verify there is no roll-over
		if ((_time.prt00 == _time_chk.prt00) &&
			(_time.prt01 == _time_chk.prt01) &&
			(_time.prt10 == _time_chk.prt10) &&
			(_time.prt11 == _time_chk.prt11))
		{
			switch (_time.mth) {
				default:
				case 0x01: _date_str[0] = 'J'; _date_str[1] = 'a'; _date_str[2] = 'n'; break; 
				case 0x02: _date_str[0] = 'F'; _date_str[1] = 'e'; _date_str[2] = 'b'; break; 
				case 0x03: _date_str[0] = 'M'; _date_str[1] = 'a'; _date_str[2] = 'r'; break; 
				case 0x04: _date_str[0] = 'A'; _date_str[1] = 'p'; _date_str[2] = 'r'; break; 
				case 0x05: _date_str[0] = 'M'; _date_str[1] = 'a'; _date_str[2] = 'y'; break; 
				case 0x06: _date_str[0] = 'J'; _date_str[1] = 'u'; _date_str[2] = 'n'; break; 
				case 0x07: _date_str[0] = 'J'; _date_str[1] = 'u'; _date_str[2] = 'l'; break; 
				case 0x08: _date_str[0] = 'A'; _date_str[1] = 'u'; _date_str[2] = 'g'; break; 
				case 0x09: _date_str[0] = 'S'; _date_str[1] = 'e'; _date_str[2] = 'p'; break; 
				case 0x10: _date_str[0] = 'O'; _date_str[1] = 'c'; _date_str[2] = 't'; break; 
				case 0x11: _date_str[0] = 'N'; _date_str[1] = 'o'; _date_str[2] = 'v'; break; 
				case 0x12: _date_str[0] = 'D'; _date_str[1] = 'e'; _date_str[2] = 'c'; break; 
			}
             
			_date_str[3] = ' ';
			_date_str[6] = ',';
			_date_str[7] = ' ';
			_date_str[8] = '2';
			_date_str[9] = '0';

			_date_str[4] = (_time.day >> 4) + '0';
			_date_str[5] = (_time.day & 0xF) + '0';

			_date_str[10] = (_time.yr >> 4) + '0';
			_date_str[11] = (_time.yr & 0xF) + '0';

			switch (_time.wkd) {
				default:
				case 0x00: _time_str[0] = 'S'; _time_str[1] = 'u'; _time_str[2] = 'n'; break; 
				case 0x01: _time_str[0] = 'M'; _time_str[1] = 'o'; _time_str[2] = 'n'; break; 
				case 0x02: _time_str[0] = 'T'; _time_str[1] = 'u'; _time_str[2] = 'e'; break; 
				case 0x03: _time_str[0] = 'W'; _time_str[1] = 'e'; _time_str[2] = 'd'; break; 
				case 0x04: _time_str[0] = 'T'; _time_str[1] = 'h'; _time_str[2] = 'u'; break; 
				case 0x05: _time_str[0] = 'F'; _time_str[1] = 'r'; _time_str[2] = 'i'; break; 
				case 0x06: _time_str[0] = 'S'; _time_str[1] = 'a'; _time_str[2] = 't'; break;  
			}
			
			_time_str[3] = ' ';
			_time_str[6] = ':';
			_time_str[9] = ':';

			_time_str[4] = (_time.hr >> 4) + '0';
			_time_str[5] = (_time.hr & 0xF) + '0';

			_time_str[7] = (_time.min >> 4) + '0';
			_time_str[8] = (_time.min & 0xF) + '0';

			_time_str[10] = (_time.sec >> 4) + '0';
			_time_str[11] = (_time.sec & 0xF) + '0';
            
             
			break;
		}	
   
 	}
// display time in second line of LCD
dispsecLine(0);

putstringLCD(_time_str);

// display date in first line of LCD
dispfirstLine(0);

putstringLCD(_date_str);
}

