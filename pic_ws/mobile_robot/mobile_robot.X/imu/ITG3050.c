/*
 * File:   	ITG3050.c
 * Created: 	7th August, 2012, 10:30 
 * Author:	gopal.jatiya@brigosha.com 
 * Version      v0.1
 * Comment:	Coding Standard Implemented
 */

/***************** Include System and sensor header files **********************************/

#include "ITG3050.h"

ts_itg3050 *P_ITG3050_XS;

/*_________________________________________ Initialize the Communicationa and verify ChipID______________________*/
// Intialize the the gyro ITG3050 and Read the chip ID 
// fn parameters: pointer to structure ts_itg3050
// fn Return : Initialize SUCESS = 0; or Initialize FAILURE = -1;	
S8 ITG3050_INIT(ts_itg3050 *p_itg3050_xs )
{
 	S8 v_ComRes_s8;
	U8 v_data_u8;
	P_ITG3050_XS = p_itg3050_xs;
	P_ITG3050_XS->v_DevAddr_u8 = C_ITG3050_I2CAdd;
	// Read the chip Id of the connected device
	v_ComRes_s8 = P_ITG3050_XS->ITG3050_BUS_READ_FUNC((P_ITG3050_XS->v_DevAddr_u8),C_ITG3050_CHIP_ID__REG,&v_data_u8,1);
	P_ITG3050_XS->v_ChipID_u8 = ITG3050_GET_BITSLICE(v_data_u8, C_ITG3050_CHIP_ID);
				
	return v_ComRes_s8;	
}

/*________________________________Set Range____________________________________*/
/*
This function is used to set the range for the gyro
fn parameters: v_Range_u8: Variable containing valid range macro, use from ITG3050.h
			   e.g: C_ITG3050_Range_2000degps
fn Return : Communication result SUCCESS = 0; FAILURE = -1
*/
S8 ITG3050_SET_Range(U8 v_Range_u8)
{
	S8 v_ComRes_s8;
	U8 v_data_u8;
	
	if ((v_Range_u8>C_ITG3050_Range_2000degps)||P_ITG3050_XS==0) //check for valid range value and null pointer
		return -1;
		
	v_ComRes_s8 = P_ITG3050_XS->ITG3050_BUS_READ_FUNC((P_ITG3050_XS->v_DevAddr_u8),C_ITG3050_Range__REG,&v_data_u8,1);
	v_data_u8 = ITG3050_SET_BITSLICE(v_data_u8,C_ITG3050_Range,v_Range_u8);
	v_ComRes_s8= P_ITG3050_XS->ITG3050_BUS_WRITE_FUNC(P_ITG3050_XS->v_DevAddr_u8,C_ITG3050_Range__REG, &v_data_u8,1);
	
	return v_ComRes_s8;
}

/*________________________________Get Range____________________________________*/
/*
This function is used to get the current range for the gyro
fn parameters: p_Range_u8: Pointer to the variable where the range is returned
fn Return : Communication result SUCCESS = 0; FAILURE = -1
*/
S8 ITG3050_GET_Range(U8 *p_Range_u8)
{
	S8 v_ComRes_s8;
	U8 v_data_u8;
	
	if (P_ITG3050_XS==0) //check for Null pointer
		return -1;
		
	v_ComRes_s8 = P_ITG3050_XS->ITG3050_BUS_READ_FUNC((P_ITG3050_XS->v_DevAddr_u8),C_ITG3050_Range__REG,&v_data_u8,1);
	*p_Range_u8 = ITG3050_GET_BITSLICE(v_data_u8,C_ITG3050_Range);
	
	return v_ComRes_s8;
}

/*________________________________Set Bandwidth ____________________________________*/
/*
This function is used to set the bandwidth for the gyro,also decides the internal sample rate 1Khz or 8Khz
fn parameters: v_BW_u8: Variable containing valid bandwidth macro, use from ITG3050.h
			   e.g: C_ITG3050_Bandwidth_256Hz (Analog sample rate=8KHz)
fn Return : Communication result SUCCESS = 0; FAILURE = -1
*/
S8 ITG3050_SET_BW(U8 v_BW_u8)
{
	S8 v_ComRes_s8;
	U8 v_data_u8;
	
	if ((v_BW_u8>C_ITG3050_Bandwidth_5Hz)||P_ITG3050_XS==0) //check for valid bandwidth value and null pointer
		return -1;
		
	v_ComRes_s8 = P_ITG3050_XS->ITG3050_BUS_READ_FUNC((P_ITG3050_XS->v_DevAddr_u8),C_ITG3050_BW__REG,&v_data_u8,1);
	v_data_u8 = ITG3050_SET_BITSLICE(v_data_u8,C_ITG3050_BW,v_BW_u8);
	v_ComRes_s8= P_ITG3050_XS->ITG3050_BUS_WRITE_FUNC(P_ITG3050_XS->v_DevAddr_u8,C_ITG3050_BW__REG, &v_data_u8,1);
	
	return v_ComRes_s8;
}

