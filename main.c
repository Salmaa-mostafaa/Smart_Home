/*
 * main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Salma Mosatfa
 */


#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* For GET_BIT Macro */
#include "lcd.h"
#include "buzzer.h"
#include "led.h"
#include "motor.h"
#include "flame_sensor.h"
#include "ldr.h"
#include "lm35.h"



int main(void){
	LCD_init();
	Buzzer_init();
	LEDS_init();
	DcMotor_Init();
	FlameSensor_init();

	uint8 Temperature=0;
	uint16 Intensity=0;

	 LCD_displayStringRowColumn(0,4,"FAN is ");
	 LCD_displayStringRowColumn(1,0,"TEMP=");
	 LCD_displayStringRowColumn(1,9,"LDR=");


	while(1){

		Temperature=Sensor_getTemp();
		Intensity=LDR_getLightIntensity();

		if(FlameSensor_getValue()){
			LCD_clearScreen();
			Buzzer_on();
			LCD_displayStringRowColumn(0,0,"Critical alert!");
			while(FlameSensor_getValue());
			Buzzer_off();
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,4,"FAN is ");
			LCD_displayStringRowColumn(1,0,"TEMP=");
			LCD_displayStringRowColumn(1,9,"LDR=");
		}

		if(Temperature<25){
			 LCD_displayStringRowColumn(0,11,"OFF");
			 LCD_moveCursor(1,6);
			 LCD_intgerToString((uint32)Temperature);
			 LCD_moveCursor(1,13);
			 if(Intensity>=100){
			 	LCD_intgerToString((uint32)Intensity);
			 	LCD_displayCharacter('%');
			 			}
			 else{
			    LCD_intgerToString((uint32)Intensity);
			 	LCD_displayCharacter('%');
			 	LCD_displayCharacter(' ');

		}
		}
		else{
			LCD_displayStringRowColumn(0,11,"ON ");
			LCD_moveCursor(1,6);
			LCD_intgerToString((uint32)Temperature);
			LCD_moveCursor(1,13);
			if(Intensity>=100){
			LCD_intgerToString((uint32)Intensity);
			LCD_displayCharacter('%');
			}
			else{
				LCD_intgerToString((uint32)Intensity);
				LCD_displayCharacter('%');
				LCD_displayCharacter(' ');
			}
		}

				if(Temperature>=40){
					DcMotor_Rotate(CW,100);
				}
				else if((Temperature>=35) && (Temperature<40)){
					DcMotor_Rotate(CW,75);
				}
				else if((Temperature>=30) && (Temperature<35)){
							DcMotor_Rotate(CW,50);
						}
				else if((Temperature>=25) && (Temperature<30)){
							DcMotor_Rotate(CW,25);
						}
				else if(Temperature<25){
							DcMotor_Rotate(STOP,0);
						}


				if (Intensity <= 15) {
							LED_on(RED);
							LED_on(GREEN);
							LED_on(BLUE);
						} else if ((Intensity > 15) && (Intensity <= 50)) {
							LED_on(RED);
							LED_on(GREEN);
							LED_off(BLUE);
						} else if ((Intensity > 50) && (Intensity <= 70)) {
							LED_on(RED);
							LED_off(GREEN);
							LED_off(BLUE);
						} else {
							LED_off(RED);
							LED_off(GREEN);
							LED_off(BLUE);
						}
	}
}

