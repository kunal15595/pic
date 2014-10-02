
                              Readme File for Code Example:
              CE019 - Proportional Integral Derivative (PID) controllers
                      for Closed-loop Control Systems
        -------------------------------------------------------------------

This file contains the following sections:
1. Code Example Description
2. Folder Contents
3. Suggested Development Resources
4. Reconfiguring the project for a different dsPIC30F device
5. Revision History


1. Code Example Description:
----------------------------
This code example demonstrates a Proportional Integral Derivative (PID) Controller. The PID controller can be found as part of the MPLAB C30 DSP library functions starting from version 2.0 of the toolsuite.

The source file dsp.h provides the following prototypes and definitions:

typedef struct {
        fractional* abcCoefficients;  /* coeffs derived from Kp, Ki & Kd */
        fractional* controlHistory;   /* state variables (delay line)in Y-data
        fractional controlOutput;     /* PID Controller Output  */
        fractional measuredOutput;    /* Measured Output sample */
        fractional controlReference;  /* Reference Input sample */
} tPID;

extern void PIDCoeffCalc( fractional* kCoeffs, tPID* controller );
extern void PIDInit ( tPID* controller );
extern fractional* PID ( tPID* controller );

The three PID functions have been implemented in the source file pid.s available in the DSP library.

The source file main.c demonstrates how the PID functions can be called in a closed-loop control appication. Refer to the C30 Library Users Guide for further information.

A brief description on PID Controllers:
----------------------------------------

A PID controller responds to an error signal in a closed control loop and attempts to adjust the controlled quantity in order to achieve the desired system response. The controlled parameter can be any measurable system quantity, such as speed, voltage, current, or stock price.  The output of the PID controller can control one or more system parameters that will affect the controlled system quantity.  For example, the speed control loop in this application can control the PWM duty cycle directly or it can set the current demand for an inner control loop that regulates the motor currents.  The benefit of the PID controller is that it can be adjusted empirically by adjusting one or more gain values and observing the change  in system response.

A digital PID controller is executed at a periodic sampling interval and it is assumed that the controller is executed frequently enough so that the system can be properly controlled.  For example, the current controller in this application is executed every PWM cycle, since the motor can change very rapidly.  The speed controller in this application is executed at the medium event rate (100 Hz), because motor speed changes will occur relatively slowly due to mechanical time constants.

The error signal is formed by subtracting the desired setting of the parameter to be controlled from the actual measured value of that parameter.  This sign of the error indicates the direction of change required by the control input.

The Proportional (P) term of the controller is formed by multiplying the error signal by a P gain.  This will cause the PID controller to produce a control response that is a function of the error magnitude.  As the error signal becomes larger, the P term of the controller becomes larger to provide more correction.

The effect of the P term will tend to reduce the overall error as time elapses.  However, the effect of the P term will reduce as the error approaches zero.  In most systems, the error of the controlled parameter will get very close to zero, but will not converge.  The result is a small remaining steady state error.  The Integral (I) term of the controller is used to fix small steady state errors.  The I term takes a continuous running total of the error signal.  Therefore, a small steady state error will accumulate into a large error value over time.  This accumulated error signal is multiplied by an I gain factor and becomes the I output term of the PID controller.

The Differential (D) term of the PID controller is used to enhance the speed of the controller and responds to the rate of change of the error signal.  The D term input is calculated by subtracting the present error value from a prior value.  This delta error value is multiplied by a D gain factor that becomes the D output term of the PID controller.  The D term of the controller produces more control output the faster the system error is changing.

It should be noted that not all PID controllers will implement the D or, less commonly, the I terms.  For example, the speed controller in this application does not have a D term due to the relatively slow response time of motor speed changes.  In this case, the D term could cause excessive changes in PWM duty cycle that could affect the operation of the sensorless algorithm and produce over current trips.

Adjusting the PID Gains

The P gain of a PID controller will set the overall system response.  When first tuning a controller, the I and D gains should be set to zero.  The P gain can then be increased until the system responds well to set-point changes without excessive overshoot or oscillations.  Using lower values of P gain will 'loosly' control the system, while higher values will give 'tighter' control.  At this point, the system will probably not converge to the set-point.

