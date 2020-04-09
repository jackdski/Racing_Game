/*
 * lcd_display.c
 *
 *  Created on: Mar 20, 2020
 *      Author: jack
 */

/*  I N C L U D E S   */
#include "lcd_display.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#include "display.h"
#include "dmd.h"
#include "glib.h"

#include "tracks.h"

/*  G L O B A L   V A R I A B L E S   */
extern eSystemState 	system_state;
extern Vehicle_t 		vehicle;
//extern eAutopilotState 	autopilot_state;
extern Speed_t 			Vehicle_Speed;
extern Direction_t 		Vehicle_Direction;
extern Track_t 			track;
extern Track_Settings_t track_settings;

/*	S E M A P H O R E S   */
extern SemaphoreHandle_t mSpeedData;
extern SemaphoreHandle_t mDirectionData;
extern SemaphoreHandle_t mSystemState;
//extern SemaphoreHandle_t mAutopilotState;
extern SemaphoreHandle_t mVehicleData;
extern SemaphoreHandle_t mTrack;

/*	T A S K   H A N D L E S   */
extern TaskHandle_t thLCDDisplay;
extern TaskHandle_t thVehMon;

/*  P R I V A T E   V A R I A B L E S   */
static TimerHandle_t 	startup_timer;
static TimerHandle_t 	gameover_timer;
static TimerHandle_t 	highscore_timer;
static GLIB_Context_t   glibContext;
static GLIB_Rectangle_t vehicle_shape_graphic;
static uint16_t 		vehicle_x_position;
//static VehPosition_t 	vehicle_position;

/*	T A S K   */

