/*
 * high_score.h
 *
 *  Created on: Apr 9, 2020
 *      Author: jack
 */

#ifndef SRC_HIGH_SCORE_H_
#define SRC_HIGH_SCORE_H_

#include <stdint.h>

#define MAX_LIST_ENTRIES

typedef struct {
	uint8_t num_entries;
	uint8_t best_time[MAX_LIST_ENTRIES];
} High_Score_List_t;


#endif /* SRC_HIGH_SCORE_H_ */
