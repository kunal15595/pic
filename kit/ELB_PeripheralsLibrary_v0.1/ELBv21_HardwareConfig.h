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
[File]          : ELBv21_HardwareConfig.h
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : ELB default hardware configuration Macros and Functions
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR] 				CHANGES
 v0.1	   	01.10.2012 	shashi.prakash@brigosha.com		Origin
********************************************************************************
*/

#ifndef ELBV21_HARDWARECONFIG_H
#define	ELBV21_HARDWARECONFIG_H

/*** MICROCHIP LIBRARY ***/
#include <p24FJ256GB206.h>
#include <ports.h>
#include <PPS.h>

/*** BRIGOSHA LIBRARY ***/
#include "Define.h"


/********** Constants  **********/
#define DIR_OUT	0
#define DIR_IN	1

#define USE1 0b00000001
#define USE2 0b00000010
#define USE3 0b00000100
#define USE4 0b00001000
#define USE5 0b00010000
#define USE6 0b00100000
#define USE7 0b01000000
#define USE8 0b10000000

/********** IO **********/
// Sch :(RE4);  (RE5); (RB8); (RB9); (RF3)

#define RE4_OUT   (             _TRISE4 = 0, _RE4=0)
#define RE5_OUT   (             _TRISE5 = 0, _RE5=0)
#define RB8_OUT   (_ANSB8 = 0,  _TRISB8 = 0, _RB8=0)
#define RB9_OUT   (_ANSB9 = 0,  _TRISB9 = 0, _RB9=0)
#define RF3_OUT   (             _TRISF3 = 0, _RF3=0)

#define RE4_IN    (             _TRISE4 = 1, _RE4=0)
#define RE5_IN    (             _TRISE5 = 1, _RE5=0)
#define RB8_IN    (_ANSB8 = 0,  _TRISB8 = 1, _RB8=0)
#define RB9_IN    (_ANSB9 = 0,  _TRISB9 = 1, _RB9=0)
#define RF3_IN    (             _TRISF3 = 1, _RF3=0)

/********** ADC **********/
// Sch :(ADC1= ANO= RB0);  (ADC2= AN1= RB1); (ADC1= AN2= RB3); (ADC1= AN3= RB3);

/********** LEDs **********/
// Sch : (LED1 = RE1);  (LED2 = RE2); (LED3 = RE3);

#define LED1_DIR _TRISE1	// LED1 direction bit
#define LED2_DIR _TRISE2	// LED2 direction bit
#define LED3_DIR _TRISE3	// LED3 direction bit

#define LED1    _LATE1		// LED1 latch bit
#define LED2    _LATE2		// LED2 latch bit
#define LED3    _LATE3		// LED3 latch bit

#define M_ToggleIO(GPIO)    (GPIO = !GPIO)   	// Toggle GPIO

/********** DC/Stepper Motor **********/
// Sch : (A1 = RB10);  (A2 = RB11); (B1 = RB12); (B2 = RB13)

#define  MotA1_DIR _TRISB10
#define  MotA2_DIR _TRISB11
#define  MotB1_DIR _TRISB12
#define  MotB2_DIR _TRISB13

#define MotA1 _LATB10
#define MotA2 _LATB11
#define MotB1 _LATB12
#define MotB2 _LATB13

/********** DC/Stepper Motor **********/
// Sch : (PWM1 = RD11);  (PWM2 = RD8); (PWM3 = RD0); (PWM4 = RD1)

#define  PWM1_DIR _TRISD11
#define  PWM2_DIR _TRISD8
#define  PWM3_DIR _TRISD0
#define  PWM4_DIR _TRISD1

#define  PWM1 _LATD11
#define  PWM2 _LATD8
#define  PWM3 _LATD0
#define  PWM4 _LATD1

/********** Push Buttons **********/
// Sch : (PB1 = RE0= CN58);  (PB2 = RF1= CN69); (PB3 = RF0=CN68);

#define  PB1_DIR _TRISE0
#define  PB2_DIR _TRISF1
#define  PB3_DIR _TRISF0

#define  PB1 _RE0
#define  PB2 _RF1
#define  PB3 _RF0

