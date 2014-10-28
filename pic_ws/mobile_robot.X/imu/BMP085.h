/*
 * File:   		BMP085.h
 * Created: 	3rd December, 2011, 7:00 PM 
 * Author:		gopal.jatiya@brigosha.com 
 * Version      v0.1
 * Comment:		Coding Standard Implemented
 */
/*Version Number		Modified by		Date
	0.1					Gopal Jatiya	3rd December, 2011
	0.2					Gopal Jatiya	19th August, 2012
*/
#ifndef BMP085_H
#define BMP085_H
 
/*******Include Definitions*****************************/
#include "Define.h"

/*******I2C Specific****************************************/
#define C_BMP085_I2CAdd			0x77						

/* defines the return parameter type of the BMP085_WR_FUNCTION

*/
#define M_BMP085_BUS_WR_RETURN_TYPE S8

/* defines the calling parameter types of the BMP085_WR_FUNCTION

*/
#define M_BMP085_BUS_WR_PARAM_TYPES U8,U8,U8 *,U8

/* links the order of parameters defined in BMP085_BUS_WR_PARAM_TYPE to function calls used inside the API

*/
#define M_BMP085_BUS_WR_PARAM_ORDER device_addr, register_addr, register_v_data_u8, write_length


/* never change this line */
#define BMP085_BUS_WRITE_FUNC(device_addr, register_addr, register_v_data_u8, write_length)\
           bus_write( device_addr, register_addr, register_v_data_u8, write_length )




/* defines the return parameter type of the BMP085_RD_FUNCTION

*/
#define M_BMP085_BUS_RD_RETURN_TYPE S8

/* defines the calling parameter types of the BMP085_RD_FUNCTION

*/
#define M_BMP085_BUS_RD_PARAM_TYPES U8, U8, U8 *, U8

/* links the order of parameters defined in BMP085_BUS_RD_PARAM_TYPE to function calls used inside the API

*/
#define M_BMP085_BUS_RD_PARAM_ORDER device_addr, register_addr, register_v_data_u8, read_length



/* never change this line */
#define BMP085_BUS_READ_FUNC(device_addr, register_addr, register_v_data_u8, read_length)\
           bus_read( device_addr, register_addr, register_v_data_u8, read_length )
		   
/****** BMP085 Register Adress ****************************/
#define C_BMP085_PROM_START__ADDR	0xaa
#define C_BMP085_PROM_DATA__LEN		22

#define C_BMP085_CHIP_ID_REG		0xD0		//Chip ID register of BMP085
#define C_BMP085_VERSION_REG		0xD1		//Version register of BMP085

#define C_BMP085_CTRL_MEAS_REG		0xF4		//Control measurement register
#define C_BMP085_ADC_OUT_MSB_REG	0xF6		//ADC MSB register
#define C_BMP085_ADC_OUT_LSB_REG	0xF7		//ADC LSB register

#define C_BMP085_SOFT_RESET_REG		0xE0		//Soft Reset Register

#define C_BMP085_T_MEASURE          0x2E		// temperature measurent 
#define C_BMP085_P_MEASURE          0x34		// pressure measurement

/*************** calibration parameters ************/
#define C_BMP085_PARAM_MG      3038        //calibration parameter
#define C_BMP085_PARAM_MH     -7357        //calibration parameter
#define C_BMP085_PARAM_MI      3791        //calibration parameter

/****************bit slice positions in registers ****************/

#define C_BMP085_CHIP_ID__POS		0
#define C_BMP085_CHIP_ID__MSK		0xFF
#define C_BMP085_CHIP_ID__LEN		8
#define C_BMP085_CHIP_ID__REG		C_BMP085_CHIP_ID_REG


#define C_BMP085_ML_VERSION__POS		0
#define C_BMP085_ML_VERSION__LEN		4
#define C_BMP085_ML_VERSION__MSK		0x0F
#define C_BMP085_ML_VERSION__REG		C_BMP085_VERSION_REG



#define C_BMP085_AL_VERSION__POS  		4
#define C_BMP085_AL_VERSION__LEN  		4
#define C_BMP085_AL_VERSION__MSK		0xF0
#define C_BMP085_AL_VERSION__REG		C_BMP085_VERSION_REG


#define BMP085_GET_BITSLICE(regvar, bitname)\
			(regvar & bitname##__MSK) >> bitname##__POS


#define BMP085_SET_BITSLICE(regvar, bitname, val)\
		  (regvar & ~bitname##__MSK) | ((val<<bitname##__POS)&bitname##__MSK)
		  
typedef struct {
   S16 ac1;
   S16 ac2;
   S16 ac3;
   U16 ac4;
   U16 ac5;
   U16 ac6;
   S16 b1;
   S16 b2;
   S16 mb;
   S16 mc;
   S16 md;      		   
} ts_bmp085_calibration_param;

typedef struct  {	
	ts_bmp085_calibration_param s_CalParam_xs;	
	U8 v_Mode_u8;
	U8 v_ChipID_u8,	v_MLversion_u8,	v_ALversion_u8;
	U8 v_DevAdd_u8;	
	U8 v_SensorType_u8;

	S32 v_param_b5_s32;
	U8 v_No_of_Samples_u8;
	U8 v_OversamplingSetting_u8;
	
	M_BMP085_BUS_WR_RETURN_TYPE (*bus_write)(M_BMP085_BUS_WR_PARAM_TYPES);
	M_BMP085_BUS_RD_RETURN_TYPE (*bus_read)(M_BMP085_BUS_RD_PARAM_TYPES);
} ts_bmp085;

/****** BMP085 Hardware Abstraction layer Function prototypes ***********/

S8 BMP085_INIT(ts_bmp085 *);

S8 BMP085_GET_Pressure_Teperature(S32 *, S16 *);

#endif  // End of Header file BMP085.h
