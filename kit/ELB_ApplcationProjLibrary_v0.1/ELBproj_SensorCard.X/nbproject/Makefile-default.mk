#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_SensorCard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_SensorCard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ELB_I2C.o ${OBJECTDIR}/ELB_OSC.o ${OBJECTDIR}/ELB_Timer.o ${OBJECTDIR}/ELB_UART.o ${OBJECTDIR}/ELBv21_HardwareConfig.o ${OBJECTDIR}/ELB_ISR.o ${OBJECTDIR}/Main.o ${OBJECTDIR}/ITG3050.o ${OBJECTDIR}/AMGPsensor.o ${OBJECTDIR}/BMA150.o ${OBJECTDIR}/BMP085.o ${OBJECTDIR}/HMC5883.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ELB_I2C.o.d ${OBJECTDIR}/ELB_OSC.o.d ${OBJECTDIR}/ELB_Timer.o.d ${OBJECTDIR}/ELB_UART.o.d ${OBJECTDIR}/ELBv21_HardwareConfig.o.d ${OBJECTDIR}/ELB_ISR.o.d ${OBJECTDIR}/Main.o.d ${OBJECTDIR}/ITG3050.o.d ${OBJECTDIR}/AMGPsensor.o.d ${OBJECTDIR}/BMA150.o.d ${OBJECTDIR}/BMP085.o.d ${OBJECTDIR}/HMC5883.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ELB_I2C.o ${OBJECTDIR}/ELB_OSC.o ${OBJECTDIR}/ELB_Timer.o ${OBJECTDIR}/ELB_UART.o ${OBJECTDIR}/ELBv21_HardwareConfig.o ${OBJECTDIR}/ELB_ISR.o ${OBJECTDIR}/Main.o ${OBJECTDIR}/ITG3050.o ${OBJECTDIR}/AMGPsensor.o ${OBJECTDIR}/BMA150.o ${OBJECTDIR}/BMP085.o ${OBJECTDIR}/HMC5883.o


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_SensorCard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ256GB206
MP_LINKER_FILE_OPTION=,-Tp24FJ256GB206.gld
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
${OBJECTDIR}/ELB_I2C.o: ELB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_I2C.o.d 
	@${RM} ${OBJECTDIR}/ELB_I2C.o.ok ${OBJECTDIR}/ELB_I2C.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELB_I2C.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_I2C.o.d" -o ${OBJECTDIR}/ELB_I2C.o ELB_I2C.c    
	
${OBJECTDIR}/ELB_OSC.o: ELB_OSC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_OSC.o.d 
	@${RM} ${OBJECTDIR}/ELB_OSC.o.ok ${OBJECTDIR}/ELB_OSC.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELB_OSC.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_OSC.o.d" -o ${OBJECTDIR}/ELB_OSC.o ELB_OSC.c    
	
${OBJECTDIR}/ELB_Timer.o: ELB_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_Timer.o.d 
	@${RM} ${OBJECTDIR}/ELB_Timer.o.ok ${OBJECTDIR}/ELB_Timer.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELB_Timer.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_Timer.o.d" -o ${OBJECTDIR}/ELB_Timer.o ELB_Timer.c    
	
${OBJECTDIR}/ELB_UART.o: ELB_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_UART.o.d 
	@${RM} ${OBJECTDIR}/ELB_UART.o.ok ${OBJECTDIR}/ELB_UART.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELB_UART.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_UART.o.d" -o ${OBJECTDIR}/ELB_UART.o ELB_UART.c    
	
${OBJECTDIR}/ELBv21_HardwareConfig.o: ELBv21_HardwareConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELBv21_HardwareConfig.o.d 
	@${RM} ${OBJECTDIR}/ELBv21_HardwareConfig.o.ok ${OBJECTDIR}/ELBv21_HardwareConfig.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELBv21_HardwareConfig.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELBv21_HardwareConfig.o.d" -o ${OBJECTDIR}/ELBv21_HardwareConfig.o ELBv21_HardwareConfig.c    
	
${OBJECTDIR}/ELB_ISR.o: ELB_ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_ISR.o.d 
	@${RM} ${OBJECTDIR}/ELB_ISR.o.ok ${OBJECTDIR}/ELB_ISR.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELB_ISR.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_ISR.o.d" -o ${OBJECTDIR}/ELB_ISR.o ELB_ISR.c    
	
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o.ok ${OBJECTDIR}/Main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d" -o ${OBJECTDIR}/Main.o Main.c    
	
${OBJECTDIR}/ITG3050.o: ITG3050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ITG3050.o.d 
	@${RM} ${OBJECTDIR}/ITG3050.o.ok ${OBJECTDIR}/ITG3050.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ITG3050.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ITG3050.o.d" -o ${OBJECTDIR}/ITG3050.o ITG3050.c    
	
${OBJECTDIR}/AMGPsensor.o: AMGPsensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AMGPsensor.o.d 
	@${RM} ${OBJECTDIR}/AMGPsensor.o.ok ${OBJECTDIR}/AMGPsensor.o.err 
	@${FIXDEPS} "${OBJECTDIR}/AMGPsensor.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/AMGPsensor.o.d" -o ${OBJECTDIR}/AMGPsensor.o AMGPsensor.c    
	
