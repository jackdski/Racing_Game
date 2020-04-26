/*
 * configurations.c
 *
 *  Created on: Mar 21, 2020
 *      Author: jack
 */

#include "configurations.h"

// Characteristics
static Characteristics_t sedan_characteristics = {
		.width 					=	SEDAN_WIDTH,
		.length 				=	SEDAN_LENGTH,
		.turn_radius			= 	SEDAN_TURN_RADIUS,
		.cross_sectional_area 	=	SEDAN_CS_AREA,
		.mass 					= 	SEDAN_MASS,
		.max_power 				=	SEDAN_MAX_POWER,
		.brake_force			= 	SEDAN_BRAKE_FORCE
};

static Characteristics_t suv_characteristics = {
		.width 					=	SUV_WIDTH,
		.length 				=	SUV_LENGTH,
		.turn_radius			= 	SUV_TURN_RADIUS,
		.cross_sectional_area 	=	SUV_CS_AREA,
		.mass 					= 	SUV_MASS,
		.max_power 				=	SUV_MAX_POWER,
		.brake_force			= 	SUV_BRAKE_FORCE
};

static Characteristics_t truck_characteristics = {
		.width 					=	TRUCK_WIDTH,
		.length 				=	TRUCK_LENGTH,
		.turn_radius			= 	TRUCK_TURN_RADIUS,
		.cross_sectional_area 	=	TRUCK_CS_AREA,
		.mass 					= 	TRUCK_MASS,
		.max_power 				=	TRUCK_MAX_POWER,
		.brake_force			= 	TRUCK_BRAKE_FORCE
};

static Characteristics_t f_one_characteristics = {
		.width 					=	F1_WIDTH,
		.length 				=	F1_LENGTH,
		.turn_radius			= 	F1_TURN_RADIUS,
		.cross_sectional_area 	=	F1_CS_AREA,
		.mass 					= 	F1_MASS,
		.max_power 				=	F1_MAX_POWER,
		.brake_force			= 	F1_BRAKE_FORCE
};


void vehicle_init(Vehicle_t * veh) {
	veh->car_type = Sedan;
	strcpy(veh->vehicle_name, SEDAN_STR);
	veh->weather = Sunny;
	veh->road_type = Asphalt;

	veh->tires.tire_type = Normal;
	veh->tires.tire_type = Normal;
	veh->tires.static_frict_coef = TIRE_ASPH_SUNNY_COEF;
	veh->tires.rolling_frict_coef = TIRE_ROLL_ASPH_SUNNY_COEF;

	veh->characteristics.mass = SEDAN_MASS;				// [kg]
	veh->characteristics.width = SEDAN_WIDTH;			// [cm]
	veh->characteristics.length = SEDAN_LENGTH;  		// [cm]
	veh->characteristics.turn_radius = SEDAN_TURN_RADIUS;
	veh->characteristics.max_power = SEDAN_MAX_POWER;
	veh->characteristics.cross_sectional_area = SEDAN_CS_AREA;

	veh->forces.drag_coefficient = SEDAN_CD;
	veh->distance_covered = 0;
}

void vehicle_change_settings(Vehicle_t * veh, eCarType car_type) {
	veh->car_type = car_type;
	switch(car_type) {
		case(Sedan): {
			strcpy(veh->vehicle_name, SEDAN_STR);
			veh->characteristics = sedan_characteristics;
			break;
		}
		case(SUV): {
			strcpy(veh->vehicle_name, SUV_STR);
			veh->characteristics = suv_characteristics;
			break;
		}
		case(Truck): {
			strcpy(veh->vehicle_name, TRUCK_STR);
			veh->characteristics = truck_characteristics;
			break;
		}
		case(F1): {
			strcpy(veh->vehicle_name, F1_STR);
			veh->characteristics = f_one_characteristics;
			break;
		}
		default: configASSERT(false);
	}
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
