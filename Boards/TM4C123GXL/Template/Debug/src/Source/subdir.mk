################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Source/app_control.c \
../src/Source/app_him.c \
../src/Source/app_info.c \
../src/Source/main.c \
../src/Source/startup_gcc.c \
../src/Source/sys_ad.c \
../src/Source/sys_gpio.c \
../src/Source/sys_hw.c \
../src/Source/sys_i2c.c \
../src/Source/sys_mcu.c \
../src/Source/sys_pwm.c \
../src/Source/sys_spi.c \
../src/Source/sys_timer.c \
../src/Source/sys_uart.c 

OBJS += \
./src/Source/app_control.o \
./src/Source/app_him.o \
./src/Source/app_info.o \
./src/Source/main.o \
./src/Source/startup_gcc.o \
./src/Source/sys_ad.o \
./src/Source/sys_gpio.o \
./src/Source/sys_hw.o \
./src/Source/sys_i2c.o \
./src/Source/sys_mcu.o \
./src/Source/sys_pwm.o \
./src/Source/sys_spi.o \
./src/Source/sys_timer.o \
./src/Source/sys_uart.o 

C_DEPS += \
./src/Source/app_control.d \
./src/Source/app_him.d \
./src/Source/app_info.d \
./src/Source/main.d \
./src/Source/startup_gcc.d \
./src/Source/sys_ad.d \
./src/Source/sys_gpio.d \
./src/Source/sys_hw.d \
./src/Source/sys_i2c.d \
./src/Source/sys_mcu.d \
./src/Source/sys_pwm.d \
./src/Source/sys_spi.d \
./src/Source/sys_timer.d \
./src/Source/sys_uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/Source/%.o: ../src/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -D__LM4C123G -DARM_MATH_CM4 -DPART_LM4F123GH6M -DTARGET_IS_BLIZZARD_RA1 -I"/home/jaga/JAGAV1.1.0/Boards/TM4C123GXL/Template/src/Util" -I"/home/jaga/JAGAV1.1.0/Boards/TM4C123GXL/Template/src/Middleware" -I"/home/jaga/JAGAV1.1.0/Boards/TM4C123GXL/Template/src/TM4C123GXL" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


