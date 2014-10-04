/*--------------------------------------------------------------------

  Title       : Create Task Demo 
  Filename    : Example_1.c 
    
  Copyright @ Bob The Bass 2012 
    
--------------------------------------------------------------------*/

/*--- Using a Pic30f6011A.h ---*/

#include "multitask.h" 
 
/*--- Configuration fuses ---*/

//_FOSC(CSW_FSCM_OFF & XT_PLL8)
//_FWDT(WDT_OFF)

/*--- Trace maximum stack usage ---*/  

#ifdef __DEBUG
#define NUM_TASKS 5U
uint16_t UsedStack[NUM_TASKS]; 
#endif

/*--- Task function prototypes ---*/

void task_0(void);
void task_1(void);
void task_2(void);
void task_3(void);
void task_4(void);

/*--- Local function prototypes ---*/

void init_io(void);
void Delay(uint16_t delay);

/*--- Global variables ---*/

uint16_t var0;
uint16_t var1;
uint16_t var2;
uint16_t var3;
uint16_t var4;

/*--- Program Entry ---*/

int main(void)
  {
    var0 = 0;
    var1 = 0;
    var2 = 0;
    var3 = 0;
    var4 = 0;

  init_io();

  CreateTask(task_0, 56);   /* All task create functions must be called from main() */
  CreateTask(task_1, 56);   /* in one unbroken sequence */
  CreateTask(task_2, 56);  
  CreateTask(task_3, 56);
  CreateTask(task_4, 56);  
  
  #ifdef __DEBUG
  TraceStack(&UsedStack[0]);
  TraceTask(0, &PORTB, 0);
  TraceTask(1, &PORTB, 1);
  TraceTask(2, &PORTB, 2);
  TraceTask(3, &PORTB, 3);
  TraceTask(4, &PORTB, 4);
  #endif

  Multitask(TMR_PERIOD);
  return 0;
  }

/*--- Task 0 ---*/

void task_0(void)
  {  
  while(1)
    {
    Delay(5);
    var0++; 
    }   
  }

/*--- Task 1 ---*/

void task_1(void)
  {  
  while(1)
    {
    Delay(5);
    TaskSleep(2);
    var1++;
    }
  }

/*--- Task 2 ---*/

void task_2(void)
  {
  while(1)
    {
    Delay(15);
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
    }
  }

/*--- Task 4 ---*/

void task_4(void)
  {
  while(1)
    {
    Delay(20);
    var4--;
    }
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
//  ADPCFG = 0xffff;
  PORTB = 0;
  TRISB = 0;      /* All outputs */
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
