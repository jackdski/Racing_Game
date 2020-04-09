################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cmu.c \
../src/configurations.c \
../src/direction.c \
../src/fifo.c \
../src/high_score.c \
../src/lcd_display.c \
../src/led.c \
../src/main.c \
../src/monitor.c \
../src/speed.c \
../src/tracks.c 

OBJS += \
./src/cmu.o \
./src/configurations.o \
./src/direction.o \
./src/fifo.o \
./src/high_score.o \
./src/lcd_display.o \
./src/led.o \
./src/main.o \
./src/monitor.o \
./src/speed.o \
./src/tracks.o 

C_DEPS += \
./src/cmu.d \
./src/configurations.d \
./src/direction.d \
./src/fifo.d \
./src/high_score.d \
./src/lcd_display.d \
./src/led.d \
./src/main.d \
./src/monitor.d \
./src/speed.d \
./src/tracks.d 


# Each subdirectory must supply rules for building sources it contributes
src/cmu.o: ../src/cmu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/cmu.d" -MT"src/cmu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/configurations.o: ../src/configurations.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/configurations.d" -MT"src/configurations.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/direction.o: ../src/direction.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/direction.d" -MT"src/direction.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fifo.o: ../src/fifo.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/fifo.d" -MT"src/fifo.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/high_score.o: ../src/high_score.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/high_score.d" -MT"src/high_score.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lcd_display.o: ../src/lcd_display.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/lcd_display.d" -MT"src/lcd_display.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/led.o: ../src/led.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/led.d" -MT"src/led.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/main.d" -MT"src/main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/monitor.o: ../src/monitor.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/monitor.d" -MT"src/monitor.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/speed.o: ../src/speed.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/speed.d" -MT"src/speed.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/tracks.o: ../src/tracks.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFM32PG12B500F1024GL125=1' -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/bsp" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/common/drivers" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32PG12B/Include" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//hardware/kit/SLSTK3402A_EFM32PG12/config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/include" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/MemMang" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/src" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/glib" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/dmd/ssd2119" -I"/home/jack/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v2.6//platform/middleware/glib/" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Graphics" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/Config" -I"/home/jack/SimplicityStudio/v4_workspace/jdanielski_Final_Project/SEGGER" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/tracks.d" -MT"src/tracks.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


