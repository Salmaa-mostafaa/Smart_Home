/*
 * ldr.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */

#ifndef LDR_H_
#define LDR_H_
#include "std_types.h"

#define LDR_SENSOR_CHANNEL_ID 0
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100
#define LDR_SENSOR_MAX_VOLT_VALUE 2.56


uint16 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
