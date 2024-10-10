/*
 * pwm.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */

#include "pwm.h"
#include "gpio.h"
#include "common_macros.h"
#include "avr/io.h"

void PWM_Timer0_Init(void){
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#if(COMPARE_MATCH==NON_INVERTING)
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);

#elif(COMPARE_MATCH==INVERTING)
     SET_BIT(TCCR0,COM00);
     SET_BIT(TCCR0,COM01);

#elif(COMPARE_MATCH==RESERVED)
     SET_BIT(TCCR0,COM00);
	 CLEAR_BIT(TCCR0,COM01);

#else
     CLEAR_BIT(TCCR0,COM00);
     CLEAR_BIT(TCCR0,COM01);

#endif


#if(CLOCK_SELECT==NO_CLOCK)
     CLEAR_BIT(TCCR0,CS02);
     CLEAR_BIT(TCCR0,CS01);
     CLEAR_BIT(TCCR0,CS00);

#elif(CLOCK_SELECT==NO_PRESCALLING)
     CLEAR_BIT(TCCR0,CS02);
     CLEAR_BIT(TCCR0,CS01);
     SET_BIT(TCCR0,CS00);

#elif(CLOCK_SELECT==8)
     CLEAR_BIT(TCCR0,CS02);
     CLEAR_BIT(TCCR0,CS00);
     SET_BIT(TCCR0,CS01);

#elif(CLOCK_SELECT==64)
     CLEAR_BIT(TCCR0,CS02);
     SET_BIT(TCCR0,CS01);
     SET_BIT(TCCR0,CS00);

#elif(CLOCK_SELECT==256)
     CLEAR_BIT(TCCR0,CS00);
     CLEAR_BIT(TCCR0,CS01);
     SET_BIT(TCCR0,CS02);

#elif(CLOCK_SELECT==1024)
     SET_BIT(TCCR0,CS02);
     CLEAR_BIT(TCCR0,CS01);
     SET_BIT(TCCR0,CS00);
#endif
     TCNT0=START_VALUE;
     OCR0=END_VALUE;
     GPIO_setupPinDirection(PORT_PWM_ID, PIN_PWM_ID, PIN_OUTPUT);
}

void PWM_Timer0_Start(uint8 duty_cycle){
	switch(duty_cycle){
	case 100:
		OCR0=255;
		break;
	case 75:
			OCR0=192;
			break;
	case 50:
			OCR0=128;
			break;
	case 25:
			OCR0=64;
			break;
	case 0:
				OCR0=0;
				break;
		}
}
