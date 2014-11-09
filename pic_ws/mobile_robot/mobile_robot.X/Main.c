#include "AVIX.h"

//#include "Define.h"
//#include "CONFIGbits.h"
#include "ELBv21_HardwareConfig.h"
#include "ELB_LCD.h"

//Module wise includes
#include "master.h"
#include "astar_thread.h"
#include "ping.h"
#include "servo.h"
#include "imu.h"
#include "xbee.h"
#include "motor.h"
#include "std_int.h"
#include <stdbool.h>

//
#include "ELB_OSC.h"
#include "ELB_PWM.h"


//Global variables
bool path_found;
struct coordinate current_pos,next_pos,dest_pos;

//	-----------------------------------------------------------------------------------------------
//	External function declarations.
//	-----------------------------------------------------------------------------------------------
extern void systemSetup(void);


//	===============================================================================================
//	FUNCTION:	myErrorFunc
//	=======================
//	Central AVIX error handler. Set breakpoint at while loop to catch errors in development
//	environment
//	===============================================================================================
//
void myErrorFunc(tavixErrorCode errorCode)
{
    printf("%d\n",errorCode);
	while(1);
}

void peripherals_setup(){
//    TIMER2_INIT( 1000, TMR_INT_PRI2 );
    ConfigPins_PWM(USE1 | USE3);
    T2CONbits.TCKPS = 01;
    T2CON = 0x8000;
    LCD_INIT();
    LED2_DIR = DIR_OUT;
    LED3_DIR = DIR_OUT;
    ConfigPins_UART1();
    ConfigPins_UART2();
    UART1_INIT(M_9600Hz, M_BRGH_High, RX_INT_PRI1); //Initialise UART1
    UART2_INIT(M_9600Hz, M_BRGH_High, RX_INT_PRI2);

    __builtin_write_OSCCONL(OSCCON & 0xbf);
//    iPPSInput(IN_FN_PPS_IC2, IN_PIN_PPS_RP10);
    iPPSInput(IN_FN_PPS_IC1, IN_PIN_PPS_RP22);
//
    iPPSOutput(OUT_PIN_PPS_RP12, OUT_FN_PPS_OC1);
    iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_OC9);
//
    __builtin_write_OSCCONL(OSCCON | 0x40);

    unsigned int config1;
    unsigned int config2;

    // input capture
    ConfigIntCapture1(IC_INT_ON | IC_INT_PRIOR_2);
    ConfigIntCapture2(IC_INT_ON | IC_INT_PRIOR_3);

    config1 = IC_IDLE_STOP | IC_TIMER2_SRC | IC_INT_1CAPTURE | IC_EVERY_EDGE;
    config2 = IC_CASCADE_DISABLE /*| IC_SYNC_ENABLE | IC_SYNC_TRIG_IN_TMR2*/;
    OpenCapture1_GB(config1, config2);
//    config1 = IC_IDLE_STOP | IC_TIMER2_SRC | IC_INT_1CAPTURE | IC_EVERY_FALL_EDGE;
//    config2 = IC_CASCADE_DISABLE /*| IC_SYNC_ENABLE | IC_SYNC_TRIG_IN_TMR2*/;
//    OpenCapture2_GB(config1, config2);

    PWM1_INIT(PWMsrc_FOSC, 20);

}


//	===============================================================================================
//	FUNCTION:	avixMain
//	====================
//	Main function for AVIX based project. From here specific selected tutorial function is called.
//	===============================================================================================
//


void avixMain(void)
{
     //---------------------------------------------------------------------------------------------
     // Setup the system and install an AVIX central error handler.
     //---------------------------------------------------------------------------------------------
     systemSetup();
     avixError_SetHandler(myErrorFunc);
     peripherals_setup();
//  LCD_INIT();
     
///////////////////////////////////////
     path_found=false;
     current_pos.x=0;
     current_pos.y=0;
     next_pos.x=0;
     next_pos.y=0;
     dest_pos.x=9;
     dest_pos.y=9;
//////////////////////////////////////////////
     avixThread_Create("master_thread", master_thread, NULL, 1,500, AVIX_THREAD_READY);
     avixThread_Create("imu_thread", imu_thread, NULL, 1,500, AVIX_THREAD_READY);
     avixThread_Create("motor_thread", motor_thread, NULL, 1,500, AVIX_THREAD_READY);
     avixThread_Create("servo_thread", servo_thread, NULL, 1,500, AVIX_THREAD_READY);
     avixThread_Create("xbee_thread", xbee_thread, NULL, 1,500, AVIX_THREAD_READY);
//     avixThread_Create("ping_thread", ping_thread, NULL, 1,500, AVIX_THREAD_READY);

}

