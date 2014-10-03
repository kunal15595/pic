/* 
 * File:   ELB_I2C.h
 * Author: Shashu
 *
 * Created on 28 September, 2012, 10:32 AM
 */

#ifndef ELB_I2C_H
#define	ELB_I2C_H

#include <i2c.h>

#include "Define.h"
//#include "ELB_ConfigOsc.h"

/*** Baud Rate options ***/
#define M_FSCL_FastMode       400000
#define M_FSCL_StandardMode   100000

/*** Read Write Mask ***/
#define M_I2C_Read              0x01		/* I2C Read mask */
#define M_I2C_Write             0x00		/* I2C Write mask */

/**** Interrupt Options ***/
// Master interrupt
#define MI2C_INT_PRI0     0b10000000
#define MI2C_INT_PRI1     0b10010000
#define MI2C_INT_PRI2     0b10100000
#define MI2C_INT_PRI3     0b10110000
#define MI2C_INT_PRI4     0b11000000
#define MI2C_INT_PRI5     0b11010000
#define MI2C_INT_PRI6     0b11100000
#define MI2C_INT_PRI7     0b11110000
// Slave interrupt
#define SI2C_INT_PRI0     0b00001000
#define SI2C_INT_PRI1     0b00001001
#define SI2C_INT_PRI2     0b00001010
#define SI2C_INT_PRI3     0b00001011
#define SI2C_INT_PRI4     0b00001100
#define SI2C_INT_PRI5     0b00001101
#define SI2C_INT_PRI6     0b00001110
#define SI2C_INT_PRI7     0b00001111

/*** Functions ***/
 void I2C1_INIT(S32, U8);
 void I2C2_INIT(S32, U8);
 void I2C3_INIT(S32, U8 );

 S8 I2C1_WRITE_String(U8, U8, U8 *, U8);
 S8 I2C2_WRITE_String(U8, U8, U8 *, U8);
 S8 I2C3_WRITE_String(U8, U8, U8 *, U8);

 S8 I2C1_READ_String( U8, U8, U8 *, U8);
 S8 I2C2_READ_String( U8, U8, U8 *, U8);
 S8 I2C3_READ_String( U8, U8, U8 *, U8);

#define I2C1_WRITE_Byte(DevAdd, RegAdd, RegValue)  I2C1_WRITE_String(DevAdd, RegAdd, RegValue, 1)
#define I2C2_WRITE_Byte(DevAdd, RegAdd, RegValue)  I2C2_WRITE_String(DevAdd, RegAdd, RegValue, 1)
#define I2C3_WRITE_Byte(DevAdd, RegAdd, RegValue)  I2C3_WRITE_String(DevAdd, RegAdd, RegValue, 1)

#define I2C1_READ_Byte(DevAdd, RegAdd, RegValue)  I2C1_READ_String(DevAdd, RegAdd, RegValue, 1)
#define I2C2_READ_Byte(DevAdd, RegAdd, RegValue)  I2C2_READ_String(DevAdd, RegAdd, RegValue, 1)
#define I2C3_READ_Byte(DevAdd, RegAdd, RegValue)  I2C3_READ_String(DevAdd, RegAdd, RegValue, 1)


#endif	/* ELB_I2C_H */

