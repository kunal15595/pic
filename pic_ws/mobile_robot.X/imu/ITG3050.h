/*
 * File:   	ITG3050.h
 * Created: 	7th August, 2012, 10:30 
 * Author:	gopal.jatiya@brigosha.com 
 * Version      v0.1
 * Comment:	Coding Standard Implemented
 */

#ifndef ITG3050_H
#define ITG3050_H
 
/*******Include Definitions*****************************/
#include "Define.h"

/*******I2C Specific****************************************/
#define C_ITG3050_I2CAdd1			0x68						// 7 bit adress of 0110100X, where last bit is defined by AD0 being low.
#define C_ITG3050_I2CAdd2			0x69						// 7 bit adress of 0110100X, where last bit is defined by AD0 being high.
#define C_ITG3050_I2CAdd			C_ITG3050_I2CAdd2

/* defines the return parameter type of the ITG3050_WR_FUNCTION

*/
#define M_ITG3050_BUS_WR_RETURN_TYPE S8

/* defines the calling parameter types of the ITG3050_WR_FUNCTION

*/
#define M_ITG3050_BUS_WR_PARAM_TYPES U8,U8,U8 *,U8

/* links the order of parameters defined in ITG3050_BUS_WR_PARAM_TYPE to function calls used inside the API

*/
#define M_ITG3050_BUS_WR_PARAM_ORDER v_DevAdd_u8, v_RegAdd_u8, v_RegVal_u8, v_Len_u8


/* Function pointer macro */
#define ITG3050_BUS_WRITE_FUNC(v_DevAdd_u8, v_RegAdd_u8, v_RegVal_u8, v_Len_u8)\
           bus_write( v_DevAdd_u8, v_RegAdd_u8, v_RegVal_u8, v_Len_u8 )




/* defines the return parameter type of the ITG3050_RD_FUNCTION

*/
#define M_ITG3050_BUS_RD_RETURN_TYPE S8

/* defines the calling parameter types of the ITG3050_RD_FUNCTION

*/
#define M_ITG3050_BUS_RD_PARAM_TYPES U8,U8,U8 *,U8

/* links the order of parameters defined in ITG3050_BUS_RD_PARAM_TYPE to function calls used inside the API

*/
#define M_ITG3050_BUS_RD_PARAM_ORDER v_DevAdd_u8, v_RegAdd_u8, v_RegVal_u8, v_Len_u8



/* Function pointer macro */
#define ITG3050_BUS_READ_FUNC(v_DevAdd_u8, v_RegAdd_u8, v_RegVal_u8, v_Len_u8)\
           bus_read( v_DevAdd_u8, v_RegAdd_u8, v_RegVal_u8, v_Len_u8 )


/****** ITG3050 Register Adress ****************************/
#define C_ITG3050_v_ChipID_u8		C_ITG3050_I2CAdd	//Chip ID of ITG3050 is its I2C address

