/*-------------------------------------------------------------------------
 *                                 Main.c                                 *
 * Copyright Theta Engineering, Costa Mesa CA, 2014  All Rights Reserved  *
 *------------------------------------------------------------------------*

 This module demonstrates the Trajectory interface. It is implemented for
 Microchip dsPIC33, however the Trajectory module itself is device-independent
 and can run on any platform with 16- and 32-bit integer types and a compliant
 C compiler.
 */

#include <xc.h>
#include "Trajectory.h"

// DSPIC33EP512GM304 Configuration Bit Settings:
// FGS
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GCP = OFF                // General Segment Code-Protect bit (General Segment Code protect is disabled)
// FOSCSEL
#pragma config FNOSC = FRCPLL           // Initial Oscillator Source Selection Bits (Primary Oscillator (XT, HS, EC) with PLL)
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)
// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary Oscillator disabled)
#pragma config OSCIOFNC = ON            // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config IOL1WAY = ON             // Peripheral pin select configuration (Allow only one reconfiguration)
#pragma config FCKSM = CSDCMD           // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)
// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler Bits (1:32,768)
#pragma config WDTPRE = PR128           // Watchdog Timer Prescaler bit (1:128)
#pragma config PLLKEN = ON              // PLL Lock Wait Enable bit (Clock switch to PLL source will wait until the PLL lock signal is valid.)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable bit (Watchdog timer always enabled)
#pragma config BOREN = ON               // Brown-out Reset (BOR) Detection Enable bit (BOR is enabled)
#pragma config ALTI2C1 = OFF            // Alternate I2C pins for I2C1 (SDA1/SCK1 pins are selected as the I/O pins for I2C1)
#pragma config ALTI2C2 = OFF            // Alternate I2C pins for I2C2 (SDA2/SCK2 pins are selected as the I/O pins for I2C2)
// FICD
#pragma config ICS = PGD2               // ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
// IOCON locks
#pragma config PWMLOCK = OFF            // PWMLOCK bit (PWM lock disabled)

// System oscillator frequency:
#define OSC_FREQ        (79227500L)     //Oscillator frequency
#define FCY             (OSC_FREQ/2)    //CPU clock frequency
#define FP              (OSC_FREQ/2)    //Peripherals clock frequency

int main()
{
    tTRAJECTORY uTrajectory;
    uint16_t nPos;

    //Oscillator Control Register:
    OSCCONbits.COSC = 1; //Current Oscillator Selection bits
    OSCCONbits.NOSC = 1; //New Oscillator Selection bits
    OSCCONbits.CLKLOCK = 1; //Clock Lock Enable bit
    //1 = Clock switching is disabled, system clock source is locked
    //0 = Clock switching is enabled, system clock source may be modified by
    //    clock switching
    OSCCONbits.IOLOCK = 0; /*Peripheral Pin Select (PPS) Lock bit*/
    //1 = Peripheral Pin Select is locked. Writes to Peripheral Pin Select
    //    registers are not allowed.
    //0 = Peripheral Pin Select is not locked. Writes to Peripheral Pin Select
    //    registers are allowed.
    OSCCONbits.OSWEN = 0; //Oscillator Switch Enable bit
    //1 = Request oscillator switch to selection specified by the NOSC<2:0> bits
    //0 = Oscillator switch is complete

    //Clock Divisor Register:
    CLKDIVbits.ROI = 0; //Recover on Interrupt bit
    //1 = Interrupts will clear the DOZEN bit and the processor clock, and the
    //    peripheral clock ratio is set to 1:1
    //0 = Interrupts have no effect on the DOZEN bit
    CLKDIVbits.DOZE = 0; //Processor Clock Reduction Select bits
    CLKDIVbits.DOZEN = 0; //Doze Mode Enable bit
    CLKDIVbits.FRCDIV = 0; //Internal Fast RC Oscillator Post scaler bits
    CLKDIVbits.PLLPOST = 1; //PLL VCO Output Divider Select bits (N2)
    CLKDIVbits.PLLPRE = 0; //PLL Phase Detector Input Divider Select bits (N1)
    PLLFBDbits.PLLDIV = 84; //PLL Feedback Divisor Register (M)

    // T6 Timer:
    T6CONbits.TON = 0; //Make sure timer module is off.
    T6CONbits.TCKPS = 1; //1 = divide by 8
    T6CONbits.T32 = 0; //Use 16-bit timer.
    T6CONbits.TCS = 0; //Select internal clock as clock source
    PR6 = (FP / (8 * 1000)) - 1; //Calculate preload for 1kHz frequency
    TMR6 = 0; //Clear timer
    IPC11bits.T6IP = 4; //Set interrupt priority
    IFS2bits.T6IF = 0; //Clear interrupt flag
    IEC2bits.T6IE = 0; //Enable interrupt.
    T6CONbits.TON = 1; //Start timer.


    // Initialize Trajectory:
    TrajectoryInit(&uTrajectory,
        10000,                      // Steady velocity, in counts per second
        512,                        // Acceleration, in 1/65536 counts per ms^2
        512                         // Deceleration, in 1/65536 counts per ms^2
    );

    // Begin a seek:
    TrajectorySeek(&uTrajectory, 30000, FORWARD);

    while (1)
    {
        if (IFS2bits.T6IF == 0)     // Wait for interrupt
            continue;
        IFS2bits.T6IF = 0;          // Clear interrupt flag

        // Obtain the trajectory real-time position:
        nPos = TrajectoryUpdate(&uTrajectory);

        // Insert motion control using nPos here ...
    }
}
