/*
 * configurations.c
 *
 *  Created on: Mar 21, 2020
 *      Author: jack
 */

#include "configurations.h"

void vehicle_init(Vehicle_t * veh) {
	veh->car_type = Sedan;
	strcpy(veh->vehicle_name, SEDAN_STR);
	veh->weather = Sunny;
	veh->road_type = Asphalt;

	veh->tire_type = Normal;
	veh->tires.tire_type = Normal;
	veh->tires.static_frict_coef = TIRE_ASPH_SUNNY_COEF;
	veh->tires.rolling_frict_coef = TIRE_ROLL_ASPH_SUNNY_COEF;

	veh->mass = SEDAN_MASS;				// [kg]
	veh->width = SEDAN_WIDTH;			// [cm]
	veh->length = SEDAN_LENGTH;  		// [cm]
	veh->turn_radius = SEDAN_TURN_RADIUS;

	veh->max_power = SEDAN_MAX_POWER;
	veh->cross_sectional_area = SEDAN_CS_AREA;
	veh->drag_coefficient = SEDAN_CD;
	veh->distance_covered = 0;
}

void vehicle_change_settings(Vehicle_t * veh, eCarType car_type) {

}

void vehicle_speed_init(Speed_t * veh_speed) {
	veh_speed->accelerator_pos = 0;
	veh_speed->speed = 0;
}

void vehicle_direction_init(Direction_t * veh_dir) {
	veh_dir->direction = Straight;
	veh_dir->position = 0;
	veh_dir->angle = 0;
}

void track_settings_init(Track_Settings_t * settings) {
	settings->track = 0;
	settings->weather = 0;
	settings->road_type = 0;
}
