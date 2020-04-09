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
//extern eAutopilotState autopilot_state;
//extern Speed_t Vehicle_Speed;
extern Direction_t Vehicle_Direction;


/*	S E M A P H O R E S   */
//extern SemaphoreHandle_t semButton;
extern SemaphoreHandle_t mDirectionData;
extern SemaphoreHandle_t mSystemState;
//extern SemaphoreHandle_t mAutopilotState;


/*	T A S K   H A N D L E S   */
TaskHandle_t thLEDTask;
TaskHandle_t thLCDDisplay;

/*  P R I V A T E   V A R I A B L E S   */


/*	T A S K   */

void DirectionTask(void * pvParameters) {
	const TickType_t delay_time = pdMS_TO_TICKS(50);

	static eSystemState sys_state;
//	static eAutopilotState ap_state;

	static uint8_t capsense_pos;
	eDirection direction = Straight;
	int8_t angle;
//	eDirection old_direction = Straight;

	// init
	CAPSENSE_Init();	// initialize hardware

	while(1) {
		capsense_pos = get_capsense_position();

		// Get system state
		xSemaphoreTake(mSystemState, 0);
		sys_state = system_state;
		xSemaphoreGive(mSystemState);

		// Get autopilot state
//		xSemaphoreTake(mAutopilotState, 0);
//		ap_state = autopilot_state;
//		xSemaphoreGive(mAutopilotState);

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
				switch(capsense_pos) {
					case(1): direction = Hard_Left; angle = -60; break;
					case(2): direction = Left; 		angle = -30; break;
					case(3): direction = Right; 	angle =  30; break;
					case(4): direction = Hard_Right; angle = 60; break;
					default: direction = Straight; 	angle = 0; break;
				}

				xSemaphoreTake(mDirectionData, 10); 		// get mutex
				Vehicle_Direction.direction = direction; 	// update global variable
				Vehicle_Direction.angle = angle;
				xSemaphoreGive(mDirectionData);  			// release mutex
				break;
			}
			case(GameOver): {
				break;
			}
			case(HighScore): {
				break;
			}
		}
		vTaskDelay(delay_time);
	}
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
