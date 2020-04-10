/*
 * speed.c
 *
 *  Created on: Mar 20, 2020
 *      Author: jack
 */

/*  I N C L U D E S   */
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "speed.h"

/*  G L O B A L   V A R I A B L E S   */
extern eSystemState system_state;
extern eAutopilotState autopilot_state;
extern Speed_t Vehicle_Speed;
extern Vehicle_t vehicle;
//extern Track_t track;

/*	S E M A P H O R E S   */
extern SemaphoreHandle_t mSpeedData;
extern SemaphoreHandle_t mSystemState;
extern SemaphoreHandle_t mAutopilotState;
extern SemaphoreHandle_t mVehicleData;

/*	T A S K   H A N D L E S   */
TaskHandle_t thLEDTask;
TaskHandle_t thLCDDisplay;

/*  P R I V A T E   V A R I A B L E S   */
static TimerHandle_t autopilot_timer;
static TimerHandle_t confirm_timer;
static TimerHandle_t accelerator_distance_timer;


/*	T A S K   */

void SpeedTask(void * pvParameters) {
	uint8_t delay_ms = 50;
	const TickType_t delay_time = pdMS_TO_TICKS(delay_ms);
	const TickType_t config_delay_time = pdMS_TO_TICKS(200);
	const TickType_t timer_period = pdMS_TO_TICKS(1000);

//	static Vehicle_t veh;
	static eSystemState sys_state;
	static eAutopilotState ap_state;

	static bool buttons_held = false;
	static eButtonState button_zero_state = false;
	static eButtonState button_one_state = false;

	// init
	gpio_init_buttons();
	autopilot_timer= xTimerCreate("Autopilot Timer", timer_period, pdFALSE, (void*)0, tmrAutopilotCallback);
	confirm_timer = xTimerCreate("Confirm Timer", pdMS_TO_TICKS(1000), pdFALSE, (void*)0, tmrConfigCallback);
	accelerator_distance_timer = xTimerCreate("Accelerator Timer", pdMS_TO_TICKS(SPEED_UPDATE_GAMEPLAY), pdFALSE, (void*)0, tmrAccelDistanceCallback);

	while(1) {
		// sample buttons
		button_zero_state = sample_button0();
		button_one_state = sample_button1();

		// Get system state
		xSemaphoreTake(mSystemState, 0);
		sys_state = system_state;
		xSemaphoreGive(mSystemState);

		// Get autopilot state
		xSemaphoreTake(mAutopilotState, 0);
		ap_state = autopilot_state;
		xSemaphoreGive(mAutopilotState);

		// Update speed info accordingly
		switch(sys_state) {
			case(Startup): {
				break;
			}
			case(Configuration): {
				switch(find_press_type(button_zero_state, button_one_state)) {
					case(Double_Press): {
						buttons_held = true;
						if(xTimerIsTimerActive(confirm_timer) == pdFALSE) {
							xTimerReset(confirm_timer, 10);
						}
						xSemaphoreTake(mVehicleData, 0);
						xSemaphoreTake(mSpeedData, 0);
						vehicle.forces.static_friction_force  = calc_static_friction_force(vehicle);
						vehicle.forces.rolling_friction_force = calc_rolling_friction_force(vehicle);;
//						veh = vehicle;
						xSemaphoreGive(mSpeedData);
						xSemaphoreGive(mVehicleData);
						break;
					}
					case(Increment_Press): {
						if(xTimerIsTimerActive(confirm_timer) == pdTRUE) {
							xTimerStop(confirm_timer, 10);
						}
						xTaskNotify(thLCDDisplay, LCD_CONFIG_TYPE_NEXT, eSetValueWithOverwrite);
						break;
					}
					case(Decrement_Press): {
						if(xTimerIsTimerActive(confirm_timer) == pdTRUE) {
							xTimerStop(confirm_timer, 10);
						}
						xTaskNotify(thLCDDisplay, LCD_CONFIG_TYPE_PREV, eSetValueWithOverwrite);
						break;
					}
					case(No_Press): {
						if(xTimerIsTimerActive(confirm_timer) == pdTRUE) {
							xTimerStop(confirm_timer, 10);
						}
						buttons_held = false;
						break;
					}
					default: break;
				}

				break;
			}
			case(GetReady): {
				// do nothing
				break;
			}
			case(Gameplay): {
				if(xTimerIsTimerActive(accelerator_distance_timer) == pdFALSE) {
					xTimerStart(accelerator_distance_timer, 10);
				}

				switch(find_press_type(button_zero_state, button_one_state)) {
					case(Double_Press): {  	// Autopilot check
						buttons_held = true;
						xTimerReset(autopilot_timer, 10);
						break;
					}
					case(Increment_Press): {	// Increase accelerator
						if(buttons_held == true) {
							xTimerStop(autopilot_timer, 10);
						}
						if(ap_state == Autopilot_Enabled) {
							break;
						}
						else if(xSemaphoreTake(mSpeedData, 10) == pdPASS) {
							if(Vehicle_Speed.accelerator_pos + ACCELERATOR_CHANGE <= ACCELERATOR_MAX_POS) {
								Vehicle_Speed.accelerator_pos += ACCELERATOR_CHANGE;
							}
							else {
								Vehicle_Speed.accelerator_pos = ACCELERATOR_MAX_POS;
							}
							xSemaphoreGive(mSpeedData);
						}
						break;
					}
					case(Decrement_Press): {	// Decrease accelerator
						if(buttons_held == true) {
							xTimerStop(autopilot_timer, 10);
						}
						if(xSemaphoreTake(mSpeedData, 10) == pdPASS) {
							if(Vehicle_Speed.accelerator_pos - ACCELERATOR_CHANGE >= ACCELERATOR_MIN_POS) {
								Vehicle_Speed.accelerator_pos -= ACCELERATOR_CHANGE;
							}
							else {
								Vehicle_Speed.accelerator_pos = ACCELERATOR_MIN_POS;
							}
							xSemaphoreGive(mSpeedData);
						}
						break;
					}
					case(No_Press):
					default: buttons_held = false; break;
				}
				break;
			}
			case(GameOver): {
				break;
			}
			case(HighScore): {
				// reset vspeed alues
				xSemaphoreTake(mSpeedData, 10);
				Vehicle_Speed.accelerator_pos = 0;
				Vehicle_Speed.brakes_applied = false;
				Vehicle_Speed.max_speed = 0;
				Vehicle_Speed.speed = 0;
				xSemaphoreGive(mSpeedData);

				xSemaphoreTake(mVehicleData, 10);
				vehicle.distance_covered = 0;
				xSemaphoreGive(mVehicleData);

				// send notification if both buttons pressed for 1s
				switch(find_press_type(button_zero_state, button_one_state)) {
					case(Double_Press): {
						buttons_held = true;
						if(xTimerIsTimerActive(confirm_timer) == pdFALSE) {
							xTimerReset(confirm_timer, 10);
						}
						break;
					}
					default: buttons_held = false; break;
				}
				break;
			}
		}
		// Delay Task
		if(sys_state == Configuration) {
			vTaskDelay(config_delay_time);
		}
		else {
			vTaskDelay(delay_time);
		}
	}
}

