/*
 * tracks.h
 *
 *  Created on: Mar 30, 2020
 *      Author: jack
 */

#ifndef SRC_TRACKS_H_
#define SRC_TRACKS_H_

#include "configurations.h"

void init_tracks(void);
void set_track(Track_t * set_track, eGrandPrix track_name);
uint32_t get_next_waypoints(uint8_t waypoint_arr[3][2]);
uint16_t get_remaining_waypoints_count(Track_t track);

#endif /* SRC_TRACKS_H_ */
