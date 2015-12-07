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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Template.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Template.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../../../Middleware/buttons/buttons.c ../../../../Middleware/info_hw/info_hw.c ../../../../Middleware/lcd/lcd.c ../../../../Middleware/leds/leds.c ../../../../HAL/PIC18F4550/ad/hal_ad.c ../../../../HAL/PIC18F4550/delay/hal_delay.c ../../../../HAL/PIC18F4550/eeprom/hal_eeprom.c ../../../../HAL/PIC18F4550/flash/hal_flash.c ../../../../HAL/PIC18F4550/gpio/hal_gpio.c ../../../../HAL/PIC18F4550/i2c/hal_i2c.c ../../../../HAL/PIC18F4550/interrupt/hal_interrupts.c ../../../../HAL/PIC18F4550/pwm/hal_pwm.c ../../../../HAL/PIC18F4550/reset/hal_reset.c ../../../../HAL/PIC18F4550/spi/hal_spi.c ../../../../HAL/PIC18F4550/timer/hal_timer.c ../../../../HAL/PIC18F4550/uart/hal_uart.c ../Source/main.c ../Source/sys_timer.c ../Source/sys_i2c.c ../Source/sys_ad.c ../Source/sys_spi.c ../Source/sys_pwm.c ../Source/sys_uart.c ../Source/app_control.c ../Source/app_him.c ../Source/app_info.c ../Source/sys_gpio.c ../Source/sys_hw.c ../Source/sys_mcu.c ../../../../Util/crc/crc.c ../../../../Util/PID/pid.c ../../../../Util/xprintf/xprintf.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/755039388/buttons.p1 ${OBJECTDIR}/_ext/949021219/info_hw.p1 ${OBJECTDIR}/_ext/188133584/lcd.p1 ${OBJECTDIR}/_ext/1537171771/leds.p1 ${OBJECTDIR}/_ext/1891564187/hal_ad.p1 ${OBJECTDIR}/_ext/1614864127/hal_delay.p1 ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1 ${OBJECTDIR}/_ext/1612818578/hal_flash.p1 ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1 ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1 ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1 ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1 ${OBJECTDIR}/_ext/1601927987/hal_reset.p1 ${OBJECTDIR}/_ext/1491070122/hal_spi.p1 ${OBJECTDIR}/_ext/1599967549/hal_timer.p1 ${OBJECTDIR}/_ext/1021420912/hal_uart.p1 ${OBJECTDIR}/_ext/1728301206/main.p1 ${OBJECTDIR}/_ext/1728301206/sys_timer.p1 ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1 ${OBJECTDIR}/_ext/1728301206/sys_ad.p1 ${OBJECTDIR}/_ext/1728301206/sys_spi.p1 ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1 ${OBJECTDIR}/_ext/1728301206/sys_uart.p1 ${OBJECTDIR}/_ext/1728301206/app_control.p1 ${OBJECTDIR}/_ext/1728301206/app_him.p1 ${OBJECTDIR}/_ext/1728301206/app_info.p1 ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1 ${OBJECTDIR}/_ext/1728301206/sys_hw.p1 ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1 ${OBJECTDIR}/_ext/430495143/crc.p1 ${OBJECTDIR}/_ext/430475582/pid.p1 ${OBJECTDIR}/_ext/484809764/xprintf.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/755039388/buttons.p1.d ${OBJECTDIR}/_ext/949021219/info_hw.p1.d ${OBJECTDIR}/_ext/188133584/lcd.p1.d ${OBJECTDIR}/_ext/1537171771/leds.p1.d ${OBJECTDIR}/_ext/1891564187/hal_ad.p1.d ${OBJECTDIR}/_ext/1614864127/hal_delay.p1.d ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1.d ${OBJECTDIR}/_ext/1612818578/hal_flash.p1.d ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1.d ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1.d ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1.d ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1.d ${OBJECTDIR}/_ext/1601927987/hal_reset.p1.d ${OBJECTDIR}/_ext/1491070122/hal_spi.p1.d ${OBJECTDIR}/_ext/1599967549/hal_timer.p1.d ${OBJECTDIR}/_ext/1021420912/hal_uart.p1.d ${OBJECTDIR}/_ext/1728301206/main.p1.d ${OBJECTDIR}/_ext/1728301206/sys_timer.p1.d ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1.d ${OBJECTDIR}/_ext/1728301206/sys_ad.p1.d ${OBJECTDIR}/_ext/1728301206/sys_spi.p1.d ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1.d ${OBJECTDIR}/_ext/1728301206/sys_uart.p1.d ${OBJECTDIR}/_ext/1728301206/app_control.p1.d ${OBJECTDIR}/_ext/1728301206/app_him.p1.d ${OBJECTDIR}/_ext/1728301206/app_info.p1.d ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1.d ${OBJECTDIR}/_ext/1728301206/sys_hw.p1.d ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1.d ${OBJECTDIR}/_ext/430495143/crc.p1.d ${OBJECTDIR}/_ext/430475582/pid.p1.d ${OBJECTDIR}/_ext/484809764/xprintf.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/755039388/buttons.p1 ${OBJECTDIR}/_ext/949021219/info_hw.p1 ${OBJECTDIR}/_ext/188133584/lcd.p1 ${OBJECTDIR}/_ext/1537171771/leds.p1 ${OBJECTDIR}/_ext/1891564187/hal_ad.p1 ${OBJECTDIR}/_ext/1614864127/hal_delay.p1 ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1 ${OBJECTDIR}/_ext/1612818578/hal_flash.p1 ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1 ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1 ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1 ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1 ${OBJECTDIR}/_ext/1601927987/hal_reset.p1 ${OBJECTDIR}/_ext/1491070122/hal_spi.p1 ${OBJECTDIR}/_ext/1599967549/hal_timer.p1 ${OBJECTDIR}/_ext/1021420912/hal_uart.p1 ${OBJECTDIR}/_ext/1728301206/main.p1 ${OBJECTDIR}/_ext/1728301206/sys_timer.p1 ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1 ${OBJECTDIR}/_ext/1728301206/sys_ad.p1 ${OBJECTDIR}/_ext/1728301206/sys_spi.p1 ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1 ${OBJECTDIR}/_ext/1728301206/sys_uart.p1 ${OBJECTDIR}/_ext/1728301206/app_control.p1 ${OBJECTDIR}/_ext/1728301206/app_him.p1 ${OBJECTDIR}/_ext/1728301206/app_info.p1 ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1 ${OBJECTDIR}/_ext/1728301206/sys_hw.p1 ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1 ${OBJECTDIR}/_ext/430495143/crc.p1 ${OBJECTDIR}/_ext/430475582/pid.p1 ${OBJECTDIR}/_ext/484809764/xprintf.p1

