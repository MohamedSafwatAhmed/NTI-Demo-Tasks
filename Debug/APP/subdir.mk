################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Counting_Up.c \
../APP/Timer_time.c \
../APP/main.c 

OBJS += \
./APP/Counting_Up.o \
./APP/Timer_time.o \
./APP/main.o 

C_DEPS += \
./APP/Counting_Up.d \
./APP/Timer_time.d \
./APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Eclipse\Avr_Driver\MCAL\Timer0" -I"D:\Eclipse\Avr_Driver\HAL\Lcd" -I"D:\Eclipse\Avr_Driver" -I"D:\Eclipse\Avr_Driver\HAL\KeyPad" -I"D:\Eclipse\Avr_Driver\HAL\SSD" -I"D:\Eclipse\Avr_Driver\Service" -I"D:\Eclipse\Avr_Driver\APP" -I"D:\Eclipse\Avr_Driver\MCAL\Dio" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


