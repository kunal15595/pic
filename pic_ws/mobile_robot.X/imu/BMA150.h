/*
 * File:   		BMA150.h
 * Created: 	4th August, 2012, 12:26 PM 
 * Author:		gopal.jatiya@brigosha.com 
 * Version      v0.1
 * Comment:		Coding Standard Implemented
 */

#ifndef BMA150_H
#define BMA150_H
 
/*******Include Definitions*****************************/
#include "DEFINE.h"

/*******I2C Specific****************************************/
#define C_BMA150_I2CAdd			0x38


/* defines the return parameter type of the BMA150_WR_FUNCTION

*/
#define M_BMA150_BUS_WR_RETURN_TYPE char

/* defines the calling parameter types of the BMA150_WR_FUNCTION

*/
#define M_BMA150_BUS_WR_PARAM_TYPES unsigned char,unsigned char,unsigned char *,unsigned char

/* links the order of parameters defined in BMA150_BUS_WR_PARAM_TYPE to function calls used inside the API

*/
#define M_BMA150_BUS_WR_PARAM_ORDER device_addr, register_addr, register_v_data_u8, write_length


/* never change this line */
#define BMA150_BUS_WRITE_FUNC(device_addr, register_addr, register_v_data_u8, write_length)\
           bus_write( device_addr, register_addr, register_v_data_u8, write_length )




/* defines the return parameter type of the BMA150_RD_FUNCTION

*/
#define M_BMA150_BUS_RD_RETURN_TYPE char

/* defines the calling parameter types of the BMA150_RD_FUNCTION

*/
#define M_BMA150_BUS_RD_PARAM_TYPES unsigned char, unsigned char, unsigned char *, unsigned char

/*links the order of parameters defined in BMA150_BUS_RD_PARAM_TYPE to function calls used inside the API

*/
#define M_BMA150_BUS_RD_PARAM_ORDER device_addr, register_addr, register_v_data_u8, read_length



/* never change this line */
#define BMA150_BUS_READ_FUNC(device_addr, register_addr, register_v_data_u8, read_length)\
           bus_read( device_addr, register_addr, register_v_data_u8, read_length )
		   
/****** BMA150 Register Adress ****************************/


#define C_BMA150_CHIP_ID_REG		0x00
#define C_BMA150_VERSION_REG		0x01
#define C_BMA150_X_AXIS_LSB_REG		0x02
#define C_BMA150_X_AXIS_MSB_REG		0x03
#define C_BMA150_Y_AXIS_LSB_REG		0x04
#define C_BMA150_Y_AXIS_MSB_REG		0x05
#define C_BMA150_Z_AXIS_LSB_REG		0x06
#define C_BMA150_Z_AXIS_MSB_REG		0x07
#define C_BMA150_TEMP_RD_REG		0x08
#define C_BMA150_STATUS_REG		0x09
#define C_BMA150_CTRL0_REG		0x0A
#define C_BMA150_CTRL1_REG		0x0B
#define C_BMA150_LOW_TH_REG		0x0C
#define C_BMA150_LOW_DUR_REG		0x0D
#define C_BMA150_HIGH_TH_REG		0x0E
#define C_BMA150_HIGH_DUR_REG		0x0F
#define C_BMA150_ANYMOTION_TH_REG	0x10
#define C_BMA150_HYSTERESIS_REG		0x11
#define C_BMA150_CD1_REG		0x12
#define C_BMA150_CD2_REG		0x13
#define C_BMA150_CTRL2_REG		0x14
#define C_BMA150_CTRL3_REG		0x15
#define C_BMA150_GAIN_X_REG		0x16
#define C_BMA150_GAIN_Y_REG		0x17
#define C_BMA150_GAIN_Z_REG		0x18
#define C_BMA150_GAIN_T_REG		0x19
#define C_BMA150_OFFSET_X_REG		0x1A
#define C_BMA150_OFFSET_Y_REG		0x1B
#define C_BMA150_OFFSET_Z_REG		0x1C
#define C_BMA150_OFFSET_T_REG		0x1D
/* register write and read delays */


