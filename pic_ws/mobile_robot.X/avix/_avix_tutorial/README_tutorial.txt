 

                                             AVIX Tutorial
==================================================================================================
Description:
--------------------------------------------------------------------------------------------------
Directory _avix_tutorial contains a tutorial application illustrating many of the AVIX mechanisms.

Advised is to also install  the AVIX RTOS viewer (available for MPLAB8x only) and activate this in 
the debugger.  How to do  this can be  found in  the AVIX RTOS viewer manual,  which is  installed  
together with  the RTOS viewer executable. The AVIX RTOS viewer  provides a  detailed  overview of 
the current status  of all AVIX objects  like threads, pipes,  messages, ... both  when running in 
the simulator and on hardware.

>>> The  tutorial consists of 9 small  programs, each illustrating  specific features  of the AVIX 
    RTOS. The applicable functionality is selected by giving the value 1..9 to variable tutorialId 
    present in file _tutorialMain.c

>>> A detailed description about the structure of this tutorial application can be found in 
    AVIX_Tutorial.pdf which can be found in the _AVIX\Doc directory.

NOTE: WHEN USING A FREE  DEMO DISTRIBUTION,  THE APPLICATION WILL RUN FOR A MAXIMUM  OF 30 MINUTES
      AFTER WHICH IT WILL STOP. THIS LIMITATION IS BUILT INTO THE AVIX FREE DEMO DISTRIBUTION!

--------------------------------------------------------------------------------------------------
Hardware environment:
--------------------------------------------------------------------------------------------------
The tutorial  project is  preconfigured for the ICD3 debugger. When using another debugger, select 
this in MPLAB once the project is opened.

--------------------------------------------------------------------------------------------------
MPLAB simulator:
--------------------------------------------------------------------------------------------------
A number  of controllers  are fully  supported by  the MPLAB simulator. The simulator does however
contain so many  issues that  in most  cases the application can not run reliably. Therefore it is
strongly advised not to use the simulator.

--------------------------------------------------------------------------------------------------


=====================================
How to run the tutorial with MPLAB8x?
=====================================
1: Open <install directory>\_avix_tutorial\_mplab_project_files\tutorialAVIX.mcw
2: Build the project
3: Flash the application to the controller
4: Run the application

Observe the global variables manipulated by the tutorial application. Read AVIX_Tutorial.pdf for a
detailed explanation.




===================================
How to run the tutorial with MPLABX
===================================
1: Import the MPLAB8x project file either from the MPLABX opening  screen or from the import  menu 
   entry in the MPLABX file menu.
   Project file: <install directory>\_avix_tutorial\_mplab_project_files\tutorialAVIX.mcp
2: Build the project
3: Flash the application to the controller
4: Run the application

Observe the global variables manipulated by the tutorial application. Read AVIX_Tutorial.pdf for a
detailed explanation.


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                      .----------------------------------------------------.
                      |                     AVIX-RT                        |
                      |----------------------------------------------------|
                      |web:     www.avix-rt.com                            |
                      |e-mail:  info@avix-rt.com        (general inquiries)|
                      |         support@avix-rt.com     (support questions)|
                      |phone:   +31(0)615285177                            |
                      |address: AVIX-RT                                    |
                      |         Maisveld 84                                |
                      |         5236 VC  's-Hertogenbosch                  |
                      |         The Netherlands                            |
                      `----------------------------------------------------'

==================================================================================================
                         AVIX-RT © 2006-2012, All Rights Reserved
==================================================================================================

