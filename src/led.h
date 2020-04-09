#ifndef GPIO_H_
#define GPIO_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include "em_gpio.h"

//***********************************************************************************
// defined files
//***********************************************************************************

// LED0
#define	LED0_port		gpioPortF
#define LED0_pin		04u
#define LED0_default	false 	// off
// LED1
#define LED1_port		gpioPortF
#define LED1_pin		05u
#define LED1_default	false	// off



//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************
void LedTask(void *pvParameters);

void gpio_init_leds(void);
void set_led0(bool setting);
void set_led1(bool setting);
void reset_led_settings(bool * settings0, bool * settings1);

#endif