#define C_BMA150_EE_W_DELAY 28	/* delay after EEP write is 28 msec */

/*********bit slice positions in registers*/

#define C_BMA150_CHIP_ID__POS		0
#define C_BMA150_CHIP_ID__MSK		0x07
#define C_BMA150_CHIP_ID__LEN		3
#define C_BMA150_CHIP_ID__REG		C_BMA150_CHIP_ID_REG


#define C_BMA150_ML_VERSION__POS	0
#define C_BMA150_ML_VERSION__LEN	4
#define C_BMA150_ML_VERSION__MSK	0x0F
#define C_BMA150_ML_VERSION__REG	C_BMA150_VERSION_REG



#define C_BMA150_AL_VERSION__POS  	4
#define C_BMA150_AL_VERSION__LEN  	4
#define C_BMA150_AL_VERSION__MSK	0xF0
#define C_BMA150_AL_VERSION__REG	C_BMA150_VERSION_REG


/* DATA REGISTERS */

#define C_BMA150_NEW_DATA_X__POS  	0
#define C_BMA150_NEW_DATA_X__LEN  	1
#define C_BMA150_NEW_DATA_X__MSK  	0x01
#define C_BMA150_NEW_DATA_X__REG	C_BMA150_X_AXIS_LSB_REG

#define C_BMA150_ACC_X_LSB__POS   	6
#define C_BMA150_ACC_X_LSB__LEN   	2
#define C_BMA150_ACC_X_LSB__MSK		0xC0
#define C_BMA150_ACC_X_LSB__REG		C_BMA150_X_AXIS_LSB_REG

#define C_BMA150_ACC_X_MSB__POS   	0
#define C_BMA150_ACC_X_MSB__LEN   	8
#define C_BMA150_ACC_X_MSB__MSK		0xFF
#define C_BMA150_ACC_X_MSB__REG		C_BMA150_X_AXIS_MSB_REG

#define C_BMA150_NEW_DATA_Y__POS  	0
#define C_BMA150_NEW_DATA_Y__LEN  	1
#define C_BMA150_NEW_DATA_Y__MSK  	0x01
#define C_BMA150_NEW_DATA_Y__REG	C_BMA150_Y_AXIS_LSB_REG

#define C_BMA150_ACC_Y_LSB__POS   	6
#define C_BMA150_ACC_Y_LSB__LEN   	2
#define C_BMA150_ACC_Y_LSB__MSK   	0xC0
#define C_BMA150_ACC_Y_LSB__REG		C_BMA150_Y_AXIS_LSB_REG

#define C_BMA150_ACC_Y_MSB__POS   	0
#define C_BMA150_ACC_Y_MSB__LEN   	8
#define C_BMA150_ACC_Y_MSB__MSK   	0xFF
#define C_BMA150_ACC_Y_MSB__REG		C_BMA150_Y_AXIS_MSB_REG

#define C_BMA150_NEW_DATA_Z__POS  	0
#define C_BMA150_NEW_DATA_Z__LEN  	1
#define C_BMA150_NEW_DATA_Z__MSK	0x01
#define C_BMA150_NEW_DATA_Z__REG	C_BMA150_Z_AXIS_LSB_REG

#define C_BMA150_ACC_Z_LSB__POS   	6
#define C_BMA150_ACC_Z_LSB__LEN   	2
#define C_BMA150_ACC_Z_LSB__MSK		0xC0
#define C_BMA150_ACC_Z_LSB__REG		C_BMA150_Z_AXIS_LSB_REG

#define C_BMA150_ACC_Z_MSB__POS   	0
#define C_BMA150_ACC_Z_MSB__LEN   	8
#define C_BMA150_ACC_Z_MSB__MSK		0xFF
#define C_BMA150_ACC_Z_MSB__REG		C_BMA150_Z_AXIS_MSB_REG

