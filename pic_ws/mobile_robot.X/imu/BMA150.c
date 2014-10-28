/*
 * File:   		BMA150.c
 * Created: 	4th August, 2012, 12:26 PM 
 * Author:		gopal.jatiya@brigosha.com 
 * Version      v0.1
 * Comment:		Coding Standard Implemented
 */
 
 /***************** Include System and sensor header files **********************************/
  
#include "DEFINE.h"
#include "bma150.h"

ts_bma150 *P_BMA150_XS;

/*_________________________________________ Initialize the Communicationa and verify ChipID______________________*/
// Intialize the the accel BMA150 and Open the I2C 
// fn parameters: pointer to structure ts_bma150
// fn Return : Initialize SUCESS = 0; or Initialize FAILURE = -1;

S8 BMA150_INIT(ts_bma150 *p_bma150_xs) 
{
	S8 v_comres_s8=0;
	unsigned char v_data_u8;

	P_BMA150_XS = p_bma150_xs;							/* assign bma150 ptr */
	P_BMA150_XS->v_DevAdd_u8 = C_BMA150_I2CAdd;			/* preset BMA150 I2C_addr */
	v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_CHIP_ID__REG, &v_data_u8, 1);	/* read Chip Id */
	
	P_BMA150_XS->v_chipID_u8 = BMA150_GET_BITSLICE(v_data_u8, C_BMA150_CHIP_ID);	/* get bitslice */
		
	v_comres_s8 += P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_ML_VERSION__REG, &v_data_u8, 1); /* read Version reg */
	P_BMA150_XS->v_mlVersion_u8 = BMA150_GET_BITSLICE(v_data_u8, C_BMA150_ML_VERSION);				/* get ML Version */
	P_BMA150_XS->v_alVersion_u8 = BMA150_GET_BITSLICE(v_data_u8, C_BMA150_AL_VERSION);				/* get AL Version */

	return v_comres_s8;

}

/*_________________________________________ write eew bit______________________*/
// Write eew bit to lock/unlock the EEPROM 
// fn parameters: v_eew_u8 0= lock EEPROM 1 = unlock EEPROM
// fn Return : SUCESS = 0; or FAILURE = -1;
S8 BMA150_SET_EE_W(unsigned char v_eew_u8)
{
	unsigned char v_data_u8;
	S8 v_comres_s8=0;
	
	if (P_BMA150_XS==0)
		return -1;
	
  	v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_EE_W__REG,&v_data_u8, 1);
	v_data_u8 = BMA150_SET_BITSLICE(v_data_u8, C_BMA150_EE_W, v_eew_u8);
	v_comres_s8 = P_BMA150_XS->BMA150_BUS_WRITE_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_EE_W__REG, &v_data_u8, 1);
	return v_comres_s8;
}

/*_________________________________________ set bma150s range______________________*/
// Set the range of the accelerometer
// fn parameters: v_Range_s8
// See the constants C_BMA150_RANGE_2G and others
// fn Return : SUCESS = 0; or FAILURE = -1;
S8 BMA150_SET_RANGE(char v_Range_s8) 
{			
   S8 v_comres_s8 = 0;
   unsigned char v_data_u8;

   if (P_BMA150_XS==0)
	    return -1;

   if (v_Range_s8<3) 
   {	
		v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_RANGE__REG, &v_data_u8, 1 );
		v_data_u8 = BMA150_SET_BITSLICE(v_data_u8, C_BMA150_RANGE, v_Range_s8);		  	
		v_comres_s8 += P_BMA150_XS->BMA150_BUS_WRITE_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_RANGE__REG, &v_data_u8, 1);
   }
   else
		return -1;
		
   return v_comres_s8;

}

/*_________________________________________ get bma150s range______________________*/
// get the range of the accelerometer
// fn parameters: pointer to store range p_Range_u8
// fn Return : SUCESS = 0; or FAILURE = -1;
S8 BMA150_GET_RANGE(unsigned char *p_Range_u8) 
{

	S8 v_comres_s8 = 0;
	

	if (P_BMA150_XS==0)
		return -1;
	v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_RANGE__REG, p_Range_u8, 1 );

	*p_Range_u8 = BMA150_GET_BITSLICE(*p_Range_u8, C_BMA150_RANGE);
	
	return v_comres_s8;

}

