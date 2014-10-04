/*--------------------------------------------
 
  Title       : Header file for multitask.s V3.3  
  Filename    : multitask.h 
    
  Copyright @ Bob The Bass 2012  

----------------------------------------------*/

/*--- Frequency of Instruction Cycle Clock in Megahertz (Fcy) ---*/

#define FREQ_FCY 10.0

/*--- Task time slice in mili Seconds ---*/

#define TIME_SLICE  5.0   

/*--- Macro to calculate Timer period (8:1 Prescale value) ---*/

#define PRESCALE  8.0
#define TMR_PERIOD (((TIME_SLICE)*(1000.0))/((PRESCALE)/(FREQ_FCY)))

/*--- System configuration parameters --*/

#ifndef MULTITASK_H 
#define MULTITASK_H

/*--- Processor Include files ---*/

#if defined (__dsPIC30F__)
    #include <p30Fxxxx.h>
#elif defined (__dsPIC33F__)
    #include <p33Fxxxx.h>
#elif defined (__PIC24H__)
    #include <p24Hxxxx.h>
#elif defined (__PIC24F__)
    #include <p24Fxxxx.h>
#else
    #error Selected processor not supported
#endif

#include "PosixTypes.h"

/*--- Function pointer type define ---*/

typedef void(*Taskptr)(void);

/*--- Multitask function prototypes ---*/

void CreateTask(Taskptr task, uint16_t stack_size);
void Multitask(uint16_t tmr_period);

void TaskSleep(uint16_t count);
void TaskYield(void);
void DisableInterrupts(void);
void EnableInterrupts(void);

/*--- Event flag functions ---*/

void WaitForEvent(uint16_t event);
void TriggerEvent(uint16_t event);

/*--- Semaphore functions ---*/

void SetSemaphore(uint16_t *sem);
void ClearSemaphore(uint16_t *sem);

/*--- Message passing functions ---*/

void CreateMessage(uint8_t MsgID, uint8_t message_size);
Bool MessageWrite(uint8_t MsgID, void *message);
Bool ByteWrite(uint8_t MsgID, uint8_t index, uint8_t byte);
Bool MessageWaiting(uint8_t MsgID);
Bool MessageRead(uint8_t MsgID, void *message);
uint8_t ByteRead(uint8_t MsgID, uint8_t index);

/*--- Debug and Trace functions ---*/

#ifdef __DEBUG
void TraceStack(uint16_t *StackTop);
void TraceTask(uint16_t TaskID, volatile uint16_t *port, uint16_t port_bit);
#endif
 
#endif  /* Include gaurd */ 
        
/*--- End of File ---*/