/*________________________________Get Bandwidth ____________________________________*/
/*
This function is used to get the current Bandwidth for the gyro
fn parameters: p_BW_u8: Pointer to the variable where the Bandwidth is returned
fn Return : Communication result SUCCESS = 0; FAILURE = -1
*/
S8 ITG3050_GET_BW(U8 *p_BW_u8)
{
	S8 v_ComRes_s8;
	U8 v_data_u8;
	
	if (P_ITG3050_XS==0) //check for Null pointer
		return -1;
		
	v_ComRes_s8 = P_ITG3050_XS->ITG3050_BUS_READ_FUNC((P_ITG3050_XS->v_DevAddr_u8),C_ITG3050_BW__REG,&v_data_u8,1);
	*p_BW_u8 = ITG3050_GET_BITSLICE(v_data_u8,C_ITG3050_BW);
	
	return v_ComRes_s8;
}

/*_______________________________________SET SAMPLE RATE____________________________________________________________*/
/* This function sets the sampling rate divider. Fsample = Finternal/(divider +1).
	Finternal is decided from bandwidth setting. Please see ITG3050.h for options.					
 fn parameters: v_Divider_u8 : variable to be written. Valid values (0-255)
 fn Return : write SUCESS = 0; or write FAILURE = -1;
 */
S8 ITG3050_SET_SampleRate(U8 v_Divider_u8)
{	
	S8 v_ComRes_s8;
	U8 v_data_u8;
	
	if (P_ITG3050_XS==0) //check for valid bandwidth value and null pointer
		return -1;
		
	v_ComRes_s8 = P_ITG3050_XS->ITG3050_BUS_READ_FUNC((P_ITG3050_XS->v_DevAddr_u8),C_ITG3050_SMPLRT_DIV__REG,&v_data_u8,1);
	v_data_u8 = ITG3050_SET_BITSLICE(v_data_u8,C_ITG3050_SMPLRT_DIV,v_Divider_u8);
	v_ComRes_s8= P_ITG3050_XS->ITG3050_BUS_WRITE_FUNC(P_ITG3050_XS->v_DevAddr_u8,C_ITG3050_SMPLRT_DIV__REG, &v_data_u8,1);
	
	return v_ComRes_s8;
}

/*________________________________Get SAMPLE RATE ____________________________________*/
/*
This function is used to get the current Sampling Rate divider value
fn parameters: p_Divider_u8: Pointer to the variable where the divider is returned
fn Return : Communication result SUCCESS = 0; FAILURE = -1
*/
S8 ITG3050_GET_SampleRate(U8 *p_Divider_u8)
{
	S8 v_ComRes_s8;
	U8 v_data_u8;
	
	if (P_ITG3050_XS==0) //check for Null pointer
		return -1;
		
	v_ComRes_s8 = P_ITG3050_XS->ITG3050_BUS_READ_FUNC((P_ITG3050_XS->v_DevAddr_u8),C_ITG3050_SMPLRT_DIV__REG,&v_data_u8,1);
	*p_Divider_u8 = ITG3050_GET_BITSLICE(v_data_u8,C_ITG3050_SMPLRT_DIV);
	
	return v_ComRes_s8;
}		
					
/*__________________________GET TEMPERATURE of ITG3050_________________________________________________*/
// This function reads the temperature 
// fn parameters: (Pointer to store read value of Temperature)
//fn return: Communication Result: Success =0 ; failure =-1
S8 ITG3050_GET_Temperature(F32 *p_ReadTemp_f32)
{
 	S8 v_ComRes_s8;
	U8 a_Temp_u8[2]={0};	
 	S16 v_ReadTempRaw_s16=0;
	// Read the temperature value from MSB and LSB registers
	v_ComRes_s8=P_ITG3050_XS->ITG3050_BUS_READ_FUNC(P_ITG3050_XS->v_DevAddr_u8,C_ITG3050_TempH__REG , a_Temp_u8, 2);
	
	// Combine the MSB and LSB to get the 16 bit temperature
	v_ReadTempRaw_s16 = (((S16)a_Temp_u8[0])<<8) | (S16)a_Temp_u8[1];	
	
	// Convert the Temperature in LSB to Temperature in degree celsius
	*p_ReadTemp_f32 = ((F32)(v_ReadTempRaw_s16 + C_ITG3050_TEMPOffsetInLSB)/C_ITG3050_TempSensLSBperCelsius) + C_ITG3050_TEMPOffsetInDeg;
	
	return v_ComRes_s8;

}

