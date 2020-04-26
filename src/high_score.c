/*
 * high_score.c
 *
 *  Created on: Apr 9, 2020
 *      Author: jack
 */

#include "high_score.h"

static TimerHandle_t high_score_timer;
static float timer_seconds;

void init_high_score_list(High_Score_List_t * list) {
	list->num_entries = 0;

	// init all times to a large value
	uint8_t i;
	for(i = 0; i <= MAX_LIST_ENTRIES; i++) {
		list->best_time[i] = 0; //999999;
	}

	// create timer
	high_score_timer = xTimerCreate("HighScore Timer",
			pdMS_TO_TICKS(250),
			pdTRUE,
			(void *)0,
			increment_timer);
}


/*
 * keep sorted from least to greatest // TODO: add highest speed score
 */
void high_score_add(High_Score_List_t * list, uint32_t new_data) {
	if(list->num_entries < MAX_LIST_ENTRIES) {
		list->num_entries++;
	}

	int8_t i = MAX_LIST_ENTRIES - 1;
	while(new_data > list->best_time[i] && i >= 0) {
		list->best_time[i+1] = list->best_time[i];
		i--;
	}
	list->best_time[i + 1] = new_data;
}

uint32_t calculate_score(uint32_t max_speed, uint32_t distance, float trial_time) {
	return max_speed * distance * (10 / trial_time);
}

void start_high_score_timer(void) {
	timer_seconds = 0;				// make sure timer is reset
	xTimerReset(high_score_timer, 0);
}

void stop_high_score_timer(void) {
	if(xTimerIsTimerActive(high_score_timer) == pdTRUE) {
		xTimerStop(high_score_timer, 0);
	}
}

float get_high_score_timer_value(void) {
	return timer_seconds;
}

void increment_timer(TimerHandle_t xTimer) {
	timer_seconds += 0.250;
}
