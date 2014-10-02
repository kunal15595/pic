/*****************************************************************************
Copyright (C) 2011-12 Brigosha Technologies Private Limited
Disclaimer		: 
 Common:
 Brigosha Technologies products are developed for the consumer goods industry. They may only be used 
 within the parameters of the respective valid product data sheet.  Brigosha Technologies products are 
 provided with the express understanding that there is no warranty of fitness for a particular purpose. 
 They are not fit for use in life-sustaining, safety or security sensitive systems or any system or device 
 that may lead to bodily harm or property damage if the system or device malfunctions.


 Special:
 This software module (hereinafter called "Software") and any information on application-sheets 
 (hereinafter called "Information") is provided free of charge for the sole purpose to support your 
 application work. The Software and Information is subject to the following terms and conditions: 

 The Software is specifically designed for the exclusive use for Brigosha Technologies products by 
 personnel who have special experience and training. Do not use this Software if you do not have the 
 proper experience or training. 

 This Software package is provided `` as is `` and without any expressed or implied warranties, 
 including without limitation, the implied warranties of merchantability and fitness for a particular 
 purpose. 

 Brigosha Technologies  deny any liability for the functional impairment of this Software in terms of
 fitness, performance and safety. Brigosha Technologies shall not be liable for any direct or indirect
 damages or injury.
 
 The Information provided is believed to be accurate and reliable. Brigosha Technologies assumes no 
 responsibility for the consequences of use of such Information nor for any infringement of patents or 
 other rights of third parties which may result from its use. No license is granted by implication or 
 otherwise under any patent or patent rights of Brigosha Technologies. Specifications mentioned in the
 Information are subject to change without notice.

 It is not allowed to deliver the source code of the Software to any third party without permission of 
 Brigosha Technologies.

****************************************************************************************************/ 
/*
********************************************************************************
[File]          : CONFIGbits.h
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : Configuration bit settings for the Controller. Include this file
                  in the main file and use the macros for various oscillator selection.
                  #define OSC_PRIPLL_32MHZ
                  #define OSC_FRCPLL_16MHZ
                  #define OSC_SOSC_32KHZ
                  #define OSC_LPRC_31KHZ
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR] 				CHANGES
 v0.1	   	01.10.2012 	shashi.prakash@brigosha.com		Origin
********************************************************************************
*/

#ifndef CONFIGBITS_H
#define	CONFIGBITS_H

#include <stdio.h>
#include <stdlib.h>
#include <p24FJ256GB206.h>

/****************CONFIGURATION BITS*********************************/
_CONFIG1(JTAGEN_OFF &GCP_OFF &GWRP_OFF &ICS_PGx2 &FWDTEN_OFF)

#ifdef OSC_PRIPLL_32MHZ
    _CONFIG2(IESO_OFF &FCKSM_CSDCMD  &OSCIOFNC_OFF &POSCMOD_HS &FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2)
#else
    #ifdef OSC_FRCPLL_16MHZ
    _CONFIG2(IESO_OFF &FCKSM_CSDCMD  &OSCIOFNC_OFF &POSCMOD_HS &FNOSC_FRCPLL & PLL96MHZ_ON & PLLDIV_NODIV)
    #else
        #ifdef OSC_SOSC_32KHZ
        _CONFIG2(IESO_OFF &FCKSM_CSDCMD  &OSCIOFNC_OFF &POSCMOD_NONE &FNOSC_SOSC )
        #else
            #ifdef OSC_LPRC_31KHZ
            _CONFIG2(IESO_OFF &FCKSM_CSDCMD  &OSCIOFNC_OFF &POSCMOD_NONE &FNOSC_LPRC )
            #else
            _CONFIG2(IESO_OFF &FCKSM_CSDCMD  &OSCIOFNC_OFF &POSCMOD_NONE &FNOSC_FRCDIV )
            #endif
        #endif
    #endif
#endif
/*******************************************************************/
#endif	/* CONFIGBITS_H */