//***********************************************************************************
// software timer
//***********************************************************************************
void tmrAutopilotCallback(TimerHandle_t xTimer) {
	if(xSemaphoreTake(mAutopilotState, 10) == pdPASS) {
		// Change global autopilot state
		if(autopilot_state == Autopilot_Enabled) {
			autopilot_state = Autopilot_Disabled;
		}
		else if(autopilot_state == Autopilot_Disabled) {
			autopilot_state = Autopilot_Enabled;
		}
		xSemaphoreGive(mAutopilotState);
	}
}

void tmrConfigCallback(TimerHandle_t xTimer) {
	// Get system state
	eSystemState sys_state;
	xSemaphoreTake(mSystemState, 0);
	sys_state = system_state;
	xSemaphoreGive(mSystemState);

	// notify correct task
	if(sys_state == Configuration) {
		xTaskNotify(thLCDDisplay, LCD_CONFIG_CONFIRM, eSetValueWithOverwrite);
	}
	else if(sys_state == HighScore) {
		xTaskNotify(thLCDDisplay, LCD_HIGHSCORE_RESET, eSetValueWithOverwrite);
	}
}

void tmrAccelDistanceCallback(TimerHandle_t xTimer) {
	xSemaphoreTake(mVehicleData, 10);
	xSemaphoreTake(mSpeedData, 10);
	calculate_distance_update(&vehicle, Vehicle_Speed, DISTANCE_UPDATE_GAMEPLAY);
	Vehicle_Speed.speed = calc_new_speed(vehicle, Vehicle_Speed);

	// keep track of Max Speed stat
	if(Vehicle_Speed.speed > Vehicle_Speed.max_speed) {
		Vehicle_Speed.max_speed = Vehicle_Speed.speed;
	}

	xSemaphoreGive(mVehicleData);
	xSemaphoreGive(mSpeedData);
}


