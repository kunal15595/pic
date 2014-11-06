#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=astar/astar.c astar/astar_heap.c astar/astar_test.c astar/astar_thread.c astar/sys_time.c ../_AVIX/Cnfg/AVIXConfig.c Main.c master.c elb/ELB_I2C.c elb/ELB_ISR.c elb/ELB_LCD.c elb/ELB_OSC.c elb/ELB_PWM.c elb/ELB_Timer.c elb/ELB_UART.c elb/ELBv21_HardwareConfig.c imu/AMGPsensor.c imu/BMA150.c imu/BMP085.c imu/Config_Accel.c imu/Config_Gyro.c imu/Config_Mag.c imu/HMC5883.c imu/ITG3050.c motor/motor.c ping/ping.c servo/servo.c xbee/xbee.c ../sys_files/src/systemSetup.c ../_avix_tutorial/src/_tutoriallMain.c ../_avix_tutorial/src/tutorial01_RoundRobin.c ../_avix_tutorial/src/tutorial02_RoundRobin.c ../_avix_tutorial/src/tutorial03_Preemption.c ../_avix_tutorial/src/tutorial04_Timer.c ../_avix_tutorial/src/tutorial05_EventFlags.c ../_avix_tutorial/src/tutorial06_EventFlags.c ../_avix_tutorial/src/tutorial07_Messages.c ../_avix_tutorial/src/tutorial08_Pipes.c ../_avix_tutorial/src/tutorial09_Exchange.c imu/imu.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/astar/astar.o ${OBJECTDIR}/astar/astar_heap.o ${OBJECTDIR}/astar/astar_test.o ${OBJECTDIR}/astar/astar_thread.o ${OBJECTDIR}/astar/sys_time.o ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o ${OBJECTDIR}/Main.o ${OBJECTDIR}/master.o ${OBJECTDIR}/elb/ELB_I2C.o ${OBJECTDIR}/elb/ELB_ISR.o ${OBJECTDIR}/elb/ELB_LCD.o ${OBJECTDIR}/elb/ELB_OSC.o ${OBJECTDIR}/elb/ELB_PWM.o ${OBJECTDIR}/elb/ELB_Timer.o ${OBJECTDIR}/elb/ELB_UART.o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o ${OBJECTDIR}/imu/AMGPsensor.o ${OBJECTDIR}/imu/BMA150.o ${OBJECTDIR}/imu/BMP085.o ${OBJECTDIR}/imu/Config_Accel.o ${OBJECTDIR}/imu/Config_Gyro.o ${OBJECTDIR}/imu/Config_Mag.o ${OBJECTDIR}/imu/HMC5883.o ${OBJECTDIR}/imu/ITG3050.o ${OBJECTDIR}/motor/motor.o ${OBJECTDIR}/ping/ping.o ${OBJECTDIR}/servo/servo.o ${OBJECTDIR}/xbee/xbee.o ${OBJECTDIR}/_ext/699472203/systemSetup.o ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o ${OBJECTDIR}/imu/imu.o
POSSIBLE_DEPFILES=${OBJECTDIR}/astar/astar.o.d ${OBJECTDIR}/astar/astar_heap.o.d ${OBJECTDIR}/astar/astar_test.o.d ${OBJECTDIR}/astar/astar_thread.o.d ${OBJECTDIR}/astar/sys_time.o.d ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.d ${OBJECTDIR}/Main.o.d ${OBJECTDIR}/master.o.d ${OBJECTDIR}/elb/ELB_I2C.o.d ${OBJECTDIR}/elb/ELB_ISR.o.d ${OBJECTDIR}/elb/ELB_LCD.o.d ${OBJECTDIR}/elb/ELB_OSC.o.d ${OBJECTDIR}/elb/ELB_PWM.o.d ${OBJECTDIR}/elb/ELB_Timer.o.d ${OBJECTDIR}/elb/ELB_UART.o.d ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d ${OBJECTDIR}/imu/AMGPsensor.o.d ${OBJECTDIR}/imu/BMA150.o.d ${OBJECTDIR}/imu/BMP085.o.d ${OBJECTDIR}/imu/Config_Accel.o.d ${OBJECTDIR}/imu/Config_Gyro.o.d ${OBJECTDIR}/imu/Config_Mag.o.d ${OBJECTDIR}/imu/HMC5883.o.d ${OBJECTDIR}/imu/ITG3050.o.d ${OBJECTDIR}/motor/motor.o.d ${OBJECTDIR}/ping/ping.o.d ${OBJECTDIR}/servo/servo.o.d ${OBJECTDIR}/xbee/xbee.o.d ${OBJECTDIR}/_ext/699472203/systemSetup.o.d ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.d ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.d ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.d ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.d ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.d ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.d ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.d ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.d ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.d ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.d ${OBJECTDIR}/imu/imu.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/astar/astar.o ${OBJECTDIR}/astar/astar_heap.o ${OBJECTDIR}/astar/astar_test.o ${OBJECTDIR}/astar/astar_thread.o ${OBJECTDIR}/astar/sys_time.o ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o ${OBJECTDIR}/Main.o ${OBJECTDIR}/master.o ${OBJECTDIR}/elb/ELB_I2C.o ${OBJECTDIR}/elb/ELB_ISR.o ${OBJECTDIR}/elb/ELB_LCD.o ${OBJECTDIR}/elb/ELB_OSC.o ${OBJECTDIR}/elb/ELB_PWM.o ${OBJECTDIR}/elb/ELB_Timer.o ${OBJECTDIR}/elb/ELB_UART.o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o ${OBJECTDIR}/imu/AMGPsensor.o ${OBJECTDIR}/imu/BMA150.o ${OBJECTDIR}/imu/BMP085.o ${OBJECTDIR}/imu/Config_Accel.o ${OBJECTDIR}/imu/Config_Gyro.o ${OBJECTDIR}/imu/Config_Mag.o ${OBJECTDIR}/imu/HMC5883.o ${OBJECTDIR}/imu/ITG3050.o ${OBJECTDIR}/motor/motor.o ${OBJECTDIR}/ping/ping.o ${OBJECTDIR}/servo/servo.o ${OBJECTDIR}/xbee/xbee.o ${OBJECTDIR}/_ext/699472203/systemSetup.o ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o ${OBJECTDIR}/imu/imu.o

