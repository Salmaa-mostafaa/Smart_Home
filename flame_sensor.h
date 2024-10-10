/*
 * flame_sensor.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_
#include "std_types.h"

#define PORT_FLAME_SENSOR_ID       PORTD_ID
#define PIN_FLAME_SENSOR_ID        PIN2_ID


void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
