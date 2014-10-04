/*--------------------------------------------------------------------

  Title       : Semaphore demo
  Filename    : Example_3.c 
    
  Copyright @ Bob The Bass 2008 
    
--------------------------------------------------------------------*/

/*--- Using a PIC24FJ128GA010 ---*/

#include "multitask.h" 

/*--- Config fuse settings ---*/ 

_CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & COE_OFF & FWDTEN_OFF & ICS_PGx2) 
_CONFIG2(FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_HS & FNOSC_PRI)

/*--- Trace maximum stack usage ---*/  

#ifdef __DEBUG
#define NUM_TASKS 4U
uint16_t UsedStack[NUM_TASKS]; 
#endif

/*--- Define and initialise global Semiphores to 0 ---*/

uint16_t Semaphore_1 = 0;
uint16_t Semaphore_2 = 0;

/*--- Task function prototypes ---*/

void task_0(void);
void task_1(void);
void task_2(void);
void task_3(void);

/*--- Local function prototypes ---*/

void init_io(void);
void InitTimer_2(void);
void Critical_function(uint8_t arg, uint8_t *var);
void Delay(uint16_t delay);

/*--- Global variables ---*/

uint8_t var0 = 0;
uint8_t var1 = 0;
uint8_t var2 = 0;
uint8_t var3 = 0;

/*--- Program Entry ---*/

int main(void)
  { 
  init_io();

  CreateTask(task_0, 0xff);
  CreateTask(task_1, 0xff);
  CreateTask(task_2, 0x100);
  CreateTask(task_3, 0x100);
  
  #ifdef __DEBUG
  TraceStack(&UsedStack[0]);
  TraceTask(0, &PORTB, 0);
  TraceTask(1, &PORTB, 1);
  TraceTask(2, &PORTB, 2);
  TraceTask(3, &PORTB, 3);
  #endif

  InitTimer_2();

  Multitask(TMR_PERIOD);
  return 0;
  }

/*--- Task 0 ---*/

void task_0(void)
  {  
  while(1)
    {
    Delay(5);   
    Critical_function(1, &var0);
    TaskYield();
    }   
  }

/*--- Task 1 ---*/

void task_1(void)
  {  
  while(1)
    {
    Delay(5);  
    Critical_function(2, &var1);
    TaskYield();
    }
  }

/*--- Task 2 ---*/

void task_2(void)
  {
  while(1)
    {
    Delay(5);  
    Critical_function(3, &var2);
    TaskYield();
    }
  }

/*--- Task 3 ---*/

void task_3(void)
  {
  while(1)
    {
    Delay(5);  
    var3++; 
    }
  }

/*--- Critical function ---*/

void Critical_function(uint8_t arg, uint8_t *var)
  {
  SetSemaphore(&Semaphore_1);

  if(arg == 1){
    LATCbits.LATC1 = 1;
    Delay(500); 
    (*var)++;
    }
  else if(arg == 2){
    LATCbits.LATC2 = 1;
    Delay(400);
    (*var)--; 
    }
  else if(arg == 3){
    LATCbits.LATC3 = 1;
    Delay(300);
    (*var) += 2; 
    }

  LATCbits.LATC1 = LATCbits.LATC2 = LATCbits.LATC3 = 0;

  ClearSemaphore(&Semaphore_1);
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

/*--- Timer 2 interrupt ---*/

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
  {
  uint16_t ix = 100;

  LATCbits.LATC4 = 1;

  while(ix--){
    ;
    }

  LATCbits.LATC4 = 0;

  IFS0bits.T2IF = 0; 
  }

/*--- Initialise io port ---*/

void init_io(void)
  {
  AD1PCFG = 0xffff;
  TRISB = 0;
  TRISC = 0;
  }

/*--- Initialise Timer 2 ---*/ 

void InitTimer_2(void)
  {
  T2CON = 0x8010;     /* Prescaler 1:8 */
  TMR2 = 0;           /* Clear Timer 2 */
  PR2 = 12000;        /* Period register */
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
