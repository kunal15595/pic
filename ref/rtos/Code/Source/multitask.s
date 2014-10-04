/*-------------------------------------------------

Title       : Multitasking kernel V3.3 
Filename    : multitask.s

Copyright @ Bob The Bass 2012 
      
---------------------------------------------------*/

/* ONLY! uncomment this line for PIC24F types with DSRPAG and DSWPAG instead of PSVPAG */

        ;.equiv NO_PSV_PAGE,1 

/*--- Select include files ---*/

        .ifdef __dsPIC30F
        .include "p30fxxxx.inc"
        .equ VALID_INC,1
        .equiv DSPIC_TYPE,1
        .endif

        .ifdef __dsPIC33F
        .include "p33Fxxxx.inc"
        .equ VALID_INC,1
        .equiv DSPIC_TYPE,1
        .endif

        .ifdef __PIC24F
        .include "p24Fxxxx.inc"
        .equ VALID_INC,1
        .endif

        .ifdef __PIC24H
        .include "p24Hxxxx.inc"
        .equ VALID_INC,1
        .endif

        .ifndef VALID_INC
        .error "Generic include file not found?"
        .endif

/*--- Macros for Timer interrupt ---*/

        .macro  StartTaskTimer      ;Initialise task timer
        mov     w0,PR1              ;TMR_PERIOD to timer period register
        clr     TMR1                ;Clear timer

        bset    IPC0,#T1IP0         ;Set timer priority to 1  
        bclr    IPC0,#T1IP1         
        bclr    IPC0,#T1IP2

        bclr    IFS0,#T1IF          ;Clear interrupt flag
        bset    IEC0,#T1IE          ;Enable interrupt

        mov     #0x8010,w0          
        mov     w0,T1CON            ;Start Timer, Prescale 8:1
        .endm

        .macro  ClearInterrupt
        bclr    IFS0,#T1IF          ;Clear interrupt flag
        .endm

        .macro  StartTasking        ;Enable Tasking interrupt
        bset    IEC0,#T1IE          ;Set interrupt enable flag 
        .endm   

        .macro  StopTasking         ;Disable Tasking interrupt
        bclr    IEC0,#T1IE          ;Clear interrupt enable flag
        .endm

/*--- Global Task Functions ---*/

        .global __T1Interrupt 
        .global _CreateTask
        .global _Multitask

        .global _TaskSleep
        .global _TaskYield
        .global _DisableInterrupts
        .global _EnableInterrupts
        
/*--- Global Debug and Trace functions ---*/

        .ifdef __DEBUG
        .global _TraceTask
        .global _TraceStack
        .endif       

/*--- Global support functions ---*/

        .global _WaitForEvent
        .global _TriggerEvent

        .global _SetSemaphore
        .global _ClearSemaphore

/*--- Global message functions ---*/

        .global _CreateMessage
        .global _MessageWrite
        .global _ByteWrite
        .global _MessageWaiting
        .global _MessageRead
        .global _ByteRead

/*------ Task state constants ------*/

        .equiv  READY,      0
        .equiv  BLOCKED,    1
        .equiv  WAITING,    2     
        .equiv  ASLEEP,     3

/*--- Offsets into task structure ---*/

        .equiv  STATUS,     4
        .equiv  PENDING,    6
        .equiv  EVENTFLAGS, 8
        .equiv  SLEEPING,   10

        .ifdef __DEBUG
        .equiv  TRACEPORT,  12  
        .equiv  TRACEBIT,   14  
        .endif   

/*--- Offsets into message structure ---*/

        .equiv  MSGID,      2
        .equiv  MSGSIZE,    4
        .equiv  MESSAGE,    6

/*--- Uninitialized ram allocation. ---*/

        .bss  
        StackTop:       .space 2 
        Critical:       .space 2
                  
/*--- Initialized ram allocation. ---*/

        .data
        TaskList:       .int 0
        MessageList:    .int 0 

        .ifdef __DEBUG
        TraceBuffer:    .int 0
        .endif   
            
/*--- Program entry ---*/

        .text 
              
/*--- Create Task structure and initialise task stack ---*/

