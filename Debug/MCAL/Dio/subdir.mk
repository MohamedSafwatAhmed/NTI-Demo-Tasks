################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Dio/Dio.c 

OBJS += \
./MCAL/Dio/Dio.o 

C_DEPS += \
./MCAL/Dio/Dio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Dio/Dio.o: ../MCAL/Dio/Dio.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Eclipse\Avr_Driver\Service" -I"D:\Eclipse\Avr_Driver\APP" -I"D:\Eclipse\Avr_Driver\MCAL\Dio" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"MCAL/Dio/Dio.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


