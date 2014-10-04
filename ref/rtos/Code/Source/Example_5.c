/*--------------------------------------------------------------------

  Title       : Byte Read/Write Demo 
  Filename    : Example_5.c     

Uncomment this line at the top of 'multitask.s' file to add support for this device. 

        .equiv NO_PSV_PAGE,1
    
--------------------------------------------------------------------*/

/*--- Using a PIC24HJ256DA210 ---*/

#include "multitask.h" 

/*--- Configuration fuses---*/

_CONFIG1(WDTPS_PS32768 & FWPSA_PR128 & ALTVREF_ALTVREDIS & WINDIS_OFF & FWDTEN_OFF & ICS_PGx1 & GWRP_OFF & GCP_OFF & JTAGEN_OFF) 
_CONFIG2(POSCMOD_HS & IOL1WAY_OFF & OSCIOFNC_OFF & OSCIOFNC_OFF & FCKSM_CSDCMD & FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2 & IESO_OFF)
_CONFIG3(WPFP_WPFP255 & SOSCSEL_SOSC & WUTSEL_LEG & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM) 

/*--- Trace maximum stack usage ---*/  

#ifdef __DEBUG
#define NUM_TASKS 3U
uint16_t UsedStack[NUM_TASKS]; 
#endif

/*--- Task function prototypes ---*/

void task_0(void);
void task_1(void);
void task_2(void);

/*--- Local function prototypes ---*/

void init_io(void);
void InitTimer_2(void);
void Delay(uint16_t delay);

/*--- Structure of circular buffer indexes ---*/

typedef struct
  {
  uint8_t Data;
  uint8_t count;
  }INDEX;

volatile INDEX Index;
uint8_t data[8]; 

/*--- Stack pointer ---*/

volatile uint8_t StkPtr;
uint8_t buffer[8];  

/*--- Message names ---*/

enum{STACK, BUFFER};

#define STACKSIZE   8
#define BUFFERSIZE  12 

/*--- Program Entry ---*/

int main(void)
  {
  init_io();
  
  CreateTask(task_0, 128);
  CreateTask(task_1, 128);
  CreateTask(task_2, 128);   

  #ifdef __DEBUG
  TraceStack(&UsedStack[0]);
  TraceTask(0, &PORTB, 0);
  TraceTask(1, &PORTB, 1);
  TraceTask(2, &PORTB, 2);
  #endif

  CreateMessage(STACK, STACKSIZE);
  CreateMessage(BUFFER, BUFFERSIZE);
  
  InitTimer_2();

  StkPtr = 0;
  Index.Data = 0;
  Index.count = 0;
  
  Multitask(TMR_PERIOD);
  return 0;
  }

/*--- Task 0 ---*/

void task_0(void)
  {
  uint8_t value = 0;
   
  while(1)
    {
    Delay(5);

    if(StkPtr < STACKSIZE)
      {
      value++;
      ByteWrite(STACK, StkPtr++, value);
      }

    Nop(); 
    }   
  }

/*--- Task 1 ---*/

void task_1(void)
  {
  uint8_t byte;  

  while(1)
    {
    Delay(5);

    byte = ByteRead(STACK, (StkPtr ? --StkPtr : StkPtr));
    buffer[StkPtr] = byte;

    Nop(); 
    }
  }

/*--- Task 2 ---*/

void task_2(void)
  {
  uint8_t ix;

  ix = 0;
  
  while(1)
    {
    Delay(10);

    while(Index.count)
      {
      data[ix++] = ByteRead(BUFFER, Index.Data);
      Index.count--;
      Index.Data = (Index.Data + 1) % BUFFERSIZE;
      ix = (ix < 8) ? ix : 0;
      }

    Nop(); 
    }
  }

/*--- Timer 2 interrupt ---*/

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
  {
  uint8_t ix;
  static uint8_t byte = 0;

  LATCbits.LATC1 = 1;

  if(Index.count < BUFFERSIZE)
    { 
    ix = (Index.Data + Index.count) % BUFFERSIZE; 
    ByteWrite(BUFFER, ix, byte++);
    Index.count++;
    }
 
  LATCbits.LATC1 = 0;
  IFS0bits.T2IF = 0; 
  }

/*--- Re-Entrant delay function ---*/

void Delay(uint16_t delay)
  {
  uint16_t timer;

  while(delay--)
    {
    timer = 100;
    while(timer--){
      Nop();
      }
    }
  }

/*--- Initialise io port ---*/

void init_io(void)
  {
  ANSA = 0x0000;
	ANSB = 0x0000;
	ANSC = 0x0000;
	ANSD = 0x0000;
	ANSE = 0x0000;
	ANSF = 0x0000;
	ANSG = 0x0000;
 
  TRISB = 0;
  TRISC = 0;
  }

/*--- Initialise Timer 2 ---*/ 

void InitTimer_2(void)
  {
  T2CON = 0x8010;     /* Prescaler 1:8 */
  TMR2 = 0;           /* Clear Timer 2 */
  PR2 = 3000;         /* Period register */
  IPC1bits.T2IP = 3;  /* priority */
  
  IFS0bits.T2IF = 0;  /* Interrupt flag */
  IEC0bits.T2IE = 1;  /* Interrupt enable */
  }

/*--- Stack underflow/overflow trap  ---*/

#ifdef __DEBUG

void __attribute__((__interrupt__, no_auto_psv)) _StackError(void)
  {
  for(;;){
    Nop();
    }
  }

/*--- Address error trap  ---*/

void __attribute__((__interrupt__, no_auto_psv)) _AddressError(void)
  {
  for(;;){
    Nop();
    }
  }

#endif


/*--- End of File ---*/
