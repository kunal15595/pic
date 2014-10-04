/*
  Copyright Simma Software, Inc. - 2011

  ee.c

  Implements SPI interface to Microchip 25xx serial EEPROM chips.

  This routine relies on a simple blocking SPI interface and can be
  easily adapted as needed.  The transmit portion buffers user data
  into a section in RAM.  Periodically the ee_update() function
  is called to write this buffered data to the serial EEPROM.
*/
#include <stdint.h>
#include "ee.h"
#include "ee_cfg.h"



/* the mask size depends on page size */
#if EE_PAGE_SIZE == 16
#define EE_PAGE_MASK         0xf
#elif EE_PAGE_SIZE == 32
#define EE_PAGE_MASK        0x1f
#else
#error unsupported EEPROM page size
#endif


/* commands to eeprom */
#define EE_READ                  (3)
#define EE_WRITE                 (2)
#define EE_WRDI                  (4)
#define EE_WREN                  (6)
#define EE_RDSR                  (5)
#define EE_WRSR                  (1)



/* this is one self contained buffer,
   we will probably used an arrar of these */
typedef struct {

  uint8_t addr;
  uint8_t buf[ EE_BUF_SIZE ];
  uint8_t len;
  uint8_t index;

} ee_buf_t;



ee_buf_t ee_buf;



/*
** Writes data directly to buffer, which is later written to EEPROM.
** INPUT: addr - EEPROM address
**        buf - buffer where EEPROM data is read from
**        buf_len - amount of data to write
** RETURN 0 - success
**        1 - fail
*/
uint8_t
ee_write ( uint8_t addr, uint8_t *buf, uint8_t buf_len )
{
  uint8_t cnt;

  /* return failure if any address exceeds chip's address space */
  if( ((addr + buf_len) > EE_CHIP_SIZE)
      || (buf_len > EE_BUF_SIZE) )
    return 1;

  if( ee_buf.len )
    return 1;

  ee_buf.len = buf_len;
  ee_buf.addr = addr;
  ee_buf.index = 0;

  /* copy over data */
  for( cnt = 0; cnt < buf_len; cnt++ )
    ee_buf.buf[ cnt ] = buf[ cnt ]; 
  
  return 0;
}



/*
** Reads directly from EEPROM.
** INPUT: addr - EEPROM address
**        buf - buffer where EEPROM data is placed
**        buf_len - amount of data to read
** RETURN 0 - success
**        1 - fail
*/
uint8_t
ee_read ( uint8_t addr, uint8_t *buf, uint8_t buf_len )
{
  uint8_t ret;

  /* bail if no buffer */
  if( !buf )
    return 1;

  /* read status register */ 
  spi_select_ee();
  spi_tx( EE_RDSR );
  ret = spi_rx();
  spi_deselect();

  /* is the serial eeprom busy? */
  if( (ret & 1) == 0 ) {

    /* put it in read mode */
    spi_select_ee();
    spi_tx( EE_READ );

    /* send address */
    spi_tx( addr );

    /* fill buffer */
    for( ret = 0; ret < buf_len; ret++ )
      buf[ ret ] =  spi_rx();

    spi_deselect();

  } else {

    return 1;
  }

  return 0;
}



/*
** Periodic update function which flushes buffer to EEPROM.
*/
void
ee_update ( void )
{
  uint8_t tmp, cnt, write_len;

  /* if there isn't anything to write, then don't do anything */
  if( ee_buf.len == 0 )
    return;

  /* find out a couple things */
  spi_select_ee();
  spi_tx( EE_RDSR );
  tmp = spi_rx();
  spi_deselect();

  /* is the chip busy */
  if( (tmp & 1) != 0 )
    return;

  /* write enable the device */
  spi_select_ee();
  spi_tx( EE_WREN );
  spi_deselect();

  /* is it block protected or write pin enabled? */
  if( tmp & (12) ) {

    spi_select_ee();
    spi_tx( EE_WRSR );
    spi_tx( 0 );
    spi_deselect();

  } else {

    /* write the starting addr to chip */
    spi_select_ee();
    spi_tx( EE_WRITE );
    spi_tx( ee_buf.addr );

    /* data can only be written until the end of the eeprom's page.
       the page is either 16 or 32 bytes big (refer to datasheet).
       this statement gives us our max write length */
    write_len = EE_PAGE_SIZE - (ee_buf.addr & EE_PAGE_MASK);

    /* if our buffer is less than the max length, then adjust max */
    if( ee_buf.len < write_len )
      write_len = ee_buf.len;

    /* write all the data we are allowed to */
    for( cnt = 0; cnt < write_len; cnt++ )
      spi_tx( ee_buf.buf[ee_buf.index+cnt] );

    /* there might still be data left to write, so adjust the variables
       to reflect the amount of information that was just written */
    ee_buf.len -= cnt;
    ee_buf.index += cnt;
    ee_buf.addr += cnt;

    spi_deselect();
  }

  return;
}
