/*
 * speed.h
 *
 *  Created on: Mar 20, 2020
 *      Author: jack
 */

#ifndef SRC_SPEED_H_
#define SRC_SPEED_H_

#include "em_gpio.h"
#include "em_cmu.h"
#include "configurations.h"
#include <math.h>

/*  F R E E R T O S   I N C L U D E S   */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

/* C O N S T A N T S */

#define SPEED_UPDATE_GAMEPLAY		500// 300		// [ms]
#define DISTANCE_UPDATE_GAMEPLAY	0.3		// [s]

#define ACCELERATOR_CHANGE		0.05
#define ACCELERATOR_MIN_POS		-1.0
#define ACCELERATOR_MAX_POS		1.0

#define RHO_AIR					1.2 	// [kg/m^3]
#define GRAVITY					9.81	// [m/s^2]

// BUTTON0
#define BUTTON0_port	gpioPortF
#define BUTTON0_pin		06u

// BUTTON1
#define BUTTON1_port	gpioPortF
#define BUTTON1_pin		07u

/* E N U M S */
typedef enum {
	Button_Open,
	Button_Pressed,
} eButtonState;

typedef enum {
	No_Press,
	Double_Press,
	Increment_Press,
	Decrement_Press,
} ePressType;

/*	F U N C T I O N S   */
void SpeedTask(void * pvParameters);
void tmrAutopilotCallback(TimerHandle_t xTimer);
void tmrConfigCallback(TimerHandle_t xTimer);
void tmrAccelDistanceCallback(TimerHandle_t xTimer);
float calc_new_speed(Vehicle_t veh, Speed_t veh_speed);
void update_vehicle_position(Vehicle_t * veh, uint32_t speed, Direction_t veh_direction, float dt);
float calc_drag_force(Vehicle_t veh, Speed_t speed);
float calc_static_friction_force(Vehicle_t veh);
float calc_rolling_friction_force(Vehicle_t veh);
void calculate_distance_update(Vehicle_t * veh, Speed_t speed, float dt);
void gpio_init_buttons(void);
eButtonState sample_button0(void);
eButtonState sample_button1(void);
ePressType find_press_type(eButtonState btn0, eButtonState btn1);

#endif /* SRC_SPEED_H_ */
