/*
 * 01_led_fast_PWN.c
 *
 * Created: 2017. 06. 12. 10:21:08
 * Author : Peeter
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <string.h>
#include "ADC_driver.h"
#include "UART_driver.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif


void pwm_init()
{
	// initialize timer0 in PWM mode
	TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	TCCR0B |= 1 << CS00;
	
	DDRD |= ( 1 << DDRD6);
}

void system_init()
{
	ADC_init();
	UART_init();

	// Enable interrupts globally, UART uses interrupts
	sei();
}


int main(void)
{
	pwm_init();
	
	system_init();

	FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;


	printf("start....\n\r");
    /* Replace with your application code */
	char speed[256];
	int speedvalue = 0;
	int speedvalue2 = 0;
	//gets(speed);
	//puts(speed);
    while (1) 
    {
		printf("The value is in %%: ");
		gets(speed);
		if (UDR0 != 0)
		{
			speedvalue = atoi(speed);
			printf("%d  %%\n", speedvalue);
			if (speedvalue <= 100)
			{
				speedvalue2 = 91 + (1.64 * (float)speedvalue);
				OCR0A = speedvalue2;
			}
		}
		
    }
}

