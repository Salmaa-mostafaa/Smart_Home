/*
 * motor.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"

#define PORT_MOTOR_ID          PORTB_ID
#define PIN_MOTOR_IN1_ID        PIN0_ID
#define PIN_MOTOR_IN2_ID        PIN1_ID
#define PIN_MOTOR_EN1_ID        PIN3_ID

#define MOTOR_ON            LOGIC_HIGH
#define MOTOR_OFF           LOGIC_LOW

typedef enum
{
	STOP,CW,ACW
}DcMotor_State;


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* MOTOR_H_ */
