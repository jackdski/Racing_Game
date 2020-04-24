/*
 * configurations.h
 *
 *  Created on: Mar 20, 2020
 *      Author: jack
 *
 */

#ifndef SRC_CONFIGURATIONS_H_
#define SRC_CONFIGURATIONS_H_

#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "glib.h"

/* C O N F I G U R A T I O N   V A L U E S */

/* D I S P L A Y */
#define DISPLAY_REFRESH_RATE	25		// [Hz]

#define GLIB_FONT_WIDTH   (glibContext.font.fontWidth + glibContext.font.charSpacing)
#define GLIB_FONT_HEIGHT  (glibContext.font.fontHeight)

#define CENTER_X (glibContext.pDisplayGeometry->xSize / 2)
#define CENTER_Y (glibContext.pDisplayGeometry->ySize / 2)

//#define MAX_X (glibContext.pDisplayGeometry->xSize - 1)
//#define MAX_Y (glibContext.pDisplayGeometry->ySize - 1)

#define MIN_X           0
#define MIN_Y           0

#define SCREEN_SIZE_METERS_X	40.0
#define SCREEN_SIZE_METERS_Y	40.0

#define DISPLAY_MAX_STR_LEN     48


/*	T R A C K S   */
#define TEST_STR				"Test"
#define SPA_STR					"SPA, BE"
#define MONACO_STR				"Monaco"
#define MELBOURNE_STR			"Melbourne, Aus."

#define TRACK_PYLON_WIDTH		(MAX_X / 3)
#define TRACK_PYLON_DISTANCE	(20)


/*	V E H I C L E   */

/* STRINGS */
#define SEDAN_STR				"Model 3"
#define SUV_STR					"Model Y"
#define TRUCK_STR				"Cybrtrck"
#define VAN_STR					"Model V"
#define F1_STR					"F1"

// Tires
#define TIRE_NORMAL_STR			"Normal"
#define TIRE_SLICKS_STR			"Slicks"
#define TIRE_SNOW_STR			"Snow"

// Weather
#define WEATHER_SUNNY_STR		"Sunny"
#define WEATHER_RAIN_STR		"Rain"
#define WEATHER_SNOW_STR		"Snow"

// Road Type
#define ROAD_ASPHALT_STR		"Asphalt"
#define ROAD_GRAVEL_STR			"Gravel"
#define ROAD_DIRT_STR			"Dirt"

/* http://hpwizard.com/tire-friction-coefficient.html */
// Friction Coefficient
#define TIRE_ASPH_SUNNY_COEF		1.00
#define TIRE_ASPH_WET_COEF			0.70
#define TIRE_ASPH_SNOW_COEF			0.15

// Rolling Resistance Coefficient
#define TIRE_ROLL_ASPH_SUNNY_COEF	0.014
#define TIRE_ROLL_ASPH_WET_COEF		0.017
#define TIRE_ROLL_ASPH_SNOW_COEF	0.016

/* MASS [kg] */
#define SEDAN_MASS				1645.0
#define SUV_MASS				2003.0
#define TRUCK_MASS				2295.0
#define VAN_MASS				2404.0
#define	F1_MASS					712.0

/* WIDTH */
#define SEDAN_WIDTH				10
#define SUV_WIDTH				7
#define TRUCK_WIDTH				8
#define VAN_WIDTH				9
#define	F1_WIDTH				6

/* LENGTH */
#define SEDAN_LENGTH			18
#define SUV_LENGTH				15
#define TRUCK_LENGTH			16
#define VAN_LENGTH				17
#define	F1_LENGTH				14

/* TURN RADIUS [m] */			// TODO: Needed?
#define SEDAN_TURN_RADIUS		10
#define SUV_TURN_RADIUS			12
#define TRUCK_TURN_RADIUS		14
#define VAN_TURN_RADIUS			15
#define F1_TURN_RADIUS			13

/* MAX POWER [W] */
#define SEDAN_MAX_POWER			(211000.0 / 2.0)
#define SUV_MAX_POWER			350000.0
#define TRUCK_MAX_POWER			597000.0
#define VAN_MAX_POWER			390000.0
#define	F1_MAX_POWER			696000.0

/* Cd DRAG COEFFICIENT VALUES */
#define SEDAN_CD				0.23
#define SUV_CD					0.23
#define TRUCK_CD				0.30

