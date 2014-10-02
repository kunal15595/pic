
#ifndef AMGPSENSOR_H
#define	AMGPSENSOR_H

#include "BMA150.h"
#include "HMC5883.h"
#include "ITG3050.h"
#include "BMP085.h"

#include "ELB_I2C.h"
#include "ELB_UART.h"

#define Acc  0x01
#define Mag  0x02
#define Gyro 0x04
#define Pres 0x08
#define TempPres 0x80

#define READ_HEADER1 0x01
#define READ_HEADER2 0x02

#define SEND_UART1USB  0x01
#define SEND_UART2DB9  0x02
#define SEND_UART2XBEE 0x02

#define SendSerialData(x, y )     UART1_SEND_String(x,y)

void AMGP_INIT(U8, U8);
void SendDataPacket(U8 );

typedef struct
{
    S16 AccX, AccY, AccZ;
    F32 AccTemp;
    S16 MagX, MagY, MagZ;
    F32 MagTemp;
    S16 GyroX, GyroY, GyroZ;
    F32 GyroTemp;
    S32 Pressure;
    S16 PresTemp;
}ts_AMGPdata ;

typedef struct
{
    void (* Config)(U8);
    void (* Read)(U8);
    void (* Send)(U8);
    ts_AMGPdata   Data;
}ts_AMGPsensor;

#endif	/* AMGPSENSOR_H */

