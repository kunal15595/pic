/*
 * File:   		HMC5883.c
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
 /***************** Include System and sensor header files **********************************/  

#include "hmc5883.h"

ts_hmc5883 *P_HMC5883_XS;

/*_________________________________________ Initialize hmc5883 structure______________________*/
// Intialize the the HMC5883
// fn parameters: pointer to structure ts_hmc5883
// fn Return : Initialize SUCESS = 0; or Initialize FAILURE = -1;

S8 HMC5883_INIT(ts_hmc5883 *hmc5883)
{
	S8 v_ComRes_s8 = 0;
	U8 v_Data_u8;
	
	P_HMC5883_XS = hmc5883;
	P_HMC5883_XS->v_DevAdd_u8 = C_HMC5883_I2C_ADDRESS;
	v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_IDA_REG,&v_Data_u8,1);
	P_HMC5883_XS->v_DeviceID_u8 = v_Data_u8;
	
	return v_ComRes_s8;
}

/*_______________________________________ Read Magnetic Data on X,Y and Z __________________*/
//Reads magnetic data along x,y and z axes
//fn parameters: Pointer to the structure of magnetic data to store the value
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1;

S8 HMC5883_GET_MData_xyz(ts_hmc5883_mdata * p_MagData_xs)
{
	S8 v_ComRes_s8 = 0;
	U8 a_data_u8[6];
	
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{
		/*Read magnetic data from the data register*/
		v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_MDATA_REG,a_data_u8,6);
		/*Merging and Typecasting*/
		p_MagData_xs->v_DataX_s16 = ((S16)(a_data_u8[0])<<8) | (S16)a_data_u8[1];
		p_MagData_xs->v_DataY_s16 = ((S16)(a_data_u8[4])<<8) | (S16)a_data_u8[5];
		p_MagData_xs->v_DataZ_s16 = ((S16)(a_data_u8[2])<<8) | (S16)a_data_u8[3];
	}
	
	return v_ComRes_s8;
}

/*_________________________________________Set Measurement Configuration Mode ________________*/
//Sets the measurement configuration as normal , positive or negative
/*fn parameter: Variable to set the configuration mode, see hmc5883.h for macros
				e.g: C_HMC5883_NORMAL_MEASURE_MODE: Normal Measurement Mode
				 */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_SET_Measurement_Mode(U8 v_MeasMode_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		if(v_MeasMode_u8>C_HMC5883_NEGATIVE_BIAS_MODE)
		{
			v_ComRes_s8=-2; /*If the value is greater than 2 its out of range */
		}
		else
		{
			/* Read the status of the configuration A register */
			v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGA_MEASUREMENT__REG,&v_data_u8,1);
			/* Set the measurement mode bits in the configuration A register according to the functional state passed as a argument */
			v_data_u8 = HMC5883_SET_BITSLICE(v_data_u8, C_HMC5883_CONFIGA_MEASUREMENT, v_MeasMode_u8);
			/* write mode configuration A register with the modified value */
			v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_WRITE_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGA_MEASUREMENT__REG,&v_data_u8,1);
		}
	}
	
	return v_ComRes_s8;
}

/*_________________________________________Get Measurement Configuration Mode ________________*/
//Gets the measurement configuration as normal , positive or negative
/*fn parameter: Pointer to a variable to store the configuration mode
				0x00: Normal Measurement Mode
				0x01: Positive Bias
				0x02: Negative Bias */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_GET_Measurement_Mode(U8 *p_MeasMode_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		/* Read the status of the configuration A register */
		v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGA_MEASUREMENT__REG,&v_data_u8,1);
		/* Get the measurement mode bits in the configuration A register */
		v_data_u8 = HMC5883_GET_BITSLICE(v_data_u8, C_HMC5883_CONFIGA_MEASUREMENT);
		*p_MeasMode_u8 = v_data_u8;
		
	}
	return v_ComRes_s8;
}

