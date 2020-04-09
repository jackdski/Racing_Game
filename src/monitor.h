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

void VehicleMonitorTask(void * pvParameters);

#endif /* SRC_MONITOR_H_ */
