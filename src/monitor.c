/*
 * monitor.c
 *
 *  Created on: Apr 6, 2020
 *      Author: jack
 */

/*  I N C L U D E S   */
#include "monitor.h"

/*  G L O B A L   V A R I A B L E S   */
//extern eSystemState system_state;
//extern Speed_t Vehicle_Speed;
extern Vehicle_t vehicle;
extern Track_t track;

/*	S E M A P H O R E S   */
//extern SemaphoreHandle_t mSpeedData;
//extern SemaphoreHandle_t mSystemState;
//extern SemaphoreHandle_t mAutopilotState;
//extern SemaphoreHandle_t mVehicleData;

/*	T A S K   H A N D L E S   */
TaskHandle_t thLEDTask;
TaskHandle_t thLCDDisplay;

/*  P R I V A T E   V A R I A B L E S   */

/*	T A S K   */

void VehicleMonitorTask(void * pvParameters) {
	const TickType_t delay_time = pdMS_TO_TICKS(50);

	while(1) {
		if(track.waypoints[track.index].distance_marker < vehicle.distance_covered) {
			track.index++;
			if(track.index > track.num_waypoints + 3) {
				xTaskNotify(thLCDDisplay, MONITOR_GAMEOVER, eSetValueWithOverwrite);
			}
		}

		vTaskDelay(delay_time);
	}
}


