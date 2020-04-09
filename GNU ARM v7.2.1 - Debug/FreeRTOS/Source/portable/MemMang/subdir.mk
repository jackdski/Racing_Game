################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/MemMang/heap_4.o: ../FreeRTOS/Source/portable/MemMang/heap_4.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"FreeRTOS/Source/portable/MemMang/heap_4.d" -MT"FreeRTOS/Source/portable/MemMang/heap_4.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


