################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
OverDriverPedal_sw2.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
OverDriverPedal_sw2.list \

OBJCOPY_BIN += \
OverDriverPedal_sw2.bin \


# All Target
all: OverDriverPedal_sw2.elf secondary-outputs

# Tool invocations
OverDriverPedal_sw2.elf: $(OBJS) $(USER_OBJS) /home/chris/Projects/Embedded/OverDrivePedal_sw/OverDriverPedal_sw2/STM32L011D4PX_FLASH.ld
	arm-none-eabi-gcc -o "OverDriverPedal_sw2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"/home/chris/Projects/Embedded/OverDrivePedal_sw/OverDriverPedal_sw2/STM32L011D4PX_FLASH.ld" --specs=nosys.specs -Wl,-Map="OverDriverPedal_sw2.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

OverDriverPedal_sw2.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "OverDriverPedal_sw2.list"
	@echo 'Finished building: $@'
	@echo ' '

OverDriverPedal_sw2.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "OverDriverPedal_sw2.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