//***********************************************************************************
// calculations
//***********************************************************************************
//void calc_new_speed(ePressType change_direction, Vehicle_t veh, Speed_t * veh_speed) {
float calc_new_speed(Vehicle_t veh, Speed_t veh_speed) {
	// Add in braking force when veh_speed.accelerator_pos < 0.0
	float power_motor = veh_speed.accelerator_pos * veh.characteristics.max_power;
	veh.forces.drag_force = calc_drag_force(veh, veh_speed);

	float power_applied = veh.forces.drag_force;

	if(veh_speed.speed > 0) {
		power_applied += veh.forces.rolling_friction_force;
	}
	else {
		power_applied += veh.forces.static_friction_force;
	}

	power_applied *= (float)veh_speed.speed;

	float s = (float)SPEED_UPDATE_GAMEPLAY / 1000.0;
	float vf = 0.0;

	double temp = (power_motor - power_applied) / (2 * veh.characteristics.mass * s);

	if(temp > 0.0) {
		vf = sqrt(temp);
		vf *= s;
	}
	else {
		vf = -1 * s * sqrt(-1 * temp);
	}

	vf += (float)veh_speed.speed;
	return vf;
}

/* Fd = Cd * 1/2 * p * v^2 * A */
float calc_drag_force(Vehicle_t veh, Speed_t speed) {
	float force = veh.characteristics.cross_sectional_area * veh.forces.drag_coefficient;
	force += pow(speed.speed, 2.0);
	force = (force * RHO_AIR) / 2;

	return force;
}

/* Static Friction Force = mu * (Normal Force) = mu * m * g */
float calc_static_friction_force(Vehicle_t veh) {
	return veh.tires.static_frict_coef * veh.characteristics.mass * GRAVITY;
}

/* Rolling Friction Force = c * (Normal Force) = c * m * g */
float calc_rolling_friction_force(Vehicle_t veh) {
	return veh.tires.rolling_frict_coef * veh.characteristics.mass * GRAVITY;
}

// TODO
//void calc_sideways_acceleration(Speed_t veh_speed) {
//	if(direction == Straight) {
//		return 0;
//	}
//	else {
//		return (v * v) / (veh.turn_radius / veh.angle);
//	}
//}

/*
 * @param dt	time in milliseconds between distance updates
 */
void calculate_distance_update(Vehicle_t * veh, Speed_t speed, float dt) {
	veh->distance_covered += (uint32_t)speed.speed * dt;
}

//***********************************************************************************
// functions
//***********************************************************************************

void gpio_init_buttons(void) {
	CMU_ClockEnable(cmuClock_GPIO, true);

	GPIO_DriveStrengthSet(BUTTON0_port, gpioDriveStrengthStrongAlternateStrong);
	GPIO_PinModeSet(BUTTON0_port, BUTTON0_pin, gpioModeInput, 0);

	GPIO_DriveStrengthSet(BUTTON1_port, gpioDriveStrengthStrongAlternateStrong);
	GPIO_PinModeSet(BUTTON1_port, BUTTON1_pin, gpioModeInput, 0);

	// enable IRQs
//	NVIC_EnableIRQ(GPIO_EVEN_IRQn);
//	NVIC_EnableIRQ(GPIO_ODD_IRQn);

	// configure button interrupts for rising and falling edges
//	GPIO_ExtIntConfig(BUTTON0_port, BUTTON0_pin, BUTTON0_pin, 1, 1, true);
//	GPIO_ExtIntConfig(BUTTON1_port, BUTTON1_pin, BUTTON1_pin, 1, 1, true);
}

/*
 * @brief Reads the value of the button0 pin
 */
eButtonState sample_button0(void) {
	uint32_t status = !GPIO_PinInGet(BUTTON0_port, BUTTON0_pin);
	if(status == 0) {
		return Button_Open;
	}
	else if(status) {
		return Button_Pressed;
	}
	return Button_Pressed;
}

/*
 * @brief Reads the value of the button1 pin
 */
eButtonState sample_button1(void) {
	uint32_t status = !GPIO_PinInGet(BUTTON1_port, BUTTON1_pin);
	if(status == 0) {
		return Button_Open;
	}
	else if(status) {
		return Button_Pressed;
	}
	return Button_Pressed;
}

ePressType find_press_type(eButtonState btn0, eButtonState btn1) {
	if((btn0 == Button_Pressed) && (btn1 == Button_Pressed)) {
		return Double_Press;
	}
	else if((btn0 == Button_Pressed) && (btn1 == Button_Open)) {
		return Increment_Press;
	}
	else if((btn0 == Button_Open) && (btn1 == Button_Pressed)) {
		return Decrement_Press;
	}
	else {
		return No_Press;
	}
}


/*************************************
 * Interrupt Handlers
 *************************************/

/*
 * @brief IRQ that clears the interrupt
 */
void GPIO_EVEN_IRQHandler(void) {  // button0
	// Clear all even pin interrupt flags
	GPIO_IntClear(0x5555);
}

/*
 * @brief IRQ that clears the interrupt
 */
void GPIO_ODD_IRQHandler(void) {	// button1
	// Clear all odd pin interrupt flags
	GPIO_IntClear(0xAAAA);
}