_CreateTask:
        sl      w1,w1               ;Allign, stack depth to bytes
        mov     w15,w14             ;Save stack pointer
        sub     w14,#4,w14          ;Point to callers return address
        mov     w14,w4              ;Start of free memory
        add     w1,w15,w15          ;Add stack size to stack pointer
        mov     w15,w12             ;Save top of task stack
        repeat  #1
        mov     [w14++],[w15++]     ;Shift callers return address and SR
        mov     [w14],[w15]         ;To new stack pointer
        
        mov     w4,Critical         ;Use variable to save task pointer
        cp0     TaskList            ;First stack in list? 
        bra     nz,1f
        mov     w4,TaskList         ;Intialise TaskList
        clr     w5                  ;Clear ID counter
        
1:      mov     w12,[w4++]          ;Pointer to next task        
        mov     w4,StackTop         ;Save pointer to stack top
        mov     w4,[w4++]           

        mov     w5,w2               ;ID counter
        inc     w5,w5               ;Increment ID counter
        swap    w2                  ;ID to hi-byte
        mov.b   #READY,w2
        mov     w2,[w4++]           ;Task Status to ready
        add     #6,w4               ;Task flags space

.ifdef __DEBUG
        add     #4,w4               ;Trace bits space
.endif
        mov     w0,[w4++]           ;Pointer to task function
        clr     [w4++]              ;High byte of function pointer

        mov     #36,w1              ;Register stack space

.ifdef DSPIC_TYPE
        add     #22,w1              ;Add dsp register stack space
.endif

        add     w1,w4,w4            ;Add size of registers to task structure
        mov     _CORCON,w1          
        mov     w1,[w4++]           ;Intialise CORCON

.ifdef NO_PSV_PAGE                  ;PIC24F types with no PSVPAG
        mov     _DSRPAG,w1          
        mov     w1,[w4++]           ;Intialise DSRPAG
        mov     _DSWPAG,w1          
        mov     w1,[w4++]           ;Intialise DSWPAG
.else
        mov     _PSVPAG,w1          
        mov     w1,[w4++]           ;Intialise PSVPAG
.endif
    
        mov     StackTop,w1         ;Get pointer to stack top       
        mov     w4,[w1]             ;Intialise stack pointer    
        return

/*--- Start Timer and Multitasking ---*/

_Multitask:
        StartTaskTimer              ;Initialise task timer
        mov     Critical,w2         ;Save last task address  
        mov     TaskList,w0         ;Pointer to first Task        
        mov     w0,[w2]             ;Create linked list

.ifdef __DEBUG
        rcall   SetPortBit          ;Set Trace bit
.endif  

        mov     w0,StackTop         ;Save Stack address
        inc2    StackTop            ;Point to Task structure
        add     #16,w0              ;Offset to Task function pointer

.ifdef __DEBUG
        add     #4,w0               ;Trace Port and Trace Bit
.endif
        mov     w0,w15              ;Initialise stack with Task function address          
        retfie                      ;Start Multitasking

/*--- Task sleep ---*/

_TaskSleep:
        mov     StackTop,w2         ;Load task pointer
        dec2    w2,w2               ;Point to task structure        
        mov     w0,[w2+SLEEPING]    ;Save sleep time   
        mov     #ASLEEP,w0          ;Change status to Sleeping
        mov.b   w0,[w2+STATUS]      ;Fall through to yield  

/*--- Task yield ---*/

_TaskYield:
        bset    SR,#5               ;Set interrupt priority level to 1
        clr     TMR1                ;Clear timer for next task
               
/*--- Task scheduler Timer interrupt ---*/
        
__T1Interrupt:
        ClearInterrupt              ;Clear interrupt flag           
        push    SR                  
        push    w0                           
        mov     #0xe0,w0
        ior.b   SR                  ;Disable interrupts          
        push    w1
        push.d  w2
        push.d  w4
        push.d  w6
        push.d  w8
        push.d  w10
        push.d  w12
        push    w14
        push    RCOUNT
        push    TBLPAG

.ifdef DSPIC_TYPE
        push    ACCAL
        push    ACCAH
        push    ACCAU
        push    ACCBL
        push    ACCBH
        push    ACCBU
        push    DCOUNT
        push    DOSTARTL
        push    DOSTARTH
        push    DOENDL
        push    DOENDH  
.endif
        push    CORCON

.ifdef NO_PSV_PAGE
        push    DSRPAG
        push    DSWPAG
.else
        push    PSVPAG
.endif

        mov     StackTop,w0         ;Task top of stack
        mov     w15,[w0]            ;Move top of stack to pointer

