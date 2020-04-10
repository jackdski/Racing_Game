/*
 * monitor.c
 *
 *  Created on: Apr 6, 2020
 *      Author: jack
 */

/*  I N C L U D E S   */
#include "monitor.h"

/*  G L O B A L   V A R I A B L E S   */
extern eSystemState system_state;
extern Vehicle_t vehicle;
extern Direction_t Vehicle_Direction;
extern Speed_t Vehicle_Speed;
extern Track_t track;
extern Active_Warnings_t active_warnings;

/*	S E M A P H O R E S   */
extern SemaphoreHandle_t mVehicleData;
extern SemaphoreHandle_t mSpeedData;
extern SemaphoreHandle_t mDirectionData;
extern SemaphoreHandle_t mSystemState;
//extern SemaphoreHandle_t mAutopilotState;

/*	T A S K   H A N D L E S   */
TaskHandle_t thLEDTask;
TaskHandle_t thLCDDisplay;

/*  P R I V A T E   V A R I A B L E S   */

/*	T A S K   */

void VehicleMonitorTask(void * pvParameters) {
	const TickType_t delay_time = pdMS_TO_TICKS(50);
	static eSlip slip_data;
	static eSystemState sys_state;
	init_active_warnings(&active_warnings);

	while(1) {
		// Get system state
		xSemaphoreTake(mSystemState, 10);
		sys_state = system_state;
		xSemaphoreGive(mSystemState);

		if(sys_state == GameOver) {
			init_active_warnings(&active_warnings);
		}

		if(track.waypoints[track.index].distance_marker < vehicle.distance_covered) {
			track.index++;
			if(track.index > track.num_waypoints + 3) {
				xTaskNotify(thLCDDisplay, MONITOR_GAMEOVER, eSetValueWithOverwrite);
			}
		}

		// determine slip
		xSemaphoreTake(mDirectionData, 10);
		if(Vehicle_Direction.angle != 0) {
			xSemaphoreTake(mSpeedData, 10);
			if(Vehicle_Speed.speed > 0.0) {
				xSemaphoreTake(mVehicleData, 10);
				slip_data = does_slip(vehicle, Vehicle_Speed);
				xSemaphoreGive(mVehicleData);
			}
			xSemaphoreGive(mSpeedData);
		}
		xSemaphoreGive(mDirectionData);

		switch(slip_data) {
		case(Slip): {
			set_warning(&active_warnings, Occured_Slip);
			break;
		}
		case(Slip_Warning): {
			set_warning(&active_warnings, Warning_Slip);
			break;
		}
		case(No_Slip):
		default: break;
		}

		vTaskDelay(delay_time);
	}
}

void init_active_warnings(Active_Warnings_t * warnings) {
	warnings->slip_warning = false;
	warnings->slip_occured = false;
	warnings->steering_warning = false;
	warnings->steering_offroad = false;
}

void set_warning(Active_Warnings_t * warnings, eWarning_Type warning) {
	switch(warning) {
	case(Warning_Slip): 	warnings->slip_warning 		= true; break;
	case(Warning_Offroad): 	warnings->steering_warning 	= true; break;
	case(Occured_Slip):		warnings->slip_occured 		= true; break;
	case(Occured_Offroad):	warnings->steering_offroad	= true; break;
	default: break;
	}
}

void clear_warning(Active_Warnings_t * warnings, eWarning_Type warning) {
	switch(warning) {
	case(Warning_Slip): 	warnings->slip_warning 		= false; break;
	case(Warning_Offroad): 	warnings->steering_warning 	= false; break;
	case(Occured_Slip):		warnings->slip_occured 		= false; break;
	case(Occured_Offroad):	warnings->steering_offroad	= false; break;
	default: break;
	}
}

// TODO: change 0.1 to steering parameter
 eSlip does_slip(Vehicle_t veh, Speed_t veh_speed) {
	 float boundary;
	 boundary = pow((veh_speed.accelerator_pos * veh.characteristics.max_power), 2.0);
	 boundary += pow(pow(veh_speed.speed, 2.0) / veh.characteristics.turn_radius / 0.1 , 2.0);
	 boundary = sqrt(boundary);

	 if(boundary >= veh.forces.rolling_friction_force) {
		 return Slip;
	 }
	 else if( boundary >= (veh.forces.rolling_friction_force * SLIP_PERCENTAGE)) {
		 return Slip_Warning;
	 }
	 else {
		 return No_Slip;
	 }
}
