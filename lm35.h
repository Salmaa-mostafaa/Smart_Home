/*
 * lm35.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */

#ifndef LM35_H_
#define LM35_H_
#include "std_types.h"

#define TEMP_CHANNAL 1
#define SENSOR_MAX_VALUE 150
#define SENSOR_MAX_VOLTAGE 1.5


uint8 Sensor_getTemp(void);

#endif /* LM35_H_ */
