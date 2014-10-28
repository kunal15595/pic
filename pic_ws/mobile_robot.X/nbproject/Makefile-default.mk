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
SOURCEFILES_QUOTED_IF_SPACED=avix/samples/_tutoriallMain.c avix/samples/tutorial01_RoundRobin.c avix/samples/tutorial02_RoundRobin.c avix/samples/tutorial03_Preemption.c avix/samples/tutorial04_Timer.c avix/samples/tutorial05_EventFlags.c avix/samples/tutorial06_EventFlags.c avix/samples/tutorial07_Messages.c avix/samples/tutorial08_Pipes.c avix/samples/tutorial09_Exchange.c avix/Cnfg/AVIXConfig.c elb/ELB_I2C.c elb/ELB_ISR.c elb/ELB_LCD.c elb/ELB_OSC.c elb/ELB_Timer.c elb/ELB_UART.c elb/ELBv21_HardwareConfig.c elb/ELB_PWM.c imu/AMGPsensor.c imu/BMA150.c imu/BMP085.c imu/Config_Accel.c imu/Config_Gyro.c imu/Config_Mag.c imu/HMC5883.c imu/ITG3050.c imu/imu_main.c avix/Cnfg/systemSetup.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/avix/samples/_tutoriallMain.o ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o ${OBJECTDIR}/avix/samples/tutorial04_Timer.o ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o ${OBJECTDIR}/avix/samples/tutorial07_Messages.o ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o ${OBJECTDIR}/elb/ELB_I2C.o ${OBJECTDIR}/elb/ELB_ISR.o ${OBJECTDIR}/elb/ELB_LCD.o ${OBJECTDIR}/elb/ELB_OSC.o ${OBJECTDIR}/elb/ELB_Timer.o ${OBJECTDIR}/elb/ELB_UART.o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o ${OBJECTDIR}/elb/ELB_PWM.o ${OBJECTDIR}/imu/AMGPsensor.o ${OBJECTDIR}/imu/BMA150.o ${OBJECTDIR}/imu/BMP085.o ${OBJECTDIR}/imu/Config_Accel.o ${OBJECTDIR}/imu/Config_Gyro.o ${OBJECTDIR}/imu/Config_Mag.o ${OBJECTDIR}/imu/HMC5883.o ${OBJECTDIR}/imu/ITG3050.o ${OBJECTDIR}/imu/imu_main.o ${OBJECTDIR}/avix/Cnfg/systemSetup.o
POSSIBLE_DEPFILES=${OBJECTDIR}/avix/samples/_tutoriallMain.o.d ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d ${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d ${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d ${OBJECTDIR}/elb/ELB_I2C.o.d ${OBJECTDIR}/elb/ELB_ISR.o.d ${OBJECTDIR}/elb/ELB_LCD.o.d ${OBJECTDIR}/elb/ELB_OSC.o.d ${OBJECTDIR}/elb/ELB_Timer.o.d ${OBJECTDIR}/elb/ELB_UART.o.d ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d ${OBJECTDIR}/elb/ELB_PWM.o.d ${OBJECTDIR}/imu/AMGPsensor.o.d ${OBJECTDIR}/imu/BMA150.o.d ${OBJECTDIR}/imu/BMP085.o.d ${OBJECTDIR}/imu/Config_Accel.o.d ${OBJECTDIR}/imu/Config_Gyro.o.d ${OBJECTDIR}/imu/Config_Mag.o.d ${OBJECTDIR}/imu/HMC5883.o.d ${OBJECTDIR}/imu/ITG3050.o.d ${OBJECTDIR}/imu/imu_main.o.d ${OBJECTDIR}/avix/Cnfg/systemSetup.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/avix/samples/_tutoriallMain.o ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o ${OBJECTDIR}/avix/samples/tutorial04_Timer.o ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o ${OBJECTDIR}/avix/samples/tutorial07_Messages.o ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o ${OBJECTDIR}/elb/ELB_I2C.o ${OBJECTDIR}/elb/ELB_ISR.o ${OBJECTDIR}/elb/ELB_LCD.o ${OBJECTDIR}/elb/ELB_OSC.o ${OBJECTDIR}/elb/ELB_Timer.o ${OBJECTDIR}/elb/ELB_UART.o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o ${OBJECTDIR}/elb/ELB_PWM.o ${OBJECTDIR}/imu/AMGPsensor.o ${OBJECTDIR}/imu/BMA150.o ${OBJECTDIR}/imu/BMP085.o ${OBJECTDIR}/imu/Config_Accel.o ${OBJECTDIR}/imu/Config_Gyro.o ${OBJECTDIR}/imu/Config_Mag.o ${OBJECTDIR}/imu/HMC5883.o ${OBJECTDIR}/imu/ITG3050.o ${OBJECTDIR}/imu/imu_main.o ${OBJECTDIR}/avix/Cnfg/systemSetup.o

# Source Files
SOURCEFILES=avix/samples/_tutoriallMain.c avix/samples/tutorial01_RoundRobin.c avix/samples/tutorial02_RoundRobin.c avix/samples/tutorial03_Preemption.c avix/samples/tutorial04_Timer.c avix/samples/tutorial05_EventFlags.c avix/samples/tutorial06_EventFlags.c avix/samples/tutorial07_Messages.c avix/samples/tutorial08_Pipes.c avix/samples/tutorial09_Exchange.c avix/Cnfg/AVIXConfig.c elb/ELB_I2C.c elb/ELB_ISR.c elb/ELB_LCD.c elb/ELB_OSC.c elb/ELB_Timer.c elb/ELB_UART.c elb/ELBv21_HardwareConfig.c elb/ELB_PWM.c imu/AMGPsensor.c imu/BMA150.c imu/BMP085.c imu/Config_Accel.c imu/Config_Gyro.c imu/Config_Mag.c imu/HMC5883.c imu/ITG3050.c imu/imu_main.c avix/Cnfg/systemSetup.c


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
${OBJECTDIR}/avix/samples/_tutoriallMain.o: avix/samples/_tutoriallMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/_tutoriallMain.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/_tutoriallMain.o.ok ${OBJECTDIR}/avix/samples/_tutoriallMain.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/_tutoriallMain.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/_tutoriallMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/_tutoriallMain.o.d" -o ${OBJECTDIR}/avix/samples/_tutoriallMain.o avix/samples/_tutoriallMain.c    
	
${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o: avix/samples/tutorial01_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.ok ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d" -o ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o avix/samples/tutorial01_RoundRobin.c    
	
${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o: avix/samples/tutorial02_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.ok ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d" -o ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o avix/samples/tutorial02_RoundRobin.c    
	
${OBJECTDIR}/avix/samples/tutorial03_Preemption.o: avix/samples/tutorial03_Preemption.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.ok ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d" -o ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o avix/samples/tutorial03_Preemption.c    
	
${OBJECTDIR}/avix/samples/tutorial04_Timer.o: avix/samples/tutorial04_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial04_Timer.o.ok ${OBJECTDIR}/avix/samples/tutorial04_Timer.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial04_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d" -o ${OBJECTDIR}/avix/samples/tutorial04_Timer.o avix/samples/tutorial04_Timer.c    
	
${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o: avix/samples/tutorial05_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.ok ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d" -o ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o avix/samples/tutorial05_EventFlags.c    
	
${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o: avix/samples/tutorial06_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.ok ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d" -o ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o avix/samples/tutorial06_EventFlags.c    
	
${OBJECTDIR}/avix/samples/tutorial07_Messages.o: avix/samples/tutorial07_Messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial07_Messages.o.ok ${OBJECTDIR}/avix/samples/tutorial07_Messages.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial07_Messages.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d" -o ${OBJECTDIR}/avix/samples/tutorial07_Messages.o avix/samples/tutorial07_Messages.c    
	
${OBJECTDIR}/avix/samples/tutorial08_Pipes.o: avix/samples/tutorial08_Pipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.ok ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d" -o ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o avix/samples/tutorial08_Pipes.c    
	
${OBJECTDIR}/avix/samples/tutorial09_Exchange.o: avix/samples/tutorial09_Exchange.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.ok ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d" -o ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o avix/samples/tutorial09_Exchange.c    
	
${OBJECTDIR}/avix/Cnfg/AVIXConfig.o: avix/Cnfg/AVIXConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/Cnfg 
	@${RM} ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d 
	@${RM} ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.ok ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.err 
	@${RM} ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d" -o ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o avix/Cnfg/AVIXConfig.c    
	
${OBJECTDIR}/elb/ELB_I2C.o: elb/ELB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o.ok ${OBJECTDIR}/elb/ELB_I2C.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_I2C.o.d" -o ${OBJECTDIR}/elb/ELB_I2C.o elb/ELB_I2C.c    
	
${OBJECTDIR}/elb/ELB_ISR.o: elb/ELB_ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o.ok ${OBJECTDIR}/elb/ELB_ISR.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_ISR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_ISR.o.d" -o ${OBJECTDIR}/elb/ELB_ISR.o elb/ELB_ISR.c    
	
${OBJECTDIR}/elb/ELB_LCD.o: elb/ELB_LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o.ok ${OBJECTDIR}/elb/ELB_LCD.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_LCD.o.d" -o ${OBJECTDIR}/elb/ELB_LCD.o elb/ELB_LCD.c    
	
${OBJECTDIR}/elb/ELB_OSC.o: elb/ELB_OSC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o.ok ${OBJECTDIR}/elb/ELB_OSC.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_OSC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_OSC.o.d" -o ${OBJECTDIR}/elb/ELB_OSC.o elb/ELB_OSC.c    
	
${OBJECTDIR}/elb/ELB_Timer.o: elb/ELB_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o.ok ${OBJECTDIR}/elb/ELB_Timer.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_Timer.o.d" -o ${OBJECTDIR}/elb/ELB_Timer.o elb/ELB_Timer.c    
	
${OBJECTDIR}/elb/ELB_UART.o: elb/ELB_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o.ok ${OBJECTDIR}/elb/ELB_UART.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_UART.o.d" -o ${OBJECTDIR}/elb/ELB_UART.o elb/ELB_UART.c    
	
${OBJECTDIR}/elb/ELBv21_HardwareConfig.o: elb/ELBv21_HardwareConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.ok ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.err 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d" -o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o elb/ELBv21_HardwareConfig.c    
	
${OBJECTDIR}/elb/ELB_PWM.o: elb/ELB_PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o.ok ${OBJECTDIR}/elb/ELB_PWM.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_PWM.o.d" -o ${OBJECTDIR}/elb/ELB_PWM.o elb/ELB_PWM.c    
	
${OBJECTDIR}/imu/AMGPsensor.o: imu/AMGPsensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o.d 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o.ok ${OBJECTDIR}/imu/AMGPsensor.o.err 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/AMGPsensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/AMGPsensor.o.d" -o ${OBJECTDIR}/imu/AMGPsensor.o imu/AMGPsensor.c    
	
${OBJECTDIR}/imu/BMA150.o: imu/BMA150.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMA150.o.d 
	@${RM} ${OBJECTDIR}/imu/BMA150.o.ok ${OBJECTDIR}/imu/BMA150.o.err 
	@${RM} ${OBJECTDIR}/imu/BMA150.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/BMA150.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/BMA150.o.d" -o ${OBJECTDIR}/imu/BMA150.o imu/BMA150.c    
	
${OBJECTDIR}/imu/BMP085.o: imu/BMP085.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMP085.o.d 
	@${RM} ${OBJECTDIR}/imu/BMP085.o.ok ${OBJECTDIR}/imu/BMP085.o.err 
	@${RM} ${OBJECTDIR}/imu/BMP085.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/BMP085.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/BMP085.o.d" -o ${OBJECTDIR}/imu/BMP085.o imu/BMP085.c    
	
${OBJECTDIR}/imu/Config_Accel.o: imu/Config_Accel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o.ok ${OBJECTDIR}/imu/Config_Accel.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Accel.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/Config_Accel.o.d" -o ${OBJECTDIR}/imu/Config_Accel.o imu/Config_Accel.c    
	
${OBJECTDIR}/imu/Config_Gyro.o: imu/Config_Gyro.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o.ok ${OBJECTDIR}/imu/Config_Gyro.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Gyro.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/Config_Gyro.o.d" -o ${OBJECTDIR}/imu/Config_Gyro.o imu/Config_Gyro.c    
	
${OBJECTDIR}/imu/Config_Mag.o: imu/Config_Mag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o.ok ${OBJECTDIR}/imu/Config_Mag.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Mag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/Config_Mag.o.d" -o ${OBJECTDIR}/imu/Config_Mag.o imu/Config_Mag.c    
	
${OBJECTDIR}/imu/HMC5883.o: imu/HMC5883.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o.d 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o.ok ${OBJECTDIR}/imu/HMC5883.o.err 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/HMC5883.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/HMC5883.o.d" -o ${OBJECTDIR}/imu/HMC5883.o imu/HMC5883.c    
	
${OBJECTDIR}/imu/ITG3050.o: imu/ITG3050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o.d 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o.ok ${OBJECTDIR}/imu/ITG3050.o.err 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/ITG3050.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/ITG3050.o.d" -o ${OBJECTDIR}/imu/ITG3050.o imu/ITG3050.c    
	
${OBJECTDIR}/imu/imu_main.o: imu/imu_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/imu_main.o.d 
	@${RM} ${OBJECTDIR}/imu/imu_main.o.ok ${OBJECTDIR}/imu/imu_main.o.err 
	@${RM} ${OBJECTDIR}/imu/imu_main.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/imu_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/imu_main.o.d" -o ${OBJECTDIR}/imu/imu_main.o imu/imu_main.c    
	
${OBJECTDIR}/avix/Cnfg/systemSetup.o: avix/Cnfg/systemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/Cnfg 
	@${RM} ${OBJECTDIR}/avix/Cnfg/systemSetup.o.d 
	@${RM} ${OBJECTDIR}/avix/Cnfg/systemSetup.o.ok ${OBJECTDIR}/avix/Cnfg/systemSetup.o.err 
	@${RM} ${OBJECTDIR}/avix/Cnfg/systemSetup.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/Cnfg/systemSetup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/Cnfg/systemSetup.o.d" -o ${OBJECTDIR}/avix/Cnfg/systemSetup.o avix/Cnfg/systemSetup.c    
	
else
${OBJECTDIR}/avix/samples/_tutoriallMain.o: avix/samples/_tutoriallMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/_tutoriallMain.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/_tutoriallMain.o.ok ${OBJECTDIR}/avix/samples/_tutoriallMain.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/_tutoriallMain.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/_tutoriallMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/_tutoriallMain.o.d" -o ${OBJECTDIR}/avix/samples/_tutoriallMain.o avix/samples/_tutoriallMain.c    
	
${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o: avix/samples/tutorial01_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.ok ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o.d" -o ${OBJECTDIR}/avix/samples/tutorial01_RoundRobin.o avix/samples/tutorial01_RoundRobin.c    
	
${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o: avix/samples/tutorial02_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.ok ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o.d" -o ${OBJECTDIR}/avix/samples/tutorial02_RoundRobin.o avix/samples/tutorial02_RoundRobin.c    
	
${OBJECTDIR}/avix/samples/tutorial03_Preemption.o: avix/samples/tutorial03_Preemption.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.ok ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial03_Preemption.o.d" -o ${OBJECTDIR}/avix/samples/tutorial03_Preemption.o avix/samples/tutorial03_Preemption.c    
	
${OBJECTDIR}/avix/samples/tutorial04_Timer.o: avix/samples/tutorial04_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial04_Timer.o.ok ${OBJECTDIR}/avix/samples/tutorial04_Timer.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial04_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial04_Timer.o.d" -o ${OBJECTDIR}/avix/samples/tutorial04_Timer.o avix/samples/tutorial04_Timer.c    
	
${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o: avix/samples/tutorial05_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.ok ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o.d" -o ${OBJECTDIR}/avix/samples/tutorial05_EventFlags.o avix/samples/tutorial05_EventFlags.c    
	
${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o: avix/samples/tutorial06_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.ok ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o.d" -o ${OBJECTDIR}/avix/samples/tutorial06_EventFlags.o avix/samples/tutorial06_EventFlags.c    
	
${OBJECTDIR}/avix/samples/tutorial07_Messages.o: avix/samples/tutorial07_Messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial07_Messages.o.ok ${OBJECTDIR}/avix/samples/tutorial07_Messages.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial07_Messages.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial07_Messages.o.d" -o ${OBJECTDIR}/avix/samples/tutorial07_Messages.o avix/samples/tutorial07_Messages.c    
	
${OBJECTDIR}/avix/samples/tutorial08_Pipes.o: avix/samples/tutorial08_Pipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.ok ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial08_Pipes.o.d" -o ${OBJECTDIR}/avix/samples/tutorial08_Pipes.o avix/samples/tutorial08_Pipes.c    
	
${OBJECTDIR}/avix/samples/tutorial09_Exchange.o: avix/samples/tutorial09_Exchange.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/samples 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.ok ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.err 
	@${RM} ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/samples/tutorial09_Exchange.o.d" -o ${OBJECTDIR}/avix/samples/tutorial09_Exchange.o avix/samples/tutorial09_Exchange.c    
	
${OBJECTDIR}/avix/Cnfg/AVIXConfig.o: avix/Cnfg/AVIXConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/Cnfg 
	@${RM} ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d 
	@${RM} ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.ok ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.err 
	@${RM} ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/Cnfg/AVIXConfig.o.d" -o ${OBJECTDIR}/avix/Cnfg/AVIXConfig.o avix/Cnfg/AVIXConfig.c    
	
${OBJECTDIR}/elb/ELB_I2C.o: elb/ELB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o.ok ${OBJECTDIR}/elb/ELB_I2C.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_I2C.o.d" -o ${OBJECTDIR}/elb/ELB_I2C.o elb/ELB_I2C.c    
	
${OBJECTDIR}/elb/ELB_ISR.o: elb/ELB_ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o.ok ${OBJECTDIR}/elb/ELB_ISR.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_ISR.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_ISR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_ISR.o.d" -o ${OBJECTDIR}/elb/ELB_ISR.o elb/ELB_ISR.c    
	
${OBJECTDIR}/elb/ELB_LCD.o: elb/ELB_LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o.ok ${OBJECTDIR}/elb/ELB_LCD.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_LCD.o.d" -o ${OBJECTDIR}/elb/ELB_LCD.o elb/ELB_LCD.c    
	
${OBJECTDIR}/elb/ELB_OSC.o: elb/ELB_OSC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o.ok ${OBJECTDIR}/elb/ELB_OSC.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_OSC.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_OSC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_OSC.o.d" -o ${OBJECTDIR}/elb/ELB_OSC.o elb/ELB_OSC.c    
	
${OBJECTDIR}/elb/ELB_Timer.o: elb/ELB_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o.ok ${OBJECTDIR}/elb/ELB_Timer.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_Timer.o.d" -o ${OBJECTDIR}/elb/ELB_Timer.o elb/ELB_Timer.c    
	
${OBJECTDIR}/elb/ELB_UART.o: elb/ELB_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o.ok ${OBJECTDIR}/elb/ELB_UART.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_UART.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_UART.o.d" -o ${OBJECTDIR}/elb/ELB_UART.o elb/ELB_UART.c    
	
${OBJECTDIR}/elb/ELBv21_HardwareConfig.o: elb/ELBv21_HardwareConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.ok ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.err 
	@${RM} ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELBv21_HardwareConfig.o.d" -o ${OBJECTDIR}/elb/ELBv21_HardwareConfig.o elb/ELBv21_HardwareConfig.c    
	
${OBJECTDIR}/elb/ELB_PWM.o: elb/ELB_PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/elb 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o.d 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o.ok ${OBJECTDIR}/elb/ELB_PWM.o.err 
	@${RM} ${OBJECTDIR}/elb/ELB_PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/elb/ELB_PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/elb/ELB_PWM.o.d" -o ${OBJECTDIR}/elb/ELB_PWM.o elb/ELB_PWM.c    
	
${OBJECTDIR}/imu/AMGPsensor.o: imu/AMGPsensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o.d 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o.ok ${OBJECTDIR}/imu/AMGPsensor.o.err 
	@${RM} ${OBJECTDIR}/imu/AMGPsensor.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/AMGPsensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/AMGPsensor.o.d" -o ${OBJECTDIR}/imu/AMGPsensor.o imu/AMGPsensor.c    
	
${OBJECTDIR}/imu/BMA150.o: imu/BMA150.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMA150.o.d 
	@${RM} ${OBJECTDIR}/imu/BMA150.o.ok ${OBJECTDIR}/imu/BMA150.o.err 
	@${RM} ${OBJECTDIR}/imu/BMA150.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/BMA150.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/BMA150.o.d" -o ${OBJECTDIR}/imu/BMA150.o imu/BMA150.c    
	
${OBJECTDIR}/imu/BMP085.o: imu/BMP085.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/BMP085.o.d 
	@${RM} ${OBJECTDIR}/imu/BMP085.o.ok ${OBJECTDIR}/imu/BMP085.o.err 
	@${RM} ${OBJECTDIR}/imu/BMP085.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/BMP085.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/BMP085.o.d" -o ${OBJECTDIR}/imu/BMP085.o imu/BMP085.c    
	
${OBJECTDIR}/imu/Config_Accel.o: imu/Config_Accel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o.ok ${OBJECTDIR}/imu/Config_Accel.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Accel.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Accel.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/Config_Accel.o.d" -o ${OBJECTDIR}/imu/Config_Accel.o imu/Config_Accel.c    
	
${OBJECTDIR}/imu/Config_Gyro.o: imu/Config_Gyro.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o.ok ${OBJECTDIR}/imu/Config_Gyro.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Gyro.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Gyro.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/Config_Gyro.o.d" -o ${OBJECTDIR}/imu/Config_Gyro.o imu/Config_Gyro.c    
	
${OBJECTDIR}/imu/Config_Mag.o: imu/Config_Mag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o.d 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o.ok ${OBJECTDIR}/imu/Config_Mag.o.err 
	@${RM} ${OBJECTDIR}/imu/Config_Mag.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/Config_Mag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/Config_Mag.o.d" -o ${OBJECTDIR}/imu/Config_Mag.o imu/Config_Mag.c    
	
${OBJECTDIR}/imu/HMC5883.o: imu/HMC5883.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o.d 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o.ok ${OBJECTDIR}/imu/HMC5883.o.err 
	@${RM} ${OBJECTDIR}/imu/HMC5883.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/HMC5883.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/HMC5883.o.d" -o ${OBJECTDIR}/imu/HMC5883.o imu/HMC5883.c    
	
${OBJECTDIR}/imu/ITG3050.o: imu/ITG3050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o.d 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o.ok ${OBJECTDIR}/imu/ITG3050.o.err 
	@${RM} ${OBJECTDIR}/imu/ITG3050.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/ITG3050.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/ITG3050.o.d" -o ${OBJECTDIR}/imu/ITG3050.o imu/ITG3050.c    
	
${OBJECTDIR}/imu/imu_main.o: imu/imu_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/imu 
	@${RM} ${OBJECTDIR}/imu/imu_main.o.d 
	@${RM} ${OBJECTDIR}/imu/imu_main.o.ok ${OBJECTDIR}/imu/imu_main.o.err 
	@${RM} ${OBJECTDIR}/imu/imu_main.o 
	@${FIXDEPS} "${OBJECTDIR}/imu/imu_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/imu/imu_main.o.d" -o ${OBJECTDIR}/imu/imu_main.o imu/imu_main.c    
	
${OBJECTDIR}/avix/Cnfg/systemSetup.o: avix/Cnfg/systemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/avix/Cnfg 
	@${RM} ${OBJECTDIR}/avix/Cnfg/systemSetup.o.d 
	@${RM} ${OBJECTDIR}/avix/Cnfg/systemSetup.o.ok ${OBJECTDIR}/avix/Cnfg/systemSetup.o.err 
	@${RM} ${OBJECTDIR}/avix/Cnfg/systemSetup.o 
	@${FIXDEPS} "${OBJECTDIR}/avix/Cnfg/systemSetup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"avix/Interface" -I"avix/Utilities/Interface" -I"elb" -MMD -MF "${OBJECTDIR}/avix/Cnfg/systemSetup.o.d" -o ${OBJECTDIR}/avix/Cnfg/systemSetup.o avix/Cnfg/systemSetup.c    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  avix/Lib/AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   avix\Lib\AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a      -Wl,--defsym=__MPLAB_BUILD=1,--stack=16,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  avix/Lib/AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/mobile_robot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   avix\Lib\AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a      -Wl,--defsym=__MPLAB_BUILD=1,--stack=16,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
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
