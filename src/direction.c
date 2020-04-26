/*
 * direction.c
 *
 *  Created on: Mar 21, 2020
 *      Author: jack
 */

/*  I N C L U D E S   */
#include <stdbool.h>
#include <stdint.h>
#include "direction.h"

/*  G L O B A L   V A R I A B L E S   */
extern eSystemState system_state;
extern Speed_t Vehicle_Speed;
extern Direction_t Vehicle_Direction;


/*	S E M A P H O R E S   */
//extern SemaphoreHandle_t semButton;
extern SemaphoreHandle_t mDirectionData;
extern SemaphoreHandle_t mSystemState;
extern SemaphoreHandle_t mSpeedData;
//extern SemaphoreHandle_t mAutopilotState;


/*	T A S K   H A N D L E S   */
TaskHandle_t thLEDTask;
TaskHandle_t thLCDDisplay;

/*  P R I V A T E   V A R I A B L E S   */
static eSystemState sys_state;
static TimerHandle_t sys_state_timer;

/*	T A S K   */

void DirectionTask(void * pvParameters) {
	const TickType_t delay_time = pdMS_TO_TICKS(200);

	static uint8_t capsense_pos;
	eDirection direction = Straight;
	int8_t angle;

	sys_state_timer = xTimerCreate("sys state Timer", pdMS_TO_TICKS(400), pdTRUE, (void*)0, tmr_get_system_state);
	xTimerStart(sys_state_timer, 10);

	// init
	CAPSENSE_Init();	// initialize hardware

	while(1) {
		capsense_pos = get_capsense_position();

		switch(sys_state) {
			case(Startup): {
				break;
			}
			case(Configuration): {
				static uint8_t old_pos = 0;
				if(capsense_pos != old_pos) {  // only update on taps, not holds
					old_pos = capsense_pos;
					switch(capsense_pos) {
						case(1): {
							xTaskNotify(thLCDDisplay, LCD_CONFIG_VAL_PREV, eSetValueWithOverwrite);
							break;
						}
						case(4): {
							xTaskNotify(thLCDDisplay, LCD_CONFIG_VAL_NEXT, eSetValueWithOverwrite);
							break;
						}
						default: break;
					}
				}
				break;
			}
			case(GetReady): {
				break;
			}
			case(Gameplay): {
				// update direction based on latest sample
				uint32_t speed;
				if(xSemaphoreTake(mSpeedData, 30)) {
					speed = Vehicle_Speed.speed;
					xSemaphoreGive(mSpeedData);
				}
				switch(capsense_pos) {
					case(1): direction = Hard_Left;  angle =  45.0; break;
					case(2): direction = Left; 		 angle =  15.0; break;
					case(3): direction = Right;		 angle = -15.0; break;
					case(4): direction = Hard_Right; angle = -45.0; break;
					default: direction = Straight; 	 angle =   0.0; break;
				}

				xSemaphoreTake(mDirectionData, 30);
				Vehicle_Direction.direction = direction; 	// update global variable
				if(speed > 0) {
					Vehicle_Direction.angle += angle;
				}
				if(Vehicle_Direction.angle > 360.0) {
					Vehicle_Direction.angle -= 360.0;
				}
				else if(Vehicle_Direction.angle < 0.0) {
					Vehicle_Direction.angle += 360;
				}
				xSemaphoreGive(mDirectionData);
				break;
			}
			case(GameOver): {
				xSemaphoreTake(mDirectionData, 10);
				Vehicle_Direction.direction = Straight;
				Vehicle_Direction.position = 0;
				Vehicle_Direction.angle = 0.0;
				xSemaphoreGive(mDirectionData);
				break;
			}
			case(HighScore): {
				break;
			}
		}
		vTaskDelay(delay_time);
	}
}

void tmr_get_system_state(TimerHandle_t xTimer) {
	// Get system state
	xSemaphoreTake(mSystemState, 100);
	sys_state = system_state;
	xSemaphoreGive(mSystemState);
}


/*
 * @brief Returns the position of the capsense button being pressed
 *
 * @return Capsense button being pressed [1-4], returns 0 if more than one is pressed
 */
uint8_t get_capsense_position(void) {
	/* Use the default STK capacitive sensing setup and enable it */
	ACMP_Enable(ACMP_CAPSENSE);
	CAPSENSE_Sense();

	bool sensors_touched[NUM_SLIDER_CHANNELS];
	uint8_t num_sensors_touched = 0;
	uint8_t i;
	for(i = 0; i < NUM_SLIDER_CHANNELS; i++) {
		sensors_touched[i] = CAPSENSE_getPressed(i);
		if(sensors_touched[i] == 1) {
			num_sensors_touched++;
		}
	}
	ACMP_Disable(ACMP_CAPSENSE);

	if((num_sensors_touched == 0) || (num_sensors_touched > 1)) {
		return 0;
	}
	else {
		for(i = 0; i < NUM_SLIDER_CHANNELS; i++) {
			if(sensors_touched[i] == 1) {
				return i+1;
			}
		}
	}
	return 0;
}
