/*
 * File:   		HMC5883.h
 * Created: 	6th October, 2011, 1:00 PM 
 * Author:		gopal.jatiya@brigosha.com 
 * Version      v0.1
 * Comment:		Coding Standard Implemented
 */
/*****************************Revision History****************************/
/*Version Number		Modified by		Date
	0.1					Gopal Jatiya	6th October, 2011
	0.2					Gopal Jatiya	18th August, 2012
*/

 
#ifndef __HMC5883_H__
#define __HMC5883_H__

#include "Define.h"

/* links the order of parameters defined in HMC5883_BUS_WR_PARAM_TYPE to function calls used inside the API*/
#define M_HMC5883_BUS_WR_PARAM_TYPES U8, U8, U8 *, U8

/* links the order of parameters defined in HMC5883_BUS_WR_PARAM_TYPE to function calls used inside the API*/
#define M_HMC5883_BUS_WR_PARAM_ORDER device_addr, register_addr, register_data, wr_len

/* never change this line */
#define HMC5883_BUS_WRITE_FUNC(device_addr, register_addr, register_data, wr_len )\
           bus_write(device_addr, register_addr, register_data, wr_len )
		   
/* links the order of parameters defined in HMC5883_BUS_RD_PARAM_TYPE to function calls used inside the API*/
#define M_HMC5883_BUS_RD_PARAM_TYPES U8, U8, U8 *, U8

/* links the order of parameters defined in HMC5883_BUS_RD_PARAM_TYPE to function calls used inside the API*/
#define M_HMC5883_BUS_RD_PARAM_ORDER device_addr, register_addr, register_data, wr_len

/* never change this line */
#define HMC5883_BUS_READ_FUNC(device_addr, register_addr, register_data, wr_len )\
           bus_read(device_addr, register_addr, register_data, wr_len )


/*******I2C Specific****************************************/
#define C_HMC5883_I2C_ADDRESS              0x1E            /*I2C device Address for HMC5883*/

/*******HMC5883 REgister Addresses**************************/
#define C_HMC5883_CONFIGA_REG              0x00		/*Address of Configuration Register A */
#define C_HMC5883_CONFIGB_REG			   0x01		/*Address of Configuration Register B */
#define C_HMC5883_MODE_REG				   0x02		/*Address of Mode Register */

#define C_HMC5883_X_AXIS_LSB_REG           0x04     /*Address of X-AXIS data Magnetism data output register,LS-Byte */
#define C_HMC5883_X_AXIS_MSB_REG           0x03     /*Address of X-AXIS data Magnetism data output register,MS-Byte */
#define C_HMC5883_Y_AXIS_LSB_REG           0x08     /*Address of Y-AXIS data Magnetism data output register,LS-Byte */
#define C_HMC5883_Y_AXIS_MSB_REG           0x07     /*Address of Y-AXIS data Magnetism data output register,MS-Byte */
#define C_HMC5883_Z_AXIS_LSB_REG           0x06     /*Address of Z-AXIS data Magnetism data output register,LS-Byte */
#define C_HMC5883_Z_AXIS_MSB_REG           0x05     /*Address of Z-AXIS data Magnetism data output register,MS-Byte */		

#define C_HMC5883_MDATA_REG                C_HMC5883_X_AXIS_MSB_REG

#define C_HMC5883_STATUS_REG       			0x09     /*Address of Status register */
#define C_HMC5883_IDA_REG          			0x0A     /*Address of Identification register A */
#define C_HMC5883_IDB_REG          			0x0B     /*Address of Identification register B */
#define C_HMC5883_IDC_REG          			0x0C     /*Address of Identification register C */

/* Configuration Resgister A bits */
#define C_HMC5883_CONFIGA_MEASUREMENT__POS         0                       /*1st & 2nd bit of Config A Register */
#define C_HMC5883_CONFIGA_MEASUREMENT__LEN         2
#define C_HMC5883_CONFIGA_MEASUREMENT__MSK         0x03
#define C_HMC5883_CONFIGA_MEASUREMENT__REG         C_HMC5883_CONFIGA_REG

#define C_HMC5883_CONFIGA_DATAOUTRATE__POS         2                       /*3 to 5 bits of Config A Registers */
#define C_HMC5883_CONFIGA_DATAOUTRATE__LEN         3
#define C_HMC5883_CONFIGA_DATAOUTRATE__MSK         0x1C
#define C_HMC5883_CONFIGA_DATAOUTRATE__REG         C_HMC5883_CONFIGA_REG

