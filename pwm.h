/*
 * pwm.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

#define COMPARE_MATCH   NON_INVERTING
#define CLOCK_SELECT    1024
#define START_VALUE     0
#define END_VALUE       0

#define PORT_PWM_ID       PORTB_ID
#define PIN_PWM_ID        PIN3_ID


void PWM_Timer0_Init(void);
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