# Source Files
SOURCEFILES=astar/astar.c astar/astar_heap.c astar/astar_test.c astar/astar_thread.c astar/sys_time.c ../_AVIX/Cnfg/AVIXConfig.c Main.c master.c elb/ELB_I2C.c elb/ELB_ISR.c elb/ELB_LCD.c elb/ELB_OSC.c elb/ELB_PWM.c elb/ELB_Timer.c elb/ELB_UART.c elb/ELBv21_HardwareConfig.c imu/AMGPsensor.c imu/BMA150.c imu/BMP085.c imu/Config_Accel.c imu/Config_Gyro.c imu/Config_Mag.c imu/HMC5883.c imu/ITG3050.c motor/motor.c ping/ping.c servo/servo.c xbee/xbee.c ../sys_files/src/systemSetup.c ../_avix_tutorial/src/_tutoriallMain.c ../_avix_tutorial/src/tutorial01_RoundRobin.c ../_avix_tutorial/src/tutorial02_RoundRobin.c ../_avix_tutorial/src/tutorial03_Preemption.c ../_avix_tutorial/src/tutorial04_Timer.c ../_avix_tutorial/src/tutorial05_EventFlags.c ../_avix_tutorial/src/tutorial06_EventFlags.c ../_avix_tutorial/src/tutorial07_Messages.c ../_avix_tutorial/src/tutorial08_Pipes.c ../_avix_tutorial/src/tutorial09_Exchange.c imu/imu.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ256GB210
MP_LINKER_FILE_OPTION=,-Tp24FJ256GB210.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/astar/astar.o: astar/astar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar.o.d 
	@${RM} ${OBJECTDIR}/astar/astar.o.ok ${OBJECTDIR}/astar/astar.o.err 
	@${RM} ${OBJECTDIR}/astar/astar.o 
	@${FIXDEPS} "${OBJECTDIR}/astar/astar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/astar/astar.o.d" -o ${OBJECTDIR}/astar/astar.o astar/astar.c     -fno-pcc-struct-return
	