#define C_ITG3050_RegAdd_ChipId   	0x00			// Chip id of ITG3050 is 0x-110100X, X can be high or low Depending on AD0				
#define C_ITG3050_RegAdd_X_OFFS_USRH	0x0C			// X Gyro offset MSB
#define C_ITG3050_RegAdd_X_OFFS_USRL	0x0D			// X Gyro offset LSB
#define C_ITG3050_RegAdd_Y_OFFS_USRH	0x0E			// Y Gyro offset MSB
#define C_ITG3050_RegAdd_Y_OFFS_USRL	0x0F			// Y Gyro offset LSB
#define C_ITG3050_RegAdd_Z_OFFS_USRH	0x10			// Z Gyro offset MSB
#define C_ITG3050_RegAdd_Z_OFFS_USRL	0x11			// Z Gyro offset LSB	
#define C_ITG3050_RegAdd_FIFO_EN	0x12			// FIFO enable register 
#define C_ITG3050_RegAdd_SMPLRT_DIV   	0x15			// Divider for the sampling rate "Fsample = Finternal/(divider+1)" 
#define C_ITG3050_RegAdd_RangeBW  	0x16			// Range of gyro measurement and Low Pass Filter to be used
#define C_ITG3050_RegAdd_IntConfig   	0x17			// Settings for Interrupt generation, latchign and clearing
#define C_ITG3050_RegAdd_IntStatus	0x1A			// Interrupt status for PLL ready and Raw v_data_u8 ready
#define C_ITG3050_RegAdd_TempH		0x1B			// High byte of temperature
#define C_ITG3050_RegAdd_TempL		0x1C			// Low byte of temperature
#define C_ITG3050_RegAdd_GyroXH		0x1D			// High byte of X rotation
#define C_ITG3050_RegAdd_GyroXL      	0x1E			// Low byte of X rotation
#define C_ITG3050_RegAdd_GyroYH		0x1F			// High byte of Y rotation
#define C_ITG3050_RegAdd_GyroYL      	0x20			// Low byte of Y rotation
#define C_ITG3050_RegAdd_GyroZH		0x21			// High byte of Z rotation
#define C_ITG3050_RegAdd_GyroZL      	0x22			// Low byte of Z rotation
#define C_ITG3050_RegAdd_FIFO_COUNT_H	0x3A			// FIFO counter MSB
#define C_ITG3050_RegAdd_FIFO_COUNT_L	0x3B			// FIFO counter LSB
#define C_ITG3050_RegAdd_FIFO_DATA	0x3C			// Oldest FIFO data
#define C_ITG3050_RegAdd_USER_CTRL	0x3D			// Register to control all functions of gyro
#define C_ITG3050_RegAdd_PowerMgmt      0X3E			// Reset, sleep mode, stand by , oscillator select

/*********bit slice positions in registers*/

/* Who am I register*/
#define C_ITG3050_CHIP_ID__POS		0
#define C_ITG3050_CHIP_ID__MSK		0x7F
#define C_ITG3050_CHIP_ID__LEN		7
#define C_ITG3050_CHIP_ID__REG		C_ITG3050_RegAdd_ChipId

/* Gyro Offset registers*/
#define C_ITG3050_X_OFFS_H__POS		0
#define C_ITG3050_X_OFFS_H__MSK		0xFF
#define C_ITG3050_X_OFFS_H__LEN		8
#define C_ITG3050_X_OFFS_H__REG		C_ITG3050_RegAdd_X_OFFS_USRH

#define C_ITG3050_X_OFFS_L__POS		0
#define C_ITG3050_X_OFFS_L__MSK		0xFF
#define C_ITG3050_X_OFFS_L__LEN		8
#define C_ITG3050_X_OFFS_L__REG		C_ITG3050_RegAdd_X_OFFS_USRL

#define C_ITG3050_Y_OFFS_H__POS		0
#define C_ITG3050_Y_OFFS_H__MSK		0xFF
#define C_ITG3050_Y_OFFS_H__LEN		8
#define C_ITG3050_Y_OFFS_H__REG		C_ITG3050_RegAdd_Y_OFFS_USRH

#define C_ITG3050_Y_OFFS_L__POS		0
#define C_ITG3050_Y_OFFS_L__MSK		0xFF
#define C_ITG3050_Y_OFFS_L__LEN		8
#define C_ITG3050_Y_OFFS_L__REG		C_ITG3050_RegAdd_Y_OFFS_USRL

#define C_ITG3050_Z_OFFS_H__POS		0
#define C_ITG3050_Z_OFFS_H__MSK		0xFF
#define C_ITG3050_Z_OFFS_H__LEN		8
#define C_ITG3050_Z_OFFS_H__REG		C_ITG3050_RegAdd_Z_OFFS_USRH