void DisplayTask(void * pvParameters) {
	static TickType_t refresh_rate = pdMS_TO_TICKS(1000 / DISPLAY_REFRESH_RATE);
	static TickType_t countdown_delay = pdMS_TO_TICKS(1000);
	static TickType_t timer_period = pdMS_TO_TICKS(3000);
	static TickType_t highscore_timer_period = pdMS_TO_TICKS(10000);


	static eSystemState sys_state;
	static Speed_t 		veh_speed;
	static Direction_t 	veh_dir;
	static Track_Settings_t cpy_track_settings;
	static eDotSelect 	current_config_value = Track_Type_Dot;
	static uint8_t 		countdown_value = 4;
	vehicle_x_position = CENTER_X;

	// init
	EMSTATUS status;
	status = DISPLAY_Init();
	if (DISPLAY_EMSTATUS_OK != status) {
		configASSERT(false);
	}

	/* Initialize the DMD module for the DISPLAY device driver. */
	status = DMD_init(0);
	if (DMD_OK != status) {
		configASSERT(false);
	}

	status = GLIB_contextInit(&glibContext);
	if (GLIB_OK != status) {
		configASSERT(false);
	}

	/* Setup display colours */
	glibContext.backgroundColor = White;
	glibContext.foregroundColor = Black;

	// create software timers
	startup_timer   = xTimerCreate("Autopilot Timer", timer_period, pdFALSE, (void*)0, tmrStartupCallback);
	gameover_timer  = xTimerCreate("GameOver Timer", timer_period, pdFALSE, (void*)0, tmrGameoverCallback);
	highscore_timer = xTimerCreate("HighScore Timer", highscore_timer_period, pdFALSE, (void*)0, tmrHighScoreCallback);

	while(1) {
		// Get system state
		xSemaphoreTake(mSystemState, 10);
		sys_state = system_state;
		xSemaphoreGive(mSystemState);

		switch(sys_state) {
			case(Startup): {
				static bool written = false;
				if(written == false) {
					startup_screen();
					DMD_updateDisplay();

					if(xTimerIsTimerActive(startup_timer) == pdFALSE) {
						xTimerStart(startup_timer, 10);
					}
					written = true;
				}
				break;
			}
			case(Configuration): {
				static bool written = false;
				if(xTimerIsTimerActive(startup_timer) == pdTRUE) {
					xTimerStop(startup_timer, 10);
				}

				if(written == false) {
					// write initial config options
					xSemaphoreTake(mVehicleData, 10);
					config_update(vehicle, track_settings, current_config_value);
					xSemaphoreGive(mVehicleData);

					DMD_updateDisplay();
					written = true;
				}
				else {
					// wait for notification from capsense or buttons
					uint32_t notification_value;
					xTaskNotifyWait(ULONG_MAX, ULONG_MAX, &notification_value, portMAX_DELAY);
					switch(notification_value) {
						case(LCD_CONFIG_CONFIRM): {
							// calculate the vehicle model
							xSemaphoreTake(mVehicleData, 10);
							gameplay_calculate_vehicle_shape(vehicle, &vehicle_shape_graphic);
							vehicle_x_position = CENTER_X - (vehicle.width / 2);
							xSemaphoreGive(mVehicleData);

							xSemaphoreTake(mTrack, 10);
							cpy_track_settings = track_settings;
							set_track(&track, track_settings.track);
							xSemaphoreGive(mTrack);

							// progress the system state
							xSemaphoreTake(mSystemState, 10);
							system_state = GetReady;
							xSemaphoreGive(mSystemState);
							break;
						}
						case(LCD_CONFIG_TYPE_NEXT): {
							increment_current_config_value(&current_config_value);
							xSemaphoreTake(mVehicleData, 10);
							config_update(vehicle, cpy_track_settings, current_config_value);
							xSemaphoreGive(mVehicleData);
							DMD_updateDisplay();
							break;
						}
						case(LCD_CONFIG_TYPE_PREV): {
							decrement_current_config_value(&current_config_value);
							xSemaphoreTake(mVehicleData, 10);
							config_update(vehicle, cpy_track_settings, current_config_value);
							xSemaphoreGive(mVehicleData);
							DMD_updateDisplay();
							break;
						}
						case(LCD_CONFIG_VAL_NEXT): {
							xSemaphoreTake(mVehicleData, 10);
							increment_current_dot_value(current_config_value, &vehicle, &cpy_track_settings );
							config_update(vehicle, cpy_track_settings, current_config_value);
							xSemaphoreGive(mVehicleData);
							DMD_updateDisplay();
							break;
						}
						case(LCD_CONFIG_VAL_PREV): {
							xSemaphoreTake(mVehicleData, 10);
							decrement_current_dot_value(current_config_value, &vehicle, &cpy_track_settings);
							config_update(vehicle, cpy_track_settings, current_config_value);
							xSemaphoreGive(mVehicleData);
							DMD_updateDisplay();
							break;
						}
					}

				}
				break;
			}
			case(GetReady): {
				getready_draw_countdown(countdown_value - 1);
				DMD_updateDisplay();
				countdown_value--;

				if(countdown_value == 0) {
					countdown_value = 4;	// reset
					xSemaphoreTake(mSystemState, 10);
					system_state = Gameplay;
					sys_state = system_state;
					xSemaphoreGive(mSystemState);
					vTaskResume(thVehMon);
				}
				break;
			}
			case(Gameplay): {
				// see if gameover notification
				uint32_t notification_value;
				if(xTaskNotifyWait(ULONG_MAX, ULONG_MAX, &notification_value, 0) == pdTRUE) {
					xSemaphoreTake(mSystemState, 10);
					system_state = GameOver;
					sys_state = system_state;
					xSemaphoreGive(mSystemState);
					break;
				}

				xSemaphoreTake(mSpeedData, 0);
				veh_speed = Vehicle_Speed;

				xSemaphoreGive(mSpeedData);

				xSemaphoreTake(mDirectionData, 0);
				veh_dir = Vehicle_Direction;
				xSemaphoreGive(mDirectionData);

				gameplay_draw_screen(vehicle_shape_graphic, veh_speed, veh_dir);

				xSemaphoreTake(mTrack, 0);
				xSemaphoreTake(mVehicleData, 0);
				bool done = gameplay_draw_track(vehicle, track, veh_speed);
				xSemaphoreGive(mTrack);
				xSemaphoreGive(mVehicleData);

				if(done == true) {
					xSemaphoreTake(mSystemState, 10);
					system_state = GameOver;
					sys_state = system_state;
					xSemaphoreGive(mSystemState);
				}

				DMD_updateDisplay();
				break;
			}
			case(GameOver): {
				static bool inverse = false;
				if(inverse == true) {
					gameover_print_header_inverse();
					inverse = false;
				}
				else {
					gameover_print_header();
					inverse = true;
				}
				DMD_updateDisplay();

				if(xTimerIsTimerActive(gameover_timer) == pdFALSE) {
					xTimerReset(gameover_timer, 10);
				}

				// wait for notification
				uint32_t notification_value;
				if(xTaskNotifyWait(ULONG_MAX, ULONG_MAX, &notification_value, 0) == pdTRUE) {
					if(notification_value == LCD_GAMEOVER_NEXT) {
						xSemaphoreTake(mSystemState, 10);
						system_state = HighScore;
						sys_state = system_state;
						xSemaphoreGive(mSystemState);
					}
				}

				break;
			}
			case(HighScore): {
				// Display High Score data
				high_score_display();
				DMD_updateDisplay();

				// start timer
				if(xTimerIsTimerActive(highscore_timer) == pdFALSE) {
					xTimerReset(highscore_timer, 10);
				}

				// wait for notification
				uint32_t notification_value;
				xTaskNotifyWait(ULONG_MAX, ULONG_MAX, &notification_value, portMAX_DELAY);
				if(notification_value == LCD_HIGHSCORE_RESET) {
					xSemaphoreTake(mSystemState, 10);
					system_state = Configuration;
					sys_state = system_state;
					xSemaphoreGive(mSystemState);
				}
			}
		}

		// Delay Task
		if(sys_state == GetReady) {
			vTaskDelay(countdown_delay);
		}
		else {
			vTaskDelay(refresh_rate);
		}
	}
}


//***********************************************************************************
// software timers
//***********************************************************************************
void tmrStartupCallback(TimerHandle_t xTimer) {
	if(xSemaphoreTake(mSystemState, 10) == pdPASS) {
		if(system_state == Startup) {
			system_state = Configuration;
		}
		xSemaphoreGive(mSystemState);
	}
}