#define C_BMA150_TEMPERATURE__POS 	0
#define C_BMA150_TEMPERATURE__LEN 	8
#define C_BMA150_TEMPERATURE__MSK 	0xFF
#define C_BMA150_TEMPERATURE__REG	C_BMA150_TEMP_RD_REG

/* STATUS BITS */

#define C_BMA150_HG_STATUS__POS		0
#define C_BMA150_HG_STATUS__LEN		1
#define C_BMA150_HG_STATUS__MSK		0x01
#define C_BMA150_HG_STATUS__REG		C_BMA150_STATUS_REG

#define C_BMA150_LG_STATUS__POS		1
#define C_BMA150_LG_STATUS__LEN		1
#define C_BMA150_LG_STATUS__MSK		0x02
#define C_BMA150_LG_STATUS__REG		C_BMA150_STATUS_REG

#define C_BMA150_HG_LATCHED__POS	2
#define C_BMA150_HG_LATCHED__LEN	1
#define C_BMA150_HG_LATCHED__MSK	0x04
#define C_BMA150_HG_LATCHED__REG	C_BMA150_STATUS_REG

#define C_BMA150_LG_LATCHED__POS	3
#define C_BMA150_LG_LATCHED__LEN	1
#define C_BMA150_LG_LATCHED__MSK	0x08
#define C_BMA150_LG_LATCHED__REG	C_BMA150_STATUS_REG

#define C_BMA150_ALERT_PHASE__POS	4
#define C_BMA150_ALERT_PHASE__LEN	1
#define C_BMA150_ALERT_PHASE__MSK	0x10
#define C_BMA150_ALERT_PHASE__REG	C_BMA150_STATUS_REG

#define C_BMA150_STR__POS		7
#define C_BMA150_STR__LEN		1
#define C_BMA150_STR__MSK		0x80
#define C_BMA150_STR__REG		C_BMA150_STATUS_REG


/* CONTROL0 BITS */

#define C_BMA150_SLEEP__POS		0
#define C_BMA150_SLEEP__LEN		1
#define C_BMA150_SLEEP__MSK		0x01
#define C_BMA150_SLEEP__REG		C_BMA150_CTRL0_REG

#define C_BMA150_SOFT_RESET__POS	1
#define C_BMA150_SOFT_RESET__LEN	1
#define C_BMA150_SOFT_RESET__MSK	0x02
#define C_BMA150_SOFT_RESET__REG	C_BMA150_CTRL0_REG

#define C_BMA150_ST0__POS		2
#define C_BMA150_ST0__LEN		1
#define C_BMA150_ST0__MSK		0x04
#define C_BMA150_ST0__REG		C_BMA150_CTRL0_REG

#define C_BMA150_ST1__POS		3
#define C_BMA150_ST1__LEN		1
#define C_BMA150_ST1__MSK		0x08
#define C_BMA150_ST1__REG		C_BMA150_CTRL0_REG

#define C_BMA150_EE_W__POS		4
#define C_BMA150_EE_W__LEN		1
#define C_BMA150_EE_W__MSK		0x10
#define C_BMA150_EE_W__REG		C_BMA150_CTRL0_REG

#define C_BMA150_UPDATE_IMAGE__POS	5
#define C_BMA150_UPDATE_IMAGE__LEN	1
#define C_BMA150_UPDATE_IMAGE__MSK	0x20
#define C_BMA150_UPDATE_IMAGE__REG	C_BMA150_CTRL0_REG

#define C_BMA150_RESET_INT__POS		6
#define C_BMA150_RESET_INT__LEN		1
#define C_BMA150_RESET_INT__MSK		0x40
#define C_BMA150_RESET_INT__REG		C_BMA150_CTRL0_REG

/* CONTROL1 BITS */

