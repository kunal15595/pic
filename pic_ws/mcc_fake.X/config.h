/* 
 * File:   config.h
 * Author: kunal-laptop
 *
 * Created on October 4, 2014, 3:19 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif



// PIC24FJ256GB206 Configuration Bit Settings

#include <p24FJ256GB206.h>
int CONFIG4 __attribute__((space(prog), address(0x2ABF8))) = 0xFFFF ;
int CONFIG3 __attribute__((space(prog), address(0x2ABFA))) = 0xFFFF ;
int CONFIG2 __attribute__((space(prog), address(0x2ABFC))) = 0xFCFF ;
int CONFIG1 __attribute__((space(prog), address(0x2ABFE))) = 0x7FFF ;

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