void tmrGameoverCallback(TimerHandle_t xTimer) {
	xTaskNotify(thLCDDisplay, LCD_GAMEOVER_NEXT, eSetValueWithOverwrite);
}

void tmrHighScoreCallback(TimerHandle_t xTimer) {
	xTaskNotify(thLCDDisplay, LCD_HIGHSCORE_RESET, eSetValueWithOverwrite);
}



//***********************************************************************************
// startup
//***********************************************************************************

void startup_screen(void) {
	GLIB_clear(&glibContext);
	char str[DISPLAY_MAX_STR_LEN];
	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNormal8x8);
	snprintf(str, DISPLAY_MAX_STR_LEN, "RTOS 2020");
	GLIB_drawString(&glibContext,
		  str,
		  strlen(str),
		  CENTER_X  - ((GLIB_FONT_WIDTH * strlen(str))/2),
		  5,
		  0);

	snprintf(str, DISPLAY_MAX_STR_LEN, "jdanielski");
	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  CENTER_X - ((GLIB_FONT_WIDTH * strlen(str)) / 2),
				  5 + (3 * GLIB_FONT_HEIGHT),
				  0);
}


//***********************************************************************************
// config
//***********************************************************************************
void config_write_track_type(eGrandPrix track) {
	char str[DISPLAY_MAX_STR_LEN];
	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNarrow6x8);
		snprintf(str, DISPLAY_MAX_STR_LEN, "Track:\t");
		GLIB_drawString(&glibContext,
					  str,
					  strlen(str),
					  MIN_X + 10,
					  (Track_Type_Dot * GLIB_FONT_HEIGHT),
					  0);

		switch(track) {
			case(Test): snprintf(str, DISPLAY_MAX_STR_LEN, TEST_STR); break;
			case(SPA): snprintf(str, DISPLAY_MAX_STR_LEN, SPA_STR); break;
			case(Monaco): snprintf(str, DISPLAY_MAX_STR_LEN, MONACO_STR); break;
			case(Melbourne): snprintf(str, DISPLAY_MAX_STR_LEN, MELBOURNE_STR); break;
		}

		GLIB_drawString(&glibContext,
					  str,
					  strlen(str),
					  MAX_X - 50,
					  (Track_Type_Dot * GLIB_FONT_HEIGHT),
					  0);
}

void config_write_car_type(eCarType carType) {
	char str[DISPLAY_MAX_STR_LEN];
	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNarrow6x8);
		snprintf(str, DISPLAY_MAX_STR_LEN, "Car Type:\t");
		GLIB_drawString(&glibContext,
					  str,
					  strlen(str),
					  MIN_X + 10,
					  (Car_Type_Dot * GLIB_FONT_HEIGHT),
					  0);

		switch(carType) {
			case(Sedan): snprintf(str, DISPLAY_MAX_STR_LEN, SEDAN_STR); break;
			case(SUV): snprintf(str, DISPLAY_MAX_STR_LEN, SUV_STR); break;
			case(Truck): snprintf(str, DISPLAY_MAX_STR_LEN, TRUCK_STR); break;
			case(Van): snprintf(str, DISPLAY_MAX_STR_LEN, VAN_STR); break;
			case(F1): snprintf(str, DISPLAY_MAX_STR_LEN, F1_STR); break;
		}

		GLIB_drawString(&glibContext,
					  str,
					  strlen(str),
					  MAX_X - 50,
					  (Car_Type_Dot * GLIB_FONT_HEIGHT),
					  0);
}


void config_write_tire_type(eTires tireType) {
	char str[DISPLAY_MAX_STR_LEN];

	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNarrow6x8);
	snprintf(str, DISPLAY_MAX_STR_LEN, "Tire Type:\t");
	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MIN_X + 10,
				  (Tire_Type_Dot * GLIB_FONT_HEIGHT),	// 5
				  0);

	switch(tireType) {
		case(Normal): snprintf(str, DISPLAY_MAX_STR_LEN, TIRE_NORMAL_STR); break;
		case(Slicks): snprintf(str, DISPLAY_MAX_STR_LEN, TIRE_SLICKS_STR); break;
		case(Snow_Tires): snprintf(str, DISPLAY_MAX_STR_LEN, TIRE_SNOW_STR); break;
	}

	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MAX_X - 50,
				  (Tire_Type_Dot * GLIB_FONT_HEIGHT),
				  0);
}

void config_write_weather_type(eWeather weather) {
	char str[DISPLAY_MAX_STR_LEN];

	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNarrow6x8);
	snprintf(str, DISPLAY_MAX_STR_LEN, "Weather:\t");
	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MIN_X + 10,
				  (Weather_Type_Dot * GLIB_FONT_HEIGHT),	// 6
				  0);

	switch(weather) {
		case(Sunny): snprintf(str, DISPLAY_MAX_STR_LEN, WEATHER_SUNNY_STR); break;
		case(Rain): snprintf(str, DISPLAY_MAX_STR_LEN, WEATHER_RAIN_STR); break;
		case(Snowy): snprintf(str, DISPLAY_MAX_STR_LEN, WEATHER_SNOW_STR); break;
	}

	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MAX_X - 50,
				  (Weather_Type_Dot * GLIB_FONT_HEIGHT),
				  0);
}