/* CROSS-SECTIONAL AREA */
#define SEDAN_CS_AREA			2.0
#define SUV_CS_AREA				2.5
#define TRUCK_CS_AREA			2.75
#define F1_CS_AREA				1.75

/* MAX BRAKING FORCE */ 		// TODO
#define SEDAN_BRAKE_FORCE		14000.0
#define SUV_BRAKE_FORCE			16000.0
#define TRUCK_BRAKE_FORCE		17000.0
#define F1_BRAKE_FORCE			19000.0

/* TASK NOTFICATION VALUES */
#define LCD_CONFIG_TYPE_NEXT	0xAA
#define LCD_CONFIG_TYPE_PREV	0x55
#define LCD_CONFIG_VAL_NEXT		0xDE
#define LCD_CONFIG_VAL_PREV		0xAD
#define LCD_CONFIG_CONFIRM		0xABCDEF0

#define LCD_GAMEOVER_NEXT		0x12345678
#define LCD_HIGHSCORE_RESET		0xFEDCAB1

#define MONITOR_GAMEOVER		0x87654321


/* E N U M S */
typedef enum {
	Test,
	SPA,
	Monaco,
	Melbourne,
} eGrandPrix;

typedef enum {
	Autopilot_Disabled,
	Autopilot_Enabled
} eAutopilotState;

typedef enum {
	Startup,
	Configuration,
	GetReady,
	Gameplay,
	GameOver,
	HighScore
} eSystemState;

typedef enum {
	Hard_Left,
	Left,
	Straight,
	Right,
	Hard_Right
} eDirection;


/* C O N F I G   E N U M S */

typedef enum {
	Normal,
	Slicks,
	Snow_Tires
} eTires;

typedef enum {
	Sedan,
	SUV,
	Truck,
	F1
} eCarType;

typedef enum {
	Sunny,
	Rain,
	Snowy
} eWeather;

typedef enum {
	Asphalt,
	Gravel,
	Dirt
} eRoadType;

/* S T R U C T S */

// Track-related
typedef struct {
	uint16_t x_position;
	uint16_t y_position;
} Pylon_t;

typedef struct {
	uint8_t x;
	uint8_t y;
} Midpoint_Pixel_t;

typedef struct {
	eGrandPrix track;
	eWeather weather;
	eRoadType road_type;
} Track_Settings_t;

typedef struct {
//	uint16_t distance_marker;
//	eTurnType turn;
	float x;
	float y;
} Waypoint_t;

typedef struct {
	char name[20];
	bool initialized;
	uint16_t index;
//	uint16_t meters_covered; // TODO
	uint16_t num_waypoints;
	uint32_t meters;		// how long the track is
	Waypoint_t * waypoints;
	Midpoint_Pixel_t midpoints[25];
} Track_t;

// Vehicle-related

typedef struct {
	float drag_coefficient;
	float drag_force;
	float static_friction_force;
	float rolling_friction_force;
} Forces_t;

typedef struct {
	uint16_t left_pos;
	uint16_t right_pos;
	uint16_t top_pos;
	uint16_t bottom_pos;
} Vehicle_Shape_t;

typedef struct {
	uint16_t width;			// [cm]
	uint16_t length;  		// [cm]
	uint16_t turn_radius;  	// [m]
	uint16_t cross_sectional_area;
	float mass;				// [kg]
	float max_power;
	float brake_force;
} Characteristics_t;

typedef struct {
	eTires tire_type;
	float static_frict_coef;
	float rolling_frict_coef;
} Tires_t;

typedef struct {
	uint32_t speed;
	uint32_t max_speed;
	float accelerator_pos;	// [0:100]
	bool brakes_applied;
} Speed_t;

typedef struct {
	eDirection direction;
	uint8_t position;
	float angle;
} Direction_t;

typedef struct {
	float x;
	float y;
} Position_t;

typedef struct {
	char vehicle_name[20];
	eCarType car_type;
	eWeather weather;
	eRoadType road_type;
	Position_t position;
	Tires_t tires;
	Forces_t forces;
	Characteristics_t characteristics;
	GLIB_Rectangle_t shape;
	float distance_covered;
} Vehicle_t;

void vehicle_init(Vehicle_t * veh);
void vehicle_change_settings(Vehicle_t * veh, eCarType car_type);
void vehicle_speed_init(Speed_t * veh_speed);
void vehicle_direction_init(Direction_t * veh_dir);
void track_settings_init(Track_Settings_t * settings);

#endif /* SRC_CONFIGURATIONS_H_ */
