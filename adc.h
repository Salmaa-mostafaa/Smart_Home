/*
 * adc.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

#define PRESCALER 128
#define ReferenceVoltage  2.56
#define ADC_MAX_VALUE  1023


void ADC_init(void);
uint16 ADC_readChannel(uint8 Ch_num);


#endif /* ADC_H_ */
