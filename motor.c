/*
 * motor.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mostafa
 */
#include "motor.h"
#include "gpio.h"
#include "pwm.h"

void DcMotor_Init(void){
	GPIO_setupPinDirection(PORT_MOTOR_ID, PIN_MOTOR_IN1_ID , PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_MOTOR_ID, PIN_MOTOR_IN2_ID , PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_MOTOR_ID, PIN_MOTOR_EN1_ID , PIN_OUTPUT);

	GPIO_writePin(PORT_MOTOR_ID, PIN_MOTOR_IN1_ID, MOTOR_OFF);
	GPIO_writePin(PORT_MOTOR_ID, PIN_MOTOR_EN1_ID, MOTOR_ON);
	GPIO_writePin(PORT_MOTOR_ID, PIN_MOTOR_IN2_ID, MOTOR_OFF);
	 PWM_Timer0_Init();

}

void DcMotor_Rotate(DcMotor_State state, uint8 speed){
         switch(state){
         case STOP:
        	 GPIO_writePin(PORT_MOTOR_ID, PIN_MOTOR_IN1_ID, MOTOR_OFF);
        	 GPIO_writePin(PORT_MOTOR_ID, PIN_MOTOR_IN2_ID, MOTOR_OFF);
        	 PWM_Timer0_Start(speed);
        	   break;
         case CW:
        	  GPIO_writePin(PORT_MOTOR_ID, PIN_MOTOR_IN1_ID, MOTOR_OFF);
        	  GPIO_writePin(PORT_MOTOR_ID, PIN_MOTOR_IN2_ID, MOTOR_ON);
        	  PWM_Timer0_Start(speed);
               break;
         case ACW:
        	 GPIO_writePin(PORT_MOTOR_ID, PIN_MOTOR_IN1_ID, MOTOR_ON);
        	 GPIO_writePin(PORT_MOTOR_ID, PIN_MOTOR_IN2_ID, MOTOR_OFF);
        	 PWM_Timer0_Start(speed);
        	   break;
         }
}
