/*--------------------------------------------------------------------

  Title       : Message passing Demo 
  Filename    : Example_4.c     
  
  Copyright @ Bob The Bass 2008 
    
--------------------------------------------------------------------*/

/*--- Using a PIC24HJ64GP206 ---*/

#include "multitask.h" 

/*--- Configuration fuses---*/

_FBS(RBS_NO_RAM & BSS_NO_FLASH & BWRP_WRPROTECT_OFF)
_FSS(RSS_NO_RAM & SSS_NO_FLASH & SWRP_WRPROTECT_OFF)
_FGS(GSS_OFF & GCP_OFF & GWRP_OFF)
_FOSCSEL(FNOSC_PRIPLL & IESO_ON) 
_FOSC(FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMD_HS)
_FWDT(FWDTEN_OFF & WINDIS_OFF & WDTPRE_PR128 & WDTPOST_PS32768)
_FPOR(FPWRT_PWR64)

/*--- Trace maximum stack usage ---*/  

#ifdef __DEBUG
#define NUM_TASKS 4U
uint16_t UsedStack[NUM_TASKS]; 
#endif

/*--- Task function prototypes ---*/

void task_0(void);
void task_1(void);
void task_2(void);
void task_3(void);

/*--- Local function prototypes ---*/

void config_oscillator(void);
void init_io(void);
void InitTimer_2(void);
void Delay(uint16_t delay);

/*--- Strucure to pass in message ---*/

typedef struct
  {
  uint16_t Variable_1;
  uint16_t Variable_2;
  }TESTSTRUCT;

/*--- Message names ---*/

enum{TXT_MSG = 0, STRUCT_MSG, ISR_MSG};

/*--- Program Entry ---*/

int main(void)
  { 
  config_oscillator();
  init_io();
  
  CreateTask(task_0, 128);
  CreateTask(task_1, 128);
  CreateTask(task_2, 128);   
  CreateTask(task_3, 128);

  #ifdef __DEBUG
  TraceStack(&UsedStack[0]);
  TraceTask(0, &PORTB, 0);
  TraceTask(1, &PORTB, 1);
  TraceTask(2, &PORTB, 2);
  TraceTask(3, &PORTB, 3);
  #endif

  CreateMessage(TXT_MSG, 12);
  CreateMessage(STRUCT_MSG, sizeof(TESTSTRUCT));
  CreateMessage(ISR_MSG, 24);
  
  InitTimer_2();
 
  Multitask(TMR_PERIOD);
  return 0;
  }

/*--- Task 0 ---*/

void task_0(void)
  {
  char buffer[24];
  char send_msg[] = {"Hello Task!"};
 
  while(1)
    {
    Delay(10);

    if(!MessageWaiting(TXT_MSG)){
      MessageWrite(TXT_MSG, &send_msg[0]);
      }

    if(MessageWaiting(ISR_MSG)){
      MessageRead(ISR_MSG, &buffer[0]);
      }

    Nop(); 
    }   
  }

/*--- Task 1 ---*/

void task_1(void)
  {  
  char read_msg[12];

  while(1)
    {
    Delay(10); 

    if(MessageWaiting(TXT_MSG)){
      MessageRead(TXT_MSG, &read_msg[0]);
      }
    }
  }

/*--- Task 2 ---*/

void task_2(void)
  {
  TESTSTRUCT Testsend;

  Testsend.Variable_1 = 0;
  Testsend.Variable_2 = 0;

  while(1)
    {
    Delay(10); 
     
    if(!MessageWaiting(STRUCT_MSG))
      {
      Testsend.Variable_1++;
      Testsend.Variable_2++;

      MessageWrite(STRUCT_MSG, &Testsend);
      }      
    }
  }

/*--- Task 3 ---*/

void task_3(void)
  {
  TESTSTRUCT TestReceive;

  while(1)
    {
    Delay(10);
           
    if(MessageWaiting(STRUCT_MSG)){
      MessageRead(STRUCT_MSG, &TestReceive);
      } 

    Nop();
    }
  }

/*--- Timer 2 interrupt ---*/

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
  {
  uint16_t ix = 500;

  LATCbits.LATC1 = 1;

  while(ix--){
    ;
    } 

  if(!MessageWaiting(ISR_MSG)){
    MessageWrite(ISR_MSG, "Timer 2 Calling");
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
  AD1PCFGH = 0xffff;    /* Port B as digital i/o */
	AD1PCFGL = 0xffff;

  TRISB = 0;
  TRISC = 0;
  }

/*--- Initialise Timer 2 ---*/ 

void InitTimer_2(void)
  {
  T2CON = 0x8010;     /* Prescaler 1:8 */
  TMR2 = 0;           /* Clear Timer 2 */
  PR2 = 10000;        /* Period register */
  IPC1bits.T2IP = 3;  /* priority */
  
  IFS0bits.T2IF = 0;  /* Interrupt flag */
  IEC0bits.T2IE = 1;  /* Interrupt enable */
  }

/*--- Config oscillator (using 29.4912 crystal) ---*/

void config_oscillator(void)
  {
  CLKDIVbits.ROI = 0;     /* Interrupts have no effect on the DOZEN bit */ 
  CLKDIVbits.DOZE = 0;    /* Device clock is cpu clock */ 
  CLKDIVbits.DOZEN = 0;   /* Device clock is cpu clock */ 
  CLKDIVbits.FRCDIV = 0;  /* Using external clock */

  CLKDIVbits.PLLPRE = 2;  /* 29.4912 / 4 = 7.3728 */ 
  PLLFBDbits.PLLDIV = 18; /* 7.3728 * 20 = 147.456 */ 
  CLKDIVbits.PLLPOST = 0; /* 147.456 / 2 = 73.728 (sytem clock /2 = 36.864Mips) */ 

  while(OSCCONbits.LOCK == 0){  /* Wait for pll lock */
    continue;
    }
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