/*__________________________GET Gyro values from ITG3050 registers_________________________________________*/
// This function reads the gyro values on three axis
// fn parameters: ( Pointer to X axis, Pointer to Y axis, Pointer to Z axis)
//fn return: Communication Result: Success =0 ; failure =-1
S8 ITG3050_GET_ANGULARVELOCITY(ts_GyroData *p_Omega_xs)
{
	U8 a_omega_u8[6]={0};
	S8 v_ComRes_s8; 	
	// Read the angular velocities from the 6 registers MSB and LSB for 3 axis
	v_ComRes_s8=P_ITG3050_XS->ITG3050_BUS_READ_FUNC(P_ITG3050_XS->v_DevAddr_u8,C_ITG3050_GyroXH__REG ,a_omega_u8, 6);	
	
	// combine the MSB and LSB to get 16 bit raw angular velocities value
	p_Omega_xs->v_Wx_s16 = (((S16)a_omega_u8[0])<<8) | (S16)a_omega_u8[1];
	p_Omega_xs->v_Wy_s16 = (((S16)a_omega_u8[2])<<8) | (S16)a_omega_u8[3];
	p_Omega_xs->v_Wz_s16 = (((S16)a_omega_u8[4])<<8) | (S16)a_omega_u8[5];
	
	return v_ComRes_s8;

}

/*_________________________________________Register Write__________________________________*/
//Write to any register adress
// fn parameters: v_RegAddr_u8  : Use macros for the register adress from ITG3050.h file
//				  v_RegValue_u8 : The Value of the bit(s) to be written onto the register
//				  v_BitPos_u8   : The starting position of the desired bit,use macros bitname__POS from ITG3050.h
//				  v_BitsMask_u8 : Bit mask, use macros bitname__MSK from ITG3050.h
//fn Return : SUCESS = 0; or FAILURE = -1;
S8 ITG3050_WRITE_REGISTER(U8 v_RegAddr_u8, U8 v_RegValue_u8, U8 v_BitPos_u8, U8 v_BitsMask_u8)	
{
	S8 v_comres_s8;
	U8 v_data_u8;
	
	if (P_ITG3050_XS==0)
		return -1;
	
	v_comres_s8 = P_ITG3050_XS->ITG3050_BUS_READ_FUNC(P_ITG3050_XS->v_DevAddr_u8, v_RegAddr_u8, &v_data_u8,1);
	v_data_u8 = (v_data_u8 & (~v_BitsMask_u8)) | ((v_RegValue_u8<<v_BitPos_u8) & v_BitsMask_u8);
	v_comres_s8 += P_ITG3050_XS->ITG3050_BUS_WRITE_FUNC(P_ITG3050_XS->v_DevAddr_u8, v_RegAddr_u8, &v_data_u8, 1 );
	
	return v_comres_s8;
	
}

/*_________________________________________Register Read__________________________________*/
//Read from any register adress
// fn parameters: v_RegAddr_u8  : Use macros for the register adress from ITG3050.h file
//				  p_RegValue_u8 : Pointer to the variable where data is read
//				  v_BitPos_u8   : The starting position of the desired bit,use macros bitname__POS from ITG3050.h
//				  v_BitsMask_u8 : Bit mask, use macros bitname__MSK from ITG3050.h
//fn Return : SUCESS = 0; or FAILURE = -1;
S8 ITG3050_READ_REGISTER(U8 v_RegAddr_u8, U8 *p_RegValue_u8, U8 v_BitPos_u8, U8 v_BitsMask_u8)	
{
	S8 v_comres_s8;
	
	if (P_ITG3050_XS==0)
		return -1;
	
	v_comres_s8 = P_ITG3050_XS->ITG3050_BUS_READ_FUNC(P_ITG3050_XS->v_DevAddr_u8, v_RegAddr_u8, p_RegValue_u8,1);
	
	*p_RegValue_u8 = (*p_RegValue_u8 & v_BitsMask_u8)>>v_BitPos_u8;
	
	return v_comres_s8;
	
}

