/*
 * FreeRTOSConfig.h
 *
 *  Created on: Mar 19, 2020
 *      Author: jack
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "efm32pg12b500f1024gl125.h"

/* redirect FreeRTOS port interrupts */
#define vPortSVCHandler         SVC_Handler
#define xPortPendSVHandler      PendSV_Handler
#define xPortSysTickHandler     SysTick_Handler


/* Constants related to the behaviour or the scheduler. */
#define configUSE_PREEMPTION                    1
//#define configUSE_TIME_SLICING                    1
#define configMAX_PRIORITIES                    ( 5 )
#define configIDLE_SHOULD_YIELD                 1
#define configTICK_RATE_HZ                      ( ( TickType_t ) 1000 )  // 1ms/tick
#define configUSE_16_BIT_TICKS                  1

/* Constants that describe the hardware and memory usage. */
#define configCPU_CLOCK_HZ                      38000000        // 38MHz
#define configMINIMAL_STACK_SIZE                ( ( uint16_t ) 100 )
#define configMAX_TASK_NAME_LEN                 ( 16 )

/* TODO: look at datasheet for heap size */
#define configTOTAL_HEAP_SIZE                   ( ( size_t ) 12000)  // ( 50 * 1024 ) )

#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0
#define configUSE_MUTEXES               1
#define configUSE_RECURSIVE_MUTEXES     1
#define configUSE_MALLOC_FAILED_HOOK    1
#define configUSE_APPLICATION_TASK_TAG  0
#define configUSE_COUNTING_SEMAPHORES   1       // use Counting Semaphores
#define configUSE_TASK_NOTIFICATIONS    1       // use Task Notifications
#define configUSE_TICKLESS_IDLE         0       // TODO: use Tickless Idle for long periods of sleep
#define configUSE_CO_ROUTINES           0
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0

#define configQUEUE_REGISTRY_SIZE       8
#define configCHECK_FOR_STACK_OVERFLOW  2
#define configMESSAGE_BUFFER_LENGTH_TYPE            size_t//uint8_t

/* Software timer definitions. */
#define configUSE_TIMERS                1
#define configTIMER_TASK_PRIORITY       ( 3 )
#define configTIMER_QUEUE_LENGTH        5
#define configTIMER_TASK_STACK_DEPTH    ( 200 )

/* Normal assert() semantics without relying on the provision of an assert.h
header file. */
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* Optional functions - most linkers will remove unused functions anyway. */
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskCleanUpResources           1
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_xResumeFromISR                  1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_xTaskGetSchedulerState          1
#define INCLUDE_xTaskGetCurrentTaskHandle       1
#define INCLUDE_uxTaskGetStackHighWaterMark     0
#define INCLUDE_xTaskGetIdleTaskHandle          1
#define INCLUDE_xTaskGetCurrentTaskHandle       1
#define INCLUDE_eTaskGetState                   1
#define INCLUDE_xEventGroupSetBitFromISR        1
#define INCLUDE_xTimerPendFunctionCall          1
#define INCLUDE_xTaskAbortDelay                 0
#define INCLUDE_xTaskGetHandle                  1
#define INCLUDE_xTaskResumeFromISR              1
#define INCLUDE_xSemaphoreGetMutexHolder        1
#define INCLUDE_eTaskGetState                   1
#define INCLUDE_pxTaskGetStackStart				1

/* Cortex-M3/4 interrupt priority configuration follows...................... */
/* Use the system definition, if there is one. */
#define configPRIO_BITS       __NVIC_PRIO_BITS


/* The lowest interrupt priority that can be used in a call to a "set priority"
function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         0x07

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY         ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

#include "SEGGER_SYSVIEW_FreeRTOS.h"

#endif /* FREERTOS_CONFIG_H */