#define C_BMA150_ENABLE_LG__POS		0
#define C_BMA150_ENABLE_LG__LEN		1
#define C_BMA150_ENABLE_LG__MSK		0x01
#define C_BMA150_ENABLE_LG__REG		C_BMA150_CTRL1_REG

#define C_BMA150_ENABLE_HG__POS		1
#define C_BMA150_ENABLE_HG__LEN		1
#define C_BMA150_ENABLE_HG__MSK		0x02
#define C_BMA150_ENABLE_HG__REG		C_BMA150_CTRL1_REG

#define C_BMA150_COUNTER_LG__POS	2
#define C_BMA150_COUNTER_LG__LEN	2
#define C_BMA150_COUNTER_LG__MSK	0x0C
#define C_BMA150_COUNTER_LG__REG	C_BMA150_CTRL1_REG

#define C_BMA150_COUNTER_HG__POS	4
#define C_BMA150_COUNTER_HG__LEN	2
#define C_BMA150_COUNTER_HG__MSK	0x30
#define C_BMA150_COUNTER_HG__REG	C_BMA150_CTRL1_REG

#define C_BMA150_ANYMOTION__POS		6
#define C_BMA150_ANYMOTION__LEN		1
#define C_BMA150_ANYMOTION__MSK		0x40
#define C_BMA150_ANYMOTION__REG		C_BMA150_CTRL1_REG


#define C_BMA150_ALERT__POS		7
#define C_BMA150_ALERT__LEN		1
#define C_BMA150_ALERT__MSK		0x80
#define C_BMA150_ALERT__REG		C_BMA150_CTRL1_REG

/* LOW G THRESHOLD */

#define C_BMA150_LG_TH__POS		0
#define C_BMA150_LG_TH__LEN		8
#define C_BMA150_LG_TH__MSK		0xFF
#define C_BMA150_LG_TH__REG		C_BMA150_LOW_TH_REG

/* LOW G DURATION */

#define C_BMA150_LG_DUR__POS		0
#define C_BMA150_LG_DUR__LEN		8
#define C_BMA150_LG_DUR__MSK		0xFF
#define C_BMA150_LG_DUR__REG		C_BMA150_LOW_DUR_REG


/* HIGH G THRESHOLD */

#define C_BMA150_HG_TH__POS		0
#define C_BMA150_HG_TH__LEN		8
#define C_BMA150_HG_TH__MSK		0xFF
#define C_BMA150_HG_TH__REG		C_BMA150_HIGH_TH_REG


/* HIGH G DURATION */

#define C_BMA150_HG_DUR__POS		0
#define C_BMA150_HG_DUR__LEN		8
#define C_BMA150_HG_DUR__MSK		0xFF
#define C_BMA150_HG_DUR__REG		C_BMA150_HIGH_DUR_REG

/* ANY MOTION THRESHOLD */

#define C_BMA150_ANYMOTION_TH__POS	0
#define C_BMA150_ANYMOTION_TH__LEN	8
#define C_BMA150_ANYMOTION_TH__MSK	0xFF
#define C_BMA150_ANYMOTION_TH__REG	C_BMA150_ANYMOTION_TH_REG

/* HYSTERISIS AND ANY MOTION DUR BITS */

#define C_BMA150_LG_HYST__POS		0
#define C_BMA150_LG_HYST__LEN	 	3
#define C_BMA150_LG_HYST__MSK	 	0x07
#define C_BMA150_LG_HYST__REG		C_BMA150_HYSTERESIS_REG

#define C_BMA150_HG_HYST__POS		3
#define C_BMA150_HG_HYST__LEN	 	3
#define C_BMA150_HG_HYST__MSK	 	0x38
#define C_BMA150_HG_HYST__REG		C_BMA150_HYSTERESIS_REG

#define C_BMA150_ANYMOTION_DUR__POS		6
#define C_BMA150_ANYMOTION_DUR__LEN	 	2
#define C_BMA150_ANYMOTION_DUR__MSK	 	0xC0
#define C_BMA150_ANYMOTION_DUR__REG		C_BMA150_HYSTERESIS_REG

