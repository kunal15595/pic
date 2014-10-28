/*
 * File:   		BMP085.c
 * Created: 	3rd December, 2011, 7:00 PM 
 * Author:		gopal.jatiya@brigosha.com 
 * Version      v0.1
 * Comment:		Coding Standard Implemented
 */
 /*Version Number		Modified by		Date
	0.1					Gopal Jatiya	3rd December, 2011
	0.2					Gopal Jatiya	19th August, 2012
*/
 /***************** Include System and sensor header files **********************************/
#include "BMP085.h"

ts_bmp085 *P_BMP085_XS;

/************ Local Functions Prototype ***************/
S8 bmp085_get_cal_param(void);
S8 bmp085_start_ut(void);
U16 bmp085_get_ut(void);
S8 bmp085_start_up(void);
U32 bmp085_get_up(void);
S16 bmp085_get_temperature(U16);
S32 bmp085_get_pressure(U32);

/*_________________________________________ Initialize the Communication and gets ChipID______________________*/
// Intialize the the bmp085 
// fn parameters: pointer to structure ts_bmp085
// fn Return : Initialize SUCESS = 0; or Initialize FAILURE = -1;	
S8 BMP085_INIT(ts_bmp085 *p_bmp085_xs )
{
	S8 v_ComRes_s8=0;
	U8 v_data_u8;

	P_BMP085_XS = p_bmp085_xs;                                      /* assign BMP085 ptr */
	P_BMP085_XS->v_DevAdd_u8 = C_BMP085_I2CAdd;                   /* preset BMP085 I2C_addr */
	v_ComRes_s8 += P_BMP085_XS->BMP085_BUS_READ_FUNC(P_BMP085_XS->v_DevAdd_u8, C_BMP085_CHIP_ID__REG, &v_data_u8, 1);  /* read Chip Id */
  
	P_BMP085_XS->v_ChipID_u8 = BMP085_GET_BITSLICE(v_data_u8, C_BMP085_CHIP_ID);  
	P_BMP085_XS->v_No_of_Samples_u8 = 1;  
	P_BMP085_XS->v_OversamplingSetting_u8=0;
	
	v_ComRes_s8 += P_BMP085_XS->BMP085_BUS_READ_FUNC(P_BMP085_XS->v_DevAdd_u8, C_BMP085_VERSION_REG, &v_data_u8, 1); /* read Version reg */
    
    P_BMP085_XS->v_MLversion_u8 = BMP085_GET_BITSLICE(v_data_u8, C_BMP085_ML_VERSION);        /* get ML Version */
    P_BMP085_XS->v_ALversion_u8 = BMP085_GET_BITSLICE(v_data_u8, C_BMP085_AL_VERSION);        /* get AL Version */
	
	v_ComRes_s8 = bmp085_get_cal_param(); /* readout bmp085 calibparam structure */
	
	return v_ComRes_s8;
	
}
/*___________________________________________To read the pressure and temperature________*/
//To get the current pressure in pascals
//fn parameters: poniter to variable to store pressure and temperature data
//fn return: Sucess = 1; Wait to complete =0 ; Failure =-1
//This function should be called thrice at an interval of 5ms atleast.
//It returns correct pressure only when the communication result returns 1
S8 BMP085_GET_Pressure_Teperature(S32 *p_Pres_s32, S16 *p_Temp_s16)
{
	S8 v_ComRes_s8 =0;
	U16 v_ut_u16;
	U32 v_up_u32;
	
	static U8 v_State_u8 = 0;
	
	switch(v_State_u8)
	
	{	case 	0:
			v_ComRes_s8 = bmp085_start_ut();
			v_State_u8=1;
			break;
		case	1:
			v_ut_u16 = bmp085_get_ut();
			v_ComRes_s8 = bmp085_start_up();
			v_State_u8=2;
			break;
		case	2:
			v_up_u32 = bmp085_get_up();
			*p_Temp_s16 = bmp085_get_temperature(v_ut_u16);
			*p_Pres_s32 = bmp085_get_pressure(v_up_u32);
			v_ComRes_s8 = 1;
			v_State_u8 = 0;
			break;
		default:
			break;
	}
	
	return v_ComRes_s8;
	
}

/************ Local Function Definitions *********/

