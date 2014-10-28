
#include "AMGPsensor.h"

ts_bma150 S_BMA150_XS;                  /**< Object of the Sensor BMA150 */
ts_AccData S_AccData_XS;                /**< Object for Tri-axial Acceleration Data Structure*/
F32 V_AccLSBtoMG_F32=2000.0/511.0;      /**< Acc unit conversion factor and scale factor*/
U8 V_AccelScale_U8=16;

ts_hmc5883 S_HMC5883_XS;                /**< Object of the Sensor HMC5883*/
ts_hmc5883_mdata S_MagData_XS;          /**< Object for the Tri-axial Magnetometer Data Structure*/
F32 V_MagLSBtoUT_F32=100.0/1090.0;      /**< Mag unit conversion factor and scale factor*/
U8 V_MagScale_U8=252;

ts_itg3050 S_ITG3050_XS;                /**< Object of the Sensor ITG3050*/
ts_GyroData S_GyroData_XS;              /**< Object for the Tri-axial Magnetometer Data Structure*/
F32 V_GyroLSBtoDegPS_F32=2000.0/32767.0;/**< Gyroscope unit conversion factor and scale factor*/
U8 V_GyroScale_U8=16;

ts_bmp085 S_BMP085_XS;                  /**< Object of the sensor BMP085*/
S32 V_Pressure_S32;                     /**< Variable to store pressure and temperature*/
S16 V_Temperature_S16;


ts_AMGPsensor AMGP;


void ConfigSensors(U8 v_Sensors_U8)
{
    /** Local variables ***/
    S8 v_ComRes_S8=0;

    if(v_Sensors_U8&Acc)
    {
        v_ComRes_S8 = BMA150_INIT(&S_BMA150_XS);
        v_ComRes_S8 = BMA150_SET_MODE(C_BMA150_MODE_NORMAL);
        v_ComRes_S8 = BMA150_SET_RANGE(C_BMA150_RANGE_2G);
        v_ComRes_S8 = BMA150_SET_BANDWIDTH(C_BMA150_BW_25HZ);
    }
    if(v_Sensors_U8&Mag)
    {
        v_ComRes_S8 = HMC5883_INIT(&S_HMC5883_XS);
        v_ComRes_S8 = HMC5883_SET_Measurement_Mode(C_HMC5883_NORMAL_MEASURE_MODE);
        v_ComRes_S8 = HMC5883_SET_OperationMode(C_HMC5883_CONTINUOUS_MEASUREMENT_MODE);
        v_ComRes_S8 = HMC5883_SET_DataRate(C_HMC5883_DATA_RATE_15_HZ);
        v_ComRes_S8 = HMC5883_SET_No_Samples(C_HMC5883_NO_SAMPLES_4);
        v_ComRes_S8 = HMC5883_SET_Gain(C_HMC5883_GAIN_1_3_GA);
    }
    if(v_Sensors_U8&Gyro)
    {
        v_ComRes_S8 = ITG3050_INIT(&S_ITG3050_XS );
        v_ComRes_S8 = ITG3050_SET_Range(C_ITG3050_Range_2000degps);
        v_ComRes_S8 = ITG3050_SET_BW(C_ITG3050_Bandwidth_256Hz);
        v_ComRes_S8 = ITG3050_SET_SampleRate(7);
    }
    if(v_Sensors_U8&Pres)
    {
        v_ComRes_S8 = BMP085_INIT(&S_BMP085_XS);
    }
    
}

