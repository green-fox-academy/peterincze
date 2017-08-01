/*
 * PWM_driver.c
 *
 * Created: 2017. 06. 15. 13:07:20
 *  Author: Peeter
 */ 

 #include "PWM_driver.h"
 #include <avr/io.h>
 #include <stdint.h>
 #include <stdio.h>


 void pwm_init()
 {
	 // initialize timer2 in PWM mode 
	 TCCR2A |= (1 << WGM00) | (1 << WGM21) | (1 << COM2A1);
	 TCCR2B |= 1 << CS20;
	 // on PB3
	 DDRB |= ( 1 << DDRB3);
 }


void speed_percent(int value)
{
	 int speedvalue = 0;
   	 if (value <= 100)
 	 {
		speedvalue = 90 + (1.65 * (float)value);
		OCR2A = speedvalue;
	 }
	 else printf("invalid value! \n");
}