#define C_ITG3050_Z_OFFS_L__POS		0
#define C_ITG3050_Z_OFFS_L__MSK		0xFF
#define C_ITG3050_Z_OFFS_L__LEN		8
#define C_ITG3050_Z_OFFS_L__REG		C_ITG3050_RegAdd_Z_OFFS_USRL

/* FIFO Enable Register Bits*/
#define C_ITG3050_FIFO_FOOTER__POS	0
#define C_ITG3050_FIFO_FOOTER__MSK	0x01
#define C_ITG3050_FIFO_FOOTER__LEN	1
#define C_ITG3050_FIFO_FOOTER__REG	C_ITG3050_RegAdd_FIFO_EN

#define C_ITG3050_Gyro_Z__POS	4
#define C_ITG3050_Gyro_Z__MSK	0x10
#define C_ITG3050_Gyro_Z__LEN	1
#define C_ITG3050_Gyro_Z__REG	C_ITG3050_RegAdd_FIFO_EN

#define C_ITG3050_Gyro_Y__POS	5
#define C_ITG3050_Gyro_Y__MSK	0x20
#define C_ITG3050_Gyro_Y__LEN	1
#define C_ITG3050_Gyro_Y__REG	C_ITG3050_RegAdd_FIFO_EN

#define C_ITG3050_Gyro_X__POS	6
#define C_ITG3050_Gyro_X__MSK	0x40
#define C_ITG3050_Gyro_X__LEN	1
#define C_ITG3050_Gyro_X__REG	C_ITG3050_RegAdd_FIFO_EN

#define C_ITG3050_TempOut__POS	7
#define C_ITG3050_TempOut__MSK	0x80
#define C_ITG3050_TempOut__LEN	1
#define C_ITG3050_TempOut__REG	C_ITG3050_RegAdd_FIFO_EN

/* Sampling Rate divider Bits*/
#define C_ITG3050_SMPLRT_DIV__POS	0
#define C_ITG3050_SMPLRT_DIV__MSK	0xFF
#define C_ITG3050_SMPLRT_DIV__LEN	8
#define C_ITG3050_SMPLRT_DIV__REG	C_ITG3050_RegAdd_SMPLRT_DIV

/* External frame sync, range, bw bits*/
#define C_ITG3050_BW__POS		0		
#define C_ITG3050_BW__MSK		0x07
#define C_ITG3050_BW__LEN		3
#define C_ITG3050_BW__REG		C_ITG3050_RegAdd_RangeBW

#define C_ITG3050_Range__POS		3		
#define C_ITG3050_Range__MSK		0x18
#define C_ITG3050_Range__LEN		2
#define C_ITG3050_Range__REG		C_ITG3050_RegAdd_RangeBW

#define C_ITG3050_EXT_SYNC_SET__POS	5
#define C_ITG3050_EXT_SYNC_SET__MSK	0xE0
#define C_ITG3050_EXT_SYNC_SET__LEN	3
#define C_ITG3050_EXT_SYNC_SET__REG	C_ITG3050_RegAdd_RangeBW

/*Interrupt Configuration Bits*/
#define C_ITG3050_RAW_RDY_EN__POS	0
#define C_ITG3050_RAW_RDY_EN__MSK	0x01
#define C_ITG3050_RAW_RDY_EN__LEN	1
#define C_ITG3050_RAW_RDY_EN__REG	C_ITG3050_RegAdd_IntConfig

#define C_ITG3050_ITG_RDY_EN__POS	2
#define C_ITG3050_ITG_RDY_EN__MSK	0x04
#define C_ITG3050_ITG_RDY_EN__LEN	1
#define C_ITG3050_ITG_RDY_EN__REG	C_ITG3050_RegAdd_IntConfig

#define C_ITG3050_INT_ANYRD_2CLEAR__POS		4
#define C_ITG3050_INT_ANYRD_2CLEAR__MSK		0x10
#define C_ITG3050_INT_ANYRD_2CLEAR__LEN		1
#define C_ITG3050_INT_ANYRD_2CLEAR__REG		C_ITG3050_RegAdd_IntConfig

