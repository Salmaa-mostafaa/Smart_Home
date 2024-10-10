/*
 * adc.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */
#include "gpio.h"
#include "common_macros.h"
#include "avr/io.h"
#include "adc.h"

void ADC_init(void){
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN);

#if(PRESCALER==128)
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS0);

#elif(PRESCALER==64)
    SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS0);

#elif(PRESCALER==32)
    SET_BIT(ADCSRA,ADPS2);
    SET_BIT(ADCSRA,ADPS0);
    CLEAR_BIT(ADCSRA,ADPS1);

#elif(PRESCALER==16)
    SET_BIT(ADCSRA,ADPS2);
    CLEAR_BIT(ADCSRA,ADPS0);
    CLEAR_BIT(ADCSRA,ADPS1);

#elif(PRESCALER==8)
    SET_BIT(ADCSRA,ADPS1);
    SET_BIT(ADCSRA,ADPS0);
    CLEAR_BIT(ADCSRA,ADPS2);

#elif(PRESCALER==4)
    SET_BIT(ADCSRA,ADPS1);
    CLEAR_BIT(ADCSRA,ADPS0);
    CLEAR_BIT(ADCSRA,ADPS2);

#elif(PRESCALER==2)
    CLEAR_BIT(ADCSRA,ADPS0);
    CLEAR_BIT(ADCSRA,ADPS1);
    CLEAR_BIT(ADCSRA,ADPS2);

#endif
}

uint16 ADC_readChannel(uint8 Ch_num){
	ADMUX=(ADMUX & 0xE0)|(Ch_num & 0X07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}