/*--- Task scheduler ---*/

        dec2    w0,w0               ;Pointer to current task
                
.ifdef __DEBUG
        rcall   ClearPortBit        ;Clear Trace bit
        cp0     TraceBuffer         ;Test for trace buffer
        bra     z,1f                ;Trace buffer not allocated
        sub     w15,w0,w1           ;Get stack depth
        rcall   SaveStackDepth      ;Save maximum stack depth
.endif    
                 
/*--- Loop to find next ready task ---*/

1:      mov     [w0],w0             ;Pointer to next task
        mov.b   [w0+STATUS],w1      ;Task status
        cp.b    w1,#READY           ;Test if ready state
        bra     z,StartTask         ;Start task

        cp.b    w1,#ASLEEP          ;Test if sleeping
        bra     nz,1b

        mov     [w0+SLEEPING],w1    ;Get timer value
        cp0     w1
        bra     z,2f                ;Check if timed out

        dec     w1,w1               ;Decrement timer
        mov     w1,[w0+SLEEPING]    ;Update timer value
        bra     1b                  ;Next task
             
2:      mov     #READY,w1           ;Status to ready    
        mov.b   w1,[w0+STATUS]      ;Start task    
    
                               
/*--- Start next Task ---*/

StartTask:
                
.ifdef __DEBUG       
        rcall   SetPortBit          ;Set tasks trace bit
.endif  

        inc2    w0,w0               ;Pointer to stack top
        mov     w0,StackTop         ;Save pointer for next time
        mov     [w0],w15            ;Initialise stack pointer

/*--- Restore context ---*/

.ifdef NO_PSV_PAGE
        pop     DSWPAG
        pop     DSRPAG
.else
        pop     PSVPAG
.endif

        pop     CORCON

.ifdef DSPIC_TYPE
        pop     DOENDH
        pop     DOENDL
        pop     DOSTARTH
        pop     DOSTARTL
        pop     DCOUNT
        pop     ACCBU
        pop     ACCBH
        pop     ACCBL
        pop     ACCAU
        pop     ACCAH
        pop     ACCAL
.endif
        pop     TBLPAG
        pop     RCOUNT  
        pop     w14
        pop.d   w12
        pop.d   w10
        pop.d   w8
        pop.d   w6
        pop.d   w4
        pop.d   w2
        pop.d   w0
        pop     SR
        retfie

/*--- Disable interrupts ---*/

_DisableInterrupts:
        push    w0
        mov     SR,w0
        mov     w0,Critical         ;Save status register
        mov     #0xe0,w0            ;Set interrupt bits
        ior.b   SR                  ;Disable interrupts
        pop     w0
        return

/*--- Enable interrupts ---*/

_EnableInterrupts:
        push    w0
        mov     Critical,w0         ;Restore status register
        mov     w0,SR
        pop     w0
        return

/*--- Set Wait for event flag ---*/

_WaitForEvent:
        StopTasking                 ;Stop Task switching
        mov     StackTop,w2         ;Load task pointer
        dec2    w2,w2               ;Point to task structure        
        mov     w0,[w2+EVENTFLAGS]  ;Save Flags       
        mov     #WAITING,w0
        mov.b   w0,[w2+STATUS]      ;Change status to Waiting

        StartTasking                ;Resume task switching
        rcall   _TaskYield          ;Force task switch
        return
               
/*--- Trigger event ---*/

_TriggerEvent:
        StopTasking                 ;Stop Task switching
        mov     StackTop,w1         ;Load running task pointer 
        dec2    w1,w1               ;Pointer to task struture            
        mov     w1,w2               ;w2 as task list end 
        mov     [w1],w1             ;Next task in list
        com     w0,w0               ;Flags to clear mask 

1:      mov.b   [w1+STATUS],w3      ;Get task status
        cp.b    w3,#WAITING         ;Test if waiting
        bra     nz,2f               ;Not waiting
 
        mov     [w1+EVENTFLAGS],w3  ;Get task flags
        and     w0,w3,w3            ;Mask flags               
        mov     w3,[w1+EVENTFLAGS]  ;Save result
        bra     nz,2f               ;Test if all clear

        mov     #READY,w3           ;All flags clear
        mov.b   w3,[w1+STATUS]      ;Change status to Ready

