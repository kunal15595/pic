#include <stdint.h>


extern void
ee_update( void );

extern uint8_t
ee_read( uint8_t addr, uint8_t *buf, uint8_t buf_len );

extern uint8_t
ee_write( uint8_t addr, uint8_t *buf, uint8_t buf_len );
