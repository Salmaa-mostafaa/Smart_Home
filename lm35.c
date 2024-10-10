/*
 * lm35.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */

#include "lm35.h"
#include "adc.h"

uint8 Sensor_getTemp(void){
	ADC_init();
	uint16 Digital=0;
	uint8 TEMP=0;
	Digital=ADC_readChannel(TEMP_CHANNAL);
	TEMP=(uint8)(((uint32)Digital*SENSOR_MAX_VALUE*ReferenceVoltage )/(SENSOR_MAX_VOLTAGE*ADC_MAX_VALUE));
    return TEMP;
}
