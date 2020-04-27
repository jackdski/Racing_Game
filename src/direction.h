/*
 * direction.h
 *
 *  Created on: Mar 21, 2020
 *      Author: jack
 */

#ifndef SRC_DIRECTION_H_
#define SRC_DIRECTION_H_

#include "em_acmp.h"
#include "em_cmu.h"
#include "em_device.h"
#include "em_gpio.h"
#include "capsense.h"
#include "capsenseconfig.h"
#include "configurations.h"


/*  F R E E R T O S   I N C L U D E S   */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"


#define HARD_LEFT_ANGLE		(2.0)
#define LEFT_ANGLE			(1.0)
#define RIGHT_ANGLE			(-1 * LEFT_ANGLE)
#define HARD_RIGHT_ANGLE	(-1 * HARD_LEFT_ANGLE)


/*	F U N C T I O N S   */
void DirectionTask(void * pvParameters);
void tmr_get_system_state(TimerHandle_t xTimer);
uint8_t get_capsense_position(void);


#endif /* SRC_DIRECTION_H_ */