${OBJECTDIR}/astar/astar_heap.o: astar/astar_heap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar_heap.o.d 
	@${RM} ${OBJECTDIR}/astar/astar_heap.o.ok ${OBJECTDIR}/astar/astar_heap.o.err 
	@${RM} ${OBJECTDIR}/astar/astar_heap.o 
	@${FIXDEPS} "${OBJECTDIR}/astar/astar_heap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/astar/astar_heap.o.d" -o ${OBJECTDIR}/astar/astar_heap.o astar/astar_heap.c     -fno-pcc-struct-return
	
${OBJECTDIR}/astar/astar_test.o: astar/astar_test.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar_test.o.d 
	@${RM} ${OBJECTDIR}/astar/astar_test.o.ok ${OBJECTDIR}/astar/astar_test.o.err 
	@${RM} ${OBJECTDIR}/astar/astar_test.o 
	@${FIXDEPS} "${OBJECTDIR}/astar/astar_test.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/astar/astar_test.o.d" -o ${OBJECTDIR}/astar/astar_test.o astar/astar_test.c     -fno-pcc-struct-return
	
${OBJECTDIR}/astar/astar_thread.o: astar/astar_thread.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar_thread.o.d 
	@${RM} ${OBJECTDIR}/astar/astar_thread.o.ok ${OBJECTDIR}/astar/astar_thread.o.err 
	@${RM} ${OBJECTDIR}/astar/astar_thread.o 
	@${FIXDEPS} "${OBJECTDIR}/astar/astar_thread.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/astar/astar_thread.o.d" -o ${OBJECTDIR}/astar/astar_thread.o astar/astar_thread.c     -fno-pcc-struct-return
	
${OBJECTDIR}/astar/sys_time.o: astar/sys_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/sys_time.o.d 
	@${RM} ${OBJECTDIR}/astar/sys_time.o.ok ${OBJECTDIR}/astar/sys_time.o.err 
	@${RM} ${OBJECTDIR}/astar/sys_time.o 
	@${FIXDEPS} "${OBJECTDIR}/astar/sys_time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/astar/sys_time.o.d" -o ${OBJECTDIR}/astar/sys_time.o astar/sys_time.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1950464967/AVIXConfig.o: ../_AVIX/Cnfg/AVIXConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1950464967 
	@${RM} ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.ok ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.err 
	@${RM} ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.d" -o ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o ../_AVIX/Cnfg/AVIXConfig.c     -fno-pcc-struct-return
	
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o.ok ${OBJECTDIR}/Main.o.err 
	@${RM} ${OBJECTDIR}/Main.o 
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/Main.o.d" -o ${OBJECTDIR}/Main.o Main.c     -fno-pcc-struct-return
	
