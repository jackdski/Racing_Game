################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/croutine.c \
../FreeRTOS/Source/event_groups.c \
../FreeRTOS/Source/list.c \
../FreeRTOS/Source/queue.c \
../FreeRTOS/Source/stream_buffer.c \
../FreeRTOS/Source/tasks.c \
../FreeRTOS/Source/timers.c 

OBJS += \
./FreeRTOS/Source/croutine.o \
./FreeRTOS/Source/event_groups.o \
./FreeRTOS/Source/list.o \
./FreeRTOS/Source/queue.o \
./FreeRTOS/Source/stream_buffer.o \
./FreeRTOS/Source/tasks.o \
./FreeRTOS/Source/timers.o 

C_DEPS += \
./FreeRTOS/Source/croutine.d \
./FreeRTOS/Source/event_groups.d \
./FreeRTOS/Source/list.d \
./FreeRTOS/Source/queue.d \
./FreeRTOS/Source/stream_buffer.d \
./FreeRTOS/Source/tasks.d \
./FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/croutine.o: ../FreeRTOS/Source/croutine.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"FreeRTOS/Source/croutine.d" -MT"FreeRTOS/Source/croutine.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/event_groups.o: ../FreeRTOS/Source/event_groups.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"FreeRTOS/Source/event_groups.d" -MT"FreeRTOS/Source/event_groups.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/list.o: ../FreeRTOS/Source/list.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"FreeRTOS/Source/list.d" -MT"FreeRTOS/Source/list.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/queue.o: ../FreeRTOS/Source/queue.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"FreeRTOS/Source/queue.d" -MT"FreeRTOS/Source/queue.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/stream_buffer.o: ../FreeRTOS/Source/stream_buffer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"FreeRTOS/Source/stream_buffer.d" -MT"FreeRTOS/Source/stream_buffer.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/tasks.o: ../FreeRTOS/Source/tasks.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"FreeRTOS/Source/tasks.d" -MT"FreeRTOS/Source/tasks.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/timers.o: ../FreeRTOS/Source/timers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"FreeRTOS/Source/timers.d" -MT"FreeRTOS/Source/timers.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


