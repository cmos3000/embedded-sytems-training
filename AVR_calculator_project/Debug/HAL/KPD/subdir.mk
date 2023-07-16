################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KPD/Keypad_config.c \
../HAL/KPD/Keypad_prog.c 

OBJS += \
./HAL/KPD/Keypad_config.o \
./HAL/KPD/Keypad_prog.o 

C_DEPS += \
./HAL/KPD/Keypad_config.d \
./HAL/KPD/Keypad_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KPD/%.o: ../HAL/KPD/%.c HAL/KPD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