${OBJECTDIR}/master.o: master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/master.o.d 
	@${RM} ${OBJECTDIR}/master.o.ok ${OBJECTDIR}/master.o.err 
	@${RM} ${OBJECTDIR}/master.o 
	@${FIXDEPS} "${OBJECTDIR}/master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/master.o.d" -o ${OBJECTDIR}/master.o master.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_I2C.o: elb/ELB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o.ok ${OBJECTDIR}/elb/ELB_I2C.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_I2C.o.d" -o ${OBJECTDIR}/elb/ELB_I2C.o elb/ELB_I2C.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_ISR.o: elb/ELB_ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o.ok ${OBJECTDIR}/elb/ELB_ISR.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_ISR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_ISR.o.d" -o ${OBJECTDIR}/elb/ELB_ISR.o elb/ELB_ISR.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_LCD.o: elb/ELB_LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o.ok ${OBJECTDIR}/elb/ELB_LCD.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_LCD.o.d" -o ${OBJECTDIR}/elb/ELB_LCD.o elb/ELB_LCD.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_OSC.o: elb/ELB_OSC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o.ok ${OBJECTDIR}/elb/ELB_OSC.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_OSC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_OSC.o.d" -o ${OBJECTDIR}/elb/ELB_OSC.o elb/ELB_OSC.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_PWM.o: elb/ELB_PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o.ok ${OBJECTDIR}/elb/ELB_PWM.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_PWM.o.d" -o ${OBJECTDIR}/elb/ELB_PWM.o elb/ELB_PWM.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_Timer.o: elb/ELB_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o.ok ${OBJECTDIR}/elb/ELB_Timer.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_Timer.o.d" -o ${OBJECTDIR}/elb/ELB_Timer.o elb/ELB_Timer.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_UART.o: elb/ELB_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o.ok ${OBJECTDIR}/elb/ELB_UART.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_UART.o.d" -o ${OBJECTDIR}/elb/ELB_UART.o elb/ELB_UART.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELBv21_HardwareConfig.o: elb/ELBv21_HardwareConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.ok ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.err 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d" -o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o elb/ELBv21_HardwareConfig.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/AMGPsensor.o: imu/AMGPsensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o.d 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o.ok ${OBJECTDIR}/imu/AMGPsensor.o.err 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/AMGPsensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/AMGPsensor.o.d" -o ${OBJECTDIR}/imu/AMGPsensor.o imu/AMGPsensor.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/BMA150.o: imu/BMA150.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMA150.o.d 
	@${RM} ${OBJECTDIR}/imu/BMA150.o.ok ${OBJECTDIR}/imu/BMA150.o.err 
	@${RM} ${OBJECTDIR}/imu/BMA150.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/BMA150.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/BMA150.o.d" -o ${OBJECTDIR}/imu/BMA150.o imu/BMA150.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/BMP085.o: imu/BMP085.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMP085.o.d 
	@${RM} ${OBJECTDIR}/imu/BMP085.o.ok ${OBJECTDIR}/imu/BMP085.o.err 
	@${RM} ${OBJECTDIR}/imu/BMP085.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/BMP085.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/BMP085.o.d" -o ${OBJECTDIR}/imu/BMP085.o imu/BMP085.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/Config_Accel.o: imu/Config_Accel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o.ok ${OBJECTDIR}/imu/Config_Accel.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Accel.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/Config_Accel.o.d" -o ${OBJECTDIR}/imu/Config_Accel.o imu/Config_Accel.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/Config_Gyro.o: imu/Config_Gyro.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o.ok ${OBJECTDIR}/imu/Config_Gyro.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Gyro.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/Config_Gyro.o.d" -o ${OBJECTDIR}/imu/Config_Gyro.o imu/Config_Gyro.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/Config_Mag.o: imu/Config_Mag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o.ok ${OBJECTDIR}/imu/Config_Mag.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Mag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/Config_Mag.o.d" -o ${OBJECTDIR}/imu/Config_Mag.o imu/Config_Mag.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/HMC5883.o: imu/HMC5883.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o.d 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o.ok ${OBJECTDIR}/imu/HMC5883.o.err 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/HMC5883.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/HMC5883.o.d" -o ${OBJECTDIR}/imu/HMC5883.o imu/HMC5883.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/ITG3050.o: imu/ITG3050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o.d 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o.ok ${OBJECTDIR}/imu/ITG3050.o.err 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/ITG3050.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/ITG3050.o.d" -o ${OBJECTDIR}/imu/ITG3050.o imu/ITG3050.c     -fno-pcc-struct-return
	
${OBJECTDIR}/motor/motor.o: motor/motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/motor 
	@${RM} ${OBJECTDIR}/motor/motor.o.d 
	@${RM} ${OBJECTDIR}/motor/motor.o.ok ${OBJECTDIR}/motor/motor.o.err 
	@${RM} ${OBJECTDIR}/motor/motor.o 
	@${FIXDEPS} "${OBJECTDIR}/motor/motor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/motor/motor.o.d" -o ${OBJECTDIR}/motor/motor.o motor/motor.c     -fno-pcc-struct-return
	
${OBJECTDIR}/ping/ping.o: ping/ping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ping 
	@${RM} ${OBJECTDIR}/ping/ping.o.d 
	@${RM} ${OBJECTDIR}/ping/ping.o.ok ${OBJECTDIR}/ping/ping.o.err 
	@${RM} ${OBJECTDIR}/ping/ping.o 
	@${FIXDEPS} "${OBJECTDIR}/ping/ping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/ping/ping.o.d" -o ${OBJECTDIR}/ping/ping.o ping/ping.c     -fno-pcc-struct-return
	
${OBJECTDIR}/servo/servo.o: servo/servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/servo 
	@${RM} ${OBJECTDIR}/servo/servo.o.d 
	@${RM} ${OBJECTDIR}/servo/servo.o.ok ${OBJECTDIR}/servo/servo.o.err 
	@${RM} ${OBJECTDIR}/servo/servo.o 
	@${FIXDEPS} "${OBJECTDIR}/servo/servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/servo/servo.o.d" -o ${OBJECTDIR}/servo/servo.o servo/servo.c     -fno-pcc-struct-return
	
