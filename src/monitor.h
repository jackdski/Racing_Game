/*
 * monitor.h
 *
 *  Created on: Apr 6, 2020
 *      Author: jack
 */

#ifndef SRC_MONITOR_H_
#define SRC_MONITOR_H_

#include "configurations.h"
#include "speed.h"

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

/*  F R E E R T O S   I N C L U D E S   */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#define SLIP_PERCENTAGE			0.85

typedef enum {
	No_Slip,
	Slip,
	Slip_Warning
} eSlip;

typedef enum {
	Warning_Slip,
	Warning_Offroad,
	Occured_Slip,
	Occured_Offroad
} eWarning_Type;

typedef struct {
	bool slip_warning;
	bool slip_occured;
	bool steering_warning;
	bool steering_offroad;
} Active_Warnings_t;

void VehicleMonitorTask(void * pvParameters);
void init_active_warnings(Active_Warnings_t * warnings);
void set_warning(Active_Warnings_t * warnings, eWarning_Type warning);
void clear_warning(Active_Warnings_t * warnings, eWarning_Type warning);
eSlip does_slip(Vehicle_t veh, Speed_t veh_speed);

#endif /* SRC_MONITOR_H_ */