/***************************** Reads calibration parameters ***************/
// Reads the calibration parameter structure of bmp085
//fn parameter: void
//fn Return : SUCESS = 0; or FAILURE = -1;	
S8 bmp085_get_cal_param(void)
{
	S8 v_ComRes_s8=0;
	U8 a_data_u8[22];
        S16 v_Temp1_s16,v_Temp2_s16;
        U16 v_Temp3_u16,v_Temp4_u16;
	v_ComRes_s8 = P_BMP085_XS->BMP085_BUS_READ_FUNC(P_BMP085_XS->v_DevAdd_u8, C_BMP085_PROM_START__ADDR, a_data_u8, C_BMP085_PROM_DATA__LEN);
  
	/*parameters AC1-AC6*/
	v_Temp1_s16 = (S16)a_data_u8[0],v_Temp2_s16 = (S16)a_data_u8[1];
        P_BMP085_XS->s_CalParam_xs.ac1 =  (v_Temp1_s16<<8) | v_Temp2_s16;
        v_Temp1_s16 = (S16)a_data_u8[2],v_Temp2_s16 = (S16)a_data_u8[3];
	P_BMP085_XS->s_CalParam_xs.ac2 =  (v_Temp1_s16<<8) | v_Temp2_s16;
        v_Temp1_s16 = (S16)a_data_u8[4],v_Temp2_s16 = (S16)a_data_u8[5];
	P_BMP085_XS->s_CalParam_xs.ac3 =  (v_Temp1_s16<<8) | v_Temp2_s16;
        v_Temp3_u16 = (U16)a_data_u8[6],v_Temp4_u16 = (U16)a_data_u8[7];
	P_BMP085_XS->s_CalParam_xs.ac4 =  (v_Temp3_u16<<8) | v_Temp4_u16;
        v_Temp3_u16 = (U16)a_data_u8[8],v_Temp4_u16 = (U16)a_data_u8[9];
	P_BMP085_XS->s_CalParam_xs.ac5 =   (v_Temp3_u16<<8) | v_Temp4_u16;
        v_Temp3_u16 = (U16)a_data_u8[10],v_Temp4_u16 = (U16)a_data_u8[11];
	P_BMP085_XS->s_CalParam_xs.ac6 = (v_Temp3_u16<<8) | v_Temp4_u16;
  
	/*parameters B1,B2*/
	v_Temp1_s16 = (S16)a_data_u8[12],v_Temp2_s16 = (S16)a_data_u8[13];
        P_BMP085_XS->s_CalParam_xs.b1 =  (v_Temp1_s16<<8) | v_Temp2_s16;
        v_Temp1_s16 = (S16)a_data_u8[14],v_Temp2_s16 = (S16)a_data_u8[15];
	P_BMP085_XS->s_CalParam_xs.b2 =  (v_Temp1_s16<<8) | v_Temp2_s16;
  
	/*parameters MB,MC,MD*/
        v_Temp1_s16 = (S16)a_data_u8[16],v_Temp2_s16 = (S16)a_data_u8[17];
	P_BMP085_XS->s_CalParam_xs.mb =  (v_Temp1_s16<<8) | v_Temp2_s16;
        v_Temp1_s16 = (S16)a_data_u8[18],v_Temp2_s16 = (S16)a_data_u8[19];
	P_BMP085_XS->s_CalParam_xs.mc =  (v_Temp1_s16<<8) | v_Temp2_s16;
        v_Temp1_s16 = (S16)a_data_u8[20],v_Temp2_s16 = (S16)a_data_u8[21];
	P_BMP085_XS->s_CalParam_xs.md =  (v_Temp1_s16<<8) | v_Temp2_s16;
  
	return v_ComRes_s8;
}

/***************************** Start Temperature Measurement ************/
// Starts the temperature Measurement
//fn parameter: void
//fn return: SUCESS = 0; or FAILURE = -1;
S8 bmp085_start_ut(void)
{   
	U8 v_ctrl_reg_data_u8 = C_BMP085_T_MEASURE;
	S8 v_ComRes_s8=0;
	
	v_ComRes_s8 = P_BMP085_XS->BMP085_BUS_WRITE_FUNC(P_BMP085_XS->v_DevAdd_u8, C_BMP085_CTRL_MEAS_REG, &v_ctrl_reg_data_u8, 1);
	
	return v_ComRes_s8; 
}

/********************** get uncompensated temperature ************/
// get the uncompensated temperature
// fn parameter: void
// fn return: v_ut_u16 uncompensated temperature
U16 bmp085_get_ut(void)
{
	U16 v_ut_u16;
	U8 a_data_u8[2];
        U16 v_Temp1_u16,v_Temp2_u16;
	
	P_BMP085_XS->BMP085_BUS_READ_FUNC(P_BMP085_XS->v_DevAdd_u8, C_BMP085_ADC_OUT_MSB_REG, a_data_u8, 2);
	v_Temp1_u16 = (U16)(a_data_u8[0]);
        v_Temp2_u16 = (U16)(a_data_u8[1]);
        v_ut_u16 =(v_Temp1_u16<<8) | v_Temp2_u16;
	
	return v_ut_u16;
}

/***************************** Start Pressure Measurement ************/
// Starts the pressure Measurement
//fn parameter: void
//fn return: SUCESS = 0; or FAILURE = -1;
S8 bmp085_start_up(void)
{
	S8 v_ComRes_s8=0;
	U8 v_ctrl_reg_data_u8;
	
	v_ctrl_reg_data_u8 = C_BMP085_P_MEASURE + (P_BMP085_XS->v_OversamplingSetting_u8 << 6);
   	v_ComRes_s8 = P_BMP085_XS->BMP085_BUS_WRITE_FUNC(P_BMP085_XS->v_DevAdd_u8, C_BMP085_CTRL_MEAS_REG, &v_ctrl_reg_data_u8, 1);
	
	return v_ComRes_s8;
}

