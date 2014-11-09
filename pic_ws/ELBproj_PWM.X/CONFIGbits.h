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
//            _CONFIG2(IESO_ON &FCKSM_CSECME  &OSCIOFNC_OFF &POSCMOD_HS &FNOSC_PRI  & PLLDIV_DIV2 & IOL1WAY_OFF)
            #endif
        #endif
    #endif
#endif
/*******************************************************************/
#endif	/* CONFIGBITS_H */