#define C_HMC5883_CONFIGA_NO_SAMPLES__POS		   5						/* 6th & 7th bits of Config A Register*/
#define C_HMC5883_CONFIGA_NO_SAMPLES__LEN		   2
#define C_HMC5883_CONFIGA_NO_SAMPLES__MSK		   0X60
#define C_HMC5883_CONFIGA_NO_SAMPLES__REG		   C_HMC5883_CONFIGA_REG		

/* Configuration Resgister B bits */
#define C_HMC5883_CONFIGB_GAIN__POS                5                       /*5 to 8 bits of Config B Registers */
#define C_HMC5883_CONFIGB_GAIN__LEN                3
#define C_HMC5883_CONFIGB_GAIN__MSK                0xE0
#define C_HMC5883_CONFIGB_GAIN__REG                C_HMC5883_CONFIGB_REG

/*Mode Register Bits*/
#define C_HMC5883_MODE_MD__POS                     0                       /*1st and 2nd bits of Mode Register */
#define C_HMC5883_MODE_MD__LEN                     2
#define C_HMC5883_MODE_MD__MSK                     0x03
#define C_HMC5883_MODE_MD__REG                     C_HMC5883_MODE_REG

/*Status Register Bits*/
#define C_HMC5883_STATUS_RDY__POS                  0                       /*1st bit of status Register */
#define C_HMC5883_STATUS_RDY__LEN                  1
#define C_HMC5883_STATUS_RDY__MSK                  0x01
#define C_HMC5883_STATUS_RDY__REG                  C_HMC5883_STATUS_REG

#define C_HMC5883_STATUS_LOCK__POS                 1                       /*2nd bit of status Register */
#define C_HMC5883_STATUS_LOCK__LEN                 1
#define C_HMC5883_STATUS_LOCK__MSK                 0x02
#define C_HMC5883_STATUS_LOCK__REG                 C_HMC5883_STATUS_REG

/*Identification Registers*/
#define C_HMC5883_IDA__POS		0 
#define C_HMC5883_IDA__LEN		8
#define C_HMC5883_IDA__MSK		0xFF
#define C_HMC5883_IDA__REG		C_HMC5883_IDA_REG

#define C_HMC5883_IDB__POS		0 
#define C_HMC5883_IDB__LEN		8
#define C_HMC5883_IDB__MSK		0xFF
#define C_HMC5883_IDB__REG		C_HMC5883_IDB_REG

#define C_HMC5883_IDC__POS		0 
#define C_HMC5883_IDC__LEN		8
#define C_HMC5883_IDC__MSK		0xFF
#define C_HMC5883_IDC__REG		C_HMC5883_IDC_REG

