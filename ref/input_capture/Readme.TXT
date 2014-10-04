
                   Readme File for Code Example: INPUT CAPTURE
                 		     
             -----------------------------------------------------------------------------------------

This file contains the following sections:
1. Code Example Description
2. Folder Contents
3. Suggested Development Resources
4. Reconfiguring the project for a different PIC24F device
5. Revision History

NOTE: The example code makes use of Peripheral Library support available with MPLAB_C30 v3.11.

1. Code Example Description:
----------------------------
In this code example, INPUT CAPTURE in PIC24FJ256GB110 is used to capture signal applied to IC1 on RP2 pin.
Two signal on their successive falling edges are captured and the time delay between successive capture 
is calculated.



2. Folder Contents:
-------------------
This folder contains the following sub-folders:
a. C:\Program Files\Microchip\MPLAB C30\support\gld
        This folder will have the device GLD file, it is used for building the project. 
	This file was provided with the MPLAB?C30 toolsuite.

b. C:\Program Files\Microchip\MPLAB C30\support\h
        This folder contains C header files useful in building this
        project. Device register and bit definitions are provided in
        the *.h file that follows the device name. These files were provided
        with the MPLAB?C30 toolsuite.

c. C:\Program Files\Microchip\MPLAB C30\lib
        This folder contains library archive files, which are a
        collection of precompiled object files. The file
        named "libpic30-coff.a" contains the C run-time, start-up & Peripheral
        library. These file were provided with the
        MPLAB?C30 toolsuite.

d. C:\Program Files\Microchip\MPLAB C30\src
        This folder contains all the C ,Assembler, Peripheral library source files (*.c,
        *.s) used in demonstrating the described example. This folder
        also contains a sub-folder named "obj" that stores compiled
        object files generated when the project is built.
		
e. C:\Program Files\Microchip\MPLAB C30\src\peripheral_24F\include
		This folder contains the header files for all Peripheral library support.
		
f. C:\Program Files\Microchip\MPLAB C30\docs\periph_lib\Microchip PIC24F Peripheral Library.chm
		This file contains the Peripheral Library description for all devices and modules.		


3. Suggested Development Resources:
-----------------------------------
		a. MPLAB IDE with MPLAB C30 v3.11 or above
        b. Explorer 16 Development Board with  PIC24FJ256GB110 controller

4. Reconfiguring the project for a different PIC24F device:
-------------------------------------------------------------
The Project/Workspace can be easily reconfigured for any PIC24F device.
Please use the following general guidelines:
        a. Change device selection within MPLAB?IDE to a PIC24F device of
        your choice by using the following menu option:
        MPLAB IDE>>Configure>>Select Device
        a. Change device selection within MPLAB?IDE to a PIC24F device of
        your choice by using the following menu option:
        MPLAB IDE>>Configure>>Select Device 
		
		b. To configure the device settings, either choose from the MPLAB IDE>>Configure>>"Configuration bits" 
		and configure for necessary settings or the corresponding configuration
		macros to be added into the code can be obtained from device.INC file 
		at the following default location:
		"C:\Program Files\Microchip\MPLAB C30\support\PIC24F\inc"
		These macros can be added as depicted in example code.

        c. Re-build the MPLAB?project using the menu option:
        MPLAB IDE>>Project>>Build All

        d. Download the hex file into the device and run.

5. Revision History :
---------------------
        04/04/2009 - Initial Release of the Code Example