#define C_ITG3050_LATCH_INT_EN__POS		5
#define C_ITG3050_LATCH_INT_EN__MSK		0x20
#define C_ITG3050_LATCH_INT_EN__LEN		1
#define C_ITG3050_LATCH_INT_EN__REG		C_ITG3050_RegAdd_IntConfig

#define C_ITG3050_INT_Drive__POS		6
#define C_ITG3050_INT_Drive__MSK		0x40
#define C_ITG3050_INT_Drive__LEN		1
#define C_ITG3050_INT_Drive__REG		C_ITG3050_RegAdd_IntConfig

#define C_ITG3050_ACTL__POS		7
#define C_ITG3050_ACTL__MSK		0x80
#define C_ITG3050_ACTL__LEN		1
#define C_ITG3050_ACTL__REG		C_ITG3050_RegAdd_IntConfig

/* Interrupt Status Bits*/
#define C_ITG3050_RAW_DATA_RDY__POS		0
#define C_ITG3050_RAW_DATA_RDY__MSK		0x01
#define C_ITG3050_RAW_DATA_RDY__LEN		1
#define C_ITG3050_RAW_DATA_RDY__REG		C_ITG3050_RegAdd_IntStatus

#define C_ITG3050_ITG_RDY__POS		2
#define C_ITG3050_ITG_RDY__MSK		0x04
#define C_ITG3050_ITG_RDY__LEN		1
#define C_ITG3050_ITG_RDY__REG		C_ITG3050_RegAdd_IntStatus

/* Data Registers*/
#define C_ITG3050_TempH__POS	0
#define C_ITG3050_TempH__MSK	0xFF
#define C_ITG3050_TempH__LEN	8
#define C_ITG3050_TempH__REG	C_ITG3050_RegAdd_TempH

#define C_ITG3050_TempL__POS	0
#define C_ITG3050_TempL__MSK	0xFF
#define C_ITG3050_TempL__LEN	8
#define C_ITG3050_TempL__REG	C_ITG3050_RegAdd_TempL

#define C_ITG3050_GyroXH__POS	0
#define C_ITG3050_GyroXH__MSK	0xFF
#define C_ITG3050_GyroXH__LEN	8
#define C_ITG3050_GyroXH__REG	C_ITG3050_RegAdd_GyroXH

#define C_ITG3050_GyroXL__POS	0
#define C_ITG3050_GyroXL__MSK	0xFF
#define C_ITG3050_GyroXL__LEN	8
#define C_ITG3050_GyroXL__REG	C_ITG3050_RegAdd_GyroXL

#define C_ITG3050_GyroYH__POS	0
#define C_ITG3050_GyroYH__MSK	0xFF
#define C_ITG3050_GyroYH__LEN	8
#define C_ITG3050_GyroYH__REG	C_ITG3050_RegAdd_GyroYH

#define C_ITG3050_GyroYL__POS	0
#define C_ITG3050_GyroYL__MSK	0xFF
#define C_ITG3050_GyroYL__LEN	8
#define C_ITG3050_GyroYL__REG	C_ITG3050_RegAdd_GyroYL

#define C_ITG3050_GyroZH__POS	0
#define C_ITG3050_GyroZH__MSK	0xFF
#define C_ITG3050_GyroZH__LEN	8
#define C_ITG3050_GyroZH__REG	C_ITG3050_RegAdd_GyroZH

#define C_ITG3050_GyroZL__POS	0
#define C_ITG3050_GyroZL__MSK	0xFF
#define C_ITG3050_GyroZL__LEN	8
#define C_ITG3050_GyroZL__REG	C_ITG3050_RegAdd_GyroZL

/* FIFO Count Bits*/
#define C_ITG3050_FIFO_COUNT_H__POS		0
#define C_ITG3050_FIFO_COUNT_H__MSK		0x03
#define C_ITG3050_FIFO_COUNT_H__LEN		2
#define C_ITG3050_FIFO_COUNT_H__REG		C_ITG3050_RegAdd_FIFO_COUNT_H

