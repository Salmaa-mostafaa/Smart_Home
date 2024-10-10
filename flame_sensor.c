/*
 * flame_sensor.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */

#include "flame_sensor.h"
#include "gpio.h"


void FlameSensor_init(void){
	    GPIO_setupPinDirection(PORT_FLAME_SENSOR_ID, PIN_FLAME_SENSOR_ID , PIN_INPUT);
}

uint8 FlameSensor_getValue(void){
           uint8 value=0;
           value=GPIO_readPin(PORT_FLAME_SENSOR_ID, PIN_FLAME_SENSOR_ID );
           return value;
}