/* get bit slice  */
#define HMC5883_GET_BITSLICE(regvar, bitname)\
                        (regvar & bitname##__MSK) >> bitname##__POS

/* Set bit slice */
#define HMC5883_SET_BITSLICE(regvar, bitname, val)\
                  (regvar & ~bitname##__MSK) | ((val<<bitname##__POS)&bitname##__MSK)
				  
/* Constants */

#define C_HMC5883_NULL                             0            /*constant declaration of NULL */
#define C_HMC5883_NORMAL_MEASURE_MODE              0			/* Normal Measurement Flow */	
#define C_HMC5883_POSITIVE_BIAS_MODE               1			/* Positive Bias Configuration */
#define C_HMC5883_NEGATIVE_BIAS_MODE               2			/* Negative Bias Configuration */

#define C_HMC5883_DATA_RATE_0_75_HZ                0               /*It refers HMC5883 data rate 0.75 Hz  */
#define C_HMC5883_DATA_RATE_1_5_HZ                 1               /*It refers HMC5883 data rate 1.5 Hz    */
#define C_HMC5883_DATA_RATE_3_HZ                   2               /*It refers HMC5883 data rate 3 Hz    */
#define C_HMC5883_DATA_RATE_7_5_HZ                 3               /*It refers HMC5883 data rate 7.5 Hz    */
#define C_HMC5883_DATA_RATE_15_HZ                  4               /*It refers HMC5883 data rate 15 Hz   */
#define C_HMC5883_DATA_RATE_30_HZ                  5               /*It refers HMC5883 data rate 30 Hz   */
#define C_HMC5883_DATA_RATE_75_HZ                  6               /*It refers HMC5883 data rate 75 Hz   */

#define C_HMC5883_NO_SAMPLES_1					   0			/* 1 sample averaged per measurement */	
#define C_HMC5883_NO_SAMPLES_2					   1			/* 2 samples averaged per measurement */
#define C_HMC5883_NO_SAMPLES_4					   2			/* 4 samples averaged per measurement */
#define C_HMC5883_NO_SAMPLES_8					   3			/* 8 samples averaged per measurement */

#define C_HMC5883_GAIN_0_88_GA                     0			/* Recommended Sensor field range 0f +/- 0.88 Ga*/
#define C_HMC5883_GAIN_1_3_GA                      1			/* Recommended Sensor field range 0f +/- 1.3 Ga*/
#define C_HMC5883_GAIN_1_9_GA                      2			/* Recommended Sensor field range 0f +/- 1.9 Ga*/
#define C_HMC5883_GAIN_2_5_GA                      3			/* Recommended Sensor field range 0f +/- 2.5 Ga*/
#define C_HMC5883_GAIN_4_GA                        4			/* Recommended Sensor field range 0f +/- 4.0 Ga*/
#define C_HMC5883_GAIN_4_7_GA                      5			/* Recommended Sensor field range 0f +/- 4.7 Ga*/
#define C_HMC5883_GAIN_5_6_GA                      6			/* Recommended Sensor field range 0f +/- 5.6 Ga*/
#define C_HMC5883_GAIN_8_1_GA                      7			/* Recommended Sensor field range 0f +/- 8.1 Ga*/

#define C_HMC5883_CONTINUOUS_MEASUREMENT_MODE      0            /*It refers C_HMC5883 continuous measurement mode*/
#define C_HMC5883_SINGLE_MEASUREMENT_MODE          1            /*It refers C_HMC5883 single measurement mode */
#define C_HMC5883_IDLE_MODE                        2            /*It refers C_HMC5883 idle mode  */
#define C_HMC5883_SLEEP_MODE                       3            /*It refers C_HMC5883 sleep mode  */

#define M_HMC5883_WR_FUNC_PTR S8(* bus_write)(U8, U8, U8 *, U8)
#define M_HMC5883_RD_FUNC_PTR S8(* bus_read)( U8, U8, U8 *, U8)

typedef struct
{
        short v_DataX_s16,
              v_DataY_s16,
              v_DataZ_s16;
}ts_hmc5883_mdata;                                /*structure of magnetic field data for HMC5883 */

typedef struct
{
        U8 v_DevAdd_u8;
	U8 v_DeviceID_u8;
        M_HMC5883_RD_FUNC_PTR;
        M_HMC5883_WR_FUNC_PTR;

}ts_hmc5883;

/********************* HMC5883 APIs ***************************************/
/*_________________________________________ Initialize hmc5883 structure______________________*/
// Intialize the the HMC5883
// fn parameters: pointer to structure ts_hmc5883
// fn Return : Initialize SUCESS = 0; or Initialize FAILURE = -1;

S8 HMC5883_INIT(ts_hmc5883 *);

/*_______________________________________ Read Magnetic Data on X,Y and Z __________________*/
//Reads magnetic data along x,y and z axes
//fn parameters: Pointer to the structure of magnetic data to store the value
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1;

S8 HMC5883_GET_MData_xyz(ts_hmc5883_mdata *);


/*_________________________________________Set Measurement Configuration Mode ________________*/
//Sets the measurement configuration as normal , positive or negative
/*fn parameter: Variable to set the configuration mode
				0x00: Normal Measurement Mode
				0x01: Positive Bias
				0x02: Negative Bias */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_SET_Measurement_Mode(U8);

/*_________________________________________Get Measurement Configuration Mode ________________*/
//Gets the measurement configuration as normal , positive or negative
/*fn parameter: Pointer to a variable to store the configuration mode
				0x00: Normal Measurement Mode
				0x01: Positive Bias
				0x02: Negative Bias */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_GET_Measurement_Mode(U8 *);

/*_________________________________________Set Output Data Rate ________________*/
//Sets the output data rate of the sensor
/*fn parameter: Variable to containing the data rate to set
				0: 0.75 Hz
				1: 1.5 Hz
				2: 3 Hz
				3: 7.5 Hz
				4: 15 Hz
				5: 30 Hz
				6: 75 Hz */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_SET_DataRate(U8);

/*_________________________________________Get Output Data Rate ________________*/
//Gets the output data rate of the sensor
/*fn parameter: Pointer to the variable to store the data rate
				0: 0.75 Hz
				1: 1.5 Hz
				2: 3 Hz
				3: 7.5 Hz
				4: 15 Hz
				5: 30 Hz
				6: 75 Hz */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_GET_DataRate(U8 *);

/*_________________________________________Get No of samples to avg ________________*/
//Gets the no. of samples that are averaged
/*fn parameter: Pointer to Variable to get the no. of samples
				0: 1 sample average per measurement output
				1: 2 samples average per measurement output
				2: 4 samples average per measurement output
				3: 8 samples average per measurement output */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_SET_No_Samples(U8);

/*_________________________________________Get No of samples to avg ________________*/
//Gets the no. of samples that are averaged
/*fn parameter: Pointer to Variable to get the no. of samples
				0: 1 sample average per measurement output
				1: 2 samples average per measurement output
				2: 4 samples average per measurement output
				3: 8 samples average per measurement output */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_GET_No_Samples(U8 *);

/*_________________________________________Set Gain ________________*/
//Sets the gain of the sensor
/*fn parameter: Variable to containing the gain to set
				0: +/- 0.88 Ga (1370 LSB/Gauss)
				1: +/- 1.3  Ga (1090 LSB/Gauss)
				2: +/- 1.9  Ga (820 LSB/Gauss)
				3: +/- 2.5  Ga (660 LSB/Gauss)
				4: +/- 4.0  Ga (440 LSB/Gauss)
				5: +/- 4.7  Ga (390 LSB/Gauss)
				6: +/- 5.6  Ga (330 LSB/Gauss)
				7: +/- 8.1  Ga (230 LSB/Gauss) */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_SET_Gain(U8);

/*_________________________________________Get Gain ________________*/
//Gets the gain of the sensor
/*fn parameter: Pointer to variable to store the gain
				0: +/- 0.88 Ga (1370 LSB/Gauss)
				1: +/- 1.3  Ga (1090 LSB/Gauss)
				2: +/- 1.9  Ga (820 LSB/Gauss)
				3: +/- 2.5  Ga (660 LSB/Gauss)
				4: +/- 4.0  Ga (440 LSB/Gauss)
				5: +/- 4.7  Ga (390 LSB/Gauss)
				6: +/- 5.6  Ga (330 LSB/Gauss)
				7: +/- 8.1  Ga (230 LSB/Gauss) */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_GET_Gain(U8 *);

/*_________________________________________Set Operation Mode ________________*/
//Sets the operation mode of the sensor as continuous, single or idle
/*fn parameter: Variable to set the operation mode
				0: Continuous Measurement Mode
				1: Single Measurement Mode
				2: Idle Mode 
				3: Sleep Mode */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_SET_OperationMode(U8);

/*_________________________________________Get Operation Mode ________________*/
//Gets the operation mode of the sensor as continuous, single or idle
/*fn parameter: Pointer to variable to get the operation mode
				0: Continuous Measurement Mode
				1: Single Measurement Mode
				2: Idle Mode 
				3: Sleep Mode */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_GET_OperationMode(U8 *);

/*_________________________________________Get Data Ready Status ________________*/
//Gets Data Ready Status bit
/*fn parameter: Pointer to variable to get the Data ready status
				0: Measurement has started
				1: Data is ready */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_GET_DataRdy(U8 *);

/*_________________________________________Get Lock ________________*/
//Gets Lock Status bit
/*fn parameter: Pointer to variable to get the Lock status
				0: Data Output Register not locked
				1: Data Output Register Locked */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_GET_Lock(U8 *);

/*_________________________________________Register Write__________________________________*/
//Write to any register adress
// fn parameters: v_RegAddr_u8  : Use macros for the register adress from HMC5883.h file
//				  v_RegValue_u8 : The Value of the bit(s) to be written onto the register
//				  v_BitPos_u8   : The starting position of the desired bit,use macros bitname__POS from HMC5883.h
//				  v_BitsMask_u8 : Bit mask, use macros bitname__MSK from HMC5883.h
//fn Return : SUCESS = 0; or FAILURE = -1;
S8 HMC5883_WRITE_Register(U8, U8, U8, U8);

/*_________________________________________Register Read__________________________________*/
//Read from any register adress
// fn parameters: v_RegAddr_u8  : Use macros for the register adress from HMC5883.h file
//				  p_RegValue_u8 : Pointer to the variable where data is read
//				  v_BitPos_u8   : The starting position of the desired bit,use macros bitname__POS from HMC5883.h
//				  v_BitsMask_u8 : Bit mask, use macros bitname__MSK from HMC5883.h
//fn Return : SUCESS = 0; or FAILURE = -1;
S8 HMC5883_READ_Register(U8,U8 *,U8,U8);		

#endif	//end of header file hmc5883.h
