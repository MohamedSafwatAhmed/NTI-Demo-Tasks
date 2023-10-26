################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer0/subdir.mk
-include MCAL/Dio/subdir.mk
-include HAL/SSD/subdir.mk
-include HAL/Lcd/subdir.mk
-include HAL/KeyPad/subdir.mk
-include APP/Calculator/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Avr_Driver.lss \
Avr_Driver.lss \

FLASH_IMAGE += \
Avr_Driver.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \


# All Target
all: Avr_Driver.elf secondary-outputs

# Tool invocations
Avr_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Avr_Driver.map -mmcu=atmega32 -o "Avr_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Avr_Driver.lss: Avr_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Avr_Driver.elf  >"Avr_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

Avr_Driver.hex: Avr_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Avr_Driver.elf  "Avr_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Avr_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Avr_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Avr_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
