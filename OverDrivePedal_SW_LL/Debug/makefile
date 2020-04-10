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
OverDrivePedal_SW_LL.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
OverDrivePedal_SW_LL.list \

OBJCOPY_BIN += \
OverDrivePedal_SW_LL.bin \


# All Target
all: OverDrivePedal_SW_LL.elf secondary-outputs

# Tool invocations
OverDrivePedal_SW_LL.elf: $(OBJS) $(USER_OBJS) /home/chris/Projects/Embedded/OverDrivePedal_sw/OverDrivePedal_SW_LL/STM32L011D4PX_FLASH.ld
	arm-none-eabi-gcc -o "OverDrivePedal_SW_LL.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"/home/chris/Projects/Embedded/OverDrivePedal_sw/OverDrivePedal_SW_LL/STM32L011D4PX_FLASH.ld" --specs=nosys.specs -Wl,-Map="OverDrivePedal_SW_LL.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

OverDrivePedal_SW_LL.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "OverDrivePedal_SW_LL.list"
	@echo 'Finished building: $@'
	@echo ' '

OverDrivePedal_SW_LL.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "OverDrivePedal_SW_LL.bin"
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