/********************** get uncompensated pressure ************/
// get the uncompensated pressure
// fn parameter: void
// fn return: v_up_u16 uncompensated pressure
U32 bmp085_get_up(void)
{
	U32 v_up_u32;
	U8 a_data_u8[3];
	U32 v_Temp1_u32,v_Temp2_u32,v_Temp3_u32;

	P_BMP085_XS->BMP085_BUS_READ_FUNC(P_BMP085_XS->v_DevAdd_u8, C_BMP085_ADC_OUT_MSB_REG, a_data_u8, 3);
	v_Temp1_u32 = ((U32) a_data_u8[0]);
        v_Temp2_u32 = ((U32) a_data_u8[1]);
        v_Temp3_u32 = ((U32) a_data_u8[2]);

        v_up_u32 = ((v_Temp1_u32 << 16) | (v_Temp2_u32 << 8) | v_Temp3_u32) >> (8-P_BMP085_XS->v_OversamplingSetting_u8);
	
	return v_up_u32;
}

/************************ Get temperature *************/
//Get the compensated temperature
// fn parameter:  uncompensated temperature
// fn returm: temperature
S16 bmp085_get_temperature(U16 v_ut_u16)
{
	S16 v_temperature_s16;
	S32 v_x1_s32,v_x2_s32;    

    v_x1_s32 = (((S32) v_ut_u16 - (S32) P_BMP085_XS->s_CalParam_xs.ac6) * (S32) P_BMP085_XS->s_CalParam_xs.ac5) >> 15;
    v_x2_s32 = (((S32) P_BMP085_XS->s_CalParam_xs.mc) << 11) / (v_x1_s32 + P_BMP085_XS->s_CalParam_xs.md);
    P_BMP085_XS->v_param_b5_s32 = v_x1_s32 + v_x2_s32;
	
	v_temperature_s16 = ((P_BMP085_XS->v_param_b5_s32 + 8) >> 4);  // temperature in 0.1°C

	return (v_temperature_s16);
}

/************************ Get Pressure *************/
//Get the compensated pressure
// fn parameter:  uncompensated pressure
// fn returm: pressure
S32 bmp085_get_pressure(U32 v_up_u32)
{
   S32 v_pressure_s32,v_x1_s32,v_x2_s32,v_x3_s32,v_b3_s32,v_b6_s32;
   U32 v_b4_u32, v_b7_u32;
   
   v_b6_s32 = P_BMP085_XS->v_param_b5_s32 - 4000;
   //*****calculate B3************
   v_x1_s32 = (v_b6_s32*v_b6_s32) >> 12;	 	 
   v_x1_s32 *= P_BMP085_XS->s_CalParam_xs.b2;
   v_x1_s32 >>=11;

   v_x2_s32 = (P_BMP085_XS->s_CalParam_xs.ac2*v_b6_s32);
   v_x2_s32 >>=11;

   v_x3_s32 = v_x1_s32 +v_x2_s32;

	v_b3_s32 = (((((S32)P_BMP085_XS->s_CalParam_xs.ac1 )*4 + v_x3_s32) <<P_BMP085_XS->v_OversamplingSetting_u8) + 2) >> 2;

   //*****calculate B4************
   v_x1_s32 = (P_BMP085_XS->s_CalParam_xs.ac3* v_b6_s32) >> 13;
   v_x2_s32 = (P_BMP085_XS->s_CalParam_xs.b1 * ((v_b6_s32*v_b6_s32) >> 12) ) >> 16;
   v_x3_s32 = ((v_x1_s32 + v_x2_s32) + 2) >> 2;
   v_b4_u32 = (P_BMP085_XS->s_CalParam_xs.ac4 * (U32) (v_x3_s32 + 32768)) >> 15;
     
   v_b7_u32 = ((U32)(v_up_u32 - v_b3_s32) * (50000>>P_BMP085_XS->v_OversamplingSetting_u8));   
   if (v_b7_u32 < 0x80000000)
   {
     v_pressure_s32 = (v_b7_u32 << 1) / v_b4_u32;
   }
   else
   { 
     v_pressure_s32 = (v_b7_u32 / v_b4_u32) << 1;
   }
   
   v_x1_s32 = v_pressure_s32 >> 8;
   v_x1_s32 *= v_x1_s32;
   v_x1_s32 = (v_x1_s32 * C_BMP085_PARAM_MG) >> 16;
   v_x2_s32 = (v_pressure_s32 * C_BMP085_PARAM_MH) >> 16;
   v_pressure_s32 += (v_x1_s32 + v_x2_s32 + C_BMP085_PARAM_MI) >> 4;	// pressure in Pa  

   return (v_pressure_s32);
}
