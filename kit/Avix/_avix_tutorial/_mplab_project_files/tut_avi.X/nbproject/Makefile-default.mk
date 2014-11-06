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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/tut_avi.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/tut_avi.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../../_AVIX/Cnfg/AVIXConfig.c ../../src/tutorial08_Pipes.c ../../src/_tutoriallMain.c ../../src/tutorial01_RoundRobin.c ../../src/tutorial02_RoundRobin.c ../../src/tutorial03_Preemption.c ../../src/tutorial04_Timer.c ../../src/tutorial05_EventFlags.c ../../src/tutorial06_EventFlags.c ../../src/tutorial07_Messages.c ../../src/tutorial09_Exchange.c ../../../sys_files/src/systemSetup.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1348425177/AVIXConfig.o ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o ${OBJECTDIR}/_ext/904859371/systemSetup.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d ${OBJECTDIR}/_ext/904859371/systemSetup.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1348425177/AVIXConfig.o ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o ${OBJECTDIR}/_ext/904859371/systemSetup.o

# Source Files
SOURCEFILES=../../../_AVIX/Cnfg/AVIXConfig.c ../../src/tutorial08_Pipes.c ../../src/_tutoriallMain.c ../../src/tutorial01_RoundRobin.c ../../src/tutorial02_RoundRobin.c ../../src/tutorial03_Preemption.c ../../src/tutorial04_Timer.c ../../src/tutorial05_EventFlags.c ../../src/tutorial06_EventFlags.c ../../src/tutorial07_Messages.c ../../src/tutorial09_Exchange.c ../../../sys_files/src/systemSetup.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/tut_avi.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ256GB210
MP_LINKER_FILE_OPTION=,--script=p24FJ256GB210.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1348425177/AVIXConfig.o: ../../../_AVIX/Cnfg/AVIXConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1348425177 
	@${RM} ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../_AVIX/Cnfg/AVIXConfig.c  -o ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o: ../../src/tutorial08_Pipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial08_Pipes.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o: ../../src/_tutoriallMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/_tutoriallMain.c  -o ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o: ../../src/tutorial01_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial01_RoundRobin.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o: ../../src/tutorial02_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial02_RoundRobin.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o: ../../src/tutorial03_Preemption.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial03_Preemption.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o: ../../src/tutorial04_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial04_Timer.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o: ../../src/tutorial05_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial05_EventFlags.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o: ../../src/tutorial06_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial06_EventFlags.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o: ../../src/tutorial07_Messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial07_Messages.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o: ../../src/tutorial09_Exchange.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial09_Exchange.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/904859371/systemSetup.o: ../../../sys_files/src/systemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/904859371 
	@${RM} ${OBJECTDIR}/_ext/904859371/systemSetup.o.d 
	@${RM} ${OBJECTDIR}/_ext/904859371/systemSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../sys_files/src/systemSetup.c  -o ${OBJECTDIR}/_ext/904859371/systemSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/904859371/systemSetup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/904859371/systemSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1348425177/AVIXConfig.o: ../../../_AVIX/Cnfg/AVIXConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1348425177 
	@${RM} ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../_AVIX/Cnfg/AVIXConfig.c  -o ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o: ../../src/tutorial08_Pipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial08_Pipes.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o: ../../src/_tutoriallMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/_tutoriallMain.c  -o ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o: ../../src/tutorial01_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial01_RoundRobin.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o: ../../src/tutorial02_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial02_RoundRobin.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o: ../../src/tutorial03_Preemption.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial03_Preemption.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o: ../../src/tutorial04_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial04_Timer.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o: ../../src/tutorial05_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial05_EventFlags.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o: ../../src/tutorial06_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial06_EventFlags.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o: ../../src/tutorial07_Messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial07_Messages.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o: ../../src/tutorial09_Exchange.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../src/tutorial09_Exchange.c  -o ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/904859371/systemSetup.o: ../../../sys_files/src/systemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/904859371 
	@${RM} ${OBJECTDIR}/_ext/904859371/systemSetup.o.d 
	@${RM} ${OBJECTDIR}/_ext/904859371/systemSetup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../sys_files/src/systemSetup.c  -o ${OBJECTDIR}/_ext/904859371/systemSetup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/904859371/systemSetup.o.d"      -mno-eds-warn  -g -omf=elf -O0 -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -I"." -msmart-io=1 -Wall -msfr-warn=off -fno-pcc-struct-return
	@${FIXDEPS} "${OBJECTDIR}/_ext/904859371/systemSetup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/tut_avi.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../_AVIX/Lib/AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/tut_avi.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\_AVIX\Lib\AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.tut_avi.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/tut_avi.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../_AVIX/Lib/AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/tut_avi.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\_AVIX\Lib\AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.tut_avi.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/tut_avi.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
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
