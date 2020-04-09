/*
 * tracks.c
 *
 *  Created on: Mar 30, 2020
 *      Author: jack
 */

#include "tracks.h"
#include <stdlib.h>
#include <string.h>

#include "FreeRTOS.h"

// global
extern Track_t track;

// Private
static Track_t test_track;
static Track_t spa_belgium_track;
static Track_t monaco_track;
static Track_t melbourne_track;

// Tracks
static Waypoint_t test_track_waypoints[20] = {
		{0, Straight_Turn},
		{10, Straight_Turn},
		{20, Slight_Left_Turn},
		{30, Slight_Right_Turn},
		{40, Straight_Turn},
		{50, Straight_Turn},
		{60, Slight_Left_Turn},
		{70, Slight_Left_Turn},
		{80, Slight_Right_Turn},
		{90, Slight_Right_Turn},
		{100, Straight_Turn},
		{110, Straight_Turn},
		{120, Slight_Right_Turn},
		{130, Hard_Right_Turn},
		{140, Slight_Right_Turn},
		{150, Straight_Turn},
		{160, Slight_Left_Turn},
		{170, Straight_Turn},
		{180, Straight_Turn},
		{190, Straight_Turn}
};

/*
static uint8_t spa_belgium_waypoints[][50] = {
		{100,50},
		{98, 48},
		{96, 46},
		{94, 44},
		{92, 42},
		{90, 40},
		{88, 38},
		{86, 36},
		{84, 34},
		{82, 32},
		{80, 30},
		{78, 28},
		{76, 26},
		{74, 24},
		{72, 22},
		{70, 20},
		{68, 18},
		{66, 16},
		{64, 14},
		{62, 12},
		{60, 10},
		{58, 8},
		{56, 6},
		{54, 4},
		{52, 2},
		{50, 0},
		{52, 2},
		{54, 4},
		{56, 6},
		{58, 8},
		{60, 10},
		{62, 12},
		{64, 14},
		{66, 16},
		{68, 18},
		{70, 20},
		{72, 22},
		{74, 24},
		{78, 28},
		{80, 30},
		{82, 32},
		{84, 34},
		{86, 36},
		{88, 38},
		{90, 40},
		{92, 42},
		{94, 44},
		{96, 46},
		{98, 48},
		{100,50},
};
*/

void init_tracks(void) {
	// Test Track
	strcpy(test_track.name, "Test Track");
	test_track.num_waypoints = 	20;
	test_track.meters = test_track.num_waypoints * 10;
	test_track.index 		 = 	0;
	test_track.waypoints = test_track_waypoints;

	// SPA, Belgium
	strcpy(spa_belgium_track.name, "SPA, Belgium");
	spa_belgium_track.num_waypoints = 50;
	spa_belgium_track.meters = spa_belgium_track.num_waypoints * 10;
	spa_belgium_track.index 		= 0;
	spa_belgium_track.waypoints 	= pvPortMalloc(sizeof(test_track_waypoints));
	memcpy(&spa_belgium_track.waypoints, &test_track_waypoints, sizeof(test_track_waypoints));

	// Monaco
	strcpy(monaco_track.name, "Monaco");
	monaco_track.num_waypoints 	= 50;
	monaco_track.meters = monaco_track.num_waypoints * 10;
	monaco_track.index 			= 0;
	monaco_track.waypoints 		= pvPortMalloc(sizeof(test_track_waypoints));
	memcpy(&monaco_track.waypoints, &test_track_waypoints, sizeof(test_track_waypoints));

	// Melbourne
	strcpy(melbourne_track.name, "Melbourne");
	melbourne_track.num_waypoints = 50;
	melbourne_track.meters = melbourne_track.num_waypoints * 10;
	melbourne_track.index 			= 0;
	melbourne_track.waypoints 		= pvPortMalloc(sizeof(test_track_waypoints));
	memcpy(&melbourne_track.waypoints, &test_track_waypoints, sizeof(test_track_waypoints));

}

void set_track(Track_t * set_track, eGrandPrix track_name) {
	switch(track_name) {
		case(Test): {
			*set_track = test_track;
			memcpy(set_track->waypoints, test_track.waypoints, sizeof(test_track.waypoints));
			break;
		}
		case(SPA): 	  	 *set_track = test_track; break;
		case(Monaco): 	 *set_track = test_track; break;
		case(Melbourne): *set_track = test_track; break;
		default: 		 *set_track = test_track; break;
	}
}

uint32_t get_next_waypoints(uint8_t waypoint_arr[3][2]) {
	uint16_t i, j = 0;
	for(i = track.index; i < track.index + 3; i++) {
		memcpy(waypoint_arr[j], &track.waypoints[i], sizeof(track.waypoints[i]));
		j++;
	}
	track.index++;

	return track.num_waypoints - track.index;
}

uint16_t get_remaining_waypoints_count(Track_t track) {
	return track.num_waypoints - track.index;
}


