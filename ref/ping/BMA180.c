#include "BMA180.h"
#define  ONE_G 0
#define  ONE_DOT_FIVE_G 1
#define  TWO_G 2
#define  THREE_G 3
#define  FOUR_G 4
#define  EIGHT_G 5
#define  SIXTEEN_G 6

#define FULL_SCALE_RANGE ONE_DOT_FIVE_G  //HERE CHANGES GRATIVY RANGE

unsigned char status_reg1; 
unsigned char accel_range;
unsigned char temp1,temp2; 
void InitBMA180(void)
{

  TRISBbits.TRISB4=0; //ASCK
  TRISBbits.TRISB5=1; //ASI
  TRISBbits.TRISB6=0; //ASO
  TRISBbits.TRISB3=0; //ACS
  TRISBbits.TRISB2=1; //AINT

  ACS=1;
  ASO=1;
  ASCK=1;

  sw_delay(20000); 
  
  // Set ee_w bit
  temp1 = accel_read_byte(0x0D);
  temp1 |= 0x10;
  accel_write_byte(0x0D, temp1);	// Have to set ee_w to write any other registers
  temp1 = accel_read_byte(0x0D);

  // Set Range
  temp2 = accel_read_byte(0x35);
  Nop();

  temp1 = FULL_SCALE_RANGE;
  temp1 = (temp1<<1);
  temp2 &= (~0x0E);
  temp2 |= temp1;
  accel_write_byte(0x35, temp2); //Write new range data, keep other bits the same
  sw_delay(20000); 
  temp2 = accel_read_byte(0x35);
  Nop();

  
}

void accel_write_byte(unsigned char address, unsigned char value)
{
   ASCK=1; //ASCK
   Nop();
   ACS=0;
   Nop();
   ASCK=0; //ASCK

   accel_byteout(address);
   accel_byteout(value);
   
   ASCK=1; //ASCK
   Nop();
   ACS=1;
   Nop();      
}

signed short ReadAccX(void)
{
        unsigned char temp=0;
        signed short temp2; 
                                 
        while (temp != 1)
		{
			temp = accel_read_byte(ACCXLSB) & 0x01;
		}
			
		temp = accel_read_byte(ACCXMSB);
		temp2 = temp << 8;
		temp2 |= accel_read_byte(ACCXLSB);
		temp2 = temp2 >> 2;	

        return temp2;

}

unsigned char ReadTemp(void)
{
  char temp=accel_read_byte(TEMPERATURE);

  return temp/2+15;       	

}

signed short ReadAccY(void)
{

        unsigned char temp=0;
        signed short temp2; 

        while (temp != 1)
		{
			temp = accel_read_byte(ACCYLSB) & 0x01;
		}
		
		temp = accel_read_byte(ACCYMSB);
		temp2 = temp << 8;
		temp2 |= accel_read_byte(ACCYLSB);
		temp2 = temp2 >> 2;

        return temp2;

}

signed short ReadAccZ(void)
{
        unsigned char temp=0;
        signed short temp2; 

        while (temp != 1)
		{
			temp = accel_read_byte(ACCZLSB) & 0x01;
		}
		
		temp = accel_read_byte(ACCZMSB);
		temp2 = temp << 8;
		temp2 |= accel_read_byte(ACCZLSB);
		temp2 = temp2 >> 2;

        return temp2;

}

unsigned char accel_read_byte(unsigned char address)
{
   unsigned char value;

   ASCK=1; //ASCK
   Nop();
   ACS=0;
   Nop();
   ASCK=0; //ASCK

   accel_byteout(address|0x80);
   value=accel_bytein();

   ASCK=1; //ASCK
   Nop();
   ACS=1;
   Nop();      

   return value;
}


unsigned char accel_bytein(void)
{
   ABYTE display;
   unsigned char value=0;
 
   display.FULL= 0x00;
 
   Nop();
   display.BIT7=ASI;
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   Nop();
   display.BIT6=ASI;
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   Nop();
   display.BIT5=ASI;
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK
   
   Nop();
   display.BIT4=ASI;
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   Nop();
   display.BIT3=ASI;
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   Nop();
   display.BIT2=ASI;
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   Nop();
   display.BIT1=ASI;
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   Nop();
   display.BIT0=ASI;
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   value=display.FULL;
   
   return value;
  
}


void accel_byteout(unsigned char value)
{
   ABYTE display;
 
   display.FULL= value;
 
   ASO= display.BIT7;
   Nop();
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK
  
   ASO= display.BIT6;
   Nop();
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   ASO= display.BIT5;
   Nop();
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   ASO= display.BIT4;
   Nop();
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   ASO= display.BIT3;
   Nop();
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   ASO= display.BIT2;
   Nop();
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   ASO= display.BIT1;
   Nop();
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK

   ASO= display.BIT0;
   Nop();
   ASCK=1; //ASCK
   Nop();
   ASCK=0; //ASCK
}

void sw_delay(unsigned long time)
{
  while(time--);
}