# Source Files
SOURCEFILES=../../../../Middleware/buttons/buttons.c ../../../../Middleware/info_hw/info_hw.c ../../../../Middleware/lcd/lcd.c ../../../../Middleware/leds/leds.c ../../../../HAL/PIC18F4550/ad/hal_ad.c ../../../../HAL/PIC18F4550/delay/hal_delay.c ../../../../HAL/PIC18F4550/eeprom/hal_eeprom.c ../../../../HAL/PIC18F4550/flash/hal_flash.c ../../../../HAL/PIC18F4550/gpio/hal_gpio.c ../../../../HAL/PIC18F4550/i2c/hal_i2c.c ../../../../HAL/PIC18F4550/interrupt/hal_interrupts.c ../../../../HAL/PIC18F4550/pwm/hal_pwm.c ../../../../HAL/PIC18F4550/reset/hal_reset.c ../../../../HAL/PIC18F4550/spi/hal_spi.c ../../../../HAL/PIC18F4550/timer/hal_timer.c ../../../../HAL/PIC18F4550/uart/hal_uart.c ../Source/main.c ../Source/sys_timer.c ../Source/sys_i2c.c ../Source/sys_ad.c ../Source/sys_spi.c ../Source/sys_pwm.c ../Source/sys_uart.c ../Source/app_control.c ../Source/app_him.c ../Source/app_info.c ../Source/sys_gpio.c ../Source/sys_hw.c ../Source/sys_mcu.c ../../../../Util/crc/crc.c ../../../../Util/PID/pid.c ../../../../Util/xprintf/xprintf.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Template.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4550
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/755039388/buttons.p1: ../../../../Middleware/buttons/buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/755039388" 
	@${RM} ${OBJECTDIR}/_ext/755039388/buttons.p1.d 
	@${RM} ${OBJECTDIR}/_ext/755039388/buttons.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/755039388/buttons.p1  ../../../../Middleware/buttons/buttons.c 
	@-${MV} ${OBJECTDIR}/_ext/755039388/buttons.d ${OBJECTDIR}/_ext/755039388/buttons.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/755039388/buttons.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/949021219/info_hw.p1: ../../../../Middleware/info_hw/info_hw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/949021219" 
	@${RM} ${OBJECTDIR}/_ext/949021219/info_hw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/949021219/info_hw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/949021219/info_hw.p1  ../../../../Middleware/info_hw/info_hw.c 
	@-${MV} ${OBJECTDIR}/_ext/949021219/info_hw.d ${OBJECTDIR}/_ext/949021219/info_hw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/949021219/info_hw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/188133584/lcd.p1: ../../../../Middleware/lcd/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/188133584" 
	@${RM} ${OBJECTDIR}/_ext/188133584/lcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/188133584/lcd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/188133584/lcd.p1  ../../../../Middleware/lcd/lcd.c 
	@-${MV} ${OBJECTDIR}/_ext/188133584/lcd.d ${OBJECTDIR}/_ext/188133584/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/188133584/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1537171771/leds.p1: ../../../../Middleware/leds/leds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1537171771" 
	@${RM} ${OBJECTDIR}/_ext/1537171771/leds.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1537171771/leds.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1537171771/leds.p1  ../../../../Middleware/leds/leds.c 
	@-${MV} ${OBJECTDIR}/_ext/1537171771/leds.d ${OBJECTDIR}/_ext/1537171771/leds.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1537171771/leds.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1891564187/hal_ad.p1: ../../../../HAL/PIC18F4550/ad/hal_ad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1891564187" 
	@${RM} ${OBJECTDIR}/_ext/1891564187/hal_ad.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1891564187/hal_ad.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1891564187/hal_ad.p1  ../../../../HAL/PIC18F4550/ad/hal_ad.c 
	@-${MV} ${OBJECTDIR}/_ext/1891564187/hal_ad.d ${OBJECTDIR}/_ext/1891564187/hal_ad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1891564187/hal_ad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1614864127/hal_delay.p1: ../../../../HAL/PIC18F4550/delay/hal_delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1614864127" 
	@${RM} ${OBJECTDIR}/_ext/1614864127/hal_delay.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1614864127/hal_delay.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1614864127/hal_delay.p1  ../../../../HAL/PIC18F4550/delay/hal_delay.c 
	@-${MV} ${OBJECTDIR}/_ext/1614864127/hal_delay.d ${OBJECTDIR}/_ext/1614864127/hal_delay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1614864127/hal_delay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1: ../../../../HAL/PIC18F4550/eeprom/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1507584066" 
	@${RM} ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1  ../../../../HAL/PIC18F4550/eeprom/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/_ext/1507584066/hal_eeprom.d ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1612818578/hal_flash.p1: ../../../../HAL/PIC18F4550/flash/hal_flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1612818578" 
	@${RM} ${OBJECTDIR}/_ext/1612818578/hal_flash.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1612818578/hal_flash.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1612818578/hal_flash.p1  ../../../../HAL/PIC18F4550/flash/hal_flash.c 
	@-${MV} ${OBJECTDIR}/_ext/1612818578/hal_flash.d ${OBJECTDIR}/_ext/1612818578/hal_flash.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1612818578/hal_flash.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1021823855/hal_gpio.p1: ../../../../HAL/PIC18F4550/gpio/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1021823855" 
	@${RM} ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1021823855/hal_gpio.p1  ../../../../HAL/PIC18F4550/gpio/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/_ext/1021823855/hal_gpio.d ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1491058584/hal_i2c.p1: ../../../../HAL/PIC18F4550/i2c/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1491058584" 
	@${RM} ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1491058584/hal_i2c.p1  ../../../../HAL/PIC18F4550/i2c/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/1491058584/hal_i2c.d ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1: ../../../../HAL/PIC18F4550/interrupt/hal_interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1284659487" 
	@${RM} ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1  ../../../../HAL/PIC18F4550/interrupt/hal_interrupts.c 
	@-${MV} ${OBJECTDIR}/_ext/1284659487/hal_interrupts.d ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1491067460/hal_pwm.p1: ../../../../HAL/PIC18F4550/pwm/hal_pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1491067460" 
	@${RM} ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1491067460/hal_pwm.p1  ../../../../HAL/PIC18F4550/pwm/hal_pwm.c 
	@-${MV} ${OBJECTDIR}/_ext/1491067460/hal_pwm.d ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1601927987/hal_reset.p1: ../../../../HAL/PIC18F4550/reset/hal_reset.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1601927987" 
	@${RM} ${OBJECTDIR}/_ext/1601927987/hal_reset.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1601927987/hal_reset.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1601927987/hal_reset.p1  ../../../../HAL/PIC18F4550/reset/hal_reset.c 
	@-${MV} ${OBJECTDIR}/_ext/1601927987/hal_reset.d ${OBJECTDIR}/_ext/1601927987/hal_reset.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1601927987/hal_reset.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1491070122/hal_spi.p1: ../../../../HAL/PIC18F4550/spi/hal_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1491070122" 
	@${RM} ${OBJECTDIR}/_ext/1491070122/hal_spi.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1491070122/hal_spi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1491070122/hal_spi.p1  ../../../../HAL/PIC18F4550/spi/hal_spi.c 
	@-${MV} ${OBJECTDIR}/_ext/1491070122/hal_spi.d ${OBJECTDIR}/_ext/1491070122/hal_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1491070122/hal_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1599967549/hal_timer.p1: ../../../../HAL/PIC18F4550/timer/hal_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1599967549" 
	@${RM} ${OBJECTDIR}/_ext/1599967549/hal_timer.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1599967549/hal_timer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1599967549/hal_timer.p1  ../../../../HAL/PIC18F4550/timer/hal_timer.c 
	@-${MV} ${OBJECTDIR}/_ext/1599967549/hal_timer.d ${OBJECTDIR}/_ext/1599967549/hal_timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1599967549/hal_timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1021420912/hal_uart.p1: ../../../../HAL/PIC18F4550/uart/hal_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1021420912" 
	@${RM} ${OBJECTDIR}/_ext/1021420912/hal_uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1021420912/hal_uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1021420912/hal_uart.p1  ../../../../HAL/PIC18F4550/uart/hal_uart.c 
	@-${MV} ${OBJECTDIR}/_ext/1021420912/hal_uart.d ${OBJECTDIR}/_ext/1021420912/hal_uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1021420912/hal_uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/main.p1: ../Source/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/main.p1  ../Source/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/main.d ${OBJECTDIR}/_ext/1728301206/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_timer.p1: ../Source/sys_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_timer.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_timer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_timer.p1  ../Source/sys_timer.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_timer.d ${OBJECTDIR}/_ext/1728301206/sys_timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_i2c.p1: ../Source/sys_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_i2c.p1  ../Source/sys_i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_i2c.d ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_ad.p1: ../Source/sys_ad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_ad.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_ad.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_ad.p1  ../Source/sys_ad.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_ad.d ${OBJECTDIR}/_ext/1728301206/sys_ad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_ad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_spi.p1: ../Source/sys_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_spi.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_spi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_spi.p1  ../Source/sys_spi.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_spi.d ${OBJECTDIR}/_ext/1728301206/sys_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_pwm.p1: ../Source/sys_pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_pwm.p1  ../Source/sys_pwm.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_pwm.d ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_uart.p1: ../Source/sys_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_uart.p1  ../Source/sys_uart.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_uart.d ${OBJECTDIR}/_ext/1728301206/sys_uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/app_control.p1: ../Source/app_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_control.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_control.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/app_control.p1  ../Source/app_control.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/app_control.d ${OBJECTDIR}/_ext/1728301206/app_control.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/app_control.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/app_him.p1: ../Source/app_him.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_him.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_him.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/app_him.p1  ../Source/app_him.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/app_him.d ${OBJECTDIR}/_ext/1728301206/app_him.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/app_him.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/app_info.p1: ../Source/app_info.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_info.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_info.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/app_info.p1  ../Source/app_info.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/app_info.d ${OBJECTDIR}/_ext/1728301206/app_info.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/app_info.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_gpio.p1: ../Source/sys_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_gpio.p1  ../Source/sys_gpio.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_gpio.d ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_hw.p1: ../Source/sys_hw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_hw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_hw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_hw.p1  ../Source/sys_hw.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_hw.d ${OBJECTDIR}/_ext/1728301206/sys_hw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_hw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_mcu.p1: ../Source/sys_mcu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_mcu.p1  ../Source/sys_mcu.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_mcu.d ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/430495143/crc.p1: ../../../../Util/crc/crc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/430495143" 
	@${RM} ${OBJECTDIR}/_ext/430495143/crc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/430495143/crc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/430495143/crc.p1  ../../../../Util/crc/crc.c 
	@-${MV} ${OBJECTDIR}/_ext/430495143/crc.d ${OBJECTDIR}/_ext/430495143/crc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/430495143/crc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/430475582/pid.p1: ../../../../Util/PID/pid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/430475582" 
	@${RM} ${OBJECTDIR}/_ext/430475582/pid.p1.d 
	@${RM} ${OBJECTDIR}/_ext/430475582/pid.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/430475582/pid.p1  ../../../../Util/PID/pid.c 
	@-${MV} ${OBJECTDIR}/_ext/430475582/pid.d ${OBJECTDIR}/_ext/430475582/pid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/430475582/pid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/484809764/xprintf.p1: ../../../../Util/xprintf/xprintf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/484809764" 
	@${RM} ${OBJECTDIR}/_ext/484809764/xprintf.p1.d 
	@${RM} ${OBJECTDIR}/_ext/484809764/xprintf.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/484809764/xprintf.p1  ../../../../Util/xprintf/xprintf.c 
	@-${MV} ${OBJECTDIR}/_ext/484809764/xprintf.d ${OBJECTDIR}/_ext/484809764/xprintf.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/484809764/xprintf.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/755039388/buttons.p1: ../../../../Middleware/buttons/buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/755039388" 
	@${RM} ${OBJECTDIR}/_ext/755039388/buttons.p1.d 
	@${RM} ${OBJECTDIR}/_ext/755039388/buttons.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/755039388/buttons.p1  ../../../../Middleware/buttons/buttons.c 
	@-${MV} ${OBJECTDIR}/_ext/755039388/buttons.d ${OBJECTDIR}/_ext/755039388/buttons.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/755039388/buttons.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/949021219/info_hw.p1: ../../../../Middleware/info_hw/info_hw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/949021219" 
	@${RM} ${OBJECTDIR}/_ext/949021219/info_hw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/949021219/info_hw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/949021219/info_hw.p1  ../../../../Middleware/info_hw/info_hw.c 
	@-${MV} ${OBJECTDIR}/_ext/949021219/info_hw.d ${OBJECTDIR}/_ext/949021219/info_hw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/949021219/info_hw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/188133584/lcd.p1: ../../../../Middleware/lcd/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/188133584" 
	@${RM} ${OBJECTDIR}/_ext/188133584/lcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/188133584/lcd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/188133584/lcd.p1  ../../../../Middleware/lcd/lcd.c 
	@-${MV} ${OBJECTDIR}/_ext/188133584/lcd.d ${OBJECTDIR}/_ext/188133584/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/188133584/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1537171771/leds.p1: ../../../../Middleware/leds/leds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1537171771" 
	@${RM} ${OBJECTDIR}/_ext/1537171771/leds.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1537171771/leds.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1537171771/leds.p1  ../../../../Middleware/leds/leds.c 
	@-${MV} ${OBJECTDIR}/_ext/1537171771/leds.d ${OBJECTDIR}/_ext/1537171771/leds.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1537171771/leds.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1891564187/hal_ad.p1: ../../../../HAL/PIC18F4550/ad/hal_ad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1891564187" 
	@${RM} ${OBJECTDIR}/_ext/1891564187/hal_ad.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1891564187/hal_ad.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1891564187/hal_ad.p1  ../../../../HAL/PIC18F4550/ad/hal_ad.c 
	@-${MV} ${OBJECTDIR}/_ext/1891564187/hal_ad.d ${OBJECTDIR}/_ext/1891564187/hal_ad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1891564187/hal_ad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1614864127/hal_delay.p1: ../../../../HAL/PIC18F4550/delay/hal_delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1614864127" 
	@${RM} ${OBJECTDIR}/_ext/1614864127/hal_delay.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1614864127/hal_delay.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1614864127/hal_delay.p1  ../../../../HAL/PIC18F4550/delay/hal_delay.c 
	@-${MV} ${OBJECTDIR}/_ext/1614864127/hal_delay.d ${OBJECTDIR}/_ext/1614864127/hal_delay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1614864127/hal_delay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1: ../../../../HAL/PIC18F4550/eeprom/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1507584066" 
	@${RM} ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1  ../../../../HAL/PIC18F4550/eeprom/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/_ext/1507584066/hal_eeprom.d ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1507584066/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1612818578/hal_flash.p1: ../../../../HAL/PIC18F4550/flash/hal_flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1612818578" 
	@${RM} ${OBJECTDIR}/_ext/1612818578/hal_flash.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1612818578/hal_flash.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1612818578/hal_flash.p1  ../../../../HAL/PIC18F4550/flash/hal_flash.c 
	@-${MV} ${OBJECTDIR}/_ext/1612818578/hal_flash.d ${OBJECTDIR}/_ext/1612818578/hal_flash.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1612818578/hal_flash.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1021823855/hal_gpio.p1: ../../../../HAL/PIC18F4550/gpio/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1021823855" 
	@${RM} ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1021823855/hal_gpio.p1  ../../../../HAL/PIC18F4550/gpio/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/_ext/1021823855/hal_gpio.d ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1021823855/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1491058584/hal_i2c.p1: ../../../../HAL/PIC18F4550/i2c/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1491058584" 
	@${RM} ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1491058584/hal_i2c.p1  ../../../../HAL/PIC18F4550/i2c/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/1491058584/hal_i2c.d ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1491058584/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1: ../../../../HAL/PIC18F4550/interrupt/hal_interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1284659487" 
	@${RM} ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1  ../../../../HAL/PIC18F4550/interrupt/hal_interrupts.c 
	@-${MV} ${OBJECTDIR}/_ext/1284659487/hal_interrupts.d ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1284659487/hal_interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1491067460/hal_pwm.p1: ../../../../HAL/PIC18F4550/pwm/hal_pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1491067460" 
	@${RM} ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1491067460/hal_pwm.p1  ../../../../HAL/PIC18F4550/pwm/hal_pwm.c 
	@-${MV} ${OBJECTDIR}/_ext/1491067460/hal_pwm.d ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1491067460/hal_pwm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1601927987/hal_reset.p1: ../../../../HAL/PIC18F4550/reset/hal_reset.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1601927987" 
	@${RM} ${OBJECTDIR}/_ext/1601927987/hal_reset.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1601927987/hal_reset.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1601927987/hal_reset.p1  ../../../../HAL/PIC18F4550/reset/hal_reset.c 
	@-${MV} ${OBJECTDIR}/_ext/1601927987/hal_reset.d ${OBJECTDIR}/_ext/1601927987/hal_reset.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1601927987/hal_reset.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1491070122/hal_spi.p1: ../../../../HAL/PIC18F4550/spi/hal_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1491070122" 
	@${RM} ${OBJECTDIR}/_ext/1491070122/hal_spi.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1491070122/hal_spi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1491070122/hal_spi.p1  ../../../../HAL/PIC18F4550/spi/hal_spi.c 
	@-${MV} ${OBJECTDIR}/_ext/1491070122/hal_spi.d ${OBJECTDIR}/_ext/1491070122/hal_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1491070122/hal_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1599967549/hal_timer.p1: ../../../../HAL/PIC18F4550/timer/hal_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1599967549" 
	@${RM} ${OBJECTDIR}/_ext/1599967549/hal_timer.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1599967549/hal_timer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1599967549/hal_timer.p1  ../../../../HAL/PIC18F4550/timer/hal_timer.c 
	@-${MV} ${OBJECTDIR}/_ext/1599967549/hal_timer.d ${OBJECTDIR}/_ext/1599967549/hal_timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1599967549/hal_timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1021420912/hal_uart.p1: ../../../../HAL/PIC18F4550/uart/hal_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1021420912" 
	@${RM} ${OBJECTDIR}/_ext/1021420912/hal_uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1021420912/hal_uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1021420912/hal_uart.p1  ../../../../HAL/PIC18F4550/uart/hal_uart.c 
	@-${MV} ${OBJECTDIR}/_ext/1021420912/hal_uart.d ${OBJECTDIR}/_ext/1021420912/hal_uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1021420912/hal_uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/main.p1: ../Source/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/main.p1  ../Source/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/main.d ${OBJECTDIR}/_ext/1728301206/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_timer.p1: ../Source/sys_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_timer.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_timer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_timer.p1  ../Source/sys_timer.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_timer.d ${OBJECTDIR}/_ext/1728301206/sys_timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_i2c.p1: ../Source/sys_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_i2c.p1  ../Source/sys_i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_i2c.d ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_ad.p1: ../Source/sys_ad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_ad.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_ad.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_ad.p1  ../Source/sys_ad.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_ad.d ${OBJECTDIR}/_ext/1728301206/sys_ad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_ad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_spi.p1: ../Source/sys_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_spi.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_spi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_spi.p1  ../Source/sys_spi.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_spi.d ${OBJECTDIR}/_ext/1728301206/sys_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_pwm.p1: ../Source/sys_pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_pwm.p1  ../Source/sys_pwm.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_pwm.d ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_pwm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_uart.p1: ../Source/sys_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_uart.p1  ../Source/sys_uart.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_uart.d ${OBJECTDIR}/_ext/1728301206/sys_uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/app_control.p1: ../Source/app_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_control.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_control.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/app_control.p1  ../Source/app_control.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/app_control.d ${OBJECTDIR}/_ext/1728301206/app_control.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/app_control.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/app_him.p1: ../Source/app_him.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_him.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_him.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/app_him.p1  ../Source/app_him.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/app_him.d ${OBJECTDIR}/_ext/1728301206/app_him.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/app_him.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/app_info.p1: ../Source/app_info.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_info.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/app_info.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/app_info.p1  ../Source/app_info.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/app_info.d ${OBJECTDIR}/_ext/1728301206/app_info.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/app_info.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_gpio.p1: ../Source/sys_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_gpio.p1  ../Source/sys_gpio.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_gpio.d ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_hw.p1: ../Source/sys_hw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_hw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_hw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_hw.p1  ../Source/sys_hw.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_hw.d ${OBJECTDIR}/_ext/1728301206/sys_hw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_hw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1728301206/sys_mcu.p1: ../Source/sys_mcu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1728301206/sys_mcu.p1  ../Source/sys_mcu.c 
	@-${MV} ${OBJECTDIR}/_ext/1728301206/sys_mcu.d ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1728301206/sys_mcu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/430495143/crc.p1: ../../../../Util/crc/crc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/430495143" 
	@${RM} ${OBJECTDIR}/_ext/430495143/crc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/430495143/crc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/430495143/crc.p1  ../../../../Util/crc/crc.c 
	@-${MV} ${OBJECTDIR}/_ext/430495143/crc.d ${OBJECTDIR}/_ext/430495143/crc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/430495143/crc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/430475582/pid.p1: ../../../../Util/PID/pid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/430475582" 
	@${RM} ${OBJECTDIR}/_ext/430475582/pid.p1.d 
	@${RM} ${OBJECTDIR}/_ext/430475582/pid.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/430475582/pid.p1  ../../../../Util/PID/pid.c 
	@-${MV} ${OBJECTDIR}/_ext/430475582/pid.d ${OBJECTDIR}/_ext/430475582/pid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/430475582/pid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/484809764/xprintf.p1: ../../../../Util/xprintf/xprintf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/484809764" 
	@${RM} ${OBJECTDIR}/_ext/484809764/xprintf.p1.d 
	@${RM} ${OBJECTDIR}/_ext/484809764/xprintf.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/484809764/xprintf.p1  ../../../../Util/xprintf/xprintf.c 
	@-${MV} ${OBJECTDIR}/_ext/484809764/xprintf.d ${OBJECTDIR}/_ext/484809764/xprintf.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/484809764/xprintf.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Template.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/Template.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     --rom=default,-7dc0-7fff --ram=default,-3f4-3ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  -odist/${CND_CONF}/${IMAGE_TYPE}/Template.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Template.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Template.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/Template.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -D__PIC18F4550 -P -N255 -I"../../../../HAL/PIC18F4550" -I"../../../../Middleware" -I"../Header" -I"../../../../Util" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -odist/${CND_CONF}/${IMAGE_TYPE}/Template.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
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

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
