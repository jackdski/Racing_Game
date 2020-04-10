/*
 * lcd_display.h
 *
 *  Created on: Mar 20, 2020
 *      Author: jack
 */

#ifndef SRC_LCD_DISPLAY_H_
#define SRC_LCD_DISPLAY_H_

#include "configurations.h"
#include "high_score.h"
#include "glib.h"

/*  F R E E R T O S   I N C L U D E S   */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

/* C O N S T A N T S */
#define HUD_Y_OFFSET_UPPER		(MIN_Y + 5)
#define HUD_Y_OFFSET_LOWER		(MIN_Y + GLIB_FONT_HEIGHT)
#define HUD_X_OFFSET_LEFT		(5)
#define HUD_X_OFFSET_RIGHT		(CENTER_X)
#define HUD_X_MIDPOINT			((HUD_X_OFFSET_LEFT + HUD_X_OFFSET_RIGHT) / 2)
#define HUD_Y_LINE				(MIN_Y + (2 * GLIB_FONT_HEIGHT))

#define HARD_LEFT_TURN_OFFSET	(4)
#define LEFT_TURN_OFFSET		(2)
#define HARD_RIGHT_TURN_OFFSET	(4)
#define RIGHT_TURN_OFFSET		(2)

#define LEFT_TURN_ROAD_OFFSET	(10)
#define RIGHT_TURN_ROAD_OFFSET	(10)

/* E N U M S */

typedef enum {
	Track_Type_Dot = 4,
	Car_Type_Dot,
	Tire_Type_Dot,
	Weather_Type_Dot,
	Road_Type_Dot
} eDotSelect;

/*	S T R U C T S   */

typedef struct {
	uint16_t x_left_position;
	uint16_t x_right_position;
	uint16_t y_upper_position;
	uint16_t y_lower_position;
} VehPosition_t;

typedef struct {
	uint16_t x__position;
	uint16_t x_position;
	uint16_t y_position;
} Pylon_t;

/*	F U N C T I O N S   */

void DisplayTask(void * pvParameters);
void tmrStartupCallback(TimerHandle_t xTimer);
void tmrGameoverCallback(TimerHandle_t xTimer);
void tmrHighScoreCallback(TimerHandle_t xTimer);

/* startup */
void startup_screen(void);

/* configuration */
void config_write_track_type(eGrandPrix track);
void config_write_car_type(eCarType carType);
void config_write_tire_type(eTires tireType);
void config_write_weather_type(eWeather weather);
void config_write_road_type(eRoadType road);
void config_update(Vehicle_t veh, Track_Settings_t settings, eDotSelect dot_pos);

void increment_current_config_value(eDotSelect * type);
void decrement_current_config_value(eDotSelect * type);
void increment_current_dot_value(eDotSelect type, Vehicle_t * veh, Track_Settings_t * settings);
void decrement_current_dot_value(eDotSelect type, Vehicle_t * veh, Track_Settings_t * settings);

void increment_track_choice(Track_Settings_t * settings);
void decrement_track_choice(Track_Settings_t * settings);
void increment_car_choice(Vehicle_t * veh);
void decrement_car_choice(Vehicle_t * veh);
void increment_tire_choice(Vehicle_t * veh);
void decrement_tire_choice(Vehicle_t * veh);
void increment_weather_choice(Vehicle_t * veh);
void decrement_weather_choice(Vehicle_t * veh);
void increment_road_choice(Vehicle_t * veh);
void decrement_road_choice(Vehicle_t * veh);

/* getready */
void getready_draw_countdown(uint8_t count);

/* gameplay */
void gameplay_draw_screen(GLIB_Rectangle_t veh_shape, Speed_t veh_speed, Direction_t veh_dir);
void gameplay_draw_hud(Speed_t veh_speed);
void gameplay_draw_vehicle(GLIB_Rectangle_t veh_shape, Direction_t veh_dir);
void gameplay_calculate_vehicle_shape(Vehicle_t veh, GLIB_Rectangle_t * veh_shape);
int32_t * gen4PolyPoints(uint32_t radius, int32_t xOff, int32_t yOff);
bool gameplay_draw_track(Vehicle_t veh, Track_t track, Speed_t veh_speed);
void gameplay_connect_waypoints(uint8_t * x_left_start, uint8_t * y_start, eTurnType turn_type);
uint32_t gameplay_calculate_mph_from_ms(Speed_t veh_speed);

/* game over */
void gameover_print_header(void);
void gameover_print_header_inverse(void);

/* high score */
void high_score_display(High_Score_List_t list);
void high_score_display_place(uint8_t place, uint32_t score);


#endif /* SRC_LCD_DISPLAY_H_ */