void config_write_road_type(eRoadType road) {
	char str[DISPLAY_MAX_STR_LEN];

	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNarrow6x8);
	snprintf(str, DISPLAY_MAX_STR_LEN, "Road:\t");
	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MIN_X + 10,
				  (Road_Type_Dot * GLIB_FONT_HEIGHT), // 7
				  0);

	switch(road) {
		case(Asphalt): snprintf(str, DISPLAY_MAX_STR_LEN, ROAD_ASPHALT_STR); break;
		case(Gravel): snprintf(str, DISPLAY_MAX_STR_LEN, ROAD_GRAVEL_STR); break;
		case(Dirt): snprintf(str, DISPLAY_MAX_STR_LEN, ROAD_DIRT_STR); break;
	}

	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MAX_X - 50,
				  (Road_Type_Dot * GLIB_FONT_HEIGHT),
				  0);
}

void config_update(Vehicle_t veh, Track_Settings_t settings, eDotSelect dot_pos) {
	GLIB_clear(&glibContext);
	char str[DISPLAY_MAX_STR_LEN];
	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNormal8x8);
	snprintf(str, DISPLAY_MAX_STR_LEN, "CAR CONFIG");
	GLIB_drawString(&glibContext,
		  str,
		  strlen(str),
		  CENTER_X - ((GLIB_FONT_WIDTH * strlen(str)) / 2),
		  5,
		  0);

	GLIB_drawLine(&glibContext, MIN_X - 1, MIN_Y + (2 * GLIB_FONT_HEIGHT),
			MAX_X + 1, MIN_Y + (2 * GLIB_FONT_HEIGHT));

	GLIB_drawCircleFilled(&glibContext, MIN_X+3, (dot_pos * GLIB_FONT_HEIGHT + 3), 2);

	config_write_track_type(settings.track);
	config_write_car_type(veh.car_type);
	config_write_tire_type(veh.tire_type);
	config_write_weather_type(veh.weather);
	config_write_road_type(veh.road_type);
}

/* Dot selection */
void increment_current_config_value(eDotSelect * type) {
	switch(*type) {
		case(Track_Type_Dot): 	*type = Car_Type_Dot; break;
		case(Car_Type_Dot): 	*type = Tire_Type_Dot; break;
		case(Tire_Type_Dot): 	*type = Weather_Type_Dot; break;
		case(Weather_Type_Dot): *type = Road_Type_Dot; break;
		default: break;
	}
}

void decrement_current_config_value(eDotSelect * type) {
	switch(*type) {
		case(Car_Type_Dot): 	*type = Track_Type_Dot; break;
		case(Tire_Type_Dot): 	*type = Car_Type_Dot; break;
		case(Weather_Type_Dot): *type = Tire_Type_Dot; break;
		case(Road_Type_Dot): 	*type = Weather_Type_Dot; break;
		default: break;
	}
}

void increment_current_dot_value(eDotSelect type, Vehicle_t * veh, Track_Settings_t * settings) {
	switch(type) {
		case(Track_Type_Dot): 	increment_track_choice(settings); break;
		case(Car_Type_Dot): 	increment_car_choice(veh); break;
		case(Tire_Type_Dot): 	increment_tire_choice(veh); break;
		case(Weather_Type_Dot): increment_weather_choice(veh); break;
		case(Road_Type_Dot): 	increment_road_choice(veh); break;
	}
}

void decrement_current_dot_value(eDotSelect type, Vehicle_t * veh, Track_Settings_t * settings) {
	switch(type) {
		case(Track_Type_Dot): 	decrement_track_choice(settings); break;
		case(Car_Type_Dot): 	decrement_car_choice(veh); break;
		case(Tire_Type_Dot): 	decrement_tire_choice(veh); break;
		case(Weather_Type_Dot): decrement_weather_choice(veh); break;
		case(Road_Type_Dot):	decrement_road_choice(veh); break;
	}
}


/* Track Selection */
void increment_track_choice(Track_Settings_t * settings) {
	switch(settings->track) {
	case(Melbourne): break;
	default: settings->track++;
	}
}

void decrement_track_choice(Track_Settings_t * settings) {
	switch(settings->track) {
	case(0): break;
	default: settings->track--;
	}
}

/* Car Selection */
void increment_car_choice(Vehicle_t * veh) {
	switch(veh->car_type) {
	case(Sedan): {
		veh->car_type	= SUV;
		veh->length		= SUV_LENGTH;
		veh->width		= SUV_WIDTH;
		veh->mass		= SUV_MASS;
		veh->max_power	= SUV_MAX_POWER;
		break;
	}
	case(SUV): {
		veh->car_type	= Truck;
		veh->length		= TRUCK_LENGTH;
		veh->width		= TRUCK_WIDTH;
		veh->mass 		= TRUCK_MASS;
		veh->max_power 	= TRUCK_MAX_POWER;
		break;
	}
	case(Truck): {
		veh->car_type	= Van;
		veh->length 	= VAN_LENGTH;
		veh->width		= VAN_WIDTH;
		veh->mass		= VAN_MASS;
		veh->max_power	= VAN_MAX_POWER;
		break;
	}
	case(Van): {
		veh->car_type	= F1;
		veh->length		= F1_LENGTH;
		veh->width		= F1_WIDTH;
		veh->mass		= F1_MASS;
		veh->max_power	= F1_MAX_POWER;
		break;
	}
	default: break;
	}
}