/*_________________________________________Set Output Data Rate ________________*/
//Sets the output data rate of the sensor
/*fn parameter: Variable to containing the data rate to set,see hmc5883.h for macros
				e.g: C_HMC5883_DATA_RATE_0_75_HZ: 0.75 Hz
				 */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_SET_DataRate(U8 v_DataRate_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		if(v_DataRate_u8>C_HMC5883_DATA_RATE_75_HZ)
		{
			v_ComRes_s8=-2; /*If the value is greater than 6 its out of range */
		}
		else
		{
			/* Read the status of the configuration A register */
			v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGA_DATAOUTRATE__REG,&v_data_u8,1);
			/* Set the data rate bits in the configuration A register according to the functional state passed as a argument */
			v_data_u8 = HMC5883_SET_BITSLICE(v_data_u8, C_HMC5883_CONFIGA_DATAOUTRATE, v_DataRate_u8);
			/* write mode configuration A register with the modified value */
			v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_WRITE_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGA_DATAOUTRATE__REG,&v_data_u8,1);
		}
	}
	
	return v_ComRes_s8;
}

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
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_GET_DataRate(U8 *p_DataRate_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		/* Read the status of the configuration A register */
		v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGA_DATAOUTRATE__REG,&v_data_u8,1);
		/* Get the data bits in the configuration A register */
		v_data_u8 = HMC5883_GET_BITSLICE(v_data_u8, C_HMC5883_CONFIGA_DATAOUTRATE);
		*p_DataRate_u8 = v_data_u8;	
	}
	
	return v_ComRes_s8;
}

/*_________________________________________Set No of samples to avg ________________*/
//Sets the no. of samples to be averaged
/*fn parameter: Variable to set the no. of samples,see hmc5883.h for macros
				e.g. C_HMC5883_NO_SAMPLES_1: 1 sample average per measurement output
				 */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_SET_No_Samples(U8 v_NumSamples_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		if(v_NumSamples_u8>C_HMC5883_NO_SAMPLES_8)
		{
			v_ComRes_s8=-2; /*If the value is greater than 3 its out of range */
		}
		else
		{
			/* Read the status of the configuration A register */
			v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGA_NO_SAMPLES__REG,&v_data_u8,1);
			/* Set the no. of samples bits in the configuration A register according to the functional state passed as a argument */
			v_data_u8 = HMC5883_SET_BITSLICE(v_data_u8, C_HMC5883_CONFIGA_NO_SAMPLES, v_NumSamples_u8);
			/* write mode configuration A register with the modified value */
			v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_WRITE_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGA_NO_SAMPLES__REG,&v_data_u8,1);
		}
	}
	
	return v_ComRes_s8;
}

/*_________________________________________Get No of samples to avg ________________*/
//Gets the no. of samples that are averaged
/*fn parameter: Pointer to Variable to get the no. of samples
				0: 1 sample average per measurement output
				1: 2 samples average per measurement output
				2: 4 samples average per measurement output
				3: 8 samples average per measurement output */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_GET_No_Samples(U8 *p_NumSamples_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		/* Read the status of the configuration A register */
		v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGA_NO_SAMPLES__REG,&v_data_u8,1);
		/* Get the no. of samples bits in the configuration A register*/
		v_data_u8 = HMC5883_GET_BITSLICE(v_data_u8, C_HMC5883_CONFIGA_NO_SAMPLES);
		*p_NumSamples_u8 = v_data_u8;
		
	}
	
	return v_ComRes_s8;
}

