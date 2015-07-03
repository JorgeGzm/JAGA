################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TM4C123GXL/gpio/hal_gpio.c 

OBJS += \
./src/TM4C123GXL/gpio/hal_gpio.o 

C_DEPS += \
./src/TM4C123GXL/gpio/hal_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
src/TM4C123GXL/gpio/%.o: ../src/TM4C123GXL/gpio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DARM_MATH_CM4 -DPART_LM4F123GH6M -DTARGET_IS_BLIZZARD_RA1 -I"/home/jaga/git/JAGA/Boards/TM4C123GXL/workspace/Template/src/Util" -I"/home/jaga/git/JAGA/Boards/TM4C123GXL/workspace/Template/src/TM4C123GXL" -I"/home/jaga/git/JAGA/Boards/TM4C123GXL/workspace/Template/src/Middleware" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


