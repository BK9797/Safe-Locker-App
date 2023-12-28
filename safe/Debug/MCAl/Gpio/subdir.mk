################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAl/Gpio/gpio.c 

OBJS += \
./MCAl/Gpio/gpio.o 

C_DEPS += \
./MCAl/Gpio/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAl/Gpio/%.o: ../MCAl/Gpio/%.c MCAl/Gpio/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/Users/bishoykamel/Documents/Study/Projects/safe/HAL/Keybad" -I"/Users/bishoykamel/Documents/Study/Projects/safe/HAL/LCD" -I"/Users/bishoykamel/Documents/Study/Projects/safe/HAL/Led" -I"/Users/bishoykamel/Documents/Study/Projects/safe/Libraries" -I"/Users/bishoykamel/Documents/Study/Projects/safe/MCAl" -I"/Users/bishoykamel/Documents/Study/Projects/safe/APP" -I"/Users/bishoykamel/Documents/Study/Projects/safe/HAL" -I"/Users/bishoykamel/Documents/Study/Projects/safe/MCAl/Gpio" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


