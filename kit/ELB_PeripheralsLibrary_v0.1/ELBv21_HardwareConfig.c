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
[File]          : ELBv21_HardwareConfig.c
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : ELB default hardware configuration functions
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR] 				CHANGES
 v0.1	   	01.10.2012 	shashi.prakash@brigosha.com		Origin
********************************************************************************
*/

#include "ELBv21_HardwareConfig.h"

ts_ELB_Hardware Hardware;
/*
--------------------------------------------------------------------------------
[NAME]  	 : ConfigPins_ADC
[TYPE]		 : Internal Function & accessible publically through structure
[INPUT] 	 : ADCs use status eg. pass parameters as (USE1| USE2| USE3)
[RETURN]	 : None
[DESCRIPTION]: This function configures the ADC pins.
--------------------------------------------------------------------------------
 */
void ConfigPins_ADC(U8 v_ADCUse_U8)
{
    /*** Configure ADC1 ***/
    if((v_ADCUse_U8&0x01) == 0x01)
    {
        TRISBbits.TRISB0 = DIR_IN;         	// Set ADC3 as Output
	ANSBbits.ANSB0 = C_ON;             	// Enable analog function
    }
    /*** Configure ADC2 ***/
    if((v_ADCUse_U8&0x02) == 0x02)
    {
        TRISBbits.TRISB1 = DIR_IN;         	// Set ADC3 as Output
	ANSBbits.ANSB1 = C_ON;             	// Enable analog function
    }
    /*** Configure ADC3 ***/
    if((v_ADCUse_U8&0x04) == 0x04)
    {
        TRISBbits.TRISB2 = DIR_IN;         	// Set ADC3 as Output
	ANSBbits.ANSB2 = C_ON;             	// Enable analog function
    }
    /*** Configure ADC4 ***/
    if((v_ADCUse_U8&0x08) == 0x08)
    {
        TRISBbits.TRISB3 = DIR_IN;         	// Set ADC3 as Output
	ANSBbits.ANSB3 = C_ON;             	// Enable analog function
    }

}


/*
--------------------------------------------------------------------------------
[NAME]  	 : ConfigPins_LED
[TYPE]		 : Internal Function & accessible publically through structure
[INPUT] 	 : LEDs use status, eg. pass parameters as (USE1| USE2| USE3)
[RETURN]	 : None
[DESCRIPTION]: This function configures the LED pins.
--------------------------------------------------------------------------------
 */
void ConfigPins_LED(U8 v_LEDUse_U8)
{
    /*** Configure LED1 ***/
    if((v_LEDUse_U8&0x01) == 0x01)
    {
         LED1_DIR = DIR_OUT;                    // Set LED1 as Output
	 LED1 = C_OFF;                      	// Set state to OFF        
    }
    /*** Configure LED2 ***/
    if((v_LEDUse_U8&0x02) == 0x02)
    {
	 LED2_DIR = DIR_OUT;                	// Set LED2 as Output
	 LED2 = C_OFF;                      	// Set state to OFF
    }
    /*** Configure LED3 ***/
    if((v_LEDUse_U8&0x04) == 0x04)
    {
        LED3_DIR = DIR_OUT;                     // Set LED3 as Output
	LED3 = C_OFF;                       	// Set state to OFF
    }
}


/*
--------------------------------------------------------------------------------
[NAME]  	 : ConfigPins_PWM
[TYPE]		 : Internal Function & accessible publically through structure
[INPUT] 	 : PWMs use status, eg. pass parameters as (USE1| USE2| USE3)
[RETURN]	 : None
[DESCRIPTION]: This function configures the PWM pins.
--------------------------------------------------------------------------------
 */
void ConfigPins_PWM(U8 v_PWMUse_U8)
{
    /*** Configure PWM1 ***/
    if((v_PWMUse_U8&0x01) == 0x01)
    {
         PWM1_DIR = DIR_OUT;                            // Set PWM1 as Output
	 PWM1 = C_OFF;                                  // Set state to OFF
         iPPSOutput(OUT_PIN_PPS_RP12, OUT_FN_PPS_OC1);  //Assing OC1 to pin PWM1
    }
    /*** Configure PWM2 ***/
    if((v_PWMUse_U8&0x02) == 0x02)
    {
	 PWM2_DIR = DIR_OUT;                            // Set PWM2 as Output
	 PWM2 = C_OFF;                                  // Set state to OFF
         iPPSOutput(OUT_PIN_PPS_RP2, OUT_FN_PPS_OC2);   //Assing OC1 to pin PWM1
    }
    /*** Configure PWM3 ***/
    if((v_PWMUse_U8&0x04) == 0x04)
    {
        PWM3_DIR = DIR_OUT;                             // Set PWM3 as Output
	PWM3 = C_OFF;                                   // Set state to OFF
        iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_OC3);   //Assing OC1 to pin PWM1
    }
    /*** Configure PWM4 ***/
    if((v_PWMUse_U8&0x08) == 0x08)
    {
        PWM4_DIR = DIR_OUT;                             // Set PWM4 as Output
	PWM4 = C_OFF;                                   // Set state to OFF
        iPPSOutput(OUT_PIN_PPS_RP24, OUT_FN_PPS_OC4);  //Assing OC1 to pin PWM1
    }
}