${OBJECTDIR}/xbee/xbee.o: xbee/xbee.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/xbee 
	@${RM} ${OBJECTDIR}/xbee/xbee.o.d 
	@${RM} ${OBJECTDIR}/xbee/xbee.o.ok ${OBJECTDIR}/xbee/xbee.o.err 
	@${RM} ${OBJECTDIR}/xbee/xbee.o 
	@${FIXDEPS} "${OBJECTDIR}/xbee/xbee.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/xbee/xbee.o.d" -o ${OBJECTDIR}/xbee/xbee.o xbee/xbee.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/699472203/systemSetup.o: ../sys_files/src/systemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/699472203 
	@${RM} ${OBJECTDIR}/_ext/699472203/systemSetup.o.d 
	@${RM} ${OBJECTDIR}/_ext/699472203/systemSetup.o.ok ${OBJECTDIR}/_ext/699472203/systemSetup.o.err 
	@${RM} ${OBJECTDIR}/_ext/699472203/systemSetup.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/699472203/systemSetup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/699472203/systemSetup.o.d" -o ${OBJECTDIR}/_ext/699472203/systemSetup.o ../sys_files/src/systemSetup.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o: ../_avix_tutorial/src/_tutoriallMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.ok ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.d" -o ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o ../_avix_tutorial/src/_tutoriallMain.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o: ../_avix_tutorial/src/tutorial01_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o ../_avix_tutorial/src/tutorial01_RoundRobin.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o: ../_avix_tutorial/src/tutorial02_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o ../_avix_tutorial/src/tutorial02_RoundRobin.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o: ../_avix_tutorial/src/tutorial03_Preemption.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o ../_avix_tutorial/src/tutorial03_Preemption.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o: ../_avix_tutorial/src/tutorial04_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o ../_avix_tutorial/src/tutorial04_Timer.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o: ../_avix_tutorial/src/tutorial05_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o ../_avix_tutorial/src/tutorial05_EventFlags.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o: ../_avix_tutorial/src/tutorial06_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o ../_avix_tutorial/src/tutorial06_EventFlags.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o: ../_avix_tutorial/src/tutorial07_Messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o ../_avix_tutorial/src/tutorial07_Messages.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o: ../_avix_tutorial/src/tutorial08_Pipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o ../_avix_tutorial/src/tutorial08_Pipes.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o: ../_avix_tutorial/src/tutorial09_Exchange.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o ../_avix_tutorial/src/tutorial09_Exchange.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/imu.o: imu/imu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/imu.o.d 
	@${RM} ${OBJECTDIR}/imu/imu.o.ok ${OBJECTDIR}/imu/imu.o.err 
	@${RM} ${OBJECTDIR}/imu/imu.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/imu.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/imu.o.d" -o ${OBJECTDIR}/imu/imu.o imu/imu.c     -fno-pcc-struct-return
	
else
${OBJECTDIR}/astar/astar.o: astar/astar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar.o.d 
	@${RM} ${OBJECTDIR}/astar/astar.o.ok ${OBJECTDIR}/astar/astar.o.err 
	@${RM} ${OBJECTDIR}/astar/astar.o 
	@${FIXDEPS} "${OBJECTDIR}/astar/astar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/astar/astar.o.d" -o ${OBJECTDIR}/astar/astar.o astar/astar.c     -fno-pcc-struct-return
	
${OBJECTDIR}/astar/astar_heap.o: astar/astar_heap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar_heap.o.d 
	@${RM} ${OBJECTDIR}/astar/astar_heap.o.ok ${OBJECTDIR}/astar/astar_heap.o.err 
	@${RM} ${OBJECTDIR}/astar/astar_heap.o 
	@${FIXDEPS} "${OBJECTDIR}/astar/astar_heap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/astar/astar_heap.o.d" -o ${OBJECTDIR}/astar/astar_heap.o astar/astar_heap.c     -fno-pcc-struct-return
	
