/*
 * led.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */

#ifndef LED_H_
#define LED_H_

#include"std_types.h"

typedef enum{
	RED,GREEN,BLUE
}LED_ID;

#define RED_PORT_ID  PORTB_ID
#define RED_PIN_ID   PIN5_ID

#define GREEN_PORT_ID  PORTB_ID
#define GREEN_PIN_ID   PIN6_ID

#define BLUE_PORT_ID  PORTB_ID
#define BLUE_PIN_ID   PIN7_ID

#define LED_ON LOGIC_HIGH
#define LED_OFF LOGIC_LOW


void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);
#endif /* LED_H_ */