/* CUSTOMER DATA1 BITS */

#define C_BMA150_CD1__POS			0
#define C_BMA150_CD1__LEN			8
#define C_BMA150_CD1__MSK			0xFF
#define C_BMA150_CD1__REG			C_BMA150_CD1_REG

/* CUSTOMER DATA2 BITS */

#define C_BMA150_CD2__POS			0
#define C_BMA150_CD2__LEN			8
#define C_BMA150_CD2__MSK			0xFF
#define C_BMA150_CD2__REG			C_BMA150_CD2_REG

/* BANDWIDTH AND RANGE BITS */

#define C_BMA150_BW__POS	0
#define C_BMA150_BW__LEN	3
#define C_BMA150_BW__MSK	0x07
#define C_BMA150_BW__REG	C_BMA150_CTRL2_REG

#define C_BMA150_RANGE__POS	3
#define C_BMA150_RANGE__LEN	2
#define C_BMA150_RANGE__MSK	0x18
#define C_BMA150_RANGE__REG	C_BMA150_CTRL2_REG

/* CONTROL3 BITS */

#define C_BMA150_WAKE_UP__POS		0
#define C_BMA150_WAKE_UP__LEN		1
#define C_BMA150_WAKE_UP__MSK		0x01
#define C_BMA150_WAKE_UP__REG		C_BMA150_CTRL3_REG

#define C_BMA150_WAKE_UP_PAUSE__POS		1
#define C_BMA150_WAKE_UP_PAUSE__LEN		2
#define C_BMA150_WAKE_UP_PAUSE__MSK		0x06
#define C_BMA150_WAKE_UP_PAUSE__REG		C_BMA150_CTRL3_REG

#define C_BMA150_SHADOW_DIS__POS		3
#define C_BMA150_SHADOW_DIS__LEN		1
#define C_BMA150_SHADOW_DIS__MSK		0x08
#define C_BMA150_SHADOW_DIS__REG		C_BMA150_CTRL3_REG

#define C_BMA150_LATCH_INT__POS		4
#define C_BMA150_LATCH_INT__LEN		1
#define C_BMA150_LATCH_INT__MSK		0x10
#define C_BMA150_LATCH_INT__REG		C_BMA150_CTRL3_REG

#define C_BMA150_NEWDATA_INT__POS		5
#define C_BMA150_NEWDATA_INT__LEN		1
#define C_BMA150_NEWDATA_INT__MSK		0x20
#define C_BMA150_NEWDATA_INT__REG		C_BMA150_CTRL3_REG

#define C_BMA150_ENABLE_ADV_INT__POS		6
#define C_BMA150_ENABLE_ADV_INT__LEN		1
#define C_BMA150_ENABLE_ADV_INT__MSK		0x40
#define C_BMA150_ENABLE_ADV_INT__REG		C_BMA150_CTRL3_REG

#define C_BMA150_SPI4__POS		7
#define C_BMA150_SPI4__LEN		1
#define C_BMA150_SPI4__MSK		0x80
#define C_BMA150_SPI4__REG		C_BMA150_CTRL3_REG

/* GAIN X REGISTER*/
#define C_BMA150_GAIN_X__POS		0
#define C_BMA150_GAIN_X__LEN	 	6
#define C_BMA150_GAIN_X__MSK		0x3F
#define C_BMA150_GAIN_X__REG		C_BMA150_GAIN_X_REG

#define C_BMA150_OFFSET_X_LSB__POS		6
#define C_BMA150_OFFSET_X_LSB__LEN	 	2
#define C_BMA150_OFFSET_X_LSB__MSK		0xC0
#define C_BMA150_OFFSET_X_LSB__REG		C_BMA150_GAIN_X_REG

