#ifndef	__BMA180_H
#define	__BMA180_H

#include <p30f3011.h>

//ACCEL PINOUT
#define ASCK LATBbits.LATB4
#define ASI  PORTBbits.RB5
#define ASO  LATBbits.LATB6
#define ACS  LATBbits.LATB3
#define AINT  PORTBbits.RB2

#define ID 0x00
#define Version 0x01
#define ACCXLSB 0x02
#define ACCXMSB 0x03
#define ACCYLSB 0x04
#define ACCYMSB 0x05
#define ACCZLSB 0x06
#define ACCZMSB 0x07
#define TEMPERATURE 0x08
#define STATREG1 0x09
#define STATREG2 0x0A
#define STATREG3 0x0B
#define STATREG4 0x0C
#define CTRLREG0 0x0D
#define CTRLREG1 0x0E
#define CTRLREG2 0x0F
#define BWTCS 0x20
#define OLSB1 0x35
#define OFFSETT 0x37
#define RESET 0x10

void InitBMA180(void);
unsigned char accel_bytein(void);
void accel_byteout(unsigned char value);
void sw_delay(unsigned long time);
unsigned char accel_read_byte(unsigned char address);
void accel_write_byte(unsigned char address, unsigned char value);
signed short ReadAccX(void);
signed short ReadAccY(void);
signed short ReadAccZ(void);
unsigned char ReadTemp(void);
typedef union 
{
  unsigned char FULL;

  struct 
  {
    unsigned BIT0:1;
    unsigned BIT1:1;
    unsigned BIT2:1;
    unsigned BIT3:1;
    unsigned BIT4:1;
    unsigned BIT5:1;
    unsigned BIT6:1;
    unsigned BIT7:1;        
  };
  
}ABYTE;

#endif