/*_________________________________________Set Gain ________________*/
//Sets the gain of the sensor
/*fn parameter: Variable to containing the gain to set
				e.g: C_HMC5883_GAIN_0_88_GA: +/- 0.88 Ga (1370 LSB/Gauss)
					 C_HMC5883_GAIN_1_3_GA:  +/- 1.3  Ga (1090 LSB/Gauss)
					 C_HMC5883_GAIN_1_9_GA:  +/- 1.9  Ga (820 LSB/Gauss)
					 C_HMC5883_GAIN_2_5_GA:  +/- 2.5  Ga (660 LSB/Gauss)
					 C_HMC5883_GAIN_4_GA:    +/- 4.0  Ga (440 LSB/Gauss)
					 C_HMC5883_GAIN_4_7_GA:  +/- 4.7  Ga (390 LSB/Gauss)
					 C_HMC5883_GAIN_5_6_GA:  +/- 5.6  Ga (330 LSB/Gauss)
					 C_HMC5883_GAIN_8_1_GA:  +/- 8.1  Ga (230 LSB/Gauss) */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_SET_Gain(U8 v_Gain_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		if(v_Gain_u8>C_HMC5883_GAIN_8_1_GA)
		{
			v_ComRes_s8=-2; /*If the value is greater than 7 its out of range */
		}
		else
		{
			/* Read the status of the configuration B register */
			v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGB_GAIN__REG,&v_data_u8,1);
			/* Set the data rate bits in the configuration B register according to the functional state passed as a argument */
			v_data_u8 = HMC5883_SET_BITSLICE(v_data_u8, C_HMC5883_CONFIGB_GAIN, v_Gain_u8);
			/* write mode configuration A register with the modified value */
			v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_WRITE_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGB_GAIN__REG,&v_data_u8,1);
		}
	}
	
	return v_ComRes_s8;
}

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

S8 HMC5883_GET_Gain(U8 *p_Gain_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		/* Read the status of the configuration B register */
		v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_CONFIGB_GAIN__REG,&v_data_u8,1);
		/* Set the data rate bits in the configuration B register */
		v_data_u8 = HMC5883_GET_BITSLICE(v_data_u8, C_HMC5883_CONFIGB_GAIN);
		*p_Gain_u8 = v_data_u8;
		
	}
	
	return v_ComRes_s8;
}

/*_________________________________________Set Operation Mode ________________*/
//Sets the operation mode of the sensor as continuous, single or idle
/*fn parameter: Variable to set the operation mode,see hmc5883.h for macros
				e.g. C_HMC5883_CONTINUOUS_MEASUREMENT_MODE: Continuous Measurement Mode
				 */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1 or OUT OF RANGE=-2;

S8 HMC5883_SET_OperationMode(U8 v_Mode_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		if(v_Mode_u8>C_HMC5883_SLEEP_MODE)
		{
			v_ComRes_s8=-2; /*If the value is greater than 2 its out of range */
		}
		else
		{
			/* Read the status of the MODE register */
			v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_MODE_MD__REG,&v_data_u8,1);
			/* Set the operation mode bits in the MODE register according to the functional state passed as a argument */
			v_data_u8 = HMC5883_SET_BITSLICE(v_data_u8, C_HMC5883_MODE_MD, v_Mode_u8);
			/* write MODE register with the modified value */
			v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_WRITE_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_MODE_MD__REG,&v_data_u8,1);
		}
	}
	
	return v_ComRes_s8;
}

/*_________________________________________Get Operation Mode ________________*/
//Gets the operation mode of the sensor as continuous, single or idle
/*fn parameter: Pointer to variable to get the operation mode
				0: Continuous Measurement Mode
				1: Single Measurement Mode
				2: Idle Mode 
				3: Sleep Mode */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_GET_OperationMode(U8 *p_Mode_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		/* Read the status of the MODE register */
		v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_MODE_MD__REG,&v_data_u8,1);
		/* Get the operation mode bits in the MODE register */
		v_data_u8 = HMC5883_GET_BITSLICE(v_data_u8, C_HMC5883_MODE_MD);
		*p_Mode_u8 = v_data_u8;
		
	}
	
	return v_ComRes_s8;
}