void decrement_car_choice(Vehicle_t * veh) {
	switch(veh->car_type) {
	case(SUV): {
		veh->car_type	= Sedan;
		veh->length		= SEDAN_LENGTH;
		veh->width 		= SEDAN_WIDTH;
		veh->mass 		= SEDAN_MASS;
		veh->max_power	= SEDAN_MAX_POWER;
		break;
	}
	case(Truck): {
		veh->car_type	= SUV;
		veh->length		= SUV_LENGTH;
		veh->width		= SUV_WIDTH;
		veh->mass		= SUV_MASS;
		veh->max_power	= SUV_MAX_POWER;
		break;
	}
	case(Van): {
		veh->car_type 	= Truck;
		veh->length		= TRUCK_LENGTH;
		veh->width		= TRUCK_WIDTH;
		veh->mass 		= TRUCK_MASS;
		veh->max_power	= TRUCK_MAX_POWER;
		break;
	}
	case(F1): {
		veh->car_type	= Van;
		veh->length		= VAN_LENGTH;
		veh->width		= VAN_WIDTH;
		veh->mass 		= VAN_MASS;
		veh->max_power	= VAN_MAX_POWER;
		break;
	}
	default: break;
	}
}

/* Tire Selection */
void increment_tire_choice(Vehicle_t * veh) {
	switch(veh->tire_type) {
	case(Normal): veh->tire_type = Slicks; break;
	case(Slicks): veh->tire_type = Snow_Tires; break;
	default: break;
	}
}

void decrement_tire_choice(Vehicle_t * veh) {
	switch(veh->tire_type) {
	case(Slicks): 		veh->tire_type = Normal; break;
	case(Snow_Tires): 	veh->tire_type = Slicks; break;
	default: break;
	}
}

/* Weather Selection */
void increment_weather_choice(Vehicle_t * veh) {
	switch(veh->weather) {
	case(Snowy): break;
	default: veh->weather++; break;
	}
}

void decrement_weather_choice(Vehicle_t * veh) {
	switch(veh->weather) {
	case(Sunny): break;
	default: veh->weather--; break;
	}
}

/* Road Selection */
void increment_road_choice(Vehicle_t * veh) {
	switch(veh->road_type) {
	case(Dirt): break;
	default: veh->road_type++;
	}
}

void decrement_road_choice(Vehicle_t * veh) {
	switch(veh->road_type) {
	case(Asphalt): break;
	default: veh->road_type--;
	}
}

//***********************************************************************************
// getready
//***********************************************************************************
void getready_draw_countdown(uint8_t count) {
	char str[DISPLAY_MAX_STR_LEN];
//	char * str_count = "";
	char str_count[1];
	__itoa(count, str_count, 10);

    GLIB_clear(&glibContext);

	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNumber16x20);
	snprintf(str, DISPLAY_MAX_STR_LEN, str_count);

	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  CENTER_X - ((strlen(str) * GLIB_FONT_WIDTH) / 2),
				  CENTER_Y - (GLIB_FONT_HEIGHT / 2),
				  0);

}

//***********************************************************************************
// gameplay
//***********************************************************************************
void gameplay_draw_screen(GLIB_Rectangle_t veh_shape, Speed_t veh_speed, Direction_t veh_dir) {
	GLIB_clear(&glibContext);
	gameplay_draw_hud(veh_speed);
	gameplay_draw_vehicle(veh_shape, veh_dir);
}

void gameplay_draw_hud(Speed_t veh_speed) {
	// Acceleration
	GLIB_Rectangle_t outline = { HUD_X_OFFSET_LEFT, HUD_Y_OFFSET_UPPER, HUD_X_OFFSET_RIGHT, HUD_Y_OFFSET_LOWER };
	GLIB_Rectangle_t fill;

	if(veh_speed.accelerator_pos == 0.0) {
		fill.xMin = HUD_X_MIDPOINT;
		fill.yMin = HUD_Y_OFFSET_UPPER;
		fill.xMax = HUD_X_MIDPOINT;
		fill.yMax = HUD_Y_OFFSET_LOWER;
	}
	else if(veh_speed.accelerator_pos >= 0.0) {
		fill.xMin = HUD_X_MIDPOINT;
		fill.yMin = HUD_Y_OFFSET_UPPER;
		fill.xMax = HUD_X_MIDPOINT + (veh_speed.accelerator_pos * (HUD_X_OFFSET_RIGHT - HUD_X_MIDPOINT));
		fill.yMax = HUD_Y_OFFSET_LOWER;
	}
	else {
		fill.xMin = HUD_X_MIDPOINT + ((HUD_X_MIDPOINT - HUD_X_OFFSET_LEFT) * veh_speed.accelerator_pos);
		fill.yMin = HUD_Y_OFFSET_UPPER;
		fill.xMax = HUD_X_MIDPOINT;
		fill.yMax = HUD_Y_OFFSET_LOWER;
	}

    GLIB_drawRect(&glibContext, &outline);
    GLIB_drawRectFilled(&glibContext, &fill);

	// Speed Reading
	char str_speed[3];
	char str[DISPLAY_MAX_STR_LEN] = "Speed:";

	uint32_t mph = gameplay_calculate_mph_from_ms(veh_speed);
	__itoa(mph, str_speed, 10);
	//	__itoa(veh_speed.speed, str_speed, 10);

	strcat(str, str_speed);

	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNarrow6x8);

	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MAX_X - 55,
				  3,
				  0);

	GLIB_drawLine(&glibContext, MIN_X - 1, MIN_Y + (2 * GLIB_FONT_HEIGHT),
			MAX_X + 1, MIN_Y + (2 * GLIB_FONT_HEIGHT));
}