${OBJECTDIR}/astar/astar_test.o: astar/astar_test.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar_test.o.d 
	@${RM} ${OBJECTDIR}/astar/astar_test.o.ok ${OBJECTDIR}/astar/astar_test.o.err 
	@${RM} ${OBJECTDIR}/astar/astar_test.o 
	@${FIXDEPS} "${OBJECTDIR}/astar/astar_test.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/astar/astar_test.o.d" -o ${OBJECTDIR}/astar/astar_test.o astar/astar_test.c     -fno-pcc-struct-return
	
${OBJECTDIR}/astar/astar_thread.o: astar/astar_thread.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar_thread.o.d 
	@${RM} ${OBJECTDIR}/astar/astar_thread.o.ok ${OBJECTDIR}/astar/astar_thread.o.err 
	@${RM} ${OBJECTDIR}/astar/astar_thread.o 
	@${FIXDEPS} "${OBJECTDIR}/astar/astar_thread.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/astar/astar_thread.o.d" -o ${OBJECTDIR}/astar/astar_thread.o astar/astar_thread.c     -fno-pcc-struct-return
	
${OBJECTDIR}/astar/sys_time.o: astar/sys_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/sys_time.o.d 
	@${RM} ${OBJECTDIR}/astar/sys_time.o.ok ${OBJECTDIR}/astar/sys_time.o.err 
	@${RM} ${OBJECTDIR}/astar/sys_time.o 
	@${FIXDEPS} "${OBJECTDIR}/astar/sys_time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/astar/sys_time.o.d" -o ${OBJECTDIR}/astar/sys_time.o astar/sys_time.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1950464967/AVIXConfig.o: ../_AVIX/Cnfg/AVIXConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1950464967 
	@${RM} ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.ok ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.err 
	@${RM} ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/1950464967/AVIXConfig.o.d" -o ${OBJECTDIR}/_ext/1950464967/AVIXConfig.o ../_AVIX/Cnfg/AVIXConfig.c     -fno-pcc-struct-return
	
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o.ok ${OBJECTDIR}/Main.o.err 
	@${RM} ${OBJECTDIR}/Main.o 
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/Main.o.d" -o ${OBJECTDIR}/Main.o Main.c     -fno-pcc-struct-return
	
${OBJECTDIR}/master.o: master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/master.o.d 
	@${RM} ${OBJECTDIR}/master.o.ok ${OBJECTDIR}/master.o.err 
	@${RM} ${OBJECTDIR}/master.o 
	@${FIXDEPS} "${OBJECTDIR}/master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/master.o.d" -o ${OBJECTDIR}/master.o master.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_I2C.o: elb/ELB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o.ok ${OBJECTDIR}/elb/ELB_I2C.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_I2C.o.d" -o ${OBJECTDIR}/elb/ELB_I2C.o elb/ELB_I2C.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_ISR.o: elb/ELB_ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o.ok ${OBJECTDIR}/elb/ELB_ISR.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_ISR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_ISR.o.d" -o ${OBJECTDIR}/elb/ELB_ISR.o elb/ELB_ISR.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_LCD.o: elb/ELB_LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o.ok ${OBJECTDIR}/elb/ELB_LCD.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_LCD.o.d" -o ${OBJECTDIR}/elb/ELB_LCD.o elb/ELB_LCD.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_OSC.o: elb/ELB_OSC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o.ok ${OBJECTDIR}/elb/ELB_OSC.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_OSC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_OSC.o.d" -o ${OBJECTDIR}/elb/ELB_OSC.o elb/ELB_OSC.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_PWM.o: elb/ELB_PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o.ok ${OBJECTDIR}/elb/ELB_PWM.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_PWM.o.d" -o ${OBJECTDIR}/elb/ELB_PWM.o elb/ELB_PWM.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_Timer.o: elb/ELB_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o.ok ${OBJECTDIR}/elb/ELB_Timer.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_Timer.o.d" -o ${OBJECTDIR}/elb/ELB_Timer.o elb/ELB_Timer.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELB_UART.o: elb/ELB_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o.ok ${OBJECTDIR}/elb/ELB_UART.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELB_UART.o.d" -o ${OBJECTDIR}/elb/ELB_UART.o elb/ELB_UART.c     -fno-pcc-struct-return
	
