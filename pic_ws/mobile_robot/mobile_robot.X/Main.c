#include "AVIX.h"

//#include "Define.h"
//#include "CONFIGbits.h"
#include "ELBv21_HardwareConfig.h"


//Module wise includes
#include "master.h"
#include "astar_thread.h"


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



//	===============================================================================================
//	FUNCTION:	avixMain
//	====================
//	Main function for AVIX based project. From here specific selected tutorial function is called.
//	===============================================================================================
//
int astar_test_main();


void avixMain(void)
{
     //---------------------------------------------------------------------------------------------
     // Setup the system and install an AVIX central error handler.
     //---------------------------------------------------------------------------------------------
     systemSetup();
     avixError_SetHandler(myErrorFunc);
     LED2_DIR = DIR_OUT;
     LED3_DIR = DIR_OUT;
     avixExch_Create("global_storage", sizeof(struct global_storage), NULL);
     avixThread_Create("master_thread", master_thread, NULL, 1,500L, AVIX_THREAD_READY);
     avixThread_Create("astar_thread", astar_thread, NULL, 1, 500, AVIX_THREAD_READY);
}