void gameplay_draw_vehicle(GLIB_Rectangle_t veh_shape, Direction_t veh_dir) {
	if(veh_dir.direction == Straight) {
		GLIB_Rectangle_t current_veh_shape = veh_shape;

		// move to x position
		current_veh_shape.xMax += vehicle_x_position;

		if(current_veh_shape.xMax > MAX_X - 1) {
			current_veh_shape.xMax = MAX_X - 1;
			current_veh_shape.xMin = current_veh_shape.xMax - (veh_shape.xMax - veh_shape.xMin);
		}
		else {
			current_veh_shape.xMin += vehicle_x_position;
		}
	    GLIB_drawRect(&glibContext, &current_veh_shape);
	}
	else {

		// TODO: use turn radius here
		switch(veh_dir.direction) {
			case(Left): {
				if(vehicle_x_position > 2) {
					vehicle_x_position -= 1;
				}
				// draw 4 lines to draw vehicle shape
				GLIB_drawLine(&glibContext, veh_shape.xMin + vehicle_x_position + 2, veh_shape.yMin,
						veh_shape.xMin + vehicle_x_position, veh_shape.yMax); 	// left side
				GLIB_drawLine(&glibContext, veh_shape.xMax + vehicle_x_position + 2, veh_shape.yMin,
						veh_shape.xMax + vehicle_x_position, veh_shape.yMax);	// right side
				GLIB_drawLine(&glibContext, veh_shape.xMax + vehicle_x_position, veh_shape.yMax,
						veh_shape.xMin + vehicle_x_position, veh_shape.yMax);	// top
				GLIB_drawLine(&glibContext, veh_shape.xMax + vehicle_x_position + 2, veh_shape.yMin,
						veh_shape.xMin + vehicle_x_position + 2, veh_shape.yMin);	// bottom
				break;
			}
			case(Hard_Left): {
				if(vehicle_x_position > 4) {
					vehicle_x_position -= 3;
				}
				// draw 4 lines to draw vehicle shape
				GLIB_drawLine(&glibContext, veh_shape.xMin + vehicle_x_position + 4, veh_shape.yMin,
						veh_shape.xMin + vehicle_x_position, veh_shape.yMax); 	// left side
				GLIB_drawLine(&glibContext, veh_shape.xMax +vehicle_x_position + 4, veh_shape.yMin,
						veh_shape.xMax + vehicle_x_position, veh_shape.yMax);	// right side
				GLIB_drawLine(&glibContext, veh_shape.xMax + vehicle_x_position, veh_shape.yMax,
						veh_shape.xMin + vehicle_x_position, veh_shape.yMax);	// top
				GLIB_drawLine(&glibContext, veh_shape.xMax + vehicle_x_position + 4, veh_shape.yMin,
						veh_shape.xMin + vehicle_x_position + 4, veh_shape.yMin);	// bottom
				break;

			}
			case(Right): {
				if(vehicle_x_position < (MAX_X - (veh_shape.xMax - veh_shape.xMin) - 2)) {
					vehicle_x_position += 1;
				}
				// draw 4 lines to draw vehicle shape
				GLIB_drawLine(&glibContext, veh_shape.xMin + vehicle_x_position - 2, veh_shape.yMin,
						veh_shape.xMin + vehicle_x_position, veh_shape.yMax); 	// left side
				GLIB_drawLine(&glibContext, veh_shape.xMax +vehicle_x_position - 2, veh_shape.yMin,
						veh_shape.xMax + vehicle_x_position, veh_shape.yMax);	// right side
				GLIB_drawLine(&glibContext, veh_shape.xMax + vehicle_x_position, veh_shape.yMax,
						veh_shape.xMin + vehicle_x_position, veh_shape.yMax);	// top
				GLIB_drawLine(&glibContext, veh_shape.xMax + vehicle_x_position - 2, veh_shape.yMin,
						veh_shape.xMin + vehicle_x_position - 2, veh_shape.yMin);	// bottom
				break;
			}
			case(Hard_Right): {
				if(vehicle_x_position < (MAX_X - (veh_shape.xMax - veh_shape.xMin) - 4)) {
					vehicle_x_position += 3;
				}
				// draw 4 lines to draw vehicle shape
				GLIB_drawLine(&glibContext, veh_shape.xMin + vehicle_x_position - 4, veh_shape.yMin,
						veh_shape.xMin + vehicle_x_position, veh_shape.yMax); 	// left side
				GLIB_drawLine(&glibContext, veh_shape.xMax +vehicle_x_position - 4, veh_shape.yMin,
						veh_shape.xMax + vehicle_x_position, veh_shape.yMax);	// right side
				GLIB_drawLine(&glibContext, veh_shape.xMax + vehicle_x_position, veh_shape.yMax,
						veh_shape.xMin + vehicle_x_position, veh_shape.yMax);	// top
				GLIB_drawLine(&glibContext, veh_shape.xMax + vehicle_x_position - 4, veh_shape.yMin,
						veh_shape.xMin + vehicle_x_position - 4, veh_shape.yMin);	// bottom
				break;
			}
			case(Straight):
			default: break;
		}

	}
}