/*
--------------------------------------------------------------------------------
[NAME]  	 : ConfigPins_Motor
[TYPE]		 : Internal Function & accessible publically through structure
[INPUT] 	 : Motor use status eg. pass parameters as (USE1| USE2| USE3)
[RETURN]	 : None
[DESCRIPTION]: This function configures the Motor pins.
--------------------------------------------------------------------------------
 */

void ConfigPins_Motor(U8 v_MotorUse_U8 )
{
    /*** Configure Motor A ***/
    if((v_MotorUse_U8&0x01) == 0x01)
    {
        MotA1_DIR = DIR_OUT;               	// Set Motor A1 as Output
        MotA2_DIR = DIR_OUT;               	// Set Motor A2 as Output

        MotA1 = C_OFF;                    	// Set state to OFF
		MotA2 = C_OFF;                  // Set state to OFF
    }
    /*** Configure Motor B ***/
    if((v_MotorUse_U8&0x02) == 0x02)
    {
        MotB1_DIR = DIR_OUT;               	// Set Motor B1 as Output
        MotB2_DIR = DIR_OUT;               	// Set Motor B2 as Output

        MotB1 = C_OFF;                    	// Set state to OFF
		MotB2 = C_OFF;                  // Set state to OFF
    }


}

/*
--------------------------------------------------------------------------------
[NAME]  	 : ConfigPins_PB
[TYPE]		 : Internal Function & accessible publically through structure
[INPUT] 	 : PushButton use status
[RETURN]	 : None
[DESCRIPTION]: This function configures the PushButton pins.
--------------------------------------------------------------------------------
 */
void ConfigPins_PB(U8 v_PBUse_U8)
{
    /*** Configure Push Button1 ***/
    if((v_PBUse_U8&0x01) == 0x01)
    {
         PB1_DIR = DIR_IN;                  // Set Push Button1 as input
		PB1 = C_OFF;                // Set state to OFF
    }
    else
    {
        PB1_DIR = DIR_OUT;                  // Set Push Button1 as Output
        PB1 = C_OFF;                        // Set state to OFF
    }
    /*** Configure Push Button2 ***/
    if((v_PBUse_U8&0x02) == 0x02)
    {
		PB2_DIR = DIR_IN;           // Set Push Button2 as input
		PB2 = C_OFF;                // Set state to OFF
    }
    else
    {
        PB2_DIR = DIR_OUT;                  // Set Push Button2 as input
        PB2 = C_OFF;                        // Set state to OFF
    }
    /*** Configure Push Button3 ***/
    if((v_PBUse_U8&0x04) == 0x04)
    {
        _ANSF0 = 0;
        PB3_DIR = DIR_IN;                   // Set Push Button3 as input
	PB3 = C_OFF;                        // Set state to OFF
    }
    else
    {
        _ANSF0 = 0;
        PB3_DIR = DIR_OUT;                  // Set Push Button3 as input
	PB3 = C_OFF;                        // Set state to OFF
    }
}



/*
--------------------------------------------------------------------------------
[NAME]  	 : ConfigPins_UART 1
[TYPE]		 : Internal Function & accessible publically through structure
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]: This function maps the remappable pins to UART1.
--------------------------------------------------------------------------------
*/
void ConfigPins_UART1(void)
{    
    /*** Assign UART1 pins using PPS ***/  
    _ANSB4 = 0;     	_ANSB5 = 0;
    TRISBbits.TRISB4 = 1; 	TRISBbits.TRISB5 = 0;
    iPPSInput(IN_FN_PPS_U1RX,IN_PIN_PPS_RP28);      //Assing U1RX to pin P_RX1_RP
    iPPSOutput(OUT_PIN_PPS_RP18, OUT_FN_PPS_U1TX);  //Assing U1TX to pin P_TX2_RP

}
/*
--------------------------------------------------------------------------------
[NAME]  	 : ConfigPins_UART 2
[TYPE]		 : Internal Function & accessible publically through structure
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]: This function maps the remappable pins to UART2.
--------------------------------------------------------------------------------
*/