#define C_ITG3050_FIFO_COUNT_L__POS		0
#define C_ITG3050_FIFO_COUNT_L__MSK		0xFF
#define C_ITG3050_FIFO_COUNT_L__LEN		8
#define C_ITG3050_FIFO_COUNT_L__REG		C_ITG3050_RegAdd_FIFO_COUNT_L

/* FIFO data register */
#define C_ITG3050_FIFO_Data__POS		0
#define C_ITG3050_FIFO_Data__MSK		0xFF
#define C_ITG3050_FIFO_Data__LEN		8
#define C_ITG3050_FIFO_Data__REG		C_ITG3050_RegAdd_FIFO_DATA

/* User Control Bits*/
#define C_ITG3050_GYRO_RST__POS		0
#define C_ITG3050_GYRO_RST__MSK		0x01
#define C_ITG3050_GYRO_RST__LEN		1
#define C_ITG3050_GYRO_RST__REG		C_ITG3050_RegAdd_USER_CTRL

#define C_ITG3050_FIFO_RST__POS		1
#define C_ITG3050_FIFO_RST__MSK		0x02
#define C_ITG3050_FIFO_RST__LEN		1
#define C_ITG3050_FIFO_RST__REG		C_ITG3050_RegAdd_USER_CTRL

#define C_ITG3050_FIFO_EN__POS		6
#define C_ITG3050_FIFO_EN__MSK		0x40
#define C_ITG3050_FIFO_EN__LEN		1
#define C_ITG3050_FIFO_EN__REG		C_ITG3050_RegAdd_USER_CTRL

/* Power management bits*/
#define C_ITG3050_CLK_SEL__POS		0
#define C_ITG3050_CLK_SEL__MSK		0x07
#define C_ITG3050_CLK_SEL__LEN		3
#define C_ITG3050_CLK_SEL__REG		C_ITG3050_RegAdd_PowerMgmt

#define C_ITG3050_STBY_ZG__POS		3
#define C_ITG3050_STBY_ZG__MSK		0x08
#define C_ITG3050_STBY_ZG__LEN		1
#define C_ITG3050_STBY_ZG__REG		C_ITG3050_RegAdd_PowerMgmt

#define C_ITG3050_STBY_YG__POS		4
#define C_ITG3050_STBY_YG__MSK		0x10
#define C_ITG3050_STBY_YG__LEN		1
#define C_ITG3050_STBY_YG__REG		C_ITG3050_RegAdd_PowerMgmt

#define C_ITG3050_STBY_XG__POS		5
#define C_ITG3050_STBY_XG__MSK		0x20
#define C_ITG3050_STBY_XG__LEN		1
#define C_ITG3050_STBY_XG__REG		C_ITG3050_RegAdd_PowerMgmt

#define C_ITG3050_Sleep__POS		6
#define C_ITG3050_Sleep__MSK		0x40
#define C_ITG3050_Sleep__LEN		1
#define C_ITG3050_Sleep__REG		C_ITG3050_RegAdd_PowerMgmt

#define C_ITG3050_H_RESET__POS		7
#define C_ITG3050_H_RESET__MSK		0x80
#define C_ITG3050_H_RESET__LEN		1
#define C_ITG3050_H_RESET__REG		C_ITG3050_RegAdd_PowerMgmt