void gameplay_calculate_vehicle_shape(Vehicle_t veh, GLIB_Rectangle_t * veh_shape) {
	veh_shape->xMax = (int32_t)veh.width;
	veh_shape->xMin = vehicle_x_position - 1;
	veh_shape->yMin = MAX_Y - 1;
	veh_shape->yMax = veh_shape->yMin - veh.length;
}


/*
 * @return true if last waypoint has been reached
 */
bool gameplay_draw_track(Vehicle_t veh, Track_t track, Speed_t veh_speed) {
//	static bool initialized = false;
//	static uint32_t remaining_waypoints;
//	static uint8_t current_waypoints[3][2];

//	uint8_t i;
//	for(i = 0; i < 4; i++) {
//		switch(track.waypoints[track.index + i].turn) {
//			case(Right_Turn):
//			case(Slight_Right_Turn):
//			case(Hard_Right_Turn): {
//				GLIB_drawLine(&glibContext,
//					CENTER_X - (TRACK_PYLON_WIDTH / 2) + RIGHT_TURN_ROAD_OFFSET,
////					vehicle_shape_graphic.yMax - ((i+1) * TRACK_PYLON_DISTANCE),
//					vehicle_shape_graphic.yMax - track.waypoints[track.index + i].distance_marker - track.index * TRACK_PYLON_DISTANCE,
//					CENTER_X + (TRACK_PYLON_WIDTH / 2) + RIGHT_TURN_ROAD_OFFSET,
//					vehicle_shape_graphic.yMax - track.waypoints[track.index + i].distance_marker);
////					vehicle_shape_graphic.yMax - ((i+1) * TRACK_PYLON_DISTANCE));
//				break;
//
//			}
//			case(Left_Turn):
//			case(Slight_Left_Turn):
//			case(Hard_Left_Turn): {
//				GLIB_drawLine(&glibContext,
//					CENTER_X - (TRACK_PYLON_WIDTH / 2) - LEFT_TURN_ROAD_OFFSET,
////					vehicle_shape_graphic.yMax - ((i+1) * TRACK_PYLON_DISTANCE),
//					vehicle_shape_graphic.yMax - track.waypoints[track.index + i].distance_marker,
//					CENTER_X + (TRACK_PYLON_WIDTH / 2) - LEFT_TURN_ROAD_OFFSET,
////					vehicle_shape_graphic.yMax - ((i+1) * TRACK_PYLON_DISTANCE));
//					vehicle_shape_graphic.yMax - track.waypoints[track.index + i].distance_marker);
//				break;
//			}
//			case(Straight_Turn):
//			default: {
//				GLIB_drawLine(&glibContext,
//					CENTER_X - (TRACK_PYLON_WIDTH / 2),
////					vehicle_shape_graphic.yMax - ((i+1) * TRACK_PYLON_DISTANCE) - 2,
//					vehicle_shape_graphic.yMax - track.waypoints[track.index + i].distance_marker,
//					CENTER_X + (TRACK_PYLON_WIDTH / 2),
////					vehicle_shape_graphic.yMax - ((i+1) * TRACK_PYLON_DISTANCE) - 2);
//					vehicle_shape_graphic.yMax - track.waypoints[track.index + i].distance_marker);
//				break;
//			}
//		}
//	}
//	return false;

	static uint8_t x_start;
	x_start = (CENTER_X - (TRACK_PYLON_WIDTH / 2));
	static uint8_t y_start;

	y_start = MAX_Y;

	if(track.waypoints[track.index].distance_marker < track.meters) {
		uint8_t i;
		for(i = 0; i < 6; i++) {
			gameplay_connect_waypoints(&x_start, &y_start, track.waypoints[track.index + i].turn);
		}

		// see if index needs to be updated
//		if(veh.distance_covered > track.waypoints[track.index].distance_marker) {
//			track.waypoints[track.index].distance_marker++;
//		}
		if(veh.distance_covered > track.waypoints[track.index].distance_marker) {
			track.index++;
		}
	}
	else {
//		uint8_t i;
//		for(i = 0; i < (track.num_waypoints - track.index); i++) {
//			gameplay_connect_waypoints(&x_start, &y_start, track.waypoints[track.index + i].turn);
//		}
//
//		// see if index needs to be updated
//		if(veh.distance_covered > track.waypoints[track.index].distance_marker) {
//			track.waypoints[track.index].distance_marker++;
//		}
		return true;
	}

//	gameplay_connect_waypoints(&x_start, &y_start, Straight_Turn);
//	gameplay_connect_waypoints(&x_start, &y_start, Straight_Turn);
//	gameplay_connect_waypoints(&x_start, &y_start, Right_Turn);
//	gameplay_connect_waypoints(&x_start, &y_start, Straight_Turn);
//	gameplay_connect_waypoints(&x_start, &y_start, Left_Turn);
//	gameplay_connect_waypoints(&x_start, &y_start, Slight_Right_Turn);

    return false;
}