/* GAIN Y REGISTER*/
#define C_BMA150_GAIN_Y__POS		0
#define C_BMA150_GAIN_Y__LEN	 	6
#define C_BMA150_GAIN_Y__MSK		0x3F
#define C_BMA150_GAIN_Y__REG		C_BMA150_GAIN_Y_REG

#define C_BMA150_OFFSET_Y_LSB__POS		6
#define C_BMA150_OFFSET_Y_LSB__LEN	 	2
#define C_BMA150_OFFSET_Y_LSB__MSK		0xC0
#define C_BMA150_OFFSET_Y_LSB__REG		C_BMA150_GAIN_Y_REG

/* GAIN Z REGISTER*/
#define C_BMA150_GAIN_Z__POS		0
#define C_BMA150_GAIN_Z__LEN	 	6
#define C_BMA150_GAIN_Z__MSK		0x3F
#define C_BMA150_GAIN_Z__REG		C_BMA150_GAIN_Z_REG

#define C_BMA150_OFFSET_Z_LSB__POS		6
#define C_BMA150_OFFSET_Z_LSB__LEN	 	2
#define C_BMA150_OFFSET_Z_LSB__MSK		0xC0
#define C_BMA150_OFFSET_Z_LSB__REG		C_BMA150_GAIN_Z_REG

/* GAIN T REGISTER*/
#define C_BMA150_GAIN_T__POS		0
#define C_BMA150_GAIN_T__LEN	 	6
#define C_BMA150_GAIN_T__MSK		0x3F
#define C_BMA150_GAIN_T__REG		C_BMA150_GAIN_T_REG

#define C_BMA150_OFFSET_T_LSB__POS		6
#define C_BMA150_OFFSET_T_LSB__LEN	 	2
#define C_BMA150_OFFSET_T_LSB__MSK		0xC0
#define C_BMA150_OFFSET_T_LSB__REG		C_BMA150_GAIN_T_REG

/* OFFSET */

#define C_BMA150_OFFSET_X_MSB__POS	0
#define C_BMA150_OFFSET_X_MSB__LEN 	8
#define C_BMA150_OFFSET_X_MSB__MSK	0xFF
#define C_BMA150_OFFSET_X_MSB__REG	C_BMA150_OFFSET_X_REG

#define C_BMA150_OFFSET_Y_MSB__POS	0
#define C_BMA150_OFFSET_Y_MSB__LEN 	8
#define C_BMA150_OFFSET_Y_MSB__MSK	0xFF
#define C_BMA150_OFFSET_Y_MSB__REG	C_BMA150_OFFSET_Y_REG

#define C_BMA150_OFFSET_Z_MSB__POS	0
#define C_BMA150_OFFSET_Z_MSB__LEN 	8
#define C_BMA150_OFFSET_Z_MSB__MSK	0xFF
#define C_BMA150_OFFSET_Z_MSB__REG	C_BMA150_OFFSET_Z_REG

#define C_BMA150_OFFSET_T_MSB__POS	0
#define C_BMA150_OFFSET_T_MSB__LEN 	8
#define C_BMA150_OFFSET_T_MSB__MSK	0xFF
#define C_BMA150_OFFSET_T_MSB__REG	C_BMA150_OFFSET_T_REG


