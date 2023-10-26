################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Lcd/Lcd.c 

OBJS += \
./HAL/Lcd/Lcd.o 

C_DEPS += \
./HAL/Lcd/Lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Lcd/%.o: ../HAL/Lcd/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Eclipse\Avr_Driver\MCAL\Timer0" -I"D:\Eclipse\Avr_Driver\HAL\Lcd" -I"D:\Eclipse\Avr_Driver" -I"D:\Eclipse\Avr_Driver\HAL\KeyPad" -I"D:\Eclipse\Avr_Driver\HAL\SSD" -I"D:\Eclipse\Avr_Driver\Service" -I"D:\Eclipse\Avr_Driver\APP" -I"D:\Eclipse\Avr_Driver\MCAL\Dio" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