${OBJECTDIR}/BMA150.o: BMA150.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BMA150.o.d 
	@${RM} ${OBJECTDIR}/BMA150.o.ok ${OBJECTDIR}/BMA150.o.err 
	@${FIXDEPS} "${OBJECTDIR}/BMA150.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/BMA150.o.d" -o ${OBJECTDIR}/BMA150.o BMA150.c    
	
${OBJECTDIR}/BMP085.o: BMP085.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BMP085.o.d 
	@${RM} ${OBJECTDIR}/BMP085.o.ok ${OBJECTDIR}/BMP085.o.err 
	@${FIXDEPS} "${OBJECTDIR}/BMP085.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/BMP085.o.d" -o ${OBJECTDIR}/BMP085.o BMP085.c    
	
${OBJECTDIR}/HMC5883.o: HMC5883.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/HMC5883.o.d 
	@${RM} ${OBJECTDIR}/HMC5883.o.ok ${OBJECTDIR}/HMC5883.o.err 
	@${FIXDEPS} "${OBJECTDIR}/HMC5883.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/HMC5883.o.d" -o ${OBJECTDIR}/HMC5883.o HMC5883.c    
	
else
${OBJECTDIR}/ELB_I2C.o: ELB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_I2C.o.d 
	@${RM} ${OBJECTDIR}/ELB_I2C.o.ok ${OBJECTDIR}/ELB_I2C.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELB_I2C.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_I2C.o.d" -o ${OBJECTDIR}/ELB_I2C.o ELB_I2C.c    
	
${OBJECTDIR}/ELB_OSC.o: ELB_OSC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_OSC.o.d 
	@${RM} ${OBJECTDIR}/ELB_OSC.o.ok ${OBJECTDIR}/ELB_OSC.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELB_OSC.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_OSC.o.d" -o ${OBJECTDIR}/ELB_OSC.o ELB_OSC.c    
	
${OBJECTDIR}/ELB_Timer.o: ELB_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_Timer.o.d 
	@${RM} ${OBJECTDIR}/ELB_Timer.o.ok ${OBJECTDIR}/ELB_Timer.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELB_Timer.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_Timer.o.d" -o ${OBJECTDIR}/ELB_Timer.o ELB_Timer.c    
	
${OBJECTDIR}/ELB_UART.o: ELB_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_UART.o.d 
	@${RM} ${OBJECTDIR}/ELB_UART.o.ok ${OBJECTDIR}/ELB_UART.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELB_UART.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_UART.o.d" -o ${OBJECTDIR}/ELB_UART.o ELB_UART.c    
	
${OBJECTDIR}/ELBv21_HardwareConfig.o: ELBv21_HardwareConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELBv21_HardwareConfig.o.d 
	@${RM} ${OBJECTDIR}/ELBv21_HardwareConfig.o.ok ${OBJECTDIR}/ELBv21_HardwareConfig.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELBv21_HardwareConfig.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELBv21_HardwareConfig.o.d" -o ${OBJECTDIR}/ELBv21_HardwareConfig.o ELBv21_HardwareConfig.c    
	
${OBJECTDIR}/ELB_ISR.o: ELB_ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_ISR.o.d 
	@${RM} ${OBJECTDIR}/ELB_ISR.o.ok ${OBJECTDIR}/ELB_ISR.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ELB_ISR.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_ISR.o.d" -o ${OBJECTDIR}/ELB_ISR.o ELB_ISR.c    
	
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o.ok ${OBJECTDIR}/Main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d" -o ${OBJECTDIR}/Main.o Main.c    
	
${OBJECTDIR}/ITG3050.o: ITG3050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ITG3050.o.d 
	@${RM} ${OBJECTDIR}/ITG3050.o.ok ${OBJECTDIR}/ITG3050.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ITG3050.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ITG3050.o.d" -o ${OBJECTDIR}/ITG3050.o ITG3050.c    
	
${OBJECTDIR}/AMGPsensor.o: AMGPsensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AMGPsensor.o.d 
	@${RM} ${OBJECTDIR}/AMGPsensor.o.ok ${OBJECTDIR}/AMGPsensor.o.err 
	@${FIXDEPS} "${OBJECTDIR}/AMGPsensor.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/AMGPsensor.o.d" -o ${OBJECTDIR}/AMGPsensor.o AMGPsensor.c    
	
${OBJECTDIR}/BMA150.o: BMA150.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BMA150.o.d 
	@${RM} ${OBJECTDIR}/BMA150.o.ok ${OBJECTDIR}/BMA150.o.err 
	@${FIXDEPS} "${OBJECTDIR}/BMA150.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/BMA150.o.d" -o ${OBJECTDIR}/BMA150.o BMA150.c    
	
${OBJECTDIR}/BMP085.o: BMP085.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BMP085.o.d 
	@${RM} ${OBJECTDIR}/BMP085.o.ok ${OBJECTDIR}/BMP085.o.err 
	@${FIXDEPS} "${OBJECTDIR}/BMP085.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/BMP085.o.d" -o ${OBJECTDIR}/BMP085.o BMP085.c    
	
${OBJECTDIR}/HMC5883.o: HMC5883.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/HMC5883.o.d 
	@${RM} ${OBJECTDIR}/HMC5883.o.ok ${OBJECTDIR}/HMC5883.o.err 
	@${FIXDEPS} "${OBJECTDIR}/HMC5883.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/HMC5883.o.d" -o ${OBJECTDIR}/HMC5883.o HMC5883.c    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_SensorCard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_SensorCard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_SensorCard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_SensorCard.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_SensorCard.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
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
