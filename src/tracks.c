/*
 * tracks.c
 *
 *  Created on: Mar 30, 2020
 *      Author: jack
 */

#include "tracks.h"
#include "lcd_display.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "FreeRTOS.h"

// global


// Private
static Track_t test_track;
static Track_t spa_belgium_track;
static Track_t monaco_track;
static Track_t melbourne_track;

// Tracks
static Waypoint_t test_track_waypoints[75] = {
		{99.0, 41.0},
		{100.0, 46.0},
		{100.0, 50.0},
		{100.0, 54.0},
		{99.0, 59.0},
		{98.0, 63.0},
		{97.0, 68.0},
		{95.0, 72.0},
		{93.0, 76.0},
		{90.0, 79.0},
		{88.0, 83.0},
		{85.0, 86.0},
		{81.0, 89.0},
		{78.0, 92.0},
		{74.0, 94.0},
		{70.0, 96.0},
		{65.0, 98.0},
		{61.0, 99.0},
		{57.0, 100.0},
		{52.0, 100.0},
		{48.0, 100.0},
		{43.0, 100.0},
		{39.0, 99.0},
		{35.0, 98.0},
		{30.0, 96.0},
		{26.0, 94.0},
		{22.0, 92.0},
		{19.0, 89.0},
		{15.0, 86.0},
		{12.0, 83.0},
		{10.0, 79.0},
		{7.0, 76.0},
		{5.0, 72.0},
		{3.0, 68.0},
		{2.0, 63.0},
		{1.0, 59.0},
		{0.0, 54.0},
		{0.0, 50.0},
		{0.0, 46.0},
		{1.0, 41.0},
		{2.0, 37.0},
		{3.0, 32.0},
		{5.0, 28.0},
		{7.0, 24.0},
		{10.0, 21.0},
		{12.0, 17.0},
		{15.0, 14.0},
		{19.0, 11.0},
		{22.0, 8.0},
		{26.0, 6.0},
		{30.0, 4.0},
		{35.0, 2.0},
		{39.0, 1.0},
		{43.0, 0.0},
		{48.0, 0.0},
		{52.0, 0.0},
		{57.0, 0.0},
		{61.0, 1.0},
		{65.0, 2.0},
		{70.0, 4.0},
		{74.0, 6.0},
		{78.0, 8.0},
		{81.0, 11.0},
		{85.0, 14.0},
		{88.0, 17.0},
		{90.0, 21.0},
		{93.0, 24.0},
		{95.0, 28.0},
		{97.0, 32.0},
		{98.0, 37.0},
		{99.0, 41.0},
		{100.0, 46.0},
		{100.0, 50.0},
		{100.0, 54.0},
		{99.0, 59.0}
};