2:      mov     [w1],w1             ;Next task in list
        cp      w1,w2               ;Task list end?
        bra     nz,1b      

        StartTasking                ;Resume task switching
        return
    
/*--- Set Semaphore ---*/

_SetSemaphore:
        StopTasking                 ;Stop Task switching
        mov     StackTop,w1         ;Load running task pointer 
        dec2    w1,w1               ;Pointer to current task
        mov     w0,[w1+PENDING]     ;Semaphore passed in w0 
        cp0     [w0]                ;Dereference pointer
        bra     z,2f                ;Semaphore is free? 
      
        mov     #BLOCKED,w2         ;Semaphore is not free
        mov.b   w2,[w1+STATUS]      ;Change status to Blocked
     
1:      StartTasking                ;Restart kernel
        rcall   _TaskYield          ;Force task switch
   
        StopTasking                 ;Stop Task switching
        cp0     [w0]                ;Check if semaphore clear
        bra     z,2f                ;Semaphore is clear

        mov     #BLOCKED,w2         ;Semaphore is not free
        mov.b   w2,[w1+STATUS]      ;Keep status Blocked
        bra     1b                  ;Task yield
             
2:      inc     [w0],[w0]           ;Set Semaphore
        StartTasking                ;Resume Task switching
        return      

/*--- Clear Semaphore ---*/

_ClearSemaphore:
        StopTasking                 ;Stop Task switching                 
        mov     StackTop,w1         ;Load running task pointer 
        dec2    w1,w1               ;Pointer to current task            
        mov     w1,w4               ;Save as task list end
        mov     [w1],w1             ;Pointer to next task       
        clr     [w0]                ;Clear Semaphore 

1:      mov.b   [w1+STATUS],w2      ;Task state 
        cp.b    w2,#BLOCKED         ;Is task blocked?
        bra     nz,2f               ;Not blocked
       
        mov     [w1+PENDING],w2     ;Task semaphore     
        cp      w0,w2               ;This Semaphore?
        bra     nz,2f               ;Not this semaphore

        mov     #READY,w2           ;Change status to Ready
        mov.b   w2,[w1+STATUS]  
  
2:      mov     [w1],w1             ;Pointer to next task
        cp      w1,w4               ;Task list end?
        bra     nz,1b

        StartTasking                ;Resume Task switching
        return

/*--- Create Message Box ---*/

_CreateMessage:
        ze      w1,w1               ;Clear high byte of message size
        btsc    w1,#0               ;Test message size for allignment
        inc     w1,w1               ;Allign, make even     
        add     w1,#6,w3            ;Add size of message structure
        mov     SPLIM,w2            ;Stack limit
        inc2    w2,w2               ;Last message address
        sub     w2,w3,w2            ;Subtract from last message address
        mov     MessageList,w4      ;Pointer to next message
        mov     w4,[w2]             ;Save pointer
        mov     w2,MessageList      ;Update start of list
        dec2    w2,w4               ;Set new stack limit
        mov     w4,SPLIM
        ze      w0,w0               ;Clear high byte of Message ID
        mov     w0,[++w2]           ;Save message ID
        mov     w1,[++w2]           ;Save message size     
        return

/*--- Write message ---*/

_MessageWrite:
        rcall   FindMessage         ;Get pointer to message
        push    SR                  ;Save status register   
        rcall   Message_SetUp       ;Set up for write        
        repeat  w3                  ;Message size counter
        mov.b   [w1++],[w0++]       ;Message in w1
        mov     #1,w0               ;Set write flag
        mov.b   w0,[w4+MSGID+1]     ;Save flag
        pop     SR                  ;Restore status register       
        return

/*--- Write a byte to the message buffer ---*/

_ByteWrite:
        rcall   FindMessage         ;Get pointer to message
        push    SR                  ;Save status register                            
        rcall   Message_SetUp       ;Set up for write  
        cp.b    w1,w3               ;Check index within bounds
        bra     gtu,1f              ;Index out of bounds
        add.b   w1,w0,w0            ;Add index to message pointer
        mov.b   w2,[w0]             ;Write byte
        mov     #1,w0               ;Return 1
        bra     2f

1:      clr     w0                  ;Byte not written
2:      pop     SR                  ;Restore status register 
        return

/*--- Read message ---*/