/*_________________________________________Get Data Ready Status ________________*/
//Gets Data Ready Status bit
/*fn parameter: Pointer to variable to get the Data ready status
				0: Measurement has started
				1: Data is ready */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_GET_DataRdy(U8 *p_Rdy_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		/* Read  the status register */
		v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_STATUS_RDY__REG,&v_data_u8,1);
		/* Get the operation mode bits in the MODE register */
		v_data_u8 = HMC5883_GET_BITSLICE(v_data_u8, C_HMC5883_STATUS_RDY);
		*p_Rdy_u8 = v_data_u8;
		
	}
	
	return v_ComRes_s8;
}

/*_________________________________________Get Lock ________________*/
//Gets Lock Status bit
/*fn parameter: Pointer to variable to get the Lock status
				0: Data Output Register not locked
				1: Data Output Register Locked */
//fn return: Communication Result. SUCESS = 0 or FAILURE = -1

S8 HMC5883_GET_Lock(U8 *p_Lock_u8)
{
	S8 v_ComRes_s8 = 0;
	U8 v_data_u8;
	if(P_HMC5883_XS == C_HMC5883_NULL)
	{
		v_ComRes_s8=-1;
	}
	else
	{	
		/* Read  the status register */
		v_ComRes_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8,C_HMC5883_STATUS_LOCK__REG,&v_data_u8,1);
		/* Get the operation mode bits in the MODE register */
		v_data_u8 = HMC5883_GET_BITSLICE(v_data_u8, C_HMC5883_STATUS_LOCK);
		*p_Lock_u8 = v_data_u8;
		
	}
	
	return v_ComRes_s8;
}

/*_________________________________________Register Write__________________________________*/
//Write to any register adress
// fn parameters: v_RegAddr_u8  : Use macros for the register adress from HMC5883.h file
//				  v_RegValue_u8 : The Value of the bit(s) to be written onto the register
//				  v_BitPos_u8   : The starting position of the desired bit,use macros bitname__POS from HMC5883.h
//				  v_BitsMask_u8 : Bit mask, use macros bitname__MSK from HMC5883.h
//fn Return : SUCESS = 0; or FAILURE = -1;
S8 HMC5883_WRITE_Register(U8 v_RegAddr_u8, U8 v_RegValue_u8, U8 v_BitPos_u8, U8 v_BitsMask_u8)	
{
	S8 v_comres_s8;
	U8 v_data_u8;
	
	if (P_HMC5883_XS==0)
		return -1;
	
	v_comres_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8, v_RegAddr_u8, &v_data_u8,1);
	v_data_u8 = (v_data_u8 & (~v_BitsMask_u8)) | ((v_RegValue_u8<<v_BitPos_u8) & v_BitsMask_u8);
	v_comres_s8 += P_HMC5883_XS->HMC5883_BUS_WRITE_FUNC(P_HMC5883_XS->v_DevAdd_u8, v_RegAddr_u8, &v_data_u8, 1 );
	
	return v_comres_s8;
	
}

/*_________________________________________Register Read__________________________________*/
//Read from any register adress
// fn parameters: v_RegAddr_u8  : Use macros for the register adress from HMC5883.h file
//				  p_RegValue_u8 : Pointer to the variable where data is read
//				  v_BitPos_u8   : The starting position of the desired bit,use macros bitname__POS from HMC5883.h
//				  v_BitsMask_u8 : Bit mask, use macros bitname__MSK from HMC5883.h
//fn Return : SUCESS = 0; or FAILURE = -1;
S8 HMC5883_READ_Register(U8 v_RegAddr_u8, U8 *p_RegValue_u8, U8 v_BitPos_u8, U8 v_BitsMask_u8)	
{
	S8 v_comres_s8;
	
	if (P_HMC5883_XS==0)
		return -1;
	
	v_comres_s8 = P_HMC5883_XS->HMC5883_BUS_READ_FUNC(P_HMC5883_XS->v_DevAdd_u8, v_RegAddr_u8, p_RegValue_u8,1);
	
	*p_RegValue_u8 = (*p_RegValue_u8 & v_BitsMask_u8)>>v_BitPos_u8;
	
	return v_comres_s8;
	
}

