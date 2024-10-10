/*
 * ldr.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */


#include "ldr.h"
#include "adc.h"


uint16 LDR_getLightIntensity(void){
	    ADC_init();
	    uint16 result=0;
		uint16 Intensity=0;
		result=ADC_readChannel(LDR_SENSOR_CHANNEL_ID);
		Intensity=(uint16)(((uint32)result*LDR_SENSOR_MAX_LIGHT_INTENSITY*ReferenceVoltage )/(LDR_SENSOR_MAX_VOLT_VALUE*ADC_MAX_VALUE));
	    return Intensity;
}
