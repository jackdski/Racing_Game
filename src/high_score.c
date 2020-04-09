/*
 * high_score.c
 *
 *  Created on: Apr 9, 2020
 *      Author: jack
 */

#include "high_score.h"

static High_Score_List_t high_scores;

void init_high_score_list(High_Score_List_t * list) {
	list->num_entries = 0;
}

/*
 * keep sorted from least to greatest
 */
void high_score_add(High_Score_List_t * list, uint8_t new_time) {
	uint8_t temp_times[list->num_entries + 1];

	uint8_t i = 0;
//	while(new_time > )

}
