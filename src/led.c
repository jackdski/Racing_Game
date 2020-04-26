//***********************************************************************************
// Include files
//***********************************************************************************
#include "led.h"
#include "em_cmu.h"
#include "configurations.h"
#include "monitor.h"

/*  F R E E R T O S   I N C L U D E S   */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

//***********************************************************************************
// global variables
//***********************************************************************************
/*  G L O B A L   V A R I A B L E S   */
extern eSystemState system_state;
extern Active_Warnings_t active_warnings;

/*	S E M A P H O R E S   */
extern SemaphoreHandle_t mSystemState;

//***********************************************************************************
// tasks
//***********************************************************************************

void LedTask(void *pvParameters) {
	const TickType_t delay_time = pdMS_TO_TICKS(500);
	const TickType_t gameover_time = pdMS_TO_TICKS(100);

	// init
	gpio_init_leds();

	static eSystemState sys_state;
	static bool setting0 = false;
	static bool setting1 = false;

	while(1) {
		// get system state
		xSemaphoreTake(mSystemState, 0);
		sys_state = system_state;
		xSemaphoreGive(mSystemState);

		switch(sys_state) {
			case(Startup):
			case(Configuration): {
				set_led0(setting0);
				set_led1(setting1);

				setting0 ^= 1;
				setting1 ^= 1;
				break;
			}
			case(GetReady): {
				setting0 = false;
				setting1 = false;

				set_led0(setting0);
				set_led1(setting1);
				break;
			}
			case(Gameplay): {
				if(active_warnings.slip_occured) {
					setting0 = true;
				}
				else if(active_warnings.slip_warning) {
					setting0 ^= 1;
				}
				else {
					setting0 = 0;
				}

				if(active_warnings.steering_offroad) {
					setting1 = true;
				}
				else if(active_warnings.steering_warning) {
					setting1 ^= 1;
				}
				else {
					setting1 = 0;
				}

				set_led0(setting0);
				set_led1(setting1);
				break;
			}
			case(GameOver): {
				static bool i = false;
				switch(i) {
					case(false): {
						setting0 = false;
						setting1 = true;
						i = true;
						break;
					}
					case(true): {
						setting0 = true;
						setting1 = false;
						i = false;
						break;
					}
				}

				set_led0(setting0);
				set_led1(setting1);
				break;
			}
			case(HighScore): {
				static bool i = false;
				switch(i) {
					case(false): {
						setting0 = false;
						setting1 = false;
						i = true;
						break;
					}
					case(true): {
						setting0 = true;
						setting1 = true;
						i = false;
						break;
					}
				}
				set_led0(setting0);
				set_led1(setting1);
				break;
			}
		}

		if(sys_state == GameOver) {
			vTaskDelay(gameover_time);
		}
		else {
			vTaskDelay(delay_time);
		}
	}
}

/*
 *	@brief Configures GPIO pins for LED and GPIO
 *
 *	@details Define LAB2_USE_INTERRUPT to enable interrupts on button GPIO pins
 */
void gpio_init_leds(void){
	CMU_ClockEnable(cmuClock_GPIO, true);

	// Set LED ports to be standard output drive with default off (cleared)
	GPIO_DriveStrengthSet(LED0_port, gpioDriveStrengthStrongAlternateStrong);
	GPIO_PinModeSet(LED0_port, LED0_pin, gpioModePushPull, LED0_default);

	GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthStrongAlternateStrong);
	GPIO_PinModeSet(LED1_port, LED1_pin, gpioModePushPull, LED1_default);
}


/*
 * @brief Turns LED0 on or off
 *
 * @param setting
 * 		true - turns on LED
 * 		false - turns off LED
 */
void set_led0(bool setting) {
	if(setting == true) {
		GPIO_PinOutSet(LED0_port, LED0_pin);
	}
	else {
		GPIO_PinOutClear(LED0_port, LED0_pin);
	}
}

/*
 * @brief Turns LED1 on or off
 *
 * @param setting
 * 		true - turns on LED
 * 		false - turns off LED
 */
void set_led1(bool setting) {
	if(setting) {
		GPIO_PinOutSet(LED1_port, LED1_pin);
	}
	else {
		GPIO_PinOutClear(LED1_port, LED1_pin);
	}
}

void reset_led_settings(bool * settings0, bool * settings1) {
	settings0 = false;
	settings1 = false;
}