/*_________________________________________ set BMA150s operation mode______________________*/
// Set the operation mode of bma150
// fn parameters: v_Mode_u8: 0 = normal, 1 = sleep
// See the constants C_BMA150_MODE_NORMAL and others
// fn Return : SUCESS = 0; or FAILURE = -1;
S8 BMA150_SET_MODE(unsigned char v_Mode_u8) 
{
	
	S8 v_comres_s8=0;
	unsigned char v_data1_u8;
	unsigned char v_data2_u8;

        if (P_BMA150_XS==0)
	    return -1;
        
	if (v_Mode_u8<3) {
		v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_WAKE_UP__REG, &v_data1_u8, 1 );
                v_comres_s8 += P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_SLEEP__REG, &v_data2_u8, 1 );
		switch (v_Mode_u8)
		{
	 		case C_BMA150_MODE_NORMAL:
				v_data1_u8  = BMA150_SET_BITSLICE(v_data1_u8, C_BMA150_WAKE_UP, 0);
				v_data2_u8  = BMA150_SET_BITSLICE(v_data2_u8, C_BMA150_SLEEP, 0);
				break;
			case C_BMA150_MODE_SLEEP:
				v_data1_u8  = BMA150_SET_BITSLICE(v_data1_u8, C_BMA150_WAKE_UP, 0);
				v_data2_u8  = BMA150_SET_BITSLICE(v_data2_u8, C_BMA150_SLEEP, 1);
				break;
			case C_BMA150_MODE_WAKE_UP:
				v_data1_u8  = BMA150_SET_BITSLICE(v_data1_u8, C_BMA150_WAKE_UP, 1);
				v_data2_u8= BMA150_SET_BITSLICE(v_data2_u8, C_BMA150_SLEEP, 0);
				break;
			default:
				return -1;
			break;
		}
		v_comres_s8 += P_BMA150_XS->BMA150_BUS_WRITE_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_WAKE_UP__REG, &v_data1_u8, 1);
	  	v_comres_s8 += P_BMA150_XS->BMA150_BUS_WRITE_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_SLEEP__REG, &v_data2_u8, 1);
		P_BMA150_XS->v_mode_u8 = v_Mode_u8;
	}
        else
            return -1;
	return v_comres_s8;
}

/*_________________________________________ set BMA150 internal filter bandwidth______________________*/
// Set the internal filter bandwidth of bma150
// fn parameters: v_BW_u8
// See the constants C_BMA150_BW_25HZ and others
// fn Return : SUCESS = 0; or FAILURE = -1;
S8 BMA150_SET_BANDWIDTH(unsigned char v_BW_u8) 
{
	S8 v_comres_s8 = 0;
	unsigned char v_data1_u8;


	if (P_BMA150_XS==0)
		return -1;

	if (v_BW_u8<7) {

  	  v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_BW__REG, &v_data1_u8, 1 );
	  v_data1_u8 = BMA150_SET_BITSLICE(v_data1_u8, C_BMA150_BW, v_BW_u8);
	  v_comres_s8 += P_BMA150_XS->BMA150_BUS_WRITE_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_BW__REG, &v_data1_u8, 1 );

	}
	else
		return -1;
	
    return v_comres_s8;


}

/*_________________________________________ get bma150s bandwidth______________________*/
// get the bandwidth of the accelerometer
// fn parameters: pointer to store bandwidth p_BW_u8
// fn Return : SUCESS = 0; or FAILURE = -1;
S8 BMA150_GET_BANDWIDTH(unsigned char *p_BW_u8) 
{
	S8 v_comres_s8 = 1;
	
	if (P_BMA150_XS==0)
		return -1;

	v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_BW__REG, p_BW_u8, 1 );

	*p_BW_u8 = BMA150_GET_BITSLICE(*p_BW_u8, C_BMA150_BW);
	
	return v_comres_s8;

}

