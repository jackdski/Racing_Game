################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../FreeRTOS/Source/portable/CCS/ARM_CM4F/portasm.asm 

C_SRCS += \
../FreeRTOS/Source/portable/CCS/ARM_CM4F/port.c 

OBJS += \
./FreeRTOS/Source/portable/CCS/ARM_CM4F/port.o \
./FreeRTOS/Source/portable/CCS/ARM_CM4F/portasm.o 

C_DEPS += \
./FreeRTOS/Source/portable/CCS/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/CCS/ARM_CM4F/port.o: ../FreeRTOS/Source/portable/CCS/ARM_CM4F/port.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"FreeRTOS/Source/portable/CCS/ARM_CM4F/port.d" -MT"FreeRTOS/Source/portable/CCS/ARM_CM4F/port.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/portable/CCS/ARM_CM4F/%.o: ../FreeRTOS/Source/portable/CCS/ARM_CM4F/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -c -x assembler-with-cpp -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" '-DEFM32PG12B500F1024GL125=1' -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