_MessageRead:
        rcall   FindMessage         ;Get pointer to message
        push    SR                  ;Save status register   
        rcall   Message_SetUp       ;Set up for read 
        repeat  w3                  ;Message size counter
        mov.b   [w0++],[w1++]       ;Move message to w1
        clr     w3                  ;Clear read flag
        mov.b   w3,[w4+MSGID+1]     ;Save flag  
        mov     #1,w0               ;Return 1
        pop     SR                  ;Restore status register    
        return

/*--- Read a byte from the message buffer ---*/

_ByteRead:
        rcall   FindMessage         ;Get pointer to message
        push    SR                  ;Save status register 
        rcall   Message_SetUp       ;Set up for read
        cp.b    w1,w3               ;Check index within bounds
        bra     gtu,1f              ;Index out of bounds
        add.b   w1,w0,w0            ;Add index to message pointer                           
        mov.b   [w0],w0             ;Read byte
        bra     2f

1:      clr     w0                  ;Byte not read
2:      pop     SR                  ;Restore status register 
        return

/*--- Check message box status ---*/

_MessageWaiting:
        rcall   FindMessage         ;Get pointer to message
        clr     w0
        mov.b   [w4+MSGID+1],w0     ;Message flag value
        return

/*--- Find message from ID ---*/

FindMessage:
        mov     MessageList,w4      ;Pointer to message list
1:      mov.b   [w4+MSGID],w3       ;Message ID
        cp.b    w0,w3               ;This message?
        bra     z,2f                ;Message found
        mov     [w4],w4             ;Next message in list
        cp0     w4                  ;List end?
        bra     nz,1b

        pop.d   w0                  ;skip return address
        clr     w0                  ;Message not found
2:      return

/*--- Set up message size and pointers ---*/

Message_SetUp:                         
        mov     #0xe0,w0
        ior.b   SR                  ;Disable interrupts 
        add     w4,#MESSAGE,w0      ;Pointer to message 
        mov     [w4+MSGSIZE],w3     ;Message size
        dec     w3,w3               ;Adjust size for repeat loop
        return

/*--- Debug and trace functions ---*/ 

.ifdef __DEBUG

/*--- Initialise Trace buffer address ---*/

_TraceStack:
        mov     w0,TraceBuffer      ;Pointer to Stack Trace array
        return

/*--- Save maximum used stack depth ---*/

SaveStackDepth:
        mov     [w0+STATUS],w2     
        swap    w2                  ;Get task ID
        ze      w2,w2               ;Clear Hi-byte
        sl      w2,w2               ;Allign

        mov     TraceBuffer,w3
        add     w2,w3,w3            ;Buffer address
        mov     [w3],w2             ;Last used stack depth

        sl      w2,w2               ;Change to bytes    
        cp      w1,w2               ;Current used stack depth 
        bra     leu,1f              ;Compare
        asr     w1,#1,w1            ;If greater change to depth size
        mov     w1,[w3]             ;Save largest stack depth
1:      return

/*--- Initialise Task trace port and bit ---*/

_TraceTask:
        mov     TaskList,w3         ;First task address
        cp0     w0                  ;Task ID
        bra     z,2f
1:      mov     [w3],w3             ;Next task in list
        dec     w0,w0               
        bra     nz,1b

2:      mov     w1,[w3+TRACEPORT]   ;Address of Port
        mov     #1,w4
        sl      w4,w2,w4            ;Port trace Bit        
        mov     w4,[w3+TRACEBIT]
        return

/*--- Set Trace port bit ---*/

SetPortBit:
        mov     [w0+TRACEPORT],w1   ;Address of Port
        cp0     w1
        bra     z,1f                ;Test if valid
        mov     [w0+TRACEBIT],w2    ;Port Bit
        mov     [w1],w3             ;Port value
        ior     w3,w2,w3            ;Set bit with mask
        mov     w3,[w1]             ;Update port value             
1:      return

/*--- Clear Trace port bit ---*/

ClearPortBit:
        mov     [w0+TRACEPORT],w1   ;Address of Port
        cp0     w1
        bra     z,1f                ;Test if valid
        mov     [w0+TRACEBIT],w2    ;Port Bit
        com     w2,w2               ;Clear bitmask
        mov     [w1],w3             ;Port value
        and     w3,w2,w3            ;Clear bit with mask
        mov     w3,[w1]             ;Update port value             
1:      return

.endif                              ;End of conditional debug compile
        .end                        ;End of program code

/*--- End of file. ---*/








    