/*_________________________________________ X,Y and Z-axis acceleration data readout______________________*/
// reads the accel data on x, y and z
// fn parameters: p_Acc_xs: pointer to structure ts_AccData for x,y,z readout
// fn Return : SUCESS = 0; or FAILURE = -1;
S8 BMA150_READ_ACCEL_XYZ(ts_AccData * p_Acc_xs)
{
	S8 v_comres_s8;
	unsigned char v_data_u8[6];
        short v_lsb_s16;
        short v_msb_s16;
        short v_TotalData_s16;

	if (P_BMA150_XS==0)
		return -1;
	
	v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_ACC_X_LSB__REG, v_data_u8,6);
	

	v_lsb_s16 = ((short)(v_data_u8[0] & C_BMA150_ACC_X_LSB__MSK))>>C_BMA150_ACC_X_LSB__POS;
        v_msb_s16 = ((short)(v_data_u8[1] & C_BMA150_ACC_X_MSB__MSK))<<C_BMA150_ACC_X_LSB__LEN;
        v_TotalData_s16 = (v_lsb_s16 | v_msb_s16);
        
        if(v_TotalData_s16 & 0x0200)
        {
            v_TotalData_s16 |=0xFC00;
        }
        p_Acc_xs->v_ax_s16 = v_TotalData_s16;
	
	v_lsb_s16 = ((short)(v_data_u8[2] & C_BMA150_ACC_Y_LSB__MSK))>>C_BMA150_ACC_Y_LSB__POS;
        v_msb_s16 = ((short)(v_data_u8[3] & C_BMA150_ACC_Y_MSB__MSK))<<C_BMA150_ACC_Y_LSB__LEN;
        v_TotalData_s16 = (v_lsb_s16 | v_msb_s16);
        if(v_TotalData_s16 & 0x0200)
        {
            v_TotalData_s16 |=0xFC00;
        }

        p_Acc_xs->v_ay_s16 = v_TotalData_s16;
	
	v_lsb_s16 = ((short)(v_data_u8[4] & C_BMA150_ACC_Z_LSB__MSK))>>C_BMA150_ACC_Z_LSB__POS;
        v_msb_s16 = ((short)(v_data_u8[5] & C_BMA150_ACC_Z_MSB__MSK))<<C_BMA150_ACC_Z_LSB__LEN;
        v_TotalData_s16 = (v_lsb_s16 | v_msb_s16);
        if(v_TotalData_s16 & 0x0200)
        {
            v_TotalData_s16 |=0xFC00;
        }

        p_Acc_xs->v_az_s16 = v_TotalData_s16;
	
	return v_comres_s8;
	
}

/*_________________________________________ Temperature data readout______________________*/
// reads the temperature
// fn parameters: p_Temp_f32: pointer to variable to read tempterature
// fn Return : SUCESS = 0; or FAILURE = -1;
S8 BMA150_READ_TEMPERATURE(F32 * p_Temp_f32)
{
	S8 v_comres_s8;
	unsigned char v_data_u8;
	
	if (P_BMA150_XS==0)
		return -1;
	
	v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, C_BMA150_TEMPERATURE__REG, &v_data_u8,1);
	
	*p_Temp_f32 = (F32)(C_BMA150_ZERO_TEMP) + 0.5 * ((float)v_data_u8);
	
	return v_comres_s8;

}

/*_________________________________________Register Write__________________________________*/
//Write to any register adress
// fn parameters: v_RegAddr_u8  : Use macros for the register adress from BMA150.h file
//				  v_RegValue_u8 : The Value of the bit(s) to be written onto the register
//				  v_BitPos_u8   : The starting position of the desired bit,use macros bitname__POS from BMA150.h
//				  v_BitsMask_u8 : Bit mask, use macros bitname__MSK from BMA150.h
//fn Return : SUCESS = 0; or FAILURE = -1;
S8 BMA150_WRITE_REGISTER(U8 v_RegAddr_u8, U8 v_RegValue_u8, U8 v_BitPos_u8, U8 v_BitsMask_u8)	
{
	S8 v_comres_s8;
	unsigned char v_data_u8;
	
	if (P_BMA150_XS==0)
		return -1;
	
	v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, v_RegAddr_u8, &v_data_u8,1);
	v_data_u8 = (v_data_u8 & (~v_BitsMask_u8)) | ((v_RegValue_u8<<v_BitPos_u8) & v_BitsMask_u8);
	v_comres_s8 += P_BMA150_XS->BMA150_BUS_WRITE_FUNC(P_BMA150_XS->v_DevAdd_u8, v_RegAddr_u8, &v_data_u8, 1 );
	
	return v_comres_s8;
	
}

/*_________________________________________Register Read__________________________________*/
//Read from any register adress
// fn parameters: v_RegAddr_u8  : Use macros for the register adress from BMA150.h file
//				  p_RegValue_u8 : Pointer to the variable where data is read
//				  v_BitPos_u8   : The starting position of the desired bit,use macros bitname__POS from BMA150.h
//				  v_BitsMask_u8 : Bit mask, use macros bitname__MSK from BMA150.h
//fn Return : SUCESS = 0; or FAILURE = -1;
S8 BMA150_READ_REGISTER(U8 v_RegAddr_u8, U8 *p_RegValue_u8, U8 v_BitPos_u8, U8 v_BitsMask_u8)	
{
	S8 v_comres_s8;
	
	if (P_BMA150_XS==0)
		return -1;
	
	v_comres_s8 = P_BMA150_XS->BMA150_BUS_READ_FUNC(P_BMA150_XS->v_DevAdd_u8, v_RegAddr_u8, p_RegValue_u8,1);
	
	*p_RegValue_u8 = (*p_RegValue_u8 & v_BitsMask_u8)>>v_BitPos_u8;
	
	return v_comres_s8;
	
}