#define ITG3050_GET_BITSLICE(regvar, bitname)\
			(regvar & bitname##__MSK) >> bitname##__POS


#define ITG3050_SET_BITSLICE(regvar, bitname, val)\
		  (regvar & ~bitname##__MSK) | ((val<<bitname##__POS)&bitname##__MSK) 

/****** ITG3050 Register value configurations *************/
#define C_ITG3050_Range_2000degps	0x03		// Range of +/- 2000deg/sec	
#define C_ITG3050_Range_1000degps	0x02		// Range of +/- 1000deg/sec
#define C_ITG3050_Range_500degps	0x01		// Range of +/- 500deg/sec
#define C_ITG3050_Range_250degps	0x00		// Range of +/- 250deg/sec

#define C_ITG3050_Bandwidth_256Hz 	0x00		// Gyro Bandwidth = 256Hz, Analog sample rate=8KHz
#define C_ITG3050_Bandwidth_188Hz 	0x01		// Gyro Bandwidth = 188Hz, Analog sample rate=1KHz	
#define C_ITG3050_Bandwidth_98Hz 	0x02		// Gyro Bandwidth = 98Hz, Analog sample rate=1KHz
#define C_ITG3050_Bandwidth_42Hz 	0x03		// Gyro Bandwidth = 42Hz, Analog sample rate=1KHz
#define C_ITG3050_Bandwidth_20Hz 	0x04		// Gyro Bandwidth = 20Hz, Analog sample rate=1KHz
#define C_ITG3050_Bandwidth_10Hz 	0x05		// Gyro Bandwidth = 10Hz, Analog sample rate=1KHz
#define C_ITG3050_Bandwidth_5Hz 	0x06		// Gyro Bandwidth = 5Hz, Analog sample rate=1KHz

#define C_ITG3050_H_Reset		0x01

#define C_ITG3050_SleepMode	0x01
#define C_ITG3050_NormalMode	0x00

#define C_ITG3050_IntOsc		0x00
#define C_ITG3050_PLL_XRef		0x01
#define C_ITG3050_PLL_YRef		0x02
#define C_ITG3050_PLL_ZRef		0x03
#define C_ITG3050_PLL_Ext32_768KHz	0x04
#define C_ITG3050_PLL_Ext19_2MHz	0x05
#define C_ITG3050_Clk_Rst		0x07

/****** ITG3050 Constants *********************************/
#define C_ITG3050_TEMPOffsetInLSB        13200		// Temperature offset in LSB at 35 deg
#define C_ITG3050_TEMPOffsetInDeg	 35		// Temperature offset in degress
#define C_ITG3050_TempSensLSBperCelsius  280		// Temperature sensitivity in LSB per degree

/* ITG3050 Structure */
typedef struct{

	U8 v_ChipID_u8;  /**< Holds the chip id of gyro*/
	U8 v_DevAddr_u8; /**< The I2C Address of gyro */
	
	M_ITG3050_BUS_WR_RETURN_TYPE (*bus_write)(M_ITG3050_BUS_WR_PARAM_TYPES);
	M_ITG3050_BUS_RD_RETURN_TYPE (*bus_read)(M_ITG3050_BUS_RD_PARAM_TYPES);
	
}ts_itg3050;

typedef struct  {
		S16   v_Wx_s16, /**<signed 16 bit angular velocity X */
                      v_Wy_s16, /**<signed 16 bit angular velocity Y */
                      v_Wz_s16; /**<signed 16 bit angular velocity Z */
} ts_GyroData;															
/****** ITG3050 Hardware Abstraction layer Function prototypes ***********/
S8 ITG3050_INIT(ts_itg3050 *);								
															
S8 ITG3050_SET_Range(U8);

S8 ITG3050_GET_Range(U8 *);

S8 ITG3050_SET_BW(U8);

S8 ITG3050_GET_BW(U8 *);

S8 ITG3050_SET_SampleRate(U8);

S8 ITG3050_GET_SampleRate(U8 *);

S8 ITG3050_GET_Temperature(F32 *);

S8 ITG3050_GET_ANGULARVELOCITY(ts_GyroData *);

S8 ITG3050_WRITE_REGISTER(U8,U8,U8,U8);

S8 ITG3050_READ_REGISTER(U8,U8 *,U8,U8);

#endif  // End of Header file ITG3050.h

