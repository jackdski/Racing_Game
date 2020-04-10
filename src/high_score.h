/*
 * high_score.h
 *
 *  Created on: Apr 9, 2020
 *      Author: jack
 */

#ifndef SRC_HIGH_SCORE_H_
#define SRC_HIGH_SCORE_H_

#include <stdint.h>

/*  F R E E R T O S   I N C L U D E S   */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#define MAX_LIST_ENTRIES		10

typedef struct {
	uint8_t num_entries;
	uint32_t best_time[MAX_LIST_ENTRIES];
} High_Score_List_t;

void init_high_score_list(High_Score_List_t * list);
void high_score_add(High_Score_List_t * list, uint32_t new_data);
uint32_t calculate_score(uint32_t max_speed, uint32_t distance, float trial_time);
void start_high_score_timer(void);
void stop_high_score_timer(void);
float get_high_score_timer_value(void);
void increment_timer(TimerHandle_t xTimer);

#endif /* SRC_HIGH_SCORE_H_ */