${OBJECTDIR}/elb/ELBv21_HardwareConfig.o: elb/ELBv21_HardwareConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.ok ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.err 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d" -o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o elb/ELBv21_HardwareConfig.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/AMGPsensor.o: imu/AMGPsensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o.d 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o.ok ${OBJECTDIR}/imu/AMGPsensor.o.err 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/AMGPsensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/AMGPsensor.o.d" -o ${OBJECTDIR}/imu/AMGPsensor.o imu/AMGPsensor.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/BMA150.o: imu/BMA150.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMA150.o.d 
	@${RM} ${OBJECTDIR}/imu/BMA150.o.ok ${OBJECTDIR}/imu/BMA150.o.err 
	@${RM} ${OBJECTDIR}/imu/BMA150.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/BMA150.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/BMA150.o.d" -o ${OBJECTDIR}/imu/BMA150.o imu/BMA150.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/BMP085.o: imu/BMP085.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMP085.o.d 
	@${RM} ${OBJECTDIR}/imu/BMP085.o.ok ${OBJECTDIR}/imu/BMP085.o.err 
	@${RM} ${OBJECTDIR}/imu/BMP085.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/BMP085.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/BMP085.o.d" -o ${OBJECTDIR}/imu/BMP085.o imu/BMP085.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/Config_Accel.o: imu/Config_Accel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o.ok ${OBJECTDIR}/imu/Config_Accel.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Accel.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/Config_Accel.o.d" -o ${OBJECTDIR}/imu/Config_Accel.o imu/Config_Accel.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/Config_Gyro.o: imu/Config_Gyro.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o.ok ${OBJECTDIR}/imu/Config_Gyro.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Gyro.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/Config_Gyro.o.d" -o ${OBJECTDIR}/imu/Config_Gyro.o imu/Config_Gyro.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/Config_Mag.o: imu/Config_Mag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o.ok ${OBJECTDIR}/imu/Config_Mag.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Mag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/Config_Mag.o.d" -o ${OBJECTDIR}/imu/Config_Mag.o imu/Config_Mag.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/HMC5883.o: imu/HMC5883.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o.d 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o.ok ${OBJECTDIR}/imu/HMC5883.o.err 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/HMC5883.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/HMC5883.o.d" -o ${OBJECTDIR}/imu/HMC5883.o imu/HMC5883.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/ITG3050.o: imu/ITG3050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o.d 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o.ok ${OBJECTDIR}/imu/ITG3050.o.err 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/ITG3050.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/ITG3050.o.d" -o ${OBJECTDIR}/imu/ITG3050.o imu/ITG3050.c     -fno-pcc-struct-return
	
${OBJECTDIR}/motor/motor.o: motor/motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/motor 
	@${RM} ${OBJECTDIR}/motor/motor.o.d 
	@${RM} ${OBJECTDIR}/motor/motor.o.ok ${OBJECTDIR}/motor/motor.o.err 
	@${RM} ${OBJECTDIR}/motor/motor.o 
	@${FIXDEPS} "${OBJECTDIR}/motor/motor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/motor/motor.o.d" -o ${OBJECTDIR}/motor/motor.o motor/motor.c     -fno-pcc-struct-return
	
${OBJECTDIR}/ping/ping.o: ping/ping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ping 
	@${RM} ${OBJECTDIR}/ping/ping.o.d 
	@${RM} ${OBJECTDIR}/ping/ping.o.ok ${OBJECTDIR}/ping/ping.o.err 
	@${RM} ${OBJECTDIR}/ping/ping.o 
	@${FIXDEPS} "${OBJECTDIR}/ping/ping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/ping/ping.o.d" -o ${OBJECTDIR}/ping/ping.o ping/ping.c     -fno-pcc-struct-return
	
${OBJECTDIR}/servo/servo.o: servo/servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/servo 
	@${RM} ${OBJECTDIR}/servo/servo.o.d 
	@${RM} ${OBJECTDIR}/servo/servo.o.ok ${OBJECTDIR}/servo/servo.o.err 
	@${RM} ${OBJECTDIR}/servo/servo.o 
	@${FIXDEPS} "${OBJECTDIR}/servo/servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/servo/servo.o.d" -o ${OBJECTDIR}/servo/servo.o servo/servo.c     -fno-pcc-struct-return
	