#define Enable_PB1Int()     (CNPD4bits.CN58PDE = 1, CNEN4bits.CN58IE = 1, IEC1bits.CNIE = 1)
#define Enable_PB2Int()     (CNPD5bits.CN69PDE = 1, CNEN5bits.CN69IE = 1, IEC1bits.CNIE = 1)
#define Enable_PB3Int()     (CNPD5bits.CN68PDE = 1, CNEN5bits.CN68IE = 1, IEC1bits.CNIE = 1)
#define Enable_PB123Int()   (Enable_PB1Int(), Enable_PB2Int(), Enable_PB3Int())

#define Disable_PB1Int()     (CNPD4bits.CN58PDE = 0, CNEN4bits.CN58IE = 0, IEC1bits.CNIE = 0)
#define Disable_PB2Int()     (CNPD5bits.CN69PDE = 0, CNEN5bits.CN69IE = 0, IEC1bits.CNIE = 0)
#define Disable_PB3Int()     (CNPD5bits.CN68PDE = 0, CNEN5bits.CN68IE = 0, IEC1bits.CNIE = 0)
#define Disable_PB123Int()   (Disable_PB1Int(), Disable_PB2Int(), Disable_PB3Int())

/********** UART **********/
// Sch : (TX1= RE0= RB5); (RX1= RF1= RB4);(TX2= RB14= RP14); (RX2= RB15= RP29);

/********** SPI **********/
// Sch SPI1: (SS1= RD5= RP20); (SDI1= RD4= RP25);(SDO1= RD3= RP22); (SCK1= RD2= RP23);

#define SS1_DIR  _TRISD5
#define SDI1_DIR _TRISD4
#define SDO1_DIR _TRISD3
#define SCK1_DIR _TRISD2

#define SS1  _LATD5
#define SDI1 _LATD4
#define SDO1 _LATD3
#define SCK1 _LATD2

// Sch SPI2: (SS2= RG9= RP27); (SDI2= RG8= RP19);(SDO2= RG7= RP26); (SCK2= RG6= RP21);

#define SS2_DIR  _TRISG9
#define SDI2_DIR _TRISG8
#define SDO2_DIR _TRISG7
#define SCK2_DIR _TRISG6

#define SS2  _LATG9
#define SDI2 _LATG8
#define SDO2 _LATG7
#define SCK2 _LATG6

/*** Local functions, placed in Hardware Structure ***/
void ConfigPins_ADC(U8 );

void ConfigPins_UART1(void );
void ConfigPins_UART2(void);
void ConfigPins_SPI1(void);
void ConfigPins_SPI2(void);

void ConfigPins_LED(U8 );
void ConfigPins_PWM(U8 );
void ConfigPins_Motor(U8 );
void ConfigPins_PB(U8 );

/*** Integrated Hardware Structure ***/

typedef struct
{
    /**< function to configure ADC pins. Pass macros from EAB_HardwareConfig.h */
    void (* ConfigPins_ADC)(U8);
    /**< function to configure LED pins. Pass macros from EAB_HardwareConfig.h */
    void (* ConfigPins_LED)(U8);
    /**< function to configure Motor pins. Pass macros from EAB_HardwareConfig.h */
    void (* ConfigPins_Motor)(U8);
    /**< function to configure PWM pins. Pass macros from EAB_HardwareConfig.h */
    void (* ConfigPins_PWM)(U8);
    /**< function to configure PB pins. Pass macros from EAB_HardwareConfig.h */
    void (* ConfigPins_PB)(U8);
  
    /**< function to configure UART1 pins. */
    void (* ConfigPins_UART1)();
    /**< function to configure UART2 pins. */
    void (* ConfigPins_UART2)();
    /**< function to configure SPI1 pins. */
    void (* ConfigPins_SPI1)();
    /**< function to configure SPI2 pins. */
    void (* ConfigPins_SPI2)();

    void (* ConfigPins_Default)();
    
}ts_ELB_Hardware;


void Hardware_INIT(void);

#endif	/* ELBV21_HARDWARECONFIG_H */


