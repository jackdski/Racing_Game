################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include SEGGER/subdir.mk
-include Graphics/subdir.mk
-include FreeRTOS/Source/portable/MemMang/subdir.mk
-include FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include FreeRTOS/Source/subdir.mk
-include Drivers/subdir.mk
-include Config/subdir.mk
-include CMSIS/EFM32PG12B/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: jdanielski_Final_Project.axf

# Tool invocations
jdanielski_Final_Project.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "jdanielski_Final_Project.ld" -Xlinker --gc-sections -Xlinker -Map="jdanielski_Final_Project.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o jdanielski_Final_Project.axf "./src/cmu.o" "./src/configurations.o" "./src/direction.o" "./src/fifo.o" "./src/lcd_display.o" "./src/led.o" "./src/main.o" "./src/monitor.o" "./src/speed.o" "./src/tracks.o" "./emlib/em_acmp.o" "./emlib/em_adc.o" "./emlib/em_aes.o" "./emlib/em_assert.o" "./emlib/em_burtc.o" "./emlib/em_can.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_cryotimer.o" "./emlib/em_crypto.o" "./emlib/em_csen.o" "./emlib/em_dac.o" "./emlib/em_dbg.o" "./emlib/em_dma.o" "./emlib/em_ebi.o" "./emlib/em_emu.o" "./emlib/em_gpcrc.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_iadc.o" "./emlib/em_idac.o" "./emlib/em_int.o" "./emlib/em_lcd.o" "./emlib/em_ldma.o" "./emlib/em_lesense.o" "./emlib/em_letimer.o" "./emlib/em_leuart.o" "./emlib/em_mpu.o" "./emlib/em_msc.o" "./emlib/em_opamp.o" "./emlib/em_pcnt.o" "./emlib/em_pdm.o" "./emlib/em_prs.o" "./emlib/em_qspi.o" "./emlib/em_rmu.o" "./emlib/em_rtc.o" "./emlib/em_rtcc.o" "./emlib/em_se.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./emlib/em_vcmp.o" "./emlib/em_vdac.o" "./emlib/em_wdog.o" "./SEGGER/SEGGER_HardFaultHandler.o" "./SEGGER/SEGGER_RTT.o" "./SEGGER/SEGGER_SYSVIEW.o" "./SEGGER/SEGGER_SYSVIEW_FreeRTOS.o" "./Graphics/dmd_display.o" "./Graphics/glib.o" "./Graphics/glib_bitmap.o" "./Graphics/glib_circle.o" "./Graphics/glib_font_narrow_6x8.o" "./Graphics/glib_font_normal_8x8.o" "./Graphics/glib_font_number_16x20.o" "./Graphics/glib_line.o" "./Graphics/glib_polygon.o" "./Graphics/glib_rectangle.o" "./Graphics/glib_string.o" "./FreeRTOS/Source/portable/MemMang/heap_4.o" "./FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o" "./FreeRTOS/Source/croutine.o" "./FreeRTOS/Source/event_groups.o" "./FreeRTOS/Source/list.o" "./FreeRTOS/Source/queue.o" "./FreeRTOS/Source/stream_buffer.o" "./FreeRTOS/Source/tasks.o" "./FreeRTOS/Source/timers.o" "./Drivers/capsense.o" "./Drivers/display.o" "./Drivers/displayls013b7dh03.o" "./Drivers/displaypalemlib.o" "./Drivers/retargetio.o" "./Drivers/retargettextdisplay.o" "./Drivers/textdisplay.o" "./Drivers/udelay.o" "./Config/SEGGER_SYSVIEW_Config_FreeRTOS.o" "./CMSIS/EFM32PG12B/startup_gcc_efm32pg12b.o" "./CMSIS/EFM32PG12B/system_efm32pg12b.o" -lm "./src/high_score.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: jdanielski_Final_Project.hex'
	arm-none-eabi-objcopy -O ihex "jdanielski_Final_Project.axf" "jdanielski_Final_Project.hex"
	@echo ' '

	@echo 'Building bin file: jdanielski_Final_Project.bin'
	arm-none-eabi-objcopy -O binary "jdanielski_Final_Project.axf" "jdanielski_Final_Project.bin"
	@echo ' '

	@echo 'Building s37 file: jdanielski_Final_Project.s37'
	arm-none-eabi-objcopy -O srec "jdanielski_Final_Project.axf" "jdanielski_Final_Project.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "jdanielski_Final_Project.axf" -A
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) jdanielski_Final_Project.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