void ConfigPins_UART2(void)
{
    /*** Assign UART2 pins using PPS ***/
    _ANSB15 = 0;            _ANSB14 = 0;
    TRISBbits.TRISB15 = 1;  TRISBbits.TRISB14 = 0;
    iPPSInput(IN_FN_PPS_U2RX, IN_PIN_PPS_RP29);     //Assing U1RX to pin P_RX1_RP
    iPPSOutput(OUT_PIN_PPS_RP14, OUT_FN_PPS_U2TX);  //Assing U1TX to pin P_TX2_RP
}

/*
--------------------------------------------------------------------------------
[NAME]  	 : ConfigPins_SPI 1
[TYPE]		 : Internal Function & accessible publically through structure
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]: This function maps the remappable pins to SPI1.
--------------------------------------------------------------------------------
*/
void ConfigPins_SPI1(void)
{
    /*** Assign SPI1 pins using PPS ***/
    SS1_DIR = DIR_OUT;  SDI1_DIR = DIR_IN ;
    SDO1_DIR = DIR_OUT; SCK1_DIR = DIR_OUT;

    iPPSOutput(OUT_PIN_PPS_RP20, OUT_FN_PPS_SS1OUT);
    iPPSInput( IN_FN_PPS_SDI1  , IN_PIN_PPS_RP25 );
    iPPSOutput(OUT_PIN_PPS_RP22, OUT_FN_PPS_SDO1);
    iPPSOutput(OUT_PIN_PPS_RP23, OUT_FN_PPS_SCK1OUT);


}
/*
--------------------------------------------------------------------------------
[NAME]  	 : ConfigPins_SPI 2
[TYPE]		 : Internal Function & accessible publically through structure
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]: This function maps the remappable pins to SPI2.
--------------------------------------------------------------------------------
*/

void ConfigPins_SPI2(void)
{
    _ANSG9 = 0; _ANSG8 = 0;
    _ANSG7 = 0; _ANSG6 = 0;

    /*** Assign SPI1 pins using PPS ***/
    SS2_DIR = DIR_OUT;  SDI2_DIR = DIR_IN ;
    SDO2_DIR = DIR_OUT; SCK2_DIR = DIR_OUT;

    iPPSOutput(OUT_PIN_PPS_RP27, OUT_FN_PPS_SS2OUT);
    iPPSInput( IN_FN_PPS_SDI2  , IN_PIN_PPS_RP19 );
    iPPSOutput(OUT_PIN_PPS_RP26, OUT_FN_PPS_SDO2);
    iPPSOutput(OUT_PIN_PPS_RP21, OUT_FN_PPS_SCK2OUT);
}

/*
--------------------------------------------------------------------------------
[NAME]  	 : ConfigPins_Default
[TYPE]		 : Internal Function & accessible publically through structure
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]: This function Configueres the pins of ELB to Default Hardware config.
--------------------------------------------------------------------------------
*/
void ConfigPins_Default(void)
{
    __builtin_write_OSCCONL(OSCCON & 0xbf);
    Hardware.ConfigPins_ADC(USE1|USE2|USE3|USE4);
    Hardware.ConfigPins_LED(USE1|USE2|USE3);
    Hardware.ConfigPins_Motor(USE1|USE2);
    Hardware.ConfigPins_PWM(USE1|USE2|USE3|USE4);
    Hardware.ConfigPins_PB(USE1|USE2|USE3);

    Hardware.ConfigPins_UART1();
    Hardware.ConfigPins_UART2();
    Hardware.ConfigPins_SPI1();
    Hardware.ConfigPins_SPI2();
    __builtin_write_OSCCONL(OSCCON | 0x40);
}

/*
--------------------------------------------------------------------------------
[NAME]  	 : Hardware_INIT
[TYPE]		 : Publica API, Globally Accesible
[INPUT] 	 : None
[RETURN]	 : None
[DESCRIPTION]: This function initializes the hardware structure and its functions.
--------------------------------------------------------------------------------
*/

void Hardware_INIT(void)
{    
    Hardware.ConfigPins_ADC  = ConfigPins_ADC;
    Hardware.ConfigPins_LED  = ConfigPins_LED;
    Hardware.ConfigPins_Motor= ConfigPins_Motor;
    Hardware.ConfigPins_PWM  = ConfigPins_PWM;
    Hardware.ConfigPins_PB   = ConfigPins_PB;

    Hardware.ConfigPins_SPI1 = ConfigPins_SPI1;
    Hardware.ConfigPins_SPI2 = ConfigPins_SPI2;
    Hardware.ConfigPins_UART1= ConfigPins_UART1;
    Hardware.ConfigPins_UART2= ConfigPins_UART2;

    Hardware.ConfigPins_Default = ConfigPins_Default;
}