static Waypoint_t spa_belgium_waypoints[50] = {
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

static Waypoint_t sparseR_waypoints[17] = {
		{0, 0},
		{4, 2},
		{6, 3},
		{10, 5},
		{15, 8},
		{17, 10},
		{20, 0},
		{50, 10},
		{80, 5},
		{130, 20},
		{135, 110},
		{135, 190},
		{170, 225},
		{205, 210},
		{205, 190},
		{150, 100},
		{165, 50},
		{200, 40},
		{210, 38},
		{230, 39}
};


void init_tracks(void) {
	// Test Track
	strcpy(test_track.name, "Test Track");
	test_track.num_waypoints		=  75;
	test_track.meters 				= test_track.num_waypoints * 10;
	test_track.index 				= 1;
	test_track.waypoints			= test_track_waypoints;

	// SPA, Belgium
	strcpy(spa_belgium_track.name, "SPA, Belgium");
	spa_belgium_track.num_waypoints = 17;
	spa_belgium_track.meters 		= spa_belgium_track.num_waypoints * 10;
	spa_belgium_track.index 		= 0;
	spa_belgium_track.waypoints 	= sparseR_waypoints;

	// Monaco
	strcpy(monaco_track.name, "Monaco");
	monaco_track.num_waypoints 		= 17;
	monaco_track.meters 			= monaco_track.num_waypoints * 10;
	monaco_track.index 				= 0;
	monaco_track.waypoints 			= sparseR_waypoints;

	// Melbourne
	strcpy(melbourne_track.name, "Melbourne");
	melbourne_track.num_waypoints 	= 50;
	melbourne_track.meters 			= melbourne_track.num_waypoints * 10;
	melbourne_track.index 			= 0;
	melbourne_track.waypoints 		= test_track_waypoints;
}

void set_track(Track_t * set_track, eGrandPrix track_name) {
	switch(track_name) {
		case(Test): {
			*set_track = test_track;
			memcpy(set_track->waypoints, test_track.waypoints, sizeof(test_track.waypoints));
			break;
		}
		case(SPA): {
			*set_track = spa_belgium_track;
			memcpy(set_track->waypoints, spa_belgium_track.waypoints, sizeof(spa_belgium_track.waypoints));
			break;
		}
		case(Monaco): {
			*set_track = monaco_track;
			memcpy(set_track->waypoints, monaco_track.waypoints, sizeof(monaco_track.waypoints));
			break;
		}
		case(Melbourne): {
			*set_track = melbourne_track;
			memcpy(set_track->waypoints, melbourne_track.waypoints, sizeof(melbourne_track.waypoints));
			break;
		}
		default: {
			*set_track = test_track;
			configASSERT(false);
			break;
		}
	}
}


bool convert_coords_to_pixel(Midpoint_Pixel_t * midpoint, Position_t position, float x, float y) {
	float pylon[2] = {x - position.x, y - position.y};
	float rotate[2] = {pylon[0] / SCREEN_SIZE_METERS_X, pylon[1] / SCREEN_SIZE_METERS_Y};

	float px = ((0.5 + rotate[0]) * 128);
	float py = 128 - fabs(rotate[1] * 128);
//	float py = (rotate[1] * 128);

	midpoint->x = (uint8_t)px;
	midpoint->y = (uint8_t)py;
	if(px > 138 || py > 138) {
		return true;
	}
	if(px < 0.0 || py < 0.0) {
		return true;
	}
	return false;
}

float find_starting_angle(Track_t track) {
	float PI = 3.14;

	float a[2];
	a[0] = track.waypoints[0].x;
	a[1] = track.waypoints[0].y;

	float b[2];
	b[0] = track.waypoints[1].x;
	b[1] = track.waypoints[1].y;

//	float c[2] = {track.waypoints[0].x, a[1] + 10};
	float c[2] = {a[0], a[1] + 10};


    uint32_t a2 = length_square(b[0], b[1], c[0], c[1]);
    uint32_t b2 = length_square(a[0], a[1], c[0], c[1]);
    uint32_t c2 = length_square(a[0], a[1], c[0], c[1]);

//    float la = sqrt(a2);
    float lb = sqrt(b2);
    float lc = sqrt(c2);

    float alpha;

    // check if no triangle is formed
    if(a[0] == b[0]) {		// x-coordinates are the same
    	alpha = 0.0;
    }
    else if(a[1] == b[1]) {		// y-coordinates are the same
    	alpha = 90.0;
    }
    else {
        // From Cosine law
        alpha = acos((b2 + c2 - a2)/(2* lb * lc));
        // Converting to degree
        alpha = alpha * 180 / PI;
		//    betta = betta * 180 / PI;
		//    gamma = gamma * 180 / PI;
    }

    if(track.waypoints[1].x > track.waypoints[0].x && track.waypoints[1].y > track.waypoints[0].y) {
    	alpha += 270;
    }
    else if(track.waypoints[1].x > track.waypoints[0].x && track.waypoints[1].y < track.waypoints[0].y) {
    	alpha += 180;
    }
    else if(track.waypoints[1].x < track.waypoints[0].x && track.waypoints[1].y < track.waypoints[0].y) {
    	alpha += 90;
    }

    return alpha;
}

float length_square(float x1, float y1, float x2, float y2) {
	float xdiff = x1 - x2;
	float ydiff = y1 - y2;
	return (xdiff * xdiff  + ydiff * ydiff);
}

float get_distance(Waypoint_t w0, Waypoint_t w1) {
	return sqrt(length_square(w0.x, w0.y, w1.x, w1.y));
}

uint16_t get_remaining_waypoints_count(Track_t track) {
	return track.num_waypoints - track.index;
}


