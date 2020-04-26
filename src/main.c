/*
 * @file main.c
 *
 * @author jdanielski
 *
 */

/*  I N C L U D E S   */
#include "em_device.h"
#include "em_chip.h"
#include "em_emu.h"

#include "SEGGER_SYSVIEW.h"

#include "configurations.h"
#include "cmu.h"
#include "direction.h"
#include "high_score.h"
#include "lcd_display.h"
#include "led.h"
#include "monitor.h"
#include "speed.h"
#include "tracks.h"

/*  F R E E R T O S   I N C L U D E S   */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/*  F R E E R T O S   H O O K S   */
void vApplicationMallocFailedHook( void );
void vApplicationIdleHook( void );
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
void vPreSleepProcessing( uint32_t ulExpectedIdleTime );
void vApplicationTickHook( void);
void *malloc( size_t xSize );


/*  G L O B A L   V A R I A B L E S   */
eSystemState system_state = Startup;
Vehicle_t vehicle;
eAutopilotState autopilot_state = Autopilot_Disabled;
Speed_t Vehicle_Speed;
Direction_t Vehicle_Direction;
Track_t track;
Track_Settings_t track_settings;
High_Score_List_t high_scores;
Active_Warnings_t active_warnings;


/*	S E M A P H O R E S   */
SemaphoreHandle_t semButton;
SemaphoreHandle_t mSpeedData;
SemaphoreHandle_t mDirectionData;
SemaphoreHandle_t mSystemState;
SemaphoreHandle_t mAutopilotState;
SemaphoreHandle_t mVehicleData;
SemaphoreHandle_t mTrack;

/*	T A S K   H A N D L E S   */
TaskHandle_t thLEDTask;
TaskHandle_t thLCDDisplay;
TaskHandle_t thVehMon;


/*  M A I N   */
int main(void)
{
  /* Chip errata */
  CHIP_Init();

  /* set clock to 38MHz */
  cmu_open();

  // init tracks
  init_tracks();

  /* Initialize global structs */
  vehicle_init(&vehicle);
  vehicle_speed_init(&Vehicle_Speed);
  vehicle_direction_init(&Vehicle_Direction);
  track_settings_init(&track_settings);
  init_high_score_list(&high_scores);

  SEGGER_SYSVIEW_Conf();

  /* Semaphore(s) */
  semButton = xSemaphoreCreateBinary();

  /* Mutex(s) */
  mSpeedData = xSemaphoreCreateMutex();
  mDirectionData = xSemaphoreCreateMutex();
  mSystemState = xSemaphoreCreateMutex();
  mAutopilotState = xSemaphoreCreateMutex();
  mVehicleData = xSemaphoreCreateMutex();
  mTrack = xSemaphoreCreateMutex();

  /* Create Tasks */
  xTaskCreate(LedTask, "L E D S", 100, (void *)NULL, 4, &thLEDTask);
  xTaskCreate(DisplayTask, "LCD Display", 350, (void*)NULL, 1, &thLCDDisplay);
  xTaskCreate(SpeedTask, "Speed Task", 200, (void*)NULL, 2, NULL);
  xTaskCreate(DirectionTask, "Direction", 200, (void*)NULL, 2, NULL);
  xTaskCreate(VehicleMonitorTask, "VehMonitor", 200, (void*)NULL, 1, &thVehMon);

  /* Suspend Vehicle Monitor Task */
  vTaskSuspend(thVehMon);

  /* Start RTOS Scheduler */
  vTaskStartScheduler();

  /* Infinite loop */
  while (1);
}


void vApplicationMallocFailedHook( void )
{
    taskDISABLE_INTERRUPTS();
    for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
    for( ;; ) {
    	// sleep when the opportunity is given
    	EMU_EnterEM1();
    }
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    ( void ) pcTaskName;
    ( void ) pxTask;
    taskDISABLE_INTERRUPTS();
    for( ;; );
}

void vPreSleepProcessing( uint32_t ulExpectedIdleTime ) {
	return;
}

void vApplicationTickHook( void ) {
//    for( ;; );
	return;
}

void *malloc( size_t xSize ) {
    for( ;; );
}
