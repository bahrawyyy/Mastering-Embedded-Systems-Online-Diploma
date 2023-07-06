################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
Unit7Lab1_GPIO_STM.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Unit7Lab1_GPIO_STM.list \

OBJCOPY_HEX += \
Unit7Lab1_GPIO_STM.hex \

OBJCOPY_BIN += \
Unit7Lab1_GPIO_STM.bin \


# All Target
all: Unit7Lab1_GPIO_STM.elf secondary-outputs

# Tool invocations
Unit7Lab1_GPIO_STM.elf: $(OBJS) $(USER_OBJS) C:\Users\Abdallah\STM32CubeIDE\workspace_1.4.0\Unit7Lab1_GPIO_STM\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Unit7Lab1_GPIO_STM.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Abdallah\STM32CubeIDE\workspace_1.4.0\Unit7Lab1_GPIO_STM\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Unit7Lab1_GPIO_STM.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Unit7Lab1_GPIO_STM.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Unit7Lab1_GPIO_STM.list"
	@echo 'Finished building: $@'
	@echo ' '

Unit7Lab1_GPIO_STM.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Unit7Lab1_GPIO_STM.hex"
	@echo 'Finished building: $@'
	@echo ' '

Unit7Lab1_GPIO_STM.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Unit7Lab1_GPIO_STM.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