${OBJECTDIR}/xbee/xbee.o: xbee/xbee.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/xbee 
	@${RM} ${OBJECTDIR}/xbee/xbee.o.d 
	@${RM} ${OBJECTDIR}/xbee/xbee.o.ok ${OBJECTDIR}/xbee/xbee.o.err 
	@${RM} ${OBJECTDIR}/xbee/xbee.o 
	@${FIXDEPS} "${OBJECTDIR}/xbee/xbee.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/xbee/xbee.o.d" -o ${OBJECTDIR}/xbee/xbee.o xbee/xbee.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/699472203/systemSetup.o: ../sys_files/src/systemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/699472203 
	@${RM} ${OBJECTDIR}/_ext/699472203/systemSetup.o.d 
	@${RM} ${OBJECTDIR}/_ext/699472203/systemSetup.o.ok ${OBJECTDIR}/_ext/699472203/systemSetup.o.err 
	@${RM} ${OBJECTDIR}/_ext/699472203/systemSetup.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/699472203/systemSetup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/699472203/systemSetup.o.d" -o ${OBJECTDIR}/_ext/699472203/systemSetup.o ../sys_files/src/systemSetup.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o: ../_avix_tutorial/src/_tutoriallMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.ok ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o.d" -o ${OBJECTDIR}/_ext/2107323874/_tutoriallMain.o ../_avix_tutorial/src/_tutoriallMain.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o: ../_avix_tutorial/src/tutorial01_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial01_RoundRobin.o ../_avix_tutorial/src/tutorial01_RoundRobin.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o: ../_avix_tutorial/src/tutorial02_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial02_RoundRobin.o ../_avix_tutorial/src/tutorial02_RoundRobin.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o: ../_avix_tutorial/src/tutorial03_Preemption.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial03_Preemption.o ../_avix_tutorial/src/tutorial03_Preemption.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o: ../_avix_tutorial/src/tutorial04_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial04_Timer.o ../_avix_tutorial/src/tutorial04_Timer.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o: ../_avix_tutorial/src/tutorial05_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial05_EventFlags.o ../_avix_tutorial/src/tutorial05_EventFlags.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o: ../_avix_tutorial/src/tutorial06_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial06_EventFlags.o ../_avix_tutorial/src/tutorial06_EventFlags.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o: ../_avix_tutorial/src/tutorial07_Messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial07_Messages.o ../_avix_tutorial/src/tutorial07_Messages.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o: ../_avix_tutorial/src/tutorial08_Pipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial08_Pipes.o ../_avix_tutorial/src/tutorial08_Pipes.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o: ../_avix_tutorial/src/tutorial09_Exchange.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2107323874 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.d 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.ok ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.err 
	@${RM} ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o.d" -o ${OBJECTDIR}/_ext/2107323874/tutorial09_Exchange.o ../_avix_tutorial/src/tutorial09_Exchange.c     -fno-pcc-struct-return
	
${OBJECTDIR}/imu/imu.o: imu/imu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/imu.o.d 
	@${RM} ${OBJECTDIR}/imu/imu.o.ok ${OBJECTDIR}/imu/imu.o.err 
	@${RM} ${OBJECTDIR}/imu/imu.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/imu.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../_AVIX/Interface" -I"../_AVIX/Utilities/Interface" -I"elb" -I"astar" -I"imu" -I"motor" -I"ping" -I"servo" -I"xbee" -I"xc_32" -MMD -MF "${OBJECTDIR}/imu/imu.o.d" -o ${OBJECTDIR}/imu/imu.o imu/imu.c     -fno-pcc-struct-return
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../_AVIX/Lib/AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   ..\_AVIX\Lib\AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a      -Wl,--defsym=__MPLAB_BUILD=1,--heap=16000,-L"../_avix_tutorial/_mplab_project_files",-L".",-Map="${DISTDIR}/${PROJECTNAME}.mobile_robot.X.${IMAGE_TYPE}.map"$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../_AVIX/Lib/AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   ..\_AVIX\Lib\AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a      -Wl,--defsym=__MPLAB_BUILD=1,--heap=16000,-L"../_avix_tutorial/_mplab_project_files",-L".",-Map="${DISTDIR}/${PROJECTNAME}.mobile_robot.X.${IMAGE_TYPE}.map"$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