void gameplay_connect_waypoints(uint8_t * x_left_start, uint8_t * y_start, eTurnType turn_type) {
	uint8_t y_end = *y_start - TRACK_PYLON_DISTANCE;

	if(y_end < HUD_Y_LINE) {
		y_end = HUD_Y_LINE;
	}

	// left line
	GLIB_drawLine(&glibContext,
			*x_left_start,
			*y_start,
			*x_left_start + turn_type,
			y_end);

	// right line
	GLIB_drawLine(&glibContext,
			*x_left_start + TRACK_PYLON_WIDTH,
			*y_start,
			*x_left_start + TRACK_PYLON_WIDTH + turn_type,
			y_end);

	*x_left_start += turn_type;
	*y_start -= TRACK_PYLON_DISTANCE;
}


uint32_t gameplay_calculate_mph_from_ms(Speed_t veh_speed) {
	return (uint32_t)((float)veh_speed.speed * 2.23694);
}

//***********************************************************************************
// gameover
//***********************************************************************************
void gameover_print_header(void) {
	/* Setup display colours */
	glibContext.backgroundColor = White;
	glibContext.foregroundColor = Black;

    GLIB_clear(&glibContext);
	char str[DISPLAY_MAX_STR_LEN];
	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNormal8x8);
	snprintf(str, DISPLAY_MAX_STR_LEN, "GAME\nOVER");
	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  CENTER_X - ((GLIB_FONT_WIDTH * strlen(str)) / 4) + 5,
				  CENTER_Y - (GLIB_FONT_HEIGHT * 2),
				  0);

}

void gameover_print_header_inverse(void) {
	/* Setup display colours */
	glibContext.backgroundColor = Black;
	glibContext.foregroundColor = White;

    GLIB_clear(&glibContext);
	char str[DISPLAY_MAX_STR_LEN];
	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNormal8x8);
	snprintf(str, DISPLAY_MAX_STR_LEN, "GAME\nOVER");
	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  CENTER_X - ((GLIB_FONT_WIDTH * strlen(str)) / 4) + 5,
				  CENTER_Y - (GLIB_FONT_HEIGHT * 2),
				  0);
}

//***********************************************************************************
// highscore
//***********************************************************************************
void high_score_display(void) {
	glibContext.backgroundColor = White;
	glibContext.foregroundColor = Black;

	GLIB_clear(&glibContext);

    char str[DISPLAY_MAX_STR_LEN];
	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNormal8x8);
	snprintf(str, DISPLAY_MAX_STR_LEN, "HIGH SCORE");
	GLIB_drawString(&glibContext,
		  str,
		  strlen(str),
		  CENTER_X - ((GLIB_FONT_WIDTH * strlen(str)) / 2),
		  5,
		  0);

	GLIB_drawLine(&glibContext, MIN_X - 1, MIN_Y + (2 * GLIB_FONT_HEIGHT),
			MAX_X + 1, MIN_Y + (2 * GLIB_FONT_HEIGHT));

	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNarrow6x8);
	snprintf(str, DISPLAY_MAX_STR_LEN, "Place");
	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MIN_X + 10,
				  (4 * GLIB_FONT_HEIGHT),
				  0);

	snprintf(str, DISPLAY_MAX_STR_LEN, "Score");
	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MAX_X - 50,
				  (4 * GLIB_FONT_HEIGHT),
				  0);

	// display high scores
	uint8_t i;
	for(i = 5; i < 15; i++) {
		high_score_display_place(i);
	}

}

void high_score_display_place(uint8_t place) {
	char str[DISPLAY_MAX_STR_LEN];
	char str_place[3];
	__itoa(place - 4, str_place, 10);

	strcat(str_place, ":");

	GLIB_setFont(&glibContext, (GLIB_Font_t *)&GLIB_FontNarrow6x8);
	snprintf(str, DISPLAY_MAX_STR_LEN, str_place);
	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MIN_X + 10,
				  (place * GLIB_FONT_HEIGHT),
				  0);

	snprintf(str, DISPLAY_MAX_STR_LEN, "90");
	GLIB_drawString(&glibContext,
				  str,
				  strlen(str),
				  MAX_X - 50,
				  (place * GLIB_FONT_HEIGHT),
				  0);
}
