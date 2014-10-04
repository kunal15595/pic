/*--------------------------------------------------------------------

  Title       : Event flags demo
  Filename    : Example_2.c 
    
  Copyright @ Bob The Bass 2008 
    
--------------------------------------------------------------------*/

/*--- Using a Pic33FJ256GP710 ---*/

#include "multitask.h" 

/*--- Config fuse settings ---*/ 

_FOSCSEL(FNOSC_PRIPLL);
_FOSC(FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMD_XT);
_FWDT(FWDTEN_OFF);

/*--- Trace maximum stack usage ---*/  

#ifdef __DEBUG
#define NUM_TASKS 5U
uint16_t UsedStack[NUM_TASKS]; 
#endif

/*---- Define Event flags as single bits ---*/

#define EVENT_0       0x0001
#define EVENT_1       0x0002
#define EVENT_2       0x0004
#define T2_INTERRUPT  0x0008

/*--- Task function prototypes ---*/

void task_0(void);
void task_1(void);
void task_2(void);
void task_3(void);
void task_4(void);

/*--- Local function prototypes ---*/

void init_io(void);
void InitTimer_2(void);
void InitTimer_3(void);
void Delay(uint16_t delay);

/*--- Global variables ---*/

uint16_t var0 = 0;
uint16_t var1 = 0;
uint16_t var2 = 0;
uint16_t var3 = 0;
uint16_t var4 = 0;

/*--- Program Entry ---*/

int main(void)
  { 
  init_io();
  
  CreateTask(task_0, 64);
  CreateTask(task_1, 64);
  CreateTask(task_2, 64);
  CreateTask(task_3, 64);
  CreateTask(task_4, 64);
  
  #ifdef __DEBUG
  TraceStack(&UsedStack[0]);
  TraceTask(0, &PORTB, 0);
  TraceTask(1, &PORTB, 1);
  TraceTask(2, &PORTB, 2);
  TraceTask(3, &PORTB, 3);
  TraceTask(4, &PORTB, 4);
  #endif

  InitTimer_2();
  InitTimer_3(); 

  Multitask(TMR_PERIOD);
  return 0;
  }

/*--- Task 0 ---*/

void task_0(void)
  {
  while(1)
    {
    Delay(10);
    WaitForEvent(EVENT_0);
    TriggerEvent(EVENT_1);
    var0++; 
    }   
  }

/*--- Task 1 ---*/

void task_1(void)
  { 
  while(1)
    {
    Delay(20);  
    TriggerEvent(EVENT_0);
    var1++; 
    }
  }

/*--- Task 2 ---*/

void task_2(void)
  { 
  while(1)
    { 
    Delay(5);   
    WaitForEvent(EVENT_0 + EVENT_1 + T2_INTERRUPT); 
    var2++;
    }
  }

/*--- Task 3 ---*/

void task_3(void)
  { 
  while(1)
    { 
    Delay(5);
    var3++;
    WaitForEvent(T2_INTERRUPT);
    }
  }

/*--- Task 4 ---*/

void task_4(void)
  { 
  while(1)
    { 
    Delay(5);
    var4++;
    }
  }
  
/*--- Timer 2 interrupt ---*/

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
  {
  uint16_t ix = 1000;

  LATCbits.LATC1 = 1;

  TriggerEvent(T2_INTERRUPT); 

  while(ix--){
    ;
    }

  LATCbits.LATC1 = 0;

  IFS0bits.T2IF = 0; 
  }

/*--- Timer 3 interrupt ---*/

void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void)
  {
  uint16_t ix = 500;

  LATCbits.LATC2 = 1;

  while(ix--){
    ;
    }

  LATCbits.LATC2 = 0;

  IFS0bits.T3IF = 0; 
  }

/*--- Re-Entrant delay function ---*/

void Delay(uint16_t delay)
  {
  uint16_t timer;

  while(delay--)
    {
    timer = 1000;
    while(timer--){
      Nop();
      }
    }
  }

/*--- Initialise io port ---*/

void init_io(void)
  {
  AD1PCFGH = 0xffff;
  AD1PCFGL = 0xffff;
  TRISB = 0;
  TRISC = 0;
  }

/*--- Initialise Timer 2 ---*/ 

void InitTimer_2(void)
  {
  T2CON = 0x8010;     /* Prescaler 1:8 */
  TMR2 = 0;           /* Clear Timer 2 */
  PR2 = 65000;        /* Period register */
  IPC1bits.T2IP = 3;  /* priority */
  
  IFS0bits.T2IF = 0;  /* Interrupt flag */
  IEC0bits.T2IE = 1;  /* Interrupt enable */
  }

/*--- Initialise Timer 3 ---*/

void InitTimer_3(void)
  {
  T3CON = 0x8010;     /* Internal Tcy/8 clock */      
  TMR3 = 0;
  PR3 = 1000;   
  IPC2bits.T3IP = 5;  /* priority */ 

  IFS0bits.T3IF = 0; 
  IEC0bits.T3IE = 1;    
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
