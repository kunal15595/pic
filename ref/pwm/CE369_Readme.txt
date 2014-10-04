
    		       Readme File for Code Example:
              CE369 - Motor Control - PWM Complementary PWM 
             -----------------------------------------------

The PIC24FJ16MC101/102 devices offer ultra low-cost MCUs for Motor Control 
applications. This code example configures all 6 MC PWM outputs in 
complementary, center-aligned mode operation at 500Hz frequency.

The PWM faults are always enabled during any reset event. This code example
demonstrates how the PWM faults can be cleared. To clear the PWM faults,
The /FLTA and /FLTB pins must first be externally driven high and then 
cleared in software using the PxFLTACON and PxFLTBCON registers.

Suggested Development Tools: 

1) Explorer 16 development board
2) PIC24FJ16MC102 Plug-in module
3) MPLAB IDE 8.73 or later
4) C30 compiler v3.30 or later 

This file provides a brief description of files and folders provided
in the accompanying workspace.

This folder contains the following files:
1. This file
        This file provides a description of the functionality demonstr-
        ated by the example source code.

2. Complementary PWM.mcw, Complementary PWM.mcp
        These are MPLAB® IDE workspace and project files that may be
        used to examine, build, program and debug the example source
        code.

3. Complementary PWM.c
        This file contains the source code for this code example.
