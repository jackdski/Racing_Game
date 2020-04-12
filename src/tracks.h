/*
 * tracks.h
 *
 *  Created on: Mar 30, 2020
 *      Author: jack
 */

#ifndef SRC_TRACKS_H_
#define SRC_TRACKS_H_

#include "configurations.h"
#include "lcd_display.h"

void init_tracks(void);
void set_track(Track_t * set_track, eGrandPrix track_name);
Midpoint_Pixel_t convert_coords_to_pixel(Position_t position, float x, float y);
float find_starting_angle(Track_t track);
float length_square(float x1, float y1, float x2, float y2);
uint16_t get_remaining_waypoints_count(Track_t track);

#endif /* SRC_TRACKS_H_ */
