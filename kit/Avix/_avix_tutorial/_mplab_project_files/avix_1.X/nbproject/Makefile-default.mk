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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/avix_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/avix_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/avix_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/1348425177/AVIXConfig.o: ../../../_AVIX/Cnfg/AVIXConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1348425177 
	@${RM} ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.ok ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.err 
	@${RM} ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d" -o ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o ../../../_AVIX/Cnfg/AVIXConfig.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o: ../../src/tutorial08_Pipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o ../../src/tutorial08_Pipes.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o: ../../src/_tutoriallMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.ok ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d" -o ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o ../../src/_tutoriallMain.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o: ../../src/tutorial01_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o ../../src/tutorial01_RoundRobin.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o: ../../src/tutorial02_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o ../../src/tutorial02_RoundRobin.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o: ../../src/tutorial03_Preemption.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o ../../src/tutorial03_Preemption.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o: ../../src/tutorial04_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o ../../src/tutorial04_Timer.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o: ../../src/tutorial05_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o ../../src/tutorial05_EventFlags.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o: ../../src/tutorial06_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o ../../src/tutorial06_EventFlags.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o: ../../src/tutorial07_Messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o ../../src/tutorial07_Messages.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o: ../../src/tutorial09_Exchange.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o ../../src/tutorial09_Exchange.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/904859371/systemSetup.o: ../../../sys_files/src/systemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/904859371 
	@${RM} ${OBJECTDIR}/_ext/904859371/systemSetup.o.d 
	@${RM} ${OBJECTDIR}/_ext/904859371/systemSetup.o.ok ${OBJECTDIR}/_ext/904859371/systemSetup.o.err 
	@${RM} ${OBJECTDIR}/_ext/904859371/systemSetup.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/904859371/systemSetup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/904859371/systemSetup.o.d" -o ${OBJECTDIR}/_ext/904859371/systemSetup.o ../../../sys_files/src/systemSetup.c     -fno-pcc-struct-return
	
else
${OBJECTDIR}/_ext/1348425177/AVIXConfig.o: ../../../_AVIX/Cnfg/AVIXConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1348425177 
	@${RM} ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.ok ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.err 
	@${RM} ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1348425177/AVIXConfig.o.d" -o ${OBJECTDIR}/_ext/1348425177/AVIXConfig.o ../../../_AVIX/Cnfg/AVIXConfig.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o: ../../src/tutorial08_Pipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial08_Pipes.o ../../src/tutorial08_Pipes.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o: ../../src/_tutoriallMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.ok ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o.d" -o ${OBJECTDIR}/_ext/1445274692/_tutoriallMain.o ../../src/_tutoriallMain.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o: ../../src/tutorial01_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial01_RoundRobin.o ../../src/tutorial01_RoundRobin.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o: ../../src/tutorial02_RoundRobin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial02_RoundRobin.o ../../src/tutorial02_RoundRobin.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o: ../../src/tutorial03_Preemption.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial03_Preemption.o ../../src/tutorial03_Preemption.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o: ../../src/tutorial04_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial04_Timer.o ../../src/tutorial04_Timer.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o: ../../src/tutorial05_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial05_EventFlags.o ../../src/tutorial05_EventFlags.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o: ../../src/tutorial06_EventFlags.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial06_EventFlags.o ../../src/tutorial06_EventFlags.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o: ../../src/tutorial07_Messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial07_Messages.o ../../src/tutorial07_Messages.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o: ../../src/tutorial09_Exchange.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445274692 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.ok ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.err 
	@${RM} ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o.d" -o ${OBJECTDIR}/_ext/1445274692/tutorial09_Exchange.o ../../src/tutorial09_Exchange.c     -fno-pcc-struct-return
	
${OBJECTDIR}/_ext/904859371/systemSetup.o: ../../../sys_files/src/systemSetup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/904859371 
	@${RM} ${OBJECTDIR}/_ext/904859371/systemSetup.o.d 
	@${RM} ${OBJECTDIR}/_ext/904859371/systemSetup.o.ok ${OBJECTDIR}/_ext/904859371/systemSetup.o.err 
	@${RM} ${OBJECTDIR}/_ext/904859371/systemSetup.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/904859371/systemSetup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../../_AVIX/Interface" -I"../../../_AVIX/Utilities/Interface" -MMD -MF "${OBJECTDIR}/_ext/904859371/systemSetup.o.d" -o ${OBJECTDIR}/_ext/904859371/systemSetup.o ../../../sys_files/src/systemSetup.c     -fno-pcc-struct-return
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/avix_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../_AVIX/Lib/AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG  -o dist/${CND_CONF}/${IMAGE_TYPE}/avix_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   ..\..\..\_AVIX\Lib\AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a      -Wl,--defsym=__MPLAB_BUILD=1,-L".."$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/avix_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../_AVIX/Lib/AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/avix_1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   ..\..\..\_AVIX\Lib\AVIX_PIC24-dsPIC_MICROCHIP_MPLAB_FD_050000_PIC24FJ256GB210_FH.a      -Wl,--defsym=__MPLAB_BUILD=1,-L".."$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/avix_1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
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