void ReadSensors(U8 v_Sensors_U8)
{
    S8 v_ComRes_S8 = 0;
    if(v_Sensors_U8&Acc)
    {
        BMA150_READ_ACCEL_XYZ(&S_AccData_XS);
        AMGP.Data.AccX = S_AccData_XS.v_ax_s16;
        AMGP.Data.AccY = S_AccData_XS.v_ay_s16;
        AMGP.Data.AccZ = S_AccData_XS.v_az_s16;
    }
    if(v_Sensors_U8&Mag)
    {
        HMC5883_GET_MData_xyz(&S_MagData_XS);
        AMGP.Data.MagX = S_MagData_XS.v_DataX_s16;
        AMGP.Data.MagY = S_MagData_XS.v_DataY_s16;
        AMGP.Data.MagZ = S_MagData_XS.v_DataZ_s16;
    }
    if(v_Sensors_U8&Gyro)
    {
        ITG3050_GET_ANGULARVELOCITY(&S_GyroData_XS);
        AMGP.Data.GyroX = S_GyroData_XS.v_Wx_s16;
        AMGP.Data.GyroY = S_GyroData_XS.v_Wy_s16;
        AMGP.Data.GyroZ = S_GyroData_XS.v_Wz_s16;
    }
    if(v_Sensors_U8&Pres)
    {
        v_ComRes_S8 = BMP085_GET_Pressure_Teperature(&V_Pressure_S32,&V_Temperature_S16);
        if(v_ComRes_S8==1)
        {
            AMGP.Data.Pressure = V_Pressure_S32;
            AMGP.Data.PresTemp = V_Temperature_S16;
        }
    }
}

void AMGP_INIT(U8 v_header_U8 , U8 v_SerialPort_U8)
{   
    if(v_header_U8==0x01)
    {
        //Assign sensor communication function with Current hardware I2C function
        S_BMA150_XS.bus_read = I2C1_READ_String;
        S_BMA150_XS.bus_write = I2C1_WRITE_String;

        S_HMC5883_XS.bus_read = I2C1_READ_String;
        S_HMC5883_XS.bus_write = I2C1_WRITE_String;

        S_ITG3050_XS.bus_read = I2C1_READ_String;
        S_ITG3050_XS.bus_write = I2C1_WRITE_String;

        S_BMP085_XS.bus_read = I2C1_READ_String;
        S_BMP085_XS.bus_write = I2C1_WRITE_String;
    }
    if(v_header_U8==0x02)
    {
        //Assign sensor communication function with Current hardware I2C function
        S_BMA150_XS.bus_read = I2C2_READ_String;
        S_BMA150_XS.bus_write = I2C2_WRITE_String;

        S_HMC5883_XS.bus_read = I2C2_READ_String;
        S_HMC5883_XS.bus_write = I2C2_WRITE_String;

        S_ITG3050_XS.bus_read = I2C2_READ_String;
        S_ITG3050_XS.bus_write = I2C2_WRITE_String;

        S_BMP085_XS.bus_read = I2C2_READ_String;
        S_BMP085_XS.bus_write = I2C2_WRITE_String;
    }   

    /*** Assign the serial port to Send the data ***/
//    if(v_SerialPort_U8==0x01)
//    {
//
//        //xyzh = UART1_SEND_String;
//    }
//    if(v_SerialPort_U8==0x02)
//    {
//        //Assign sensor communication function with Current hardware I2C function
//       // xyzh = UART2_SEND_String;
//    }

    AMGP.Config = ConfigSensors;
    AMGP.Read = ReadSensors;
    AMGP.Send = SendDataPacket;
  
    

}