After a reasonable P gain is selected, the I gain can be slowly increased to force the system error to zero.  Only a small amount of I gain is required in most systems.  Note that the effect of the I gain, if large enough, can overcome the action of the P term, slow the overall control response,  and cause the system to oscillate around the set-point.  If this occurs, reducing the I gain and increasing the P gain will usually solve the problem.

After the P and I gains are set, the D gain can be set.   The D term will speed up the response of control changes, but it should be used sparingly because it can cause very rapid changes in the controller output.  This behavior is called 'set-point kick'.  The set-point kick occurs because the difference in system error becomes instantaneously very large when the control set-point is changed. In some cases, damage to system hardware can occur.  If the system response is acceptable with the D gain set to zero, you can probably omit the D term.


2. Folder Contents:
-------------------
This folder contains the following sub-folders:
a. gld
        This folder contains a linker script file for the example project.
        This file is used for building the project for a 30F6014A device.
        This file simply includes the relevant device linker script, 
        "p30F4011.gld" and the relevant MPLAB® C30 library files, 
        "libdsp-coff.a", "libc-coff.a", and "libm-coff.a" or 
        "libdsp-elf.a", "libc-elf.a", and "libm-elf.a" from their installed 
        location. 

b. h
        This folder contains C header files useful in building this
        project. Device register and bit definitions are provided in
        the "p30F4011.h" file, which may be found in the installation folder
        of the MPLAB® C30 toolsuite.

c. hex
        This folder contains three file types - coff, hex and map.
        These are files generated by the MPLAB® C30 toolsuite on build
        operation performed within MPLAB® IDE. The *.map file contains
        details on memory allocation for various variables, constants
        and dsPIC30F instructions specified in the source and library
        code. The *.hex file contains a binary file that may be
        programmed into the dsPIC30F device. The *.coff file contains
        a binary file that is used by MPLAB® IDE for simulation.

d. inc
        This folder contains Assembler include files useful in building this
        project. Device register and bit definitions are provided in
        the *.inc file that follows the device name. These files were provided
        with the MPLAB® C30 toolsuite.

e. src
        This folder contains all the C and Assembler source files (*.c,
        *.s) used in demonstrating the described example. This folder
        also contains a sub-folder named "obj" that stores compiled
        object files generated when the project is built.

f. design
        This folder contains files created by dsPIC Filter Design and
        dsPICworks Data Analysis and Design Software. Input signal files,
        output signal files and filter specifications have been provided
        here.

3. Suggested Development Resources:
-----------------------------------
        a. dsPICDEM™ 1.1 Development Board (See below)
        b. dsPIC30F6014A Digital Signal Controller Plug-In Module (See below)

4. Reconfiguring the project for a different dsPIC30F device:
-------------------------------------------------------------
The Project/Workspace can be easily reconfigured for any dsPIC30F device.
Please use the following general guidelines:
        a. Change device selection within MPLAB® IDE to a dsPIC30F device of
        your choice by using the following menu option:
        MPLAB IDE>>Configure>>Select Device

        b. Provide the correct device linker script and header file for your
        device. Device linker scripts and header files are available in your
        MPLAB® C30 installation folder under:
        Device Linker Script-
                YourDrive:>Program Files\Microchip\MPLAB C30\support\gld
        Device C Header file-
                YourDrive:>Program Files\Microchip\MPLAB C30\support\h
        Device ASM Include file-
                YourDrive:>Program Files\Microchip\MPLAB C30\support\inc

        c. Provide the appropriate path to your MPLAB C30 support file locations
        using the menu option:
        MPLAB IDE>>Project>>Build Options>>Project

        d. Chose the development board applicable to your device. Some options
        are provided below:
        - dsPICDEM™ 2 Development Board supports:
          30F2010, 30F2011, 30F2012, 30F3010, 30F3011, 30F3012, 30F3013,
          30F3014, 30F4011, 30F4012, 30F4013

        - dsPICDEM™ 1.1 Development Board supports:
          30F5013, 30F6010, 30F6011, 30F6012, 30F6013, 30F6014,
          30F6011A, 30F6012A, 30F6013A, 30F6014A

        - dsPICDEM™ MC1 Development Board supports:
          30F6010, 30F6010A, 30F5016

        e. Re-build the MPLAB® project using the menu option:
        MPLAB IDE>>Project>>Build All

        f. Download the hex file into the device and run.

5. Revision History :
---------------------
        09/30/2005 - Initial Release of the Code Example
   