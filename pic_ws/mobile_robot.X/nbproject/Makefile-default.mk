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
SOURCEFILES_QUOTED_IF_SPACED=astar/astar_heap.c astar/astar.c avix/samples/_tutoriallMain.c avix/samples/tutorial01_RoundRobin.c avix/samples/tutorial02_RoundRobin.c avix/samples/tutorial03_Preemption.c avix/samples/tutorial04_Timer.c avix/samples/tutorial05_EventFlags.c avix/samples/tutorial06_EventFlags.c avix/samples/tutorial07_Messages.c avix/samples/tutorial08_Pipes.c avix/samples/tutorial09_Exchange.c avix/Cnfg/AVIXConfig.c avix/Cnfg/systemSetup.c elb/ELB_I2C.c elb/ELB_ISR.c elb/ELB_LCD.c elb/ELB_OSC.c elb/ELB_Timer.c elb/ELB_UART.c elb/ELBv21_HardwareConfig.c elb/ELB_PWM.c imu/AMGPsensor.c imu/BMA150.c imu/BMP085.c imu/Config_Accel.c imu/Config_Gyro.c imu/Config_Mag.c imu/HMC5883.c imu/ITG3050.c imu/imu_main.c motor/motor.c ping/ping.c servo/servo.c xbee/xbee.c Main.c astar/sys_time.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/astar/astar_heap.o ${OBJECTDIR}/astar/astar.o ${OBJECTDIR}/avix/samples/_tutoriallMain.o ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o ${OBJECTDIR}/avix/samples/tutorial04_Timer.o ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o ${OBJECTDIR}/avix/samples/tutorial07_Messages.o ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o ${OBJECTDIR}/avix/Cnfg/systemSetup.o ${OBJECTDIR}/elb/ELB_I2C.o ${OBJECTDIR}/elb/ELB_ISR.o ${OBJECTDIR}/elb/ELB_LCD.o ${OBJECTDIR}/elb/ELB_OSC.o ${OBJECTDIR}/elb/ELB_Timer.o ${OBJECTDIR}/elb/ELB_UART.o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o ${OBJECTDIR}/elb/ELB_PWM.o ${OBJECTDIR}/imu/AMGPsensor.o ${OBJECTDIR}/imu/BMA150.o ${OBJECTDIR}/imu/BMP085.o ${OBJECTDIR}/imu/Config_Accel.o ${OBJECTDIR}/imu/Config_Gyro.o ${OBJECTDIR}/imu/Config_Mag.o ${OBJECTDIR}/imu/HMC5883.o ${OBJECTDIR}/imu/ITG3050.o ${OBJECTDIR}/imu/imu_main.o ${OBJECTDIR}/motor/motor.o ${OBJECTDIR}/ping/ping.o ${OBJECTDIR}/servo/servo.o ${OBJECTDIR}/xbee/xbee.o ${OBJECTDIR}/Main.o ${OBJECTDIR}/astar/sys_time.o
POSSIBLE_DEPFILES=${OBJECTDIR}/astar/astar_heap.o.d ${OBJECTDIR}/astar/astar.o.d ${OBJECTDIR}/avix/samples/_tutoriallMain.o.d ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d ${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d ${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d ${OBJECTDIR}/avix/Cnfg/systemSetup.o.d ${OBJECTDIR}/elb/ELB_I2C.o.d ${OBJECTDIR}/elb/ELB_ISR.o.d ${OBJECTDIR}/elb/ELB_LCD.o.d ${OBJECTDIR}/elb/ELB_OSC.o.d ${OBJECTDIR}/elb/ELB_Timer.o.d ${OBJECTDIR}/elb/ELB_UART.o.d ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d ${OBJECTDIR}/elb/ELB_PWM.o.d ${OBJECTDIR}/imu/AMGPsensor.o.d ${OBJECTDIR}/imu/BMA150.o.d ${OBJECTDIR}/imu/BMP085.o.d ${OBJECTDIR}/imu/Config_Accel.o.d ${OBJECTDIR}/imu/Config_Gyro.o.d ${OBJECTDIR}/imu/Config_Mag.o.d ${OBJECTDIR}/imu/HMC5883.o.d ${OBJECTDIR}/imu/ITG3050.o.d ${OBJECTDIR}/imu/imu_main.o.d ${OBJECTDIR}/motor/motor.o.d ${OBJECTDIR}/ping/ping.o.d ${OBJECTDIR}/servo/servo.o.d ${OBJECTDIR}/xbee/xbee.o.d ${OBJECTDIR}/Main.o.d ${OBJECTDIR}/astar/sys_time.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/astar/astar_heap.o ${OBJECTDIR}/astar/astar.o ${OBJECTDIR}/avix/samples/_tutoriallMain.o ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o ${OBJECTDIR}/avix/samples/tutorial04_Timer.o ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o ${OBJECTDIR}/avix/samples/tutorial07_Messages.o ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o ${OBJECTDIR}/avix/Cnfg/systemSetup.o ${OBJECTDIR}/elb/ELB_I2C.o ${OBJECTDIR}/elb/ELB_ISR.o ${OBJECTDIR}/elb/ELB_LCD.o ${OBJECTDIR}/elb/ELB_OSC.o ${OBJECTDIR}/elb/ELB_Timer.o ${OBJECTDIR}/elb/ELB_UART.o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o ${OBJECTDIR}/elb/ELB_PWM.o ${OBJECTDIR}/imu/AMGPsensor.o ${OBJECTDIR}/imu/BMA150.o ${OBJECTDIR}/imu/BMP085.o ${OBJECTDIR}/imu/Config_Accel.o ${OBJECTDIR}/imu/Config_Gyro.o ${OBJECTDIR}/imu/Config_Mag.o ${OBJECTDIR}/imu/HMC5883.o ${OBJECTDIR}/imu/ITG3050.o ${OBJECTDIR}/imu/imu_main.o ${OBJECTDIR}/motor/motor.o ${OBJECTDIR}/ping/ping.o ${OBJECTDIR}/servo/servo.o ${OBJECTDIR}/xbee/xbee.o ${OBJECTDIR}/Main.o ${OBJECTDIR}/astar/sys_time.o

# Source Files
SOURCEFILES=astar/astar_heap.c astar/astar.c avix/samples/_tutoriallMain.c avix/samples/tutorial01_RoundRobin.c avix/samples/tutorial02_RoundRobin.c avix/samples/tutorial03_Preemption.c avix/samples/tutorial04_Timer.c avix/samples/tutorial05_EventFlags.c avix/samples/tutorial06_EventFlags.c avix/samples/tutorial07_Messages.c avix/samples/tutorial08_Pipes.c avix/samples/tutorial09_Exchange.c avix/Cnfg/AVIXConfig.c avix/Cnfg/systemSetup.c elb/ELB_I2C.c elb/ELB_ISR.c elb/ELB_LCD.c elb/ELB_OSC.c elb/ELB_Timer.c elb/ELB_UART.c elb/ELBv21_HardwareConfig.c elb/ELB_PWM.c imu/AMGPsensor.c imu/BMA150.c imu/BMP085.c imu/Config_Accel.c imu/Config_Gyro.c imu/Config_Mag.c imu/HMC5883.c imu/ITG3050.c imu/imu_main.c motor/motor.c ping/ping.c servo/servo.c xbee/xbee.c Main.c astar/sys_time.c


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
MP_LINKER_FILE_OPTION=,--script=p24FJ256GB210.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/astar/astar_heap.o: astar/astar_heap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar_heap.o.d 
	@${RM} ${OBJECTDIR}/astar/astar_heap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  astar/astar_heap.c  -o ${OBJECTDIR}/astar/astar_heap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/astar/astar_heap.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/astar/astar_heap.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/astar/astar.o: astar/astar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar.o.d 
	@${RM} ${OBJECTDIR}/astar/astar.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  astar/astar.c  -o ${OBJECTDIR}/astar/astar.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/astar/astar.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/astar/astar.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/_tutoriallMain.o: avix/samples/_tutoriallMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/_tutoriallMain.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/_tutoriallMain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/_tutoriallMain.c  -o ${OBJECTDIR}/avix/samples/_tutoriallMain.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/_tutoriallMain.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/_tutoriallMain.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o: avix/samples/tutorial01_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial01_RoundRobin.c  -o ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o: avix/samples/tutorial02_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial02_RoundRobin.c  -o ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial03_Preemption.o: avix/samples/tutorial03_Preemption.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial03_Preemption.c  -o ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial04_Timer.o: avix/samples/tutorial04_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial04_Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial04_Timer.c  -o ${OBJECTDIR}/avix/samples/tutorial04_Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o: avix/samples/tutorial05_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial05_EventFlags.c  -o ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o: avix/samples/tutorial06_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial06_EventFlags.c  -o ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial07_Messages.o: avix/samples/tutorial07_Messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial07_Messages.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial07_Messages.c  -o ${OBJECTDIR}/avix/samples/tutorial07_Messages.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial08_Pipes.o: avix/samples/tutorial08_Pipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial08_Pipes.c  -o ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial09_Exchange.o: avix/samples/tutorial09_Exchange.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial09_Exchange.c  -o ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/Cnfg/AVIXConfig.o: avix/Cnfg/AVIXConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/Cnfg 
	@${RM} ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d 
	@${RM} ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/Cnfg/AVIXConfig.c  -o ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/Cnfg/systemSetup.o: avix/Cnfg/systemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/Cnfg 
	@${RM} ${OBJECTDIR}/avix/Cnfg/systemSetup.o.d 
	@${RM} ${OBJECTDIR}/avix/Cnfg/systemSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/Cnfg/systemSetup.c  -o ${OBJECTDIR}/avix/Cnfg/systemSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/Cnfg/systemSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/Cnfg/systemSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_I2C.o: elb/ELB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_I2C.c  -o ${OBJECTDIR}/elb/ELB_I2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_I2C.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_I2C.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_ISR.o: elb/ELB_ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_ISR.c  -o ${OBJECTDIR}/elb/ELB_ISR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_ISR.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_ISR.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_LCD.o: elb/ELB_LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_LCD.c  -o ${OBJECTDIR}/elb/ELB_LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_LCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_LCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_OSC.o: elb/ELB_OSC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_OSC.c  -o ${OBJECTDIR}/elb/ELB_OSC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_OSC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_OSC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_Timer.o: elb/ELB_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_Timer.c  -o ${OBJECTDIR}/elb/ELB_Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_Timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_Timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_UART.o: elb/ELB_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_UART.c  -o ${OBJECTDIR}/elb/ELB_UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_UART.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELBv21_HardwareConfig.o: elb/ELBv21_HardwareConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELBv21_HardwareConfig.c  -o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_PWM.o: elb/ELB_PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_PWM.c  -o ${OBJECTDIR}/elb/ELB_PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_PWM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_PWM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/AMGPsensor.o: imu/AMGPsensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o.d 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/AMGPsensor.c  -o ${OBJECTDIR}/imu/AMGPsensor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/AMGPsensor.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/AMGPsensor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/BMA150.o: imu/BMA150.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMA150.o.d 
	@${RM} ${OBJECTDIR}/imu/BMA150.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/BMA150.c  -o ${OBJECTDIR}/imu/BMA150.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/BMA150.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/BMA150.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/BMP085.o: imu/BMP085.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMP085.o.d 
	@${RM} ${OBJECTDIR}/imu/BMP085.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/BMP085.c  -o ${OBJECTDIR}/imu/BMP085.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/BMP085.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/BMP085.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/Config_Accel.o: imu/Config_Accel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/Config_Accel.c  -o ${OBJECTDIR}/imu/Config_Accel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/Config_Accel.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Accel.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/Config_Gyro.o: imu/Config_Gyro.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/Config_Gyro.c  -o ${OBJECTDIR}/imu/Config_Gyro.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/Config_Gyro.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Gyro.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/Config_Mag.o: imu/Config_Mag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/Config_Mag.c  -o ${OBJECTDIR}/imu/Config_Mag.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/Config_Mag.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Mag.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/HMC5883.o: imu/HMC5883.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o.d 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/HMC5883.c  -o ${OBJECTDIR}/imu/HMC5883.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/HMC5883.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/HMC5883.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/ITG3050.o: imu/ITG3050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o.d 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/ITG3050.c  -o ${OBJECTDIR}/imu/ITG3050.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/ITG3050.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/ITG3050.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/imu_main.o: imu/imu_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/imu_main.o.d 
	@${RM} ${OBJECTDIR}/imu/imu_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/imu_main.c  -o ${OBJECTDIR}/imu/imu_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/imu_main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/imu_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/motor/motor.o: motor/motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/motor 
	@${RM} ${OBJECTDIR}/motor/motor.o.d 
	@${RM} ${OBJECTDIR}/motor/motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  motor/motor.c  -o ${OBJECTDIR}/motor/motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/motor/motor.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/motor/motor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ping/ping.o: ping/ping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ping 
	@${RM} ${OBJECTDIR}/ping/ping.o.d 
	@${RM} ${OBJECTDIR}/ping/ping.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ping/ping.c  -o ${OBJECTDIR}/ping/ping.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ping/ping.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/ping/ping.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/servo/servo.o: servo/servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/servo 
	@${RM} ${OBJECTDIR}/servo/servo.o.d 
	@${RM} ${OBJECTDIR}/servo/servo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  servo/servo.c  -o ${OBJECTDIR}/servo/servo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/servo/servo.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/servo/servo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/xbee/xbee.o: xbee/xbee.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/xbee 
	@${RM} ${OBJECTDIR}/xbee/xbee.o.d 
	@${RM} ${OBJECTDIR}/xbee/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  xbee/xbee.c  -o ${OBJECTDIR}/xbee/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/xbee/xbee.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/xbee/xbee.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Main.c  -o ${OBJECTDIR}/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/astar/sys_time.o: astar/sys_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/sys_time.o.d 
	@${RM} ${OBJECTDIR}/astar/sys_time.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  astar/sys_time.c  -o ${OBJECTDIR}/astar/sys_time.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/astar/sys_time.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/astar/sys_time.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/astar/astar_heap.o: astar/astar_heap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar_heap.o.d 
	@${RM} ${OBJECTDIR}/astar/astar_heap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  astar/astar_heap.c  -o ${OBJECTDIR}/astar/astar_heap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/astar/astar_heap.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/astar/astar_heap.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/astar/astar.o: astar/astar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/astar.o.d 
	@${RM} ${OBJECTDIR}/astar/astar.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  astar/astar.c  -o ${OBJECTDIR}/astar/astar.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/astar/astar.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/astar/astar.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/_tutoriallMain.o: avix/samples/_tutoriallMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/_tutoriallMain.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/_tutoriallMain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/_tutoriallMain.c  -o ${OBJECTDIR}/avix/samples/_tutoriallMain.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/_tutoriallMain.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/_tutoriallMain.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o: avix/samples/tutorial01_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial01_RoundRobin.c  -o ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o: avix/samples/tutorial02_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial02_RoundRobin.c  -o ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial03_Preemption.o: avix/samples/tutorial03_Preemption.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial03_Preemption.c  -o ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial04_Timer.o: avix/samples/tutorial04_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial04_Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial04_Timer.c  -o ${OBJECTDIR}/avix/samples/tutorial04_Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o: avix/samples/tutorial05_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial05_EventFlags.c  -o ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o: avix/samples/tutorial06_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial06_EventFlags.c  -o ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial07_Messages.o: avix/samples/tutorial07_Messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial07_Messages.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial07_Messages.c  -o ${OBJECTDIR}/avix/samples/tutorial07_Messages.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial08_Pipes.o: avix/samples/tutorial08_Pipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial08_Pipes.c  -o ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/samples/tutorial09_Exchange.o: avix/samples/tutorial09_Exchange.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/samples/tutorial09_Exchange.c  -o ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/Cnfg/AVIXConfig.o: avix/Cnfg/AVIXConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/Cnfg 
	@${RM} ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d 
	@${RM} ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/Cnfg/AVIXConfig.c  -o ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/avix/Cnfg/systemSetup.o: avix/Cnfg/systemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/Cnfg 
	@${RM} ${OBJECTDIR}/avix/Cnfg/systemSetup.o.d 
	@${RM} ${OBJECTDIR}/avix/Cnfg/systemSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  avix/Cnfg/systemSetup.c  -o ${OBJECTDIR}/avix/Cnfg/systemSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/avix/Cnfg/systemSetup.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/avix/Cnfg/systemSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_I2C.o: elb/ELB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_I2C.c  -o ${OBJECTDIR}/elb/ELB_I2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_I2C.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_I2C.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_ISR.o: elb/ELB_ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_ISR.c  -o ${OBJECTDIR}/elb/ELB_ISR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_ISR.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_ISR.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_LCD.o: elb/ELB_LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_LCD.c  -o ${OBJECTDIR}/elb/ELB_LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_LCD.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_LCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_OSC.o: elb/ELB_OSC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_OSC.c  -o ${OBJECTDIR}/elb/ELB_OSC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_OSC.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_OSC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_Timer.o: elb/ELB_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_Timer.c  -o ${OBJECTDIR}/elb/ELB_Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_Timer.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_Timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_UART.o: elb/ELB_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_UART.c  -o ${OBJECTDIR}/elb/ELB_UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_UART.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELBv21_HardwareConfig.o: elb/ELBv21_HardwareConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELBv21_HardwareConfig.c  -o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/elb/ELB_PWM.o: elb/ELB_PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  elb/ELB_PWM.c  -o ${OBJECTDIR}/elb/ELB_PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/elb/ELB_PWM.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_PWM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/AMGPsensor.o: imu/AMGPsensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o.d 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/AMGPsensor.c  -o ${OBJECTDIR}/imu/AMGPsensor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/AMGPsensor.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/AMGPsensor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/BMA150.o: imu/BMA150.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMA150.o.d 
	@${RM} ${OBJECTDIR}/imu/BMA150.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/BMA150.c  -o ${OBJECTDIR}/imu/BMA150.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/BMA150.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/BMA150.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/BMP085.o: imu/BMP085.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMP085.o.d 
	@${RM} ${OBJECTDIR}/imu/BMP085.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/BMP085.c  -o ${OBJECTDIR}/imu/BMP085.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/BMP085.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/BMP085.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/Config_Accel.o: imu/Config_Accel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/Config_Accel.c  -o ${OBJECTDIR}/imu/Config_Accel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/Config_Accel.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Accel.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/Config_Gyro.o: imu/Config_Gyro.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/Config_Gyro.c  -o ${OBJECTDIR}/imu/Config_Gyro.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/Config_Gyro.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Gyro.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/Config_Mag.o: imu/Config_Mag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/Config_Mag.c  -o ${OBJECTDIR}/imu/Config_Mag.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/Config_Mag.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Mag.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/HMC5883.o: imu/HMC5883.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o.d 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/HMC5883.c  -o ${OBJECTDIR}/imu/HMC5883.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/HMC5883.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/HMC5883.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/ITG3050.o: imu/ITG3050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o.d 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/ITG3050.c  -o ${OBJECTDIR}/imu/ITG3050.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/ITG3050.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/ITG3050.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/imu/imu_main.o: imu/imu_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/imu_main.o.d 
	@${RM} ${OBJECTDIR}/imu/imu_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  imu/imu_main.c  -o ${OBJECTDIR}/imu/imu_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/imu/imu_main.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/imu/imu_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/motor/motor.o: motor/motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/motor 
	@${RM} ${OBJECTDIR}/motor/motor.o.d 
	@${RM} ${OBJECTDIR}/motor/motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  motor/motor.c  -o ${OBJECTDIR}/motor/motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/motor/motor.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/motor/motor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ping/ping.o: ping/ping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ping 
	@${RM} ${OBJECTDIR}/ping/ping.o.d 
	@${RM} ${OBJECTDIR}/ping/ping.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ping/ping.c  -o ${OBJECTDIR}/ping/ping.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ping/ping.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/ping/ping.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/servo/servo.o: servo/servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/servo 
	@${RM} ${OBJECTDIR}/servo/servo.o.d 
	@${RM} ${OBJECTDIR}/servo/servo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  servo/servo.c  -o ${OBJECTDIR}/servo/servo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/servo/servo.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/servo/servo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/xbee/xbee.o: xbee/xbee.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/xbee 
	@${RM} ${OBJECTDIR}/xbee/xbee.o.d 
	@${RM} ${OBJECTDIR}/xbee/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  xbee/xbee.c  -o ${OBJECTDIR}/xbee/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/xbee/xbee.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/xbee/xbee.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Main.c  -o ${OBJECTDIR}/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/astar/sys_time.o: astar/sys_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/astar 
	@${RM} ${OBJECTDIR}/astar/sys_time.o.d 
	@${RM} ${OBJECTDIR}/astar/sys_time.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  astar/sys_time.c  -o ${OBJECTDIR}/astar/sys_time.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/astar/sys_time.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -I"astar" -I"xbee" -I"servo" -I"ping" -I"motor" -I"imu" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/astar/sys_time.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  avix/Lib/AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    avix\Lib\AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf  -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--heap=512,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  avix/Lib/AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    avix\Lib\AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=512,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
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