void SendDataPacket(U8 v_Content_u8)
{
        /*** Scaling constants ***/
    U8 v_AccelScale_U8 = 1;			// Note: Enter scaling factor when accel value in mg
    U8 v_GyroScale_U8 =  1;       	// Note: Enter scaling factor when gyro value in deg/sec
    U8 v_MagScale_u8 =   1;
    /*** LSB to SI conversion factor ***/
    F32 v_AccLSBtoMG_f32 = 1 ;
    F32 v_MagLSBtoUT_f32 = 1;
    F32 v_GyroLSBtoDegSec_f32 = 1;
    /*** Dummy variable to store the Scaled up Values ***/
    S16 v_SendData_S16 =0;
    static U8 V_PacketNumber_U8=0;
    static U8 V_NoOfBytes_U8 =0;
    U8 A_SendData_U8[30]={0};
    S32 v_Pressure_S32=0;
    /*** Data Packet Header ***/

    A_SendData_U8[0] = V_PacketNumber_U8;   //Packet Number
    A_SendData_U8[1] = 0x01;                //Packet Type. 0x01 means raw data
    A_SendData_U8[2] = v_Content_u8;        //Packet Content
    V_NoOfBytes_U8 = 3;                     //No of bytes so far
    V_PacketNumber_U8++;
    /* Accel Data*/
    if(v_Content_u8 & Acc)
    {
         v_SendData_S16 = (AMGP.Data.AccX)*v_AccLSBtoMG_f32*v_AccelScale_U8;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16>>8);        V_NoOfBytes_U8++;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16 & 0x00FF);  V_NoOfBytes_U8++;

        v_SendData_S16 = (AMGP.Data.AccY)*v_AccLSBtoMG_f32*v_AccelScale_U8;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16>>8);        V_NoOfBytes_U8++;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16 & 0x00FF);  V_NoOfBytes_U8++;

        v_SendData_S16 = (AMGP.Data.AccZ)*v_AccLSBtoMG_f32*v_AccelScale_U8;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16>>8);        V_NoOfBytes_U8++;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16 & 0x00FF);  V_NoOfBytes_U8++;
    }

    /*Mag Data*/
    if(v_Content_u8 & Mag)
    {
        v_SendData_S16 = (AMGP.Data.MagX)*v_MagLSBtoUT_f32*v_MagScale_u8;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16>>8);        V_NoOfBytes_U8++;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16 & 0x00FF);  V_NoOfBytes_U8++;

        v_SendData_S16 = (AMGP.Data.MagY)*v_MagLSBtoUT_f32*v_MagScale_u8;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16>>8);        V_NoOfBytes_U8++;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16 & 0x00FF);  V_NoOfBytes_U8++;

        v_SendData_S16 = (AMGP.Data.MagZ)*v_MagLSBtoUT_f32*v_MagScale_u8;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16>>8);        V_NoOfBytes_U8++;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16 & 0x00FF);  V_NoOfBytes_U8++;
    }

     /*Gyro Data*/
    if(v_Content_u8 & Gyro)
    {
        v_SendData_S16 = (AMGP.Data.GyroX)*v_GyroLSBtoDegSec_f32*v_GyroScale_U8;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16>>8);        V_NoOfBytes_U8++;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16 & 0x00FF);  V_NoOfBytes_U8++;

        v_SendData_S16 = (AMGP.Data.GyroY)*v_GyroLSBtoDegSec_f32*v_GyroScale_U8;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16>>8);        V_NoOfBytes_U8++;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16 & 0x00FF);  V_NoOfBytes_U8++;

        v_SendData_S16 = (AMGP.Data.GyroZ)*v_GyroLSBtoDegSec_f32*v_GyroScale_U8;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16>>8);        V_NoOfBytes_U8++;
        A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16 & 0x00FF);  V_NoOfBytes_U8++;
    }

    /*** Pressure Data ***/
	if (v_Content_u8 & Pres)
	{
            v_Pressure_S32 = AMGP.Data.Pressure;
            A_SendData_U8[V_NoOfBytes_U8] = (U8)( v_Pressure_S32>>16);              V_NoOfBytes_U8++;
            A_SendData_U8[V_NoOfBytes_U8] = (U8)((v_Pressure_S32 & 0x0000FF00)>>8); V_NoOfBytes_U8++;
            A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_Pressure_S32 & 0x000000FF);      V_NoOfBytes_U8++;
	}
    /*** PRESSURE SENSOR TEMPERATURE ***/
    	if (v_Content_u8 & TempPres)
	{
            v_SendData_S16 = AMGP.Data.PresTemp;
            A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16>>8);        V_NoOfBytes_U8++;
            A_SendData_U8[V_NoOfBytes_U8] = (U8)(v_SendData_S16 & 0x00FF);  V_NoOfBytes_U8++;
        }
    /*** SEND DATA FROM SERIAL PORT ***/
    SendSerialData(A_SendData_U8,V_NoOfBytes_U8 );
}
