################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SEGGER/SEGGER_HardFaultHandler.c \
../SEGGER/SEGGER_RTT.c \
../SEGGER/SEGGER_SYSVIEW.c \
../SEGGER/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./SEGGER/SEGGER_HardFaultHandler.o \
./SEGGER/SEGGER_RTT.o \
./SEGGER/SEGGER_SYSVIEW.o \
./SEGGER/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./SEGGER/SEGGER_HardFaultHandler.d \
./SEGGER/SEGGER_RTT.d \
./SEGGER/SEGGER_SYSVIEW.d \
./SEGGER/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
SEGGER/SEGGER_HardFaultHandler.o: ../SEGGER/SEGGER_HardFaultHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"SEGGER/SEGGER_HardFaultHandler.d" -MT"SEGGER/SEGGER_HardFaultHandler.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SEGGER/SEGGER_RTT.o: ../SEGGER/SEGGER_RTT.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"SEGGER/SEGGER_RTT.d" -MT"SEGGER/SEGGER_RTT.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SEGGER/SEGGER_SYSVIEW.o: ../SEGGER/SEGGER_SYSVIEW.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"SEGGER/SEGGER_SYSVIEW.d" -MT"SEGGER/SEGGER_SYSVIEW.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SEGGER/SEGGER_SYSVIEW_FreeRTOS.o: ../SEGGER/SEGGER_SYSVIEW_FreeRTOS.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"SEGGER/SEGGER_SYSVIEW_FreeRTOS.d" -MT"SEGGER/SEGGER_SYSVIEW_FreeRTOS.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