#define BMA150_GET_BITSLICE(regvar, bitname)\
			(regvar & bitname##__MSK) >> bitname##__POS


#define BMA150_SET_BITSLICE(regvar, bitname, val)\
		  (regvar & ~bitname##__MSK) | ((val<<bitname##__POS)&bitname##__MSK)  


/** \endcond */


/* CONSTANTS */


/* range and bandwidth */

#define C_BMA150_RANGE_2G			0 /**< sets range to 2G mode \see BMA150_set_range() */
#define C_BMA150_RANGE_4G		1 /**< sets range to 4G mode \see BMA150_set_range() */
#define C_BMA150_RANGE_8G			2 /**< sets range to 8G mode \see BMA150_set_range() */

#define C_BMA150_BW_25HZ		0	/**< sets bandwidth to LowPass 25HZ \see BMA150_set_bandwidth() */
#define C_BMA150_BW_50HZ		1	/**< sets bandwidth to LowPass 50HZ \see BMA150_set_bandwidth() */
#define C_BMA150_BW_100HZ		2	/**< sets bandwidth to LowPass 100HZ \see BMA150_set_bandwidth() */
#define C_BMA150_BW_190HZ		3	/**< sets bandwidth to LowPass 190HZ \see BMA150_set_bandwidth() */
#define C_BMA150_BW_375HZ		4	/**< sets bandwidth to LowPass 375HZ \see BMA150_set_bandwidth() */
#define C_BMA150_BW_750HZ		5	/**< sets bandwidth to LowPass 750HZ \see BMA150_set_bandwidth() */
#define C_BMA150_BW_1500HZ		6	/**< sets bandwidth to LowPass 1500HZ \see BMA150_set_bandwidth() */

/* mode settings */

#define C_BMA150_MODE_NORMAL      0
#define C_BMA150_MODE_SLEEP       1
#define C_BMA150_MODE_WAKE_UP     2

/* wake up */

#define C_BMA150_WAKE_UP_DUR_20MS		0
#define C_BMA150_WAKE_UP_DUR_80MS		1
#define C_BMA150_WAKE_UP_DUR_320MS		2
#define C_BMA150_WAKE_UP_DUR_2560MS		3

#define C_BMA150_ZERO_TEMP 	-30
/* LG/HG thresholds are in LSB and depend on RANGE setting */
/* no range check on threshold calculation */

#define C_BMA150_SELF_TEST0_ON		1
#define C_BMA150_SELF_TEST1_ON		2

#define C_BMA150_EE_W_OFF			0
#define C_BMA150_EE_W_ON			1


typedef struct  {
		/**< holds x-axis acceleration data sign extended. Range -512 to 511.*/
                short v_ax_s16,
                      /**< holds y-axis acceleration data sign extended. Range -512 to 511.*/
                      v_ay_s16,
                      /**< holds z-axis acceleration data sign extended. Range -512 to 511.*/
                      v_az_s16; 
} ts_AccData;

/* BMA150 typedef structure
	This structure holds all relevant information about BMA150 
*/

typedef struct {	

        /**< save BMA150's chip id which has to be 0x02 after calling BMA150_INIT() */
	unsigned char v_chipID_u8,
                      /**< holds the BMA150 ML_version number */
                      v_mlVersion_u8,
                      /**< holds the BMA150 AL_version number */
                      v_alVersion_u8,
                      /**< Power Mode info of BMA150*/
                      v_mode_u8,
                      /**< initializes BMA150's I2C device address*/
                      v_DevAdd_u8;
        /**< I2C write function pointer*/
	M_BMA150_BUS_WR_RETURN_TYPE (*bus_write)(M_BMA150_BUS_WR_PARAM_TYPES);
        /**< I2C read function pointer*/
	M_BMA150_BUS_RD_RETURN_TYPE (*bus_read)(M_BMA150_BUS_RD_PARAM_TYPES); 
} ts_bma150;

/* Function prototypes */

S8 BMA150_INIT(ts_bma150 *);

S8 BMA150_SET_EE_W(unsigned char);

S8 BMA150_SET_RANGE(char);

S8 BMA150_GET_RANGE(unsigned char *);

S8 BMA150_SET_MODE(unsigned char);

S8 BMA150_SET_BANDWIDTH(unsigned char);

S8 BMA150_GET_BANDWIDTH(unsigned char *);

S8 BMA150_READ_ACCEL_XYZ(ts_AccData *);

S8 BMA150_READ_TEMPERATURE(F32 *);

S8 BMA150_WRITE_REGISTER(U8 ,U8 , U8, U8);

S8 BMA150_READ_REGISTER(U8 ,U8 *,U8 ,U8);

#endif  // End of Header file BMA150.h
